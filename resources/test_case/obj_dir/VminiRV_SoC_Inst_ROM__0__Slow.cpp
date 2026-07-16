// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"

VL_ATTR_COLD void VminiRV_SoC_Inst_ROM___ctor_var_reset(VminiRV_SoC_Inst_ROM* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_Inst_ROM___ctor_var_reset\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->__PVT__cpu_clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1778734116331908092ull);
    vlSelf->__PVT__cpu_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3291203161397430340ull);
    vlSelf->__PVT__inst_rreq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15123064317367608396ull);
    vlSelf->__PVT__inst_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2818994400641377574ull);
    vlSelf->__PVT__inst_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2881661861247159430ull);
    vlSelf->__PVT__inst_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17653795111096142571ull);
}
