`timescale 1ns / 1ps

module divider #(
    parameter WIDTH = 32
)(
    input  wire                    clk,
    input  wire                    rst,
    input  wire [WIDTH-1:0]        x,  // dividend
    input  wire [WIDTH-1:0]        y,  // divisor
    input  wire                    start,
    output wire [WIDTH-1:0]        z,  // quotient
    output wire [WIDTH-1:0]        r,  // remainder
    output reg                     busy
);

    reg [WIDTH-1:0] remainder;
    reg [WIDTH-1:0] quotient;
    reg [WIDTH-1:0] divisor;
    reg [5:0]       count;

    assign z = quotient;
    assign r = remainder;

    // Next-state wires
    // Shift {remainder, quotient} left by 1: new bit from quotient[WIDTH-1] into remainder[0]
    wire [WIDTH-1:0] shifted_rem = {remainder[WIDTH-2:0], quotient[WIDTH-1]};
    // Subtract divisor from shifted remainder
    wire [WIDTH:0]   diff = {1'b0, shifted_rem} - {1'b0, divisor};
    wire             enough = ~diff[WIDTH];  // 1 if shifted_rem >= divisor

    wire [WIDTH-1:0] next_rem = enough ? diff[WIDTH-1:0] : shifted_rem;
    wire [WIDTH-1:0] next_quo = {quotient[WIDTH-2:0], enough};

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            count     <= 0;
            remainder <= 0;
            quotient  <= 0;
            divisor   <= 0;
            busy      <= 0;
        end else if (start && count == 0) begin
            count     <= WIDTH;
            remainder <= 0;
            quotient  <= x;
            divisor   <= y;
            busy      <= 1;
        end else if (count > 0) begin
            remainder <= next_rem;
            quotient  <= next_quo;
            count     <= count - 1;
            if (count == 1) busy <= 0;
        end
    end

endmodule
