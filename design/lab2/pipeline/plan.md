# Pipelined CPU Design Plan (Lab 2) — COMPLETED

## Status: 44/45 Trace Tests Pass

The 5-stage pipeline is fully implemented and verified. All 44 RV32I instructions pass differential trace tests. Only `start` fails (peripheral MMIO access, not a CPU logic issue).

## Architecture

5-stage pipeline: **IF → ID → EX → MEM → WB**

```
miniRV_SoC → cpu_top → cpu_core (5-stage pipeline)
                         ├─ PC, IF/ID
                         ├─ Controller, RF, SEXT (ID)
                         ├─ ForwardingUnit, ALU (EX)
                         ├─ MREQ, MEXT (MEM)
                         └─ WB (RF write)
```

## Hazard Handling (Final Implementation)

### 1. Data Hazards — Forwarding
- `ForwardingUnit.v`: EX-stage forwarding muxes (forward_a/b: 00=no fwd, 01=EX/MEM, 10=MEM/WB)
- ID-stage forwarding: `id_fwd_rd1`/`id_fwd_rd2` check EX combinational output first (back-to-back)
- Store data forwarding: `id_store_data` checks EX first, then EX/MEM, then ID-stage forward

### 2. Load-Use Hazard
- `load_use_stall`: detects RAW between load in EX and instruction in ID
- 1-cycle stall + bubble in ID/EX + `load_resync` for BRAM recovery
- Gated by `!id_alua_sel`/`!id_alub_sel` to prevent false triggers from immediate-bit aliasing

### 3. Mul/Div Multi-Cycle (Pipeline Freeze)
Key design decisions:
- **`mul_div_entering`**: 1-cycle self-clearing pulse bridging the gap between MUL entering EX and `ex_mul_div_busy` going high
- **`mul_div_stall`**: gated by `(id_ex_is_mul | id_ex_is_div)`, only depends on EX state (not IF/ID)
- **EX/MEM held (not NOP'd)** during stall — prevents WB event disruption
- **`duplicate_mul` detection**: tracks `last_mul_pc` per release, suppresses re-entry of same PC
- **IF/ID kill**: when IF/ID == ID/EX during stall, IF/ID is NOP'd (prevents duplicate advance)
- **`pc_next = if_id_pc + 4`** on release (with fallback to `id_ex_pc + 4` if IF/ID killed)

### 4. Control Hazards
- Branch: predict not-taken, 2-cycle flush penalty on taken
- JAL: resolved in ID, 1-cycle flush penalty
- JALR: resolved in EX, 2-cycle flush penalty

## ALU Mul/Div Fixes

The sequential multiplier/divider needed significant adaptation for pipelined operation:

1. **`effective_op`**: `(multi_active && any_mul_div && op == op_r) ? op_r : op` — uses new `op` immediately when it differs from latched `op_r`
2. **`multi_start`**: first entry immediate (`op_first_mul & !multi_active`), consecutive MULs delayed 1 cycle via `restart_continue` register (so `op_r` captures the new opcode)
3. **Multiplier/divider `.start()`**: gated by `multi_start & flag` instead of raw `flag` (1-cycle pulse avoids `start_rise` never firing for consecutive ops)
4. **`multi_active` clears on `!any_mul_div`**: when MUL actually leaves EX, not when busy drops (avoids infinite restart)
5. **`suppress` input**: connected to `duplicate_mul`, prevents ALU from starting during 1-cycle duplicate detection window

## Files Modified

| File | Changes |
|------|---------|
| `cpu_core.v` | Full 5-stage pipeline: IF/ID, ID/EX, EX/MEM, MEM/WB registers; hazard detection; stall/flush control; forwarding integration; mul/div freeze |
| `ALU.v` | `effective_op` fix; `multi_start` edge-triggered with delayed restart; `suppress` input; `multi_active` clear on `!any_mul_div` |
| `Controller.v` | Full 44-instruction decode; LUI added to `ALU_A_SEL_PC` and `ALU_B_SEL_EXT` (false load-use suppression) |
| `ForwardingUnit.v` | New — EX-stage forwarding with `alua_sel`/`alub_sel` gating |
| `defines.vh` | Extended with all ALU ops, new control signal encodings |

## Files Created

| File | Purpose |
|------|---------|
| `ForwardingUnit.v` | EX-stage forwarding mux selects |

## Verification

- 44/45 Trace tests pass (all except `start`)
- Mul/div results numerically verified correct for all 28 operations across 2 test passes
- No infinite loops, no spurious WB events

## Design Decisions (Updated from original plan)

| Decision | Original Plan | Final Implementation |
|----------|--------------|---------------------|
| Mul/div EX/MEM | NOP during stall | **HOLD** during stall (preserves WB state) |
| PC on MUL release | `pc - 4` | `if_id_pc + 4` (with `id_ex_pc + 4` fallback) |
| Duplicate handling | Not planned | `duplicate_mul` detection + IF/ID kill + ALU suppress |
| ALU multi-start | Simple `mul_flag & !multi_active` | Edge-triggered with 1-cycle delayed restart for consecutive ops |
| `effective_op` | `(op_r != 0) ? op_r : op` | Checks `op == op_r` before using latched `op_r` |
