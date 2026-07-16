// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"

void VminiRV_SoC_ALU___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0(VminiRV_SoC_ALU* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VminiRV_SoC_ALU___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__mul_res = (((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.product_hi)) 
                                 << 0x00000020U) | (QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.product_lo)));
    vlSelfRef.op = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_alu_op;
    vlSelfRef.__PVT__a = ((1U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_FWD__DOT__forward_a))
                           ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_fwd_data
                           : ((2U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_FWD__DOT__forward_a))
                               ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__wb_forward_data
                               : ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_alua_sel)
                                   ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_pc
                                   : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rd1)));
    vlSelfRef.mul_busy = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.busy;
    vlSelfRef.__PVT__div_flag = ((0x13U == (IData)(vlSelfRef.op)) 
                                 | (0x15U == (IData)(vlSelfRef.op)));
    vlSelfRef.__PVT__divu_flag = ((0x14U == (IData)(vlSelfRef.op)) 
                                  | (0x16U == (IData)(vlSelfRef.op)));
    vlSelfRef.__PVT__mul_flag = ((0x10U == (IData)(vlSelfRef.op)) 
                                 | (0x11U == (IData)(vlSelfRef.op)));
    vlSelfRef.__PVT__effective_op = ((0U == (IData)(vlSelfRef.op_r))
                                      ? (IData)(vlSelfRef.op)
                                      : (IData)(vlSelfRef.op_r));
    vlSelfRef.__PVT__br = ((0x00000010U & (IData)(vlSelfRef.op))
                            ? ((8U & (IData)(vlSelfRef.op))
                                ? (IData)(((0U == (7U 
                                                   & (IData)(vlSelfRef.op))) 
                                           & (vlSelfRef.__PVT__a 
                                              >= vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)))
                                : (IData)(((7U == (7U 
                                                   & (IData)(vlSelfRef.op))) 
                                           & VL_GTES_III(32, vlSelfRef.__PVT__a, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b))))
                            : (IData)(((8U == (0x0cU 
                                               & (IData)(vlSelfRef.op))) 
                                       & ((2U & (IData)(vlSelfRef.op))
                                           ? ((1U & (IData)(vlSelfRef.op))
                                               ? (vlSelfRef.__PVT__a 
                                                  < vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)
                                               : VL_LTS_III(32, vlSelfRef.__PVT__a, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b))
                                           : ((1U & (IData)(vlSelfRef.op))
                                               ? (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b 
                                                  != vlSelfRef.__PVT__a)
                                               : (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b 
                                                  == vlSelfRef.__PVT__a))))));
    vlSelfRef.__PVT__busy = ((IData)(vlSelfRef.mul_busy) 
                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.busy) 
                                | ((0U != (IData)(vlSelfRef.__PVT__U_divu__DOT__count)) 
                                   | (0U != (IData)(vlSelfRef.__PVT__U_div__DOT__count)))));
    vlSelfRef.__PVT__U_div__DOT__start_rise = ((~ (IData)(vlSelfRef.__PVT__U_div__DOT__start_d)) 
                                               & (IData)(vlSelfRef.__PVT__div_flag));
    vlSelfRef.__PVT__U_divu__DOT__start_rise = ((~ (IData)(vlSelfRef.__PVT__U_divu__DOT__start_d)) 
                                                & (IData)(vlSelfRef.__PVT__divu_flag));
    vlSelfRef.__PVT__multi_start = ((~ (IData)(vlSelfRef.multi_active)) 
                                    & ((IData)(vlSelfRef.__PVT__mul_flag) 
                                       | ((0x12U == (IData)(vlSelfRef.op)) 
                                          | ((IData)(vlSelfRef.__PVT__div_flag) 
                                             | (IData)(vlSelfRef.__PVT__divu_flag)))));
    if ((0x00000010U & (IData)(vlSelfRef.__PVT__effective_op))) {
        if ((8U & (IData)(vlSelfRef.__PVT__effective_op))) {
            vlSelfRef.__PVT__c = 0U;
        } else if ((4U & (IData)(vlSelfRef.__PVT__effective_op))) {
            vlSelfRef.__PVT__c = ((2U & (IData)(vlSelfRef.__PVT__effective_op))
                                   ? ((1U & (IData)(vlSelfRef.__PVT__effective_op))
                                       ? 0U : (IData)(vlSelfRef.__PVT__U_divu__DOT__remainder))
                                   : ((1U & (IData)(vlSelfRef.__PVT__effective_op))
                                       ? ((vlSelfRef.__PVT__a 
                                           >> 0x1fU)
                                           ? (- vlSelfRef.__PVT__U_div__DOT__remainder)
                                           : vlSelfRef.__PVT__U_div__DOT__remainder)
                                       : (IData)(vlSelfRef.__PVT__U_divu__DOT__quotient)));
        } else if ((2U & (IData)(vlSelfRef.__PVT__effective_op))) {
            vlSelfRef.__PVT__c = ((1U & (IData)(vlSelfRef.__PVT__effective_op))
                                   ? (((vlSelfRef.__PVT__a 
                                        ^ vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b) 
                                       >> 0x1fU) ? 
                                      (- vlSelfRef.__PVT__U_div__DOT__quotient)
                                       : vlSelfRef.__PVT__U_div__DOT__quotient)
                                   : (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_hi) 
                                       << 1U) | (1U 
                                                 & (IData)(
                                                           (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_lo 
                                                            >> 0x00000020U)))));
        } else if ((1U & (IData)(vlSelfRef.__PVT__effective_op))) {
            vlSelfRef.__PVT__c = (IData)((vlSelfRef.__PVT__mul_res 
                                          >> 0x20U));
            if ((vlSelfRef.a_latched >> 0x1fU)) {
                vlSelfRef.__PVT__c = (vlSelfRef.__PVT__c 
                                      - vlSelfRef.b_latched);
            }
            if ((vlSelfRef.b_latched >> 0x1fU)) {
                vlSelfRef.__PVT__c = (vlSelfRef.__PVT__c 
                                      - vlSelfRef.a_latched);
            }
        } else {
            vlSelfRef.__PVT__c = (IData)(vlSelfRef.__PVT__mul_res);
        }
    } else {
        vlSelfRef.__PVT__c = ((8U & (IData)(vlSelfRef.__PVT__effective_op))
                               ? ((4U & (IData)(vlSelfRef.__PVT__effective_op))
                                   ? 0U : ((2U & (IData)(vlSelfRef.__PVT__effective_op))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.__PVT__effective_op))
                                                ? (
                                                   (vlSelfRef.__PVT__a 
                                                    < vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)
                                                    ? 1U
                                                    : 0U)
                                                : (
                                                   VL_LTS_III(32, vlSelfRef.__PVT__a, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)
                                                    ? 1U
                                                    : 0U))
                                            : 0U)) : 
                              ((4U & (IData)(vlSelfRef.__PVT__effective_op))
                                ? ((2U & (IData)(vlSelfRef.__PVT__effective_op))
                                    ? ((1U & (IData)(vlSelfRef.__PVT__effective_op))
                                        ? VL_SHIFTRS_III(32,32,5, vlSelfRef.__PVT__a, 
                                                         (0x0000001fU 
                                                          & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b))
                                        : (vlSelfRef.__PVT__a 
                                           >> (0x0000001fU 
                                               & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)))
                                    : ((1U & (IData)(vlSelfRef.__PVT__effective_op))
                                        ? (vlSelfRef.__PVT__a 
                                           << (0x0000001fU 
                                               & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b))
                                        : (vlSelfRef.__PVT__a 
                                           & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)))
                                : ((2U & (IData)(vlSelfRef.__PVT__effective_op))
                                    ? ((1U & (IData)(vlSelfRef.__PVT__effective_op))
                                        ? (vlSelfRef.__PVT__a 
                                           | vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)
                                        : (vlSelfRef.__PVT__a 
                                           ^ vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b))
                                    : ((1U & (IData)(vlSelfRef.__PVT__effective_op))
                                        ? (vlSelfRef.__PVT__a 
                                           - vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)
                                        : (vlSelfRef.__PVT__a 
                                           + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)))));
    }
}

void VminiRV_SoC_ALU___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0(VminiRV_SoC_ALU* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VminiRV_SoC_ALU___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __Vdly__multi_active;
    __Vdly__multi_active = 0;
    CData/*5:0*/ __Vdly__U_divu__DOT__count;
    __Vdly__U_divu__DOT__count = 0;
    CData/*5:0*/ __Vdly__U_div__DOT__count;
    __Vdly__U_div__DOT__count = 0;
    // Body
    __Vdly__multi_active = vlSelfRef.multi_active;
    __Vdly__U_divu__DOT__count = vlSelfRef.__PVT__U_divu__DOT__count;
    __Vdly__U_div__DOT__count = vlSelfRef.__PVT__U_div__DOT__count;
    vlSelfRef.__PVT__U_divu__DOT__start_d = ((1U & 
                                              (~ (IData)(vlSymsp->TOP.fpga_rst))) 
                                             && (IData)(vlSelfRef.__PVT__divu_flag));
    vlSelfRef.__PVT__U_div__DOT__start_d = ((1U & (~ (IData)(vlSymsp->TOP.fpga_rst))) 
                                            && (IData)(vlSelfRef.__PVT__div_flag));
    if (vlSymsp->TOP.fpga_rst) {
        vlSelfRef.__PVT__U_divu__DOT__divisor = 0ULL;
        vlSelfRef.__PVT__U_div__DOT__divisor = 0U;
        vlSelfRef.a_latched = 0U;
        vlSelfRef.b_latched = 0U;
        __Vdly__multi_active = 0U;
        vlSelfRef.op_r = 0U;
        __Vdly__U_divu__DOT__count = 0U;
        vlSelfRef.__PVT__U_divu__DOT__remainder = 0ULL;
        vlSelfRef.__PVT__U_divu__DOT__quotient = 0ULL;
        __Vdly__U_div__DOT__count = 0U;
        vlSelfRef.__PVT__U_div__DOT__remainder = 0U;
        vlSelfRef.__PVT__U_div__DOT__quotient = 0U;
    } else {
        if (vlSelfRef.__PVT__U_divu__DOT__start_rise) {
            vlSelfRef.__PVT__U_divu__DOT__divisor = (QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b));
            __Vdly__U_divu__DOT__count = 0x21U;
            vlSelfRef.__PVT__U_divu__DOT__remainder = 0ULL;
            vlSelfRef.__PVT__U_divu__DOT__quotient 
                = (QData)((IData)(vlSelfRef.__PVT__a));
        } else if ((0U < (IData)(vlSelfRef.__PVT__U_divu__DOT__count))) {
            __Vdly__U_divu__DOT__count = (0x0000003fU 
                                          & ((IData)(vlSelfRef.__PVT__U_divu__DOT__count) 
                                             - (IData)(1U)));
            vlSelfRef.__PVT__U_divu__DOT__remainder 
                = (0x00000001ffffffffULL & ((1U & (IData)(
                                                          (vlSelfRef.__PVT__U_divu__DOT__diff 
                                                           >> 0x00000021U)))
                                             ? vlSelfRef.__PVT__U_divu__DOT__shifted_rem
                                             : vlSelfRef.__PVT__U_divu__DOT__diff));
            vlSelfRef.__PVT__U_divu__DOT__quotient 
                = vlSelfRef.__PVT__U_divu__DOT__next_quo;
        }
        if (vlSelfRef.__PVT__U_div__DOT__start_rise) {
            vlSelfRef.__PVT__U_div__DOT__divisor = 
                ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b 
                  >> 0x0000001fU) ? ((IData)(1U) + 
                                     (~ vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b))
                  : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b);
            __Vdly__U_div__DOT__count = 0x20U;
            vlSelfRef.__PVT__U_div__DOT__remainder = 0U;
            vlSelfRef.__PVT__U_div__DOT__quotient = 
                ((vlSelfRef.__PVT__a >> 0x0000001fU)
                  ? ((IData)(1U) + (~ vlSelfRef.__PVT__a))
                  : vlSelfRef.__PVT__a);
        } else if ((0U < (IData)(vlSelfRef.__PVT__U_div__DOT__count))) {
            __Vdly__U_div__DOT__count = (0x0000003fU 
                                         & ((IData)(vlSelfRef.__PVT__U_div__DOT__count) 
                                            - (IData)(1U)));
            vlSelfRef.__PVT__U_div__DOT__remainder 
                = ((1U & (IData)((vlSelfRef.__PVT__U_div__DOT__diff 
                                  >> 0x00000020U)))
                    ? vlSelfRef.__PVT__U_div__DOT__shifted_rem
                    : (IData)(vlSelfRef.__PVT__U_div__DOT__diff));
            vlSelfRef.__PVT__U_div__DOT__quotient = vlSelfRef.__PVT__U_div__DOT__next_quo;
        }
        if (vlSelfRef.__PVT__multi_start) {
            vlSelfRef.a_latched = vlSelfRef.__PVT__a;
            vlSelfRef.b_latched = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b;
            vlSelfRef.op_r = vlSelfRef.op;
            __Vdly__multi_active = 1U;
        } else if (((IData)(vlSelfRef.multi_active) 
                    & (~ (IData)(vlSelfRef.__PVT__busy)))) {
            vlSelfRef.op_r = 0U;
            __Vdly__multi_active = 0U;
        }
    }
    vlSelfRef.multi_active = __Vdly__multi_active;
    vlSelfRef.op = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_alu_op;
    vlSelfRef.__PVT__U_divu__DOT__count = __Vdly__U_divu__DOT__count;
    vlSelfRef.__PVT__U_div__DOT__count = __Vdly__U_div__DOT__count;
    vlSelfRef.__PVT__div_flag = ((0x13U == (IData)(vlSelfRef.op)) 
                                 | (0x15U == (IData)(vlSelfRef.op)));
    vlSelfRef.__PVT__divu_flag = ((0x14U == (IData)(vlSelfRef.op)) 
                                  | (0x16U == (IData)(vlSelfRef.op)));
    vlSelfRef.__PVT__mul_flag = ((0x10U == (IData)(vlSelfRef.op)) 
                                 | (0x11U == (IData)(vlSelfRef.op)));
    vlSelfRef.__PVT__effective_op = ((0U == (IData)(vlSelfRef.op_r))
                                      ? (IData)(vlSelfRef.op)
                                      : (IData)(vlSelfRef.op_r));
    vlSelfRef.__PVT__U_divu__DOT__shifted_rem = (((QData)((IData)(vlSelfRef.__PVT__U_divu__DOT__remainder)) 
                                                  << 1U) 
                                                 | (QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlSelfRef.__PVT__U_divu__DOT__quotient 
                                                                               >> 0x00000020U))))));
    vlSelfRef.__PVT__U_div__DOT__shifted_rem = ((vlSelfRef.__PVT__U_div__DOT__remainder 
                                                 << 1U) 
                                                | (vlSelfRef.__PVT__U_div__DOT__quotient 
                                                   >> 0x0000001fU));
    vlSelfRef.__PVT__U_div__DOT__start_rise = ((~ (IData)(vlSelfRef.__PVT__U_div__DOT__start_d)) 
                                               & (IData)(vlSelfRef.__PVT__div_flag));
    vlSelfRef.__PVT__U_divu__DOT__start_rise = ((~ (IData)(vlSelfRef.__PVT__U_divu__DOT__start_d)) 
                                                & (IData)(vlSelfRef.__PVT__divu_flag));
    vlSelfRef.__PVT__multi_start = ((~ (IData)(vlSelfRef.multi_active)) 
                                    & ((IData)(vlSelfRef.__PVT__mul_flag) 
                                       | ((0x12U == (IData)(vlSelfRef.op)) 
                                          | ((IData)(vlSelfRef.__PVT__div_flag) 
                                             | (IData)(vlSelfRef.__PVT__divu_flag)))));
    vlSelfRef.__PVT__U_divu__DOT__diff = (0x00000003ffffffffULL 
                                          & (vlSelfRef.__PVT__U_divu__DOT__shifted_rem 
                                             - vlSelfRef.__PVT__U_divu__DOT__divisor));
    vlSelfRef.__PVT__U_div__DOT__diff = (0x00000001ffffffffULL 
                                         & ((QData)((IData)(vlSelfRef.__PVT__U_div__DOT__shifted_rem)) 
                                            - (QData)((IData)(vlSelfRef.__PVT__U_div__DOT__divisor))));
    vlSelfRef.__PVT__U_divu__DOT__next_quo = (((QData)((IData)(vlSelfRef.__PVT__U_divu__DOT__quotient)) 
                                               << 1U) 
                                              | (QData)((IData)(
                                                                (1U 
                                                                 & (~ (IData)(
                                                                              (vlSelfRef.__PVT__U_divu__DOT__diff 
                                                                               >> 0x00000021U)))))));
    vlSelfRef.__PVT__U_div__DOT__next_quo = ((vlSelfRef.__PVT__U_div__DOT__quotient 
                                              << 1U) 
                                             | (1U 
                                                & (~ (IData)(
                                                             (vlSelfRef.__PVT__U_div__DOT__diff 
                                                              >> 0x00000020U)))));
}

void VminiRV_SoC_ALU___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__1(VminiRV_SoC_ALU* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VminiRV_SoC_ALU___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__1\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__mul_res = (((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.product_hi)) 
                                 << 0x00000020U) | (QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.product_lo)));
    vlSelfRef.mul_busy = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.busy;
    vlSelfRef.__PVT__busy = ((IData)(vlSelfRef.mul_busy) 
                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.busy) 
                                | ((0U != (IData)(vlSelfRef.__PVT__U_divu__DOT__count)) 
                                   | (0U != (IData)(vlSelfRef.__PVT__U_div__DOT__count)))));
}

void VminiRV_SoC_ALU___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0(VminiRV_SoC_ALU* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VminiRV_SoC_ALU___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__a = ((1U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_FWD__DOT__forward_a))
                           ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_fwd_data
                           : ((2U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_FWD__DOT__forward_a))
                               ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__wb_forward_data
                               : ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_alua_sel)
                                   ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_pc
                                   : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rd1)));
    if ((0x00000010U & (IData)(vlSelfRef.__PVT__effective_op))) {
        if ((8U & (IData)(vlSelfRef.__PVT__effective_op))) {
            vlSelfRef.__PVT__c = 0U;
        } else if ((4U & (IData)(vlSelfRef.__PVT__effective_op))) {
            vlSelfRef.__PVT__c = ((2U & (IData)(vlSelfRef.__PVT__effective_op))
                                   ? ((1U & (IData)(vlSelfRef.__PVT__effective_op))
                                       ? 0U : (IData)(vlSelfRef.__PVT__U_divu__DOT__remainder))
                                   : ((1U & (IData)(vlSelfRef.__PVT__effective_op))
                                       ? ((vlSelfRef.__PVT__a 
                                           >> 0x1fU)
                                           ? (- vlSelfRef.__PVT__U_div__DOT__remainder)
                                           : vlSelfRef.__PVT__U_div__DOT__remainder)
                                       : (IData)(vlSelfRef.__PVT__U_divu__DOT__quotient)));
        } else if ((2U & (IData)(vlSelfRef.__PVT__effective_op))) {
            vlSelfRef.__PVT__c = ((1U & (IData)(vlSelfRef.__PVT__effective_op))
                                   ? (((vlSelfRef.__PVT__a 
                                        ^ vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b) 
                                       >> 0x1fU) ? 
                                      (- vlSelfRef.__PVT__U_div__DOT__quotient)
                                       : vlSelfRef.__PVT__U_div__DOT__quotient)
                                   : (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_hi) 
                                       << 1U) | (1U 
                                                 & (IData)(
                                                           (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_lo 
                                                            >> 0x00000020U)))));
        } else if ((1U & (IData)(vlSelfRef.__PVT__effective_op))) {
            vlSelfRef.__PVT__c = (IData)((vlSelfRef.__PVT__mul_res 
                                          >> 0x20U));
            if ((vlSelfRef.a_latched >> 0x1fU)) {
                vlSelfRef.__PVT__c = (vlSelfRef.__PVT__c 
                                      - vlSelfRef.b_latched);
            }
            if ((vlSelfRef.b_latched >> 0x1fU)) {
                vlSelfRef.__PVT__c = (vlSelfRef.__PVT__c 
                                      - vlSelfRef.a_latched);
            }
        } else {
            vlSelfRef.__PVT__c = (IData)(vlSelfRef.__PVT__mul_res);
        }
    } else {
        vlSelfRef.__PVT__c = ((8U & (IData)(vlSelfRef.__PVT__effective_op))
                               ? ((4U & (IData)(vlSelfRef.__PVT__effective_op))
                                   ? 0U : ((2U & (IData)(vlSelfRef.__PVT__effective_op))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.__PVT__effective_op))
                                                ? (
                                                   (vlSelfRef.__PVT__a 
                                                    < vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)
                                                    ? 1U
                                                    : 0U)
                                                : (
                                                   VL_LTS_III(32, vlSelfRef.__PVT__a, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)
                                                    ? 1U
                                                    : 0U))
                                            : 0U)) : 
                              ((4U & (IData)(vlSelfRef.__PVT__effective_op))
                                ? ((2U & (IData)(vlSelfRef.__PVT__effective_op))
                                    ? ((1U & (IData)(vlSelfRef.__PVT__effective_op))
                                        ? VL_SHIFTRS_III(32,32,5, vlSelfRef.__PVT__a, 
                                                         (0x0000001fU 
                                                          & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b))
                                        : (vlSelfRef.__PVT__a 
                                           >> (0x0000001fU 
                                               & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)))
                                    : ((1U & (IData)(vlSelfRef.__PVT__effective_op))
                                        ? (vlSelfRef.__PVT__a 
                                           << (0x0000001fU 
                                               & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b))
                                        : (vlSelfRef.__PVT__a 
                                           & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)))
                                : ((2U & (IData)(vlSelfRef.__PVT__effective_op))
                                    ? ((1U & (IData)(vlSelfRef.__PVT__effective_op))
                                        ? (vlSelfRef.__PVT__a 
                                           | vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)
                                        : (vlSelfRef.__PVT__a 
                                           ^ vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b))
                                    : ((1U & (IData)(vlSelfRef.__PVT__effective_op))
                                        ? (vlSelfRef.__PVT__a 
                                           - vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)
                                        : (vlSelfRef.__PVT__a 
                                           + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)))));
    }
    vlSelfRef.__PVT__br = ((0x00000010U & (IData)(vlSelfRef.op))
                            ? ((8U & (IData)(vlSelfRef.op))
                                ? (IData)(((0U == (7U 
                                                   & (IData)(vlSelfRef.op))) 
                                           & (vlSelfRef.__PVT__a 
                                              >= vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)))
                                : (IData)(((7U == (7U 
                                                   & (IData)(vlSelfRef.op))) 
                                           & VL_GTES_III(32, vlSelfRef.__PVT__a, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b))))
                            : (IData)(((8U == (0x0cU 
                                               & (IData)(vlSelfRef.op))) 
                                       & ((2U & (IData)(vlSelfRef.op))
                                           ? ((1U & (IData)(vlSelfRef.op))
                                               ? (vlSelfRef.__PVT__a 
                                                  < vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)
                                               : VL_LTS_III(32, vlSelfRef.__PVT__a, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b))
                                           : ((1U & (IData)(vlSelfRef.op))
                                               ? (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b 
                                                  != vlSelfRef.__PVT__a)
                                               : (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b 
                                                  == vlSelfRef.__PVT__a))))));
}
