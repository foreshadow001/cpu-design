// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"

VL_ATTR_COLD void VminiRV_SoC_multiplier__W21___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu__0(VminiRV_SoC_multiplier__W21* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VminiRV_SoC_multiplier__W21___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__hi_sum = (0x00000007ffffffffULL 
                               & (vlSelfRef.multiplicand 
                                  + vlSelfRef.product_hi));
    vlSelfRef.busy = (0U != (IData)(vlSelfRef.count));
    vlSelfRef.start = (0x12U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.op));
    vlSelfRef.__PVT__next_hi = (0x00000003ffffffffULL 
                                & ((1U & (IData)(vlSelfRef.product_lo))
                                    ? (vlSelfRef.__PVT__hi_sum 
                                       >> 1U) : (vlSelfRef.product_hi 
                                                 >> 1U)));
    vlSelfRef.__PVT__next_lo = (((QData)((IData)((1U 
                                                  & ((1U 
                                                      & (IData)(vlSelfRef.product_lo))
                                                      ? (IData)(vlSelfRef.__PVT__hi_sum)
                                                      : (IData)(vlSelfRef.product_hi))))) 
                                 << 0x00000020U) | (QData)((IData)(
                                                                   (vlSelfRef.product_lo 
                                                                    >> 1U))));
    vlSelfRef.__PVT__start_rise = ((~ (IData)(vlSelfRef.__PVT__start_d)) 
                                   & (IData)(vlSelfRef.start));
}

VL_ATTR_COLD void VminiRV_SoC_multiplier__W21___ctor_var_reset(VminiRV_SoC_multiplier__W21* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VminiRV_SoC_multiplier__W21___ctor_var_reset\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->__PVT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->__PVT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->__PVT__x = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 9409450202036847209ull);
    vlSelf->__PVT__y = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 11123243248953317070ull);
    vlSelf->start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9867861323841650631ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->__PVT__z, __VscopeHash, 9847161165854524911ull);
    vlSelf->busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6386567572483775230ull);
    vlSelf->product_hi = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 15094018861780057995ull);
    vlSelf->product_lo = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 9548805623575670260ull);
    vlSelf->multiplicand = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 1216806911055910198ull);
    vlSelf->count = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 10730142128712957955ull);
    vlSelf->__PVT__start_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7233823569505293871ull);
    vlSelf->__PVT__hi_sum = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 16859112328922149601ull);
    vlSelf->__PVT__next_hi = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 16334334967864654615ull);
    vlSelf->__PVT__next_lo = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 10281755488347335706ull);
    vlSelf->__PVT__start_rise = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8459506654124776963ull);
}
