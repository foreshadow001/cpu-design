# 附录C：控制信号快速参考

> 综合自 Theory1-PPT 和数据通路表/控制信号取值表模板

## 控制信号一览

### 操作选择信号（控制多功能部件执行何种操作）

| 信号 | 位宽 | 控制对象 | 取值 | 编码 | 说明 |
|------|------|----------|------|------|------|
| `npc_op` | 2 | NPC | `NPC_PC4` | `2'b00` | PC+4（顺序执行） |
| | | | `NPC_BRA` | `2'b10` | PC+offset 或 PC+4（条件分支） |
| | | | `NPC_JMP` | `2'b11` | PC+offset（无条件跳转） |
| `alu_op` | 5 | ALU | `ALU_ADD` | `5'h00` | 加法 |
| | | | `ALU_SUB` | `5'h01` | 减法 |
| | | | `ALU_XOR` | `5'h02` | 异或 |
| | | | `ALU_OR` | `5'h03` | 或 |
| | | | `ALU_AND` | `5'h04` | 与 |
| | | | `ALU_SLL` | `5'h05` | 逻辑左移 |
| | | | `ALU_SRL` | `5'h06` | 逻辑右移 |
| | | | `ALU_SRA` | `5'h07` | 算术右移 |
| | | | `ALU_EQ` | `5'h08` | 等于比较 |
| | | | `ALU_NE` | `5'h09` | 不等比较 |
| | | | `ALU_SLT` | `5'h0A` | 有符号小于 |
| | | | `ALU_SLTU` | `5'h0B` | 无符号小于 |
| | | | `ALU_GE` | `5'h17` | 有符号大于等于（= !SLT） |
| | | | `ALU_GEU` | `5'h18` | 无符号大于等于（= !SLTU） |
| | | | `ALU_MUL` | `5'h10` | 有符号乘法[31:0] |
| | | | `ALU_MULH` | `5'h11` | 有符号乘法[63:32] |
| | | | `ALU_MULHU` | `5'h12` | 无符号乘法[63:32] |
| | | | `ALU_DIV` | `5'h13` | 有符号除法 |
| | | | `ALU_DIVU` | `5'h14` | 无符号除法 |
| | | | `ALU_REM` | `5'h15` | 有符号取余 |
| | | | `ALU_REMU` | `5'h16` | 无符号取余 |
| `sext_op` | 3 | SEXT | `EXT_I` | `3'b000` | I-type: {{20{imm[31]}}, imm[31:20]} |
| | | | `EXT_B` | `3'b010` | B-type: {{19{imm[31]}}, imm[31], imm[7], imm[30:25], imm[11:8], 1'b0} |
| | | | `EXT_U` | `3'b011` | U-type: {imm[31:12], 12'h0} |
| | | | `EXT_J` | `3'b100` | J-type: {{11{imm[31]}}, imm[31], imm[19:12], imm[20], imm[30:21], 1'b0} |
| `ram_rop` | 3 | MREQ/MEXT | `RAM_EXT_N` | `3'b000` | 不读访存 |
| | | | `RAM_EXT_B` | `3'b001` | 读字节，有符号扩展 |
| | | | `RAM_EXT_BU` | `3'b011` | 读字节，无符号扩展 |
| | | | `RAM_EXT_H` | `3'b100` | 读半字，有符号扩展 |
| | | | `RAM_EXT_HU` | `3'b101` | 读半字，无符号扩展 |
| | | | `RAM_EXT_W` | `3'b010` | 读字（32位） |
| `ram_wop` | 4 | MREQ | `RAM_WE_N` | `4'b0000` | 不写访存 |
| | | | `RAM_WE_B` | `4'b0001` | 写字节 |
| | | | `RAM_WE_H` | `4'b0011` | 写半字 |
| | | | `RAM_WE_W` | `4'b1111` | 写字（32位） |

### 多路选择信号（控制MUX数据来源）

| 信号 | 位宽 | 控制对象 | 取值 | 编码 | 说明 |
|------|------|----------|------|------|------|
| `rf_wsel` | 2 | RF写数据MUX | `WB_ALU` | `2'b00` | 写回ALU运算结果 |
| | | | `WB_RAM` | `2'b01` | 写回访存读出数据(MEXT.ext) |
| | | | `WB_PC4` | `2'b10` | 写回PC+4 (jal返回地址) |
| | | | `WB_EXT` | `2'b11` | 写回扩展后立即数 (lui) |
| `alua_sel` | 1 | ALU A输入MUX | `ALU_A_RS1` | `1'b0` | ALU.A = RF.rD1 |
| | | | `ALU_A_PC` | `1'b1` | ALU.A = PC (用于auipc) |
| `alub_sel` | 1 | ALU B输入MUX | `ALU_B_RS2` | `1'b0` | ALU.B = RF.rD2 |
| | | | `ALU_B_EXT` | `1'b1` | ALU.B = SEXT.ext |

### 使能信号

| 信号 | 位宽 | 说明 |
|------|------|------|
| `rf_we` | 1 | 寄存器写使能。1=写回，0=不写（store/branch指令） |
| `is_mul` | 1 | 有符号/无符号乘法标志（触发多周期stall） |
| `is_div` | 1 | 除法/取余标志（触发多周期stall） |

## 控制信号推导速查

### 按指令类型归纳

| 指令类型 | npc_op | rf_we | rf_wsel | sext_op | alu_op | alua_sel | alub_sel | ram_rop | ram_wop |
|----------|--------|-------|---------|---------|--------|----------|----------|---------|---------|
| R型算术/逻辑 | PC4 | 1 | WB_ALU | - | (按指令) | RS1 | RS2 | N | N |
| I型算术/逻辑 | PC4 | 1 | WB_ALU | EXT_I | (按指令) | RS1 | EXT | N | N |
| I型移位 | PC4 | 1 | WB_ALU | EXT_I | SLL/SRL/SRA | RS1 | EXT | N | N |
| Load (lb/lh/lw等) | PC4 | 1 | WB_RAM | EXT_I | ADD | RS1 | EXT | B/BU/H/HU/W | N |
| Store (sb/sh/sw) | PC4 | 0 | - | EXT_I | ADD | RS1 | EXT | N | B/H/W |
| Branch (beq/bne等) | BRANCH | 0 | - | EXT_B | EQ/NE/SLT等 | RS1 | RS2 | N | N |
| Jump (jal) | JUMP | 1 | WB_PC4 | EXT_J | - | - | - | N | N |
| Jump (jalr) | JUMP | 1 | WB_PC4 | EXT_I | ADD | RS1 | EXT | N | N |
| lui | PC4 | 1 | WB_EXT | EXT_U | - | - | - | N | N |
| auipc | PC4 | 1 | WB_ALU | EXT_U | ADD | PC | EXT | N | N |
| Mul | PC4 | 1 | WB_ALU | - | MUL/MULH/MULHU | RS1 | RS2 | N | N |
| Div/Rem | PC4 | 1 | WB_ALU | - | DIV/DIVU/REM/REMU | RS1 | RS2 | N | N |

## 访存指令控制信号详解

Load 和 Store 的关键区别：

```
Load:   rf_we=1, rf_wsel=WB_RAM, ram_rop=(B/BU/H/HU/W), ram_wop=N
Store:  rf_we=0, ram_rop=N,              ram_wop=(B/H/W)
```

两者都需要 `alu_op=ADD, alua_sel=RS1, alub_sel=EXT, sext_op=EXT_I` 来计算访存地址。

## 条件分支的信号关系

`npc_op = BRANCH` 时，NPC根据 `br` 信号决定：
- `br=1` → npc = pc + sext(offset)  （跳转）
- `br=0` → npc = pc + 4              （不跳转）

`br` 由 ALU 根据 `alu_op` 产生：
- `alu_op=EQ` → br = (rs1 == rs2)
- `alu_op=NE` → br = (rs1 != rs2)
- `alu_op=SLT` → br = (rs1 < rs2)  有符号（用于blt）
- `alu_op=SLTU` → br = (rs1 < rs2) 无符号（用于bltu）
- `alu_op=GE` → br = (rs1 >= rs2)  有符号（用于bge）
- `alu_op=GEU` → br = (rs1 >= rs2) 无符号（用于bgeu）
