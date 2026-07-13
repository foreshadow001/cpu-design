# 单周期CPU设计方法论（PPT核心提炼）

> 来源：Theory1-PPT-单周期CPU设计.pdf (63页)
> 课程：计算机设计与实践（2026夏季）| 哈工大（深圳）

## 1. CPU设计工程化方法（5步法）

```
第1步: 分析指令 → 构建指令级数据通路
         ↓
第2步: 综合数据通路（合并所有指令的数据通路，处理多输入）
         ↓
第3步: 构造控制逻辑（确定控制信号及取值，建立控制信号表）
         ↓
第4步: 提取功能部件（确定接口信号，HDL描述）
         ↓
第5步: 连接和组装
```

## 2. 数据通路表示法

**核心概念**：数据通路 = 功能部件集合 + 连接关系集合

**表格表示法**：
| 单元 | 取指 | 译码 | 执行 | 存储 |
|------|------|------|------|------|
| 部件 | PC | NPC | RF | SEXT | ALU | MREQ | MEXT |
| 输入 | npc | PC offset br | rR1 rR2 wR wD | imm | A B | ram_addr ram_wdata | din byte_offs |

- 第1-2行：功能部件及所属单元
- 第3行：各部件的输入信号
- 第4+行：每条指令一行，填入"由哪个部件的哪个输出产生该输入信号"

## 3. 7个基本功能部件

| 单元 | 部件 | 输入信号 | 输出信号 | 新增需求 |
|------|------|----------|----------|----------|
| 取指 | **PC** | din(下条指令地址), clk, rst | pc(当前指令地址) | 增加时钟、复位 |
| 取指 | **NPC** | PC(pc), offset(跳转偏移), br(是否分支), op(操作选择) | npc(下条地址), pc4(PC+4) | 增加pc4输出(jal写回), 增加op |
| 译码 | **RF** | rR1, rR2(读地址), wR(写地址), wD(写数据), we(写使能), clk | rD1, rD2(读出数据) | 增加时钟, we(写使能信号) |
| 译码 | **SEXT** | din(指令中的立即数), op(操作选择) | ext(扩展后的立即数) | 增加op选择信号 |
| 执行 | **ALU** | A, B(操作数), op(操作选择) | C(运算结果), br(标志位) | 增加op选择信号 |
| 存储 | **MREQ** | ram_addr(访存地址), ram_rop(读操作), ram_wop(写操作), ram_wdata(写数据) | da_ren, da_addr, da_wen, da_wdata | 增加读写操作选择 |
| 存储 | **MEXT** | din(主存读数据), byte_offs(字节偏移), op(操作选择) | ext(扩展后数据) | 增加op选择信号 |

## 4. 综合数据通路 — 处理多输入

当一个部件的某个输入脚被多条指令的不同信号驱动时，两种处理方法：

**方法1：多路选择器（MUX）**
- 引入多路选择信号（即控制信号的一部分）
- 例如：wD 的来源有 ALU.C, MEXT.ext, NPC.pc4, SEXT.ext → 用 rf_wsel 选择

**方法2：拓宽输入位宽**
- 例如：SEXT 的 din 原本接 inst[31:7]（25位），就能覆盖所有立即数格式的子段
  - I-type: inst[31:20]
  - U-type: inst[31:12]
  - B-type: inst[31|7|30:25|11:8]
  - J-type: inst[31|19:12|20|30:21]

## 5. 控制信号的分类

| 类型 | 信号 | 作用 |
|------|------|------|
| **操作选择** | npc_op, alu_op, sext_op, ram_rop, ram_wop | 控制多功能部件执行何种操作 |
| **多路选择** | rf_wsel, alua_sel, alub_sel | 控制多输入源的选择 |
| **使能** | rf_we | 控制是否写寄存器 |

## 6. 5条示例指令的数据通路分析

### ori rd, rs1, imm
```
PC=pc+4, RF读rs1, SEXT对imm做I型扩展, ALU做rs1 | ext, 结果写回rd
```
| npc | PC | offset | br | rR1 | rR2 | wR | wD | imm | A | B | addr | wd | din | b_offs |
|-----|-----|--------|-----|------|------|-----|------|------|-----|-----|------|-----|-----|-----|
| NPC.npc | PC.pc | - | - | inst[19:15] | - | inst[11:7] | ALU.C | inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |

### lw rd, offset(rs1)
```
PC=pc+4, RF读rs1, SEXT对offset做I型扩展, ALU做rs1+ext得到地址,
MREQ产生读请求, DRAM返回数据, MEXT扩展后写回rd
```
| npc | PC | offset | br | rR1 | rR2 | wR | wD | imm | A | B | addr | wd | din | b_offs |
|-----|-----|--------|-----|------|------|-----|------|------|-----|-----|------|-----|-----|-----|
| NPC.npc | PC.pc | - | - | inst[19:15] | - | inst[11:7] | MEXT.ext | inst[31:20] | RF.rD1 | SEXT.ext | ALU.C | - | IN.rd | ALU.C[1:0] |

### beq rs1, rs2, offset
```
PC=pc+4 或 pc+sext(offset), RF读rs1和rs2, ALU比较相等,
NPC根据br决定下条地址
```
| npc | PC | offset | br | rR1 | rR2 | wR | wD | imm | A | B | addr | wd | din | b_offs |
|-----|-----|--------|-----|------|------|-----|------|------|-----|-----|------|-----|-----|-----|
| NPC.npc | PC.pc | SEXT.ext | ALU.br | inst[19:15] | inst[24:20] | - | - | inst[31\|7\|30:25\|11:8] | RF.rD1 | RF.rD2 | - | - | - | - |

### lui rd, imm
```
PC=pc+4, SEXT对imm做U型扩展(imm<<12), 直接写回rd, 不需ALU
```
| npc | PC | offset | br | rR1 | rR2 | wR | wD | imm | A | B | addr | wd | din | b_offs |
|-----|-----|--------|-----|------|------|-----|------|------|-----|-----|------|-----|-----|-----|
| NPC.npc | PC.pc | - | - | - | - | inst[11:7] | SEXT.ext | inst[31:12] | - | - | - | - | - | - |

### jal rd, offset
```
PC=pc+sext(offset), 需写回PC+4到rd
```
| npc | PC | offset | br | rR1 | rR2 | wR | wD | imm | A | B | addr | wd | din | b_offs |
|-----|-----|--------|-----|------|------|-----|------|------|-----|-----|------|-----|-----|-----|
| NPC.npc | PC.pc | SEXT.ext | - | - | - | inst[11:7] | NPC.pc4 | inst[31\|19:12\|20\|30:21] | - | - | - | - | - | - |

## 7. CPU功能验证 — 基于Trace比对

1. **差分测试（Difftest）**：Golden Model (C语言实现的CPU行为模型) vs DUT (你的Verilog CPU)
2. 两者执行同一条指令，实时比对 PC、写回寄存器、写访存等 Trace 信息
3. 如果不同，立即报错并停止，精确定位错误指令
4. 结合反汇编 (.dump) + 波形 (.vcd) 定位根因

## 8. 实验步骤（7步）

1. 分析指令功能，确定指令的数据通路表和控制信号取值表
2. 给出所有的宏定义（控制信号编码）
3. 给出数据通路图
4. 用Verilog实现各个功能部件（PC, NPC, RF, SEXT, ALU, MREQ, MEXT）
5. 用Verilog实现Controller（组合逻辑：opcode + funct3 + funct7 → 控制信号）
6. 连接和组装——编写顶层模块连线（即cpu_core.v, cpu_top.v等）
7. 功能验证——通过Trace测试
