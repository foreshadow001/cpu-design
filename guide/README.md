# 计算机设计与实践（2026夏季）| 哈工大（深圳）

课程实验指导书整理。本实验基于 **miniRV 指令集**，目标硬件为 **EGO1 开发板**（XC7A35TCSG324-1）。

## 目录结构

```
guide/
├── README.md                   ← 本文件（索引）
├── 00-course-info.md           （课程须知 — 分组、实验流程、课表）
├── 01-fpga-board.md            （EGO1 / Minisys 开发板使用说明）
├── 02-coding-style.md          （Verilog 代码规范 — 命名、模块定义、实例化）
├── 03-faq.md                   （常见问题 — CPU设计、Trace测试、FPGA下板）
├── 04-submission.md            （作业系统提交指南 — grader.hitsz.edu.cn）
│
├── lab1/                       【实验1：单周期CPU】
│   ├── 00-overview.md          （实验概述 — 目的、内容、要求）
│   ├── 01-warmup.md            （熟悉代码及模板工程 — demo 工程结构、接口信号、addi 实例解析）
│   ├── 00-overview.md          （实验概述 — 5步工程法、44条指令分类、评分标准）
│   ├── 01-warmup.md            （熟悉代码及模板工程 — demo 工程结构、接口信号、addi 实例解析）
│   ├── 02-instructions.md      （miniRV 指令集 — 32寄存器、44条指令详解与速查）
│   ├── 03-components.md        （功能部件设计 — PC/NPC、RF、SEXT、ALU、MREQ、MEXT）
│   ├── 04-datapath.md          （数据通路设计 — 表格驱动法、5条示例逐行分析、综合方法）
│   ├── 05-controller.md        （控制单元设计 — 信号提取、取值表构建实例、Verilog实现）
│   ├── 06-multicycle.md        （多周期指令数据通路 — 访存/乘除法 stall 机制）
│   ├── 07-muldiv.md            （乘除法运算实现 — Booth 乘法器、原码除法器集成到 ALU）
│   ├── 08-divider.md           （除法器设计 — 恢复余数法、加减交替法、参考架构）
│   ├── 09-timing.md            （单周期CPU时序 — 单周期/多周期时序图解读）
│   ├── 10-verify.md            （CPU 功能验证 — Trace 差分测试、debug信号、调试流程）
│   ├── 11-performance.md       （单周期CPU性能分析 — 执行延迟、频率限制）
│   ├── 12-steps.md             （实验步骤清单 — 7 步详细清单、DDL 提醒）
│   ├── A-macros.md             （Verilog 宏定义的使用 — `define、`include）
│   ├── B-constraints.md        （引脚约束文件 — I/O 约束、时钟约束语法）
│   └── C-control-signals.md    ★ 控制信号快速参考 — 全44指令信号速查表、ALU op编码
│
├── trace/                      【Trace 测试框架与工具】
│   ├── 01-framework.md         （测试框架说明 — 差分测试原理、目录结构、运行测试、波形/反汇编调试）
│   ├── 02-remote-env.md        （远程实验平台 — SSH/FTP 连接、MobaXterm）
│   ├── 03-vm.md                （WSL2 虚拟机使用指南）
│   ├── 04-diy-env.md           （自行部署实验环境 — Verilator 安装）
│   └── 05-surfer.md            （Surfer 波形查看器使用指南）
│
└── verify/                     【下板调试与验证】
    ├── 01-trace-debug.md       （Trace 下板调试 — start.bin 测试、数码管结果解读）
    └── 02-online-debug.md      （FPGA 在线调试 — ILA 核、mark_debug、触发条件设置）
```

## 推荐阅读顺序

### 实验1：单周期CPU

| 步骤 | 文件 | 说明 |
|------|------|------|
| 0 | `00-course-info.md` → `01-fpga-board.md` | 了解课程和硬件平台 |
| 1 | `lab1/00-overview.md` → `lab1/01-warmup.md` | 理解实验目标，运行 demo 工程仿真 |
| 2 | `lab1/02-instructions.md` | 熟悉 miniRV 全部 **44** 条指令 |
| 3 | `lab1/03-components.md` | 逐一学习各功能部件设计 |
| 4 | `lab1/04-datapath.md` → `lab1/05-controller.md` | 掌握数据通路表和控制信号表设计方法 |
| 5 | `lab1/06-multicycle.md` | 理解访存和乘除法指令的 stall 机制 |
| 6 | `lab1/07-muldiv.md` → `lab1/08-divider.md` | 实现硬件乘法器和除法器 |
| 7 | `lab1/09-timing.md` | 理解单周期 CPU 时序 |
| 8 | `lab1/10-verify.md` | 了解差分测试验证原理 |
| 9 | `lab1/12-steps.md` | 按步骤清单完成实验 |

### 实验前准备

| 文件 | 说明 |
|------|------|
| `02-coding-style.md` | 代码编写全程需遵循的 Verilog 规范 |
| `lab1/A-macros.md` → `lab1/B-constraints.md` | 宏定义和约束文件的使用 |

### Trace 测试环境

| 文件 | 说明 |
|------|------|
| `trace/01-framework.md` | Trace 框架核心文档，必读 |
| `trace/03-vm.md` | 虚拟机方式（推荐，实验室预装） |
| `trace/02-remote-env.md` | 远程方式（宿舍/自习室使用） |
| `trace/04-diy-env.md` | 自行部署参考 |
| `trace/05-surfer.md` | 波形查看工具参考 |

### 下板调试

| 文件 | 说明 |
|------|------|
| `verify/01-trace-debug.md` | 使用 Trace 程序在下板时进行调试 |
| `verify/02-online-debug.md` | 使用 Vivado ILA 核进行在线调试 |

### 遇到问题

| 文件 | 说明 |
|------|------|
| `03-faq.md` | 常见问题汇总（CPU 设计、Trace 测试、FPGA 下板） |
| `04-submission.md` | 作业提交操作指南 |
| `lab1/C-control-signals.md` | ★ 控制信号快速参考卡 — 全指令信号速查、ALU op编码 |

## 实验2：流水线CPU

实验2 的指导书内容在 `lab1/` 目录中部分章节已涉及（如多周期指令的 stall 机制为流水线冒险处理的基础）。完整实验2 指导请参考课程网站后续更新。

## 关键规则速查

1. **模块层次不可改动**：`miniRV_SoC → cpu_top → cpu_core`，模块名、实例名、接口信号固定
2. **不可修改** `RUN_TRACE` 宏定义相关代码和 `/* verilator public */` 注释
3. **复位后首条指令地址**：`0x00000000`
4. **SoC 复位信号**：Trace 测试框架中 `fpga_rst` 为高电平复位
5. **代码**：仅拷贝 `src/rtl/` 下的源文件到测试框架，不拷贝 `ip/` 目录
6. **提交**：grader.hitsz.edu.cn，`.zip` 格式，< 100MB
