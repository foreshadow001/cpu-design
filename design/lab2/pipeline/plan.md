# Pipelined CPU Design Plan (Lab 2 Part 1)

## Context

The current `cpu_core.v` implements a multi-cycle microarchitecture where `inst_finished` gates PC update and `ld_st_flag`/`mul_div_flag` handle multi-cycle stalls. Lab 2 requires converting this to a classic 5-stage pipeline (IF→ID→EX→MEM→WB) with hazard detection, forwarding, and stalling — while preserving the Trace Basic test framework constraints (module hierarchy, interface, RUN_TRACE/verilator public annotations).

## Architecture Overview

### 5-Stage Pipeline with Harvard Memory

The existing BRAM wrappers (Inst_ROM, Data_RAM) have 1-cycle read latency (`inst_valid`/`data_valid` are registered). This maps naturally to the pipeline:

```
Stage  IF         ID         EX         MEM        WB
       ───        ──         ──         ───        ──
       Present    Decode     ALU        Assert     Write RF
       addr to    RF read    compute    daccess    from
       Inst_ROM   SExt       branch     req/wen    MEM/WB
                  Branch                            
                  target                            

Reg:   → IF/ID →  → ID/EX →  → EX/MEM → → MEM/WB →
```

- **IF**: `ifetch_addr` presented, `ifetch_req=1`. BRAM reads, instruction arrives next cycle into IF/ID.
- **ID**: Controller decodes, RF reads (combinational), SEXT computes immediate, branch target = PC+offset computed.
- **EX**: ALU computes, branch resolved. Mul/div may take multiple cycles.
- **MEM**: `daccess_ren`/`daccess_wen` presented. Load data arrives next cycle into MEM/WB. Store data written.
- **WB**: Register file write (posedge).

### Pipeline Registers

| Register | Key Fields |
|----------|-----------|
| **IF/ID** | `pc`, `inst` |
| **ID/EX** | `pc`, `rd1`, `rd2`, `ext`, `alu_op[4:0]`, `alua_sel`, `alub_sel`, `rf_we`, `rf_wsel[1:0]`, `ram_rop[2:0]`, `ram_wop[3:0]`, `is_mul`, `is_div`, `rs1[4:0]`, `rs2[4:0]`, `rd[4:0]`, `npc_op[1:0]` |
| **EX/MEM** | `pc`, `alu_c`, `rd2` (store data), `br`, `rf_we`, `rf_wsel[1:0]`, `ram_rop[2:0]`, `ram_wop[3:0]`, `rd[4:0]`, `is_mul`, `is_div` |
| **MEM/WB** | `pc`, `alu_c`, `ram_ext`, `rf_we`, `rf_wsel[1:0]`, `rd[4:0]` |

## Hazard Handling

### 1. Data Hazards — Forwarding

**ForwardingUnit** (new `miniRV/src/rtl/ForwardingUnit.v`): Combines the pipeline register values to generate forwarding mux selects.

**Forwarding paths** (both to ALU inputs in EX):
```
ForwardA (alu_a):
  Priority 1: EX/MEM.alu_c  — when rd_EX/MEM == rs1_EX, rf_we_EX/MEM, rd != 0
  Priority 2: MEM/WB.rf_wD  — when rd_MEM/WB == rs1_EX, rf_we_MEM/WB, rd != 0
  Default:    rf_rd1         — from ID/EX pipeline register

ForwardB (alu_b):
  Priority 1: EX/MEM.alu_c  — when rd_EX/MEM == rs2_EX, rf_we_EX/MEM, rd != 0
  Priority 2: MEM/WB.rf_wD  — when rd_MEM/WB == rs2_EX, rf_we_MEM/WB, rd != 0
  Default:    rf_rd2 or ext  — based on alub_sel
```

`rf_wD` in MEM/WB is already selected from `alu_c` (ALU ops) or `ram_ext` (loads), so forwarding from MEM/WB handles both ALU→ALU and load→ALU.

### 2. Load-Use Hazard — Stall

**Condition**: Load instruction in EX stage AND instruction in ID uses loaded register.

```
load_use = (ram_rop_EX != RAM_EXT_N)  // is load
         & ((rs1_ID == rd_EX) | (rs2_ID == rd_EX))
         & (rd_EX != 5'h0)
```

**Action** (1 cycle stall):
- `stall_pc = 1` — PC holds
- `stall_if_id = 1` — IF/ID holds (dependent instruction stays in ID)
- `flush_id_ex = 1` — ID/EX gets NOP (bubble enters EX)
- Next cycle: Load in MEM→WB (data arrives), dependent instruction enters EX, forward from MEM/WB.

### 3. Mul/Div Multi-Cycle — Stall

**Condition**: Mul/div op in EX stage and multiplier/divider busy.

```
mul_div_stall = (is_mul_EX | is_div_EX) & mul_div_busy
```

**Action** (stall until done):
- `stall_pc = 1` — PC holds (no new fetches)
- `stall_if_id = 1` — IF/ID holds (next instruction waits in ID)
- `stall_id_ex = 1` — ID/EX holds (mul/div stays in EX, ALU continues computing)
- EX/MEM gets bubble values while stalled

When `mul_div_busy` drops: ALU produces result on `alu_c`, next posedge latches it into EX/MEM, pipeline resumes.

### 4. Control Hazards — Flush

**Branch** (resolved in EX, predict not-taken):
- **Taken**: `flush_if_id=1`, `flush_id_ex=1`, PC = branch target. 2-cycle penalty.
- **Not-taken**: No penalty.

**JAL** (resolved in ID, target = PC+offset):
- `flush_if_id=1`, PC = PC+offset. 1-cycle penalty.

**JALR** (resolved in EX, target = {alu_c[31:1], 1'b0}):
- `flush_if_id=1`, `flush_id_ex=1`, PC = target. 2-cycle penalty.

### Stall/Flush Priority

```
1. Flush (branch/jump) overrides stall
2. Mul/div stall > load-use stall (they don't conflict)
```

Combined signals:
```
stall_f  = load_use | mul_div_stall
stall_d  = mul_div_stall  (only mul/div keeps ID/EX from updating)
flush_f  = (br_taken & EX_is_branch) | ID_is_jal | (EX_is_jalr)
flush_d  = flush_f | load_use
```

## Files to Create

### `miniRV/src/rtl/ForwardingUnit.v`
- Inputs: `rs1_EX`, `rs2_EX`, `rd_EXMEM`, `rf_we_EXMEM`, `rd_MEMWB`, `rf_we_MEMWB`
- Outputs: `forward_a[1:0]`, `forward_b[1:0]` (00=no forward, 01=from EX/MEM, 10=from MEM/WB)

### `miniRV/src/rtl/cpu_core_pipeline.v`
- Same module interface as current `cpu_core`
- Instantiate: PC, NPC, Controller, RF, SEXT, ALU, MREQ, MEXT, ForwardingUnit
- Pipeline registers: IF/ID, ID/EX, EX/MEM, MEM/WB with stall/flush enables
- Hazard detection logic inline
- Debug/trace signals preserved from original

### Optional: `miniRV/src/rtl/HazardUnit.v`
- If hazard detection logic grows too complex, extract it. Start inline in cpu_core_pipeline for simplicity (KISS).

## Files to Modify

### `miniRV/src/rtl/ALU.v`
- **Change needed**: The latch logic at lines 74-81 latches `a` and `b` when `mul_flag | mulu_flag | div_flag | divu_flag`. In the pipeline, `a` and `b` come from ID/EX (stable during stall because `stall_d` holds ID/EX). The `op` is also from ID/EX. This should work as-is since ID/EX holds during mul/div stall.
- **Verification**: Confirm `a_latched`/`b_latched` correctly capture operands during first EX cycle of mul/div.

## Trace Basic Constraints (MUST PRESERVE)

1. Module hierarchy: `miniRV_SoC → cpu_top → cpu_core` — names and interfaces unchanged
2. All `RUN_TRACE` ifdef blocks preserved verbatim
3. All `/* verilator public */` comments preserved
4. `fpga_rst` high-active in trace, `cpu_rst` same polarity
5. First instruction address = `0x00000000`
6. All `debug_wb_*` and `debug_mem_*` signals must reflect correct values for differential testing

### Trace Signal Mapping in Pipeline

In the pipelined design, `debug_wb_*` reflects the **WB stage**, not the current PC:
```
debug_wb_pc    = mem_wb_pc      // PC of instruction in WB stage
debug_wb_rf_we = mem_wb_rf_we   // WB stage write enable
debug_wb_rf_wR = mem_wb_rd      // WB stage destination register
debug_wb_rf_wD = mem_wb_rf_wD   // WB stage write data

debug_mem_pc    = ex_mem_pc     // PC of instruction in MEM stage
debug_mem_we    = daccess_wen    // MEM stage write enable
debug_mem_waddr = daccess_addr   // MEM stage write address
debug_mem_wdata = store_data_r   // Latched store data (same approach as current)
```

## Implementation Order

### Phase 1: Ideal Pipeline (no hazards)
1. Create `cpu_core_pipeline.v` with 5 pipeline stages
2. Pipeline registers with no stall/flush logic (always advance)
3. PC updates every cycle
4. Test with simple sequential code (no dependencies, no branches)

### Phase 2: Forwarding + Load-Use Stall
1. Create `ForwardingUnit.v`
2. Integrate forwarding muxes in EX stage
3. Add load-use hazard detection and stall
4. Test with dependent instructions

### Phase 3: Control Hazards
1. Branch flushing (predict not-taken)
2. JAL flushing
3. JALR flushing
4. Test with branches and jumps

### Phase 4: Mul/Div
1. Multi-cycle stall for mul/div in EX
2. Test with mul/div instructions

### Phase 5: Integration
1. Run all 44 single-instruction Trace tests
2. Verify against golden model
3. `start` test (will fail on peripheral access — expected)

## Verification

Each phase tested by:
1. Behavioral simulation in Vivado with `soc_simple_tb`
2. Trace Basic differential test (per-instruction) — `RUN_TRACE` define active
3. Compare `debug_wb_*` signals with golden model

## Design Decisions Summary

| Decision | Rationale |
|----------|----------|
| Predict branch not-taken | Simplest, 0 penalty for fall-through (common case) |
| Forwarding from EX/MEM and MEM/WB | Covers all ALU→ALU and load→ALU RAW hazards |
| 2-bit forward selects | 00=no fwd, 01=EX/MEM, 10=MEM/WB — simple priority encoder |
| Load-use: 1 stall cycle | Inevitable with 1-cycle BRAM latency |
| Mul/div stalls entire pipeline | Simplest correct approach for variable-latency ops |
| JAL resolved in ID | Target = PC+offset, no ALU needed, saves 1 penalty cycle |
| Branch/JALR resolved in EX | Need ALU (comparison/addition), 2 penalty cycles |
| Keep `cpu_core` module name | Trace constraint requirement |
| New file `cpu_core_pipeline.v` first | Safer to develop in parallel, swap when ready |
