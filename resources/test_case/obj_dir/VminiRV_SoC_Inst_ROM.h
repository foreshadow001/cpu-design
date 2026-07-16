// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VminiRV_SoC.h for the primary calling header

#ifndef VERILATED_VMINIRV_SOC_INST_ROM_H_
#define VERILATED_VMINIRV_SOC_INST_ROM_H_  // guard

#include "verilated.h"
class VminiRV_SoC_IROM;


class VminiRV_SoC__Syms;

class alignas(VL_CACHE_LINE_BYTES) VminiRV_SoC_Inst_ROM final {
  public:
    // CELLS
    VminiRV_SoC_IROM* U_irom;

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __PVT__cpu_clk;
    CData/*0:0*/ __PVT__cpu_rst;
    CData/*0:0*/ __PVT__inst_rreq;
    CData/*0:0*/ __PVT__inst_valid;
    IData/*31:0*/ __PVT__inst_addr;
    IData/*31:0*/ __PVT__inst_out;

    // INTERNAL VARIABLES
    VminiRV_SoC__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VminiRV_SoC_Inst_ROM();
    ~VminiRV_SoC_Inst_ROM();
    void ctor(VminiRV_SoC__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(VminiRV_SoC_Inst_ROM);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
