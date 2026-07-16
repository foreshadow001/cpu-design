// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"

bool VminiRV_SoC___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG
void VminiRV_SoC_IROM___ico_sequent__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0(VminiRV_SoC_IROM* vlSelf);
void VminiRV_SoC_cpu_core___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC_cpu_core* vlSelf);
void VminiRV_SoC_multiplier___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul__0(VminiRV_SoC_multiplier* vlSelf);
void VminiRV_SoC_multiplier__W21___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu__0(VminiRV_SoC_multiplier__W21* vlSelf);
void VminiRV_SoC_ALU___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0(VminiRV_SoC_ALU* vlSelf);
void VminiRV_SoC_multiplier__W21___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu__1(VminiRV_SoC_multiplier__W21* vlSelf);
void VminiRV_SoC_multiplier___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul__1(VminiRV_SoC_multiplier* vlSelf);
void VminiRV_SoC_cpu_core___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__1(VminiRV_SoC_cpu_core* vlSelf);
void VminiRV_SoC_cpu_core___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__2(VminiRV_SoC_cpu_core* vlSelf);
void VminiRV_SoC_cpu_core___ico_comb__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC_cpu_core* vlSelf);

bool VminiRV_SoC___024root___eval_phase__ico(VminiRV_SoC___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_phase__ico\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[1U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VicoTriggered[1U]) 
                                         | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
        vlSelfRef.__VicoTriggered[0U] = (QData)((IData)(
                                                        (((((IData)(vlSelfRef.rx) 
                                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rx__0)) 
                                                           << 3U) 
                                                          | (((IData)(vlSelfRef.sw) 
                                                              != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sw__0)) 
                                                             << 2U)) 
                                                         | ((((IData)(vlSelfRef.fpga_rst) 
                                                              != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__fpga_rst__0)) 
                                                             << 1U) 
                                                            | ((IData)(vlSelfRef.fpga_clk) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__fpga_clk__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__fpga_clk__0 
            = vlSelfRef.fpga_clk;
        vlSelfRef.__Vtrigprevexpr___TOP__fpga_rst__0 
            = vlSelfRef.fpga_rst;
        vlSelfRef.__Vtrigprevexpr___TOP__sw__0 = vlSelfRef.sw;
        vlSelfRef.__Vtrigprevexpr___TOP__rx__0 = vlSelfRef.rx;
        if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VicoDidInit)))))) {
            vlSelfRef.__VicoDidInit = 1U;
            vlSelfRef.__VicoTriggered[0U] = (1ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (2ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (4ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (8ULL | vlSelfRef.__VicoTriggered[0U]);
        }
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VminiRV_SoC___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = VminiRV_SoC___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_ico
            if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
                VminiRV_SoC_IROM___ico_sequent__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom));
            }
            if ((1ULL & vlSelfRef.__VicoTriggered[1U])) {
                VminiRV_SoC_cpu_core___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
                vlSelfRef.__Vm_traceActivity[1U] = 1U;
                VminiRV_SoC_multiplier___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul));
                VminiRV_SoC_multiplier__W21___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu));
                VminiRV_SoC_ALU___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU));
                VminiRV_SoC_multiplier__W21___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu__1((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu));
                VminiRV_SoC_multiplier___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul__1((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul));
                VminiRV_SoC_cpu_core___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__1((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
            }
            if ((2ULL & vlSelfRef.__VicoTriggered[0U])) {
                VminiRV_SoC_cpu_core___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__2((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
            }
            if (((1ULL & vlSelfRef.__VicoTriggered[1U]) 
                 | (2ULL & vlSelfRef.__VicoTriggered[0U]))) {
                VminiRV_SoC_cpu_core___ico_comb__TOP__miniRV_SoC__U_cpu__U_core__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
            }
        }
    }
    return (__VicoExecute);
}

bool VminiRV_SoC___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___trigger_anySet__act\n"); );
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

void VminiRV_SoC___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool VminiRV_SoC___024root___eval_phase__act(VminiRV_SoC___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_phase__act\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.clka) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__miniRV_SoC__U_cpu__U_irom__U_irom__clka__0))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelfRef.fpga_rst) 
                                                              & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__fpga_rst__1))) 
                                                             << 1U) 
                                                            | ((IData)(vlSelfRef.fpga_clk) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__fpga_clk__1)))))));
        vlSelfRef.__Vtrigprevexpr___TOP__fpga_clk__1 
            = vlSelfRef.fpga_clk;
        vlSelfRef.__Vtrigprevexpr___TOP__fpga_rst__1 
            = vlSelfRef.fpga_rst;
        vlSelfRef.__Vtrigprevexpr___TOP__miniRV_SoC__U_cpu__U_irom__U_irom__clka__0 
            = vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.clka;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VminiRV_SoC___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    VminiRV_SoC___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void VminiRV_SoC___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

void VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC_cpu_core* vlSelf);
void VminiRV_SoC_ALU___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0(VminiRV_SoC_ALU* vlSelf);
void VminiRV_SoC_multiplier__W21___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu__0(VminiRV_SoC_multiplier__W21* vlSelf);
void VminiRV_SoC_multiplier___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul__0(VminiRV_SoC_multiplier* vlSelf);
void VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__0(VminiRV_SoC_cpu_top* vlSelf);
void VminiRV_SoC_ALU___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__1(VminiRV_SoC_ALU* vlSelf);
void VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__1(VminiRV_SoC_cpu_top* vlSelf);
void VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__1(VminiRV_SoC_cpu_core* vlSelf);
void VminiRV_SoC_cpu_core___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC_cpu_core* vlSelf);
void VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__2(VminiRV_SoC_cpu_top* vlSelf);
void VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__2(VminiRV_SoC_cpu_core* vlSelf);
void VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__3(VminiRV_SoC_cpu_core* vlSelf);
void VminiRV_SoC_cpu_core___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__1(VminiRV_SoC_cpu_core* vlSelf);
void VminiRV_SoC_ALU___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0(VminiRV_SoC_ALU* vlSelf);
void VminiRV_SoC_cpu_core___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__2(VminiRV_SoC_cpu_core* vlSelf);
void VminiRV_SoC_IROM___nba_sequent__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0(VminiRV_SoC_IROM* vlSelf);
void VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__4(VminiRV_SoC_cpu_core* vlSelf);

bool VminiRV_SoC___024root___eval_phase__nba(VminiRV_SoC___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_phase__nba\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = VminiRV_SoC___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_nba
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
                VminiRV_SoC_ALU___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU));
                VminiRV_SoC_multiplier__W21___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu));
                VminiRV_SoC_multiplier___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul));
                VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__0((&vlSymsp->TOP__miniRV_SoC__U_cpu));
                VminiRV_SoC_ALU___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__1((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU));
            }
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__1((&vlSymsp->TOP__miniRV_SoC__U_cpu));
                VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__1((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
            }
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                VminiRV_SoC_cpu_core___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
            }
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__2((&vlSymsp->TOP__miniRV_SoC__U_cpu));
                vlSelfRef.__Vm_traceActivity[3U] = 1U;
                VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__2((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
            }
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__3((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
            }
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                VminiRV_SoC_cpu_core___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__1((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
                vlSelfRef.__Vm_traceActivity[4U] = 1U;
                VminiRV_SoC_ALU___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU));
                VminiRV_SoC_cpu_core___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__2((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
            }
            if ((4ULL & vlSelfRef.__VnbaTriggered[0U])) {
                VminiRV_SoC_IROM___nba_sequent__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom));
            }
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__4((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
            }
        }
        VminiRV_SoC___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void VminiRV_SoC___024root___eval(VminiRV_SoC___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            VminiRV_SoC___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("miniRV_SoC.v", 5, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = VminiRV_SoC___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VminiRV_SoC___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("miniRV_SoC.v", 5, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VminiRV_SoC___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("miniRV_SoC.v", 5, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = VminiRV_SoC___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = VminiRV_SoC___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void VminiRV_SoC___024root___eval_debug_assertions(VminiRV_SoC___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_debug_assertions\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.fpga_clk & 0xfeU)))) {
        Verilated::overWidthError("fpga_clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.fpga_rst & 0xfeU)))) {
        Verilated::overWidthError("fpga_rst");
    }
    if (VL_UNLIKELY(((vlSelfRef.rx & 0xfeU)))) {
        Verilated::overWidthError("rx");
    }
}
#endif  // VL_DEBUG
