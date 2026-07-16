// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"

void VminiRV_SoC___024root___ctor_var_reset(VminiRV_SoC___024root* vlSelf);

VminiRV_SoC___024root::VminiRV_SoC___024root(VminiRV_SoC__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    VminiRV_SoC___024root___ctor_var_reset(this);
}

void VminiRV_SoC___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VminiRV_SoC___024root::~VminiRV_SoC___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
