// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"

void VminiRV_SoC_IROM___ico_sequent__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0(VminiRV_SoC_IROM* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VminiRV_SoC_IROM___ico_sequent__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.clka = vlSymsp->TOP.fpga_clk;
}

void VminiRV_SoC_IROM___nba_sequent__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0(VminiRV_SoC_IROM* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VminiRV_SoC_IROM___nba_sequent__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__douta = vlSelfRef.__PVT__mem[(0x0000ffffU 
                                                   & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_addr 
                                                      >> 2U))];
}
