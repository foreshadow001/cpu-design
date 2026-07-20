# CPU Design

本仓库用于哈尔滨工业大学（深圳）《计算机设计与实践（2026 夏季）》课程实验。项目以 miniRV (RV32I 子集) 指令集为基础，使用 Verilog 实现 CPU，并通过 Vivado 工程完成仿真、综合、实现和下板验证。

## 项目概况

| 项目 | 说明 |
|------|------|
| 课程目标 | 完成 miniRV 单周期 CPU → 5级流水线 CPU → SoC 实验 |
| 指令集 | miniRV (RV32I 子集)，44 条指令 |
| 目标开发板 | EGO1，XC7A35TCSG324-1 |
| 推荐工具 | Vivado 2023.2 |
| 当前工程 | `miniRV/miniRV.xpr` |
| **当前状态** | **44/45 Trace 测试通过** (流水线 CPU)，仅 `start` 失败（外设 MMIO 问题，非 CPU 逻辑） |

已完成：
- 完整 44 条 miniRV 指令的单周期数据通路和控制信号设计
- 5 级流水线（IF→ID→EX→MEM→WB），支持转发、load-use 停顿、mul/div 流水线冻结
- 所有 R 型/I 型/S 型/B 型/U 型/J 型指令通过 Trace 差分测试
- 乘除法器：顺序移位乘、恢复余数除，参数化宽度

## 目录结构

```text
.
├── README.md                 # 项目入口、使用说明、版本管理约定
├── CLAUDE.md                 # 给 AI 编程助手的工程上下文（架构、冒险、测试细节）
├── guide/                    # 课程实验指导书与调试说明
│   ├── README.md             # 课程资料组织方式
│   ├── lab1/                 # 实验一：单周期 CPU 设计
│   ├── lab2/                 # 实验二：流水线 CPU + SoC
│   │   ├── lab2-A/           # 实验二-A：流水线 CPU
│   │   └── lab2-B/           # 实验二-B：系统总线与 SoC
│   ├── trace/                # Trace 测试框架说明
│   └── verify/               # 调试与验证说明
├── resources/                # 课程资料、控制信号表、数据通路表等参考材料
├── design/                   # 数据通路图、控制信号设计和流水线架构文档
├── hk/                       # 过程资料或表格备份
└── miniRV/                   # Vivado 工程、RTL 源码、仿真文件、约束和 COE 文件
```

### 重要源码路径

| 路径 | 说明 |
|------|------|
| `miniRV/src/rtl/defines.vh` | 控制信号、地址空间等宏定义 |
| `miniRV/src/rtl/cpu_core.v` | **5 级流水线核心**：数据通路、冒险检测、停顿/刷新控制 |
| `miniRV/src/rtl/Controller.v` | 指令译码和控制信号生成（44 条指令） |
| `miniRV/src/rtl/ForwardingUnit.v` | EX 级转发 MUX 选择信号生成 |
| `miniRV/src/rtl/ALU.v` | 算术逻辑单元（含顺序乘法器、除法器） |
| `miniRV/src/rtl/multiplier.v` | 顺序乘法器（参数化 WIDTH，移位加） |
| `miniRV/src/rtl/divider.v` | 顺序除法器（参数化 WIDTH，恢复余数） |
| `miniRV/src/rtl/MREQ.v` | 数据存储器访问请求生成 |
| `miniRV/src/rtl/MEXT.v` | load 数据扩展 |
| `miniRV/src/rtl/SEXT.v` | 立即数符号扩展 |
| `miniRV/src/rtl/NPC.v` | 下一条 PC 计算 |
| `miniRV/src/rtl/PC.v` | 程序计数器寄存器 |
| `miniRV/src/rtl/RF.v` | 寄存器文件（32×32） |
| `miniRV/src/rtl/cpu_top.v` | CPU 顶层封装 |
| `miniRV/src/rtl/miniRV_SoC.v` | SoC 顶层 |
| `miniRV/src/sim/soc_simple_tb.v` | Vivado 仿真 testbench |
| `miniRV/src/xdc/` | FPGA 约束文件 |
| `miniRV/src/coe/` | 指令存储器 COE 文件 |

## 推荐阅读顺序

1. **`guide/README.md`** → 了解课程资料组织方式。
2. **实验一（单周期）**：`guide/lab1/00-overview.md` → `guide/lab1/12-steps.md`，按实验流程推进。
3. **实验二-A（流水线）**：`guide/lab2/lab2-A/0-overview.md` → `guide/lab2/lab2-A/7-step.md`。
4. **实验二-B（SoC 总线）**：`guide/lab2/lab2-B/0-overview.md` → `guide/lab2/lab2-B/7-llama.md`。
5. **查指令/控制信号时**，优先参考：
   - `guide/lab1/02-instructions.md`
   - `guide/lab1/C-control-signals.md`
   - `resources/miniRV-控制信号取值表-完整.md`
   - `design/miniRV-全指令控制信号设计.md`
6. **流水线架构细节**：`CLAUDE.md`（冒险处理、mul/div 冻结机制、Trace 验证）
7. **调试方法**：`guide/verify/01-trace-debug.md`（Trace 比对）、`guide/verify/02-online-debug.md`（在线调试）

## 基本使用

### 打开工程

```text
miniRV/miniRV.xpr
```

### Vivado 仿真

在 Vivado GUI 中运行 behavioral simulation，顶层 testbench 为：

```text
miniRV/src/sim/soc_simple_tb.v
```

### Trace 差分测试

测试框架位于 WSL Ubuntu-24.04 中。构建并运行：

```bash
cd /home/foreshadow/cdp-tests
make build                           # 编译
make run TEST=<name>                 # 运行单个测试（如 TEST=mul）
```

运行全部 45 个测试：

```bash
for t in addi add and andi auipc beq bge bgeu blt bltu bne div divu jal jalr lb lbu lh lhu lui lw mul mulh mulhu or ori rem remu sb sh sll slli slt slti sltiu sltu sra srai srl srli sub sw xor xori start; do
    make run TEST=$t
done
```

RTL 源码修改后需同步到测试目录：

```bash
cp miniRV/src/rtl/*.v miniRV/src/rtl/*.vh /home/foreshadow/cdp-tests/mySoC/
```

调试版本位于 `cdp-debug/`（含 PIPE `$display` 和 DBG/TICK printf）。

### 综合、实现和生成 bitstream

使用 Vivado 标准流程：Run Synthesis → Run Implementation → Generate Bitstream → 下板验证。

### 更新指令存储器

Vivado Tcl Console：

```tcl
source miniRV/update_coe.tcl
```

## 开发约定

- Verilog 代码风格遵循 `guide/02-coding-style.md`。
- **不随意改动**顶层模块层次、模块名、实例名和测试框架依赖的接口信号。
- **不随意删除** `RUN_TRACE` 相关宏定义、debug 信号和 `/* verilator public */` 注释。
- 修改 RTL 后，至少完成 Vivado behavioral simulation；涉及时序、下板或 SoC 外设时，记录综合、实现、bitstream 或 FPGA 验证结果。
- 三处源文件需同步：`miniRV/src/rtl/`、`resources/test_case/`、`cdp-tests/mySoC/`。

## Trace 测试框架约束（不可违反）

1. 模块层次不可改动：`miniRV_SoC → cpu_top → cpu_core`
2. 不可修改任何 `RUN_TRACE` 宏定义块
3. 不可删除或修改 `/* verilator public */` 注释
4. SoC 顶层复位 `fpga_rst` 在 Trace 环境中是**高电平复位**
5. 系统复位后首条指令地址为 `0x00000000`
6. 仅拷贝 `src/rtl/` 下源文件到 `cdp-tests/mySoC/`，不拷贝 `ip/` 目录

## 版本管理与交接日志规范

### 存储位置

```text
docs/changelog/CHANGELOG.md
```

如单个版本说明过长，可在同目录拆分版本详情文件并链接。

### 版本号格式

语义化版本号 `v主版本.次版本.修订版本`：
- `v0.1.0`：初始可运行功能或阶段性实验功能
- `v0.2.0`：新增一组指令、模块或验证能力
- `v0.2.1`：修复 bug、补充注释、修正文档或小范围调整
- `v1.0.0`：达到阶段验收要求

### 日志条目格式

```markdown
## vX.Y.Z - YYYY-MM-DD

### Summary
### Added
### Changed
### Fixed
### Verification
### Handoff Notes
### Related Files
```

`Summary`、`Verification`、`Handoff Notes` 必须保留。

### 提交与日志对应关系

- 每次形成可交接阶段成果时，新增或更新版本日志条目。
- commit message 前缀：`feat:` / `fix:` / `docs:` / `test:` / `refactor:` / `chore:`

### Handoff 最低要求

1. 当前版本号和日期
2. 本阶段完成了哪些 RTL、文档或测试工作
3. 已完成的验证和结果
4. 尚未完成或存在风险的点
5. 下一位维护者应优先看的文件

## 当前状态

**已完成**：
- 44/45 Trace 测试通过（所有单周期 ALU、load、store、branch、jump、mul/div 指令）
- 5 级流水线：IF/ID/EX/MEM/WB，含 IRAM/DRAM BRAM 1-cycle 延迟适配
- 转发：EX-stage forwarding + ID-stage forwarding（背靠背依赖）
- Load-use 冒险：1-cycle 停顿 + BRAM 重同步
- Mul/div 流水线冻结：`mul_div_entering` 自清脉冲 + `ex_mul_div_busy`，重复检测 + ALU 抑制
- 控制冒险：分支预测不跳转（2-cycle 惩罚）、JAL ID 级解析（1-cycle）、JALR EX 级解析（2-cycle）

**待完成**：
- `start` 测试：调试外设（MMIO）访问
- Vivado 综合 / 实现 / 时序收敛
- FPGA 下板验证
- 性能分析：基准程序 CPI 测量
