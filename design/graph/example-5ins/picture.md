下面是一份**可以直接作为 AI（如 Visio AI、draw.io AI、Mermaid、Graphviz 或 CAD 绘图）输入的结构描述**。我按照**模块、位置、端口、连线、文字标注**逐一描述，做到尽可能唯一确定整个数据通路，而**不包括页面的大标题和项目符号标题**。

---

# 整体布局

整个数据通路采用**从左到右**的数据流。

最左侧为 **Inst_ROM**。

左下为 **NPC** 和 **PC**。

中间偏上为 **Controller**。

中间偏下依次为 **SEXT**、两个MUX、**RF**、ALU。

右侧依次为 **MREQ**、**MEXT**、最右侧 **Data_RAM**。

外围使用一条总线连接 PC、Controller、SEXT、ALU、MREQ、MEXT 等模块。

---

# 1 Inst_ROM

位于画面最左侧。

采用虚线矩形。

标题：

```
Inst_ROM
```

框内有两行文字：

```
指令
取指地址
```

接口：

左侧无接口。

右侧输出

```
指令
```

连接 Controller。

左下输入

```
取指地址
```

来自 PC。

---

# 2 NPC

位于左下。

矩形。

标题：

```
NPC
```

左侧四个输入，自上而下：

```
PC
op
br
offset
```

右侧两个输出：

```
npc
pc4
```

顶部有

```
reset
```

文字。

npc 输出连接 PC。

pc4 输出进入中部写回MUX。

---

# 3 PC

NPC右侧。

矩形。

标题：

```
PC
```

顶部输入：

```
rst
```

左侧输入：

```
din
```

底部输入：

```
clk
```

右侧输出：

```
pc
```

pc 输出：

一路返回 Inst_ROM 的取指地址。

一路送往 NPC 的 PC 输入。

---

# 4 Controller

位于整个图中央偏上。

矩形。

标题：

```
Controller
```

左侧四个输入：

```
opcode
funct3
funct7
```

每个输入左边标注对应位段：

```
6:0
14:12
31:25
```

输出全部位于右侧。

从上到下依次：

```
sext_op
npc_op
ram_rop
alu_op
alub_sel
rf_wsel
```

底部还有

```
rf_we
```

其中：

rf_we 向下连接 RF。

rf_wsel 向下连接写回MUX。

alub_sel 向下连接 ALU 前MUX。

alu_op 连接 ALU。

ram_rop 连接 MREQ。

npc_op 回到 NPC。

sext_op 回到 SEXT。

---

# 5 SEXT

位于 Controller 正下方。

矩形。

标题：

```
SEXT
```

左侧输入：

```
din
```

来自指令。

左下输入：

```
op
```

来自 Controller。

右侧输出：

```
ext
```

ext 输出：

一路送 ALU 输入MUX。

一路送 NPC offset。

---

# 6 RF

位于中间。

矩形。

标题：

```
RF
```

左侧输入五个：

```
rR1
rR2
wR
we
wD
```

对应来源：

rR1 ← 指令19:15

rR2 ← 指令24:20

wR ← 指令11:7

we ← Controller

wD ← 写回MUX

底部：

```
clk
```

输入。

右侧两个输出：

```
rD1
rD2
```

rD1→ALU A

rD2→ALU前MUX

---

# 7 写回MUX

位于 RF 左下。

竖直长方形MUX。

共有三个输入：

上：

ALU结果

中：

Data Memory扩展数据

下：

PC+4

输出：

连接 RF.wD

选择信号：

Controller.rf_wsel

---

# 8 ALU输入MUX

位于 RF 与 ALU 之间。

竖直MUX。

两个输入：

上：

SEXT.ext

下：

RF.rD2

输出：

ALU.B

控制：

Controller.alub_sel

---

# 9 ALU

位于中央偏右。

标题：

```
ALU
```

三角形。

左侧两个输入：

```
A
B
```

A：

来自 RF.rD1

B：

来自MUX

顶部输入：

```
op
```

来自 Controller。

右侧输出：

```
C
```

ALU输出：

一路到 MREQ.ram_addr

一路到 MEXT.b_offs

一路到 写回MUX

---

# 10 MREQ

位于 ALU 右上。

矩形。

标题：

```
MREQ
```

左侧输入四个：

```
ram_rop
ram_wop
ram_wdata
ram_addr
```

来源：

ram_rop ← Controller

ram_wop ← Controller（与ram_rop共线）

ram_wdata ← RF.rD2

ram_addr ← ALU

右侧输出四个：

```
da_ren
da_addr
da_wen
da_wdata
```

连接 Data_RAM。

---

# 11 MEXT

位于 ALU 右下。

矩形。

标题：

```
MEXT
```

左侧输入：

```
op
```

来自 Controller。

右侧输入：

```
din
```

来自 Data_RAM。

底部输入：

```
b_offs
```

位宽标注：

```
1:0
```

来自 ALU 输出最低两位。

右侧输出：

```
ext
```

输出进入写回MUX。

---

# 12 Data_RAM

位于最右。

虚线矩形。

标题：

```
Data_RAM
```

框内两部分文字：

上方：

```
读使能
读地址
```

下方：

```
读数据
```

接口：

左侧输入：

```
da_ren
da_addr
da_wen
da_wdata
```

来自 MREQ。

左侧输出：

```
读数据
```

送入 MEXT。

---

# 指令字段分配

在 Controller 左侧标注：

```
6:0      → opcode
14:12    → funct3
31:25    → funct7
```

RF 左侧标注：

```
19:15 → rR1
24:20 → rR2
11:7  → wR
```

SEXT 左侧输入：

```
31:7
```

表示立即数来自指令31:7。

---

# 主数据流

整个数据流如下：

```
PC
 ↓
Inst_ROM
 ↓
Instruction
 ↓
Controller

Instruction
 ↓
RF

Instruction
 ↓
SEXT

RF.rD1
        \
         → ALU → ALU结果
RF.rD2 /

ALU结果
     ├→ 写回MUX
     ├→ MREQ
     └→ MEXT(b_offs)

MREQ
 ↓
Data_RAM
 ↓
MEXT
 ↓
写回MUX
 ↓
RF.wD

PC
 ↓
Inst_ROM
```

---

# 控制信号流

Controller 输出控制信号如下：

```
sext_op → SEXT
npc_op  → NPC
ram_rop → MREQ
ram_wop → MREQ
alu_op  → ALU
alub_sel→ ALU输入MUX
rf_wsel → 写回MUX
rf_we   → RF
```

---

以上描述已经细化到**模块位置、接口名称、位宽标注、MUX位置、连线方向和控制信号**，基本可以仅凭文字重建出与图片一致的数据通路图。
