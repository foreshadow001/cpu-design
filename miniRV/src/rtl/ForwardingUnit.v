`timescale 1ns / 1ps

module ForwardingUnit (
    input  wire [ 4:0] id_ex_rs1,
    input  wire [ 4:0] id_ex_rs2,
    input  wire [ 4:0] id_ex_rd,
    input  wire        id_ex_rf_we,
    input  wire [ 4:0] ex_mem_rd,
    input  wire        ex_mem_rf_we,
    input  wire [ 4:0] mem_wb_rd,
    input  wire        mem_wb_rf_we,

    output wire [ 1:0] forward_a,
    output wire [ 1:0] forward_b
);

    // ForwardA: select alu_a source
    // Priority: EX/MEM > MEM/WB > default (id_ex_rd1)
    assign forward_a = (ex_mem_rf_we && (ex_mem_rd != 5'h0) && (ex_mem_rd == id_ex_rs1)) ? 2'b01 :
                       (mem_wb_rf_we && (mem_wb_rd != 5'h0) && (mem_wb_rd == id_ex_rs1)) ? 2'b10 :
                       2'b00;

    // ForwardB: select alu_b source
    // Priority: EX/MEM > MEM/WB > default (id_ex_rd2 or id_ex_ext)
    assign forward_b = (ex_mem_rf_we && (ex_mem_rd != 5'h0) && (ex_mem_rd == id_ex_rs2)) ? 2'b01 :
                       (mem_wb_rf_we && (mem_wb_rd != 5'h0) && (mem_wb_rd == id_ex_rs2)) ? 2'b10 :
                       2'b00;

endmodule
