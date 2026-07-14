`timescale 1ns / 1ps

`include "defines.vh"

module MEXT (
    input  wire [ 2:0]  op,
    input  wire [31:0]  din,
    input  wire [ 1:0]  byte_offs,
    output reg  [31:0]  ext
);

    // Shift din right by byte_offs*8 so the target data is byte-aligned at LSBs
    reg [31:0] aligned;
    always @(*) begin
        case (byte_offs)
            2'b01  : aligned = { 8'h0, din[31: 8]};
            2'b10  : aligned = {16'h0, din[31:16]};
            2'b11  : aligned = {24'h0, din[31:24]};
            default: aligned = din;
        endcase
    end

    always @(*) begin
        case (op)
            `RAM_EXT_B :  ext = {{24{aligned[ 7]}}, aligned[ 7:0]};
            `RAM_EXT_BU:  ext = { 24'h0,            aligned[ 7:0]};
            `RAM_EXT_H :  ext = {{16{aligned[15]}}, aligned[15:0]};
            `RAM_EXT_HU:  ext = { 16'h0,            aligned[15:0]};
            default    :  ext = aligned;   // RAM_EXT_W / RAM_EXT_N
        endcase
    end

endmodule
