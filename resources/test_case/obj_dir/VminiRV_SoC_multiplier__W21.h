// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VminiRV_SoC.h for the primary calling header

#ifndef VERILATED_VMINIRV_SOC_MULTIPLIER__W21_H_
#define VERILATED_VMINIRV_SOC_MULTIPLIER__W21_H_  // guard

#include "verilated.h"


class VminiRV_SoC__Syms;

class alignas(VL_CACHE_LINE_BYTES) VminiRV_SoC_multiplier__W21 final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __PVT__clk;
    CData/*0:0*/ __PVT__rst;
    CData/*0:0*/ start;
    CData/*0:0*/ busy;
    CData/*5:0*/ count;
    CData/*0:0*/ __PVT__start_d;
    CData/*0:0*/ __PVT__start_rise;
    VlWide<3>/*65:0*/ __PVT__z;
    QData/*32:0*/ __PVT__x;
    QData/*32:0*/ __PVT__y;
    QData/*33:0*/ product_hi;
    QData/*32:0*/ product_lo;
    QData/*32:0*/ multiplicand;
    QData/*34:0*/ __PVT__hi_sum;
    QData/*33:0*/ __PVT__next_hi;
    QData/*32:0*/ __PVT__next_lo;

    // INTERNAL VARIABLES
    VminiRV_SoC__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VminiRV_SoC_multiplier__W21();
    ~VminiRV_SoC_multiplier__W21();
    void ctor(VminiRV_SoC__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(VminiRV_SoC_multiplier__W21);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
