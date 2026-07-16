// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VminiRV_SoC.h for the primary calling header

#ifndef VERILATED_VMINIRV_SOC_CPU_CORE_H_
#define VERILATED_VMINIRV_SOC_CPU_CORE_H_  // guard

#include "verilated.h"
class VminiRV_SoC_ALU;


class VminiRV_SoC__Syms;

class alignas(VL_CACHE_LINE_BYTES) VminiRV_SoC_cpu_core final {
  public:
    // CELLS
    VminiRV_SoC_ALU* U_ALU;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ __PVT__cpu_rst;
        CData/*0:0*/ __PVT__cpu_clk;
        CData/*0:0*/ ifetch_req;
        CData/*0:0*/ ifetch_valid;
        CData/*3:0*/ __PVT__daccess_ren;
        CData/*0:0*/ __PVT__daccess_rvalid;
        CData/*3:0*/ __PVT__daccess_wen;
        CData/*0:0*/ __PVT__daccess_wresp;
        CData/*0:0*/ __PVT__flush_next;
        CData/*0:0*/ flush_next2;
        CData/*0:0*/ load_resync;
        CData/*0:0*/ __PVT__load_resync2;
        CData/*0:0*/ __PVT__load_stall_active;
        CData/*0:0*/ __PVT__stall_synced;
        CData/*0:0*/ __PVT__effective_flush;
        CData/*4:0*/ id_ex_alu_op;
        CData/*0:0*/ __PVT__id_ex_alua_sel;
        CData/*0:0*/ id_ex_alub_sel;
        CData/*0:0*/ __PVT__id_ex_rf_we;
        CData/*1:0*/ __PVT__id_ex_rf_wsel;
        CData/*2:0*/ __PVT__id_ex_ram_rop;
        CData/*3:0*/ __PVT__id_ex_ram_wop;
        CData/*0:0*/ __PVT__id_ex_is_mul;
        CData/*0:0*/ __PVT__id_ex_is_div;
        CData/*4:0*/ id_ex_rs1;
        CData/*4:0*/ id_ex_rs2;
        CData/*4:0*/ __PVT__id_ex_rd;
        CData/*1:0*/ __PVT__id_ex_npc_op;
        CData/*0:0*/ __PVT__load_use_stall;
        CData/*0:0*/ ex_br_taken;
        CData/*0:0*/ __PVT__mul_div_flush;
        CData/*0:0*/ flush_f;
        CData/*0:0*/ flush_d;
        CData/*0:0*/ __PVT__mul_div_entering;
        CData/*0:0*/ __PVT__id_mul_div;
        CData/*0:0*/ __PVT__mul_div_stall;
        CData/*0:0*/ __PVT__mul_div_stall_d;
        CData/*0:0*/ __PVT__mul_div_release;
        CData/*0:0*/ stall_f;
        CData/*0:0*/ stall_d;
        CData/*1:0*/ forward_b;
        CData/*0:0*/ __PVT__ex_mem_br;
        CData/*0:0*/ __PVT__ex_mem_rf_we;
        CData/*1:0*/ __PVT__ex_mem_rf_wsel;
        CData/*2:0*/ __PVT__ex_mem_ram_rop;
        CData/*3:0*/ __PVT__ex_mem_ram_wop;
        CData/*4:0*/ __PVT__ex_mem_rd;
        CData/*0:0*/ __PVT__ex_mem_is_mul;
        CData/*0:0*/ __PVT__ex_mem_is_div;
        CData/*3:0*/ __PVT__mem_da_wen;
        CData/*0:0*/ mem_wb_rf_we;
        CData/*1:0*/ mem_wb_rf_wsel;
        CData/*4:0*/ mem_wb_rd;
        CData/*2:0*/ __PVT__mem_wb_ram_rop;
        CData/*1:0*/ __PVT__mem_wb_byte_offs;
        CData/*0:0*/ debug_wb_rf_we;
        CData/*4:0*/ debug_wb_rf_wR;
        CData/*3:0*/ debug_mem_we;
        CData/*1:0*/ __PVT__U_FWD__DOT__forward_a;
        CData/*1:0*/ __PVT__U_CU__DOT__npc_op;
        CData/*2:0*/ __PVT__U_CU__DOT__sext_op;
        CData/*4:0*/ __PVT__U_CU__DOT__alu_op;
        CData/*0:0*/ __PVT__U_CU__DOT__is_mul;
        CData/*0:0*/ __PVT__U_CU__DOT__is_div;
    };
    struct {
        CData/*0:0*/ __PVT__U_CU__DOT__ADDI;
        CData/*0:0*/ __PVT__U_CU__DOT__SUB;
        CData/*0:0*/ __PVT__U_CU__DOT__XORI;
        CData/*0:0*/ __PVT__U_CU__DOT__ANDI;
        CData/*0:0*/ __PVT__U_CU__DOT__OR;
        CData/*0:0*/ __PVT__U_CU__DOT__SLTI;
        CData/*0:0*/ __PVT__U_CU__DOT__SLTIU;
        CData/*0:0*/ __PVT__U_CU__DOT__SLT;
        CData/*0:0*/ __PVT__U_CU__DOT__SLTU;
        CData/*0:0*/ __PVT__U_CU__DOT__BLT;
        CData/*0:0*/ __PVT__U_CU__DOT__BGE;
        CData/*0:0*/ __PVT__U_CU__DOT__BLTU;
        CData/*0:0*/ __PVT__U_CU__DOT__BGEU;
        CData/*0:0*/ __PVT__U_CU__DOT__JALR;
        CData/*0:0*/ __PVT__U_CU__DOT__LB;
        CData/*0:0*/ __PVT__U_CU__DOT__LBU;
        CData/*0:0*/ __PVT__U_CU__DOT__LH;
        CData/*0:0*/ __PVT__U_CU__DOT__LHU;
        CData/*0:0*/ __PVT__U_CU__DOT__SB;
        CData/*0:0*/ __PVT__U_CU__DOT__SH;
        CData/*0:0*/ __PVT__U_CU__DOT__SW;
        CData/*0:0*/ __PVT__U_CU__DOT__MUL;
        CData/*0:0*/ __PVT__U_CU__DOT__MULH;
        CData/*0:0*/ __PVT__U_CU__DOT__MULHU;
        CData/*0:0*/ __PVT__U_CU__DOT__DIV;
        CData/*0:0*/ __PVT__U_CU__DOT__DIVU;
        CData/*0:0*/ __PVT__U_CU__DOT__REM;
        CData/*0:0*/ __PVT__U_CU__DOT__REMU;
        CData/*0:0*/ __PVT__U_CU__DOT__ORI;
        CData/*0:0*/ __PVT__U_CU__DOT__SLLI;
        CData/*0:0*/ __PVT__U_CU__DOT__SRLI;
        CData/*0:0*/ __PVT__U_CU__DOT__SRAI;
        CData/*0:0*/ __PVT__U_CU__DOT__SLL;
        CData/*0:0*/ __PVT__U_CU__DOT__SRL;
        CData/*0:0*/ __PVT__U_CU__DOT__SRA;
        CData/*0:0*/ __PVT__U_CU__DOT__LW;
        CData/*0:0*/ __PVT__U_CU__DOT__BEQ;
        CData/*0:0*/ __PVT__U_CU__DOT__BNE;
        CData/*0:0*/ __PVT__U_CU__DOT__NPC_OP_BRA;
        CData/*0:0*/ __PVT__U_CU__DOT__WB_OP_RAM;
        CData/*0:0*/ __PVT__U_CU__DOT__WB_OP_PC4;
        CData/*0:0*/ __PVT__U_CU__DOT__EXT_OP_S;
        CData/*0:0*/ __PVT__U_CU__DOT__ALU_OP_XOR;
        CData/*0:0*/ __PVT__U_CU__DOT__ALU_OP_AND;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_0;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_1;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_3;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_6;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_7;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_8;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_14;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_15;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_22;
        CData/*4:0*/ __VdlyDim0__U_RF__DOT__regs__v0;
        CData/*0:0*/ __VdlySet__U_RF__DOT__regs__v0;
        IData/*31:0*/ ifetch_addr;
        IData/*31:0*/ __PVT__ifetch_inst;
        IData/*31:0*/ __PVT__daccess_addr;
        IData/*31:0*/ __PVT__daccess_rdata;
        IData/*31:0*/ __PVT__daccess_wdata;
        IData/*31:0*/ pc;
        IData/*31:0*/ fetch_pc;
        IData/*31:0*/ if_id_pc;
        IData/*31:0*/ if_id_inst;
    };
    struct {
        IData/*31:0*/ __PVT__id_br_target;
        IData/*31:0*/ id_ex_pc;
        IData/*31:0*/ __PVT__id_ex_rd1;
        IData/*31:0*/ __PVT__id_ex_rd2;
        IData/*31:0*/ id_ex_ext;
        IData/*31:0*/ __PVT__id_ex_br_target;
        IData/*31:0*/ __PVT__pc_next;
        IData/*31:0*/ __PVT__ex_mem_fwd_data;
        IData/*31:0*/ ex_alu_b;
        IData/*31:0*/ ex_alu_c;
        IData/*31:0*/ __PVT__ex_mem_pc;
        IData/*31:0*/ __PVT__ex_mem_alu_c;
        IData/*31:0*/ __PVT__ex_mem_rd2;
        IData/*31:0*/ __PVT__ex_mem_ext;
        IData/*31:0*/ __PVT__mem_da_wdata;
        IData/*31:0*/ mem_wb_pc;
        IData/*31:0*/ __PVT__mem_wb_alu_c;
        IData/*31:0*/ mem_wb_ext;
        IData/*31:0*/ __PVT__wb_forward_data;
        IData/*31:0*/ debug_wb_pc;
        IData/*31:0*/ debug_wb_rf_wD;
        IData/*31:0*/ debug_mem_pc;
        IData/*31:0*/ debug_mem_waddr;
        IData/*31:0*/ debug_mem_wdata;
        IData/*31:0*/ __PVT__store_data_r;
        IData/*31:0*/ __PVT__last_wb_pc;
        IData/*31:0*/ __PVT__U_MEXT__DOT__ext;
        IData/*31:0*/ __PVT__U_MEXT__DOT__aligned;
        IData/*31:0*/ __PVT__U_SEXT__DOT__ext;
        IData/*31:0*/ __PVT__U_RF__DOT__wD;
        IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_9;
        IData/*31:0*/ __VdlyVal__U_RF__DOT__regs__v0;
        VlUnpacked<IData/*31:0*/, 31> __PVT__U_RF__DOT__regs;
    };

    // INTERNAL VARIABLES
    VminiRV_SoC__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VminiRV_SoC_cpu_core();
    ~VminiRV_SoC_cpu_core();
    void ctor(VminiRV_SoC__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(VminiRV_SoC_cpu_core);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
