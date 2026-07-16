// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"

void VminiRV_SoC_multiplier___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul__0(VminiRV_SoC_multiplier* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VminiRV_SoC_multiplier___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__hi_sum = (0x00000003ffffffffULL 
                               & ((QData)((IData)(vlSelfRef.multiplicand)) 
                                  + vlSelfRef.product_hi));
    vlSelfRef.busy = (0U != (IData)(vlSelfRef.count));
    vlSelfRef.__PVT__next_hi = (0x00000001ffffffffULL 
                                & ((1U & vlSelfRef.product_lo)
                                    ? (vlSelfRef.__PVT__hi_sum 
                                       >> 1U) : (vlSelfRef.product_hi 
                                                 >> 1U)));
    vlSelfRef.__PVT__next_lo = ((((1U & vlSelfRef.product_lo)
                                   ? (IData)(vlSelfRef.__PVT__hi_sum)
                                   : (IData)(vlSelfRef.product_hi)) 
                                 << 0x0000001fU) | 
                                (vlSelfRef.product_lo 
                                 >> 1U));
}

void VminiRV_SoC_multiplier___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul__1(VminiRV_SoC_multiplier* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VminiRV_SoC_multiplier___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul__1\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.start = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__mul_flag;
    vlSelfRef.__PVT__start_rise = ((~ (IData)(vlSelfRef.__PVT__start_d)) 
                                   & (IData)(vlSelfRef.start));
}

void VminiRV_SoC_multiplier___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul__0(VminiRV_SoC_multiplier* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VminiRV_SoC_multiplier___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vdly__count;
    __Vdly__count = 0;
    // Body
    __Vdly__count = vlSelfRef.count;
    vlSelfRef.__PVT__start_d = ((1U & (~ (IData)(vlSymsp->TOP.fpga_rst))) 
                                && (IData)(vlSelfRef.start));
    if (vlSymsp->TOP.fpga_rst) {
        vlSelfRef.multiplicand = 0U;
        __Vdly__count = 0U;
        vlSelfRef.product_hi = 0ULL;
        vlSelfRef.product_lo = 0U;
    } else if (vlSelfRef.__PVT__start_rise) {
        vlSelfRef.multiplicand = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__a;
        __Vdly__count = 0x20U;
        vlSelfRef.product_hi = 0ULL;
        vlSelfRef.product_lo = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b;
    } else if ((0U < (IData)(vlSelfRef.count))) {
        __Vdly__count = (0x0000003fU & ((IData)(vlSelfRef.count) 
                                        - (IData)(1U)));
        vlSelfRef.product_hi = vlSelfRef.__PVT__next_hi;
        vlSelfRef.product_lo = vlSelfRef.__PVT__next_lo;
    }
    vlSelfRef.start = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__mul_flag;
    vlSelfRef.count = __Vdly__count;
    vlSelfRef.__PVT__start_rise = ((~ (IData)(vlSelfRef.__PVT__start_d)) 
                                   & (IData)(vlSelfRef.start));
    vlSelfRef.__PVT__hi_sum = (0x00000003ffffffffULL 
                               & ((QData)((IData)(vlSelfRef.multiplicand)) 
                                  + vlSelfRef.product_hi));
    vlSelfRef.busy = (0U != (IData)(vlSelfRef.count));
    vlSelfRef.__PVT__next_hi = (0x00000001ffffffffULL 
                                & ((1U & vlSelfRef.product_lo)
                                    ? (vlSelfRef.__PVT__hi_sum 
                                       >> 1U) : (vlSelfRef.product_hi 
                                                 >> 1U)));
    vlSelfRef.__PVT__next_lo = ((((1U & vlSelfRef.product_lo)
                                   ? (IData)(vlSelfRef.__PVT__hi_sum)
                                   : (IData)(vlSelfRef.product_hi)) 
                                 << 0x0000001fU) | 
                                (vlSelfRef.product_lo 
                                 >> 1U));
}
