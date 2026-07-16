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
    output wire                    busy
);

    reg [WIDTH-1:0] remainder;
    reg [WIDTH-1:0] quotient;
    reg [WIDTH-1:0] divisor;
    reg [5:0]       count;
    reg             start_d;

    assign z = quotient;
    assign r = remainder;
    assign busy = (count != 0);

    // Next-state wires
    // Shift {remainder, quotient} left by 1: new bit from quotient[WIDTH-1] into remainder[0]
    wire [WIDTH-1:0] shifted_rem = {remainder[WIDTH-2:0], quotient[WIDTH-1]};
    // Subtract divisor from shifted remainder
    wire [WIDTH:0]   diff = {1'b0, shifted_rem} - {1'b0, divisor};
    wire             enough = ~diff[WIDTH];  // 1 if shifted_rem >= divisor

    wire [WIDTH-1:0] next_rem = enough ? diff[WIDTH-1:0] : shifted_rem;
    wire [WIDTH-1:0] next_quo = {quotient[WIDTH-2:0], enough};

    // Edge-triggered start: only fire on rising edge, prevent restart
    wire start_rise = start && !start_d;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            count     <= 0;
            remainder <= 0;
            quotient  <= 0;
            divisor   <= 0;
            start_d   <= 0;
        end else begin
            start_d <= start;
            if (start_rise) begin
                count     <= WIDTH;
                remainder <= 0;
                quotient  <= x;
                divisor   <= y;
            end else if (count > 0) begin
                remainder <= next_rem;
                quotient  <= next_quo;
                count     <= count - 1;
            end
        end
    end

endmodule
