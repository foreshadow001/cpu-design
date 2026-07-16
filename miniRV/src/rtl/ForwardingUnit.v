`timescale 1ns / 1ps

module ForwardingUnit (
    input  wire [ 4:0] id_ex_rs1,
    input  wire [ 4:0] id_ex_rs2,
    input  wire        id_ex_alua_sel,
    input  wire        id_ex_alub_sel,
    input  wire [ 4:0] id_ex_rd,
    input  wire        id_ex_rf_we,
    input  wire [ 4:0] ex_mem_rd,
    input  wire        ex_mem_rf_we,
    input  wire [ 4:0] mem_wb_rd,
    input  wire        mem_wb_rf_we,

    output wire [ 1:0] forward_a,
    output wire [ 1:0] forward_b
);

    // ForwardA: select alu_a source (only when alua_sel uses rs1)
    assign forward_a = (id_ex_alua_sel == 1'b0) ? 2'b00 :
                       (ex_mem_rf_we && (ex_mem_rd != 5'h0) && (ex_mem_rd == id_ex_rs1)) ? 2'b01 :
                       (mem_wb_rf_we && (mem_wb_rd != 5'h0) && (mem_wb_rd == id_ex_rs1)) ? 2'b10 :
                       2'b00;

    // ForwardB: select alu_b source (only when alub_sel uses rs2)
    assign forward_b = (id_ex_alub_sel == 1'b0) ? 2'b00 :
                       (ex_mem_rf_we && (ex_mem_rd != 5'h0) && (ex_mem_rd == id_ex_rs2)) ? 2'b01 :
                       (mem_wb_rf_we && (mem_wb_rd != 5'h0) && (mem_wb_rd == id_ex_rs2)) ? 2'b10 :
                       2'b00;

endmodule
