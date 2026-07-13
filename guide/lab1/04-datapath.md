# 数据通路设计

在上一节"功能部件设计"中，我们为数据通路的路径设计了所需的"顶点"。现在，我们需要根据指令功能，将这些功能部件连接起来，形成路径的"边"。

设计数据通路的基本思想是：根据每条指令的功能描述和指令格式，推演出指令执行过程所需的功能部件及其输入输出信号之间的连接关系，即指令级数据通路。

在推演的过程中，还将分析功能部件需要执行的具体功能，并据此再推演相应的控制信号取值。

本课程采用**表格驱动设计**的方法来构建数据通路，即通过数据通路表来描述数据通路。表4-1给出了5条miniRV指令构建数据通路表的示例。

为了理解数据通路表的构造和使用方法，我们首先说明表的组成结构，再逐一分析每条指令的数据通路。

---

## 数据通路表模板说明

数据通路表以行为单位组织信息，前3行为表头，之后的每一行对应一条指令的数据通路连接关系。

**表4-1 数据通路表头结构**

```
单元       | 取指单元        | 译码单元                   | 执行单元       | 存储单元
部件       | PC      | NPC   | RF                    | SEXT       | ALU         | MREQ       | MEXT
输入       | npc     | PC offset br | rR1 rR2 wR wD   | imm        | A    B      | addr wd    | din b_offs
```

表头的各行列含义如下：

- **第1行 — 所属单元**：将功能部件按流水线阶段分组，包括取指单元（IF）、译码单元（ID）、执行单元（EX）、存储单元（MEM）。虽然本课程设计的是单周期CPU，但按此划分有助于建立后续流水线设计的概念基础。

- **第2行 — 功能部件**：列出每个单元内包含的功能部件，依次为`PC`（程序计数器）、`NPC`（下一地址计算）、`RF`（寄存器堆）、`SEXT`（立即数扩展）、`ALU`（算术逻辑单元）、`MREQ`（存储器访问请求）、`MEXT`（存储器读数据扩展）。

- **第3行 — 输入信号/引脚**：列出每个功能部件的输入引脚名称。例如`RF`的输入引脚依次为`rR1`（读地址1）、`rR2`（读地址2）、`wR`（写地址）、`wD`（写数据）；`ALU`的输入引脚为`A`（操作数1）和`B`（操作数2）。

- **第4行及以后 — 指令连接关系**：每条指令占一行，按表头定义的引脚顺序填写每个输入信号的来源。表中使用如下标记约定：
  - `X.y`：表示部件`X`的输出信号`y`，例如`NPC.npc`表示部件NPC的`npc`输出
  - `IN.xxx`：表示CPU的外部输入信号，例如`IN.inst[19:15]`表示指令码的`[19:15]`位
  - `-`：表示该引脚在当前指令中未被使用（无连接或Don't Care）
  - 常量值（如`VCC`）直接填写

> **关于示例的说明**
>
> 需要注意的是，本节的5条示例指令数据通路表仅作为教学示例。在实际建模过程中，可能会面临基本功能部件不满足需求的问题，因此需要修改并完善已有基础功能部件，或者设计新的功能部件。例如，若要支持`bne`指令，可能需要为NPC.br添加条件取反逻辑；若要支持`sw`指令，则需要为MREQ.wd添加数据来源通路。

---

## 5条示例指令的数据通路逐行分析

下面以5条典型miniRV指令为例，逐条展示完整的数据通路表行，并分析每条连接关系背后的设计依据。

### 5条指令数据通路总览

下表给出了ori、lw、beq、lui、jal共5条指令的数据通路表行。

```
单元       | 取指单元        | 译码单元                   | 执行单元       | 存储单元
部件       | PC      | NPC   | RF                    | SEXT       | ALU         | MREQ       | MEXT
输入       | npc     | PC offset br | rR1 rR2 wR wD   | imm        | A    B      | addr wd    | din b_offs
-----------|---------|-------|------------------------|------------|-------------|------------|------------
ori        | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | IN.inst[31:0] | RF.rD1 | SEXT.ext | - | - | - | -
lw         | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | MEXT.ext | IN.inst[31:0] | RF.rD1 | SEXT.ext | ALU.C | - | MREQ.rdata | -
beq        | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | - | - | IN.inst[31:0] | RF.rD1 | RF.rD2 | - | - | - | -
lui        | NPC.npc | PC.pc | - | - | - | - | IN.inst[11:7] | SEXT.ext | IN.inst[31:0] | - | - | - | - | - | -
jal        | NPC.npc | PC.pc | SEXT.ext | VCC | - | - | IN.inst[11:7] | NPC.pc4 | IN.inst[31:0] | - | - | - | - | - | -
```

下面逐条分析每行连接关系的设计理由。

---

### ori指令分析

**指令功能**：`rd = rs1 | zero_ext(imm[11:0])`（寄存器rs1与12位立即数按位或，结果写回rd）

**指令格式**：I-type，opcode=0010011，funct3=110

| 引脚 | 连接来源 | 设计理由 |
|------|---------|---------|
| **PC.npc** | `NPC.npc` | 顺序执行下一条指令，下址由NPC产生PC+4 |
| **NPC.PC** | `PC.pc` | NPC需要当前PC值来计算PC+4 |
| **NPC.offset** | `-` | ori不涉及分支跳转，无需偏移量 |
| **NPC.br** | `-` | ori不涉及分支条件判断 |
| **RF.rR1** | `IN.inst[19:15]` | 读取rs1源寄存器的地址来源于指令码的rs1字段 |
| **RF.rR2** | `-` | ori只需要一个源操作数，无需读取rs2 |
| **RF.wR** | `IN.inst[11:7]` | 写回目标寄存器rd的地址来源于指令码的rd字段 |
| **RF.wD** | `ALU.C` | OR运算结果由ALU产生，通过ALU.C输出写回寄存器堆 |
| **SEXT.imm** | `IN.inst[31:0]` | 立即数扩展器接收完整的指令码，由sext_op=EXT_I控制提取I型立即数字段[31:20]并进行零扩展 |
| **ALU.A** | `RF.rD1` | 第一个操作数为rs1寄存器的值，经由RF.rD1输出送至ALU的A端 |
| **ALU.B** | `SEXT.ext` | 第二个操作数为扩展后的立即数，经由SEXT.ext输出送至ALU的B端 |
| **MREQ.addr** | `-` | ori不访问数据存储器 |
| **MREQ.wd** | `-` | ori不访问数据存储器 |
| **MEXT.din** | `-` | ori不访问数据存储器 |
| **MEXT.b_offs** | `-` | ori不访问数据存储器 |

**数据流向总结**：

```
取指: PC → NPC(PC+4) → PC
译码: RF.rR1 = inst[19:15] → RF.rD1 → ALU.A
      SEXT.imm = inst[31:20] → SEXT.ext → ALU.B
执行: ALU(A|B) = RF.rD1 | SEXT.ext → ALU.C
写回: ALU.C → RF.wD, RF.wR = inst[11:7]
```

---

### lw指令分析

**指令功能**：`rd = mem[rs1 + sign_ext(imm[11:0])]`（以rs1为基地址加偏移量得到有效地址，从存储器读取数据写回rd）

**指令格式**：I-type load，opcode=0000011，funct3=010

| 引脚 | 连接来源 | 设计理由 |
|------|---------|---------|
| **PC.npc** | `NPC.npc` | 顺序执行，PC+4 |
| **NPC.PC** | `PC.pc` | NPC计算PC+4需要当前PC值 |
| **NPC.offset** | `-` | lw不涉及跳转 |
| **NPC.br** | `-` | lw不涉及分支 |
| **RF.rR1** | `IN.inst[19:15]` | rs1提供基地址 |
| **RF.rR2** | `-` | lw不需要rs2 |
| **RF.wR** | `IN.inst[11:7]` | 写入目标寄存器rd |
| **RF.wD** | `MEXT.ext` | **关键区别**：写回数据来自存储器读取结果，经MEXT扩展后写回，而非来自ALU |
| **SEXT.imm** | `IN.inst[31:0]` | sext_op=EXT_I控制SEXT提取I型立即数[31:20]并进行符号扩展（地址偏移量需要符号扩展） |
| **ALU.A** | `RF.rD1` | ALU计算有效地址，A端接基地址rs1 |
| **ALU.B** | `SEXT.ext` | B端接符号扩展后的偏移量 |
| **MREQ.addr** | `ALU.C` | **关键区别**：ALU计算得到有效地址，送至MREQ的addr端口进行存储器访问 |
| **MREQ.wd** | `-` | lw是读操作，不写存储器 |
| **MEXT.din** | `MREQ.rdata` | MREQ从存储器读出的原始数据送至MEXT进行扩展 |
| **MEXT.b_offs** | `-` | lw是字加载，字节偏移为0 |

**数据流向总结**：

```
取指: PC → NPC(PC+4) → PC
译码: RF.rR1 = inst[19:15] → RF.rD1 → ALU.A
      SEXT.imm → SEXT.ext → ALU.B
执行: ALU(A+B) = RF.rD1 + SEXT.ext → ALU.C
访存: ALU.C → MREQ.addr → MREQ.rdata → MEXT.din
写回: MEXT.ext → RF.wD, RF.wR = inst[11:7]
```

---

### beq指令分析

**指令功能**：`if (rs1 == rs2) PC = PC + sign_ext(imm[12:1] << 1)`（若rs1等于rs2则跳转到目标地址）

**指令格式**：B-type，opcode=1100011，funct3=000

| 引脚 | 连接来源 | 设计理由 |
|------|---------|---------|
| **PC.npc** | `NPC.npc` | NPC根据分支条件选择输出PC+4或PC+offset |
| **NPC.PC** | `PC.pc` | NPC需要当前PC计算PC+4和分支目标地址 |
| **NPC.offset** | `SEXT.ext` | **关键区别**：分支目标偏移量来自SEXT扩展后的B型立即数 |
| **NPC.br** | `ALU.br` | **关键区别**：分支条件由ALU的br输出提供（rs1==rs2时ALU.br=1，表示条件成立） |
| **RF.rR1** | `IN.inst[19:15]` | 读取rs1用于比较 |
| **RF.rR2** | `IN.inst[24:20]` | **关键区别**：beq需要读取两个源寄存器进行相等比较，rR2接rs2字段 |
| **RF.wR** | `-` | beq不写回寄存器 |
| **RF.wD** | `-` | beq不写回寄存器 |
| **SEXT.imm** | `IN.inst[31:0]` | sext_op=EXT_B控制SEXT提取B型立即数（分散在inst[31], inst[7], inst[30:25], inst[11:8]）并符号扩展 |
| **ALU.A** | `RF.rD1` | ALU进行减法运算，A端接rs1 |
| **ALU.B** | `RF.rD2` | **关键区别**：ALU的B端接rs2（而非立即数），通过减法比较两数是否相等 |
| **MREQ.addr** | `-` | beq不访问存储器 |
| **MREQ.wd** | `-` | beq不访问存储器 |
| **MEXT.din** | `-` | beq不访问存储器 |
| **MEXT.b_offs** | `-` | beq不访问存储器 |

**数据流向总结**：

```
取指: PC → NPC, offset → NPC, ALU.br → NPC.br → NPC.npc → PC (分支或顺序)
译码: RF.rR1 = inst[19:15] → RF.rD1 → ALU.A
      RF.rR2 = inst[24:20] → RF.rD2 → ALU.B
      SEXT.imm → SEXT.ext → NPC.offset
执行: ALU(A-B) = RF.rD1 - RF.rD2 → ALU.br → NPC.br
      若ALU.br=1: NPC.npc = PC + SEXT.ext (跳转)
      若ALU.br=0: NPC.npc = PC + 4 (顺序)
```

**关于beq的ALU操作**：beq虽然不产生写回寄存器的结果，但ALU仍然需要参与执行——通过减法运算产生零标志（br输出）来判断分支条件是否成立。

---

### lui指令分析

**指令功能**：`rd = imm[31:12] << 12`（将20位立即数加载到目标寄存器的高20位，低12位补零）

**指令格式**：U-type，opcode=0110111

| 引脚 | 连接来源 | 设计理由 |
|------|---------|---------|
| **PC.npc** | `NPC.npc` | 顺序执行 |
| **NPC.PC** | `PC.pc` | 计算PC+4 |
| **NPC.offset** | `-` | lui不涉及跳转 |
| **NPC.br** | `-` | lui不涉及分支 |
| **RF.rR1** | `-` | lui没有rs1字段（bits[19:15]属于立即数编码），不读源寄存器 |
| **RF.rR2** | `-` | lui不需要rs2 |
| **RF.wR** | `IN.inst[11:7]` | 目标寄存器rd |
| **RF.wD** | `SEXT.ext` | **关键区别**：写回数据来自SEXT输出的U型立即数（已左移12位），而非ALU结果 |
| **SEXT.imm** | `IN.inst[31:0]` | sext_op=EXT_U控制SEXT提取U型立即数[31:12]并左移12位输出 |
| **ALU.A** | `-` | lui不使用ALU |
| **ALU.B** | `-` | lui不使用ALU |
| **MREQ.addr** | `-` | lui不访问存储器 |
| **MREQ.wd** | `-` | lui不访问存储器 |
| **MEXT.din** | `-` | lui不访问存储器 |
| **MEXT.b_offs** | `-` | lui不访问存储器 |

**数据流向总结**：

```
取指: PC → NPC(PC+4) → PC
译码: SEXT.imm = inst[31:12] → SEXT({imm, 12'b0}) → RF.wD
写回: SEXT.ext → RF.wD, RF.wR = inst[11:7]
```

**关于lui的写回数据来源**：lui的写回数据直接来自立即数扩展器SEXT，而非ALU。这是因为U型指令的立即数（高20位）经过左移12位后即为目标结果，无需ALU参与运算。在后续的综合步骤中，RF.wD的多个输入来源（ALU.C、MEXT.ext、SEXT.ext、NPC.pc4）需要通过多路选择器进行选择。

---

### jal指令分析

**指令功能**：`rd = PC+4; PC = PC + sign_ext(imm[20:1] << 1)`（先保存返回地址PC+4到rd，然后无条件跳转到目标地址）

**指令格式**：J-type，opcode=1101111

| 引脚 | 连接来源 | 设计理由 |
|------|---------|---------|
| **PC.npc** | `NPC.npc` | NPC选择跳转目标 |
| **NPC.PC** | `PC.pc` | NPC需要当前PC计算PC+4和跳转目标 |
| **NPC.offset** | `SEXT.ext` | 跳转偏移量来自SEXT扩展后的J型立即数 |
| **NPC.br** | `VCC` | **关键区别**：jal是无条件跳转，br恒接VCC（逻辑1），强制NPC选择跳转地址 |
| **RF.rR1** | `-` | jal没有rs1字段 |
| **RF.rR2** | `-` | jal不需要rs2 |
| **RF.wR** | `IN.inst[11:7]` | 目标寄存器rd（约定为x1/ra，也可以是任意寄存器） |
| **RF.wD** | `NPC.pc4` | **关键区别**：写回数据为返回地址PC+4，由NPC的pc4输出提供 |
| **SEXT.imm** | `IN.inst[31:0]` | sext_op=EXT_J控制SEXT提取J型立即数（分散在inst[31], inst[19:12], inst[20], inst[30:21]）并符号扩展 |
| **ALU.A** | `-` | jal不使用ALU |
| **ALU.B** | `-` | jal不使用ALU |
| **MREQ.addr** | `-` | jal不访问存储器 |
| **MREQ.wd** | `-` | jal不访问存储器 |
| **MEXT.din** | `-` | jal不访问存储器 |
| **MEXT.b_offs** | `-` | jal不访问存储器 |

**数据流向总结**：

```
取指: PC → NPC, offset → NPC, br=VCC → NPC.npc = PC+offset → PC
      NPC.pc4 = PC+4 → RF.wD (保存返回地址)
写回: NPC.pc4 → RF.wD, RF.wR = inst[11:7]
```

**关于NPC.pc4输出**：NPC部件除了输出npc（下一指令地址）外，还需要输出pc4（PC+4）。这是jal指令的特殊需求——在跳转执行前，必须将返回地址PC+4保存到rd中。在其他指令中，NPC.pc4虽被计算但不使用。

---

## 综合数据通路

对上述5条指令逐一分析并填写数据通路表后，我们得到了每条指令独立的数据通路。为了设计能够执行所有指令的CPU，需要将这些数据通路综合（合并）为一张统一的数据通路。

### Step 1：合并数据通路表

综合的第一步是将所有指令行合并为一行"综合"行，逐列汇总所有输入信号的来源：

```
部件输入   | 综合（所有指令的输入来源）
-----------|---------------------------
PC.npc     | {NPC.npc}                                    ← 所有指令相同
NPC.PC     | {PC.pc}                                      ← 所有指令相同
NPC.offset | {-, SEXT.ext}                                ← 来源：ori/lw/lui不使用(-)，beq/jal使用SEXT.ext
NPC.br     | {-, ALU.br, VCC}                             ← 来源：ori/lw/lui不使用(-)，beq使用ALU.br，jal使用VCC
RF.rR1     | {IN.inst[19:15], -}                          ← 来源：ori/lw/beq使用inst[19:15]，lui/jal不使用(-)
RF.rR2     | {IN.inst[24:20], -}                          ← 来源：beq使用inst[24:20]，其余不使用(-)
RF.wR      | {IN.inst[11:7], -}                           ← 来源：ori/lw/lui/jal使用inst[11:7]，beq不使用(-)
RF.wD      | {ALU.C, MEXT.ext, SEXT.ext, NPC.pc4, -}    ← 来源：5种不同来源
SEXT.imm   | {IN.inst[31:0]}                              ← 所有指令相同（宽输入方案）
ALU.A      | {RF.rD1, -}                                  ← 来源：ori/lw/beq使用RF.rD1，lui/jal不使用(-)
ALU.B      | {SEXT.ext, RF.rD2, -}                        ← 来源：ori/lw使用SEXT.ext，beq使用RF.rD2，lui/jal不使用(-)
MREQ.addr  | {ALU.C, -}                                   ← 来源：lw使用ALU.C，其余不使用(-)
MREQ.wd    | {-}                                           ← 所有指令均不使用（未实现写存储器指令）
MEXT.din   | {MREQ.rdata, -}                              ← 来源：lw使用MREQ.rdata，其余不使用(-)
MEXT.b_offs| {-}                                           ← 所有指令均不使用
```

从合并结果可以清楚地看到，部分输入引脚具有**多个输入来源**（例如RF.wD有4个有效来源），这需要在数据通路中添加额外的硬件来处理。

### Step 2：处理多输入源问题

对于具有多个输入来源的引脚，有两种处理方法：

#### 方法一：添加多路选择器（MUX）

为每个具有多输入源的引脚添加一个多路选择器，通过控制信号选择当前指令所需的输入。以RF.wD为例：

| 指令 | RF.wD来源 | 选择信号rf_wsel |
|------|-----------|----------------|
| ori  | ALU.C     | WB_ALU (00)     |
| lw   | MEXT.ext  | WB_MEM (01)     |
| lui  | SEXT.ext  | WB_SEXT (10)    |
| jal  | NPC.pc4   | WB_PC4 (11)     |

此时，RF.wD的前端插入一个4输入MUX，其选择端由控制信号`rf_wsel`驱动。

同理，ALU.B有三个输入来源（SEXT.ext、RF.rD2、以及lui所需的常量0），需要添加MUX：

| 指令 | ALU.B来源 | 选择信号alub_sel |
|------|-----------|-----------------|
| ori  | SEXT.ext  | ALUB_EXT (0)    |
| lw   | SEXT.ext  | ALUB_EXT (0)    |
| beq  | RF.rD2    | ALUB_RF (1)     |

> **注**：lui和jal不使用ALU，因此ALU.B的取值不影响结果，无需为其分配MUX通道。

#### 方法二：拓宽输入信号位宽（以SEXT为例）

对于立即数扩展器SEXT的输入，如果采用方法一的多路选择器方案，则需要根据指令格式（I/B/U/J）选择不同的指令码位段作为SEXT.imm的输入：

```
I型: SEXT.imm = IN.inst[31:20]   (12位立即数)
B型: SEXT.imm = {IN.inst[31], IN.inst[7], IN.inst[30:25], IN.inst[11:8], 1'b0}  (13位立即数)
U型: SEXT.imm = IN.inst[31:12]   (20位立即数)
J型: SEXT.imm = {IN.inst[31], IN.inst[19:12], IN.inst[20], IN.inst[30:21], 1'b0}  (21位立即数)
```

这种方法需要在SEXT前添加4输入MUX，增加了线网资源的消耗。

更为简洁的方法是采用**拓宽输入位宽**的策略：将指令码中所有可能包含立即数信息的比特位全部接入SEXT，即`SEXT.imm = IN.inst[31:0]`。SEXT内部根据`sext_op`控制信号的不同取值（EXT_I/EXT_B/EXT_U/EXT_J），自动从32位输入中提取对应格式的立即数字段并进行扩展。这样，SEXT.imm的前端无需MUX，仅需一根32位总线连接指令码即可。

两种方法的对比如下：

| 方案 | 优点 | 缺点 |
|------|------|------|
| MUX方案 | 连接清晰，每位数据路径明确 | 需要额外MUX硬件，布线复杂 |
| 宽输入方案 | 节省前端MUX，布线简单 | SEXT内部逻辑略复杂，需要支持多种格式解码 |

本课程的设计采用**宽输入方案**，所有指令的SEXT.imm统一连接`IN.inst[31:0]`。

---

将综合完成后得到的最终数据通路表图形化，即可构建出CPU的数据通路图。数据通路图中需要包含所有功能部件、多路选择器以及它们之间的连接关系，同时标注多路选择器的控制信号名称，为下一节的控制单元设计做好准备。
