# miniRV 全指令控制信号设计（44条）

> 约定：`X.y` = 部件X的输出信号y，`IN.xxx` = CPU输入信号，`-` = 不使用 / don't-care

## 一、数据通路表

| 单元 | 取指单元 | | | | 译码单元 | | | | | 执行单元 | | 存储单元 | | | |
|------|----------|--|--|--|----------|--|--|--|--|----------|--|----------|--|--|--|
| 部件 | PC | NPC | | | RF | | | | SEXT | ALU | | MREQ | | MEXT | |
| 输入 | npc | PC | offset | br | rR1 | rR2 | wR | wD | imm | A | B | addr | wd | din | b_offs |
| addi | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | I:inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| ori | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | I:inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| slli | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | I:inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| xori | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | I:inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| srli | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | I:inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| srai | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | I:inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| andi | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | I:inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| slti | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | I:inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| sltiu | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | I:inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
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
| lw | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | MEXT.ext | I:inst[31:20] | RF.rD1 | SEXT.ext | ALU.C | - | IN.rd | ALU.C[1:0] |
| lb | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | MEXT.ext | I:inst[31:20] | RF.rD1 | SEXT.ext | ALU.C | - | IN.rd | ALU.C[1:0] |
| lbu | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | MEXT.ext | I:inst[31:20] | RF.rD1 | SEXT.ext | ALU.C | - | IN.rd | ALU.C[1:0] |
| lh | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | MEXT.ext | I:inst[31:20] | RF.rD1 | SEXT.ext | ALU.C | - | IN.rd | ALU.C[1:0] |
| lhu | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | MEXT.ext | I:inst[31:20] | RF.rD1 | SEXT.ext | ALU.C | - | IN.rd | ALU.C[1:0] |
| sb | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | - | - | I:inst[31:20] | RF.rD1 | SEXT.ext | ALU.C | RF.rD2 | - | - |
| sh | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | - | - | I:inst[31:20] | RF.rD1 | SEXT.ext | ALU.C | RF.rD2 | - | - |
| sw | NPC.npc | PC.pc | - | - | IN.inst[19:15] | IN.inst[24:20] | - | - | I:inst[31:20] | RF.rD1 | SEXT.ext | ALU.C | RF.rD2 | - | - |
| beq | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | - | - | B:inst[31\|7\|30:25\|11:8] | RF.rD1 | RF.rD2 | - | - | - | - |
| bne | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | - | - | B:inst[31\|7\|30:25\|11:8] | RF.rD1 | RF.rD2 | - | - | - | - |
| blt | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | - | - | B:inst[31\|7\|30:25\|11:8] | RF.rD1 | RF.rD2 | - | - | - | - |
| bltu | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | - | - | B:inst[31\|7\|30:25\|11:8] | RF.rD1 | RF.rD2 | - | - | - | - |
| bge | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | - | - | B:inst[31\|7\|30:25\|11:8] | RF.rD1 | RF.rD2 | - | - | - | - |
| bgeu | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | - | - | B:inst[31\|7\|30:25\|11:8] | RF.rD1 | RF.rD2 | - | - | - | - |
| lui | NPC.npc | PC.pc | - | - | - | - | IN.inst[11:7] | SEXT.ext | U:inst[31:12] | - | - | - | - | - | - |
| auipc | NPC.npc | PC.pc | - | - | - | - | IN.inst[11:7] | ALU.C | U:inst[31:12] | PC | SEXT.ext | - | - | - | - |
| jal | NPC.npc | PC.pc | SEXT.ext | - | - | - | IN.inst[11:7] | NPC.pc4 | J:inst[31\|19:12\|20\|30:21] | - | - | - | - | - | - |
| jalr | NPC.npc | PC.pc | SEXT.ext | - | IN.inst[19:15] | - | IN.inst[11:7] | NPC.pc4 | I:inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| **综合** | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | I:inst[31:20] | RF.rD1 | RF.rD2 | ALU.C | RF.rD2 | IN.rd | ALU.C[1:0] |
| | | | | | | | | SEXT.ext | U:inst[31:12] | PC | SEXT.ext | | | | |
| | | | | | | | | MEXT.ext | B:inst[31\|7\|30:25\|11:8] | | | | | | |
| | | | | | | | | NPC.pc4 | J:inst[31\|19:12\|20\|30:21] | | | | | | |
| **引出** | npc_op | - | - | - | - | - | rf_we | rf_wsel | sext_op | alua_sel | alub_sel | - | ram_wop | - | ram_rop |
| | | | | | | | | | | alu_op | | | | | |
| | | | | | | | | | | is_mul | | | | | |
| | | | | | | | | | | is_div | | | | | |

## 二、控制信号说明及宏定义

| 控制信号 | 取值 | 功能说明 | 使用指令 | 宏定义 |
|----------|------|----------|---------|--------|
| **npc_op** | `NPC_PC4` | npc = PC + 4（顺序执行） | 全部非跳转/分支 | `` `define NPC_PC4 2'b00 `` |
| | `NPC_BRA` | npc = br ? PC+offset : PC+4（条件分支） | beq, bne, blt, bltu, bge, bgeu | `` `define NPC_BRA 2'b10 `` |
| | `NPC_JMP` | npc = PC + offset（无条件跳转） | jal, jalr | `` `define NPC_JMP 2'b11 `` |
| **rf_we** | `1'b1` | 允许写寄存器 | 全部非store/非branch | — |
| | `1'b0` | 禁止写寄存器 | sb, sh, sw, beq, bne, blt, bltu, bge, bgeu | — |
| **rf_wsel** | `WB_ALU` | wD = ALU.C | R型全部, I型算术逻辑, auipc | `` `define WB_ALU 2'b00 `` |
| | `WB_RAM` | wD = MEXT.ext | lw, lb, lbu, lh, lhu | `` `define WB_RAM 2'b01 `` |
| | `WB_PC4` | wD = NPC.pc4 | jal, jalr | `` `define WB_PC4 2'b10 `` |
| | `WB_EXT` | wD = SEXT.ext | lui | `` `define WB_EXT 2'b11 `` |
| **sext_op** | `EXT_I` | {{20{imm[31]}}, imm[31:20]} | 全部I型 + 全部S型 | `` `define EXT_I 3'b000 `` |
| | `EXT_B` | {{19{imm[31]}}, imm[31], imm[7], imm[30:25], imm[11:8], 1'b0} | 全部B型 | `` `define EXT_B 3'b010 `` |
| | `EXT_U` | {imm[31:12], 12'h0} | lui, auipc | `` `define EXT_U 3'b011 `` |
| | `EXT_J` | {{11{imm[31]}}, imm[31], imm[19:12], imm[20], imm[30:21], 1'b0} | jal | `` `define EXT_J 3'b100 `` |
| **alu_op** | `ALU_ADD` | C = A + B | add, addi, 全部load/store, jalr, auipc | `` `define ALU_ADD 5'h00 `` |
| | `ALU_SUB` | C = A - B | sub | `` `define ALU_SUB 5'h01 `` |
| | `ALU_XOR` | C = A ^ B | xor, xori | `` `define ALU_XOR 5'h02 `` |
| | `ALU_OR` | C = A \| B | or, ori | `` `define ALU_OR 5'h03 `` |
| | `ALU_AND` | C = A & B | and, andi | `` `define ALU_AND 5'h04 `` |
| | `ALU_SLL` | C = A << B[4:0] | sll, slli | `` `define ALU_SLL 5'h05 `` |
| | `ALU_SRL` | C = A >> B[4:0] (逻辑) | srl, srli | `` `define ALU_SRL 5'h06 `` |
| | `ALU_SRA` | C = A >>> B[4:0] (算术) | sra, srai | `` `define ALU_SRA 5'h07 `` |
| | `ALU_EQ` | br = (A == B) | beq | `` `define ALU_EQ 5'h08 `` |
| | `ALU_NE` | br = (A != B) | bne | `` `define ALU_NE 5'h09 `` |
| | `ALU_SLT` | br/C = (A < B) 有符号 | slt, slti, blt | `` `define ALU_SLT 5'h0A `` |
| | `ALU_SLTU` | br/C = (A < B) 无符号 | sltu, sltiu, bltu | `` `define ALU_SLTU 5'h0B `` |
| | `ALU_MUL` | C = (A×B)[31:0] 有符号 | mul | `` `define ALU_MUL 5'h10 `` |
| | `ALU_MULH` | C = (A×B)[63:32] 有符号 | mulh | `` `define ALU_MULH 5'h11 `` |
| | `ALU_MULHU` | C = (A×B)[63:32] 无符号 | mulhu | `` `define ALU_MULHU 5'h12 `` |
| | `ALU_DIV` | C = A / B 有符号 | div | `` `define ALU_DIV 5'h13 `` |
| | `ALU_DIVU` | C = A / B 无符号 | divu | `` `define ALU_DIVU 5'h14 `` |
| | `ALU_REM` | C = A % B 有符号 | rem | `` `define ALU_REM 5'h15 `` |
| | `ALU_REMU` | C = A % B 无符号 | remu | `` `define ALU_REMU 5'h16 `` |
| | `ALU_GE` | br = (A >= B) 有符号 (≡ !SLT) | bge | `` `define ALU_GE 5'h17 `` |
| | `ALU_GEU` | br = (A >= B) 无符号 (≡ !SLTU) | bgeu | `` `define ALU_GEU 5'h18 `` |
| | `-` | 不使用ALU | lui, jal | (不需要) |
| **alua_sel** | `ALU_A_RS1` | ALU.A = RF.rD1 | 绝大多数指令 | `` `define ALU_A_RS1 1'b0 `` |
| | `ALU_A_PC` | ALU.A = PC | auipc | `` `define ALU_A_PC 1'b1 `` |
| **alub_sel** | `ALU_B_RS2` | ALU.B = RF.rD2 | 全部R型 + 全部B型 | `` `define ALU_B_RS2 1'b0 `` |
| | `ALU_B_EXT` | ALU.B = SEXT.ext | 全部I型(含load/store) + auipc | `` `define ALU_B_EXT 1'b1 `` |
| **ram_rop** | `RAM_EXT_N` | 不读访存 | 非load指令 | `` `define RAM_EXT_N 3'b000 `` |
| | `RAM_EXT_B` | 读字节, 有符号扩展 | lb | `` `define RAM_EXT_B 3'b001 `` |
| | `RAM_EXT_BU` | 读字节, 无符号扩展 | lbu | `` `define RAM_EXT_BU 3'b011 `` |
| | `RAM_EXT_H` | 读半字, 有符号扩展 | lh | `` `define RAM_EXT_H 3'b100 `` |
| | `RAM_EXT_HU` | 读半字, 无符号扩展 | lhu | `` `define RAM_EXT_HU 3'b101 `` |
| | `RAM_EXT_W` | 读字(32位) | lw | `` `define RAM_EXT_W 3'b010 `` |
| **ram_wop** | `RAM_WE_N` | 不写访存 | 非store指令 | `` `define RAM_WE_N 4'b0000 `` |
| | `RAM_WE_B` | 写字节 | sb | `` `define RAM_WE_B 4'b0001 `` |
| | `RAM_WE_H` | 写半字 | sh | `` `define RAM_WE_H 4'b0011 `` |
| | `RAM_WE_W` | 写字 | sw | `` `define RAM_WE_W 4'b1111 `` |
| **is_mul** | `1'b1` | 乘法多周期stall | mul, mulh, mulhu | — |
| | `1'b0` | 非乘法 | 其余全部 | — |
| **is_div** | `1'b1` | 除法多周期stall | div, divu, rem, remu | — |
| | `1'b0` | 非除法 | 其余全部 | — |

## 三、控制信号取值表

### R-类型 (17条) — opcode=0110011

| 指令 | funct3 | funct7 | npc_op | rf_we | rf_wsel | sext_op | alu_op | alua_sel | alub_sel | ram_rop | ram_wop | is_mul | is_div |
|------|--------|--------|--------|-------|---------|---------|--------|----------|----------|---------|---------|--------|--------|
| add | 000 | 0000000 | NPC_PC4 | 1 | WB_ALU | - | ALU_ADD | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| sub | 000 | 0100000 | NPC_PC4 | 1 | WB_ALU | - | ALU_SUB | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| xor | 100 | 0000000 | NPC_PC4 | 1 | WB_ALU | - | ALU_XOR | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| sll | 001 | 0000000 | NPC_PC4 | 1 | WB_ALU | - | ALU_SLL | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| srl | 101 | 0000000 | NPC_PC4 | 1 | WB_ALU | - | ALU_SRL | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| sra | 101 | 0100000 | NPC_PC4 | 1 | WB_ALU | - | ALU_SRA | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| and | 111 | 0000000 | NPC_PC4 | 1 | WB_ALU | - | ALU_AND | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| or  | 110 | 0000000 | NPC_PC4 | 1 | WB_ALU | - | ALU_OR  | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| slt | 010 | 0000000 | NPC_PC4 | 1 | WB_ALU | - | ALU_SLT | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| sltu| 011 | 0000000 | NPC_PC4 | 1 | WB_ALU | - | ALU_SLTU| ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| mul | 000 | 0000001 | NPC_PC4 | 1 | WB_ALU | - | ALU_MUL | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 1 | 0 |
| mulh| 001 | 0000001 | NPC_PC4 | 1 | WB_ALU | - | ALU_MULH| ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 1 | 0 |
| mulhu|011 | 0000001 | NPC_PC4 | 1 | WB_ALU | - | ALU_MULHU|ALU_A_RS1| ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 1 | 0 |
| div | 100 | 0000001 | NPC_PC4 | 1 | WB_ALU | - | ALU_DIV | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 1 |
| divu| 101 | 0000001 | NPC_PC4 | 1 | WB_ALU | - | ALU_DIVU| ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 1 |
| rem | 110 | 0000001 | NPC_PC4 | 1 | WB_ALU | - | ALU_REM | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 1 |
| remu| 111 | 0000001 | NPC_PC4 | 1 | WB_ALU | - | ALU_REMU| ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 1 |

### I-类型 (15条)

| 指令 | opcode | funct3 | funct7 | npc_op | rf_we | rf_wsel | sext_op | alu_op | alua_sel | alub_sel | ram_rop | ram_wop | is_mul | is_div |
|------|--------|--------|--------|--------|-------|---------|---------|--------|----------|----------|---------|---------|--------|--------|
| addi | 0010011 | 000 | - | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_ADD | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| ori  | 0010011 | 110 | - | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_OR  | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| slli | 0010011 | 001 | 0000000 | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_SLL | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| xori | 0010011 | 100 | - | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_XOR | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| srli | 0010011 | 101 | 0000000 | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_SRL | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| srai | 0010011 | 101 | 0100000 | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_SRA | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| andi | 0010011 | 111 | - | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_AND | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| slti | 0010011 | 010 | - | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_SLT | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| sltiu| 0010011 | 011 | - | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_SLTU| ALU_A_RS1 | ALU_B_EXT | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| lw   | 0000011 | 010 | - | NPC_PC4 | 1 | WB_RAM | EXT_I | ALU_ADD | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_W | RAM_WE_N | 0 | 0 |
| lb   | 0000011 | 000 | - | NPC_PC4 | 1 | WB_RAM | EXT_I | ALU_ADD | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_B | RAM_WE_N | 0 | 0 |
| lbu  | 0000011 | 100 | - | NPC_PC4 | 1 | WB_RAM | EXT_I | ALU_ADD | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_BU| RAM_WE_N | 0 | 0 |
| lh   | 0000011 | 001 | - | NPC_PC4 | 1 | WB_RAM | EXT_I | ALU_ADD | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_H | RAM_WE_N | 0 | 0 |
| lhu  | 0000011 | 101 | - | NPC_PC4 | 1 | WB_RAM | EXT_I | ALU_ADD | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_HU| RAM_WE_N | 0 | 0 |
| jalr | 1100111 | 000 | - | NPC_JMP | 1 | WB_PC4 | EXT_I | ALU_ADD | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_N | RAM_WE_N | 0 | 0 |

### S-类型 (3条) — opcode=0100011

| 指令 | funct3 | npc_op | rf_we | rf_wsel | sext_op | alu_op | alua_sel | alub_sel | ram_rop | ram_wop | is_mul | is_div |
|------|--------|--------|-------|---------|---------|--------|----------|----------|---------|---------|--------|--------|
| sb | 000 | NPC_PC4 | 0 | - | EXT_I | ALU_ADD | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_N | RAM_WE_B | 0 | 0 |
| sh | 001 | NPC_PC4 | 0 | - | EXT_I | ALU_ADD | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_N | RAM_WE_H | 0 | 0 |
| sw | 010 | NPC_PC4 | 0 | - | EXT_I | ALU_ADD | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_N | RAM_WE_W | 0 | 0 |

### B-类型 (6条) — opcode=1100011

| 指令 | funct3 | npc_op | rf_we | rf_wsel | sext_op | alu_op | alua_sel | alub_sel | ram_rop | ram_wop | is_mul | is_div |
|------|--------|--------|-------|---------|---------|--------|----------|----------|---------|---------|--------|--------|
| beq  | 000 | NPC_BRA | 0 | - | EXT_B | ALU_EQ  | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| bne  | 001 | NPC_BRA | 0 | - | EXT_B | ALU_NE  | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| blt  | 100 | NPC_BRA | 0 | - | EXT_B | ALU_SLT | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| bltu | 110 | NPC_BRA | 0 | - | EXT_B | ALU_SLTU| ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| bge  | 101 | NPC_BRA | 0 | - | EXT_B | ALU_GE  | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| bgeu | 111 | NPC_BRA | 0 | - | EXT_B | ALU_GEU | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N | 0 | 0 |

### U-类型 (2条)

| 指令 | opcode | npc_op | rf_we | rf_wsel | sext_op | alu_op | alua_sel | alub_sel | ram_rop | ram_wop | is_mul | is_div |
|------|--------|--------|-------|---------|---------|--------|----------|----------|---------|---------|--------|--------|
| lui   | 0110111 | NPC_PC4 | 1 | WB_EXT | EXT_U | -        | -         | -         | RAM_EXT_N | RAM_WE_N | 0 | 0 |
| auipc | 0010111 | NPC_PC4 | 1 | WB_ALU | EXT_U | ALU_ADD | ALU_A_PC  | ALU_B_EXT | RAM_EXT_N | RAM_WE_N | 0 | 0 |

### J-类型 (1条) — opcode=1101111

| 指令 | npc_op | rf_we | rf_wsel | sext_op | alu_op | alua_sel | alub_sel | ram_rop | ram_wop | is_mul | is_div |
|------|--------|-------|---------|---------|--------|----------|----------|---------|---------|--------|--------|
| jal | NPC_JMP | 1 | WB_PC4 | EXT_J | - | - | - | RAM_EXT_N | RAM_WE_N | 0 | 0 |
