# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

A mini RISC-V CPU (RV32I subset) implemented in Verilog, targeting a Xilinx FPGA board. Built with **Vivado 2023.2**. This is an academic CPU design project.

Currently implemented instructions: `ADDI`, `ORI`, `SLLI`, `LW`, `BEQ`, `BNE`, `LUI`, `JAL`. The CPU uses a multi-cycle microarchitecture — not a classic 5-stage pipeline. Instructions that don't access memory or use mul/div complete in one cycle; load/store and mul/div instructions stall via flags (`ld_st_flag`, `mul_div_flag`) until completion.

## Building and Simulating

Open `miniRV/miniRV.xpr` in Vivado 2023.2. All build, synthesis, and simulation flows go through the Vivado GUI:

- **Behavioral simulation**: Run the `soc_simple_tb` testbench from the Vivado simulation flow
- **Synthesis / Implementation / Bitstream**: Standard Vivado flow
- **Update instruction memory**: Run `source miniRV/update_coe.tcl` in Vivado Tcl Console (assembles `.asm` → `.coe` for BRAM init)

There is no CLI build system or Makefile. Everything is Vivado project-based.

## Architecture

### Module Hierarchy

```
miniRV_SoC (top, with PLL)
  └─ cpu_top
       ├─ cpu_core (the CPU itself)
       │    ├─ PC          — Program Counter register
       │    ├─ NPC         — Next PC logic (PC+4 / branch / jump)
       │    ├─ Controller  — Instruction decoder (combinational)
       │    ├─ RF          — Register File (32×32, regs[1:31], x0 hardwired to 0)
       │    ├─ SEXT        — Sign-extension (I/B/U/J formats)
       │    ├─ ALU         — Arithmetic/logic + branch comparison
       │    │    ├─ multiplier (stub — TODO)
       │    │    └─ divider    (stub — TODO)
       │    ├─ MREQ        — Memory request generator (addr alignment, byte/halfword handling)
       │    └─ MEXT        — Memory extension (load result extraction/extension)
       ├─ Inst_ROM (BRAM IP wrapper)
       └─ Data_RAM (BRAM IP wrapper)
```

### Key Control Signals (defined in `src/rtl/defines.vh`)

Control signals use `define` macros with one-hot or enumerated encoding:
- `ALU_*` — ALU operation select (ADD, OR, SLL, EQ, NE)
- `NPC_*` — Next PC source (PC+4, branch, jump)
- `EXT_*` — Immediate format (I, B, U, J)
- `WB_*` — Writeback data source (ALU result, RAM, PC+4, extended immediate)
- `RAM_EXT_*` / `RAM_WE_*` — Memory access size and write enables

### Instruction Timing

- **Single-cycle instructions** (ADDI, ORI, SLLI, LUI, BEQ, BNE, JAL): Complete in the same cycle as `ifetch_valid`
- **Load instructions**: `ld_st_flag` asserts on decode; instruction completes when `daccess_rvalid` returns. `ram_rop_r` and `alu_c_r` are latched during this wait.
- **Store instructions**: `ld_st_flag` asserts; completes when `daccess_wresp` returns.
- **Mul/Div**: `mul_div_flag` asserts; completes when `mul_div_busy` deasserts. RF writeback target register (`rf_wR_r`) is latched.

### `inst_finished` Signal

This is the key instruction sequencing signal. It qualifies the PC update (`PC.fetch`) and the next `ifetch_req`. It asserts when:
- A single-cycle instruction is decoded (`ifetch_valid & !is_ld_st & !is_mul_div`)
- A load/store completes its memory access
- A mul/div operation finishes

### Address Space

| Range | Purpose |
|---|---|
| `0x0000_0000` – `0x0007_FFFF` | Block memory (512KB) |
| `0x2000_0000` – `0x3FFF_FFFF` | DDR3 (512MB) |
| `0xFFFF_0000` | Switch input |
| `0xFFFF_1000` | LED output |
| `0xFFFF_2000` | Digit LED |
| `0xFFFF_3000` | UART |
| `0xFFFF_4000` | Timer |

### Verification

The testbench (`soc_simple_tb.v`) loads a program from `IROM` BRAM and checks for instruction `0x00000073` (`ecall`) to declare "Test Passed!" and finish. The `RUN_TRACE` define enables debug signal visibility (`debug_wb_*`, `debug_mem_*`).

### IP Cores (Vivado Block Memory Generator)

- **IROM**: Instruction ROM BRAM, initialized via `.coe` file
- **DRAM**: Data RAM BRAM
- **clk_wiz_0**: Clock PLL (bypassed in `RUN_TRACE` simulation mode, used for FPGA synthesis)

## Key Files

| File | Purpose |
|---|---|
| `src/rtl/defines.vh` | All `define` macros for control signals and address space |
| `src/rtl/cpu_core.v` | Main CPU datapath and control wiring |
| `src/rtl/Controller.v` | Instruction decoder — maps opcode/funct3/funct7 to control signals |
| `src/rtl/ALU.v` | ALU with integrated mul/div unit placeholders |
| `src/sim/soc_simple_tb.v` | Top-level testbench |
| `src/coe/mul_div_test.asm` | Test program for mul/div instructions |
| `src/xdc/miniRV_SoC.xdc` | FPGA pin constraints |
| `src/xdc/clock.xdc` | Clock timing constraint (100MHz / 10ns) |

## Design Methodology (from Course PPT)

The course defines a systematic 5-step engineering method for CPU design:

1. **Build instruction-level datapath**: For each instruction, analyze what data flows through which components. Document in the datapath table (rows = instructions, columns = component input pins).
2. **Synthesize full datapath**: Merge all instruction datapath rows. Handle multi-input pins with MUXes (introduce mux select control signals).
3. **Construct control logic**: Extract control signal values per instruction into the control signal table. Derive logic expressions: `control_signal = f(opcode, funct3, funct7)`.
4. **Implement functional components**: Each of the 7 components (PC, NPC, RF, SEXT, ALU, MREQ, MEXT) with defined interfaces.
5. **Connect and assemble**: Wire components according to the datapath table.

See `resources/单周期CPU设计方法论.md` for the detailed methodology and `resources/miniRV-控制信号取值表-完整.md` for the complete control signal table (all 44 instructions filled in).

## Trace 测试框架约束（不可违反）

修改任何 RTL 代码时必须遵守以下规则，否则 Trace 测试无法运行：

1. **模块层次不可改动**：`miniRV_SoC → cpu_top → cpu_core`，模块名、实例名、`cpu_core` 的接口信号均固定。模板工程默认满足要求，不要改动。
2. **不可修改** 所有源文件中任何出现 `RUN_TRACE` 宏定义的代码。
3. **不可修改** 所有源文件中任何行内出现 `/* verilator public */` 的代码，且不能删除或修改此注释。
4. **SoC 顶层复位信号** `fpga_rst` 在 Trace 测试框架中是**高电平复位**（与 Vivado 仿真中的低电平 `fpga_rst` 不同）。
5. **系统复位后首条指令地址**是 `0x00000000`。
6. **代码拷贝**：仅拷贝 `src/rtl/` 下的源文件到 `cdp-tests/mySoC/`，不拷贝 `ip/` 目录。

## Full miniRV Instruction Set (44 instructions)

The demo implements 8 instructions. The full set includes 36 more (17 R-type, 7 more I-type, 3 S-type, 4 more B-type, 1 more U-type). Distribution:
- **Group A** (浅蓝): 18 instructions — one teammate does these
- **Group B** (浅橙): 18 instructions — the other teammate does these
- **8 demo** (绿色): already in the template

See `resources/Lab1-单周期CPU设计/miniRV指令速查表.xlsx` (and CSV) for the complete instruction encoding table.

New ALU ops to define beyond the existing `ALU_ADD/OR/SLL/EQ/NE`:
`ALU_SUB`, `ALU_XOR`, `ALU_AND`, `ALU_SRL`, `ALU_SRA`, `ALU_SLT`, `ALU_SLTU`, `ALU_MUL`, `ALU_MULH`, `ALU_MULHU`, `ALU_DIV`, `ALU_DIVU`, `ALU_REM`, `ALU_REMU`, `ALU_GE`, `ALU_GEU`

Key design observations:
- `bge` uses `ALU_SLT` with reversed operands or negation: `(rs1 >= rs2) ≡ !(rs1 < rs2)`. Same for `bgeu`/`sltu`.
- `auipc` is the only instruction using `alua_sel = ALU_A_PC` (PC + sext(imm)).
- Store instructions: `rf_we = 0`, use `ram_wop` to control byte/halfword/word.
- `jalr`: `npc_op = JUMP` (to rs1+offset) but `rf_wsel = WB_PC4` (save return address).

## Active TODO Items (student work)

- **`multiplier.v`**: Implement sequential multiplier (parameterized WIDTH, produces 2×WIDTH result)
- **`divider.v`**: Implement sequential divider (parameterized WIDTH)
- **`MREQ.v`**: Complete store byte (`RAM_WE_B`) and store halfword (`RAM_WE_H`) logic with proper offset-based byte-enable generation
- **`MEXT.v`**: Complete load extension for `RAM_EXT_B`, `RAM_EXT_BU`, `RAM_EXT_H`, `RAM_EXT_HU` (signed/unsigned byte/halfword)
- **`MREQ.v`**: Complete load alignment checks for byte/halfword loads
- **`Controller.v`**: Wire up new instructions beyond the current 8-instruction subset (add `is_mul`, `is_div`, store instructions, new ALU ops, etc.)
- **`defines.vh`**: Add new ALU op defines, new control signal encodes as needed
