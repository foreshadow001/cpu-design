# miniRV 控制信号取值表

> 方法论：数据通路表 → 多输入源分析 → 控制信号提取 → 按指令填取值
> A组 = 浅蓝 (18条)，B组 = 浅橙 (18条)，绿色 = demo已实现 (8条)

---

## 1. 数据通路表 — 5条demo指令

符号约定：`X.y` = 部件X的输出信号y，`IN.xxx` = CPU输入信号，`-` = 不使用。

| 单元 | 取指单元 | | | | 译码单元 | | | | | 执行单元 | | 存储单元 | | | |
|------|----------|--|--|--|----------|--|--|--|--|----------|--|----------|--|--|--|
| 部件 | PC | NPC | | | RF | | | | SEXT | ALU | | MREQ | | MEXT | |
| 输入 | npc | PC | offset | br | rR1 | rR2 | wR | wD | imm | A | B | addr | wd | din | b_offs |
| ori | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | IN.inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| lui | NPC.npc | PC.pc | - | - | - | - | IN.inst[11:7] | SEXT.ext | IN.inst[31:12] | - | - | - | - | - | - |
| lw | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | MEXT.ext | IN.inst[31:20] | RF.rD1 | SEXT.ext | ALU.C | - | IN.rd | ALU.C[1:0] |
| beq | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | - | - | IN.inst[31\|7\|30:25\|11:8] | RF.rD1 | RF.rD2 | - | - | - | - |
| jal | NPC.npc | PC.pc | SEXT.ext | - | - | - | IN.inst[11:7] | NPC.pc4 | IN.inst[31\|19:12\|20\|30:21] | - | - | - | - | - | - |

## 2. 综合数据通路 — 合并所有行

| 单元 | 取指单元 | | | | 译码单元 | | | | | 执行单元 | | 存储单元 | | | |
|------|----------|--|--|--|----------|--|--|--|--|----------|--|----------|--|--|--|
| 部件 | PC | NPC | | | RF | | | | SEXT | ALU | | MREQ | | MEXT | |
| 输入 | npc | PC | offset | br | rR1 | rR2 | wR | wD | imm | A | B | addr | wd | din | b_offs |
| 完整 | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | **4源↓** | **4格式↓** | **2源↓** | **2源↓** | ALU.C | - | IN.rd | ALU.C[1:0] |
| 来源1 | | | | | | | | ALU.C | I: inst[31:20] | RF.rD1 | RF.rD2 | | | | |
| 来源2 | | | | | | | | SEXT.ext | U: inst[31:12] | PC (auipc用) | SEXT.ext | | | | |
| 来源3 | | | | | | | | MEXT.ext | B: inst[31\|7\|30:25\|11:8] | | | | | | |
| 来源4 | | | | | | | | NPC.pc4 | J: inst[31\|19:12\|20\|30:21] | | | | | | |
| MUX? | 无 | 无 | 无 | 无 | 无 | 无 | 无 | **→ rf_wsel** | **→ sext_op** | **→ alua_sel** | **→ alub_sel** | 无 | 无 | 无 | 无 |

## 3. 控制信号提取

### 3.1 从 NPC 列提取 npc_op

观察 offset 和 br 列：

| 数据通路特征 | 指令举例 | npc_op | 编码 |
|-------------|----------|--------|------|
| offset=- , br=- (只用PC) | addi, ori, lw, lui, add, sub... | NPC_PC4 | 2'b00 |
| offset=SEXT.ext, br=ALU.br (条件) | beq, bne, blt, bltu, bge, bgeu | NPC_BRA | 2'b10 |
| offset=SEXT.ext, br=- (无条件) | jal, jalr | NPC_JMP | 2'b11 |

### 3.2 从 RF.wD 列提取 rf_wsel 和 rf_we

| wD 来源 | 指令类型 | rf_wsel | 编码 |
|----------|----------|---------|------|
| ALU.C | R型、I型算术逻辑、auipc | WB_ALU | 2'b00 |
| MEXT.ext | load指令 (lw, lb, lbu, lh, lhu) | WB_RAM | 2'b01 |
| NPC.pc4 | jal, jalr (保存返回地址) | WB_PC4 | 2'b10 |
| SEXT.ext | lui (立即数直接写回) | WB_EXT | 2'b11 |

| 是否写回 | 指令类型 | rf_we |
|----------|----------|-------|
| 写回 | R型, I型(非load), load, U型, J型, jalr | 1 |
| 不写回 | S型(store), B型(branch) | 0 |

### 3.3 从 SEXT.imm 列提取 sext_op

| 立即数格式 | inst 位段 | 对应指令类型 | sext_op | 编码 |
|-----------|-----------|-------------|---------|------|
| I-type | inst[31:20] | addi, ori, slli, xori, srli, srai, andi, slti, sltiu, lw, lb, lbu, lh, lhu, jalr, sb, sh, sw | EXT_I | 3'b000 |
| B-type | inst[31\|7\|30:25\|11:8] | beq, bne, blt, bltu, bge, bgeu | EXT_B | 3'b010 |
| U-type | inst[31:12] | lui, auipc | EXT_U | 3'b011 |
| J-type | inst[31\|19:12\|20\|30:21] | jal | EXT_J | 3'b100 |

### 3.4 从 ALU.A 列提取 alua_sel

| ALU.A 来源 | 指令 | alua_sel | 编码 |
|------------|------|----------|------|
| RF.rD1 | 绝大多数指令 | ALU_A_RS1 | 1'b0 |
| PC | auipc | ALU_A_PC | 1'b1 |

### 3.5 从 ALU.B 列提取 alub_sel

| ALU.B 来源 | 指令类型 | alub_sel | 编码 |
|------------|----------|----------|------|
| RF.rD2 | R型, B型(branch) | ALU_B_RS2 | 1'b0 |
| SEXT.ext | I型(含load/store), auipc | ALU_B_EXT | 1'b1 |

### 3.6 ALU 操作提取 alu_op

| 运算 | 对应指令 | alu_op | 编码 | 备注 |
|------|----------|--------|------|------|
| 加法 | add, addi, lw, lb, lbu, lh, lhu, sb, sh, sw, jalr, auipc | ALU_ADD | 5'h00 | 地址计算也用ADD |
| 减法 | sub | ALU_SUB | 5'h01 | |
| 异或 | xor, xori | ALU_XOR | 5'h02 | |
| 或 | or, ori | ALU_OR | 5'h03 | |
| 与 | and, andi | ALU_AND | 5'h04 | |
| 逻辑左移 | sll, slli | ALU_SLL | 5'h05 | |
| 逻辑右移 | srl, srli | ALU_SRL | 5'h06 | |
| 算术右移 | sra, srai | ALU_SRA | 5'h07 | |
| 等于 | beq | ALU_EQ | 5'h08 | |
| 不等 | bne | ALU_NE | 5'h09 | |
| 有符号小于 | slt, slti, blt | ALU_SLT | 5'h0A | |
| 无符号小于 | sltu, sltiu, bltu | ALU_SLTU | 5'h0B | |
| 有符号乘法[31:0] | mul | ALU_MUL | 5'h10 | |
| 有符号乘法[63:32] | mulh | ALU_MULH | 5'h11 | |
| 无符号乘法[63:32] | mulhu | ALU_MULHU | 5'h12 | |
| 有符号除法 | div | ALU_DIV | 5'h13 | |
| 无符号除法 | divu | ALU_DIVU | 5'h14 | |
| 有符号取余 | rem | ALU_REM | 5'h15 | |
| 无符号取余 | remu | ALU_REMU | 5'h16 | |
| 有符号≥ | bge | ALU_GE | 5'h17 | ≡ !SLT |
| 无符号≥ | bgeu | ALU_GEU | 5'h18 | ≡ !SLTU |
| 不使用ALU | lui, jal | - | - | |

### 3.7 存储单元控制信号提取

**读访存 (ram_rop)**:

| 读类型 | 对应指令 | ram_rop | 编码 |
|--------|----------|---------|------|
| 不读 | R型, I型算术, S型, B型, U型, J型 | RAM_EXT_N | 3'b000 |
| 读字 | lw | RAM_EXT_W | 3'b010 |
| 读字节(有符号) | lb | RAM_EXT_B | 3'b001 |
| 读字节(无符号) | lbu | RAM_EXT_BU | 3'b011 |
| 读半字(有符号) | lh | RAM_EXT_H | 3'b100 |
| 读半字(无符号) | lhu | RAM_EXT_HU | 3'b101 |

**写访存 (ram_wop)**:

| 写类型 | 对应指令 | ram_wop | 编码 |
|--------|----------|---------|------|
| 不写 | R型, I型, B型, U型, J型, load | RAM_WE_N | 4'b0000 |
| 写字节 | sb | RAM_WE_B | 4'b0001 |
| 写半字 | sh | RAM_WE_H | 4'b0011 |
| 写字 | sw | RAM_WE_W | 4'b1111 |

**多周期标志**:

| 信号 | 含义 | 为1的指令 | 为0的指令 |
|------|------|----------|----------|
| is_mul | 乘法标志(触发stall) | mul, mulh, mulhu | 其余 |
| is_div | 除法标志(触发stall) | div, divu, rem, remu | 其余 |

---

## 4. 完整控制信号取值表

> 列名缩写：npc = npc_op, we = rf_we, wsel = rf_wsel, sext = sext_op, a = alua_sel, b = alub_sel, rop = ram_rop, wop = ram_wop

### 4.1 R-类型 (17条) — opcode = 0110011

| 指令 | funct3 | funct7 | npc | we | wsel | sext | alu_op | a | b | rop | wop | mul | div |
|------|--------|--------|-----|----|------|------|--------|---|---|-----|-----|-----|-----|
| add | 000 | 0000000 | PC4 | 1 | ALU | - | ADD | A | RS2 | N | N | 0 | 0 |
| sub | 000 | 0100000 | PC4 | 1 | ALU | - | SUB | A | RS2 | N | N | 0 | 0 |
| xor | 100 | 0000000 | PC4 | 1 | ALU | - | XOR | A | RS2 | N | N | 0 | 0 |
| sll | 001 | 0000000 | PC4 | 1 | ALU | - | SLL | A | RS2 | N | N | 0 | 0 |
| srl | 101 | 0000000 | PC4 | 1 | ALU | - | SRL | A | RS2 | N | N | 0 | 0 |
| sra | 101 | 0100000 | PC4 | 1 | ALU | - | SRA | A | RS2 | N | N | 0 | 0 |
| and | 111 | 0000000 | PC4 | 1 | ALU | - | AND | A | RS2 | N | N | 0 | 0 |
| or  | 110 | 0000000 | PC4 | 1 | ALU | - | OR  | A | RS2 | N | N | 0 | 0 |
| slt | 010 | 0000000 | PC4 | 1 | ALU | - | SLT | A | RS2 | N | N | 0 | 0 |
| sltu| 011 | 0000000 | PC4 | 1 | ALU | - | SLTU| A | RS2 | N | N | 0 | 0 |
| mul | 000 | 0000001 | PC4 | 1 | ALU | - | MUL | A | RS2 | N | N | 1 | 0 |
| mulh| 001 | 0000001 | PC4 | 1 | ALU | - | MULH| A | RS2 | N | N | 1 | 0 |
| mulhu|011 | 0000001 | PC4 | 1 | ALU | - | MULHU|A | RS2 | N | N | 1 | 0 |
| div | 100 | 0000001 | PC4 | 1 | ALU | - | DIV | A | RS2 | N | N | 0 | 1 |
| divu| 101 | 0000001 | PC4 | 1 | ALU | - | DIVU| A | RS2 | N | N | 0 | 1 |
| rem | 110 | 0000001 | PC4 | 1 | ALU | - | REM | A | RS2 | N | N | 0 | 1 |
| remu| 111 | 0000001 | PC4 | 1 | ALU | - | REMU| A | RS2 | N | N | 0 | 1 |

### 4.2 I-类型 (15条) — imm[11:0] + rs1 + funct3 + rd + opcode

| 指令 | opcode | funct3 | funct7 | npc | we | wsel | sext | alu_op | a | b | rop | wop | mul | div |
|------|--------|--------|--------|-----|----|------|------|--------|---|---|-----|-----|-----|-----|
| addi | 0010011 | 000 | - | PC4 | 1 | ALU | I | ADD | A | SX | N | N | 0 | 0 |
| ori  | 0010011 | 110 | - | PC4 | 1 | ALU | I | OR  | A | SX | N | N | 0 | 0 |
| slli | 0010011 | 001 | 0000000 | PC4 | 1 | ALU | I | SLL | A | SX | N | N | 0 | 0 |
| xori | 0010011 | 100 | - | PC4 | 1 | ALU | I | XOR | A | SX | N | N | 0 | 0 |
| srli | 0010011 | 101 | 0000000 | PC4 | 1 | ALU | I | SRL | A | SX | N | N | 0 | 0 |
| srai | 0010011 | 101 | 0100000 | PC4 | 1 | ALU | I | SRA | A | SX | N | N | 0 | 0 |
| andi | 0010011 | 111 | - | PC4 | 1 | ALU | I | AND | A | SX | N | N | 0 | 0 |
| slti | 0010011 | 010 | - | PC4 | 1 | ALU | I | SLT | A | SX | N | N | 0 | 0 |
| sltiu| 0010011 | 011 | - | PC4 | 1 | ALU | I | SLTU| A | SX | N | N | 0 | 0 |
| lw   | 0000011 | 010 | - | PC4 | 1 | RAM | I | ADD | A | SX | W | N | 0 | 0 |
| lb   | 0000011 | 000 | - | PC4 | 1 | RAM | I | ADD | A | SX | B | N | 0 | 0 |
| lbu  | 0000011 | 100 | - | PC4 | 1 | RAM | I | ADD | A | SX | BU| N | 0 | 0 |
| lh   | 0000011 | 001 | - | PC4 | 1 | RAM | I | ADD | A | SX | H | N | 0 | 0 |
| lhu  | 0000011 | 101 | - | PC4 | 1 | RAM | I | ADD | A | SX | HU| N | 0 | 0 |
| jalr | 1100111 | 000 | - | JMP | 1 | P4  | I | ADD | A | SX | N | N | 0 | 0 |

### 4.3 S-类型 (3条) — opcode = 0100011

| 指令 | funct3 | npc | we | wsel | sext | alu_op | a | b | rop | wop | mul | div |
|------|--------|-----|----|------|------|--------|---|---|-----|-----|-----|-----|
| sb | 000 | PC4 | 0 | - | I | ADD | A | SX | N | B | 0 | 0 |
| sh | 001 | PC4 | 0 | - | I | ADD | A | SX | N | H | 0 | 0 |
| sw | 010 | PC4 | 0 | - | I | ADD | A | SX | N | W | 0 | 0 |

### 4.4 B-类型 (6条) — opcode = 1100011

| 指令 | funct3 | npc | we | wsel | sext | alu_op | a | b | rop | wop | mul | div |
|------|--------|-----|----|------|------|--------|---|---|-----|-----|-----|-----|
| beq  | 000 | BRA | 0 | - | B | EQ   | A | RS2 | N | N | 0 | 0 |
| bne  | 001 | BRA | 0 | - | B | NE   | A | RS2 | N | N | 0 | 0 |
| blt  | 100 | BRA | 0 | - | B | SLT  | A | RS2 | N | N | 0 | 0 |
| bltu | 110 | BRA | 0 | - | B | SLTU | A | RS2 | N | N | 0 | 0 |
| bge  | 101 | BRA | 0 | - | B | GE   | A | RS2 | N | N | 0 | 0 |
| bgeu | 111 | BRA | 0 | - | B | GEU  | A | RS2 | N | N | 0 | 0 |

### 4.5 U-类型 (2条)

| 指令 | opcode | npc | we | wsel | sext | alu_op | a | b | rop | wop | mul | div |
|------|--------|-----|----|------|------|--------|---|---|-----|-----|-----|-----|
| lui   | 0110111 | PC4 | 1 | EXT | U | -  | -  | -  | N | N | 0 | 0 |
| auipc | 0010111 | PC4 | 1 | ALU | U | ADD | AP | SX | N | N | 0 | 0 |

### 4.6 J-类型 (1条) — opcode = 1101111

| 指令 | npc | we | wsel | sext | alu_op | a | b | rop | wop | mul | div |
|------|-----|----|------|------|--------|---|---|-----|-----|-----|-----|
| jal | JMP | 1 | P4 | J | - | - | - | N | N | 0 | 0 |

---

## 5. 控制信号编码速查表

### 5.1 npc_op

| 助记符 | 编码 | 行为 |
|--------|------|------|
| PC4 | 2'b00 | npc = PC + 4 |
| BRA | 2'b10 | npc = br ? PC+offset : PC+4 |
| JMP | 2'b11 | npc = PC + offset |

### 5.2 rf_wsel

| 助记符 | 编码 | wD 来源 |
|--------|------|---------|
| ALU | 2'b00 | ALU.C |
| RAM | 2'b01 | MEXT.ext |
| P4 | 2'b10 | NPC.pc4 |
| EXT | 2'b11 | SEXT.ext |

### 5.3 sext_op

| 助记符 | 编码 | 拼接规则 |
|--------|------|----------|
| I | 3'b000 | {{20{imm[31]}}, imm[31:20]} |
| B | 3'b010 | {{19{imm[31]}}, imm[31], imm[7], imm[30:25], imm[11:8], 1'b0} |
| U | 3'b011 | {imm[31:12], 12'h0} |
| J | 3'b100 | {{11{imm[31]}}, imm[31], imm[19:12], imm[20], imm[30:21], 1'b0} |

### 5.4 alua_sel / alub_sel

| 信号 | 助记符 | 编码 | 选择 |
|------|--------|------|------|
| alua_sel | A | 1'b0 | ALU.A = RF.rD1 |
| alua_sel | AP | 1'b1 | ALU.A = PC |
| alub_sel | RS2 | 1'b0 | ALU.B = RF.rD2 |
| alub_sel | SX | 1'b1 | ALU.B = SEXT.ext |

### 5.5 alu_op

| 助记符 | 编码 | 运算 | 使用指令 |
|--------|------|------|----------|
| ADD | 5'h00 | a + b | add, addi, lw/lb/lbu/lh/lhu, sb/sh/sw, jalr, auipc |
| SUB | 5'h01 | a - b | sub |
| XOR | 5'h02 | a ^ b | xor, xori |
| OR  | 5'h03 | a \| b | or, ori |
| AND | 5'h04 | a & b | and, andi |
| SLL | 5'h05 | a << b | sll, slli |
| SRL | 5'h06 | a >> b (逻辑) | srl, srli |
| SRA | 5'h07 | a >> b (算术) | sra, srai |
| EQ  | 5'h08 | a == b | beq |
| NE  | 5'h09 | a != b | bne |
| SLT | 5'h0A | a < b (有符号) | slt, slti, blt |
| SLTU| 5'h0B | a < b (无符号) | sltu, sltiu, bltu |
| MUL | 5'h10 | (a×b)[31:0] | mul |
| MULH| 5'h11 | (a×b)[63:32] 有符号 | mulh |
| MULHU|5'h12 | (a×b)[63:32] 无符号 | mulhu |
| DIV | 5'h13 | a / b (有符号) | div |
| DIVU| 5'h14 | a / b (无符号) | divu |
| REM | 5'h15 | a % b (有符号) | rem |
| REMU| 5'h16 | a % b (无符号) | remu |
| GE  | 5'h17 | a >= b (有符号) | bge |
| GEU | 5'h18 | a >= b (无符号) | bgeu |

### 5.6 ram_rop / ram_wop

| 助记符 | 编码 | 含义 | 使用指令 |
|--------|------|------|----------|
| N (rop) | 3'b000 | 不读访存 | 非load指令 |
| B  | 3'b001 | 读字节(有符号扩展) | lb |
| BU | 3'b011 | 读字节(无符号扩展) | lbu |
| H  | 3'b100 | 读半字(有符号扩展) | lh |
| HU | 3'b101 | 读半字(无符号扩展) | lhu |
| W  | 3'b010 | 读字 | lw |
| N (wop) | 4'b0000 | 不写访存 | 非store指令 |
| B  | 4'b0001 | 写字节 | sb |
| H  | 4'b0011 | 写半字 | sh |
| W  | 4'b1111 | 写字 | sw |

---

## 6. 新增宏定义清单

已有定义用 `//` 注释，需新增的定义无注释前缀。

```verilog
// === NPC (已有) ===
// `define NPC_PC4     2'b00
// `define NPC_BRA     2'b10
// `define NPC_JMP     2'b11

// === WB (已有) ===
// `define WB_ALU      2'b00
// `define WB_RAM      2'b01
// `define WB_PC4      2'b10
// `define WB_EXT      2'b11

// === EXT (已有) ===
// `define EXT_I       3'b000
// `define EXT_B       3'b010
// `define EXT_U       3'b011
// `define EXT_J       3'b100

// === ALU MUX (已有) ===
// `define ALU_A_RS1   1'b0
// `define ALU_A_PC    1'b1
// `define ALU_B_RS2   1'b0
// `define ALU_B_EXT   1'b1

// === ALU OP ===
// `define ALU_ADD     5'h00   // 已有
// `define ALU_OR      5'h03   // 已有
// `define ALU_SLL     5'h05   // 已有
// `define ALU_EQ      5'h08   // 已有
// `define ALU_NE      5'h09   // 已有
`define ALU_SUB     5'h01
`define ALU_XOR     5'h02
`define ALU_AND     5'h04
`define ALU_SRL     5'h06
`define ALU_SRA     5'h07
`define ALU_SLT     5'h0A
`define ALU_SLTU    5'h0B
`define ALU_MUL     5'h10
`define ALU_MULH    5'h11
`define ALU_MULHU   5'h12
`define ALU_DIV     5'h13
`define ALU_DIVU    5'h14
`define ALU_REM     5'h15
`define ALU_REMU    5'h16
`define ALU_GE      5'h17
`define ALU_GEU     5'h18

// === RAM (已有) ===
// `define RAM_EXT_N   3'b000
// `define RAM_EXT_W   3'b010
// `define RAM_EXT_B   3'b001
// `define RAM_EXT_BU  3'b011
// `define RAM_EXT_H   3'b100
// `define RAM_EXT_HU  3'b101
// `define RAM_WE_N    4'b0000
// `define RAM_WE_B    4'b0001
// `define RAM_WE_H    4'b0011
// `define RAM_WE_W    4'b1111
```

---

## 7. 按指令类型归纳速查

| 指令类型 | npc | we | wsel | sext | alu_op | a | b | rop | wop | mul | div |
|----------|-----|----|------|------|--------|---|---|-----|-----|-----|-----|
| R型算术/逻辑 | PC4 | 1 | ALU | - | 见5.5 | A | RS2 | N | N | 0 | 0 |
| I型算术/逻辑 | PC4 | 1 | ALU | I | 见5.5 | A | SX | N | N | 0 | 0 |
| I型移位 | PC4 | 1 | ALU | I | SLL/SRL/SRA | A | SX | N | N | 0 | 0 |
| Load (所有) | PC4 | 1 | RAM | I | ADD | A | SX | 见5.6 | N | 0 | 0 |
| Store (所有) | PC4 | 0 | - | I | ADD | A | SX | N | 见5.6 | 0 | 0 |
| Branch (所有) | BRA | 0 | - | B | 见5.5 | A | RS2 | N | N | 0 | 0 |
| jal | JMP | 1 | P4 | J | - | - | - | N | N | 0 | 0 |
| jalr | JMP | 1 | P4 | I | ADD | A | SX | N | N | 0 | 0 |
| lui | PC4 | 1 | EXT | U | - | - | - | N | N | 0 | 0 |
| auipc | PC4 | 1 | ALU | U | ADD | AP | SX | N | N | 0 | 0 |
| R型乘 | PC4 | 1 | ALU | - | MUL/MULH/MULHU | A | RS2 | N | N | 1 | 0 |
| R型除/余 | PC4 | 1 | ALU | - | DIV/DIVU/REM/REMU | A | RS2 | N | N | 0 | 1 |
