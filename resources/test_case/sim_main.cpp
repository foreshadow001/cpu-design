#include "VminiRV_SoC.h"
#include "VminiRV_SoC_miniRV_SoC.h"
#include "VminiRV_SoC_cpu_top.h"
#include "VminiRV_SoC_cpu_core.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <stdio.h>
#include <stdlib.h>

VminiRV_SoC *top;
VerilatedVcdC *tfp;
vluint64_t sim_time = 0;

void tick() {
    top->fpga_clk = 0; top->eval();
    top->fpga_clk = 1; top->eval();
    top->fpga_clk = 0; top->eval();
}

void reset(int cycles) {
    top->fpga_rst = 1;
    for (int i = 0; i < cycles; i++) tick();
    top->fpga_rst = 0;
    printf("[TEST] Reset done\n");
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    top = new VminiRV_SoC;
    Verilated::traceEverOn(true);
    tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("dump.vcd");
    reset(20);

    int wb_count = 0;
    for (int cycle = 0; cycle < 800; cycle++) {
        tick();
        auto *core = top->miniRV_SoC->U_cpu->U_core;

        int mb_pc   = core->mem_wb_pc;
        int mb_we   = core->mem_wb_rf_we;
        int mb_rd   = core->mem_wb_rd;
        int mb_ext  = core->mem_wb_ext;
        int mb_wsel = core->mem_wb_rf_wsel;
        int wb_we   = core->debug_wb_rf_we;
        int wb_pc   = core->debug_wb_pc;
        int wb_wR   = core->debug_wb_rf_wR;
        int wb_wD   = core->debug_wb_rf_wD;
        int id_ex_pc_val = core->id_ex_pc;
        int id_ex_ext_val = core->id_ex_ext;
        int pc_val  = core->pc;
        int ex_br_taken_val = core->ex_br_taken;
        int flush_f_val = core->flush_f;
        int flush_d_val = core->flush_d;
        int id_ex_alu_op_val = core->id_ex_alu_op;
        int ex_alu_c_val = core->ex_alu_c;
        int ex_alu_b_val = core->ex_alu_b;
        int id_ex_rs2_val = core->id_ex_rs2;
        int fwd_b_val = core->forward_b;
        int id_ex_rs1_val = core->id_ex_rs1;
        int id_ex_alub_sel_val = core->id_ex_alub_sel;

        // Show all cycles around REM stall (0x00-0x30)
        int show = (id_ex_pc_val <= 0x030)
                || mb_we || wb_we;

        // Track last_wb_pc for dedup detection
        static int last_mem_wb_pc = -1;
        int mem_wb_pc_val = core->mem_wb_pc;
        int mem_wb_we_val = core->mem_wb_rf_we;
        int mem_wb_rd_val = core->mem_wb_rd;

        if (show || cycle < 30) {
            printf("CYC%3d | id_ex=0x%04x op=%d c=0x%08x b=0x%08x fwd_b=%d sel=%d ext=0x%08x | mb:pc=0x%04x we=%d rd=%d | wb:pc=0x%04x we=%d wR=%d wD=0x%08x chg=%d | if_id=0x%04x fp=0x%04x sF=%d sD=%d\n",
                   cycle, id_ex_pc_val, id_ex_alu_op_val, ex_alu_c_val, ex_alu_b_val,
                   fwd_b_val, id_ex_alub_sel_val, id_ex_ext_val,
                   mem_wb_pc_val, mem_wb_we_val, mem_wb_rd_val,
                   wb_pc, wb_we, wb_wR, wb_wD,
                   (mem_wb_pc_val != last_mem_wb_pc),
                   core->if_id_pc, core->fetch_pc,
                   core->stall_f, core->stall_d);
            last_mem_wb_pc = mem_wb_pc_val;
        }

        if (wb_we) {
            printf(">>> VALID WB #%d: cycle=%d pc=0x%04x wR=%d wD=0x%08x\n",
                   wb_count++, cycle, wb_pc, wb_wR, wb_wD);
        }

        if (wb_count >= 200) break;
    }
    printf("[TEST] Done. %d valid WB events.\n", wb_count);
    tfp->close();
    delete top;
    return 0;
}
