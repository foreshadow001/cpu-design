// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"

VL_ATTR_COLD void VminiRV_SoC_IROM___eval_initial__TOP__miniRV_SoC__U_cpu__U_irom__U_irom(VminiRV_SoC_IROM* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VminiRV_SoC_IROM___eval_initial__TOP__miniRV_SoC__U_cpu__U_irom__U_irom\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__i = 0U;
    while (VL_GTS_III(32, 0x00010000U, vlSelfRef.__PVT__i)) {
        vlSelfRef.__PVT__j = vlSelfRef.__PVT__i;
        while (VL_LTS_III(32, vlSelfRef.__PVT__j, ((IData)(0x00000100U) 
                                                   + vlSelfRef.__PVT__i))) {
            vlSelfRef.__PVT__mem[(0x0000ffffU & vlSelfRef.__PVT__j)] = 0U;
            vlSelfRef.__PVT__j = ((IData)(1U) + vlSelfRef.__PVT__j);
        }
        vlSelfRef.__PVT__i = ((IData)(0x00000100U) 
                              + vlSelfRef.__PVT__i);
    }
    vlSelfRef.__PVT__mem_file = VL_FOPEN_NN("addi.bin"s
                                            , "r"s);
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.__PVT__mem_file)))) {
        VL_WRITEF_NX("[ERROR] Open file addi.bin failed, please check whether file exists!\n\n[%0t] %%Fatal: ram.v:28: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"miniRV_SoC.U_cpu.U_irom.U_irom", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("ram.v", 28, "", false);
    }
    VL_WRITEF_NX("[INFO] Instruction ROM initialized with addi.bin\n",0);
    std::ignore = VL_FREAD_I(32, 0, 65536, &(vlSelfRef.__PVT__mem_rd)
                             , vlSelfRef.__PVT__mem_file
                             , 0, 65536);
    vlSelfRef.__PVT__i = 0U;
    while (VL_GTS_III(32, 0x00010000U, vlSelfRef.__PVT__i)) {
        vlSelfRef.__PVT__j = vlSelfRef.__PVT__i;
        while (VL_LTS_III(32, vlSelfRef.__PVT__j, ((IData)(0x00000100U) 
                                                   + vlSelfRef.__PVT__i))) {
            vlSelfRef.__PVT__mem[(0x0000ffffU & vlSelfRef.__PVT__j)] 
                = ((((0x0000ff00U & (vlSelfRef.__PVT__mem_rd
                                     [(0x0000ffffU 
                                       & vlSelfRef.__PVT__j)] 
                                     << 8U)) | (0x000000ffU 
                                                & (vlSelfRef.__PVT__mem_rd
                                                   [
                                                   (0x0000ffffU 
                                                    & vlSelfRef.__PVT__j)] 
                                                   >> 8U))) 
                    << 0x00000010U) | ((0x0000ff00U 
                                        & (vlSelfRef.__PVT__mem_rd
                                           [(0x0000ffffU 
                                             & vlSelfRef.__PVT__j)] 
                                           >> 8U)) 
                                       | (vlSelfRef.__PVT__mem_rd
                                          [(0x0000ffffU 
                                            & vlSelfRef.__PVT__j)] 
                                          >> 0x18U)));
            vlSelfRef.__PVT__j = ((IData)(1U) + vlSelfRef.__PVT__j);
        }
        vlSelfRef.__PVT__i = ((IData)(0x00000100U) 
                              + vlSelfRef.__PVT__i);
    }
    vlSelfRef.__PVT__douta = 0U;
}

VL_ATTR_COLD void VminiRV_SoC_IROM___ctor_var_reset(VminiRV_SoC_IROM* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VminiRV_SoC_IROM___ctor_var_reset\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clka = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10236781857238200718ull);
    vlSelf->__PVT__addra = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6194089451892971914ull);
    vlSelf->__PVT__douta = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6944548842003005090ull);
    vlSelf->__PVT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15817570140490810055ull);
    vlSelf->__PVT__j = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15917291556903334389ull);
    vlSelf->__PVT__mem_file = 0;
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->__PVT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4032165174000709208ull);
    }
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->__PVT__mem_rd[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9568543471595764991ull);
    }
}
