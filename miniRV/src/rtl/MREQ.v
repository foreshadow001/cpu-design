`timescale 1ns / 1ps

`include "defines.vh"

module MREQ (
    input  wire [31:0]  ram_addr,

    input  wire [ 2:0]  ram_rop,
    output reg  [ 3:0]  da_ren,
    output wire [31:0]  da_addr,

    input  wire [ 3:0]  ram_wop,
    input  wire [31:0]  ram_wdata,
    output reg  [ 3:0]  da_wen,
    output reg  [31:0]  da_wdata
);

    wire [1:0] offset = ram_addr[1:0];

    assign da_addr = ram_addr;

    // 写访存请求
    always @(*) begin
        da_wen   = 4'h0;
        da_wdata = ram_wdata;

        case (ram_wop)
            `RAM_WE_B: begin
                case (offset)
                    2'h0: begin da_wen = 4'b0001; da_wdata = {{24{ram_wdata[7]}}, ram_wdata[7:0]}; end
                    2'h1: begin da_wen = 4'b0010; da_wdata = {{16{ram_wdata[7]}}, ram_wdata[7:0], 8'h0}; end
                    2'h2: begin da_wen = 4'b0100; da_wdata = {{8{ram_wdata[7]}}, ram_wdata[7:0], 16'h0}; end
                    2'h3: begin da_wen = 4'b1000; da_wdata = {ram_wdata[7:0], 24'h0}; end
                endcase
            end
            `RAM_WE_H: begin
                case (offset[1])
                    1'b0: begin da_wen = 4'b0011; da_wdata = {{16{ram_wdata[15]}}, ram_wdata[15:0]}; end
                    1'b1: begin da_wen = 4'b1100; da_wdata = {ram_wdata[15:0], 16'h0}; end
                endcase
            end
            `RAM_WE_W: begin
                if (offset == 2'h0) begin
                    da_wen   = ram_wop;
                end
            end
        endcase
    end

    // 读访存请求 — read full word, MEXT extracts the right bytes
    always @(*) begin
        if (ram_rop != `RAM_EXT_N) begin
            da_ren = 4'hF;
        end else begin
            da_ren = 4'h0;
        end
    end

endmodule
