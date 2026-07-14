# miniRV 全指令控制信号设计（44条）

> 与 `design/miniRV-全44条指令-数据通路与控制信号.xlsx` 完全对齐。控制信号命名采用模板约定。

## 一、数据通路表

| 指令 | npc | pc | offset | br | rR1 | rR2 | wR | wD | imm | A | B | ram_addr | ram_wdata | din | byte_offs |
|------|-----|-----|--------|-----|------|------|-----|------|------|-----|-----|----------|-----------|-----|----------|
| addi | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | IN.inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| ori | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | IN.inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| slli | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | IN.inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| xori | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | IN.inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| srli | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | IN.inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| srai | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | IN.inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| andi | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | IN.inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| slti | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | IN.inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| sltiu | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | IN.inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| lw | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | MEXT.ext | IN.inst[31:20] | RF.rD1 | SEXT.ext | ALU.C | - | IN.daccess_rdata | ALU.C[1:0] |
| lb | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | MEXT.ext | IN.inst[31:20] | RF.rD1 | SEXT.ext | ALU.C | - | IN.daccess_rdata | ALU.C[1:0] |
| lbu | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | MEXT.ext | IN.inst[31:20] | RF.rD1 | SEXT.ext | ALU.C | - | IN.daccess_rdata | ALU.C[1:0] |
| lh | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | MEXT.ext | IN.inst[31:20] | RF.rD1 | SEXT.ext | ALU.C | - | IN.daccess_rdata | ALU.C[1:0] |
| lhu | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | MEXT.ext | IN.inst[31:20] | RF.rD1 | SEXT.ext | ALU.C | - | IN.daccess_rdata | ALU.C[1:0] |
| sb | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | - | - | IN.inst[31:7] | RF.rD1 | SEXT.ext | ALU.C | RF.rD2 | - | - |
| sh | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | - | - | IN.inst[31:7] | RF.rD1 | SEXT.ext | ALU.C | RF.rD2 | - | - |
| sw | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | - | - | IN.inst[31:7] | RF.rD1 | SEXT.ext | ALU.C | RF.rD2 | - | - |
| add | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | - | RF.rD1 | RF.rD2 | - | - | - | - |
| sub | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | - | RF.rD1 | RF.rD2 | - | - | - | - |
| xor | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | - | RF.rD1 | RF.rD2 | - | - | - | - |
| sll | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | - | RF.rD1 | RF.rD2 | - | - | - | - |
| srl | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | - | RF.rD1 | RF.rD2 | - | - | - | - |
| sra | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | - | RF.rD1 | RF.rD2 | - | - | - | - |
| and | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | - | RF.rD1 | RF.rD2 | - | - | - | - |
| or  | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | - | RF.rD1 | RF.rD2 | - | - | - | - |
| slt | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | - | RF.rD1 | RF.rD2 | - | - | - | - |
| sltu | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | - | RF.rD1 | RF.rD2 | - | - | - | - |
| mul | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | - | RF.rD1 | RF.rD2 | - | - | - | - |
| mulh | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | - | RF.rD1 | RF.rD2 | - | - | - | - |
| mulhu | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | - | RF.rD1 | RF.rD2 | - | - | - | - |
| div | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | - | RF.rD1 | RF.rD2 | - | - | - | - |
| divu | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | - | RF.rD1 | RF.rD2 | - | - | - | - |
| rem | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | - | RF.rD1 | RF.rD2 | - | - | - | - |
| remu | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | - | RF.rD1 | RF.rD2 | - | - | - | - |
| beq | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | - | - | IN.inst[31\|7\|30:25\|11:8] | RF.rD1 | RF.rD2 | - | - | - | - |
| bne | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | - | - | IN.inst[31\|7\|30:25\|11:8] | RF.rD1 | RF.rD2 | - | - | - | - |
| blt | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | - | - | IN.inst[31\|7\|30:25\|11:8] | RF.rD1 | RF.rD2 | - | - | - | - |
| bltu | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | - | - | IN.inst[31\|7\|30:25\|11:8] | RF.rD1 | RF.rD2 | - | - | - | - |
| bge | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | - | - | IN.inst[31\|7\|30:25\|11:8] | RF.rD1 | RF.rD2 | - | - | - | - |
| bgeu | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | - | - | IN.inst[31\|7\|30:25\|11:8] | RF.rD1 | RF.rD2 | - | - | - | - |
| lui | NPC.npc | PC.pc | - | - | - | - | IN.inst[11:7] | SEXT.ext | IN.inst[31:12] | - | - | - | - | - | - |
| auipc | NPC.npc | PC.pc | - | - | - | - | IN.inst[11:7] | ALU.C | IN.inst[31:12] | PC.pc | SEXT.ext | - | - | - | - |
| jal | NPC.npc | PC.pc | SEXT.ext | - | - | - | IN.inst[11:7] | NPC.pc4 | IN.inst[31\|19:12\|20\|30:21] | - | - | - | - | - | - |
| jalr | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | NPC.pc4 | IN.inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| **综合** | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C / SEXT.ext / MEXT.ext / NPC.pc4 | IN.inst[31:7] | RF.rD1 / PC.pc | RF.rD2 / SEXT.ext | ALU.C | RF.rD2 | IN.daccess_rdata | ALU.C[1:0] |
| **操作选择信号** | - | - | npc_op | - | - | - | rf_we | - | sext_op | alu_op | - | ram_rop | ram_wop | ram_rop | - |
| **多路选择信号** | - | - | - | - | - | - | - | rf_wsel | - | alua_sel | alub_sel | - | - | - | - |
| **多周期标志** | - | - | - | - | - | - | - | - | - | is_mul / is_div | - | - | - | - | - |

> 控制信号行标注从综合数据通路中引出的信号。npc_op 在 NPC 列（offset/br）、rf_we/rf_wsel 在 RF 列（wR/wD）、sext_op 在 SEXT 列、alu_op/alua_sel/alub_sel/is_mul/is_div 在 ALU 列、ram_rop/ram_wop 在 MREQ/MEXT 列。

## 二、控制信号说明及宏定义

| 控制信号 | 取值 | 功能说明 | 使用指令 | 宏定义 |
|----------|------|----------|---------|--------|
| **npc_op** | `PC4` | npc = PC + 4 | 全部非跳转/分支 | `` `define NPC_PC4 2'b00 `` |
| | `BRANCH` | npc = br ? PC+offset : PC+4 | beq, bne, blt, bltu, bge, bgeu | `` `define NPC_BRA 2'b10 `` |
| | `JAL` | npc = PC + offset | jal | `` `define NPC_JAL 2'b11 `` |
| | `JALR` | npc = {alu_c[31:1], 1'b0} | jalr | `` `define NPC_JALR 2'b01 `` |
| **rf_we** | `1` | 允许写寄存器 | 全部非store/非branch | — |
| | `0` | 禁止写寄存器 | sb, sh, sw, beq, bne, blt, bltu, bge, bgeu | — |
| **rf_wsel** | `WB_ALU` | wD = ALU.C | R型全部, I型算术逻辑, auipc | `` `define WB_ALU 2'b00 `` |
| | `WB_RAM` | wD = MEXT.ext | lw, lb, lbu, lh, lhu | `` `define WB_RAM 2'b01 `` |
| | `WB_PC4` | wD = NPC.pc4 | jal, jalr | `` `define WB_PC4 2'b10 `` |
| | `WB_EXT` | wD = SEXT.ext | lui | `` `define WB_EXT 2'b11 `` |
| **sext_op** | `I_TYPE` | {{20{imm[31]}}, imm[31:20]} | 全部I型(含load/jalr) | `` `define EXT_I 3'b000 `` |
| | `S_TYPE` | {{20{imm[31]}}, imm[31:25], imm[11:7]} | sb, sh, sw | `` `define EXT_S 3'b001 `` |
| | `B_TYPE` | {{19{imm[31]}}, imm[31], imm[7], imm[30:25], imm[11:8], 1'b0} | 全部B型 | `` `define EXT_B 3'b010 `` |
| | `U_TYPE` | {imm[31:12], 12'h0} | lui, auipc | `` `define EXT_U 3'b011 `` |
| | `J_TYPE` | {{11{imm[31]}}, imm[31], imm[19:12], imm[20], imm[30:21], 1'b0} | jal | `` `define EXT_J 3'b100 `` |
| **alu_op** | `ADD` | C = A + B | add, addi, 全部load/store, jalr, auipc | `` `define ALU_ADD 5'h00 `` |
| | `SUB` | C = A - B | sub | `` `define ALU_SUB 5'h01 `` |
| | `XOR` | C = A ^ B | xor, xori | `` `define ALU_XOR 5'h02 `` |
| | `OR` | C = A \| B | or, ori | `` `define ALU_OR 5'h03 `` |
| | `AND` | C = A & B | and, andi | `` `define ALU_AND 5'h04 `` |
| | `SLL` | C = A << B[4:0] | sll, slli | `` `define ALU_SLL 5'h05 `` |
| | `SRL` | C = A >> B[4:0] (逻辑) | srl, srli | `` `define ALU_SRL 5'h06 `` |
| | `SRA` | C = $signed(A) >>> B[4:0] (算术) | sra, srai | `` `define ALU_SRA 5'h07 `` |
| | `EQ` | br = (A == B) | beq | `` `define ALU_EQ 5'h08 `` |
| | `NE` | br = (A != B) | bne | `` `define ALU_NE 5'h09 `` |
| | `SLT` | br/C = (A < B) 有符号 | slt, slti, blt | `` `define ALU_SLT 5'h0A `` |
| | `SLTU` | br/C = (A < B) 无符号 | sltu, sltiu, bltu | `` `define ALU_SLTU 5'h0B `` |
| | `MUL` | C = (A×B)[31:0] 有符号 | mul | `` `define ALU_MUL 5'h10 `` |
| | `MULH` | C = (A×B)[63:32] 有符号 | mulh | `` `define ALU_MULH 5'h11 `` |
| | `MULHU` | C = (A×B)[63:32] 无符号 | mulhu | `` `define ALU_MULHU 5'h12 `` |
| | `DIV` | C = A / B 有符号 | div | `` `define ALU_DIV 5'h13 `` |
| | `DIVU` | C = A / B 无符号 | divu | `` `define ALU_DIVU 5'h14 `` |
| | `REM` | C = A % B 有符号 | rem | `` `define ALU_REM 5'h15 `` |
| | `REMU` | C = A % B 无符号 | remu | `` `define ALU_REMU 5'h16 `` |
| | `GE` | br = (A >= B) 有符号 | bge | `` `define ALU_GE 5'h17 `` |
| | `GEU` | br = (A >= B) 无符号 | bgeu | `` `define ALU_GEU 5'h18 `` |
| | `-` | 不使用ALU | lui, jal | — |
| **alua_sel** | `ALU_A_RS1` | ALU.A = RF.rD1 | 绝大多数指令 | `` `define ALU_A_RS1 1'b0 `` |
| | `ALU_A_PC` | ALU.A = PC.pc | auipc | `` `define ALU_A_PC 1'b1 `` |
| **alub_sel** | `ALU_B_RS2` | ALU.B = RF.rD2 | 全部R型 + 全部B型 | `` `define ALU_B_RS2 1'b0 `` |
| | `ALU_B_EXT` | ALU.B = SEXT.ext | 全部I型(含load/store) + auipc | `` `define ALU_B_EXT 1'b1 `` |
| **ram_rop** | `0` | 不读访存 | 非load指令 | `` `define RAM_EXT_N 3'b000 `` |
| | `BYTE_EXT` | 读字节, 有符号扩展 | lb | `` `define RAM_EXT_B 3'b001 `` |
| | `BYTEU_EXT` | 读字节, 无符号扩展 | lbu | `` `define RAM_EXT_BU 3'b011 `` |
| | `HALF_EXT` | 读半字, 有符号扩展 | lh | `` `define RAM_EXT_H 3'b100 `` |
| | `HALFU_EXT` | 读半字, 无符号扩展 | lhu | `` `define RAM_EXT_HU 3'b101 `` |
| | `WORD_EXT` | 读字(32位) | lw | `` `define RAM_EXT_W 3'b010 `` |
| **ram_wop** | `0` | 不写访存 | 非store指令 | `` `define RAM_WE_N 4'b0000 `` |
| | `BYTE_WE` | 写字节 | sb | `` `define RAM_WE_B 4'b0001 `` |
| | `HALF_WE` | 写半字 | sh | `` `define RAM_WE_H 4'b0011 `` |
| | `WORD_WE` | 写字 | sw | `` `define RAM_WE_W 4'b1111 `` |
| **is_mul** | `1` | 乘法多周期stall | mul, mulh, mulhu | — |
| | `0` | 非乘法 | 其余全部 | — |
| **is_div** | `1` | 除法多周期stall | div, divu, rem, remu | — |
| | `0` | 非除法 | 其余全部 | — |

## 三、控制信号取值表

| 指令 | opcode | funct3 | funct7 | npc_op | rf_we | rf_wsel | sext_op | alu_op | alub_sel | ram_rop | alua_sel | ram_wop | is_mul | is_div |
|------|--------|--------|--------|--------|-------|---------|---------|--------|-----------|---------|----------|---------|--------|--------|
| addi | 0010011 | 000 | - | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_ADD | ALU_B_EXT | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| ori  | 0010011 | 110 | - | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_OR  | ALU_B_EXT | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| slli | 0010011 | 001 | 0000000 | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_SLL | ALU_B_EXT | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| xori | 0010011 | 100 | - | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_XOR | ALU_B_EXT | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| srli | 0010011 | 101 | 0000000 | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_SRL | ALU_B_EXT | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| srai | 0010011 | 101 | 0100000 | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_SRA | ALU_B_EXT | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| andi | 0010011 | 111 | - | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_AND | ALU_B_EXT | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| slti | 0010011 | 010 | - | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_SLT | ALU_B_EXT | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| sltiu| 0010011 | 011 | - | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_SLTU| ALU_B_EXT | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| lw   | 0000011 | 010 | - | NPC_PC4 | 1 | WB_RAM | EXT_I | ALU_ADD | ALU_B_EXT | RAM_EXT_W | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| lb   | 0000011 | 000 | - | NPC_PC4 | 1 | WB_RAM | EXT_I | ALU_ADD | ALU_B_EXT | RAM_EXT_B | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| lbu  | 0000011 | 100 | - | NPC_PC4 | 1 | WB_RAM | EXT_I | ALU_ADD | ALU_B_EXT | RAM_EXT_BU| ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| lh   | 0000011 | 001 | - | NPC_PC4 | 1 | WB_RAM | EXT_I | ALU_ADD | ALU_B_EXT | RAM_EXT_H | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| lhu  | 0000011 | 101 | - | NPC_PC4 | 1 | WB_RAM | EXT_I | ALU_ADD | ALU_B_EXT | RAM_EXT_HU| ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| sb | 0100011 | 000 | - | NPC_PC4 | 0 | - | EXT_S | ALU_ADD | ALU_B_EXT | RAM_EXT_N | ALU_A_RS1 | RAM_WE_B | 0 | 0 |
| sh | 0100011 | 001 | - | NPC_PC4 | 0 | - | EXT_S | ALU_ADD | ALU_B_EXT | RAM_EXT_N | ALU_A_RS1 | RAM_WE_H | 0 | 0 |
| sw | 0100011 | 010 | - | NPC_PC4 | 0 | - | EXT_S | ALU_ADD | ALU_B_EXT | RAM_EXT_N | ALU_A_RS1 | RAM_WE_W | 0 | 0 |
| add | 0110011 | 000 | 0000000 | NPC_PC4 | 1 | WB_ALU | - | ALU_ADD | ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| sub | 0110011 | 000 | 0100000 | NPC_PC4 | 1 | WB_ALU | - | ALU_SUB | ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| xor | 0110011 | 100 | 0000000 | NPC_PC4 | 1 | WB_ALU | - | ALU_XOR | ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| sll | 0110011 | 001 | 0000000 | NPC_PC4 | 1 | WB_ALU | - | ALU_SLL | ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| srl | 0110011 | 101 | 0000000 | NPC_PC4 | 1 | WB_ALU | - | ALU_SRL | ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| sra | 0110011 | 101 | 0100000 | NPC_PC4 | 1 | WB_ALU | - | ALU_SRA | ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| and | 0110011 | 111 | 0000000 | NPC_PC4 | 1 | WB_ALU | - | ALU_AND | ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| or  | 0110011 | 110 | 0000000 | NPC_PC4 | 1 | WB_ALU | - | ALU_OR  | ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| slt | 0110011 | 010 | 0000000 | NPC_PC4 | 1 | WB_ALU | - | ALU_SLT | ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| sltu| 0110011 | 011 | 0000000 | NPC_PC4 | 1 | WB_ALU | - | ALU_SLTU| ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| mul | 0110011 | 000 | 0000001 | NPC_PC4 | 1 | WB_ALU | - | ALU_MUL | ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 1 | 0 |
| mulh| 0110011 | 001 | 0000001 | NPC_PC4 | 1 | WB_ALU | - | ALU_MULH| ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 1 | 0 |
| mulhu|0110011 | 011 | 0000001 | NPC_PC4 | 1 | WB_ALU | - | ALU_MULHU|ALU_B_RS2| RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 1 | 0 |
| div | 0110011 | 100 | 0000001 | NPC_PC4 | 1 | WB_ALU | - | ALU_DIV | ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 1 |
| divu| 0110011 | 101 | 0000001 | NPC_PC4 | 1 | WB_ALU | - | ALU_DIVU| ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 1 |
| rem | 0110011 | 110 | 0000001 | NPC_PC4 | 1 | WB_ALU | - | ALU_REM | ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 1 |
| remu| 0110011 | 111 | 0000001 | NPC_PC4 | 1 | WB_ALU | - | ALU_REMU| ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 1 |
| beq  | 1100011 | 000 | - | NPC_BRA | 0 | - | EXT_B | ALU_EQ  | ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| bne  | 1100011 | 001 | - | NPC_BRA | 0 | - | EXT_B | ALU_NE  | ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| blt  | 1100011 | 100 | - | NPC_BRA | 0 | - | EXT_B | ALU_SLT | ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| bltu | 1100011 | 110 | - | NPC_BRA | 0 | - | EXT_B | ALU_SLTU| ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| bge  | 1100011 | 101 | - | NPC_BRA | 0 | - | EXT_B | ALU_GE  | ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| bgeu | 1100011 | 111 | - | NPC_BRA | 0 | - | EXT_B | ALU_GEU | ALU_B_RS2 | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |
| lui   | 0110111 | - | - | NPC_PC4 | 1 | WB_EXT | EXT_U | -        | -         | RAM_EXT_N | -         | RAM_WE_N | 0 | 0 |
| auipc | 0010111 | - | - | NPC_PC4 | 1 | WB_ALU | EXT_U | ALU_ADD | ALU_B_EXT | RAM_EXT_N | ALU_A_PC  | RAM_WE_N | 0 | 0 |
| jal | 1101111 | - | - | NPC_JAL | 1 | WB_PC4 | EXT_J | -        | -         | RAM_EXT_N | -         | RAM_WE_N | 0 | 0 |
| jalr| 1100111 | 000 | - | NPC_JALR| 1 | WB_PC4 | EXT_I | ALU_ADD | ALU_B_EXT | RAM_EXT_N | ALU_A_RS1 | RAM_WE_N | 0 | 0 |

> `-` = don't-care。

## 实现注意事项

### Store 写掩码与地址对齐

`RAM_WE_B` (0001)、`RAM_WE_H` (0011) 仅表示写类型，**实际字节使能必须由 MREQ 结合 `ram_addr[1:0]` 产生**：

| 指令 | addr[1:0] | da_wen | da_wdata 处理 |
|------|-----------|--------|-------------|
| sb | 0 | 4'b0001 | wdata[7:0] 在 byte 0 |
| sb | 1 | 4'b0010 | wdata[7:0] << 8 |
| sb | 2 | 4'b0100 | wdata[7:0] << 16 |
| sb | 3 | 4'b1000 | wdata[7:0] << 24 |
| sh | 0 | 4'b0011 | wdata[15:0] 在 half 0 |
| sh | 2 | 4'b1100 | wdata[15:0] << 16 |
| sw | 0 | 4'b1111 | wdata 直通 |

### 移位量 B[4:0]

ALU 中所有移位操作仅使用 `B[4:0]`。SRAI 的 I 型立即数高 7 位是 `0100000`，必须掩码。

### 乘除法多周期机制

乘除法使用多周期 stall 架构（模板已实现）：

| 阶段 | 信号/动作 |
|------|----------|
| 译码 | `is_mul=1` 或 `is_div=1` → `is_mul_div` 有效 |
| 进入 stall | `mul_div_flag` 拉高，目标寄存器 `rf_wR_r` 锁存 |
| 等待完成 | ALU 内部乘法器/除法器 `start` 启动，`busy` 拉高 |
| 运算完成 | `mul_div_busy` 下降 → `inst_finished` 有效 → `rf_we1` 写回 |

控制信号取值表中只需要 `is_mul`/`is_div`。`start`/`busy`/`done` 是 ALU 内部子模块（multiplier/divider）的接口信号，不在顶层控制信号表中。
