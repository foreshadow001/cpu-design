# Verilog 代码规范

良好的代码规范不仅有助于团队协作，还能减少仿真与下板不一致的问题。以下是本课程推荐的 Verilog 编码规范。

---

## 1. 文件命名

| 文件类型 | 命名规范 | 示例 |
|---------|---------|------|
| 设计文件 | 与模块名一致 | `ALU.v`、`NPC.v`、`cpu_core.v` |
| 仿真文件 | 使用 `_sim` 后缀 | `cpu_core_sim.v` |
| 测试文件 | 使用 `_tb` 后缀 | `soc_simple_tb.v` |

---

## 2. 模块命名

- **一个文件只定义一个模块**
- **模块名必须与文件名完全一致**

---

## 3. 信号命名

### 3.1 命名风格

| 信号类型 | 命名风格 | 示例 |
|---------|---------|------|
| wire / reg / 端口 | **小写字母** | `alu_a`、`rf_rd1`、`inst_finished` |
| parameter / localparam | **大写字母** | `CPU_WIDTH`、`DATA_DEPTH` |
| 宏定义（`define） | **大写字母** | `` `ALU_ADD ``、`` `NPC_PC4 `` |

### 3.2 命名规范

- 信号名应具有 **描述性**，能反映信号的功能
- 多单词使用 **下划线** 或 **驼峰式** 命名（推荐下划线风格）
- 避免使用 `a`、`b`、`tmp` 等无意义的命名

### 3.3 信号方向后缀

| 方向 | 后缀 | 示例 |
|-----|------|------|
| 输入信号 | `_i` | `clk_i`、`rst_i`、`data_i` |
| 输出信号 | `_o` | `data_o`、`addr_o`、`wen_o` |

### 3.4 时钟与复位

| 信号 | 命名规范 | 示例 |
|-----|---------|------|
| 时钟 | 以 `clk_` 为前缀 | `clk_sys`、`clk_cpu` |
| 复位 | 以 `rst_` 为前缀 | `rst_sys`、`rstn` |

### 3.5 低电平有效信号

低电平有效信号（Active Low）以 **`n`** 结尾：

- `rstn_i` —— 低电平有效的复位输入
- `wen_n` —— 低电平有效的写使能

---

## 4. 位宽与数据

### 4.1 位序约定

- 统一使用 **下降位序（Descending Bit Order）**
- **最低位（LSB）为 0**

```verilog
reg [31:0] data;  // 推荐：LSB=0
// 不推荐
reg [0:31] data;
```

---

## 5. Module 定义

### 5.1 基本格式

推荐使用 **ANSI 风格** 的端口声明：

```verilog
`timescale 1ns / 1ps

module ALU (
    input  wire         clk_i,
    input  wire         rst_i,
    input  wire [31:0]  a_i,
    input  wire [31:0]  b_i,
    input  wire [ 4:0]  op_i,
    output reg  [31:0]  c_o
);

    // ...

endmodule
```

### 5.2 `timescale 设置

- 仿真文件需要设置 `` `timescale 1ns / 1ps ``
- 综合文件一般不需要（或按工程统一配置）

### 5.3 参数定义

- `localparam`：用于模块内部非覆盖参数
- **全局参数** 应放在 I/O 端口之前定义

```verilog
module FIFO #(
    parameter DATA_WIDTH = 32,
    parameter DEPTH      = 16
) (
    input  wire                clk_i,
    input  wire                rst_i,
    input  wire [DATA_WIDTH-1:0] data_i,
    output reg  [DATA_WIDTH-1:0] data_o
);
    localparam PTR_WIDTH = $clog2(DEPTH);
    // ...
endmodule
```

---

## 6. 模块实例化

### 6.1 实例化命名

使用 `U_模块名_序号` 格式：

```verilog
NPC  U_NPC_0 (
    // ...
);

ALU U_ALU (
    // ...
);
```

### 6.2 推荐使用命名端口连接

```verilog
// 推荐：命名端口连接
ALU U_ALU (
    .clk_i  (cpu_clk),
    .rst_i  (cpu_rst),
    .a_i    (alu_a),
    .b_i    (alu_b),
    .op_i   (alu_op),
    .c_o    (alu_c)
);

// 不推荐：按位置连接（易出错）
ALU U_ALU (cpu_clk, cpu_rst, alu_a, alu_b, alu_op, alu_c);
```

---

## 7. 时序逻辑与组合逻辑分离

### 7.1 基本的书写原则

- **组合逻辑**：使用 `always @(*)`
- **时序逻辑**：使用 `always @(posedge clk)`

### 7.2 组合逻辑示例

```verilog
// 组合逻辑
always @(*) begin
    // 默认值
    result = 'b0;
    case (op)
        `ADD : result = a + b;
        `SUB : result = a - b;
        default : result = 'b0;
    endcase
end
```

### 7.3 时序逻辑示例

```verilog
// 时序逻辑
always @(posedge clk_i or posedge rst_i) begin
    if (rst_i) begin
        pc <= `PC_INIT_VAL;
    end else begin
        pc <= npc;
    end
end
```

---

## 8. 避免产生锁存器（Latch）

组合逻辑中的 `if` 语句必须包含 `else` 分支，`case` 语句必须包含 `default` 分支，否则会综合出锁存器。

```verilog
// 设置默认值是避免 latch 的好方法
always @(*) begin
    data_o = 'b0;  // 默认值
    case (sel)
        2'b00 : data_o = reg0;
        2'b01 : data_o = reg1;
        2'b10 : data_o = reg2;
        default : data_o = 'b0;
    endcase
end
```

---

## 9. 阻塞赋值与非阻塞赋值

- **时序逻辑** 中使用 **非阻塞赋值** `<=`
- **组合逻辑** 中使用 **阻塞赋值** `=`
- **严禁混用！** 混用会导致仿真与下板不一致

---

## 10. 关键路径优化

- 将复杂的组合逻辑分散到多个时钟周期
- 在关键路径上插入流水线寄存器
- 综合后通过 Vivado 的 **时序报告（Timing Report）** 查看关键路径
