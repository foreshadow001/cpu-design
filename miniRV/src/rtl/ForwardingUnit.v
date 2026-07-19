`timescale 1ns / 1ps

module ForwardingUnit (
    input  wire [ 4:0] id_ex_rs1,
    input  wire [ 4:0] id_ex_rs2,
    input  wire        id_ex_alua_sel,  // 0=RS1, 1=PC (AUIPC)
    input  wire        id_ex_alub_sel,  // 0=RS2, 1=EXT (immediate)
    input  wire [ 4:0] id_ex_rd,
    input  wire        id_ex_rf_we,
    input  wire [ 4:0] ex_mem_rd,
    input  wire        ex_mem_rf_we,
    input  wire [ 4:0] mem_wb_rd,
    input  wire        mem_wb_rf_we,

    output wire [ 1:0] forward_a,
    output wire [ 1:0] forward_b
);

    // ForwardA: only forward when instruction uses RS1 as register (not PC)
    wire fwd_a_ex = ex_mem_rf_we && (ex_mem_rd != 5'h0) && (ex_mem_rd == id_ex_rs1) && !id_ex_alua_sel;
    wire fwd_a_wb = mem_wb_rf_we && (mem_wb_rd != 5'h0) && (mem_wb_rd == id_ex_rs1) && !id_ex_alua_sel;
    assign forward_a = fwd_a_ex ? 2'b01 : fwd_a_wb ? 2'b10 : 2'b00;

    // ForwardB: only forward when instruction uses RS2 as register (not EXT)
    wire fwd_b_ex = ex_mem_rf_we && (ex_mem_rd != 5'h0) && (ex_mem_rd == id_ex_rs2) && !id_ex_alub_sel;
    wire fwd_b_wb = mem_wb_rf_we && (mem_wb_rd != 5'h0) && (mem_wb_rd == id_ex_rs2) && !id_ex_alub_sel;
    assign forward_b = fwd_b_ex ? 2'b01 : fwd_b_wb ? 2'b10 : 2'b00;

endmodule
