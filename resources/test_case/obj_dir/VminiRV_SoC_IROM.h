// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VminiRV_SoC.h for the primary calling header

#ifndef VERILATED_VMINIRV_SOC_IROM_H_
#define VERILATED_VMINIRV_SOC_IROM_H_  // guard

#include "verilated.h"


class VminiRV_SoC__Syms;

class alignas(VL_CACHE_LINE_BYTES) VminiRV_SoC_IROM final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ clka;
    SData/*15:0*/ __PVT__addra;
    IData/*31:0*/ __PVT__douta;
    IData/*31:0*/ __PVT__i;
    IData/*31:0*/ __PVT__j;
    IData/*31:0*/ __PVT__mem_file;
    VlUnpacked<IData/*31:0*/, 65536> __PVT__mem;
    VlUnpacked<IData/*31:0*/, 65536> __PVT__mem_rd;

    // INTERNAL VARIABLES
    VminiRV_SoC__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VminiRV_SoC_IROM();
    ~VminiRV_SoC_IROM();
    void ctor(VminiRV_SoC__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(VminiRV_SoC_IROM);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
