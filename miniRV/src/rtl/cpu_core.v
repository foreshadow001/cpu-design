`timescale 1ns / 1ps

`include "defines.vh"

module cpu_core(
    input  wire         cpu_rst,
    input  wire         cpu_clk,

    // Instruction Fetch Interface
    output wire         ifetch_req   /* verilator public */ ,
    output wire [31:0]  ifetch_addr  /* verilator public */ ,
    input  wire         ifetch_valid /* verilator public */ ,
    input  wire [31:0]  ifetch_inst,

    // Data Access Interface
    output wire [ 3:0]  daccess_ren,
    output wire [31:0]  daccess_addr,
    input  wire         daccess_rvalid,
    input  wire [31:0]  daccess_rdata,
    output wire [ 3:0]  daccess_wen,
    output wire [31:0]  daccess_wdata,
    input  wire         daccess_wresp
);

    /**********************************************************************
     * IF Stage — PC + Instruction Fetch
     **********************************************************************/
    reg [31:0] pc /* verilator public */;
    reg [31:0] fetch_pc /* verilator public */;  // PC 1 cycle ago; syncs to held PC during stall
    wire [31:0] pc_plus_4 = pc + 32'h4;

    // BRAM has 1-cycle read latency: douta <= mem[addra] at posedge.
    // After a PC change (flush_f), the BRAM needs 2 reads from the new PC
    // before valid data appears. flush_next + flush_next2 provide the 2
    // extra NOP cycles needed.
    //
    // posedge 0 (flush_f):     PC→target, IF/ID←NOP, BRAM sees target
    // posedge 1 (flush_next):  PC holds,  IF/ID←NOP, BRAM reads target (1st)
    // posedge 2 (flush_next2): PC→tgt+4, IF/ID←NOP, BRAM reads target (2nd)
    // posedge 3 (normal):      PC→tgt+8, IF/ID←{target, BRAM[target]} ✓
    reg flush_next;
    reg flush_next2 /* verilator public */;
    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            flush_next  <= 1'b0;
            flush_next2 <= 1'b0;
        end else begin
            flush_next  <= flush_f;
            flush_next2 <= flush_next;
        end
    end

    // Load-use resync: 1 extra NOP after stall releases.
    reg  load_resync  /* verilator public */;
    reg  load_resync2;
    wire load_stall_active = load_use_stall & !flush_f;
    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            load_resync  <= 1'b0;
            load_resync2 <= 1'b0;
        end else begin
            load_resync  <= load_stall_active;
            load_resync2 <= load_resync;
        end
    end

    // On first stall cycle, sync fetch_pc to held PC so that after the
    // stall, IF/ID captures {held_pc, BRAM[held_pc]} correctly.
    reg stall_synced;
    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst)               stall_synced <= 1'b0;
        else if (!stall_f)         stall_synced <= 1'b0;
        else if (stall_f && !stall_synced) stall_synced <= 1'b1;
    end

    wire effective_flush = flush_f | flush_next | flush_next2
                         | load_resync | load_resync2;

    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            pc       <= 32'h0;
            fetch_pc <= 32'h0;
        end else if (flush_f) begin
            pc       <= pc_next;
            fetch_pc <= pc_next;
        end else if (stall_f && !stall_synced) begin
            // First stall: rewind for load-use, hold for mul/div
            if (load_use_stall) begin
                pc       <= pc - 32'h4;
                fetch_pc <= pc - 32'h4;
            end else begin
                pc       <= pc;
                fetch_pc <= pc;
            end
        end else if (!stall_f && !flush_next
                      && !(mul_div_flush && flush_next2)
                      && !load_resync && !load_resync2) begin
            pc       <= pc_next;
            fetch_pc <= pc;
        end
    end

    /**********************************************************************
     * IF/ID Pipeline Register
     **********************************************************************/
    reg [31:0] if_id_pc   /* verilator public */;
    reg [31:0] if_id_inst /* verilator public */;

    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            if_id_pc   <= 32'h0;
            if_id_inst <= 32'h0;
        end else if (effective_flush) begin
            if_id_pc   <= 32'h0;
            if_id_inst <= 32'h0;
        end else if (!stall_f) begin
            if_id_pc   <= fetch_pc;
            if_id_inst <= ifetch_valid ? ifetch_inst : 32'h0;
        end
    end

    /**********************************************************************
     * ID Stage — Decode + RF Read + Sign Extend
     **********************************************************************/
    wire [ 1:0] id_npc_op;
    wire [ 1:0] id_rf_wsel;
    wire [ 2:0] id_sext_op;
    wire [ 4:0] id_alu_op;
    wire        id_alua_sel;
    wire        id_alub_sel;
    wire [ 2:0] id_ram_rop;
    wire [ 3:0] id_ram_wop;
    wire        id_is_mul;
    wire        id_is_div;
    wire        id_rf_we;

    wire [4:0] id_rs1 = if_id_inst[19:15];
    wire [4:0] id_rs2 = if_id_inst[24:20];
    wire [4:0] id_rd  = if_id_inst[11:7];

    Controller U_CU (
        .opcode     (if_id_inst[6:0]),
        .funct3     (if_id_inst[14:12]),
        .funct7     (if_id_inst[31:25]),
        .npc_op     (id_npc_op),
        .sext_op    (id_sext_op),
        .alu_op     (id_alu_op),
        .alua_sel   (id_alua_sel),
        .alub_sel   (id_alub_sel),
        .is_mul     (id_is_mul),
        .is_div     (id_is_div),
        .ram_r_op   (id_ram_rop),
        .ram_w_op   (id_ram_wop),
        .rf_we      (id_rf_we),
        .rf_wsel    (id_rf_wsel)
    );

    wire [31:0] id_rf_rd1;
    wire [31:0] id_rf_rd2;

    RF U_RF (
        .clk    (cpu_clk),
        .rR1    (id_rs1),
        .rR2    (id_rs2),
        .rD1    (id_rf_rd1),
        .rD2    (id_rf_rd2),
        .we     (wb_rf_we),
        .wR     (wb_rf_wR),
        .wD     (wb_rf_wD)
    );

    wire [31:0] id_ext;
    wire [31:0] id_br_target = if_id_pc + id_ext;  // branch/JAL target

    SEXT U_SEXT (
        .op     (id_sext_op),
        .imm    (if_id_inst[31:7]),
        .ext    (id_ext)
    );

    /**********************************************************************
     * ID/EX Pipeline Register
     **********************************************************************/
    reg [31:0] id_ex_pc /* verilator public */;
    reg [31:0] id_ex_rd1;
    reg [31:0] id_ex_rd2;
    reg [31:0] id_ex_ext /* verilator public */;
    reg [31:0] id_ex_br_target;
    reg [ 4:0] id_ex_alu_op /* verilator public */;
    reg        id_ex_alua_sel;
    reg        id_ex_alub_sel /* verilator public */;
    reg        id_ex_rf_we;
    reg [ 1:0] id_ex_rf_wsel;
    reg [ 2:0] id_ex_ram_rop;
    reg [ 3:0] id_ex_ram_wop;
    reg        id_ex_is_mul;
    reg        id_ex_is_div;
    reg [ 4:0] id_ex_rs1 /* verilator public */;
    reg [ 4:0] id_ex_rs2 /* verilator public */;
    reg [ 4:0] id_ex_rd;
    reg [ 1:0] id_ex_npc_op;

    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            id_ex_pc        <= 32'h0;
            id_ex_rd1       <= 32'h0;
            id_ex_rd2       <= 32'h0;
            id_ex_ext       <= 32'h0;
            id_ex_br_target <= 32'h0;
            id_ex_alu_op    <= `ALU_ADD;
            id_ex_alua_sel  <= `ALU_A_RS1;
            id_ex_alub_sel  <= `ALU_B_RS2;
            id_ex_rf_we     <= 1'b0;
            id_ex_rf_wsel   <= `WB_ALU;
            id_ex_ram_rop   <= `RAM_EXT_N;
            id_ex_ram_wop   <= `RAM_WE_N;
            id_ex_is_mul    <= 1'b0;
            id_ex_is_div    <= 1'b0;
            id_ex_rs1       <= 5'h0;
            id_ex_rs2       <= 5'h0;
            id_ex_rd        <= 5'h0;
            id_ex_npc_op    <= `NPC_PC4;
        end else if (flush_d) begin
            // Flush: insert NOP-like values in ID/EX
            id_ex_ram_rop   <= `RAM_EXT_N;
            id_ex_ram_wop   <= `RAM_WE_N;
            id_ex_rf_we     <= 1'b0;
            id_ex_rf_wsel   <= `WB_ALU;
            id_ex_is_mul    <= 1'b0;
            id_ex_is_div    <= 1'b0;
            id_ex_npc_op    <= `NPC_PC4;
            id_ex_alua_sel  <= `ALU_A_RS1;
            id_ex_alub_sel  <= `ALU_B_RS2;
            id_ex_alu_op    <= `ALU_ADD;
            id_ex_ext       <= 32'h0;
        end else if (!stall_d) begin
            id_ex_pc        <= if_id_pc;
            id_ex_rd1       <= id_fwd_rd1;      // ID-stage forwarding
            id_ex_rd2       <= id_store_data;   // store data with forwarding
            id_ex_ext       <= id_ext;
            id_ex_br_target <= id_br_target;
            id_ex_alu_op    <= id_alu_op;
            id_ex_alua_sel  <= id_alua_sel;
            id_ex_alub_sel  <= id_alub_sel;
            id_ex_rf_we     <= id_rf_we;
            id_ex_rf_wsel   <= id_rf_wsel;
            id_ex_ram_rop   <= id_ram_rop;
            id_ex_ram_wop   <= id_ram_wop;
            id_ex_is_mul    <= id_is_mul;
            id_ex_is_div    <= id_is_div;
            id_ex_rs1       <= id_rs1;
            id_ex_rs2       <= id_rs2;
            id_ex_rd        <= id_rd;
            id_ex_npc_op    <= id_npc_op;
        end
        // else: stall_d=1, flush_d=0 → hold current values (mul/div stays in EX)
    end

    /**********************************************************************
     * Hazard Detection — Stall + Flush
     **********************************************************************/
    // Load-use hazard: load in EX, dependent instruction in ID (Phase 2)
    wire load_use_stall = (id_ex_ram_rop != `RAM_EXT_N)
                        & ((id_rs1 == id_ex_rd) | (id_rs2 == id_ex_rd))
                        & (id_ex_rd != 5'h0);

    // Control hazards (Phase 3)
    wire id_is_jal   = (id_npc_op == `NPC_JMP);
    wire ex_is_jalr  = (id_ex_npc_op == `NPC_JALR);
    wire ex_br_taken /* verilator public */ = (id_ex_npc_op == `NPC_BRA) & ex_br;

    // Target addresses
    wire [31:0] id_jal_target  = if_id_pc + id_ext;
    wire [31:0] ex_br_target   = id_ex_br_target;
    wire [31:0] ex_jalr_target = {ex_alu_c[31:1], 1'b0};

    // mul_div_release: PC skipped instruction during stall, flush_f re-fetches it.
    // Track this flush type separately — mul/div needs PC held during flush_next2
    // to keep BRAM reading the re-fetched address (pc-4), unlike branches where
    // PC advances during flush_next2 (works because adjacent instructions match).
    reg  mul_div_flush;
    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst)             mul_div_flush <= 1'b0;
        else if (mul_div_release) mul_div_flush <= 1'b1;
        else if (!flush_next && !flush_next2) mul_div_flush <= 1'b0;
    end

    wire flush_f /* verilator public */ = id_is_jal | ex_br_taken | ex_is_jalr
                                        | mul_div_release;
    wire flush_d /* verilator public */ = ex_br_taken | ex_is_jalr | load_use_stall;

    assign ifetch_req  = !cpu_rst;
    assign ifetch_addr = pc;

    // PC next: when mul/div releases, go back 4 to re-fetch lost instruction
    wire [31:0] pc_next;
    assign pc_next = mul_div_release ? (pc - 32'h4) :
                     ex_br_taken  ? ex_br_target  :
                     ex_is_jalr   ? ex_jalr_target :
                     id_is_jal    ? id_jal_target  :
                     pc_plus_4;

    // Mul/div: detect in ID stage, stall immediately when it enters EX
    // (eliminates the 1-cycle gap before busy goes high)
    reg  mul_div_entering;   // set 1 cycle before mul/div enters EX
    wire id_mul_div = id_is_mul | id_is_div;

    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst)
            mul_div_entering <= 1'b0;
        else
            mul_div_entering <= id_mul_div;
    end

    // Stall: first EX cycle (entering) OR ongoing computation (busy)
    wire mul_div_stall = mul_div_entering
                       | ((id_ex_is_mul | id_ex_is_div) & ex_mul_div_busy);

    // Falling edge of mul_div_stall: PC must go back 4 to re-fetch the
    // instruction that was lost when IF/ID stalled (BRAM 1-cycle latency)
    reg  mul_div_stall_d;
    wire mul_div_release = mul_div_stall_d & !mul_div_stall;
    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst)
            mul_div_stall_d <= 1'b0;
        else
            mul_div_stall_d <= mul_div_stall;
    end

    // Stall: load-use, mul/div; flush overrides
    wire stall_f  /* verilator public */ = ((load_use_stall & !flush_f) | mul_div_stall) & !flush_f;
    wire stall_d /* verilator public */ = mul_div_stall;
    wire stall_e = mul_div_stall;   // insert NOP into EX/MEM during mul/div

    // Forwarding unit
    wire [1:0] forward_a;
    wire [1:0] forward_b /* verilator public */;

    ForwardingUnit U_FWD (
        .id_ex_rs1      (id_ex_rs1),
        .id_ex_rs2      (id_ex_rs2),
        .id_ex_alua_sel (id_ex_alua_sel),
        .id_ex_alub_sel (id_ex_alub_sel),
        .id_ex_rd       (id_ex_rd),
        .id_ex_rf_we    (id_ex_rf_we),
        .ex_mem_rd      (ex_mem_rd),
        .ex_mem_rf_we   (ex_mem_rf_we),
        .mem_wb_rd      (mem_wb_rd),
        .mem_wb_rf_we   (mem_wb_rf_we),
        .forward_a      (forward_a),
        .forward_b      (forward_b)
    );

    // ID-stage forwarding: ID/EX captures forwarded values, not stale RF
    // Check EX combinational output (for back-to-back), then EX/MEM, then MEM/WB
    wire [31:0] id_fwd_rd1 = (id_ex_rf_we && id_ex_rd != 0 && id_ex_rd == id_rs1)
                           ? ex_alu_c
                           : (ex_mem_rf_we && ex_mem_rd != 0 && ex_mem_rd == id_rs1)
                           ? ex_mem_alu_c
                           : (mem_wb_rf_we && mem_wb_rd != 0 && mem_wb_rd == id_rs1)
                           ? wb_forward_data
                           : id_rf_rd1;

    wire [31:0] id_fwd_rd2 = (id_ex_rf_we && id_ex_rd != 0 && id_ex_rd == id_rs2)
                           ? ex_alu_c
                           : (ex_mem_rf_we && ex_mem_rd != 0 && ex_mem_rd == id_rs2)
                           ? ex_mem_alu_c
                           : (mem_wb_rf_we && mem_wb_rd != 0 && mem_wb_rd == id_rs2)
                           ? wb_forward_data
                           : id_rf_rd2;

    // Store data forwarding: rs2 in ID might need data from EX or MEM
    wire [31:0] id_store_data;
    assign id_store_data = (ex_mem_rf_we && (ex_mem_rd != 5'h0) && (ex_mem_rd == id_rs2))
                         ? ex_mem_alu_c
                         : id_fwd_rd2;

    /**********************************************************************
     * EX Stage — ALU (with forwarding muxes)
     **********************************************************************/
    // EX/MEM forwarding data: select based on wsel (like wb_forward_data)
    wire [31:0] ex_mem_fwd_data;
    assign ex_mem_fwd_data = (ex_mem_rf_wsel == `WB_ALU) ? ex_mem_alu_c :
                             (ex_mem_rf_wsel == `WB_EXT) ? ex_mem_ext   :
                             ex_mem_alu_c;  // default (PC4/RAM handled by MEM/WB)

    // ALU input A: PC (for AUIPC) or forwarded register value
    wire [31:0] ex_alu_a_raw = id_ex_alua_sel ? id_ex_pc : id_ex_rd1;
    wire [31:0] ex_alu_a = (forward_a == 2'b01) ? ex_mem_fwd_data :
                           (forward_a == 2'b10) ? wb_forward_data :
                           ex_alu_a_raw;

    // ALU input B: EXT (immediate) or forwarded register value
    wire [31:0] ex_alu_b_raw = id_ex_alub_sel ? id_ex_ext : id_ex_rd2;
    wire [31:0] ex_alu_b /* verilator public */ = (forward_b == 2'b01) ? ex_mem_fwd_data :
                           (forward_b == 2'b10) ? wb_forward_data :
                           ex_alu_b_raw;

    wire [31:0] ex_alu_c /* verilator public */;
    wire        ex_br;
    wire        ex_mul_div_busy;

    ALU U_ALU (
        .rst    (cpu_rst),
        .clk    (cpu_clk),
        .op     (id_ex_alu_op),
        .a      (ex_alu_a),
        .b      (ex_alu_b),
        .br     (ex_br),
        .c      (ex_alu_c),
        .busy   (ex_mul_div_busy)
    );

    /**********************************************************************
     * EX/MEM Pipeline Register
     **********************************************************************/
    reg [31:0] ex_mem_pc;
    reg [31:0] ex_mem_alu_c;
    reg [31:0] ex_mem_rd2;
    reg [31:0] ex_mem_ext;
    reg        ex_mem_br;
    reg        ex_mem_rf_we;
    reg [ 1:0] ex_mem_rf_wsel;
    reg [ 2:0] ex_mem_ram_rop;
    reg [ 3:0] ex_mem_ram_wop;
    reg [ 4:0] ex_mem_rd;
    reg        ex_mem_is_mul;
    reg        ex_mem_is_div;

    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            ex_mem_pc       <= 32'h0;
            ex_mem_alu_c    <= 32'h0;
            ex_mem_rd2      <= 32'h0;
            ex_mem_ext      <= 32'h0;
            ex_mem_br       <= 1'b0;
            ex_mem_rf_we    <= 1'b0;
            ex_mem_rf_wsel  <= `WB_ALU;
            ex_mem_ram_rop  <= `RAM_EXT_N;
            ex_mem_ram_wop  <= `RAM_WE_N;
            ex_mem_rd       <= 5'h0;
            ex_mem_is_mul   <= 1'b0;
            ex_mem_is_div   <= 1'b0;
        end else if (stall_e) begin
            // Mul/div computing: insert NOP downstream (block garbage)
            ex_mem_rf_we    <= 1'b0;
            ex_mem_ram_rop  <= `RAM_EXT_N;
            ex_mem_ram_wop  <= `RAM_WE_N;
            ex_mem_is_mul   <= 1'b0;
            ex_mem_is_div   <= 1'b0;
        end else begin
            ex_mem_pc       <= id_ex_pc;
            ex_mem_alu_c    <= ex_alu_c;
            ex_mem_rd2      <= id_ex_rd2;
            ex_mem_ext      <= id_ex_ext;
            ex_mem_br       <= ex_br;
            ex_mem_rf_we    <= id_ex_rf_we;
            ex_mem_rf_wsel  <= id_ex_rf_wsel;
            ex_mem_ram_rop  <= id_ex_ram_rop;
            ex_mem_ram_wop  <= id_ex_ram_wop;
            ex_mem_rd       <= id_ex_rd;
            ex_mem_is_mul   <= id_ex_is_mul;
            ex_mem_is_div   <= id_ex_is_div;
        end
    end

    /**********************************************************************
     * MEM Stage — Memory Access (combinational to outputs)
     **********************************************************************/
    wire [ 3:0] mem_da_ren;
    wire [31:0] mem_da_addr;
    wire [ 3:0] mem_da_wen;
    wire [31:0] mem_da_wdata;

    MREQ U_MREQ (
        .ram_addr   (ex_mem_alu_c),
        .ram_rop    (ex_mem_ram_rop),
        .da_ren     (mem_da_ren),
        .da_addr    (mem_da_addr),
        .ram_wop    (ex_mem_ram_wop),
        .ram_wdata  (ex_mem_rd2),
        .da_wen     (mem_da_wen),
        .da_wdata   (mem_da_wdata)
    );

    // Phase 1: drive daccess directly (combinational) from MREQ
    assign daccess_ren   = mem_da_ren;
    assign daccess_addr  = mem_da_addr;
    assign daccess_wen   = mem_da_wen;
    assign daccess_wdata = mem_da_wdata;

    /**********************************************************************
     * MEM/WB Pipeline Register
     **********************************************************************/
    reg [31:0] mem_wb_pc     /* verilator public */;
    reg [31:0] mem_wb_alu_c;
    reg [31:0] mem_wb_ext /* verilator public */;
    reg        mem_wb_rf_we  /* verilator public */;
    reg [ 1:0] mem_wb_rf_wsel /* verilator public */;
    reg [ 4:0] mem_wb_rd     /* verilator public */;
    reg [ 2:0] mem_wb_ram_rop;
    reg [ 1:0] mem_wb_byte_offs;

    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            mem_wb_pc        <= 32'h0;
            mem_wb_alu_c     <= 32'h0;
            mem_wb_ext       <= 32'h0;
            mem_wb_rf_we     <= 1'b0;
            mem_wb_rf_wsel   <= `WB_ALU;
            mem_wb_rd        <= 5'h0;
            mem_wb_ram_rop   <= `RAM_EXT_N;
            mem_wb_byte_offs <= 2'h0;
        end else begin
            mem_wb_pc        <= ex_mem_pc;
            mem_wb_alu_c     <= ex_mem_alu_c;
            mem_wb_ext       <= ex_mem_ext;
            mem_wb_rf_we     <= ex_mem_rf_we;
            mem_wb_rf_wsel   <= ex_mem_rf_wsel;
            mem_wb_rd        <= ex_mem_rd;
            mem_wb_ram_rop   <= ex_mem_ram_rop;
            mem_wb_byte_offs <= ex_mem_alu_c[1:0];
        end
    end

    /**********************************************************************
     * WB Stage — MEXT + Register File Writeback
     **********************************************************************
     * MEXT is combinational: op/byte_offs from MEM/WB, din from daccess_rdata.
     * For loads: daccess_rdata arrives at posedge ~1 cycle after MEM stage
     * issued the request (BRAM 1-cycle read latency). So rdata is valid
     * during the cycle AFTER the load enters WB. We handle this with a
     * delayed write for loads (see wb_load_* registers below).
     **********************************************************************/
    wire [31:0] wb_ram_ext;

    MEXT U_MEXT (
        .op         (mem_wb_ram_rop),
        .din        (daccess_rdata),
        .byte_offs  (mem_wb_byte_offs),
        .ext        (wb_ram_ext)
    );

    // Combinational writeback data — used for forwarding (includes live load data)
    wire [31:0] wb_forward_data;
    assign wb_forward_data = (mem_wb_rf_wsel == `WB_ALU) ? mem_wb_alu_c   :
                             (mem_wb_rf_wsel == `WB_RAM) ? wb_ram_ext     :
                             (mem_wb_rf_wsel == `WB_PC4) ? (mem_wb_pc + 4) :
                             (mem_wb_rf_wsel == `WB_EXT) ? mem_wb_ext       :
                             32'h0;

    // Load writeback: BRAM has 1-cycle read latency, so load data arrives
    // during WB (daccess_rvalid goes high 1 cycle after daccess_ren).
    // We write to RF immediately using the live daccess_rvalid/wb_ram_ext.
    // For non-loads, write happens in the WB stage normally.
    wire wb_is_load = (mem_wb_rf_wsel == `WB_RAM);

    wire        wb_rf_we;
    wire [ 4:0] wb_rf_wR;
    wire [31:0] wb_rf_wD;
    assign wb_rf_we = wb_is_load ? (mem_wb_rf_we & daccess_rvalid) : mem_wb_rf_we;
    assign wb_rf_wR = mem_wb_rd;
    assign wb_rf_wD = wb_is_load ? wb_ram_ext :
                      (mem_wb_rf_wsel == `WB_ALU) ? mem_wb_alu_c   :
                      (mem_wb_rf_wsel == `WB_PC4) ? (mem_wb_pc + 4) :
                      (mem_wb_rf_wsel == `WB_EXT) ? mem_wb_ext       :
                      32'h0;

    /**********************************************************************
     * Debug / Trace Signals (RUN_TRACE)
     **********************************************************************/

`ifdef RUN_TRACE
    wire [31:0] debug_wb_pc    /* verilator public */ ;
    wire        debug_wb_rf_we /* verilator public */ ;
    wire [ 4:0] debug_wb_rf_wR /* verilator public */ ;
    wire [31:0] debug_wb_rf_wD /* verilator public */ ;

    wire [31:0] debug_mem_pc    /* verilator public */ ;
    wire [ 3:0] debug_mem_we    /* verilator public */ ;
    wire [31:0] debug_mem_waddr /* verilator public */ ;
    wire [31:0] debug_mem_wdata /* verilator public */ ;

    // Latch store data from ID/EX for trace comparison
    reg [31:0] store_data_r;
    always @(posedge cpu_clk) begin
        if (|id_ex_ram_wop) store_data_r <= id_ex_rd2;
    end

    // debug_wb: pulse once when WB instruction changes
    reg [31:0] last_wb_pc;
    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) last_wb_pc <= 32'h0;
        else         last_wb_pc <= mem_wb_pc;
    end
    wire wb_change = (mem_wb_pc != last_wb_pc);
    assign debug_wb_pc    = mem_wb_pc;
    assign debug_wb_rf_we = mem_wb_rf_we & wb_change;
    assign debug_wb_rf_wR = mem_wb_rd;
    assign debug_wb_rf_wD = wb_rf_wD;

    // debug_mem: directly from MEM stage
    assign debug_mem_pc    = ex_mem_pc;
    assign debug_mem_we    = mem_da_wen;
    assign debug_mem_waddr = mem_da_addr;
    assign debug_mem_wdata = store_data_r;
`endif

endmodule
