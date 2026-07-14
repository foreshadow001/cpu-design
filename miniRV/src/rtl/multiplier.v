`timescale 1ns / 1ps

module multiplier #(
    parameter WIDTH = 32
)(
    input  wire                    clk,
    input  wire                    rst,
    input  wire [WIDTH-1:0]        x,
    input  wire [WIDTH-1:0]        y,
    input  wire                    start /* verilator public */,
    output wire [O_WID-1:0]        z,
    output wire                    busy /* verilator public */
);

    localparam O_WID = 2*WIDTH;

    reg [WIDTH:0]   product_hi   /* verilator public */;  // 33 bits with carry
    reg [WIDTH-1:0] product_lo   /* verilator public */;
    reg [WIDTH-1:0] multiplicand /* verilator public */;
    reg [5:0]       count        /* verilator public */;

    assign busy = (count != 0);
    assign z    = {product_hi[WIDTH-1:0], product_lo};

    // 34-bit sum of upper half + multiplicand
    wire [WIDTH+1:0] hi_sum = {1'b0, product_hi} + {2'b0, multiplicand};

    // Next state: if lo[0], add multiplicand to hi, then shift right
    wire [WIDTH:0]   next_hi = product_lo[0] ? hi_sum[WIDTH+1:1] : {1'b0, product_hi[WIDTH:1]};
    wire [WIDTH-1:0] next_lo = product_lo[0]
        ? {hi_sum[0], product_lo[WIDTH-1:1]}
        : {product_hi[0], product_lo[WIDTH-1:1]};

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            count        <= 0;
            multiplicand <= 0;
            product_hi   <= 0;
            product_lo   <= 0;
        end else if (start && count == 0) begin
            count        <= WIDTH;
            multiplicand <= x;
            product_hi   <= 0;
            product_lo   <= y;
        end else if (count > 0) begin
            product_hi <= next_hi;
            product_lo <= next_lo;
            count      <= count - 1;
        end
    end

endmodule
