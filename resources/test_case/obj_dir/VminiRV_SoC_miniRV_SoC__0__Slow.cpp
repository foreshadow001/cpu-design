// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"

VL_ATTR_COLD void VminiRV_SoC_miniRV_SoC___ctor_var_reset(VminiRV_SoC_miniRV_SoC* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VminiRV_SoC_miniRV_SoC___ctor_var_reset\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->fpga_clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3788526577575665920ull);
    vlSelf->fpga_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2329026847278319248ull);
    vlSelf->sw = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6428059944100430812ull);
    vlSelf->led = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14009161575225144129ull);
    vlSelf->dig_en = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5665788227264769465ull);
    vlSelf->dig_seg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 95249216967467866ull);
    vlSelf->dig_seg1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15970299611956719915ull);
    vlSelf->rx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7329251852453572689ull);
    vlSelf->tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16692943634734642928ull);
}
