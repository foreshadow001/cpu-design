# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

A mini RISC-V CPU (RV32I subset, 44 instructions) implemented in Verilog, targeting a Xilinx FPGA board. Built with **Vivado 2023.2**. This is an academic CPU design project.

**Current status**: 44/45 Trace tests pass. The CPU uses a classic **5-stage pipeline** (IF→ID→EX→MEM→WB) with forwarding, hazard detection, and mul/div stalling. The only failing test is `start` (peripheral access, expected — not a CPU logic issue).

## Building and Simulating

Open `miniRV/miniRV.xpr` in Vivado 2023.2. All build, synthesis, and simulation flows go through the Vivado GUI:

- **Behavioral simulation**: Run the `soc_simple_tb` testbench from the Vivado simulation flow
- **Synthesis / Implementation / Bitstream**: Standard Vivado flow
- **Update instruction memory**: Run `source miniRV/update_coe.tcl` in Vivado Tcl Console (assembles `.asm` → `.coe` for BRAM init)

### Trace Testing (cdp-tests)

The cdp-tests framework is in `//wsl.localhost/Ubuntu-24.04/home/foreshadow/cdp-tests/`. To build and run:

```bash
cd /home/foreshadow/cdp-tests
make build          # compile
make run TEST=<name>  # run single test (e.g., TEST=mul)
```

Run all tests:
```bash
for t in addi add and andi auipc beq bge bgeu blt bltu bne div divu jal jalr lb lbu lh lhu lui lw mul mulh mulhu or ori rem remu sb sh sll slli slt slti sltiu sltu sra srai srl srli sub sw xor xori start; do
    make run TEST=$t
done
```

Source files live in `cdp-tests/mySoC/`. After modifying RTL, copy updated files:
```bash
cp miniRV/src/rtl/*.v miniRV/src/rtl/*.vh /path/to/cdp-tests/mySoC/
```

A debug copy with verbose trace output is at `cdp-debug/` (same structure, but with PIPE `$display` in RTL and TICK/DBG printf in test.cpp).

## Architecture

### Module Hierarchy

```
miniRV_SoC (top, with PLL)
  └─ cpu_top
       ├─ cpu_core (the CPU itself — 5-stage pipeline)
       │    ├─ PC            — Program Counter register
       │    ├─ NPC           — Next PC logic (PC+4 / branch / jump / mul release)
       │    ├─ Controller    — Instruction decoder (combinational, 44 instructions)
       │    ├─ RF            — Register File (32×32, regs[1:31], x0 hardwired to 0)
       │    ├─ SEXT          — Sign-extension (I/B/U/J/S formats)
       │    ├─ ALU           — Arithmetic/logic + branch comparison
       │    │    ├─ multiplier   — Sequential multiplier (32-bit, 33-bit unsigned)
       │    │    └─ divider      — Sequential divider (32-bit, 33-bit unsigned)
       │    ├─ ForwardingUnit — EX-stage forwarding mux selects
       │    ├─ MREQ          — Memory request generator (addr alignment, byte/halfword)
       │    └─ MEXT          — Memory extension (load result extraction/extension)
       ├─ Inst_ROM (BRAM IP wrapper, 1-cycle read latency)
       └─ Data_RAM (BRAM IP wrapper)
```

### 5-Stage Pipeline

```
Stage  IF         ID         EX         MEM        WB
       ───        ──         ──         ───        ──
       Present    Decode     ALU        Assert     Write RF
       addr to    RF read    compute    daccess    from
       Inst_ROM   SExt       branch     req/wen    MEM/WB
                  Branch     forward
                  target     mul/div

Reg:   → IF/ID →  → ID/EX →  → EX/MEM → → MEM/WB →
```

- **IF**: `ifetch_addr` presented, `ifetch_req=1`. BRAM reads, instruction arrives next cycle into IF/ID.
- **ID**: Controller decodes, RF reads (combinational), SEXT computes immediate, branch/JAL target = PC+offset. ID-stage forwarding for back-to-back dependencies.
- **EX**: ALU computes, forwarding muxes select operands, branch resolved. Mul/div may take multiple cycles.
- **MEM**: `daccess_ren`/`daccess_wen` presented. Load data arrives next cycle into MEM/WB. Store data written.
- **WB**: Register file write (posedge).

### Pipeline Registers

| Register | Key Fields |
|----------|-----------|
| **IF/ID** | `pc`, `inst` |
| **ID/EX** | `pc`, `rd1`, `rd2`, `ext`, `alu_op[4:0]`, `alua_sel`, `alub_sel`, `rf_we`, `rf_wsel[1:0]`, `ram_rop[2:0]`, `ram_wop[3:0]`, `is_mul`, `is_div`, `rs1[4:0]`, `rs2[4:0]`, `rd[4:0]`, `npc_op[1:0]`, `br_target` |
| **EX/MEM** | `pc`, `alu_c`, `rd2` (store data), `br`, `rf_we`, `rf_wsel[1:0]`, `ram_rop[2:0]`, `ram_wop[3:0]`, `rd[4:0]`, `is_mul`, `is_div`, `ext` |
| **MEM/WB** | `pc`, `alu_c`, `ext`, `rf_we`, `rf_wsel[1:0]`, `rd[4:0]`, `ram_rop[2:0]`, `byte_offs[1:0]` |

## Hazard Handling

### 1. Data Hazards — Forwarding

**ForwardingUnit** (`src/rtl/ForwardingUnit.v`): Generates forwarding mux selects for ALU inputs.

```
ForwardA (alu_a):
  Priority 1: EX/MEM.alu_c  — when rd_EX/MEM == rs1_EX, rf_we_EX/MEM, rd != 0, !alua_sel
  Priority 2: MEM/WB.rf_wD  — when rd_MEM/WB == rs1_EX, rf_we_MEM/WB, rd != 0, !alua_sel
  Default:    rf_rd1         — from ID/EX pipeline register

ForwardB (alu_b):
  Priority 1: EX/MEM.alu_c  — same check for rs2, gated by !alub_sel
  Priority 2: MEM/WB.rf_wD  — same check for rs2
  Default:    rf_rd2 or ext  — based on alub_sel
```

**ID-stage forwarding**: For back-to-back dependencies, `id_fwd_rd1`/`id_fwd_rd2` check the EX combinational output (`ex_alu_c`) directly before checking pipeline registers. This avoids 1-cycle bubbles.

### 2. Load-Use Hazard — Stall

**Condition**: Load instruction in EX stage AND instruction in ID uses loaded register as a real register source (not immediate pseudo-register).

```
load_use = (id_ex_ram_rop != RAM_EXT_N)  // is load
         & (((id_rs1 == id_ex_rd) & !id_alua_sel)
          | ((id_rs2 == id_ex_rd) & !id_alub_sel))
         & (id_ex_rd != 5'h0)
```

**Action** (1 cycle stall):
- `stall_f = 1` — PC holds, IF/ID holds (dependent instruction stays in ID)
- `stall_d = 0` — ID/EX updates (bubble enters EX via flush_d)
- `flush_d = 1` — ID/EX gets NOP (bubble)
- Next cycle: Load in MEM→WB (data arrives), dependent instruction re-enters EX, forward from MEM/WB.
- After stall releases: `load_resync`/`load_resync2` provide 2 extra IF/ID NOP cycles for BRAM resync.

### 3. Mul/Div Multi-Cycle — Stall with Pipeline Freeze

**Condition**: Mul/div op in EX stage.

```
mul_div_stall = (id_ex_is_mul | id_ex_is_div)
              & (mul_div_entering | ex_mul_div_busy)
              & !duplicate_mul
```

**Action** (pipeline freeze):
- `stall_f = 1` — PC holds, IF/ID holds
- `stall_d = 1` — ID/EX holds (mul/div stays in EX)
- `stall_e = 0` but EX/MEM holds via `mul_div_stall` branch — keeps previous values, NO NOP
- MEM/WB continues to see the same EX/MEM data → `wb_change = 0` → no spurious events

**On release** (`mul_div_stall` drops):
- `mul_div_release` fires (1-cycle pulse)
- `flush_f = ... | mul_div_release` → IF/ID NOP + PC change for BRAM resync
- EX/MEM gets MUL result
- `duplicate_mul` detection prevents same-PC re-execution (kills IF/ID if it matches ID/EX)

**Key design decisions for mul/div**:
- `mul_div_entering`: 1-cycle self-clearing pulse bridging MUL entry and `busy` going high
- `pc_next = if_id_pc + 4` on release (re-fetches instruction after the one stuck in IF/ID)
- Fallback to `id_ex_pc + 4` if IF/ID was killed (duplicate)
- EX/MEM held (not NOP'd) during stall → no WB event disruption
- ALU `suppress` input prevents multiplier restart during duplicate detection window
- `last_wb_pc` freezes on NOP (`mem_wb_pc == 0`) to prevent `wb_change` from resetting
- ALU `effective_op` uses `op` when it differs from `op_r` (consecutive different MUL ops)
- ALU `restart_continue`: 1-cycle delayed restart for consecutive MULs so `op_r` captures new op

### 4. Control Hazards — Flush

**Branch** (resolved in EX, predict not-taken):
- **Taken**: `flush_f=1, flush_d=1`, PC = branch target. 2-cycle penalty.
- **Not-taken**: No penalty.

**JAL** (resolved in ID, target = PC+offset):
- `flush_f=1`, PC = PC+offset. 1-cycle penalty.

**JALR** (resolved in EX, target = {alu_c[31:1], 1'b0}):
- `flush_f=1, flush_d=1`, PC = target. 2-cycle penalty.

### Stall/Flush Signals

```verilog
wire stall_f = ((load_use_stall & !flush_f) | mul_div_stall) & !flush_f;
wire stall_d = mul_div_stall;
wire stall_e = mul_div_stall | duplicate_mul;
wire flush_f = id_is_jal | ex_br_taken | ex_is_jalr | mul_div_release;
wire flush_d = ex_br_taken | ex_is_jalr | load_use_stall | duplicate_mul;
wire effective_flush = flush_f | flush_next | flush_next2 | load_resync | load_resync2;
```

## Key Control Signals (defined in `src/rtl/defines.vh`)

Control signals use `define` macros:
- `ALU_*` — ALU operation select (ADD, SUB, XOR, AND, OR, SLL, SRL, SRA, SLT, SLTU, GE, GEU, MUL, MULH, MULHU, DIV, DIVU, REM, REMU, EQ, NE)
- `NPC_*` — Next PC source (PC4, BRA, JMP, JALR)
- `EXT_*` — Immediate format (I, B, U, S, J)
- `WB_*` — Writeback data source (ALU, RAM, PC4, EXT)
- `RAM_EXT_*` / `RAM_WE_*` — Memory access size and write enables
- `ALU_A_*` / `ALU_B_*` — ALU operand select (RS1, PC / RS2, EXT)

## Key Files

| File | Purpose |
|---|---|
| `src/rtl/defines.vh` | All `define` macros for control signals and address space |
| `src/rtl/cpu_core.v` | 5-stage pipeline datapath, hazard detection, stall/flush control |
| `src/rtl/Controller.v` | Instruction decoder — maps opcode/funct3/funct7 to all control signals (44 instructions) |
| `src/rtl/ForwardingUnit.v` | EX-stage forwarding mux selects (forward_a, forward_b) |
| `src/rtl/ALU.v` | ALU with integrated sequential multiplier and divider |
| `src/rtl/multiplier.v` | Sequential multiplier (parameterized WIDTH, shift-add algorithm) |
| `src/rtl/divider.v` | Sequential divider (parameterized WIDTH, restoring algorithm) |
| `src/rtl/MREQ.v` | Memory request: address alignment, byte/halfword/word store byte-enable |
| `src/rtl/MEXT.v` | Memory extension: byte/halfword load sign/zero extension |
| `src/sim/soc_simple_tb.v` | Top-level testbench |
| `src/coe/mul_div_test.asm` | Test program for mul/div instructions |
| `src/xdc/miniRV_SoC.xdc` | FPGA pin constraints |
| `src/xdc/clock.xdc` | Clock timing constraint (100MHz / 10ns) |

## Address Space

| Range | Purpose |
|---|---|
| `0x0000_0000` – `0x0007_FFFF` | Block memory (512KB) |
| `0x2000_0000` – `0x3FFF_FFFF` | DDR3 (512MB) |
| `0xFFFF_0000` | Switch input |
| `0xFFFF_1000` | LED output |
| `0xFFFF_2000` | Digit LED |
| `0xFFFF_3000` | UART |
| `0xFFFF_4000` | Timer |

## Trace 测试框架约束（不可违反）

修改任何 RTL 代码时必须遵守以下规则，否则 Trace 测试无法运行：

1. **模块层次不可改动**：`miniRV_SoC → cpu_top → cpu_core`，模块名、实例名、`cpu_core` 的接口信号均固定。模板工程默认满足要求，不要改动。
2. **不可修改** 所有源文件中任何出现 `RUN_TRACE` 宏定义的代码。
3. **不可修改** 所有源文件中任何行内出现 `/* verilator public */` 的代码，且不能删除或修改此注释。
4. **SoC 顶层复位信号** `fpga_rst` 在 Trace 测试框架中是**高电平复位**（与 Vivado 仿真中的低电平 `fpga_rst` 不同）。
5. **系统复位后首条指令地址**是 `0x00000000`。
6. **代码拷贝**：仅拷贝 `src/rtl/` 下的源文件到 `cdp-tests/mySoC/`，不拷贝 `ip/` 目录。

## Trace Test Results (44/45 Passing)

| Status | Tests |
|--------|-------|
| **PASS (44)** | addi, add, and, andi, auipc, beq, bge, bgeu, blt, bltu, bne, div, divu, jal, jalr, lb, lbu, lh, lhu, lui, lw, mul, mulh, mulhu, or, ori, rem, remu, sb, sh, sll, slli, slt, slti, sltiu, sltu, sra, srai, srl, srli, sub, sw, xor, xori |
| **FAIL (1)** | start — peripheral access test, not a CPU logic issue |

## Active TODO Items

- **`start` test**: Debug peripheral (MMIO) access for the start test
- **Vivado synthesis**: Verify the design synthesizes and meets timing (100MHz / 10ns)
- **FPGA testing**: Run on actual FPGA board
- **Performance analysis**: Measure CPI for benchmark programs
