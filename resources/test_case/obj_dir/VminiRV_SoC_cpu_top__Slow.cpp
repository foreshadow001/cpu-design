// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"

void VminiRV_SoC_cpu_top___ctor_var_reset(VminiRV_SoC_cpu_top* vlSelf);

VminiRV_SoC_cpu_top::VminiRV_SoC_cpu_top() = default;
VminiRV_SoC_cpu_top::~VminiRV_SoC_cpu_top() = default;

void VminiRV_SoC_cpu_top::ctor(VminiRV_SoC__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    VminiRV_SoC_cpu_top___ctor_var_reset(this);
}

void VminiRV_SoC_cpu_top::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void VminiRV_SoC_cpu_top::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
