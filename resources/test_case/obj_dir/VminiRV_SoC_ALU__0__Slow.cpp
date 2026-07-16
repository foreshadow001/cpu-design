// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"

VL_ATTR_COLD void VminiRV_SoC_ALU___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0(VminiRV_SoC_ALU* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VminiRV_SoC_ALU___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__U_div__DOT__shifted_rem = ((vlSelfRef.__PVT__U_div__DOT__remainder 
                                                 << 1U) 
                                                | (vlSelfRef.__PVT__U_div__DOT__quotient 
                                                   >> 0x0000001fU));
    vlSelfRef.__PVT__U_divu__DOT__shifted_rem = (((QData)((IData)(vlSelfRef.__PVT__U_divu__DOT__remainder)) 
                                                  << 1U) 
                                                 | (QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlSelfRef.__PVT__U_divu__DOT__quotient 
                                                                               >> 0x00000020U))))));
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
    vlSelfRef.__PVT__U_div__DOT__diff = (0x00000001ffffffffULL 
                                         & ((QData)((IData)(vlSelfRef.__PVT__U_div__DOT__shifted_rem)) 
                                            - (QData)((IData)(vlSelfRef.__PVT__U_div__DOT__divisor))));
    vlSelfRef.__PVT__U_divu__DOT__diff = (0x00000003ffffffffULL 
                                          & (vlSelfRef.__PVT__U_divu__DOT__shifted_rem 
                                             - vlSelfRef.__PVT__U_divu__DOT__divisor));
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
    vlSelfRef.__PVT__U_div__DOT__next_quo = ((vlSelfRef.__PVT__U_div__DOT__quotient 
                                              << 1U) 
                                             | (1U 
                                                & (~ (IData)(
                                                             (vlSelfRef.__PVT__U_div__DOT__diff 
                                                              >> 0x00000020U)))));
    vlSelfRef.__PVT__U_divu__DOT__next_quo = (((QData)((IData)(vlSelfRef.__PVT__U_divu__DOT__quotient)) 
                                               << 1U) 
                                              | (QData)((IData)(
                                                                (1U 
                                                                 & (~ (IData)(
                                                                              (vlSelfRef.__PVT__U_divu__DOT__diff 
                                                                               >> 0x00000021U)))))));
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

VL_ATTR_COLD void VminiRV_SoC_ALU___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__1(VminiRV_SoC_ALU* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VminiRV_SoC_ALU___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__1\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mul_busy = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.busy;
    vlSelfRef.__PVT__busy = ((IData)(vlSelfRef.mul_busy) 
                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.busy) 
                                | ((0U != (IData)(vlSelfRef.__PVT__U_divu__DOT__count)) 
                                   | (0U != (IData)(vlSelfRef.__PVT__U_div__DOT__count)))));
}

VL_ATTR_COLD void VminiRV_SoC_ALU___ctor_var_reset(VminiRV_SoC_ALU* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VminiRV_SoC_ALU___ctor_var_reset\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->__PVT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->__PVT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->op = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3630531923276091163ull);
    vlSelf->__PVT__a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 510903276987443985ull);
    vlSelf->__PVT__b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16900879642891266615ull);
    vlSelf->__PVT__c = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15598372446745583797ull);
    vlSelf->__PVT__br = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11408036722012964857ull);
    vlSelf->__PVT__busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6386567572483775230ull);
    vlSelf->__PVT__mul_flag = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15627662567909443225ull);
    vlSelf->__PVT__mul_res = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6869574032066498394ull);
    vlSelf->mul_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8102764323911122084ull);
    vlSelf->__PVT__div_flag = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11758797804081996342ull);
    vlSelf->__PVT__divu_flag = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9772159577025595468ull);
    vlSelf->op_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 633771380163301472ull);
    vlSelf->__PVT__effective_op = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4821799470362748746ull);
    vlSelf->a_latched = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6301976335140055269ull);
    vlSelf->b_latched = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3946299015998978694ull);
    vlSelf->multi_active = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1659937605690596626ull);
    vlSelf->__PVT__multi_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7597201289947551380ull);
    vlSelf->__PVT__U_divu__DOT__remainder = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 15687870126052982968ull);
    vlSelf->__PVT__U_divu__DOT__quotient = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 10314082525217887872ull);
    vlSelf->__PVT__U_divu__DOT__divisor = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 11757406943278986952ull);
    vlSelf->__PVT__U_divu__DOT__count = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 8950185320488696729ull);
    vlSelf->__PVT__U_divu__DOT__start_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12789718735257710165ull);
    vlSelf->__PVT__U_divu__DOT__shifted_rem = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 15754078018658619924ull);
    vlSelf->__PVT__U_divu__DOT__diff = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 40963032347654823ull);
    vlSelf->__PVT__U_divu__DOT__next_quo = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 11895621847023105833ull);
    vlSelf->__PVT__U_divu__DOT__start_rise = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9807033142618830266ull);
    vlSelf->__PVT__U_div__DOT__remainder = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7613722743951439366ull);
    vlSelf->__PVT__U_div__DOT__quotient = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1281125019085125256ull);
    vlSelf->__PVT__U_div__DOT__divisor = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11886086847799525190ull);
    vlSelf->__PVT__U_div__DOT__count = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 4311462597379026967ull);
    vlSelf->__PVT__U_div__DOT__start_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14975077576032649143ull);
    vlSelf->__PVT__U_div__DOT__shifted_rem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4840733035880692691ull);
    vlSelf->__PVT__U_div__DOT__diff = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 3156765289429734892ull);
    vlSelf->__PVT__U_div__DOT__next_quo = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17298603427080974474ull);
    vlSelf->__PVT__U_div__DOT__start_rise = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11797646753803549374ull);
}
