// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "VminiRV_SoC__Syms.h"


void VminiRV_SoC___024root__trace_chg_0_sub_0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VminiRV_SoC___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_chg_0\n"); );
    // Body
    VminiRV_SoC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VminiRV_SoC___024root*>(voidSelf);
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    VminiRV_SoC___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VminiRV_SoC___024root__trace_chg_dtype____0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 31>& __VdtypeVar);

void VminiRV_SoC___024root__trace_chg_0_sub_0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_chg_0_sub_0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0U]))) {
        bufp->chgIData(oldp+0,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dram__DOT__U_dram__DOT__i),32);
        bufp->chgIData(oldp+1,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dram__DOT__U_dram__DOT__j),32);
        bufp->chgIData(oldp+2,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dram__DOT__U_dram__DOT__mem_file),32);
        bufp->chgIData(oldp+3,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__i),32);
        bufp->chgIData(oldp+4,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__j),32);
        bufp->chgIData(oldp+5,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__mem_file),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity[2U])))) {
        bufp->chgBit(oldp+6,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__busy));
        bufp->chgBit(oldp+7,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__mul_flag));
        bufp->chgQData(oldp+8,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__mul_res),64);
        bufp->chgBit(oldp+10,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__div_flag));
        bufp->chgBit(oldp+11,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__divu_flag));
        bufp->chgCData(oldp+12,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__effective_op),5);
        bufp->chgBit(oldp+13,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__multi_start));
        bufp->chgBit(oldp+14,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__start_rise));
        bufp->chgBit(oldp+15,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__start_rise));
        bufp->chgQData(oldp+16,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.__PVT__hi_sum),34);
        bufp->chgBit(oldp+18,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.__PVT__start_rise));
        bufp->chgQData(oldp+19,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.__PVT__hi_sum),35);
        bufp->chgBit(oldp+21,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.__PVT__start_rise));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity[3U])))) {
        bufp->chgCData(oldp+22,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__npc_op),2);
        bufp->chgCData(oldp+23,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__sext_op),3);
        bufp->chgCData(oldp+24,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__alu_op),5);
        bufp->chgBit(oldp+25,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI) 
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
        bufp->chgCData(oldp+26,(((2U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LB)))) 
                                 | ((3U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LBU)))) 
                                    | ((4U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LH)))) 
                                       | ((5U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LHU)))) 
                                          | (1U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LW))))))))),3);
        bufp->chgCData(oldp+27,((0x0000000fU & ((1U 
                                                 & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SB)))) 
                                                | ((3U 
                                                    & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SH)))) 
                                                   | (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SW))))))),4);
        bufp->chgBit(oldp+28,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__is_mul));
        bufp->chgBit(oldp+29,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__is_div));
        bufp->chgIData(oldp+30,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_SEXT__DOT__ext),32);
        bufp->chgIData(oldp+31,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_br_target),32);
        bufp->chgBit(oldp+32,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__load_use_stall));
        bufp->chgBit(oldp+33,((3U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__npc_op))));
        bufp->chgBit(oldp+34,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_mul_div));
        bufp->chgBit(oldp+35,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mul_div_stall));
        bufp->chgBit(oldp+36,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mul_div_release));
        bufp->chgCData(oldp+37,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_FWD__DOT__forward_a),2);
        bufp->chgBit(oldp+38,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI));
        bufp->chgBit(oldp+39,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SUB));
        bufp->chgBit(oldp+40,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XORI));
        bufp->chgBit(oldp+41,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ANDI));
        bufp->chgBit(oldp+42,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR));
        bufp->chgBit(oldp+43,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI));
        bufp->chgBit(oldp+44,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU));
        bufp->chgBit(oldp+45,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT));
        bufp->chgBit(oldp+46,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU));
        bufp->chgBit(oldp+47,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BLT));
        bufp->chgBit(oldp+48,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BGE));
        bufp->chgBit(oldp+49,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BLTU));
        bufp->chgBit(oldp+50,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BGEU));
        bufp->chgBit(oldp+51,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__JALR));
        bufp->chgBit(oldp+52,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LB));
        bufp->chgBit(oldp+53,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LBU));
        bufp->chgBit(oldp+54,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LH));
        bufp->chgBit(oldp+55,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LHU));
        bufp->chgBit(oldp+56,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SB));
        bufp->chgBit(oldp+57,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SH));
        bufp->chgBit(oldp+58,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SW));
        bufp->chgBit(oldp+59,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MUL));
        bufp->chgBit(oldp+60,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MULH));
        bufp->chgBit(oldp+61,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MULHU));
        bufp->chgBit(oldp+62,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__DIV));
        bufp->chgBit(oldp+63,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__DIVU));
        bufp->chgBit(oldp+64,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__REM));
        bufp->chgBit(oldp+65,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__REMU));
        bufp->chgBit(oldp+66,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI));
        bufp->chgBit(oldp+67,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI));
        bufp->chgBit(oldp+68,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI));
        bufp->chgBit(oldp+69,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI));
        bufp->chgBit(oldp+70,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLL));
        bufp->chgBit(oldp+71,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL));
        bufp->chgBit(oldp+72,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA));
        bufp->chgBit(oldp+73,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LW));
        bufp->chgBit(oldp+74,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BEQ));
        bufp->chgBit(oldp+75,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BNE));
        bufp->chgBit(oldp+76,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__NPC_OP_BRA));
        bufp->chgBit(oldp+77,((1U & (~ ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__NPC_OP_BRA) 
                                        | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_PC4))))));
        bufp->chgBit(oldp+78,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_RAM));
        bufp->chgBit(oldp+79,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_PC4));
        bufp->chgBit(oldp+80,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__JALR) 
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
        bufp->chgBit(oldp+81,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__EXT_OP_S));
        bufp->chgBit(oldp+82,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI) 
                               | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR))));
        bufp->chgBit(oldp+83,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ALU_OP_XOR));
        bufp->chgBit(oldp+84,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ALU_OP_AND));
        bufp->chgBit(oldp+85,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI) 
                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BLT) 
                                  | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT)))));
        bufp->chgBit(oldp+86,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU) 
                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BLTU) 
                                  | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU)))));
        bufp->chgBit(oldp+87,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLL) 
                               | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI))));
        bufp->chgBit(oldp+88,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL) 
                               | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI))));
        bufp->chgBit(oldp+89,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA) 
                               | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI))));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity[4U])))) {
        bufp->chgBit(oldp+90,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__load_stall_active));
        bufp->chgBit(oldp+91,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__effective_flush));
        bufp->chgIData(oldp+92,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pc_next),32);
        bufp->chgIData(oldp+93,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__a),32);
        bufp->chgBit(oldp+94,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__br));
        bufp->chgIData(oldp+95,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__wb_forward_data),32);
        bufp->chgIData(oldp+96,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__wD),32);
        bufp->chgIData(oldp+97,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__c),32);
        bufp->chgIData(oldp+98,(((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__a 
                                  >> 0x0000001fU) ? 
                                 ((IData)(1U) + (~ vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__a))
                                  : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__a)),32);
        bufp->chgQData(oldp+99,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__a))),33);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+101,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_wresp));
        bufp->chgBit(oldp+102,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__flush_next));
        bufp->chgBit(oldp+103,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__load_resync2));
        bufp->chgBit(oldp+104,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__stall_synced));
        bufp->chgIData(oldp+105,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rd1),32);
        bufp->chgIData(oldp+106,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_br_target),32);
        bufp->chgBit(oldp+107,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_alua_sel));
        bufp->chgBit(oldp+108,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_is_mul));
        bufp->chgBit(oldp+109,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_is_div));
        bufp->chgCData(oldp+110,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_npc_op),2);
        bufp->chgBit(oldp+111,((1U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_npc_op))));
        bufp->chgBit(oldp+112,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mul_div_flush));
        bufp->chgBit(oldp+113,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mul_div_entering));
        bufp->chgBit(oldp+114,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mul_div_stall_d));
        bufp->chgIData(oldp+115,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_pc),32);
        bufp->chgIData(oldp+116,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rd2),32);
        bufp->chgIData(oldp+117,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ext),32);
        bufp->chgBit(oldp+118,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_br));
        bufp->chgCData(oldp+119,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_wop),4);
        bufp->chgBit(oldp+120,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_is_mul));
        bufp->chgBit(oldp+121,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_is_div));
        bufp->chgIData(oldp+122,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_alu_c),32);
        bufp->chgCData(oldp+123,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_ram_rop),3);
        bufp->chgCData(oldp+124,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_byte_offs),2);
        bufp->chgIData(oldp+125,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__last_wb_pc),32);
        bufp->chgIData(oldp+126,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__quotient),32);
        bufp->chgIData(oldp+127,((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__quotient)),32);
        bufp->chgIData(oldp+128,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__remainder),32);
        bufp->chgIData(oldp+129,((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__remainder)),32);
        bufp->chgBit(oldp+130,((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__count))));
        bufp->chgBit(oldp+131,((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__count))));
        bufp->chgIData(oldp+132,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__divisor),32);
        bufp->chgCData(oldp+133,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__count),6);
        bufp->chgBit(oldp+134,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__start_d));
        bufp->chgIData(oldp+135,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__shifted_rem),32);
        bufp->chgQData(oldp+136,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__diff),33);
        bufp->chgBit(oldp+138,((1U & (~ (IData)((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__diff 
                                                 >> 0x00000020U))))));
        bufp->chgIData(oldp+139,(((1U & (IData)((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__diff 
                                                 >> 0x00000020U)))
                                   ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__shifted_rem
                                   : (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__diff))),32);
        bufp->chgIData(oldp+140,(((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__quotient 
                                   << 1U) | (1U & (~ (IData)(
                                                             (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_div__DOT__diff 
                                                              >> 0x00000020U)))))),32);
        bufp->chgQData(oldp+141,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__quotient),33);
        bufp->chgQData(oldp+143,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__remainder),33);
        bufp->chgQData(oldp+145,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__divisor),33);
        bufp->chgCData(oldp+147,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__count),6);
        bufp->chgBit(oldp+148,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__start_d));
        bufp->chgQData(oldp+149,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__shifted_rem),33);
        bufp->chgQData(oldp+151,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__diff),34);
        bufp->chgBit(oldp+153,((1U & (~ (IData)((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__diff 
                                                 >> 0x00000021U))))));
        bufp->chgQData(oldp+154,((0x00000001ffffffffULL 
                                  & ((1U & (IData)(
                                                   (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__diff 
                                                    >> 0x00000021U)))
                                      ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__shifted_rem
                                      : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__diff))),33);
        bufp->chgQData(oldp+156,((((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__quotient)) 
                                   << 1U) | (QData)((IData)(
                                                            (1U 
                                                             & (~ (IData)(
                                                                          (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.__PVT__U_divu__DOT__diff 
                                                                           >> 0x00000021U)))))))),33);
        bufp->chgBit(oldp+158,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.__PVT__start_d));
        bufp->chgBit(oldp+159,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.__PVT__start_d));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgCData(oldp+160,((0x0000000fU & (- (IData)(
                                                           (0U 
                                                            != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop)))))),4);
        bufp->chgIData(oldp+161,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c),32);
        bufp->chgBit(oldp+162,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_valid));
        bufp->chgCData(oldp+163,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_da_wen),4);
        bufp->chgIData(oldp+164,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_da_wdata),32);
        bufp->chgSData(oldp+165,((0x0000ffffU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c 
                                                 >> 2U))),16);
        bufp->chgIData(oldp+166,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rd2),32);
        bufp->chgBit(oldp+167,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rf_we));
        bufp->chgCData(oldp+168,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rf_wsel),2);
        bufp->chgCData(oldp+169,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_ram_rop),3);
        bufp->chgCData(oldp+170,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_ram_wop),4);
        bufp->chgCData(oldp+171,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rd),5);
        bufp->chgIData(oldp+172,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_fwd_data),32);
        bufp->chgBit(oldp+173,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rf_we));
        bufp->chgCData(oldp+174,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rf_wsel),2);
        bufp->chgCData(oldp+175,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop),3);
        bufp->chgCData(oldp+176,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rd),5);
        bufp->chgCData(oldp+177,((3U & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c)),2);
    }
    bufp->chgBit(oldp+178,(vlSelfRef.fpga_clk));
    bufp->chgBit(oldp+179,(vlSelfRef.fpga_rst));
    bufp->chgSData(oldp+180,(vlSelfRef.sw),16);
    bufp->chgBit(oldp+181,(vlSelfRef.rx));
    bufp->chgBit(oldp+182,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_req));
    bufp->chgIData(oldp+183,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_addr),32);
    bufp->chgBit(oldp+184,(((~ (IData)(vlSelfRef.fpga_rst)) 
                            & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_req))));
    bufp->chgIData(oldp+185,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__douta),32);
    bufp->chgIData(oldp+186,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_rdata),32);
    bufp->chgBit(oldp+187,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_valid));
    bufp->chgIData(oldp+188,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.pc),32);
    bufp->chgIData(oldp+189,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.fetch_pc),32);
    bufp->chgIData(oldp+190,(((IData)(4U) + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.pc)),32);
    bufp->chgBit(oldp+191,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.flush_next2));
    bufp->chgBit(oldp+192,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.load_resync));
    bufp->chgIData(oldp+193,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_pc),32);
    bufp->chgIData(oldp+194,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst),32);
    bufp->chgCData(oldp+195,((3U & ((1U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_RAM)))) 
                                    | ((2U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_PC4)))) 
                                       | (- (IData)(
                                                    (0x37U 
                                                     == 
                                                     (0x0000007fU 
                                                      & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst)))))))),2);
    bufp->chgBit(oldp+196,((0x17U == (0x0000007fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst))));
    bufp->chgBit(oldp+197,(((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI) 
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
    bufp->chgCData(oldp+198,((0x0000001fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                             >> 0x0000000fU))),5);
    bufp->chgCData(oldp+199,((0x0000001fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                             >> 0x00000014U))),5);
    bufp->chgCData(oldp+200,((0x0000001fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                             >> 7U))),5);
    bufp->chgIData(oldp+201,((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs
                              [(0x0000001fU & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                >> 0x0000000fU) 
                                               - (IData)(1U)))] 
                              & (- (IData)(((0x1eU 
                                             >= (0x0000001fU 
                                                 & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                     >> 0x0000000fU) 
                                                    - (IData)(1U)))) 
                                            & (0U != 
                                               (0x0000001fU 
                                                & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                   >> 0x0000000fU)))))))),32);
    bufp->chgIData(oldp+202,((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs
                              [(0x0000001fU & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                >> 0x00000014U) 
                                               - (IData)(1U)))] 
                              & (- (IData)(((0x1eU 
                                             >= (0x0000001fU 
                                                 & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                     >> 0x00000014U) 
                                                    - (IData)(1U)))) 
                                            & (0U != 
                                               (0x0000001fU 
                                                & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                                   >> 0x00000014U)))))))),32);
    bufp->chgIData(oldp+203,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_pc),32);
    bufp->chgIData(oldp+204,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_ext),32);
    bufp->chgCData(oldp+205,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_alu_op),5);
    bufp->chgBit(oldp+206,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_alub_sel));
    bufp->chgCData(oldp+207,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_rs1),5);
    bufp->chgCData(oldp+208,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_rs2),5);
    bufp->chgBit(oldp+209,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_br_taken));
    bufp->chgIData(oldp+210,((0xfffffffeU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_c)),32);
    bufp->chgBit(oldp+211,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.flush_f));
    bufp->chgBit(oldp+212,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.flush_d));
    bufp->chgBit(oldp+213,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.stall_f));
    bufp->chgBit(oldp+214,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.stall_d));
    bufp->chgCData(oldp+215,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.forward_b),2);
    bufp->chgIData(oldp+216,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_7) 
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
    bufp->chgIData(oldp+217,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_8) 
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
    bufp->chgIData(oldp+218,(((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rd) 
                                == (0x0000001fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
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
    bufp->chgIData(oldp+219,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_alua_sel)
                               ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_pc
                               : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rd1)),32);
    bufp->chgIData(oldp+220,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_alub_sel)
                               ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_ext
                               : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rd2)),32);
    bufp->chgIData(oldp+221,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b),32);
    bufp->chgIData(oldp+222,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_c),32);
    bufp->chgIData(oldp+223,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_pc),32);
    bufp->chgIData(oldp+224,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_ext),32);
    bufp->chgBit(oldp+225,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rf_we));
    bufp->chgCData(oldp+226,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rf_wsel),2);
    bufp->chgCData(oldp+227,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rd),5);
    bufp->chgIData(oldp+228,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEXT__DOT__ext),32);
    bufp->chgBit(oldp+229,((1U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rf_wsel))));
    bufp->chgBit(oldp+230,(((1U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rf_wsel))
                             ? ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_valid) 
                                & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rf_we))
                             : (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rf_we))));
    bufp->chgIData(oldp+231,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_pc),32);
    bufp->chgBit(oldp+232,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_we));
    bufp->chgCData(oldp+233,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_wR),5);
    bufp->chgIData(oldp+234,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_wD),32);
    bufp->chgIData(oldp+235,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_pc),32);
    bufp->chgCData(oldp+236,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_we),4);
    bufp->chgIData(oldp+237,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_waddr),32);
    bufp->chgIData(oldp+238,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_wdata),32);
    bufp->chgIData(oldp+239,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__store_data_r),32);
    bufp->chgBit(oldp+240,((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_pc 
                            != vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__last_wb_pc)));
    bufp->chgCData(oldp+241,((0x0000007fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst)),7);
    bufp->chgCData(oldp+242,((7U & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                    >> 0x0000000cU))),3);
    bufp->chgCData(oldp+243,((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                              >> 0x00000019U)),7);
    bufp->chgBit(oldp+244,(((0U == (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                    >> 0x00000019U)) 
                            & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_3))));
    bufp->chgBit(oldp+245,(((0U == (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                    >> 0x00000019U)) 
                            & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_14))));
    bufp->chgBit(oldp+246,(((0U == (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                    >> 0x00000019U)) 
                            & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_15))));
    bufp->chgBit(oldp+247,((0x37U == (0x0000007fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst))));
    bufp->chgBit(oldp+248,((0x6fU == (0x0000007fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst))));
    bufp->chgBit(oldp+249,(((0x17U == (0x0000007fU 
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
    bufp->chgBit(oldp+250,(((0x17U == (0x0000007fU 
                                       & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst)) 
                            | (0x37U == (0x0000007fU 
                                         & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst)))));
    bufp->chgBit(oldp+251,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI) 
                             | ((0U == (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                                        >> 0x00000019U)) 
                                & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_3))) 
                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_RAM) 
                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__EXT_OP_S) 
                                  | ((0x17U == (0x0000007fU 
                                                & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst)) 
                                     | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__JALR)))))));
    bufp->chgBit(oldp+252,((((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI) 
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
    bufp->chgBit(oldp+253,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__NPC_OP_BRA) 
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
    bufp->chgBit(oldp+254,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_0) 
                            & ((~ (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_alua_sel)) 
                               & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_rs1) 
                                  == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rd))))));
    bufp->chgBit(oldp+255,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_1) 
                            & ((~ (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_alua_sel)) 
                               & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_rs1) 
                                  == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rd))))));
    bufp->chgBit(oldp+256,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_0) 
                            & ((~ (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_alub_sel)) 
                               & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_rs2) 
                                  == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rd))))));
    bufp->chgBit(oldp+257,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6e95ff9d_0_1) 
                            & ((~ (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_alub_sel)) 
                               & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.id_ex_rs2) 
                                  == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.mem_wb_rd))))));
    bufp->chgIData(oldp+258,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEXT__DOT__aligned),32);
    VminiRV_SoC___024root__trace_chg_dtype____0(vlSelf, bufp, 259, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs);
    bufp->chgIData(oldp+290,((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.if_id_inst 
                              >> 7U)),25);
    bufp->chgCData(oldp+291,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.op),5);
    bufp->chgBit(oldp+292,((0x12U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.op))));
    bufp->chgQData(oldp+293,((((QData)((IData)((0x7fffffffU 
                                                & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_hi)))) 
                               << 0x00000021U) | vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_lo)),64);
    bufp->chgBit(oldp+295,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.mul_busy));
    bufp->chgBit(oldp+296,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.busy));
    bufp->chgCData(oldp+297,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.op_r),5);
    bufp->chgIData(oldp+298,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.a_latched),32);
    bufp->chgIData(oldp+299,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.b_latched),32);
    bufp->chgBit(oldp+300,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU.multi_active));
    bufp->chgIData(oldp+301,(((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b 
                               >> 0x0000001fU) ? ((IData)(1U) 
                                                  + 
                                                  (~ vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b))
                               : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b)),32);
    bufp->chgQData(oldp+302,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ex_alu_b))),33);
    bufp->chgBit(oldp+304,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.clka));
    bufp->chgSData(oldp+305,((0x0000ffffU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_addr 
                                             >> 2U))),16);
    bufp->chgBit(oldp+306,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.start));
    bufp->chgBit(oldp+307,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.busy));
    bufp->chgQData(oldp+308,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.product_hi),33);
    bufp->chgIData(oldp+310,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.product_lo),32);
    bufp->chgIData(oldp+311,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.multiplicand),32);
    bufp->chgCData(oldp+312,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.count),6);
    bufp->chgQData(oldp+313,((0x00000001ffffffffULL 
                              & ((1U & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.product_lo)
                                  ? (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.__PVT__hi_sum 
                                     >> 1U) : (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.product_hi 
                                               >> 1U)))),33);
    bufp->chgIData(oldp+315,(((((1U & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.product_lo)
                                 ? (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.__PVT__hi_sum)
                                 : (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.product_hi)) 
                               << 0x0000001fU) | (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul.product_lo 
                                                  >> 1U))),32);
    bufp->chgBit(oldp+316,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.start));
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
    bufp->chgWData(oldp+317,(__Vtemp_1),66);
    bufp->chgQData(oldp+320,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_hi),34);
    bufp->chgQData(oldp+322,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_lo),33);
    bufp->chgQData(oldp+324,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.multiplicand),33);
    bufp->chgCData(oldp+326,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.count),6);
    bufp->chgQData(oldp+327,((0x00000003ffffffffULL 
                              & ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_lo))
                                  ? (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.__PVT__hi_sum 
                                     >> 1U) : (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_hi 
                                               >> 1U)))),34);
    bufp->chgQData(oldp+329,((((QData)((IData)((1U 
                                                & ((1U 
                                                    & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_lo))
                                                    ? (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.__PVT__hi_sum)
                                                    : (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_hi))))) 
                               << 0x00000020U) | (QData)((IData)(
                                                                 (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu.product_lo 
                                                                  >> 1U))))),33);
}

void VminiRV_SoC___024root__trace_chg_dtype____0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 31>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_chg_dtype____0\n"); );
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+8,(__VdtypeVar[8]),32);
    bufp->chgIData(oldp+9,(__VdtypeVar[9]),32);
    bufp->chgIData(oldp+10,(__VdtypeVar[10]),32);
    bufp->chgIData(oldp+11,(__VdtypeVar[11]),32);
    bufp->chgIData(oldp+12,(__VdtypeVar[12]),32);
    bufp->chgIData(oldp+13,(__VdtypeVar[13]),32);
    bufp->chgIData(oldp+14,(__VdtypeVar[14]),32);
    bufp->chgIData(oldp+15,(__VdtypeVar[15]),32);
    bufp->chgIData(oldp+16,(__VdtypeVar[16]),32);
    bufp->chgIData(oldp+17,(__VdtypeVar[17]),32);
    bufp->chgIData(oldp+18,(__VdtypeVar[18]),32);
    bufp->chgIData(oldp+19,(__VdtypeVar[19]),32);
    bufp->chgIData(oldp+20,(__VdtypeVar[20]),32);
    bufp->chgIData(oldp+21,(__VdtypeVar[21]),32);
    bufp->chgIData(oldp+22,(__VdtypeVar[22]),32);
    bufp->chgIData(oldp+23,(__VdtypeVar[23]),32);
    bufp->chgIData(oldp+24,(__VdtypeVar[24]),32);
    bufp->chgIData(oldp+25,(__VdtypeVar[25]),32);
    bufp->chgIData(oldp+26,(__VdtypeVar[26]),32);
    bufp->chgIData(oldp+27,(__VdtypeVar[27]),32);
    bufp->chgIData(oldp+28,(__VdtypeVar[28]),32);
    bufp->chgIData(oldp+29,(__VdtypeVar[29]),32);
    bufp->chgIData(oldp+30,(__VdtypeVar[30]),32);
}

void VminiRV_SoC___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_cleanup\n"); );
    // Body
    VminiRV_SoC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VminiRV_SoC___024root*>(voidSelf);
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}
