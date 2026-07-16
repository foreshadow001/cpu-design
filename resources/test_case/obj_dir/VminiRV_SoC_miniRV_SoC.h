// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VminiRV_SoC.h for the primary calling header

#ifndef VERILATED_VMINIRV_SOC_MINIRV_SOC_H_
#define VERILATED_VMINIRV_SOC_MINIRV_SOC_H_  // guard

#include "verilated.h"
class VminiRV_SoC_cpu_top;


class VminiRV_SoC__Syms;

class alignas(VL_CACHE_LINE_BYTES) VminiRV_SoC_miniRV_SoC final {
  public:
    // CELLS
    VminiRV_SoC_cpu_top* U_cpu;

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ fpga_clk;
    CData/*0:0*/ fpga_rst;
    CData/*7:0*/ dig_en;
    CData/*7:0*/ dig_seg;
    CData/*7:0*/ dig_seg1;
    CData/*0:0*/ rx;
    CData/*0:0*/ tx;
    SData/*15:0*/ sw;
    SData/*15:0*/ led;

    // INTERNAL VARIABLES
    VminiRV_SoC__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VminiRV_SoC_miniRV_SoC();
    ~VminiRV_SoC_miniRV_SoC();
    void ctor(VminiRV_SoC__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(VminiRV_SoC_miniRV_SoC);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
