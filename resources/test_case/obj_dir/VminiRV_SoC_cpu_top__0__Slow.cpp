// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"

VL_ATTR_COLD void VminiRV_SoC_cpu_top___eval_initial__TOP__miniRV_SoC__U_cpu(VminiRV_SoC_cpu_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VminiRV_SoC_cpu_top___eval_initial__TOP__miniRV_SoC__U_cpu\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00010000U, vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__i)) {
        vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__j 
            = vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__i;
        while (VL_LTS_III(32, vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__j, 
                          ((IData)(0x00000100U) + vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__i))) {
            vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem[(0x0000ffffU 
                                                            & vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__j)] = 0U;
            vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__j 
                = ((IData)(1U) + vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__j);
        }
        vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__i 
            = ((IData)(0x00000100U) + vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__i);
    }
    vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem_file 
        = VL_FOPEN_NN("addi.bin"s, "r"s);
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem_file)))) {
        VL_WRITEF_NX("[ERROR] Open file addi.bin failed, please check whether file exists!\n\n[%0t] %%Fatal: ram.v:79: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"miniRV_SoC.U_cpu.U_dram.U_dram", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("ram.v", 79, "", false);
    }
    VL_WRITEF_NX("[INFO] Data RAM initialized with addi.bin\n",0);
    std::ignore = VL_FREAD_I(32, 0, 65536, &(vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem_rd)
                             , vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem_file
                             , 0, 65536);
    vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00010000U, vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__i)) {
        vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__j 
            = vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__i;
        while (VL_LTS_III(32, vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__j, 
                          ((IData)(0x00000100U) + vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__i))) {
            vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem[(0x0000ffffU 
                                                            & vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__j)] 
                = ((((0x0000ff00U & (vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem_rd
                                     [(0x0000ffffU 
                                       & vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__j)] 
                                     << 8U)) | (0x000000ffU 
                                                & (vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem_rd
                                                   [
                                                   (0x0000ffffU 
                                                    & vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__j)] 
                                                   >> 8U))) 
                    << 0x00000010U) | ((0x0000ff00U 
                                        & (vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem_rd
                                           [(0x0000ffffU 
                                             & vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__j)] 
                                           >> 8U)) 
                                       | (vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem_rd
                                          [(0x0000ffffU 
                                            & vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__j)] 
                                          >> 0x18U)));
            vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__j 
                = ((IData)(1U) + vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__j);
        }
        vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__i 
            = ((IData)(0x00000100U) + vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__i);
    }
    vlSelfRef.__PVT__dc2cpu_rdata = 0U;
}

VL_ATTR_COLD void VminiRV_SoC_cpu_top___ctor_var_reset(VminiRV_SoC_cpu_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VminiRV_SoC_cpu_top___ctor_var_reset\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->__PVT__cpu_clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1778734116331908092ull);
    vlSelf->__PVT__cpu_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3291203161397430340ull);
    vlSelf->__PVT__dc2cpu_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2997495713283647695ull);
    vlSelf->__PVT__dc2cpu_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8307247787385901520ull);
    vlSelf->__PVT__dc2cpu_wresp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8596049284252740770ull);
    vlSelf->__PVT__U_dram__DOT__U_dram__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11152381209628549080ull);
    vlSelf->__PVT__U_dram__DOT__U_dram__DOT__j = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 876063424920550392ull);
    vlSelf->__PVT__U_dram__DOT__U_dram__DOT__mem_file = 0;
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->__PVT__U_dram__DOT__U_dram__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1477975187475610059ull);
    }
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->__PVT__U_dram__DOT__U_dram__DOT__mem_rd[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11619560648704446094ull);
    }
}
