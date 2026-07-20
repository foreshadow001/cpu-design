`timescale 1ns / 1ps

`include "defines.vh"

module ALU (
    input  wire         rst,
    input  wire         clk,
    input  wire [ 4:0]  op /* verilator public */,
    input  wire [31:0]  a,
    input  wire [31:0]  b,
    input  wire         suppress,  // prevents multi-cycle start for duplicate MULs

    output reg  [31:0]  c,
    output reg          br,
    output wire         busy
);

    wire        mul_flag, mulu_flag;
    wire [63:0] mul_res, mulu_res;
    wire        mul_busy /* verilator public */, mulu_busy;
    wire        div_flag, divu_flag;
    wire [31:0] div_quo , divu_quo ;    // quotient
    wire [31:0] div_rem , divu_rem ;    // remainder
    wire        div_busy, divu_busy;
    reg  [ 4:0] op_r /* verilator public */;

    wire [4:0] effective_op = (multi_active && any_mul_div && op == op_r) ? op_r : op;

    always @(*) begin
        case (effective_op)
            `ALU_ADD  : c = a + b;
            `ALU_SUB  : c = a - b;
            `ALU_XOR  : c = a ^ b;
            `ALU_AND  : c = a & b;
            `ALU_OR   : c = a | b;
            `ALU_SLL  : c = a << b[4:0];
            `ALU_SRL  : c = a >> b[4:0];
            `ALU_SRA  : c = $signed(a) >>> b[4:0];
            `ALU_SLT  : c = ($signed(a) < $signed(b)) ? 32'h1 : 32'h0;
            `ALU_SLTU : c = (a < b) ? 32'h1 : 32'h0;
            `ALU_MUL  : c = mul_res[31:0];
            `ALU_MULH : begin
                // Signed correction for upper 32 bits
                c = mul_res[63:32];
                if (a_latched[31]) c = c - b_latched;
                if (b_latched[31]) c = c - a_latched;
            end
            `ALU_MULHU: c = mulu_res[63:32];
            `ALU_DIV  : c = (a[31] ^ b[31]) ? (-$signed(div_quo)) : div_quo;
            `ALU_DIVU : c = divu_quo;
            `ALU_REM  : c = a[31] ? (-$signed(div_rem)) : div_rem;
            `ALU_REMU : c = divu_rem;
            default   : c = 32'h0;
        endcase
    end

    always @(*) begin
        case (op)
            `ALU_EQ  : br = (a == b);
            `ALU_NE  : br = (a != b);
            `ALU_SLT : br = ($signed(a) < $signed(b));
            `ALU_SLTU: br = (a < b);
            `ALU_GE  : br = ($signed(a) >= $signed(b));
            `ALU_GEU : br = (a >= b);
            default  : br = 1'b0;
        endcase
    end

    assign mul_flag  = (op == `ALU_MUL) || (op == `ALU_MULH);
    assign mulu_flag = (op == `ALU_MULHU);
    assign div_flag  = (op == `ALU_DIV) || (op == `ALU_REM);
    assign divu_flag = (op == `ALU_DIVU) || (op == `ALU_REMU);
    assign busy      = mul_busy | mulu_busy | div_busy | divu_busy;

    // Latch operands for signed correction in mulh
    reg [31:0] a_latched /* verilator public */, b_latched /* verilator public */;
    // Latch operands at start of multi-cycle op; hold during stall.
    // Clear when MUL/DIV leaves EX (mul_flag drops), not when busy drops.
    reg multi_active /* verilator public */;
    wire any_mul_div = mul_flag | mulu_flag | div_flag | divu_flag;
    // Start on first entry OR when op changes to new MUL/DIV while multi_active
    // Start: first entry (!multi_active) fires immediately.
    // Consecutive MUL/DIV (multi_active && !busy) delayed 1 cycle so op_r
    // captures the new instruction'"'"'s op.
    wire need_continue = any_mul_div & multi_active & !busy;
    reg  restart_continue;
    always @(posedge clk or posedge rst) begin
        if (rst) restart_continue <= 1'b0;
        else     restart_continue <= need_continue;
    end
    wire op_first_mul = any_mul_div & !multi_active;
    wire multi_start = (op_first_mul | restart_continue) & !suppress;

    // Track busy falling edge (unused, kept for reference)

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            multi_active <= 1'b0;
            op_r         <= 5'h0;
            a_latched    <= 32'h0;
            b_latched    <= 32'h0;
        end else if (multi_start) begin
            a_latched    <= a;
            b_latched    <= b;
            op_r         <= op;
            multi_active <= 1'b1;
        end else if (multi_active && !any_mul_div) begin
            op_r         <= 5'h0;
            multi_active <= 1'b0;
        end
    end

    multiplier #(32) U_mul (
        .clk    (clk),
        .rst    (rst),
        .x      (a),
        .y      (b),
        .start  (multi_start & mul_flag),
        .z      (mul_res),
        .busy   (mul_busy)
    );

    multiplier #(33) U_mulu (
        .clk    (clk),
        .rst    (rst),
        .x      ({1'b0, a}),
        .y      ({1'b0, b}),
        .start  (multi_start & mulu_flag),
        .z      (mulu_res),
        .busy   (mulu_busy)
    );

    divider #(32) U_div (
        .clk    (clk),
        .rst    (rst),
        .x      (a[31] ? (~a + 1) : a),
        .y      (b[31] ? (~b + 1) : b),
        .start  (multi_start & div_flag),
        .z      (div_quo),
        .r      (div_rem),
        .busy   (div_busy)
    );

    divider #(33) U_divu (
        .clk    (clk),
        .rst    (rst),
        .x      ({1'b0, a}),
        .y      ({1'b0, b}),
        .start  (multi_start & divu_flag),
        .z      (divu_quo),
        .r      (divu_rem),
        .busy   (divu_busy)
    );

endmodule
