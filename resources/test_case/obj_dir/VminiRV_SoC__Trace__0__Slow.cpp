// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "VminiRV_SoC__Syms.h"


VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_sub__TOP__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "$rootio", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+178,0,"fpga_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+179,0,"fpga_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+180,0,"sw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+331,0,"led",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+332,0,"dig_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+333,0,"dig_seg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+334,0,"dig_seg1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+181,0,"rx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+335,0,"tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "miniRV_SoC", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BIT(tracep,c+178,0,"fpga_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+179,0,"fpga_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+180,0,"sw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+331,0,"led",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+332,0,"dig_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+333,0,"dig_seg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+334,0,"dig_seg1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+181,0,"rx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+335,0,"tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+178,0,"sys_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+179,0,"sys_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "U_cpu", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_irom__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BIT(tracep,c+178,0,"cpu_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+179,0,"cpu_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+182,0,"cpu2ic_rreq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+183,0,"cpu2ic_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+184,0,"ic2cpu_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+185,0,"ic2cpu_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+160,0,"cpu2dc_ren",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+161,0,"cpu2dc_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+162,0,"dc2cpu_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+186,0,"dc2cpu_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+163,0,"cpu2dc_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+164,0,"cpu2dc_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+101,0,"dc2cpu_wresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "U_core", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "U_dram", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+178,0,"cpu_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+179,0,"cpu_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+160,0,"data_ren",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+161,0,"data_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+162,0,"data_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+186,0,"data_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+163,0,"data_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+164,0,"data_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+101,0,"data_wresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "U_dram", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+336,0,"ADDR_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+178,0,"clka",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+165,0,"addra",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+163,0,"wea",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+164,0,"dina",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+186,0,"douta",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+2,0,"mem_file",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "U_irom", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_irom__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_irom__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_irom__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BIT(tracep,c+178,0,"cpu_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+179,0,"cpu_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+182,0,"inst_rreq",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+183,0,"inst_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+184,0,"inst_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+185,0,"inst_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "U_irom", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_dtype____0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BIT(tracep,c+179,0,"cpu_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+178,0,"cpu_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+182,0,"ifetch_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+183,0,"ifetch_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+187,0,"ifetch_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+185,0,"ifetch_inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+160,0,"daccess_ren",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+161,0,"daccess_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+162,0,"daccess_rvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+186,0,"daccess_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+163,0,"daccess_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+164,0,"daccess_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+101,0,"daccess_wresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+188,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+189,0,"fetch_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+190,0,"pc_plus_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+102,0,"flush_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+191,0,"flush_next2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+192,0,"load_resync",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+103,0,"load_resync2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+90,0,"load_stall_active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+104,0,"stall_synced",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+91,0,"effective_flush",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+193,0,"if_id_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+194,0,"if_id_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+22,0,"id_npc_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+195,0,"id_rf_wsel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+23,0,"id_sext_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+24,0,"id_alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+196,0,"id_alua_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+25,0,"id_alub_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+26,0,"id_ram_rop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+27,0,"id_ram_wop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+28,0,"id_is_mul",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+29,0,"id_is_div",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+197,0,"id_rf_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+198,0,"id_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+199,0,"id_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+200,0,"id_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+201,0,"id_rf_rd1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+202,0,"id_rf_rd2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+30,0,"id_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+31,0,"id_br_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+203,0,"id_ex_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+105,0,"id_ex_rd1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+166,0,"id_ex_rd2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+204,0,"id_ex_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+106,0,"id_ex_br_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+205,0,"id_ex_alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+107,0,"id_ex_alua_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+206,0,"id_ex_alub_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+167,0,"id_ex_rf_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+168,0,"id_ex_rf_wsel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+169,0,"id_ex_ram_rop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+170,0,"id_ex_ram_wop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+108,0,"id_ex_is_mul",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+109,0,"id_ex_is_div",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+207,0,"id_ex_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+208,0,"id_ex_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+171,0,"id_ex_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+110,0,"id_ex_npc_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+32,0,"load_use_stall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+33,0,"id_is_jal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+111,0,"ex_is_jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+209,0,"ex_br_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+31,0,"id_jal_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+106,0,"ex_br_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+210,0,"ex_jalr_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+112,0,"mul_div_flush",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+211,0,"flush_f",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+212,0,"flush_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+92,0,"pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+113,0,"mul_div_entering",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+34,0,"id_mul_div",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+35,0,"mul_div_stall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+114,0,"mul_div_stall_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+36,0,"mul_div_release",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+213,0,"stall_f",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+214,0,"stall_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+35,0,"stall_e",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+37,0,"forward_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+215,0,"forward_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+216,0,"id_fwd_rd1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+217,0,"id_fwd_rd2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+218,0,"id_store_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+172,0,"ex_mem_fwd_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+219,0,"ex_alu_a_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+93,0,"ex_alu_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+220,0,"ex_alu_b_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+221,0,"ex_alu_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+222,0,"ex_alu_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+94,0,"ex_br",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+6,0,"ex_mul_div_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+115,0,"ex_mem_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+161,0,"ex_mem_alu_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+116,0,"ex_mem_rd2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+117,0,"ex_mem_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+118,0,"ex_mem_br",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+173,0,"ex_mem_rf_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+174,0,"ex_mem_rf_wsel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+175,0,"ex_mem_ram_rop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+119,0,"ex_mem_ram_wop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+176,0,"ex_mem_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+120,0,"ex_mem_is_mul",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+121,0,"ex_mem_is_div",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+160,0,"mem_da_ren",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+161,0,"mem_da_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+163,0,"mem_da_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+164,0,"mem_da_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+223,0,"mem_wb_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+122,0,"mem_wb_alu_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+224,0,"mem_wb_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+225,0,"mem_wb_rf_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+226,0,"mem_wb_rf_wsel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+227,0,"mem_wb_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+123,0,"mem_wb_ram_rop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+124,0,"mem_wb_byte_offs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+228,0,"wb_ram_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+95,0,"wb_forward_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+229,0,"wb_is_load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+230,0,"wb_rf_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+227,0,"wb_rf_wR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+96,0,"wb_rf_wD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+231,0,"debug_wb_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+232,0,"debug_wb_rf_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+233,0,"debug_wb_rf_wR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+234,0,"debug_wb_rf_wD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+235,0,"debug_mem_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+236,0,"debug_mem_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+237,0,"debug_mem_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+238,0,"debug_mem_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+239,0,"store_data_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+125,0,"last_wb_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+240,0,"wb_change",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "U_ALU", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "U_CU", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+241,0,"opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+242,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+243,0,"funct7",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+22,0,"npc_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+23,0,"sext_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+196,0,"alua_sel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+25,0,"alub_sel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+24,0,"alu_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+28,0,"is_mul",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+29,0,"is_div",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+26,0,"ram_r_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+27,0,"ram_w_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+197,0,"rf_we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+195,0,"rf_wsel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+38,0,"ADDI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+244,0,"ADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+39,0,"SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+196,0,"AUIPC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+40,0,"XORI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+245,0,"XOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+41,0,"ANDI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+246,0,"AND",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+42,0,"OR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+43,0,"SLTI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+44,0,"SLTIU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+45,0,"SLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+46,0,"SLTU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+47,0,"BLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+48,0,"BGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+49,0,"BLTU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+50,0,"BGEU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+51,0,"JALR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+52,0,"LB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+53,0,"LBU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+54,0,"LH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+55,0,"LHU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+56,0,"SB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+57,0,"SH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+58,0,"SW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+59,0,"MUL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+60,0,"MULH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+61,0,"MULHU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+62,0,"DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+63,0,"DIVU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+64,0,"REM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+65,0,"REMU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+66,0,"ORI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+67,0,"SLLI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+68,0,"SRLI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+69,0,"SRAI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+70,0,"SLL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+71,0,"SRL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+72,0,"SRA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+73,0,"LW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+74,0,"BEQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"BNE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+247,0,"LUI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+248,0,"JAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+76,0,"NPC_OP_BRA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+248,0,"NPC_OP_JMP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+51,0,"NPC_OP_JALR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+77,0,"NPC_OP_PC4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+197,0,"RF_OP_WE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+249,0,"WB_OP_ALU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+78,0,"WB_OP_RAM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+79,0,"WB_OP_PC4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+247,0,"WB_OP_EXT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+80,0,"EXT_OP_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+76,0,"EXT_OP_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+250,0,"EXT_OP_U",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+81,0,"EXT_OP_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+248,0,"EXT_OP_J",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+251,0,"ALU_OP_ADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+39,0,"ALU_OP_SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+82,0,"ALU_OP_OR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+83,0,"ALU_OP_XOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+84,0,"ALU_OP_AND",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+85,0,"ALU_OP_SLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+86,0,"ALU_OP_SLTU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+48,0,"ALU_OP_GE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+50,0,"ALU_OP_GEU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+59,0,"ALU_OP_MUL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+60,0,"ALU_OP_MULH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+61,0,"ALU_OP_MULHU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+62,0,"ALU_OP_DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+63,0,"ALU_OP_DIVU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+64,0,"ALU_OP_REM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+65,0,"ALU_OP_REMU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+87,0,"ALU_OP_SLL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+88,0,"ALU_OP_SRL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+89,0,"ALU_OP_SRA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+74,0,"ALU_OP_EQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"ALU_OP_NE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+252,0,"ALU_A_SEL_RS1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+196,0,"ALU_A_SEL_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+253,0,"ALU_B_SEL_RS2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+25,0,"ALU_B_SEL_EXT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+52,0,"RAM_EXT_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+53,0,"RAM_EXT_BU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+54,0,"RAM_EXT_H",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+55,0,"RAM_EXT_HU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+73,0,"RAM_EXT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+56,0,"RAM_W_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+57,0,"RAM_W_H",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+58,0,"RAM_W_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "U_FWD", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+207,0,"id_ex_rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+208,0,"id_ex_rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+107,0,"id_ex_alua_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+206,0,"id_ex_alub_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+171,0,"id_ex_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+167,0,"id_ex_rf_we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+176,0,"ex_mem_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+173,0,"ex_mem_rf_we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+227,0,"mem_wb_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+225,0,"mem_wb_rf_we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+37,0,"forward_a",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+215,0,"forward_b",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+254,0,"fwd_a_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+255,0,"fwd_a_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+256,0,"fwd_b_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+257,0,"fwd_b_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "U_MEXT", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+123,0,"op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+186,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+124,0,"byte_offs",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+228,0,"ext",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+258,0,"aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "U_MREQ", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+161,0,"ram_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+175,0,"ram_rop",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+160,0,"da_ren",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+161,0,"da_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+119,0,"ram_wop",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+116,0,"ram_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+163,0,"da_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+164,0,"da_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+177,0,"offset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "U_RF", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+178,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+198,0,"rR1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+199,0,"rR2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+230,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+227,0,"wR",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+96,0,"wD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+201,0,"rD1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+202,0,"rD2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);

    VminiRV_SoC___024root__trace_init_dtype____0(vlSelf, tracep, "regs", 0, c+259, VerilatedTraceSigDirection::NONE);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "U_SEXT", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+23,0,"op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+290,0,"imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,7);
    VL_TRACE_DECL_BUS(tracep,c+30,0,"ext",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_dtype_sub____0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_dtype____0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_dtype____0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VminiRV_SoC___024root__trace_init_dtype_sub____0(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_dtype_sub____0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_dtype_sub____0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 1, 31);
    for (int i = 0; i < 31; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 1), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BIT(tracep,c+179,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+178,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+291,0,"op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+93,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+221,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+97,0,"c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+94,0,"br",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+6,0,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"mul_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+292,0,"mulu_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_QUAD(tracep,c+8,0,"mul_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+293,0,"mulu_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BIT(tracep,c+295,0,"mul_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+296,0,"mulu_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+10,0,"div_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+11,0,"divu_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+126,0,"div_quo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+127,0,"divu_quo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+128,0,"div_rem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+129,0,"divu_rem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+130,0,"div_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+131,0,"divu_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+297,0,"op_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+12,0,"effective_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+298,0,"a_latched",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+299,0,"b_latched",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+300,0,"multi_active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+13,0,"multi_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "U_div", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+337,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+178,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+179,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+98,0,"x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+301,0,"y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+10,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+126,0,"z",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+128,0,"r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+130,0,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+128,0,"remainder",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+126,0,"quotient",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+132,0,"divisor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+133,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BIT(tracep,c+134,0,"start_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+135,0,"shifted_rem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_QUAD(tracep,c+136,0,"diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 32,0);
    VL_TRACE_DECL_BIT(tracep,c+138,0,"enough",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+139,0,"next_rem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+140,0,"next_quo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+14,0,"start_rise",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "U_divu", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+338,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+178,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+179,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_QUAD(tracep,c+99,0,"x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 32,0);
    VL_TRACE_DECL_QUAD(tracep,c+302,0,"y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 32,0);
    VL_TRACE_DECL_BIT(tracep,c+11,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_QUAD(tracep,c+141,0,"z",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 32,0);
    VL_TRACE_DECL_QUAD(tracep,c+143,0,"r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 32,0);
    VL_TRACE_DECL_BIT(tracep,c+131,0,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_QUAD(tracep,c+143,0,"remainder",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 32,0);
    VL_TRACE_DECL_QUAD(tracep,c+141,0,"quotient",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 32,0);
    VL_TRACE_DECL_QUAD(tracep,c+145,0,"divisor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 32,0);
    VL_TRACE_DECL_BUS(tracep,c+147,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BIT(tracep,c+148,0,"start_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_QUAD(tracep,c+149,0,"shifted_rem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 32,0);
    VL_TRACE_DECL_QUAD(tracep,c+151,0,"diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 33,0);
    VL_TRACE_DECL_BIT(tracep,c+153,0,"enough",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_QUAD(tracep,c+154,0,"next_rem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 32,0);
    VL_TRACE_DECL_QUAD(tracep,c+156,0,"next_quo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 32,0);
    VL_TRACE_DECL_BIT(tracep,c+15,0,"start_rise",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "U_mul", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "U_mulu", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+336,0,"ADDR_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+304,0,"clka",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+305,0,"addra",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+185,0,"douta",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+5,0,"mem_file",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+337,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+178,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+179,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+93,0,"x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+221,0,"y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+306,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_QUAD(tracep,c+8,0,"z",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BIT(tracep,c+307,0,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+339,0,"O_WID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_QUAD(tracep,c+308,0,"product_hi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 32,0);
    VL_TRACE_DECL_BUS(tracep,c+310,0,"product_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+311,0,"multiplicand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+312,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BIT(tracep,c+158,0,"start_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_QUAD(tracep,c+16,0,"hi_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 33,0);
    VL_TRACE_DECL_QUAD(tracep,c+313,0,"next_hi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 32,0);
    VL_TRACE_DECL_BUS(tracep,c+315,0,"next_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+18,0,"start_rise",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu__0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+338,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+178,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+179,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_QUAD(tracep,c+99,0,"x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 32,0);
    VL_TRACE_DECL_QUAD(tracep,c+302,0,"y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 32,0);
    VL_TRACE_DECL_BIT(tracep,c+316,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+317,0,"z",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 65,0);
    VL_TRACE_DECL_BIT(tracep,c+296,0,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+340,0,"O_WID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_QUAD(tracep,c+320,0,"product_hi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 33,0);
    VL_TRACE_DECL_QUAD(tracep,c+322,0,"product_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 32,0);
    VL_TRACE_DECL_QUAD(tracep,c+324,0,"multiplicand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 32,0);
    VL_TRACE_DECL_BUS(tracep,c+326,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BIT(tracep,c+159,0,"start_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_QUAD(tracep,c+19,0,"hi_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 34,0);
    VL_TRACE_DECL_QUAD(tracep,c+327,0,"next_hi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 33,0);
    VL_TRACE_DECL_QUAD(tracep,c+329,0,"next_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 32,0);
    VL_TRACE_DECL_BIT(tracep,c+21,0,"start_rise",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_top(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_top\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VminiRV_SoC___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VminiRV_SoC___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VminiRV_SoC___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VminiRV_SoC___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_register(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_register\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VminiRV_SoC___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&VminiRV_SoC___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&VminiRV_SoC___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&VminiRV_SoC___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_const_0_sub_0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_const_0\n"); );
    // Body
    VminiRV_SoC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VminiRV_SoC___024root*>(voidSelf);
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VminiRV_SoC___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_const_0_sub_0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_const_0_sub_0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullSData(oldp+331,(vlSymsp->TOP__miniRV_SoC.led),16);
    bufp->fullCData(oldp+332,(vlSymsp->TOP__miniRV_SoC.dig_en),8);
    bufp->fullCData(oldp+333,(vlSymsp->TOP__miniRV_SoC.dig_seg),8);
    bufp->fullCData(oldp+334,(vlSymsp->TOP__miniRV_SoC.dig_seg1),8);
    bufp->fullBit(oldp+335,(vlSymsp->TOP__miniRV_SoC.tx));
    bufp->fullIData(oldp+336,(0x00000010U),32);
    bufp->fullIData(oldp+337,(0x00000020U),32);
    bufp->fullIData(oldp+338,(0x00000021U),32);
    bufp->fullIData(oldp+339,(0x00000040U),32);
    bufp->fullIData(oldp+340,(0x00000042U),32);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_full_0_sub_0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_full_0\n"); );
    // Body
    VminiRV_SoC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VminiRV_SoC___024root*>(voidSelf);
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VminiRV_SoC___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_full_dtype____0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 31>& __VdtypeVar);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_full_0_sub_0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_full_0_sub_0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+0,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dram__DOT__U_dram__DOT__i),32);
    bufp->fullIData(oldp+1,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dram__DOT__U_dram__DOT__j),32);
    bufp->fullIData(oldp+2,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dram__DOT__U_dram__DOT__mem_file),32);
    bufp->fullIData(oldp+3,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__i),32);
    bufp->fullIData(oldp+4,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__j),32);
    bufp->fullIData(oldp+5,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__mem_file),32);
    bufp->fullBit(oldp+6,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__busy));
    bufp->fullBit(oldp+7,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__mul_flag));
    bufp->fullQData(oldp+8,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__mul_res),64);
    bufp->fullBit(oldp+10,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__div_flag));
    bufp->fullBit(oldp+11,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__divu_flag));
    bufp->fullCData(oldp+12,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__effective_op),5);
    bufp->fullBit(oldp+13,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__multi_start));
    bufp->fullBit(oldp+14,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__start_rise));
    bufp->fullBit(oldp+15,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__start_rise));
    bufp->fullQData(oldp+16,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.__PVT__hi_sum),34);
    bufp->fullBit(oldp+18,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.__PVT__start_rise));
    bufp->fullQData(oldp+19,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.__PVT__hi_sum),35);
    bufp->fullBit(oldp+21,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.__PVT__start_rise));
    bufp->fullCData(oldp+22,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__npc_op),2);
    bufp->fullCData(oldp+23,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__sext_op),3);
    bufp->fullCData(oldp+24,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__alu_op),5);
    bufp->fullBit(oldp+25,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI) 
                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XORI) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ANDI) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI) 
                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU) 
                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI) 
                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI) 
                                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI) 
                                                     | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_RAM)))))))))) 
                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__EXT_OP_S) 
                               | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_22)))));
    bufp->fullCData(oldp+26,(((2U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LB)))) 
                              | ((3U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LBU)))) 
                                 | ((4U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LH)))) 
                                    | ((5U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LHU)))) 
                                       | (1U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LW))))))))),3);
    bufp->fullCData(oldp+27,((0x0000000fU & ((1U & 
                                              (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SB)))) 
                                             | ((3U 
                                                 & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SH)))) 
                                                | (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SW))))))),4);
    bufp->fullBit(oldp+28,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__is_mul));
    bufp->fullBit(oldp+29,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__is_div));
    bufp->fullIData(oldp+30,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_SEXT__DOT__ext),32);
    bufp->fullIData(oldp+31,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_br_target),32);
    bufp->fullBit(oldp+32,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__load_use_stall));
    bufp->fullBit(oldp+33,((3U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__npc_op))));
    bufp->fullBit(oldp+34,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_mul_div));
    bufp->fullBit(oldp+35,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mul_div_stall));
    bufp->fullBit(oldp+36,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mul_div_release));
    bufp->fullCData(oldp+37,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_FWD__DOT__forward_a),2);
    bufp->fullBit(oldp+38,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI));
    bufp->fullBit(oldp+39,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SUB));
    bufp->fullBit(oldp+40,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XORI));
    bufp->fullBit(oldp+41,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ANDI));
    bufp->fullBit(oldp+42,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR));
    bufp->fullBit(oldp+43,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI));
    bufp->fullBit(oldp+44,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU));
    bufp->fullBit(oldp+45,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT));
    bufp->fullBit(oldp+46,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU));
    bufp->fullBit(oldp+47,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BLT));
    bufp->fullBit(oldp+48,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BGE));
    bufp->fullBit(oldp+49,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BLTU));
    bufp->fullBit(oldp+50,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BGEU));
    bufp->fullBit(oldp+51,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__JALR));
    bufp->fullBit(oldp+52,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LB));
    bufp->fullBit(oldp+53,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LBU));
    bufp->fullBit(oldp+54,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LH));
    bufp->fullBit(oldp+55,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LHU));
    bufp->fullBit(oldp+56,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SB));
    bufp->fullBit(oldp+57,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SH));
    bufp->fullBit(oldp+58,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SW));
    bufp->fullBit(oldp+59,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MUL));
    bufp->fullBit(oldp+60,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MULH));
    bufp->fullBit(oldp+61,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MULHU));
    bufp->fullBit(oldp+62,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__DIV));
    bufp->fullBit(oldp+63,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__DIVU));
    bufp->fullBit(oldp+64,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__REM));
    bufp->fullBit(oldp+65,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__REMU));
    bufp->fullBit(oldp+66,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI));
    bufp->fullBit(oldp+67,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI));
    bufp->fullBit(oldp+68,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI));
    bufp->fullBit(oldp+69,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI));
    bufp->fullBit(oldp+70,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLL));
    bufp->fullBit(oldp+71,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL));
    bufp->fullBit(oldp+72,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA));
    bufp->fullBit(oldp+73,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LW));
    bufp->fullBit(oldp+74,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BEQ));
    bufp->fullBit(oldp+75,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BNE));
    bufp->fullBit(oldp+76,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__NPC_OP_BRA));
    bufp->fullBit(oldp+77,((1U & (~ ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__NPC_OP_BRA) 
                                     | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_PC4))))));
    bufp->fullBit(oldp+78,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_RAM));
    bufp->fullBit(oldp+79,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_PC4));
    bufp->fullBit(oldp+80,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__JALR) 
                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI) 
                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI) 
                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XORI) 
                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ANDI) 
                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI) 
                                           | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU) 
                                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI) 
                                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI) 
                                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI) 
                                                       | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_RAM)))))))))))));
    bufp->fullBit(oldp+81,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__EXT_OP_S));
    bufp->fullBit(oldp+82,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI) 
                            | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR))));
    bufp->fullBit(oldp+83,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ALU_OP_XOR));
    bufp->fullBit(oldp+84,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ALU_OP_AND));
    bufp->fullBit(oldp+85,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI) 
                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BLT) 
                               | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT)))));
    bufp->fullBit(oldp+86,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU) 
                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BLTU) 
                               | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU)))));
    bufp->fullBit(oldp+87,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLL) 
                            | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI))));
    bufp->fullBit(oldp+88,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL) 
                            | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI))));
    bufp->fullBit(oldp+89,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA) 
                            | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI))));
    bufp->fullBit(oldp+90,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__load_stall_active));
    bufp->fullBit(oldp+91,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__effective_flush));
    bufp->fullIData(oldp+92,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pc_next),32);
    bufp->fullIData(oldp+93,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__a),32);
    bufp->fullBit(oldp+94,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__br));
    bufp->fullIData(oldp+95,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__wb_forward_data),32);
    bufp->fullIData(oldp+96,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__wD),32);
    bufp->fullIData(oldp+97,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__c),32);
    bufp->fullIData(oldp+98,(((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__a 
                               >> 0x0000001fU) ? ((IData)(1U) 
                                                  + 
                                                  (~ vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__a))
                               : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__a)),32);
    bufp->fullQData(oldp+99,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__a))),33);
    bufp->fullBit(oldp+101,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_wresp));
    bufp->fullBit(oldp+102,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__flush_next));
    bufp->fullBit(oldp+103,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__load_resync2));
    bufp->fullBit(oldp+104,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__stall_synced));
    bufp->fullIData(oldp+105,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rd1),32);
    bufp->fullIData(oldp+106,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_br_target),32);
    bufp->fullBit(oldp+107,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_alua_sel));
    bufp->fullBit(oldp+108,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_is_mul));
    bufp->fullBit(oldp+109,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_is_div));
    bufp->fullCData(oldp+110,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_npc_op),2);
    bufp->fullBit(oldp+111,((1U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_npc_op))));
    bufp->fullBit(oldp+112,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mul_div_flush));
    bufp->fullBit(oldp+113,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mul_div_entering));
    bufp->fullBit(oldp+114,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mul_div_stall_d));
    bufp->fullIData(oldp+115,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_pc),32);
    bufp->fullIData(oldp+116,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rd2),32);
    bufp->fullIData(oldp+117,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ext),32);
    bufp->fullBit(oldp+118,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_br));
    bufp->fullCData(oldp+119,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_wop),4);
    bufp->fullBit(oldp+120,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_is_mul));
    bufp->fullBit(oldp+121,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_is_div));
    bufp->fullIData(oldp+122,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_alu_c),32);
    bufp->fullCData(oldp+123,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_ram_rop),3);
    bufp->fullCData(oldp+124,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_byte_offs),2);
    bufp->fullIData(oldp+125,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__last_wb_pc),32);
    bufp->fullIData(oldp+126,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__quotient),32);
    bufp->fullIData(oldp+127,((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__quotient)),32);
    bufp->fullIData(oldp+128,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__remainder),32);
    bufp->fullIData(oldp+129,((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__remainder)),32);
    bufp->fullBit(oldp+130,((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__count))));
    bufp->fullBit(oldp+131,((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__count))));
    bufp->fullIData(oldp+132,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__divisor),32);
    bufp->fullCData(oldp+133,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__count),6);
    bufp->fullBit(oldp+134,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__start_d));
    bufp->fullIData(oldp+135,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__shifted_rem),32);
    bufp->fullQData(oldp+136,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__diff),33);
    bufp->fullBit(oldp+138,((1U & (~ (IData)((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__diff 
                                              >> 0x00000020U))))));
    bufp->fullIData(oldp+139,(((1U & (IData)((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__diff 
                                              >> 0x00000020U)))
                                ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__shifted_rem
                                : (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__diff))),32);
    bufp->fullIData(oldp+140,(((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__quotient 
                                << 1U) | (1U & (~ (IData)(
                                                          (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__diff 
                                                           >> 0x00000020U)))))),32);
    bufp->fullQData(oldp+141,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__quotient),33);
    bufp->fullQData(oldp+143,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__remainder),33);
    bufp->fullQData(oldp+145,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__divisor),33);
    bufp->fullCData(oldp+147,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__count),6);
    bufp->fullBit(oldp+148,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__start_d));
    bufp->fullQData(oldp+149,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__shifted_rem),33);
    bufp->fullQData(oldp+151,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__diff),34);
    bufp->fullBit(oldp+153,((1U & (~ (IData)((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__diff 
                                              >> 0x00000021U))))));
    bufp->fullQData(oldp+154,((0x00000001ffffffffULL 
                               & ((1U & (IData)((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__diff 
                                                 >> 0x00000021U)))
                                   ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__shifted_rem
                                   : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__diff))),33);
    bufp->fullQData(oldp+156,((((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__quotient)) 
                                << 1U) | (QData)((IData)(
                                                         (1U 
                                                          & (~ (IData)(
                                                                       (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__diff 
                                                                        >> 0x00000021U)))))))),33);
    bufp->fullBit(oldp+158,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.__PVT__start_d));
    bufp->fullBit(oldp+159,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.__PVT__start_d));
    bufp->fullCData(oldp+160,((0x0000000fU & (- (IData)(
                                                        (0U 
                                                         != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop)))))),4);
    bufp->fullIData(oldp+161,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c),32);
    bufp->fullBit(oldp+162,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_valid));
    bufp->fullCData(oldp+163,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_da_wen),4);
    bufp->fullIData(oldp+164,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_da_wdata),32);
    bufp->fullSData(oldp+165,((0x0000ffffU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c 
                                              >> 2U))),16);
    bufp->fullIData(oldp+166,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rd2),32);
    bufp->fullBit(oldp+167,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rf_we));
    bufp->fullCData(oldp+168,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rf_wsel),2);
    bufp->fullCData(oldp+169,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_ram_rop),3);
    bufp->fullCData(oldp+170,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_ram_wop),4);
    bufp->fullCData(oldp+171,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rd),5);
    bufp->fullIData(oldp+172,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_fwd_data),32);
    bufp->fullBit(oldp+173,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rf_we));
    bufp->fullCData(oldp+174,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rf_wsel),2);
    bufp->fullCData(oldp+175,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop),3);
    bufp->fullCData(oldp+176,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rd),5);
    bufp->fullCData(oldp+177,((3U & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c)),2);
    bufp->fullBit(oldp+178,(vlSelfRef.fpga_clk));
    bufp->fullBit(oldp+179,(vlSelfRef.fpga_rst));
    bufp->fullSData(oldp+180,(vlSelfRef.sw),16);
    bufp->fullBit(oldp+181,(vlSelfRef.rx));
    bufp->fullBit(oldp+182,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_req));
    bufp->fullIData(oldp+183,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_addr),32);
    bufp->fullBit(oldp+184,(((~ (IData)(vlSelfRef.fpga_rst)) 
                             & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_req))));
    bufp->fullIData(oldp+185,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__douta),32);
    bufp->fullIData(oldp+186,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_rdata),32);
    bufp->fullBit(oldp+187,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_valid));
    bufp->fullIData(oldp+188,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.pc),32);
    bufp->fullIData(oldp+189,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.fetch_pc),32);
    bufp->fullIData(oldp+190,(((IData)(4U) + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.pc)),32);
    bufp->fullBit(oldp+191,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.flush_next2));
    bufp->fullBit(oldp+192,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.load_resync));
    bufp->fullIData(oldp+193,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_pc),32);
    bufp->fullIData(oldp+194,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst),32);
    bufp->fullCData(oldp+195,((3U & ((1U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_RAM)))) 
                                     | ((2U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_PC4)))) 
                                        | (- (IData)(
                                                     (0x37U 
                                                      == 
                                                      (0x0000007fU 
                                                       & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst)))))))),2);
    bufp->fullBit(oldp+196,((0x17U == (0x0000007fU 
                                       & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst))));
    bufp->fullBit(oldp+197,(((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI) 
                               | ((0U == (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                          >> 0x00000019U)) 
                                  & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_3))) 
                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SUB) 
                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI) 
                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ALU_OP_XOR) 
                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ALU_OP_AND) 
                                          | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR) 
                                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI) 
                                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU) 
                                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT) 
                                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU) 
                                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI) 
                                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI) 
                                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI) 
                                                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLL) 
                                                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA) 
                                                                        | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL)))))))))))))))) 
                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_RAM) 
                                | ((0x37U == (0x0000007fU 
                                              & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst)) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_22) 
                                      | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_mul_div)))))));
    bufp->fullCData(oldp+198,((0x0000001fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                              >> 0x0000000fU))),5);
    bufp->fullCData(oldp+199,((0x0000001fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                              >> 0x00000014U))),5);
    bufp->fullCData(oldp+200,((0x0000001fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                              >> 7U))),5);
    bufp->fullIData(oldp+201,((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs
                               [(0x0000001fU & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                 >> 0x0000000fU) 
                                                - (IData)(1U)))] 
                               & (- (IData)(((0x1eU 
                                              >= (0x0000001fU 
                                                  & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                      >> 0x0000000fU) 
                                                     - (IData)(1U)))) 
                                             & (0U 
                                                != 
                                                (0x0000001fU 
                                                 & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                    >> 0x0000000fU)))))))),32);
    bufp->fullIData(oldp+202,((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs
                               [(0x0000001fU & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                 >> 0x00000014U) 
                                                - (IData)(1U)))] 
                               & (- (IData)(((0x1eU 
                                              >= (0x0000001fU 
                                                  & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                      >> 0x00000014U) 
                                                     - (IData)(1U)))) 
                                             & (0U 
                                                != 
                                                (0x0000001fU 
                                                 & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                    >> 0x00000014U)))))))),32);
    bufp->fullIData(oldp+203,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_pc),32);
    bufp->fullIData(oldp+204,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_ext),32);
    bufp->fullCData(oldp+205,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_alu_op),5);
    bufp->fullBit(oldp+206,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_alub_sel));
    bufp->fullCData(oldp+207,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_rs1),5);
    bufp->fullCData(oldp+208,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_rs2),5);
    bufp->fullBit(oldp+209,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_br_taken));
    bufp->fullIData(oldp+210,((0xfffffffeU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_c)),32);
    bufp->fullBit(oldp+211,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.flush_f));
    bufp->fullBit(oldp+212,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.flush_d));
    bufp->fullBit(oldp+213,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.stall_f));
    bufp->fullBit(oldp+214,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.stall_d));
    bufp->fullCData(oldp+215,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.forward_b),2);
    bufp->fullIData(oldp+216,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_7) 
                                & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_6))
                                ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_c
                                : ((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rd) 
                                     == (0x0000001fU 
                                         & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                            >> 0x0000000fU))) 
                                    & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_0))
                                    ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c
                                    : ((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rd) 
                                         == (0x0000001fU 
                                             & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                >> 0x0000000fU))) 
                                        & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_1))
                                        ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__wb_forward_data
                                        : (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs
                                           [(0x0000001fU 
                                             & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                 >> 0x0000000fU) 
                                                - (IData)(1U)))] 
                                           & (- (IData)(
                                                        ((0x1eU 
                                                          >= 
                                                          (0x0000001fU 
                                                           & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                               >> 0x0000000fU) 
                                                              - (IData)(1U)))) 
                                                         & (0U 
                                                            != 
                                                            (0x0000001fU 
                                                             & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                                >> 0x0000000fU))))))))))),32);
    bufp->fullIData(oldp+217,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_8) 
                                & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_6))
                                ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_c
                                : ((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rd) 
                                     == (0x0000001fU 
                                         & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                            >> 0x00000014U))) 
                                    & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_0))
                                    ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c
                                    : ((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rd) 
                                         == (0x0000001fU 
                                             & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                >> 0x00000014U))) 
                                        & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_1))
                                        ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__wb_forward_data
                                        : (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs
                                           [(0x0000001fU 
                                             & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                 >> 0x00000014U) 
                                                - (IData)(1U)))] 
                                           & (- (IData)(
                                                        ((0x1eU 
                                                          >= 
                                                          (0x0000001fU 
                                                           & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                               >> 0x00000014U) 
                                                              - (IData)(1U)))) 
                                                         & (0U 
                                                            != 
                                                            (0x0000001fU 
                                                             & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                                >> 0x00000014U))))))))))),32);
    bufp->fullIData(oldp+218,(((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rd) 
                                 == (0x0000001fU & 
                                     (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                      >> 0x00000014U))) 
                                & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_0))
                                ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c
                                : (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_8) 
                                    & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_6))
                                    ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_c
                                    : ((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rd) 
                                         == (0x0000001fU 
                                             & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                >> 0x00000014U))) 
                                        & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_1))
                                        ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__wb_forward_data
                                        : (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs
                                           [(0x0000001fU 
                                             & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                 >> 0x00000014U) 
                                                - (IData)(1U)))] 
                                           & (- (IData)(
                                                        ((0x1eU 
                                                          >= 
                                                          (0x0000001fU 
                                                           & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                               >> 0x00000014U) 
                                                              - (IData)(1U)))) 
                                                         & (0U 
                                                            != 
                                                            (0x0000001fU 
                                                             & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                                >> 0x00000014U))))))))))),32);
    bufp->fullIData(oldp+219,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_alua_sel)
                                ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_pc
                                : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rd1)),32);
    bufp->fullIData(oldp+220,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_alub_sel)
                                ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_ext
                                : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rd2)),32);
    bufp->fullIData(oldp+221,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b),32);
    bufp->fullIData(oldp+222,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_c),32);
    bufp->fullIData(oldp+223,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_pc),32);
    bufp->fullIData(oldp+224,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_ext),32);
    bufp->fullBit(oldp+225,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rf_we));
    bufp->fullCData(oldp+226,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rf_wsel),2);
    bufp->fullCData(oldp+227,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rd),5);
    bufp->fullIData(oldp+228,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEXT__DOT__ext),32);
    bufp->fullBit(oldp+229,((1U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rf_wsel))));
    bufp->fullBit(oldp+230,(((1U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rf_wsel))
                              ? ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_valid) 
                                 & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rf_we))
                              : (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rf_we))));
    bufp->fullIData(oldp+231,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_pc),32);
    bufp->fullBit(oldp+232,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_we));
    bufp->fullCData(oldp+233,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_wR),5);
    bufp->fullIData(oldp+234,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_wD),32);
    bufp->fullIData(oldp+235,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_pc),32);
    bufp->fullCData(oldp+236,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_we),4);
    bufp->fullIData(oldp+237,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_waddr),32);
    bufp->fullIData(oldp+238,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_wdata),32);
    bufp->fullIData(oldp+239,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__store_data_r),32);
    bufp->fullBit(oldp+240,((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_pc 
                             != vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__last_wb_pc)));
    bufp->fullCData(oldp+241,((0x0000007fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst)),7);
    bufp->fullCData(oldp+242,((7U & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                     >> 0x0000000cU))),3);
    bufp->fullCData(oldp+243,((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                               >> 0x00000019U)),7);
    bufp->fullBit(oldp+244,(((0U == (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                     >> 0x00000019U)) 
                             & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_3))));
    bufp->fullBit(oldp+245,(((0U == (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                     >> 0x00000019U)) 
                             & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_14))));
    bufp->fullBit(oldp+246,(((0U == (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                     >> 0x00000019U)) 
                             & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_15))));
    bufp->fullBit(oldp+247,((0x37U == (0x0000007fU 
                                       & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst))));
    bufp->fullBit(oldp+248,((0x6fU == (0x0000007fU 
                                       & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst))));
    bufp->fullBit(oldp+249,(((0x17U == (0x0000007fU 
                                        & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst)) 
                             | ((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI) 
                                  | ((0U == (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                             >> 0x00000019U)) 
                                     & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_3))) 
                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SUB) 
                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI) 
                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ALU_OP_XOR) 
                                          | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ALU_OP_AND) 
                                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR) 
                                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI) 
                                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU) 
                                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT) 
                                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU) 
                                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI) 
                                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI) 
                                                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI) 
                                                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLL) 
                                                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA) 
                                                                           | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL)))))))))))))))) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_mul_div)))));
    bufp->fullBit(oldp+250,(((0x17U == (0x0000007fU 
                                        & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst)) 
                             | (0x37U == (0x0000007fU 
                                          & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst)))));
    bufp->fullBit(oldp+251,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI) 
                              | ((0U == (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                         >> 0x00000019U)) 
                                 & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_3))) 
                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_RAM) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__EXT_OP_S) 
                                   | ((0x17U == (0x0000007fU 
                                                 & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst)) 
                                      | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__JALR)))))));
    bufp->fullBit(oldp+252,((((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI) 
                                | ((0U == (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                           >> 0x00000019U)) 
                                   & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_3))) 
                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SUB) 
                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI) 
                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ALU_OP_XOR) 
                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ALU_OP_AND) 
                                           | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR) 
                                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI) 
                                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU) 
                                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT) 
                                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU) 
                                                          | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI) 
                                                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI) 
                                                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI) 
                                                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLL) 
                                                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA) 
                                                                         | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL)))))))))))))))) 
                              | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_mul_div)) 
                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_RAM) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__EXT_OP_S) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__NPC_OP_BRA) 
                                      | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_PC4)))))));
    bufp->fullBit(oldp+253,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__NPC_OP_BRA) 
                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLL) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA) 
                                      | (((0U == (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                  >> 0x00000019U)) 
                                          & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_3)) 
                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SUB) 
                                            | (((0U 
                                                 == 
                                                 (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                  >> 0x00000019U)) 
                                                & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_14)) 
                                               | (((0U 
                                                    == 
                                                    (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                     >> 0x00000019U)) 
                                                   & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_15)) 
                                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR) 
                                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT) 
                                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU) 
                                                           | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_mul_div))))))))))))));
    bufp->fullBit(oldp+254,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_0) 
                             & ((~ (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_alua_sel)) 
                                & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_rs1) 
                                   == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rd))))));
    bufp->fullBit(oldp+255,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_1) 
                             & ((~ (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_alua_sel)) 
                                & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_rs1) 
                                   == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rd))))));
    bufp->fullBit(oldp+256,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_0) 
                             & ((~ (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_alub_sel)) 
                                & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_rs2) 
                                   == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rd))))));
    bufp->fullBit(oldp+257,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_1) 
                             & ((~ (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_alub_sel)) 
                                & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_rs2) 
                                   == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rd))))));
    bufp->fullIData(oldp+258,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEXT__DOT__aligned),32);
    VminiRV_SoC___024root__trace_full_dtype____0(vlSelf, bufp, 259, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs);
    bufp->fullIData(oldp+290,((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                               >> 7U)),25);
    bufp->fullCData(oldp+291,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.op),5);
    bufp->fullBit(oldp+292,((0x12U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.op))));
    bufp->fullQData(oldp+293,((((QData)((IData)((0x7fffffffU 
                                                 & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_hi)))) 
                                << 0x00000021U) | vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_lo)),64);
    bufp->fullBit(oldp+295,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.mul_busy));
    bufp->fullBit(oldp+296,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.busy));
    bufp->fullCData(oldp+297,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.op_r),5);
    bufp->fullIData(oldp+298,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.a_latched),32);
    bufp->fullIData(oldp+299,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.b_latched),32);
    bufp->fullBit(oldp+300,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.multi_active));
    bufp->fullIData(oldp+301,(((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b 
                                >> 0x0000001fU) ? ((IData)(1U) 
                                                   + 
                                                   (~ vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b))
                                : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)),32);
    bufp->fullQData(oldp+302,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b))),33);
    bufp->fullBit(oldp+304,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.clka));
    bufp->fullSData(oldp+305,((0x0000ffffU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_addr 
                                              >> 2U))),16);
    bufp->fullBit(oldp+306,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.start));
    bufp->fullBit(oldp+307,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.busy));
    bufp->fullQData(oldp+308,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.product_hi),33);
    bufp->fullIData(oldp+310,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.product_lo),32);
    bufp->fullIData(oldp+311,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.multiplicand),32);
    bufp->fullCData(oldp+312,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.count),6);
    bufp->fullQData(oldp+313,((0x00000001ffffffffULL 
                               & ((1U & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.product_lo)
                                   ? (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.__PVT__hi_sum 
                                      >> 1U) : (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.product_hi 
                                                >> 1U)))),33);
    bufp->fullIData(oldp+315,(((((1U & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.product_lo)
                                  ? (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.__PVT__hi_sum)
                                  : (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.product_hi)) 
                                << 0x0000001fU) | (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.product_lo 
                                                   >> 1U))),32);
    bufp->fullBit(oldp+316,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.start));
    __Vtemp_1[0U] = (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_lo);
    __Vtemp_1[1U] = (((IData)((0x00000001ffffffffULL 
                               & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_hi)) 
                      << 1U) | (IData)((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_lo 
                                        >> 0x00000020U)));
    __Vtemp_1[2U] = (((IData)((0x00000001ffffffffULL 
                               & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_hi)) 
                      >> 0x0000001fU) | ((IData)(((0x00000001ffffffffULL 
                                                   & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_hi) 
                                                  >> 0x00000020U)) 
                                         << 1U));
    bufp->fullWData(oldp+317,(__Vtemp_1),66);
    bufp->fullQData(oldp+320,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_hi),34);
    bufp->fullQData(oldp+322,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_lo),33);
    bufp->fullQData(oldp+324,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.multiplicand),33);
    bufp->fullCData(oldp+326,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.count),6);
    bufp->fullQData(oldp+327,((0x00000003ffffffffULL 
                               & ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_lo))
                                   ? (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.__PVT__hi_sum 
                                      >> 1U) : (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_hi 
                                                >> 1U)))),34);
    bufp->fullQData(oldp+329,((((QData)((IData)((1U 
                                                 & ((1U 
                                                     & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_lo))
                                                     ? (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.__PVT__hi_sum)
                                                     : (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_hi))))) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_lo 
                                                                   >> 1U))))),33);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_full_dtype____0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 31>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_full_dtype____0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[0]),32);
    bufp->fullIData(oldp+1,(__VdtypeVar[1]),32);
    bufp->fullIData(oldp+2,(__VdtypeVar[2]),32);
    bufp->fullIData(oldp+3,(__VdtypeVar[3]),32);
    bufp->fullIData(oldp+4,(__VdtypeVar[4]),32);
    bufp->fullIData(oldp+5,(__VdtypeVar[5]),32);
    bufp->fullIData(oldp+6,(__VdtypeVar[6]),32);
    bufp->fullIData(oldp+7,(__VdtypeVar[7]),32);
    bufp->fullIData(oldp+8,(__VdtypeVar[8]),32);
    bufp->fullIData(oldp+9,(__VdtypeVar[9]),32);
    bufp->fullIData(oldp+10,(__VdtypeVar[10]),32);
    bufp->fullIData(oldp+11,(__VdtypeVar[11]),32);
    bufp->fullIData(oldp+12,(__VdtypeVar[12]),32);
    bufp->fullIData(oldp+13,(__VdtypeVar[13]),32);
    bufp->fullIData(oldp+14,(__VdtypeVar[14]),32);
    bufp->fullIData(oldp+15,(__VdtypeVar[15]),32);
    bufp->fullIData(oldp+16,(__VdtypeVar[16]),32);
    bufp->fullIData(oldp+17,(__VdtypeVar[17]),32);
    bufp->fullIData(oldp+18,(__VdtypeVar[18]),32);
    bufp->fullIData(oldp+19,(__VdtypeVar[19]),32);
    bufp->fullIData(oldp+20,(__VdtypeVar[20]),32);
    bufp->fullIData(oldp+21,(__VdtypeVar[21]),32);
    bufp->fullIData(oldp+22,(__VdtypeVar[22]),32);
    bufp->fullIData(oldp+23,(__VdtypeVar[23]),32);
    bufp->fullIData(oldp+24,(__VdtypeVar[24]),32);
    bufp->fullIData(oldp+25,(__VdtypeVar[25]),32);
    bufp->fullIData(oldp+26,(__VdtypeVar[26]),32);
    bufp->fullIData(oldp+27,(__VdtypeVar[27]),32);
    bufp->fullIData(oldp+28,(__VdtypeVar[28]),32);
    bufp->fullIData(oldp+29,(__VdtypeVar[29]),32);
    bufp->fullIData(oldp+30,(__VdtypeVar[30]),32);
}
