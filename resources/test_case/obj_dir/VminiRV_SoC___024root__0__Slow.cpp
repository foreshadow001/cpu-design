// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"

VL_ATTR_COLD void VminiRV_SoC___024root___eval_static(VminiRV_SoC___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_static\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__fpga_clk__0 = vlSelfRef.fpga_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__fpga_rst__0 = vlSelfRef.fpga_rst;
    vlSelfRef.__Vtrigprevexpr___TOP__sw__0 = vlSelfRef.sw;
    vlSelfRef.__Vtrigprevexpr___TOP__rx__0 = vlSelfRef.rx;
    vlSelfRef.__Vtrigprevexpr___TOP__fpga_clk__1 = vlSelfRef.fpga_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__fpga_rst__1 = vlSelfRef.fpga_rst;
    vlSelfRef.__Vtrigprevexpr___TOP__miniRV_SoC__U_cpu__U_irom__U_irom__clka__0 
        = vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.clka;
}

VL_ATTR_COLD void VminiRV_SoC_cpu_top___eval_initial__TOP__miniRV_SoC__U_cpu(VminiRV_SoC_cpu_top* vlSelf);
VL_ATTR_COLD void VminiRV_SoC_IROM___eval_initial__TOP__miniRV_SoC__U_cpu__U_irom__U_irom(VminiRV_SoC_IROM* vlSelf);

VL_ATTR_COLD void VminiRV_SoC___024root___eval_initial(VminiRV_SoC___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_initial\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VminiRV_SoC_cpu_top___eval_initial__TOP__miniRV_SoC__U_cpu((&vlSymsp->TOP__miniRV_SoC__U_cpu));
    {
        // Inlined CFunc: __Vm_traceActivitySetAll
        vlSelfRef.__Vm_traceActivity[0U] = 1U;
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    VminiRV_SoC_IROM___eval_initial__TOP__miniRV_SoC__U_cpu__U_irom__U_irom((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom));
}

VL_ATTR_COLD void VminiRV_SoC___024root___eval_final(VminiRV_SoC___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_final\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VminiRV_SoC___024root___eval_phase__stl(VminiRV_SoC___024root* vlSelf);

VL_ATTR_COLD void VminiRV_SoC___024root___eval_settle(VminiRV_SoC___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_settle\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            VminiRV_SoC___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("miniRV_SoC.v", 5, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = VminiRV_SoC___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD bool VminiRV_SoC___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(VminiRV_SoC___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool VminiRV_SoC___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

VL_ATTR_COLD void VminiRV_SoC_cpu_core___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC_cpu_core* vlSelf);
void VminiRV_SoC_IROM___ico_sequent__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0(VminiRV_SoC_IROM* vlSelf);
VL_ATTR_COLD void VminiRV_SoC_ALU___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0(VminiRV_SoC_ALU* vlSelf);
VL_ATTR_COLD void VminiRV_SoC_multiplier___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul__0(VminiRV_SoC_multiplier* vlSelf);
VL_ATTR_COLD void VminiRV_SoC_multiplier__W21___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu__0(VminiRV_SoC_multiplier__W21* vlSelf);
VL_ATTR_COLD void VminiRV_SoC_cpu_core___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__1(VminiRV_SoC_cpu_core* vlSelf);
VL_ATTR_COLD void VminiRV_SoC_ALU___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__1(VminiRV_SoC_ALU* vlSelf);
VL_ATTR_COLD void VminiRV_SoC_cpu_core___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__2(VminiRV_SoC_cpu_core* vlSelf);

VL_ATTR_COLD bool VminiRV_SoC___024root___eval_phase__stl(VminiRV_SoC___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_phase__stl\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__stl
        vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VstlTriggered[0U]) 
                                         | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VminiRV_SoC___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = VminiRV_SoC___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                {
                    // Inlined CFunc: _stl_sequent__TOP__0
                    vlSelfRef.tx = vlSymsp->TOP__miniRV_SoC.tx;
                    vlSelfRef.dig_seg1 = vlSymsp->TOP__miniRV_SoC.dig_seg1;
                    vlSelfRef.dig_seg = vlSymsp->TOP__miniRV_SoC.dig_seg;
                    vlSelfRef.dig_en = vlSymsp->TOP__miniRV_SoC.dig_en;
                    vlSelfRef.led = vlSymsp->TOP__miniRV_SoC.led;
                }
                {
                    // Inlined CFunc: __Vm_traceActivitySetAll
                    vlSelfRef.__Vm_traceActivity[0U] = 1U;
                    vlSelfRef.__Vm_traceActivity[1U] = 1U;
                    vlSelfRef.__Vm_traceActivity[2U] = 1U;
                    vlSelfRef.__Vm_traceActivity[3U] = 1U;
                    vlSelfRef.__Vm_traceActivity[4U] = 1U;
                }
                VminiRV_SoC_cpu_core___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
                VminiRV_SoC_IROM___ico_sequent__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom));
                VminiRV_SoC_ALU___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU));
                VminiRV_SoC_multiplier___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul));
                VminiRV_SoC_multiplier__W21___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu));
                VminiRV_SoC_cpu_core___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__1((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
                VminiRV_SoC_ALU___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__1((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU));
                VminiRV_SoC_cpu_core___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__2((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
            }
        }
    }
    return (__VstlExecute);
}

bool VminiRV_SoC___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(VminiRV_SoC___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( fpga_clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( fpga_rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @( sw)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @( rx)\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool VminiRV_SoC___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(VminiRV_SoC___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge fpga_clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge fpga_rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge miniRV_SoC.U_cpu.U_irom.U_irom.clka)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VminiRV_SoC___024root___ctor_var_reset(VminiRV_SoC___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___ctor_var_reset\n"); );
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
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__fpga_clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__fpga_rst__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__sw__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rx__0 = 0;
    vlSelf->__VicoDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__fpga_clk__1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__fpga_rst__1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__miniRV_SoC__U_cpu__U_irom__U_irom__clka__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
