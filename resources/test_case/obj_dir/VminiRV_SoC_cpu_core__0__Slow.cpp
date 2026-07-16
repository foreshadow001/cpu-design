// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"

VL_ATTR_COLD void VminiRV_SoC_cpu_core___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC_cpu_core* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_2;
    __VdfgRegularize_h6e95ff9d_0_2 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_16;
    __VdfgRegularize_h6e95ff9d_0_16 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_17;
    __VdfgRegularize_h6e95ff9d_0_17 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_18;
    __VdfgRegularize_h6e95ff9d_0_18 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_19;
    __VdfgRegularize_h6e95ff9d_0_19 = 0;
    // Body
    vlSelfRef.ifetch_addr = vlSelfRef.pc;
    vlSelfRef.debug_wb_pc = vlSelfRef.mem_wb_pc;
    vlSelfRef.debug_wb_rf_wR = vlSelfRef.mem_wb_rd;
    vlSelfRef.debug_mem_waddr = vlSelfRef.__PVT__ex_mem_alu_c;
    vlSelfRef.__PVT__U_CU__DOT__ADDI = (IData)((0x00000013U 
                                                == 
                                                (0x0000707fU 
                                                 & vlSelfRef.if_id_inst)));
    vlSelfRef.debug_mem_pc = vlSelfRef.__PVT__ex_mem_pc;
    vlSelfRef.debug_mem_wdata = vlSelfRef.__PVT__store_data_r;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6 = ((IData)(vlSelfRef.__PVT__id_ex_rf_we) 
                                                & (0U 
                                                   != (IData)(vlSelfRef.__PVT__id_ex_rd)));
    vlSelfRef.__PVT__mem_da_wdata = vlSelfRef.__PVT__ex_mem_rd2;
    vlSelfRef.debug_wb_rf_we = ((IData)(vlSelfRef.mem_wb_rf_we) 
                                & (vlSelfRef.mem_wb_pc 
                                   != vlSelfRef.__PVT__last_wb_pc));
    vlSelfRef.__PVT__mem_da_wen = 0U;
    if ((1U == (IData)(vlSelfRef.__PVT__ex_mem_ram_wop))) {
        if ((2U & vlSelfRef.__PVT__ex_mem_alu_c)) {
            if ((1U & vlSelfRef.__PVT__ex_mem_alu_c)) {
                vlSelfRef.__PVT__mem_da_wdata = (vlSelfRef.__PVT__ex_mem_rd2 
                                                 << 0x00000018U);
                vlSelfRef.__PVT__mem_da_wen = 8U;
            } else {
                vlSelfRef.__PVT__mem_da_wdata = (((- (IData)(
                                                             (1U 
                                                              & (vlSelfRef.__PVT__ex_mem_rd2 
                                                                 >> 7U)))) 
                                                  << 0x00000018U) 
                                                 | (0x00ff0000U 
                                                    & (vlSelfRef.__PVT__ex_mem_rd2 
                                                       << 0x00000010U)));
                vlSelfRef.__PVT__mem_da_wen = 4U;
            }
        } else if ((1U & vlSelfRef.__PVT__ex_mem_alu_c)) {
            vlSelfRef.__PVT__mem_da_wdata = (((- (IData)(
                                                         (1U 
                                                          & (vlSelfRef.__PVT__ex_mem_rd2 
                                                             >> 7U)))) 
                                              << 0x00000010U) 
                                             | (0x0000ff00U 
                                                & (vlSelfRef.__PVT__ex_mem_rd2 
                                                   << 8U)));
            vlSelfRef.__PVT__mem_da_wen = 2U;
        } else {
            vlSelfRef.__PVT__mem_da_wdata = (((- (IData)(
                                                         (1U 
                                                          & (vlSelfRef.__PVT__ex_mem_rd2 
                                                             >> 7U)))) 
                                              << 8U) 
                                             | (0x000000ffU 
                                                & vlSelfRef.__PVT__ex_mem_rd2));
            vlSelfRef.__PVT__mem_da_wen = 1U;
        }
    } else if ((3U == (IData)(vlSelfRef.__PVT__ex_mem_ram_wop))) {
        if ((2U & vlSelfRef.__PVT__ex_mem_alu_c)) {
            vlSelfRef.__PVT__mem_da_wdata = (vlSelfRef.__PVT__ex_mem_rd2 
                                             << 0x00000010U);
            vlSelfRef.__PVT__mem_da_wen = 0x0cU;
        } else {
            vlSelfRef.__PVT__mem_da_wdata = (((- (IData)(
                                                         (1U 
                                                          & (vlSelfRef.__PVT__ex_mem_rd2 
                                                             >> 0x0fU)))) 
                                              << 0x00000010U) 
                                             | (0x0000ffffU 
                                                & vlSelfRef.__PVT__ex_mem_rd2));
            vlSelfRef.__PVT__mem_da_wen = 3U;
        }
    } else if ((0x0fU == (IData)(vlSelfRef.__PVT__ex_mem_ram_wop))) {
        if ((0U == (3U & vlSelfRef.__PVT__ex_mem_alu_c))) {
            vlSelfRef.__PVT__mem_da_wen = vlSelfRef.__PVT__ex_mem_ram_wop;
        }
    }
    vlSelfRef.ifetch_req = (1U & (~ (IData)(vlSymsp->TOP.fpga_rst)));
    vlSelfRef.__PVT__U_CU__DOT__LB = (IData)((3U == 
                                              (0x0000707fU 
                                               & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__LBU = (IData)((0x00004003U 
                                               == (0x0000707fU 
                                                   & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__LH = (IData)((0x00001003U 
                                              == (0x0000707fU 
                                                  & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__LHU = (IData)((0x00005003U 
                                               == (0x0000707fU 
                                                   & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__LW = (IData)((0x00002003U 
                                              == (0x0000707fU 
                                                  & vlSelfRef.if_id_inst)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_7 = ((IData)(vlSelfRef.__PVT__id_ex_rd) 
                                                == 
                                                (0x0000001fU 
                                                 & (vlSelfRef.if_id_inst 
                                                    >> 0x0000000fU)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_8 = ((IData)(vlSelfRef.__PVT__id_ex_rd) 
                                                == 
                                                (0x0000001fU 
                                                 & (vlSelfRef.if_id_inst 
                                                    >> 0x00000014U)));
    vlSelfRef.__PVT__U_CU__DOT__SB = (IData)((0x00000023U 
                                              == (0x0000707fU 
                                                  & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__SH = (IData)((0x00001023U 
                                              == (0x0000707fU 
                                                  & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__SW = (IData)((0x00002023U 
                                              == (0x0000707fU 
                                                  & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__SLTI = (IData)((0x00002013U 
                                                == 
                                                (0x0000707fU 
                                                 & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__SLTIU = (IData)((0x00003013U 
                                                 == 
                                                 (0x0000707fU 
                                                  & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__SLT = (IData)((0x00002033U 
                                               == (0xfe00707fU 
                                                   & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__ORI = (IData)((0x00006013U 
                                               == (0x0000707fU 
                                                   & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__SLLI = (IData)((0x00001013U 
                                                == 
                                                (0xfe00707fU 
                                                 & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__XORI = (IData)((0x00004013U 
                                                == 
                                                (0x0000707fU 
                                                 & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__ANDI = (IData)((0x00007013U 
                                                == 
                                                (0x0000707fU 
                                                 & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__JALR = (IData)((0x00000067U 
                                                == 
                                                (0x0000707fU 
                                                 & vlSelfRef.if_id_inst)));
    __VdfgRegularize_h6e95ff9d_0_19 = (IData)((0x00005013U 
                                               == (0x0000707fU 
                                                   & vlSelfRef.if_id_inst)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3 = (IData)(
                                                       (0x00000033U 
                                                        == 
                                                        (0x0000707fU 
                                                         & vlSelfRef.if_id_inst)));
    __VdfgRegularize_h6e95ff9d_0_17 = (IData)((0x00003033U 
                                               == (0x0000707fU 
                                                   & vlSelfRef.if_id_inst)));
    __VdfgRegularize_h6e95ff9d_0_18 = (IData)((0x00001033U 
                                               == (0x0000707fU 
                                                   & vlSelfRef.if_id_inst)));
    __VdfgRegularize_h6e95ff9d_0_16 = (IData)((0x00006033U 
                                               == (0x0000707fU 
                                                   & vlSelfRef.if_id_inst)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14 = (IData)(
                                                        (0x00004033U 
                                                         == 
                                                         (0x0000707fU 
                                                          & vlSelfRef.if_id_inst)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_15 = (IData)(
                                                        (0x00007033U 
                                                         == 
                                                         (0x0000707fU 
                                                          & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__BLT = (IData)((0x00004063U 
                                               == (0x0000707fU 
                                                   & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__BGE = (IData)((0x00005063U 
                                               == (0x0000707fU 
                                                   & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__BLTU = (IData)((0x00006063U 
                                                == 
                                                (0x0000707fU 
                                                 & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__BGEU = (IData)((0x00007063U 
                                                == 
                                                (0x0000707fU 
                                                 & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__BEQ = (IData)((0x00000063U 
                                               == (0x0000707fU 
                                                   & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__U_CU__DOT__BNE = (IData)((0x00001063U 
                                               == (0x0000707fU 
                                                   & vlSelfRef.if_id_inst)));
    __VdfgRegularize_h6e95ff9d_0_2 = (IData)((0x00005033U 
                                              == (0x0000707fU 
                                                  & vlSelfRef.if_id_inst)));
    vlSelfRef.__PVT__ex_mem_fwd_data = ((0U == (IData)(vlSelfRef.__PVT__ex_mem_rf_wsel))
                                         ? vlSelfRef.__PVT__ex_mem_alu_c
                                         : ((3U == (IData)(vlSelfRef.__PVT__ex_mem_rf_wsel))
                                             ? vlSelfRef.__PVT__ex_mem_ext
                                             : vlSelfRef.__PVT__ex_mem_alu_c));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0 = ((IData)(vlSelfRef.__PVT__ex_mem_rf_we) 
                                                & (0U 
                                                   != (IData)(vlSelfRef.__PVT__ex_mem_rd)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1 = ((IData)(vlSelfRef.mem_wb_rf_we) 
                                                & (0U 
                                                   != (IData)(vlSelfRef.mem_wb_rd)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_9 = ((2U 
                                                 == (IData)(vlSelfRef.mem_wb_rf_wsel))
                                                 ? 
                                                ((IData)(4U) 
                                                 + vlSelfRef.mem_wb_pc)
                                                 : 
                                                (vlSelfRef.mem_wb_ext 
                                                 & (- (IData)(
                                                              (3U 
                                                               == (IData)(vlSelfRef.mem_wb_rf_wsel))))));
    vlSelfRef.__PVT__U_MEXT__DOT__aligned = ((1U == (IData)(vlSelfRef.__PVT__mem_wb_byte_offs))
                                              ? (vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_rdata 
                                                 >> 8U)
                                              : ((2U 
                                                  == (IData)(vlSelfRef.__PVT__mem_wb_byte_offs))
                                                  ? 
                                                 (vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_rdata 
                                                  >> 0x00000010U)
                                                  : 
                                                 ((3U 
                                                   == (IData)(vlSelfRef.__PVT__mem_wb_byte_offs))
                                                   ? 
                                                  (vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_rdata 
                                                   >> 0x00000018U)
                                                   : vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_rdata)));
    vlSelfRef.debug_mem_we = vlSelfRef.__PVT__mem_da_wen;
    vlSelfRef.ifetch_valid = ((~ (IData)(vlSymsp->TOP.fpga_rst)) 
                              & (IData)(vlSelfRef.ifetch_req));
    vlSelfRef.__PVT__U_CU__DOT__WB_OP_RAM = ((IData)(vlSelfRef.__PVT__U_CU__DOT__LW) 
                                             | ((IData)(vlSelfRef.__PVT__U_CU__DOT__LB) 
                                                | ((IData)(vlSelfRef.__PVT__U_CU__DOT__LBU) 
                                                   | ((IData)(vlSelfRef.__PVT__U_CU__DOT__LH) 
                                                      | (IData)(vlSelfRef.__PVT__U_CU__DOT__LHU)))));
    vlSelfRef.__PVT__load_use_stall = ((0U != (IData)(vlSelfRef.__PVT__id_ex_ram_rop)) 
                                       & (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_7) 
                                           | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_8)) 
                                          & (0U != (IData)(vlSelfRef.__PVT__id_ex_rd))));
    vlSelfRef.__PVT__U_CU__DOT__EXT_OP_S = ((IData)(vlSelfRef.__PVT__U_CU__DOT__SB) 
                                            | ((IData)(vlSelfRef.__PVT__U_CU__DOT__SW) 
                                               | (IData)(vlSelfRef.__PVT__U_CU__DOT__SH)));
    vlSelfRef.__PVT__U_CU__DOT__WB_OP_PC4 = ((0x6fU 
                                              == (0x0000007fU 
                                                  & vlSelfRef.if_id_inst)) 
                                             | (IData)(vlSelfRef.__PVT__U_CU__DOT__JALR));
    vlSelfRef.__PVT__U_CU__DOT__SRLI = ((0U == (vlSelfRef.if_id_inst 
                                                >> 0x00000019U)) 
                                        & (IData)(__VdfgRegularize_h6e95ff9d_0_19));
    vlSelfRef.__PVT__U_CU__DOT__SRAI = ((0x20U == (vlSelfRef.if_id_inst 
                                                   >> 0x00000019U)) 
                                        & (IData)(__VdfgRegularize_h6e95ff9d_0_19));
    vlSelfRef.__PVT__U_CU__DOT__SUB = ((0x20U == (vlSelfRef.if_id_inst 
                                                  >> 0x00000019U)) 
                                       & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3));
    vlSelfRef.__PVT__U_CU__DOT__MUL = ((1U == (vlSelfRef.if_id_inst 
                                               >> 0x00000019U)) 
                                       & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3));
    vlSelfRef.__PVT__U_CU__DOT__SLTU = ((0U == (vlSelfRef.if_id_inst 
                                                >> 0x00000019U)) 
                                        & (IData)(__VdfgRegularize_h6e95ff9d_0_17));
    vlSelfRef.__PVT__U_CU__DOT__MULHU = ((1U == (vlSelfRef.if_id_inst 
                                                 >> 0x00000019U)) 
                                         & (IData)(__VdfgRegularize_h6e95ff9d_0_17));
    vlSelfRef.__PVT__U_CU__DOT__SLL = ((0U == (vlSelfRef.if_id_inst 
                                               >> 0x00000019U)) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_18));
    vlSelfRef.__PVT__U_CU__DOT__MULH = ((1U == (vlSelfRef.if_id_inst 
                                                >> 0x00000019U)) 
                                        & (IData)(__VdfgRegularize_h6e95ff9d_0_18));
    vlSelfRef.__PVT__U_CU__DOT__OR = ((0U == (vlSelfRef.if_id_inst 
                                              >> 0x00000019U)) 
                                      & (IData)(__VdfgRegularize_h6e95ff9d_0_16));
    vlSelfRef.__PVT__U_CU__DOT__REM = ((1U == (vlSelfRef.if_id_inst 
                                               >> 0x00000019U)) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_16));
    vlSelfRef.__PVT__U_CU__DOT__ALU_OP_XOR = ((IData)(vlSelfRef.__PVT__U_CU__DOT__XORI) 
                                              | ((0U 
                                                  == 
                                                  (vlSelfRef.if_id_inst 
                                                   >> 0x00000019U)) 
                                                 & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14)));
    vlSelfRef.__PVT__U_CU__DOT__DIV = ((1U == (vlSelfRef.if_id_inst 
                                               >> 0x00000019U)) 
                                       & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14));
    vlSelfRef.__PVT__U_CU__DOT__ALU_OP_AND = ((IData)(vlSelfRef.__PVT__U_CU__DOT__ANDI) 
                                              | ((0U 
                                                  == 
                                                  (vlSelfRef.if_id_inst 
                                                   >> 0x00000019U)) 
                                                 & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_15)));
    vlSelfRef.__PVT__U_CU__DOT__REMU = ((1U == (vlSelfRef.if_id_inst 
                                                >> 0x00000019U)) 
                                        & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_15));
    vlSelfRef.__PVT__U_CU__DOT__NPC_OP_BRA = ((IData)(vlSelfRef.__PVT__U_CU__DOT__BEQ) 
                                              | ((IData)(vlSelfRef.__PVT__U_CU__DOT__BNE) 
                                                 | ((IData)(vlSelfRef.__PVT__U_CU__DOT__BLT) 
                                                    | ((IData)(vlSelfRef.__PVT__U_CU__DOT__BGE) 
                                                       | ((IData)(vlSelfRef.__PVT__U_CU__DOT__BGEU) 
                                                          | (IData)(vlSelfRef.__PVT__U_CU__DOT__BLTU))))));
    vlSelfRef.__PVT__U_CU__DOT__SRL = ((0U == (vlSelfRef.if_id_inst 
                                               >> 0x00000019U)) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_2));
    vlSelfRef.__PVT__U_CU__DOT__SRA = ((0x20U == (vlSelfRef.if_id_inst 
                                                  >> 0x00000019U)) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_2));
    vlSelfRef.__PVT__U_CU__DOT__DIVU = ((1U == (vlSelfRef.if_id_inst 
                                                >> 0x00000019U)) 
                                        & (IData)(__VdfgRegularize_h6e95ff9d_0_2));
    vlSelfRef.forward_b = (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0) 
                            & ((~ (IData)(vlSelfRef.id_ex_alub_sel)) 
                               & ((IData)(vlSelfRef.id_ex_rs2) 
                                  == (IData)(vlSelfRef.__PVT__ex_mem_rd))))
                            ? 1U : (2U & (- (IData)(
                                                    ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1) 
                                                     & ((~ (IData)(vlSelfRef.id_ex_alub_sel)) 
                                                        & ((IData)(vlSelfRef.id_ex_rs2) 
                                                           == (IData)(vlSelfRef.mem_wb_rd))))))));
    vlSelfRef.__PVT__U_FWD__DOT__forward_a = (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0) 
                                               & ((~ (IData)(vlSelfRef.__PVT__id_ex_alua_sel)) 
                                                  & ((IData)(vlSelfRef.id_ex_rs1) 
                                                     == (IData)(vlSelfRef.__PVT__ex_mem_rd))))
                                               ? 1U
                                               : (2U 
                                                  & (- (IData)(
                                                               ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1) 
                                                                & ((~ (IData)(vlSelfRef.__PVT__id_ex_alua_sel)) 
                                                                   & ((IData)(vlSelfRef.id_ex_rs1) 
                                                                      == (IData)(vlSelfRef.mem_wb_rd))))))));
    vlSelfRef.__PVT__U_MEXT__DOT__ext = ((((4U & (IData)(vlSelfRef.__PVT__mem_wb_ram_rop))
                                            ? ((0x00ffff00U 
                                                & (((2U 
                                                     & (IData)(vlSelfRef.__PVT__mem_wb_ram_rop))
                                                     ? 
                                                    (vlSelfRef.__PVT__U_MEXT__DOT__aligned 
                                                     >> 0x00000010U)
                                                     : 
                                                    ((- (IData)(
                                                                (1U 
                                                                 & (vlSelfRef.__PVT__U_MEXT__DOT__aligned 
                                                                    >> 0x0000000fU)))) 
                                                     & (- (IData)(
                                                                  (1U 
                                                                   & (~ (IData)(vlSelfRef.__PVT__mem_wb_ram_rop))))))) 
                                                   << 8U)) 
                                               | (0x000000ffU 
                                                  & (vlSelfRef.__PVT__U_MEXT__DOT__aligned 
                                                     >> 8U)))
                                            : ((2U 
                                                & (IData)(vlSelfRef.__PVT__mem_wb_ram_rop))
                                                ? (
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlSelfRef.__PVT__U_MEXT__DOT__aligned 
                                                                  >> 7U)))) 
                                                   & (- (IData)(
                                                                (1U 
                                                                 & (~ (IData)(vlSelfRef.__PVT__mem_wb_ram_rop))))))
                                                : (vlSelfRef.__PVT__U_MEXT__DOT__aligned 
                                                   >> 8U))) 
                                          << 8U) | 
                                         (0x000000ffU 
                                          & vlSelfRef.__PVT__U_MEXT__DOT__aligned));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_22 = ((0x17U 
                                                  == 
                                                  (0x0000007fU 
                                                   & vlSelfRef.if_id_inst)) 
                                                 | (IData)(vlSelfRef.__PVT__U_CU__DOT__WB_OP_PC4));
    vlSelfRef.__PVT__U_CU__DOT__is_mul = ((IData)(vlSelfRef.__PVT__U_CU__DOT__MUL) 
                                          | ((IData)(vlSelfRef.__PVT__U_CU__DOT__MULHU) 
                                             | (IData)(vlSelfRef.__PVT__U_CU__DOT__MULH)));
    vlSelfRef.__PVT__U_CU__DOT__sext_op = ((1U & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__EXT_OP_S)))) 
                                           | ((2U & 
                                               (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__NPC_OP_BRA)))) 
                                              | ((3U 
                                                  & (- (IData)(
                                                               ((0x17U 
                                                                 == 
                                                                 (0x0000007fU 
                                                                  & vlSelfRef.if_id_inst)) 
                                                                | (0x37U 
                                                                   == 
                                                                   (0x0000007fU 
                                                                    & vlSelfRef.if_id_inst)))))) 
                                                 | (4U 
                                                    & (- (IData)(
                                                                 (0x6fU 
                                                                  == 
                                                                  (0x0000007fU 
                                                                   & vlSelfRef.if_id_inst))))))));
    vlSelfRef.__PVT__U_CU__DOT__npc_op = (3U & ((1U 
                                                 & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__JALR)))) 
                                                | ((2U 
                                                    & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__NPC_OP_BRA)))) 
                                                   | (- (IData)(
                                                                (0x6fU 
                                                                 == 
                                                                 (0x0000007fU 
                                                                  & vlSelfRef.if_id_inst)))))));
    vlSelfRef.__PVT__U_CU__DOT__is_div = ((IData)(vlSelfRef.__PVT__U_CU__DOT__DIV) 
                                          | ((IData)(vlSelfRef.__PVT__U_CU__DOT__DIVU) 
                                             | ((IData)(vlSelfRef.__PVT__U_CU__DOT__REMU) 
                                                | (IData)(vlSelfRef.__PVT__U_CU__DOT__REM))));
    vlSelfRef.__PVT__U_CU__DOT__alu_op = ((1U & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__SUB)))) 
                                          | ((2U & 
                                              (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__ALU_OP_XOR)))) 
                                             | ((4U 
                                                 & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__ALU_OP_AND)))) 
                                                | ((3U 
                                                    & (- (IData)(
                                                                 ((IData)(vlSelfRef.__PVT__U_CU__DOT__ORI) 
                                                                  | (IData)(vlSelfRef.__PVT__U_CU__DOT__OR))))) 
                                                   | ((0x0aU 
                                                       & (- (IData)(
                                                                    ((IData)(vlSelfRef.__PVT__U_CU__DOT__SLTI) 
                                                                     | ((IData)(vlSelfRef.__PVT__U_CU__DOT__BLT) 
                                                                        | (IData)(vlSelfRef.__PVT__U_CU__DOT__SLT)))))) 
                                                      | ((0x0bU 
                                                          & (- (IData)(
                                                                       ((IData)(vlSelfRef.__PVT__U_CU__DOT__SLTIU) 
                                                                        | ((IData)(vlSelfRef.__PVT__U_CU__DOT__BLTU) 
                                                                           | (IData)(vlSelfRef.__PVT__U_CU__DOT__SLTU)))))) 
                                                         | ((0x17U 
                                                             & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__BGE)))) 
                                                            | ((0x18U 
                                                                & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__BGEU)))) 
                                                               | ((0x10U 
                                                                   & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__MUL)))) 
                                                                  | ((0x11U 
                                                                      & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__MULH)))) 
                                                                     | ((0x12U 
                                                                         & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__MULHU)))) 
                                                                        | ((0x13U 
                                                                            & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__DIV)))) 
                                                                           | ((0x14U 
                                                                               & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__DIVU)))) 
                                                                              | ((0x15U 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__REM)))) 
                                                                                | ((0x16U 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__REMU)))) 
                                                                                | ((5U 
                                                                                & (- (IData)(
                                                                                ((IData)(vlSelfRef.__PVT__U_CU__DOT__SLL) 
                                                                                | (IData)(vlSelfRef.__PVT__U_CU__DOT__SLLI))))) 
                                                                                | ((6U 
                                                                                & (- (IData)(
                                                                                ((IData)(vlSelfRef.__PVT__U_CU__DOT__SRL) 
                                                                                | (IData)(vlSelfRef.__PVT__U_CU__DOT__SRLI))))) 
                                                                                | ((7U 
                                                                                & (- (IData)(
                                                                                ((IData)(vlSelfRef.__PVT__U_CU__DOT__SRA) 
                                                                                | (IData)(vlSelfRef.__PVT__U_CU__DOT__SRAI))))) 
                                                                                | ((8U 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__BEQ)))) 
                                                                                | (9U 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__BNE)))))))))))))))))))))));
    vlSelfRef.__PVT__U_RF__DOT__wD = ((1U == (IData)(vlSelfRef.mem_wb_rf_wsel))
                                       ? vlSelfRef.__PVT__U_MEXT__DOT__ext
                                       : ((0U == (IData)(vlSelfRef.mem_wb_rf_wsel))
                                           ? vlSelfRef.__PVT__mem_wb_alu_c
                                           : vlSelfRef.__VdfgRegularize_h6e95ff9d_0_9));
    vlSelfRef.__PVT__wb_forward_data = ((0U == (IData)(vlSelfRef.mem_wb_rf_wsel))
                                         ? vlSelfRef.__PVT__mem_wb_alu_c
                                         : ((1U == (IData)(vlSelfRef.mem_wb_rf_wsel))
                                             ? vlSelfRef.__PVT__U_MEXT__DOT__ext
                                             : vlSelfRef.__VdfgRegularize_h6e95ff9d_0_9));
    vlSelfRef.__PVT__U_SEXT__DOT__ext = ((4U & (IData)(vlSelfRef.__PVT__U_CU__DOT__sext_op))
                                          ? ((- (IData)(
                                                        (1U 
                                                         & (~ (IData)(vlSelfRef.__PVT__U_CU__DOT__sext_op))))) 
                                             & (((((0x00000ffeU 
                                                    & ((- (IData)(
                                                                  (vlSelfRef.if_id_inst 
                                                                   >> 0x0000001fU))) 
                                                       << 1U)) 
                                                   | (vlSelfRef.if_id_inst 
                                                      >> 0x0000001fU)) 
                                                  << 0x00000014U) 
                                                 | ((((0x000001feU 
                                                       & (vlSelfRef.if_id_inst 
                                                          >> 0x0000000bU)) 
                                                      | (1U 
                                                         & (vlSelfRef.if_id_inst 
                                                            >> 0x00000014U))) 
                                                     << 0x0000000bU) 
                                                    | (0x000007feU 
                                                       & (vlSelfRef.if_id_inst 
                                                          >> 0x00000014U)))) 
                                                & (- (IData)(
                                                             (1U 
                                                              & (~ 
                                                                 ((IData)(vlSelfRef.__PVT__U_CU__DOT__sext_op) 
                                                                  >> 1U)))))))
                                          : ((2U & (IData)(vlSelfRef.__PVT__U_CU__DOT__sext_op))
                                              ? (((1U 
                                                   & (IData)(vlSelfRef.__PVT__U_CU__DOT__sext_op))
                                                   ? 
                                                  (0x7ffff800U 
                                                   & (vlSelfRef.if_id_inst 
                                                      >> 1U))
                                                   : 
                                                  ((0x7ffff000U 
                                                    & ((- (IData)(
                                                                  (vlSelfRef.if_id_inst 
                                                                   >> 0x0000001fU))) 
                                                       << 0x0000000cU)) 
                                                   | ((((2U 
                                                         & (vlSelfRef.if_id_inst 
                                                            >> 0x0000001eU)) 
                                                        | (1U 
                                                           & (vlSelfRef.if_id_inst 
                                                              >> 7U))) 
                                                       << 0x0000000aU) 
                                                      | ((0x000003f0U 
                                                          & (vlSelfRef.if_id_inst 
                                                             >> 0x00000015U)) 
                                                         | (0x0000000fU 
                                                            & (vlSelfRef.if_id_inst 
                                                               >> 8U)))))) 
                                                 << 1U)
                                              : (((- (IData)(
                                                             (vlSelfRef.if_id_inst 
                                                              >> 0x0000001fU))) 
                                                  << 0x0000000cU) 
                                                 | ((0x00000fe0U 
                                                     & (vlSelfRef.if_id_inst 
                                                        >> 0x00000014U)) 
                                                    | (0x0000001fU 
                                                       & ((1U 
                                                           & (IData)(vlSelfRef.__PVT__U_CU__DOT__sext_op))
                                                           ? 
                                                          (vlSelfRef.if_id_inst 
                                                           >> 7U)
                                                           : 
                                                          (vlSelfRef.if_id_inst 
                                                           >> 0x00000014U)))))));
    vlSelfRef.__PVT__id_mul_div = ((IData)(vlSelfRef.__PVT__U_CU__DOT__is_mul) 
                                   | (IData)(vlSelfRef.__PVT__U_CU__DOT__is_div));
    vlSelfRef.debug_wb_rf_wD = vlSelfRef.__PVT__U_RF__DOT__wD;
    vlSelfRef.ex_alu_b = ((1U == (IData)(vlSelfRef.forward_b))
                           ? vlSelfRef.__PVT__ex_mem_fwd_data
                           : ((2U == (IData)(vlSelfRef.forward_b))
                               ? vlSelfRef.__PVT__wb_forward_data
                               : ((IData)(vlSelfRef.id_ex_alub_sel)
                                   ? vlSelfRef.id_ex_ext
                                   : vlSelfRef.__PVT__id_ex_rd2)));
    vlSelfRef.__PVT__id_br_target = (vlSelfRef.if_id_pc 
                                     + vlSelfRef.__PVT__U_SEXT__DOT__ext);
}

VL_ATTR_COLD void VminiRV_SoC_cpu_core___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__1(VminiRV_SoC_cpu_core* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__1\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ex_br_taken = ((2U == (IData)(vlSelfRef.__PVT__id_ex_npc_op)) 
                             & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__br));
    vlSelfRef.ex_alu_c = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__c;
    vlSelfRef.flush_d = ((IData)(vlSelfRef.ex_br_taken) 
                         | ((1U == (IData)(vlSelfRef.__PVT__id_ex_npc_op)) 
                            | (IData)(vlSelfRef.__PVT__load_use_stall)));
}

VL_ATTR_COLD void VminiRV_SoC_cpu_core___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__2(VminiRV_SoC_cpu_core* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__2\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__mul_div_stall = ((IData)(vlSelfRef.__PVT__mul_div_entering) 
                                      | (((IData)(vlSelfRef.__PVT__id_ex_is_mul) 
                                          | (IData)(vlSelfRef.__PVT__id_ex_is_div)) 
                                         & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__busy)));
    vlSelfRef.stall_d = vlSelfRef.__PVT__mul_div_stall;
    vlSelfRef.__PVT__mul_div_release = ((~ (IData)(vlSelfRef.__PVT__mul_div_stall)) 
                                        & (IData)(vlSelfRef.__PVT__mul_div_stall_d));
    vlSelfRef.__PVT__pc_next = ((IData)(vlSelfRef.__PVT__mul_div_release)
                                 ? (vlSelfRef.pc - (IData)(4U))
                                 : ((IData)(vlSelfRef.ex_br_taken)
                                     ? vlSelfRef.__PVT__id_ex_br_target
                                     : ((1U == (IData)(vlSelfRef.__PVT__id_ex_npc_op))
                                         ? (0xfffffffeU 
                                            & vlSelfRef.ex_alu_c)
                                         : ((3U == (IData)(vlSelfRef.__PVT__U_CU__DOT__npc_op))
                                             ? vlSelfRef.__PVT__id_br_target
                                             : ((IData)(4U) 
                                                + vlSelfRef.pc)))));
    vlSelfRef.flush_f = ((3U == (IData)(vlSelfRef.__PVT__U_CU__DOT__npc_op)) 
                         | ((IData)(vlSelfRef.ex_br_taken) 
                            | ((1U == (IData)(vlSelfRef.__PVT__id_ex_npc_op)) 
                               | (IData)(vlSelfRef.__PVT__mul_div_release))));
    vlSelfRef.__PVT__effective_flush = ((IData)(vlSelfRef.flush_f) 
                                        | ((IData)(vlSelfRef.__PVT__flush_next) 
                                           | ((IData)(vlSelfRef.flush_next2) 
                                              | ((IData)(vlSelfRef.load_resync) 
                                                 | (IData)(vlSelfRef.__PVT__load_resync2)))));
    vlSelfRef.__PVT__load_stall_active = ((~ (IData)(vlSelfRef.flush_f)) 
                                          & (IData)(vlSelfRef.__PVT__load_use_stall));
    vlSelfRef.stall_f = ((~ (IData)(vlSelfRef.flush_f)) 
                         & ((IData)(vlSelfRef.__PVT__load_stall_active) 
                            | (IData)(vlSelfRef.__PVT__mul_div_stall)));
}

VL_ATTR_COLD void VminiRV_SoC_cpu_core___ctor_var_reset(VminiRV_SoC_cpu_core* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___ctor_var_reset\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->__PVT__cpu_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3291203161397430340ull);
    vlSelf->__PVT__cpu_clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1778734116331908092ull);
    vlSelf->ifetch_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13988598673442078761ull);
    vlSelf->ifetch_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 350717475051527729ull);
    vlSelf->ifetch_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6811466923363536727ull);
    vlSelf->__PVT__ifetch_inst = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8558606901877018110ull);
    vlSelf->__PVT__daccess_ren = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15596693531133668067ull);
    vlSelf->__PVT__daccess_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13107628966763336906ull);
    vlSelf->__PVT__daccess_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 727624420842126878ull);
    vlSelf->__PVT__daccess_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9338636961853158484ull);
    vlSelf->__PVT__daccess_wen = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11979066971063036917ull);
    vlSelf->__PVT__daccess_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14139082339821019062ull);
    vlSelf->__PVT__daccess_wresp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13544389067558286709ull);
    vlSelf->pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4211327832146562899ull);
    vlSelf->fetch_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1783992286795620984ull);
    vlSelf->__PVT__flush_next = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14033508906544510833ull);
    vlSelf->flush_next2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11013695746701444480ull);
    vlSelf->load_resync = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7875211009995643209ull);
    vlSelf->__PVT__load_resync2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16095681743774838306ull);
    vlSelf->__PVT__load_stall_active = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4599639717584953615ull);
    vlSelf->__PVT__stall_synced = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6272021242325694807ull);
    vlSelf->__PVT__effective_flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15907288743082328285ull);
    vlSelf->if_id_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3714999190566275027ull);
    vlSelf->if_id_inst = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7783103429203213670ull);
    vlSelf->__PVT__id_br_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1439488230337312721ull);
    vlSelf->id_ex_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8227801926672923065ull);
    vlSelf->__PVT__id_ex_rd1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13357851876858741730ull);
    vlSelf->__PVT__id_ex_rd2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6743237858806109672ull);
    vlSelf->id_ex_ext = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6875244709410966152ull);
    vlSelf->__PVT__id_ex_br_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1123445908512789980ull);
    vlSelf->id_ex_alu_op = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6344149315736107156ull);
    vlSelf->__PVT__id_ex_alua_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11501279645200606534ull);
    vlSelf->id_ex_alub_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16638054830832199037ull);
    vlSelf->__PVT__id_ex_rf_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 180382528549294641ull);
    vlSelf->__PVT__id_ex_rf_wsel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1164546906498462449ull);
    vlSelf->__PVT__id_ex_ram_rop = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8679149984107597168ull);
    vlSelf->__PVT__id_ex_ram_wop = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12445201525654381612ull);
    vlSelf->__PVT__id_ex_is_mul = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8127241264395841238ull);
    vlSelf->__PVT__id_ex_is_div = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10520526865974539272ull);
    vlSelf->id_ex_rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6852308722992195068ull);
    vlSelf->id_ex_rs2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17143458124409410272ull);
    vlSelf->__PVT__id_ex_rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 63367195500711501ull);
    vlSelf->__PVT__id_ex_npc_op = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9092934799597251182ull);
    vlSelf->__PVT__load_use_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3340987187204866703ull);
    vlSelf->ex_br_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9629840222784088888ull);
    vlSelf->__PVT__mul_div_flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6346158944784609938ull);
    vlSelf->flush_f = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9194322461003894836ull);
    vlSelf->flush_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12157993274752035746ull);
    vlSelf->__PVT__pc_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6559071652263501277ull);
    vlSelf->__PVT__mul_div_entering = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7774015482136585894ull);
    vlSelf->__PVT__id_mul_div = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8685565073389472101ull);
    vlSelf->__PVT__mul_div_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 753458014284029301ull);
    vlSelf->__PVT__mul_div_stall_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1693303049386723523ull);
    vlSelf->__PVT__mul_div_release = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17932029376591680289ull);
    vlSelf->stall_f = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8063790051519579766ull);
    vlSelf->stall_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1425001533980491023ull);
    vlSelf->forward_b = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1405274818540712582ull);
    vlSelf->__PVT__ex_mem_fwd_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5902524509580108082ull);
    vlSelf->ex_alu_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11276294523137515889ull);
    vlSelf->ex_alu_c = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11626381262027565457ull);
    vlSelf->__PVT__ex_mem_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13319499437008714072ull);
    vlSelf->__PVT__ex_mem_alu_c = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6059797838304090016ull);
    vlSelf->__PVT__ex_mem_rd2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12192200440604879771ull);
    vlSelf->__PVT__ex_mem_ext = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1456972988757778566ull);
    vlSelf->__PVT__ex_mem_br = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7134110505075767235ull);
    vlSelf->__PVT__ex_mem_rf_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10283157880512968553ull);
    vlSelf->__PVT__ex_mem_rf_wsel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 28900988178740214ull);
    vlSelf->__PVT__ex_mem_ram_rop = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11073095012645995173ull);
    vlSelf->__PVT__ex_mem_ram_wop = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2588229651271269033ull);
    vlSelf->__PVT__ex_mem_rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15488483898575448744ull);
    vlSelf->__PVT__ex_mem_is_mul = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3208079301134724640ull);
    vlSelf->__PVT__ex_mem_is_div = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8998738319882196420ull);
    vlSelf->__PVT__mem_da_wen = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4475258233511521394ull);
    vlSelf->__PVT__mem_da_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15823647845132456445ull);
    vlSelf->mem_wb_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8395010496922727201ull);
    vlSelf->__PVT__mem_wb_alu_c = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5519282975193672736ull);
    vlSelf->mem_wb_ext = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16436526174555004321ull);
    vlSelf->mem_wb_rf_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14791182224258261904ull);
    vlSelf->mem_wb_rf_wsel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3708431576921598234ull);
    vlSelf->mem_wb_rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8506654544299532341ull);
    vlSelf->__PVT__mem_wb_ram_rop = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2920514517607000655ull);
    vlSelf->__PVT__mem_wb_byte_offs = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16303115511012922465ull);
    vlSelf->__PVT__wb_forward_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5576574879040977113ull);
    vlSelf->debug_wb_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6075763121981089365ull);
    vlSelf->debug_wb_rf_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1778091111374526266ull);
    vlSelf->debug_wb_rf_wR = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3400022790968849549ull);
    vlSelf->debug_wb_rf_wD = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2766513357858672243ull);
    vlSelf->debug_mem_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17148620087140646525ull);
    vlSelf->debug_mem_we = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6888492429864618669ull);
    vlSelf->debug_mem_waddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7626575431285814964ull);
    vlSelf->debug_mem_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14422704713290713356ull);
    vlSelf->__PVT__store_data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14964709395055876958ull);
    vlSelf->__PVT__last_wb_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11948907237839288619ull);
    vlSelf->__PVT__U_MEXT__DOT__ext = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9777731372355035530ull);
    vlSelf->__PVT__U_MEXT__DOT__aligned = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2798817366644745278ull);
    vlSelf->__PVT__U_FWD__DOT__forward_a = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16228311343781913140ull);
    vlSelf->__PVT__U_SEXT__DOT__ext = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3772305779136611616ull);
    vlSelf->__PVT__U_RF__DOT__wD = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2338712356774897892ull);
    for (int __Vi0 = 0; __Vi0 < 31; ++__Vi0) {
        vlSelf->__PVT__U_RF__DOT__regs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5291467431221063363ull);
    }
    vlSelf->__PVT__U_CU__DOT__npc_op = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11356328313947222872ull);
    vlSelf->__PVT__U_CU__DOT__sext_op = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9774058925445894686ull);
    vlSelf->__PVT__U_CU__DOT__alu_op = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7876591833629442608ull);
    vlSelf->__PVT__U_CU__DOT__is_mul = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14108566982199595895ull);
    vlSelf->__PVT__U_CU__DOT__is_div = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18105734016502943832ull);
    vlSelf->__PVT__U_CU__DOT__ADDI = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13351754805057559634ull);
    vlSelf->__PVT__U_CU__DOT__SUB = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5201936181351543553ull);
    vlSelf->__PVT__U_CU__DOT__XORI = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14704224623502839274ull);
    vlSelf->__PVT__U_CU__DOT__ANDI = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8220862927762717622ull);
    vlSelf->__PVT__U_CU__DOT__OR = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10933441594312694304ull);
    vlSelf->__PVT__U_CU__DOT__SLTI = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15883451816216027902ull);
    vlSelf->__PVT__U_CU__DOT__SLTIU = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17112836561729480892ull);
    vlSelf->__PVT__U_CU__DOT__SLT = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7958379657712640385ull);
    vlSelf->__PVT__U_CU__DOT__SLTU = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18061753986109785328ull);
    vlSelf->__PVT__U_CU__DOT__BLT = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16890997336715384193ull);
    vlSelf->__PVT__U_CU__DOT__BGE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11784200544887964886ull);
    vlSelf->__PVT__U_CU__DOT__BLTU = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14122911987683431402ull);
    vlSelf->__PVT__U_CU__DOT__BGEU = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10983899180111450872ull);
    vlSelf->__PVT__U_CU__DOT__JALR = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9301576613476241068ull);
    vlSelf->__PVT__U_CU__DOT__LB = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9737637992888366236ull);
    vlSelf->__PVT__U_CU__DOT__LBU = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9394685547017346355ull);
    vlSelf->__PVT__U_CU__DOT__LH = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5339836140400082971ull);
    vlSelf->__PVT__U_CU__DOT__LHU = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14613260138172002134ull);
    vlSelf->__PVT__U_CU__DOT__SB = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6901110351831404029ull);
    vlSelf->__PVT__U_CU__DOT__SH = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8374548510242471866ull);
    vlSelf->__PVT__U_CU__DOT__SW = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14360833122405608587ull);
    vlSelf->__PVT__U_CU__DOT__MUL = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 975691689551424054ull);
    vlSelf->__PVT__U_CU__DOT__MULH = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17481802356835529221ull);
    vlSelf->__PVT__U_CU__DOT__MULHU = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17892959734818410540ull);
    vlSelf->__PVT__U_CU__DOT__DIV = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8375916581770993905ull);
    vlSelf->__PVT__U_CU__DOT__DIVU = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6646611475864061748ull);
    vlSelf->__PVT__U_CU__DOT__REM = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1500810019920022232ull);
    vlSelf->__PVT__U_CU__DOT__REMU = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13081504579486005451ull);
    vlSelf->__PVT__U_CU__DOT__ORI = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8720531004048326149ull);
    vlSelf->__PVT__U_CU__DOT__SLLI = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10351367793833166257ull);
    vlSelf->__PVT__U_CU__DOT__SRLI = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 930646014164179230ull);
    vlSelf->__PVT__U_CU__DOT__SRAI = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9156208535915462686ull);
    vlSelf->__PVT__U_CU__DOT__SLL = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12309133033405962194ull);
    vlSelf->__PVT__U_CU__DOT__SRL = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7225712731001690525ull);
    vlSelf->__PVT__U_CU__DOT__SRA = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11146741053519461569ull);
    vlSelf->__PVT__U_CU__DOT__LW = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18223974386066428881ull);
    vlSelf->__PVT__U_CU__DOT__BEQ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10383672445696283211ull);
    vlSelf->__PVT__U_CU__DOT__BNE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14532018258220533184ull);
    vlSelf->__PVT__U_CU__DOT__NPC_OP_BRA = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10683143667182966686ull);
    vlSelf->__PVT__U_CU__DOT__WB_OP_RAM = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4669417168895849925ull);
    vlSelf->__PVT__U_CU__DOT__WB_OP_PC4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2967703514271865806ull);
    vlSelf->__PVT__U_CU__DOT__EXT_OP_S = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3522002849948645477ull);
    vlSelf->__PVT__U_CU__DOT__ALU_OP_XOR = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8982874190829170ull);
    vlSelf->__PVT__U_CU__DOT__ALU_OP_AND = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11119754100971358617ull);
    vlSelf->__VdfgRegularize_h6e95ff9d_0_0 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_1 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_3 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_6 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_7 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_8 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_9 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_14 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_15 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_22 = 0;
    vlSelf->__VdlyVal__U_RF__DOT__regs__v0 = 0;
    vlSelf->__VdlyDim0__U_RF__DOT__regs__v0 = 0;
    vlSelf->__VdlySet__U_RF__DOT__regs__v0 = 0;
}
