# 控制单元设计

数据通路包含了完成处理器所要求的操作所必须的硬件，但数据通路要在控制器的控制下才能有条不紊地工作，才能正确地运行程序并得出程序员想要的结果。

---

## 1. 控制信号的分类

控制器的功能是根据指令的操作码（`opcode`）和功能码（`funct3`、`funct7`），产生指令执行所需的控制信号。从控制信号的功能和作用分类，可将控制信号分为**功能选择信号**、**多路选择信号**两种类型，如表5-1所示。

**表5-1 控制信号的分类**

| 类型 | 作用 | 控制的对象 |
|------|------|-----------|
| 操作选择信号 | 指令执行时，控制功能部件具体完成哪个操作。比如ALU对数据进行何种运算、RF要读数据还是写数据，等等 | 多功能部件，比如NPC、SEXT、ALU、RF等 |
| 多路选择信号 | 对多输入源进行选择，从而整合不同指令的数据通路 | 数据通路中的多路选择器 |

## 2. 确定数据通路所需的控制信号

为了设计控制器，我们需要确定数据通路需要哪些控制信号。

在上一节"数据通路设计"中，我们通过分析和综合，由指令级别的数据通路逐步构建出整个CPU的数据通路。现在，我们需要在数据通路表的基础上进行扩展——在"综合"的下方新增"操作选择信号"和"多路选择信号"两行；然后分析数据通路，得出每个功能部件所需的控制信号，并填入表中，如表5-2所示。

**表5-2 扩展数据通路表，添加控制信号（示例）**

| 部件 | 控制信号 | 类型 | 功能说明 |
|------|---------|------|---------|
| NPC | `npc_op` | 操作选择信号 | 选择NPC的输出：PC+4、分支目标、跳转目标 |
| RF | `rf_we` | 操作选择信号 | 寄存器写使能，1表示允许写回 |
| RF/MUX | `rf_wsel` | 多路选择信号 | 选择RF.wD的来源：ALU结果/存储器数据/PC+4/立即数 |
| SEXT | `sext_op` | 操作选择信号 | 选择立即数扩展格式：I型/B型/U型/J型 |
| ALU | `alu_op` | 操作选择信号 | 选择ALU运算类型：加/减/或/左移 |
| ALU/MUX | `alub_sel` | 多路选择信号 | 选择ALU.B的来源：SEXT输出/RF.rD2 |
| MREQ | `ram_rop` | 操作选择信号 | 存储器读使能，1表示读数据存储器 |

接下来，把控制单元和控制信号添加到数据通路图中，即可得到单周期CPU数据通路图。控制单元的输入信号是指令的操作码、功能码，输出信号则是上表列出的操作选择信号和多路选择信号。

## 3. 从数据通路表提取控制信号

在上一节中，我们将5条示例指令的数据通路表逐列合并，得到了综合后的数据通路表。综合表中，每个功能部件的输入引脚对应的多输入源集合，直接决定了需要什么控制信号以及控制信号有多少种取值。

下面以几个关键输入引脚为例，展示从综合表提取控制信号的具体过程。

### 3.1 NPC相关控制信号——`npc_op`

从综合表中，NPC的三个输入引脚具有以下来源：

| NPC引脚 | 综合来源 | 使用的指令 |
|---------|---------|-----------|
| NPC.PC | `PC.pc`（唯一来源） | 所有指令——无需控制 |
| NPC.offset | `SEXT.ext`（beq, jal）, `-`（其余） | beq, jal需要偏移量 |
| NPC.br | `ALU.br`（beq）, `VCC`（jal）, `-`（其余） | 分支/跳转需要条件信号 |

NPC需要根据当前指令类型决定如何计算下一指令地址：
- **顺序执行**（ori, lw, lui）：PC = PC + 4，忽略offset和br
- **条件分支**（beq）：PC = PC + offset（若ALU.br=1），否则PC+4
- **无条件跳转**（jal）：PC = PC + offset（br恒为1）

因此，需要`npc_op`控制信号来区分这几种模式，其取值如下：

| npc_op取值 | 行为 | 对应指令 |
|-----------|------|---------|
| `NPC_PC4` | PC = PC + 4 | ori, lw, lui, addi, slli |
| `NPC_BEQ` | PC = PC + offset（ALU.br=1时） | beq |
| `NPC_BNE` | PC = PC + offset（ALU.br=0时） | bne |
| `NPC_JAL` | PC = PC + offset（无条件） | jal |

### 3.2 RF写数据相关控制信号——`rf_we` 与 `rf_wsel`

RF.wD引脚在综合表中有多个来源：

| 来源 | 使用的指令 |
|------|-----------|
| `ALU.C` | ori, addi, slli（ALU运算结果写回） |
| `MEXT.ext` | lw（存储器加载数据写回） |
| `SEXT.ext` | lui（立即数写回） |
| `NPC.pc4` | jal（返回地址写回） |
| `-` | beq, bne（不写回） |

由此引出两个控制信号：

- **`rf_we`（寄存器写使能）**：区分指令是否需要写回寄存器。写回的指令（ori, lw, lui, jal, addi, slli）令`rf_we=1`；不写回的指令（beq, bne）令`rf_we=0`。

- **`rf_wsel`（写数据选择信号）**：当`rf_we=1`时，进一步选择wD的数据来源。需要2位编码：

| rf_wsel取值 | 选择来源 | 对应指令 |
|------------|---------|---------|
| `WB_ALU` (00) | ALU.C | ori, addi, slli |
| `WB_MEM` (01) | MEXT.ext | lw |
| `WB_SEXT` (10) | SEXT.ext | lui |
| `WB_PC4` (11) | NPC.pc4 | jal |

### 3.3 ALU相关控制信号——`alu_op` 与 `alub_sel`

ALU的两个输入引脚和操作类型也需控制：

| ALU引脚 | 综合来源 | 使用指令 |
|---------|---------|---------|
| ALU.A | `RF.rD1`（ori, lw, beq）, `-`（lui, jal） | 大多数指令读rs1 |
| ALU.B | `SEXT.ext`（ori, lw）, `RF.rD2`（beq）, `-`（lui, jal） | 两种不同来源 |

- **`alub_sel`（B端选择信号）**：选择ALU.B的来源。`ALUB_EXT`选择SEXT.ext（用于ori, lw等需要立即数的指令）；`ALUB_RF`选择RF.rD2（用于beq等需要rs2的指令）。

- **`alu_op`（运算类型选择信号）**：控制ALU执行何种运算：

| alu_op取值 | 运算 | 对应指令 |
|-----------|------|---------|
| `ALU_ADD` (000) | 加法 | lw（访存地址计算）, addi, lui |
| `ALU_SUB` (001) | 减法 | beq, bne（比较两操作数） |
| `ALU_OR` (010) | 按位或 | ori |
| `ALU_SLL` (011) | 左移 | slli |

### 3.4 SEXT相关控制信号——`sext_op`

虽然SEXT.imm在数据通路表中统一接`IN.inst[31:0]`（宽输入方案），但不同指令格式的立即数编码位置和扩展方式不同，需要`sext_op`控制SEXT内部提取逻辑：

| sext_op取值 | 格式 | 提取方式 | 对应指令 |
|------------|------|---------|---------|
| `EXT_I` (00) | I-type | 提取inst[31:20]，符号扩展 | ori, lw, addi, slli |
| `EXT_B` (01) | B-type | 提取inst[31], inst[7], inst[30:25], inst[11:8]，符号扩展后左移1位 | beq, bne |
| `EXT_U` (10) | U-type | 提取inst[31:12]，左移12位，低位置0 | lui |
| `EXT_J` (11) | J-type | 提取inst[31], inst[19:12], inst[20], inst[30:21]，符号扩展后左移1位 | jal |

### 3.5 MREQ相关控制信号——`ram_rop`

MREQ.addr仅在lw指令中由ALU.C驱动，其余指令不使用。需要`ram_rop`控制信号使能存储器读操作：

| ram_rop取值 | 操作 | 对应指令 |
|------------|------|---------|
| 0 | 不读存储器 | ori, beq, lui, jal, addi, slli, bne |
| 1 | 读存储器 | lw |

---

## 4. 控制信号取值表构建实例

通过上述分析，我们得出了每条指令对应的控制信号取值。将所有指令的控制信号取值汇总，即可构建**控制信号取值表**。

**表5-3 8条miniRV指令的控制信号取值表（原始编码）**

| 指令 | opcode | funct3 | funct7[5] | npc_op | rf_we | rf_wsel | sext_op | alu_op | alub_sel | ram_rop |
|------|--------|--------|-----------|--------|-------|---------|---------|--------|----------|---------|
| addi | 0010011 | 000 | - | 00 | 1 | 00 | 00 | 000 | 0 | 0 |
| ori | 0010011 | 110 | - | 00 | 1 | 00 | 00 | 010 | 0 | 0 |
| slli | 0010011 | 001 | 0 | 00 | 1 | 00 | 00 | 011 | 0 | 0 |
| lui | 0110111 | - | - | 00 | 1 | 10 | 10 | - | - | 0 |
| lw | 0000011 | 010 | - | 00 | 1 | 01 | 00 | 000 | 0 | 1 |
| beq | 1100011 | 000 | - | 01 | 0 | - | 01 | 001 | 1 | 0 |
| bne | 1100011 | 001 | - | 10 | 0 | - | 01 | 001 | 1 | 0 |
| jal | 1101111 | - | - | 11 | 1 | 11 | 11 | - | - | 0 |

**表5-4 8条miniRV指令的控制信号取值表（宏定义名称）**

| 指令 | opcode | funct3 | funct7[5] | npc_op | rf_we | rf_wsel | sext_op | alu_op | alub_sel | ram_rop |
|------|--------|--------|-----------|--------|-------|---------|---------|--------|----------|---------|
| addi | 0010011 | 000 | - | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_ADD | ALUB_EXT | 0 |
| ori | 0010011 | 110 | - | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_OR | ALUB_EXT | 0 |
| slli | 0010011 | 001 | 0 | NPC_PC4 | 1 | WB_ALU | EXT_I | ALU_SLL | ALUB_EXT | 0 |
| lui | 0110111 | - | - | NPC_PC4 | 1 | WB_SEXT | EXT_U | - | - | 0 |
| lw | 0000011 | 010 | - | NPC_PC4 | 1 | WB_MEM | EXT_I | ALU_ADD | ALUB_EXT | 1 |
| beq | 1100011 | 000 | - | NPC_BEQ | 0 | - | EXT_B | ALU_SUB | ALUB_RF | 0 |
| bne | 1100011 | 001 | - | NPC_BNE | 0 | - | EXT_B | ALU_SUB | ALUB_RF | 0 |
| jal | 1101111 | - | - | NPC_JAL | 1 | WB_PC4 | EXT_J | - | - | 0 |

> **表5-4使用说明**：表中`-`表示该控制信号的取值在当前指令中为Don't Care（不影响结果），实际实现时可赋任意值。`funct7[5]`列仅在slli指令中用于区分SLLI与SRAI/SRLI。

### 取值表填写要点

以addi指令为例，说明控制信号取值的设计依据：

- **npc_op = NPC_PC4**：addi顺序执行，PC应加4
- **rf_we = 1**：addi需要将结果写回目标寄存器rd
- **rf_wsel = WB_ALU**：写回数据来源于ALU的加法运算结果
- **sext_op = EXT_I**：addi的立即数位于指令码的[31:20]位，属于I型立即数格式
- **alu_op = ALU_ADD**：addi需要ALU完成rs1与立即数的加法运算
- **alub_sel = ALUB_EXT**：ALU的B端应接SEXT扩展后的立即数
- **ram_rop = 0**：addi不访问数据存储器

---

## 5. 设计控制信号的逻辑表达式

### 5.1 一般表达式推导

确定了各个控制信号的取值之后，每个控制信号都可以表示为指令编码（`opcode`、`funct3`、`funct7`）的逻辑函数。以`rf_we`为例：

```
rf_we = 1 当指令为 addi, ori, slli, lui, lw, jal 时
rf_we = 0 当指令为 beq, bne 时
```

用逻辑表达式描述：

```
rf_we = (opcode == 0010011)                        // addi, ori, slli
      | (opcode == 0110111)                        // lui
      | (opcode == 0000011 & funct3 == 010)         // lw
      | (opcode == 1101111)                        // jal
```

即所有非分支指令都需要写回寄存器堆（除beq、bne外）。

### 5.2 行为级Verilog实现方法

虽然可以通过卡诺图化简每个控制信号的逻辑表达式，但在本课程设计中采用**行为描述法**实现控制单元，即使用Verilog的`assign`语句或`always`块配合`case`语句直接生成控制信号。

首先，根据指令编码定义指令识别信号：

```verilog
// ====== 指令译码 ======
wire ADD_I = (opcode == 7'b0010011) & (funct3 == 3'b000);
wire ORI   = (opcode == 7'b0010011) & (funct3 == 3'b110);
wire SLL_I = (opcode == 7'b0010011) & (funct3 == 3'b001) & (~funct7[5]);
wire LUI   = (opcode == 7'b0110111);
wire LW    = (opcode == 7'b0000011) & (funct3 == 3'b010);
wire BEQ   = (opcode == 7'b1100011) & (funct3 == 3'b000);
wire BNE   = (opcode == 7'b1100011) & (funct3 == 3'b001);
wire JAL   = (opcode == 7'b1101111);
```

然后，基于指令识别信号生成各个控制信号。以`npc_op`为例，采用优先级编码：

```verilog
// ====== NPC控制 ======
reg [1:0] npc_op;
always @(*) begin
    if (JAL)      npc_op = NPC_JAL;  // 无条件跳转
    else if (BEQ) npc_op = NPC_BEQ;  // 相等时跳转
    else if (BNE) npc_op = NPC_BNE;  // 不等时跳转
    else          npc_op = NPC_PC4;  // 顺序执行
end
```

也可以使用`assign`语句配合条件运算符实现：

```verilog
assign npc_op = JAL ? NPC_JAL :
                BEQ ? NPC_BEQ :
                BNE ? NPC_BNE :
                NPC_PC4;
```

其他控制信号的生成方式类似：

```verilog
// ====== 寄存器写使能 ======
assign rf_we = ADD_I | ORI | SLL_I | LUI | LW | JAL;

// ====== 写数据来源选择 ======
assign rf_wsel = JAL    ? WB_PC4  :
                 LW     ? WB_MEM  :
                 LUI    ? WB_SEXT :
                 WB_ALU;  // 默认：ALU运算结果

// ====== 立即数扩展格式 ======
assign sext_op = JAL ? EXT_J :
                 BEQ | BNE ? EXT_B :
                 LUI ? EXT_U :
                 EXT_I;  // 默认：I型扩展

// ====== ALU运算类型 ======
reg [2:0] alu_op;
always @(*) begin
    if (ORI)      alu_op = ALU_OR;
    else if (SLL_I) alu_op = ALU_SLL;
    else if (BEQ | BNE) alu_op = ALU_SUB;
    else if (LW | ADD_I) alu_op = ALU_ADD;
    else          alu_op = ALU_ADD;  // 默认值
end

// ====== ALU的B端来源 ======
assign alub_sel = (BEQ | BNE) ? ALUB_RF : ALUB_EXT;

// ====== 存储器读使能 ======
assign ram_rop = LW;
```

### 5.3 行为描述法与布尔表达式法的比较

| 方法 | 优点 | 缺点 | 适用场景 |
|------|------|------|---------|
| 布尔表达式法 | 逻辑门级实现，面积优化 | 表达式推导繁琐，可读性差 | 资源受限的简单设计 |
| 行为描述法 | 可读性强，易于修改和扩展 | 综合结果可能略大 | 复杂控制单元设计（本课程采用） |

行为描述法的核心思路是"先译码、后生成"——首先将`opcode`/`funct3`/`funct7`译码为指令级别的wire信号，再将这些wire信号组合生成各控制信号。这种方法的优点是：
1. 代码结构与数据通路表、控制信号取值表一一对应，便于验证
2. 新增指令时，只需添加译码信号和修改相应控制信号的生成逻辑
3. 控制信号取值使用宏定义（`NPC_PC4`、`WB_ALU`等），可读性强

> **关于Verilog宏定义**
>
> 控制信号取值表中的`NPC_PC4`、`WB_ALU`等宏名称需要在Verilog代码中通过`` `define ``或`localparam`定义。例如：
>
> ```verilog
> // NPC控制
> localparam NPC_PC4 = 2'b00;
> localparam NPC_BEQ = 2'b01;
> localparam NPC_BNE = 2'b10;
> localparam NPC_JAL = 2'b11;
>
> // 写回选择
> localparam WB_ALU  = 2'b00;
> localparam WB_MEM  = 2'b01;
> localparam WB_SEXT = 2'b10;
> localparam WB_PC4  = 2'b11;
>
> // ALU运算
> localparam ALU_ADD = 3'b000;
> localparam ALU_SUB = 3'b001;
> localparam ALU_OR  = 3'b010;
> localparam ALU_SLL = 3'b011;
>
> // 立即数扩展格式
> localparam EXT_I = 2'b00;
> localparam EXT_B = 2'b01;
> localparam EXT_U = 2'b10;
> localparam EXT_J = 2'b11;
>
> // ALU B端选择
> localparam ALUB_EXT = 1'b0;
> localparam ALUB_RF = 1'b1;
> ```
>
> 这样，控制信号取值表中的宏名称与Verilog代码中的参数定义完全对应，便于阅读和维护。
