// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VminiRV_SoC.h for the primary calling header

#ifndef VERILATED_VMINIRV_SOC___024ROOT_H_
#define VERILATED_VMINIRV_SOC___024ROOT_H_  // guard

#include "verilated.h"
class VminiRV_SoC_miniRV_SoC;


class VminiRV_SoC__Syms;

class alignas(VL_CACHE_LINE_BYTES) VminiRV_SoC___024root final {
  public:
    // CELLS
    VminiRV_SoC_miniRV_SoC* miniRV_SoC;

    // DESIGN SPECIFIC STATE
    VL_IN8(fpga_clk,0,0);
    VL_IN8(fpga_rst,0,0);
    VL_OUT8(dig_en,7,0);
    VL_OUT8(dig_seg,7,0);
    VL_OUT8(dig_seg1,7,0);
    VL_IN8(rx,0,0);
    VL_OUT8(tx,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__fpga_clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__fpga_rst__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rx__0;
    CData/*0:0*/ __VicoDidInit;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VicoPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__fpga_clk__1;
    CData/*0:0*/ __Vtrigprevexpr___TOP__fpga_rst__1;
    CData/*0:0*/ __Vtrigprevexpr___TOP__miniRV_SoC__U_cpu__U_irom__U_irom__clka__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    VL_IN16(sw,15,0);
    VL_OUT16(led,15,0);
    SData/*15:0*/ __Vtrigprevexpr___TOP__sw__0;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 2> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;

    // INTERNAL VARIABLES
    VminiRV_SoC__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VminiRV_SoC___024root(VminiRV_SoC__Syms* symsp, const char* namep);
    ~VminiRV_SoC___024root();
    VL_UNCOPYABLE(VminiRV_SoC___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
