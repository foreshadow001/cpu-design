// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VminiRV_SoC.h for the primary calling header

#ifndef VERILATED_VMINIRV_SOC_ALU_H_
#define VERILATED_VMINIRV_SOC_ALU_H_  // guard

#include "verilated.h"
class VminiRV_SoC_multiplier;
class VminiRV_SoC_multiplier__W21;


class VminiRV_SoC__Syms;

class alignas(VL_CACHE_LINE_BYTES) VminiRV_SoC_ALU final {
  public:
    // CELLS
    VminiRV_SoC_multiplier* U_mul;
    VminiRV_SoC_multiplier__W21* U_mulu;

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __PVT__rst;
    CData/*0:0*/ __PVT__clk;
    CData/*4:0*/ op;
    CData/*0:0*/ __PVT__br;
    CData/*0:0*/ __PVT__busy;
    CData/*0:0*/ __PVT__mul_flag;
    CData/*0:0*/ mul_busy;
    CData/*0:0*/ __PVT__div_flag;
    CData/*0:0*/ __PVT__divu_flag;
    CData/*4:0*/ op_r;
    CData/*4:0*/ __PVT__effective_op;
    CData/*0:0*/ multi_active;
    CData/*0:0*/ __PVT__multi_start;
    CData/*5:0*/ __PVT__U_divu__DOT__count;
    CData/*0:0*/ __PVT__U_divu__DOT__start_d;
    CData/*0:0*/ __PVT__U_divu__DOT__start_rise;
    CData/*5:0*/ __PVT__U_div__DOT__count;
    CData/*0:0*/ __PVT__U_div__DOT__start_d;
    CData/*0:0*/ __PVT__U_div__DOT__start_rise;
    IData/*31:0*/ __PVT__a;
    IData/*31:0*/ __PVT__b;
    IData/*31:0*/ __PVT__c;
    IData/*31:0*/ a_latched;
    IData/*31:0*/ b_latched;
    IData/*31:0*/ __PVT__U_div__DOT__remainder;
    IData/*31:0*/ __PVT__U_div__DOT__quotient;
    IData/*31:0*/ __PVT__U_div__DOT__divisor;
    IData/*31:0*/ __PVT__U_div__DOT__shifted_rem;
    IData/*31:0*/ __PVT__U_div__DOT__next_quo;
    QData/*63:0*/ __PVT__mul_res;
    QData/*32:0*/ __PVT__U_divu__DOT__remainder;
    QData/*32:0*/ __PVT__U_divu__DOT__quotient;
    QData/*32:0*/ __PVT__U_divu__DOT__divisor;
    QData/*32:0*/ __PVT__U_divu__DOT__shifted_rem;
    QData/*33:0*/ __PVT__U_divu__DOT__diff;
    QData/*32:0*/ __PVT__U_divu__DOT__next_quo;
    QData/*32:0*/ __PVT__U_div__DOT__diff;

    // INTERNAL VARIABLES
    VminiRV_SoC__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VminiRV_SoC_ALU();
    ~VminiRV_SoC_ALU();
    void ctor(VminiRV_SoC__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(VminiRV_SoC_ALU);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
