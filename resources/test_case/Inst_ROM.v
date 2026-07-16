`timescale 1ns / 1ps

`include "defines.vh"

module Inst_ROM (
    input  wire         cpu_clk,
    input  wire         cpu_rst,        // high active
    // Interface to CPU
    input  wire         inst_rreq,
    input  wire [31:0]  inst_addr,
    output wire         inst_valid,
    output wire [31:0]  inst_out
);

    // Combinational: remove 1 cycle of latency
    assign inst_valid = cpu_rst ? 1'b0 : inst_rreq;

    IROM U_irom (
        .clka   (cpu_clk),
        .addra  (inst_addr[31:2]),
        .douta  (inst_out)
    );

endmodule
