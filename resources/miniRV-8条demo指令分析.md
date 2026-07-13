# miniRV 8条demo指令分析

> 已实现指令：`addi`, `ori`, `slli`, `lui`, `lw`, `beq`, `bne`, `jal`
> 约定：`X.y` = 部件X的输出信号y，`IN.xxx` = CPU输入信号，`-` = 不使用

## 一、数据通路表

| 单元 | 取指单元 | | | | 译码单元 | | | | | 执行单元 | | 存储单元 | | | |
|------|----------|--|--|--|----------|--|--|--|--|----------|--|----------|--|--|--|
| 部件 | PC | NPC | | | RF | | | | SEXT | ALU | | MREQ | | MEXT | |
| 输入 | npc | PC | offset | br | rR1 | rR2 | wR | wD | imm | A | B | addr | wd | din | b_offs |
| addi | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | IN.inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| ori | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | IN.inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| slli | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | IN.inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| lui | NPC.npc | PC.pc | - | - | - | - | IN.inst[11:7] | SEXT.ext | IN.inst[31:12] | - | - | - | - | - | - |
| lw | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | MEXT.ext | IN.inst[31:20] | RF.rD1 | SEXT.ext | ALU.C | - | IN.rd | ALU.C[1:0] |
| beq | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | - | - | IN.inst[31\|7\|30:25\|11:8] | RF.rD1 | RF.rD2 | - | - | - | - |
| bne | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | - | - | IN.inst[31\|7\|30:25\|11:8] | RF.rD1 | RF.rD2 | - | - | - | - |
| jal | NPC.npc | PC.pc | SEXT.ext | - | - | - | IN.inst[11:7] | NPC.pc4 | IN.inst[31\|19:12\|20\|30:21] | - | - | - | - | - | - |
| **综合** | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C | I:inst[31:20] | RF.rD1 | RF.rD2 | ALU.C | - | IN.rd | ALU.C[1:0] |
| | | | | | | | | SEXT.ext | U:inst[31:12] | | SEXT.ext | | | | |
| | | | | | | | | MEXT.ext | B:inst[31\|7\|30:25\|11:8] | | | | | | |
| | | | | | | | | NPC.pc4 | J:inst[31\|19:12\|20\|30:21] | | | | | | |
| **引出控制信号** | - | - | - | - | - | - | - | **rf_wsel** | **sext_op** | **alua_sel** | **alub_sel** | - | - | - | - |
| **引出控制信号** | **npc_op** (offset/br组合) | | | | **rf_we** | | | | | **alu_op** | | **ram_rop** | | **ram_rop** | |

## 二、控制信号说明及宏定义

| 控制信号 | 所属部件 | 取值 | 功能说明 | 使用的指令 | 宏定义 |
|----------|----------|------|----------|-----------|--------|
| **npc_op** | NPC | `NPC_PC4` | 下条地址 = PC + 4（顺序执行） | addi, ori, slli, lui, lw | `` `define NPC_PC4 2'b00 `` |
| | | `NPC_BRA` | 下条地址 = br ? PC+offset : PC+4（条件分支） | beq, bne | `` `define NPC_BRA 2'b10 `` |
| | | `NPC_JMP` | 下条地址 = PC + offset（无条件跳转） | jal | `` `define NPC_JMP 2'b11 `` |
| **rf_we** | RF | `1'b1` | 允许写寄存器 | addi, ori, slli, lui, lw, jal | (直接使用1/0) |
| | | `1'b0` | 禁止写寄存器 | beq, bne | |
| **rf_wsel** | RF(wD MUX) | `WB_ALU` | wD = ALU.C（ALU运算结果） | addi, ori, slli | `` `define WB_ALU 2'b00 `` |
| | | `WB_RAM` | wD = MEXT.ext（主存读出数据） | lw | `` `define WB_RAM 2'b01 `` |
| | | `WB_PC4` | wD = NPC.pc4（返回地址PC+4） | jal | `` `define WB_PC4 2'b10 `` |
| | | `WB_EXT` | wD = SEXT.ext（立即数扩展结果） | lui | `` `define WB_EXT 2'b11 `` |
| **sext_op** | SEXT | `EXT_I` | I型扩展：{{20{imm[31]}}, imm[31:20]} | addi, ori, slli, lw | `` `define EXT_I 3'b000 `` |
| | | `EXT_B` | B型扩展：{{19{imm[31]}}, imm[31], imm[7], imm[30:25], imm[11:8], 1'b0} | beq, bne | `` `define EXT_B 3'b010 `` |
| | | `EXT_U` | U型扩展：{imm[31:12], 12'h0} | lui | `` `define EXT_U 3'b011 `` |
| | | `EXT_J` | J型扩展：{{11{imm[31]}}, imm[31], imm[19:12], imm[20], imm[30:21], 1'b0} | jal | `` `define EXT_J 3'b100 `` |
| **alu_op** | ALU | `ALU_ADD` | 加法：C = A + B | addi, lw | `` `define ALU_ADD 5'h00 `` |
| | | `ALU_OR` | 按位或：C = A \| B | ori | `` `define ALU_OR 5'h03 `` |
| | | `ALU_SLL` | 逻辑左移：C = A << B[4:0] | slli | `` `define ALU_SLL 5'h05 `` |
| | | `ALU_EQ` | 相等比较：br = (A == B) | beq | `` `define ALU_EQ 5'h08 `` |
| | | `ALU_NE` | 不等比较：br = (A != B) | bne | `` `define ALU_NE 5'h09 `` |
| | | `-` | 不使用ALU | lui, jal | (不需要) |
| **alua_sel** | ALU(A MUX) | `ALU_A_RS1` | ALU.A = RF.rD1 | addi, ori, slli, lw, beq, bne | `` `define ALU_A_RS1 1'b0 `` |
| | | `ALU_A_PC` | ALU.A = PC | (8条demo中未使用) | `` `define ALU_A_PC 1'b1 `` |
| **alub_sel** | ALU(B MUX) | `ALU_B_RS2` | ALU.B = RF.rD2 | beq, bne | `` `define ALU_B_RS2 1'b0 `` |
| | | `ALU_B_EXT` | ALU.B = SEXT.ext | addi, ori, slli, lw | `` `define ALU_B_EXT 1'b1 `` |
| **ram_rop** | MREQ/MEXT | `RAM_EXT_N` | 不读访存 | addi, ori, slli, lui, beq, bne, jal | `` `define RAM_EXT_N 3'b000 `` |
| | | `RAM_EXT_W` | 读字（32位），MEXT直通 | lw | `` `define RAM_EXT_W 3'b010 `` |
| **ram_wop** | MREQ | `RAM_WE_N` | 不写访存 | 全部8条demo指令 | `` `define RAM_WE_N 4'b0000 `` |

## 三、控制信号取值表

| 指令 | opcode | funct3 | funct7 | npc_op | rf_we | rf_wsel | sext_op | alu_op | alua_sel | alub_sel | ram_rop | ram_wop |
|------|--------|--------|--------|--------|-------|---------|---------|--------|----------|----------|---------|---------|
| addi | 0010011 | 000 | - | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_ADD | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_N | RAM_WE_N |
| ori  | 0010011 | 110 | - | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_OR  | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_N | RAM_WE_N |
| slli | 0010011 | 001 | 0000000 | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_SLL | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_N | RAM_WE_N |
| lui  | 0110111 | - | - | NPC_PC4 | 1 | WB_EXT | EXT_U | -        | -         | -         | RAM_EXT_N | RAM_WE_N |
| lw   | 0000011 | 010 | - | NPC_PC4 | 1 | WB_RAM | EXT_I | ALU_ADD | ALU_A_RS1 | ALU_B_EXT | RAM_EXT_W | RAM_WE_N |
| beq  | 1100011 | 000 | - | NPC_BRA | 0 | -      | EXT_B | ALU_EQ  | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N |
| bne  | 1100011 | 001 | - | NPC_BRA | 0 | -      | EXT_B | ALU_NE  | ALU_A_RS1 | ALU_B_RS2 | RAM_EXT_N | RAM_WE_N |
| jal  | 1101111 | - | - | NPC_JMP | 1 | WB_PC4 | EXT_J | -        | -         | -         | RAM_EXT_N | RAM_WE_N |

> `-` 表示该指令不使用此信号，取值可为任意（don't-care）。
