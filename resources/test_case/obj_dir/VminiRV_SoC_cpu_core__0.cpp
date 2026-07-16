// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"

void VminiRV_SoC_cpu_core___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC_cpu_core* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__0\n"); );
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
    vlSelfRef.__PVT__U_CU__DOT__ADDI = (IData)((0x00000013U 
                                                == 
                                                (0x0000707fU 
                                                 & vlSelfRef.if_id_inst)));
    vlSelfRef.debug_wb_rf_we = ((IData)(vlSelfRef.mem_wb_rf_we) 
                                & (vlSelfRef.mem_wb_pc 
                                   != vlSelfRef.__PVT__last_wb_pc));
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
    vlSelfRef.debug_wb_rf_wD = vlSelfRef.__PVT__U_RF__DOT__wD;
    vlSelfRef.ex_alu_b = ((1U == (IData)(vlSelfRef.forward_b))
                           ? vlSelfRef.__PVT__ex_mem_fwd_data
                           : ((2U == (IData)(vlSelfRef.forward_b))
                               ? vlSelfRef.__PVT__wb_forward_data
                               : ((IData)(vlSelfRef.id_ex_alub_sel)
                                   ? vlSelfRef.id_ex_ext
                                   : vlSelfRef.__PVT__id_ex_rd2)));
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
    vlSelfRef.__PVT__id_br_target = (vlSelfRef.if_id_pc 
                                     + vlSelfRef.__PVT__U_SEXT__DOT__ext);
}

void VminiRV_SoC_cpu_core___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__1(VminiRV_SoC_cpu_core* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__1\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ex_br_taken = ((2U == (IData)(vlSelfRef.__PVT__id_ex_npc_op)) 
                             & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__br));
    vlSelfRef.__PVT__mul_div_stall = ((IData)(vlSelfRef.__PVT__mul_div_entering) 
                                      | (((IData)(vlSelfRef.__PVT__id_ex_is_mul) 
                                          | (IData)(vlSelfRef.__PVT__id_ex_is_div)) 
                                         & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__busy)));
    vlSelfRef.ex_alu_c = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__c;
    vlSelfRef.flush_d = ((IData)(vlSelfRef.ex_br_taken) 
                         | ((1U == (IData)(vlSelfRef.__PVT__id_ex_npc_op)) 
                            | (IData)(vlSelfRef.__PVT__load_use_stall)));
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

void VminiRV_SoC_cpu_core___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__2(VminiRV_SoC_cpu_core* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__2\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ifetch_req = (1U & (~ (IData)(vlSymsp->TOP.fpga_rst)));
}

void VminiRV_SoC_cpu_core___ico_comb__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC_cpu_core* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___ico_comb__TOP__miniRV_SoC__U_cpu__U_core__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ifetch_valid = ((~ (IData)(vlSymsp->TOP.fpga_rst)) 
                              & (IData)(vlSelfRef.ifetch_req));
}

void VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC_cpu_core* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __Vdly__stall_synced;
    __Vdly__stall_synced = 0;
    IData/*31:0*/ __Vdly__pc;
    __Vdly__pc = 0;
    // Body
    __Vdly__stall_synced = vlSelfRef.__PVT__stall_synced;
    __Vdly__pc = vlSelfRef.pc;
    vlSelfRef.__PVT__mul_div_entering = ((~ (IData)(vlSymsp->TOP.fpga_rst)) 
                                         & (IData)(vlSelfRef.__PVT__id_mul_div));
    vlSelfRef.__PVT__mul_div_stall_d = ((~ (IData)(vlSymsp->TOP.fpga_rst)) 
                                        & (IData)(vlSelfRef.__PVT__mul_div_stall));
    vlSelfRef.__PVT__ex_mem_is_mul = ((1U & (~ (IData)(vlSymsp->TOP.fpga_rst))) 
                                      && ((1U & (~ (IData)(vlSelfRef.__PVT__mul_div_stall))) 
                                          && (IData)(vlSelfRef.__PVT__id_ex_is_mul)));
    vlSelfRef.__PVT__ex_mem_is_div = ((1U & (~ (IData)(vlSymsp->TOP.fpga_rst))) 
                                      && ((1U & (~ (IData)(vlSelfRef.__PVT__mul_div_stall))) 
                                          && (IData)(vlSelfRef.__PVT__id_ex_is_div)));
    if (vlSymsp->TOP.fpga_rst) {
        __Vdly__stall_synced = 0U;
        vlSelfRef.__PVT__id_ex_br_target = 0U;
        vlSelfRef.__PVT__ex_mem_br = 0U;
        vlSelfRef.__PVT__id_ex_npc_op = 0U;
        vlSelfRef.id_ex_alu_op = 0U;
        vlSelfRef.__PVT__ex_mem_ram_wop = 0U;
        vlSelfRef.id_ex_alub_sel = 0U;
        vlSelfRef.__PVT__mem_wb_ram_rop = 0U;
        vlSelfRef.__PVT__mem_wb_alu_c = 0U;
        vlSelfRef.__PVT__mem_wb_byte_offs = 0U;
        vlSelfRef.mem_wb_ext = 0U;
        vlSelfRef.__PVT__last_wb_pc = 0U;
        vlSelfRef.id_ex_rs1 = 0U;
        vlSelfRef.id_ex_rs2 = 0U;
        vlSelfRef.__PVT__id_ex_alua_sel = 0U;
        vlSelfRef.__PVT__id_ex_rd1 = 0U;
        vlSelfRef.__PVT__ex_mem_rd2 = 0U;
        vlSelfRef.__PVT__id_ex_is_mul = 0U;
        vlSelfRef.__PVT__id_ex_is_div = 0U;
        vlSelfRef.__PVT__ex_mem_ext = 0U;
        vlSelfRef.mem_wb_pc = 0U;
        vlSelfRef.id_ex_ext = 0U;
        vlSelfRef.__PVT__ex_mem_pc = 0U;
        vlSelfRef.id_ex_pc = 0U;
        vlSelfRef.if_id_pc = 0U;
        __Vdly__pc = 0U;
        vlSelfRef.fetch_pc = 0U;
        vlSelfRef.__PVT__mul_div_flush = 0U;
    } else {
        if (vlSelfRef.stall_f) {
            if (((IData)(vlSelfRef.stall_f) & (~ (IData)(vlSelfRef.__PVT__stall_synced)))) {
                __Vdly__stall_synced = 1U;
            }
        } else {
            __Vdly__stall_synced = 0U;
        }
        vlSelfRef.__PVT__ex_mem_ram_wop = ((IData)(vlSelfRef.__PVT__mul_div_stall)
                                            ? 0U : (IData)(vlSelfRef.__PVT__id_ex_ram_wop));
        vlSelfRef.__PVT__mem_wb_ram_rop = vlSelfRef.__PVT__ex_mem_ram_rop;
        vlSelfRef.__PVT__mem_wb_alu_c = vlSelfRef.__PVT__ex_mem_alu_c;
        vlSelfRef.__PVT__mem_wb_byte_offs = (3U & vlSelfRef.__PVT__ex_mem_alu_c);
        vlSelfRef.mem_wb_ext = vlSelfRef.__PVT__ex_mem_ext;
        if (vlSelfRef.flush_d) {
            vlSelfRef.__PVT__id_ex_npc_op = 0U;
            vlSelfRef.id_ex_alu_op = 0U;
            vlSelfRef.id_ex_alub_sel = 0U;
            vlSelfRef.__PVT__id_ex_alua_sel = 0U;
            vlSelfRef.__PVT__id_ex_is_mul = 0U;
            vlSelfRef.__PVT__id_ex_is_div = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.stall_d)))) {
            vlSelfRef.__PVT__id_ex_npc_op = vlSelfRef.__PVT__U_CU__DOT__npc_op;
            vlSelfRef.id_ex_alu_op = vlSelfRef.__PVT__U_CU__DOT__alu_op;
            vlSelfRef.id_ex_alub_sel = (((IData)(vlSelfRef.__PVT__U_CU__DOT__ADDI) 
                                         | ((IData)(vlSelfRef.__PVT__U_CU__DOT__ORI) 
                                            | ((IData)(vlSelfRef.__PVT__U_CU__DOT__XORI) 
                                               | ((IData)(vlSelfRef.__PVT__U_CU__DOT__ANDI) 
                                                  | ((IData)(vlSelfRef.__PVT__U_CU__DOT__SLTI) 
                                                     | ((IData)(vlSelfRef.__PVT__U_CU__DOT__SLTIU) 
                                                        | ((IData)(vlSelfRef.__PVT__U_CU__DOT__SLLI) 
                                                           | ((IData)(vlSelfRef.__PVT__U_CU__DOT__SRLI) 
                                                              | ((IData)(vlSelfRef.__PVT__U_CU__DOT__SRAI) 
                                                                 | (IData)(vlSelfRef.__PVT__U_CU__DOT__WB_OP_RAM)))))))))) 
                                        | ((IData)(vlSelfRef.__PVT__U_CU__DOT__EXT_OP_S) 
                                           | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_22)));
            vlSelfRef.__PVT__id_ex_alua_sel = (0x17U 
                                               == (0x0000007fU 
                                                   & vlSelfRef.if_id_inst));
            vlSelfRef.__PVT__id_ex_is_mul = vlSelfRef.__PVT__U_CU__DOT__is_mul;
            vlSelfRef.__PVT__id_ex_is_div = vlSelfRef.__PVT__U_CU__DOT__is_div;
        }
        if ((1U & (~ (IData)(vlSelfRef.__PVT__mul_div_stall)))) {
            vlSelfRef.__PVT__ex_mem_br = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__br;
            vlSelfRef.__PVT__ex_mem_rd2 = vlSelfRef.__PVT__id_ex_rd2;
            vlSelfRef.__PVT__ex_mem_ext = vlSelfRef.id_ex_ext;
        }
        if (vlSelfRef.flush_d) {
            vlSelfRef.id_ex_ext = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.stall_d)))) {
            vlSelfRef.id_ex_ext = vlSelfRef.__PVT__U_SEXT__DOT__ext;
        }
        vlSelfRef.__PVT__last_wb_pc = vlSelfRef.mem_wb_pc;
        vlSelfRef.mem_wb_pc = vlSelfRef.__PVT__ex_mem_pc;
        if ((1U & (~ (IData)(vlSelfRef.__PVT__mul_div_stall)))) {
            vlSelfRef.__PVT__ex_mem_pc = vlSelfRef.id_ex_pc;
        }
        if ((1U & (~ (IData)(vlSelfRef.flush_d)))) {
            if ((1U & (~ (IData)(vlSelfRef.stall_d)))) {
                vlSelfRef.__PVT__id_ex_br_target = vlSelfRef.__PVT__id_br_target;
                vlSelfRef.id_ex_rs1 = (0x0000001fU 
                                       & (vlSelfRef.if_id_inst 
                                          >> 0x0000000fU));
                vlSelfRef.id_ex_rs2 = (0x0000001fU 
                                       & (vlSelfRef.if_id_inst 
                                          >> 0x00000014U));
                vlSelfRef.__PVT__id_ex_rd1 = (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_7) 
                                               & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6))
                                               ? vlSelfRef.ex_alu_c
                                               : ((
                                                   ((IData)(vlSelfRef.__PVT__ex_mem_rd) 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSelfRef.if_id_inst 
                                                        >> 0x0000000fU))) 
                                                   & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0))
                                                   ? vlSelfRef.__PVT__ex_mem_alu_c
                                                   : 
                                                  ((((IData)(vlSelfRef.mem_wb_rd) 
                                                     == 
                                                     (0x0000001fU 
                                                      & (vlSelfRef.if_id_inst 
                                                         >> 0x0000000fU))) 
                                                    & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1))
                                                    ? vlSelfRef.__PVT__wb_forward_data
                                                    : 
                                                   (vlSelfRef.__PVT__U_RF__DOT__regs
                                                    [
                                                    (0x0000001fU 
                                                     & ((vlSelfRef.if_id_inst 
                                                         >> 0x0000000fU) 
                                                        - (IData)(1U)))] 
                                                    & (- (IData)(
                                                                 ((0x1eU 
                                                                   >= 
                                                                   (0x0000001fU 
                                                                    & ((vlSelfRef.if_id_inst 
                                                                        >> 0x0000000fU) 
                                                                       - (IData)(1U)))) 
                                                                  & (0U 
                                                                     != 
                                                                     (0x0000001fU 
                                                                      & (vlSelfRef.if_id_inst 
                                                                         >> 0x0000000fU))))))))));
                vlSelfRef.id_ex_pc = vlSelfRef.if_id_pc;
            }
        }
        if (vlSelfRef.__PVT__effective_flush) {
            vlSelfRef.if_id_pc = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.stall_f)))) {
            vlSelfRef.if_id_pc = vlSelfRef.fetch_pc;
        }
        if (vlSelfRef.flush_f) {
            __Vdly__pc = vlSelfRef.__PVT__pc_next;
            vlSelfRef.fetch_pc = vlSelfRef.__PVT__pc_next;
        } else if (((IData)(vlSelfRef.stall_f) & (~ (IData)(vlSelfRef.__PVT__stall_synced)))) {
            __Vdly__pc = vlSelfRef.pc;
            vlSelfRef.fetch_pc = vlSelfRef.pc;
        } else if ((1U & (((((~ (IData)(vlSelfRef.stall_f)) 
                             & (~ (IData)(vlSelfRef.__PVT__flush_next))) 
                            & (~ ((IData)(vlSelfRef.__PVT__mul_div_flush) 
                                  & (IData)(vlSelfRef.flush_next2)))) 
                           & (~ (IData)(vlSelfRef.load_resync))) 
                          & (~ (IData)(vlSelfRef.__PVT__load_resync2))))) {
            vlSelfRef.fetch_pc = vlSelfRef.pc;
            __Vdly__pc = vlSelfRef.__PVT__pc_next;
        }
        if (vlSelfRef.__PVT__mul_div_release) {
            vlSelfRef.__PVT__mul_div_flush = 1U;
        } else if ((1U & ((~ (IData)(vlSelfRef.__PVT__flush_next)) 
                          & (~ (IData)(vlSelfRef.flush_next2))))) {
            vlSelfRef.__PVT__mul_div_flush = 0U;
        }
    }
    vlSelfRef.debug_wb_pc = vlSelfRef.mem_wb_pc;
    vlSelfRef.debug_mem_pc = vlSelfRef.__PVT__ex_mem_pc;
    vlSelfRef.__PVT__stall_synced = __Vdly__stall_synced;
    vlSelfRef.pc = __Vdly__pc;
    vlSelfRef.__PVT__load_resync2 = ((1U & (~ (IData)(vlSymsp->TOP.fpga_rst))) 
                                     && (IData)(vlSelfRef.load_resync));
    vlSelfRef.load_resync = ((1U & (~ (IData)(vlSymsp->TOP.fpga_rst))) 
                             && (IData)(vlSelfRef.__PVT__load_stall_active));
    vlSelfRef.flush_next2 = ((1U & (~ (IData)(vlSymsp->TOP.fpga_rst))) 
                             && (IData)(vlSelfRef.__PVT__flush_next));
    vlSelfRef.__PVT__flush_next = ((1U & (~ (IData)(vlSymsp->TOP.fpga_rst))) 
                                   && (IData)(vlSelfRef.flush_f));
}

void VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__1(VminiRV_SoC_cpu_core* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__1\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__U_RF__DOT__regs__v0 = 0U;
    if ((((1U == (IData)(vlSelfRef.mem_wb_rf_wsel))
           ? ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_valid) 
              & (IData)(vlSelfRef.mem_wb_rf_we)) : (IData)(vlSelfRef.mem_wb_rf_we)) 
         & (0U != (IData)(vlSelfRef.mem_wb_rd)))) {
        if ((0x1eU >= (0x0000001fU & ((IData)(vlSelfRef.mem_wb_rd) 
                                      - (IData)(1U))))) {
            vlSelfRef.__VdlyVal__U_RF__DOT__regs__v0 
                = vlSelfRef.__PVT__U_RF__DOT__wD;
            vlSelfRef.__VdlyDim0__U_RF__DOT__regs__v0 
                = (0x0000001fU & ((IData)(vlSelfRef.mem_wb_rd) 
                                  - (IData)(1U)));
            vlSelfRef.__VdlySet__U_RF__DOT__regs__v0 = 1U;
        }
    }
    if ((0U != (IData)(vlSelfRef.__PVT__id_ex_ram_wop))) {
        vlSelfRef.__PVT__store_data_r = vlSelfRef.__PVT__id_ex_rd2;
    }
    vlSelfRef.debug_mem_wdata = vlSelfRef.__PVT__store_data_r;
}

void VminiRV_SoC_cpu_core___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC_cpu_core* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

void VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__2(VminiRV_SoC_cpu_core* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__2\n"); );
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
    vlSelfRef.mem_wb_rf_we = ((1U & (~ (IData)(vlSymsp->TOP.fpga_rst))) 
                              && (IData)(vlSelfRef.__PVT__ex_mem_rf_we));
    vlSelfRef.mem_wb_rf_wsel = ((IData)(vlSymsp->TOP.fpga_rst)
                                 ? 0U : (IData)(vlSelfRef.__PVT__ex_mem_rf_wsel));
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
    vlSelfRef.debug_wb_rf_we = ((IData)(vlSelfRef.mem_wb_rf_we) 
                                & (vlSelfRef.mem_wb_pc 
                                   != vlSelfRef.__PVT__last_wb_pc));
    vlSelfRef.__PVT__ex_mem_rf_we = ((1U & (~ (IData)(vlSymsp->TOP.fpga_rst))) 
                                     && ((1U & (~ (IData)(vlSelfRef.__PVT__mul_div_stall))) 
                                         && (IData)(vlSelfRef.__PVT__id_ex_rf_we)));
    if (vlSymsp->TOP.fpga_rst) {
        vlSelfRef.__PVT__id_ex_ram_wop = 0U;
        vlSelfRef.__PVT__id_ex_rd2 = 0U;
        vlSelfRef.__PVT__ex_mem_ram_rop = 0U;
        vlSelfRef.__PVT__ex_mem_rf_wsel = 0U;
        vlSelfRef.__PVT__ex_mem_alu_c = 0U;
        vlSelfRef.mem_wb_rd = 0U;
        vlSelfRef.__PVT__id_ex_ram_rop = 0U;
        vlSelfRef.__PVT__id_ex_rf_wsel = 0U;
        vlSelfRef.__PVT__id_ex_rf_we = 0U;
        vlSelfRef.__PVT__ex_mem_rd = 0U;
        vlSelfRef.__PVT__id_ex_rd = 0U;
        vlSelfRef.if_id_inst = 0U;
    } else {
        vlSelfRef.__PVT__ex_mem_ram_rop = ((IData)(vlSelfRef.__PVT__mul_div_stall)
                                            ? 0U : (IData)(vlSelfRef.__PVT__id_ex_ram_rop));
        if (vlSelfRef.flush_d) {
            vlSelfRef.__PVT__id_ex_ram_wop = 0U;
            vlSelfRef.__PVT__id_ex_ram_rop = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.stall_d)))) {
            vlSelfRef.__PVT__id_ex_ram_wop = (0x0000000fU 
                                              & ((1U 
                                                  & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__SB)))) 
                                                 | ((3U 
                                                     & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__SH)))) 
                                                    | (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__SW))))));
            vlSelfRef.__PVT__id_ex_ram_rop = ((2U & 
                                               (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__LB)))) 
                                              | ((3U 
                                                  & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__LBU)))) 
                                                 | ((4U 
                                                     & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__LH)))) 
                                                    | ((5U 
                                                        & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__LHU)))) 
                                                       | (1U 
                                                          & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__LW))))))));
        }
        if ((1U & (~ (IData)(vlSelfRef.__PVT__mul_div_stall)))) {
            vlSelfRef.__PVT__ex_mem_rf_wsel = vlSelfRef.__PVT__id_ex_rf_wsel;
        }
        if (vlSelfRef.flush_d) {
            vlSelfRef.__PVT__id_ex_rf_wsel = 0U;
            vlSelfRef.__PVT__id_ex_rf_we = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.stall_d)))) {
            vlSelfRef.__PVT__id_ex_rf_wsel = (3U & 
                                              ((1U 
                                                & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__WB_OP_RAM)))) 
                                               | ((2U 
                                                   & (- (IData)((IData)(vlSelfRef.__PVT__U_CU__DOT__WB_OP_PC4)))) 
                                                  | (- (IData)(
                                                               (0x37U 
                                                                == 
                                                                (0x0000007fU 
                                                                 & vlSelfRef.if_id_inst)))))));
            vlSelfRef.__PVT__id_ex_rf_we = ((((IData)(vlSelfRef.__PVT__U_CU__DOT__ADDI) 
                                              | ((0U 
                                                  == 
                                                  (vlSelfRef.if_id_inst 
                                                   >> 0x00000019U)) 
                                                 & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3))) 
                                             | ((IData)(vlSelfRef.__PVT__U_CU__DOT__SUB) 
                                                | ((IData)(vlSelfRef.__PVT__U_CU__DOT__ORI) 
                                                   | ((IData)(vlSelfRef.__PVT__U_CU__DOT__ALU_OP_XOR) 
                                                      | ((IData)(vlSelfRef.__PVT__U_CU__DOT__ALU_OP_AND) 
                                                         | ((IData)(vlSelfRef.__PVT__U_CU__DOT__OR) 
                                                            | ((IData)(vlSelfRef.__PVT__U_CU__DOT__SLTI) 
                                                               | ((IData)(vlSelfRef.__PVT__U_CU__DOT__SLTIU) 
                                                                  | ((IData)(vlSelfRef.__PVT__U_CU__DOT__SLT) 
                                                                     | ((IData)(vlSelfRef.__PVT__U_CU__DOT__SLTU) 
                                                                        | ((IData)(vlSelfRef.__PVT__U_CU__DOT__SLLI) 
                                                                           | ((IData)(vlSelfRef.__PVT__U_CU__DOT__SRLI) 
                                                                              | ((IData)(vlSelfRef.__PVT__U_CU__DOT__SRAI) 
                                                                                | ((IData)(vlSelfRef.__PVT__U_CU__DOT__SLL) 
                                                                                | ((IData)(vlSelfRef.__PVT__U_CU__DOT__SRA) 
                                                                                | (IData)(vlSelfRef.__PVT__U_CU__DOT__SRL)))))))))))))))) 
                                            | ((IData)(vlSelfRef.__PVT__U_CU__DOT__WB_OP_RAM) 
                                               | ((0x37U 
                                                   == 
                                                   (0x0000007fU 
                                                    & vlSelfRef.if_id_inst)) 
                                                  | ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_22) 
                                                     | (IData)(vlSelfRef.__PVT__id_mul_div)))));
        }
        if ((1U & (~ (IData)(vlSelfRef.flush_d)))) {
            if ((1U & (~ (IData)(vlSelfRef.stall_d)))) {
                vlSelfRef.__PVT__id_ex_rd2 = ((((IData)(vlSelfRef.__PVT__ex_mem_rd) 
                                                == 
                                                (0x0000001fU 
                                                 & (vlSelfRef.if_id_inst 
                                                    >> 0x00000014U))) 
                                               & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0))
                                               ? vlSelfRef.__PVT__ex_mem_alu_c
                                               : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_8) 
                                                   & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6))
                                                   ? vlSelfRef.ex_alu_c
                                                   : 
                                                  ((((IData)(vlSelfRef.mem_wb_rd) 
                                                     == 
                                                     (0x0000001fU 
                                                      & (vlSelfRef.if_id_inst 
                                                         >> 0x00000014U))) 
                                                    & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1))
                                                    ? vlSelfRef.__PVT__wb_forward_data
                                                    : 
                                                   (vlSelfRef.__PVT__U_RF__DOT__regs
                                                    [
                                                    (0x0000001fU 
                                                     & ((vlSelfRef.if_id_inst 
                                                         >> 0x00000014U) 
                                                        - (IData)(1U)))] 
                                                    & (- (IData)(
                                                                 ((0x1eU 
                                                                   >= 
                                                                   (0x0000001fU 
                                                                    & ((vlSelfRef.if_id_inst 
                                                                        >> 0x00000014U) 
                                                                       - (IData)(1U)))) 
                                                                  & (0U 
                                                                     != 
                                                                     (0x0000001fU 
                                                                      & (vlSelfRef.if_id_inst 
                                                                         >> 0x00000014U))))))))));
            }
        }
        vlSelfRef.mem_wb_rd = vlSelfRef.__PVT__ex_mem_rd;
        if ((1U & (~ (IData)(vlSelfRef.__PVT__mul_div_stall)))) {
            vlSelfRef.__PVT__ex_mem_alu_c = vlSelfRef.ex_alu_c;
            vlSelfRef.__PVT__ex_mem_rd = vlSelfRef.__PVT__id_ex_rd;
        }
        if ((1U & (~ (IData)(vlSelfRef.flush_d)))) {
            if ((1U & (~ (IData)(vlSelfRef.stall_d)))) {
                vlSelfRef.__PVT__id_ex_rd = (0x0000001fU 
                                             & (vlSelfRef.if_id_inst 
                                                >> 7U));
            }
        }
        if (vlSelfRef.__PVT__effective_flush) {
            vlSelfRef.if_id_inst = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.stall_f)))) {
            vlSelfRef.if_id_inst = ((IData)(vlSelfRef.ifetch_valid)
                                     ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__douta
                                     : 0U);
        }
    }
    vlSelfRef.debug_mem_waddr = vlSelfRef.__PVT__ex_mem_alu_c;
    vlSelfRef.__PVT__mem_da_wdata = vlSelfRef.__PVT__ex_mem_rd2;
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
    vlSelfRef.__PVT__ex_mem_fwd_data = ((0U == (IData)(vlSelfRef.__PVT__ex_mem_rf_wsel))
                                         ? vlSelfRef.__PVT__ex_mem_alu_c
                                         : ((3U == (IData)(vlSelfRef.__PVT__ex_mem_rf_wsel))
                                             ? vlSelfRef.__PVT__ex_mem_ext
                                             : vlSelfRef.__PVT__ex_mem_alu_c));
    vlSelfRef.debug_wb_rf_wR = vlSelfRef.mem_wb_rd;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1 = ((IData)(vlSelfRef.mem_wb_rf_we) 
                                                & (0U 
                                                   != (IData)(vlSelfRef.mem_wb_rd)));
    vlSelfRef.debug_mem_we = vlSelfRef.__PVT__mem_da_wen;
    vlSelfRef.__PVT__mul_div_stall = ((IData)(vlSelfRef.__PVT__mul_div_entering) 
                                      | (((IData)(vlSelfRef.__PVT__id_ex_is_mul) 
                                          | (IData)(vlSelfRef.__PVT__id_ex_is_div)) 
                                         & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__busy)));
    vlSelfRef.__PVT__mul_div_release = ((~ (IData)(vlSelfRef.__PVT__mul_div_stall)) 
                                        & (IData)(vlSelfRef.__PVT__mul_div_stall_d));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0 = ((IData)(vlSelfRef.__PVT__ex_mem_rf_we) 
                                                & (0U 
                                                   != (IData)(vlSelfRef.__PVT__ex_mem_rd)));
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
    vlSelfRef.stall_d = vlSelfRef.__PVT__mul_div_stall;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6 = ((IData)(vlSelfRef.__PVT__id_ex_rf_we) 
                                                & (0U 
                                                   != (IData)(vlSelfRef.__PVT__id_ex_rd)));
    vlSelfRef.__PVT__U_CU__DOT__ADDI = (IData)((0x00000013U 
                                                == 
                                                (0x0000707fU 
                                                 & vlSelfRef.if_id_inst)));
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
    vlSelfRef.__PVT__id_br_target = (vlSelfRef.if_id_pc 
                                     + vlSelfRef.__PVT__U_SEXT__DOT__ext);
}

void VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__3(VminiRV_SoC_cpu_core* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__3\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__U_RF__DOT__regs__v0) {
        vlSelfRef.__PVT__U_RF__DOT__regs[vlSelfRef.__VdlyDim0__U_RF__DOT__regs__v0] 
            = vlSelfRef.__VdlyVal__U_RF__DOT__regs__v0;
    }
}

void VminiRV_SoC_cpu_core___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__1(VminiRV_SoC_cpu_core* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__1\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.debug_wb_rf_wD = vlSelfRef.__PVT__U_RF__DOT__wD;
    vlSelfRef.ex_alu_b = ((1U == (IData)(vlSelfRef.forward_b))
                           ? vlSelfRef.__PVT__ex_mem_fwd_data
                           : ((2U == (IData)(vlSelfRef.forward_b))
                               ? vlSelfRef.__PVT__wb_forward_data
                               : ((IData)(vlSelfRef.id_ex_alub_sel)
                                   ? vlSelfRef.id_ex_ext
                                   : vlSelfRef.__PVT__id_ex_rd2)));
}

void VminiRV_SoC_cpu_core___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__2(VminiRV_SoC_cpu_core* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__2\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ex_alu_c = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__c;
    vlSelfRef.ex_br_taken = ((2U == (IData)(vlSelfRef.__PVT__id_ex_npc_op)) 
                             & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__br));
    vlSelfRef.flush_d = ((IData)(vlSelfRef.ex_br_taken) 
                         | ((1U == (IData)(vlSelfRef.__PVT__id_ex_npc_op)) 
                            | (IData)(vlSelfRef.__PVT__load_use_stall)));
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

void VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__4(VminiRV_SoC_cpu_core* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__4\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ifetch_addr = vlSelfRef.pc;
}
