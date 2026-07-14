# CPU Design

本仓库用于哈尔滨工业大学（深圳）《计算机设计与实践（2026 夏季）》课程实验，当前处于初始版本。项目以 miniRV 指令集为基础，使用 Verilog 实现 CPU，并通过 Vivado 工程完成仿真、综合、实现和下板验证。

## 项目概况

- 课程目标：完成 miniRV CPU 设计，并逐步扩展到后续流水线 SoC 实验。
- 指令集：miniRV，RV32I 子集。
- 目标开发板：EGO1，XC7A35TCSG324-1。
- 推荐工具：Vivado 2023.2。
- 当前工程：`miniRV/miniRV.xpr`。
- 当前状态：仓库为初始整理版本，后续功能实现、调试记录、版本交接信息需要按本文档约定持续维护。

## 目录结构

```text
.
├── README.md                 # 项目入口、使用说明、版本管理约定
├── CLAUDE.md                 # 给 AI 编程助手的工程上下文
├── guide/                    # 课程实验指导书与调试说明
├── resources/                # 课程资料、控制信号表、数据通路表等参考材料
├── design/                   # 数据通路、控制信号和全指令设计文档
├── hk/                       # 过程资料或表格备份
└── miniRV/                   # Vivado 工程、RTL 源码、仿真文件、约束和 COE 文件
```

重要源码路径：

| 路径 | 说明 |
| --- | --- |
| `miniRV/src/rtl/` | CPU 和 SoC 的 Verilog RTL 源码 |
| `miniRV/src/sim/` | 仿真 testbench |
| `miniRV/src/xdc/` | FPGA 约束文件 |
| `miniRV/src/coe/` | 指令存储器初始化相关文件 |
| `miniRV/src/rtl/defines.vh` | 控制信号、地址空间等宏定义 |
| `miniRV/src/rtl/cpu_core.v` | CPU 核心数据通路与控制连接 |
| `miniRV/src/rtl/Controller.v` | 指令译码和控制信号生成 |
| `miniRV/src/rtl/ALU.v` | 算术逻辑单元 |
| `miniRV/src/rtl/MREQ.v` | 数据存储器访问请求生成 |
| `miniRV/src/rtl/MEXT.v` | load 数据扩展 |

## 推荐阅读顺序

1. 先读 `guide/README.md`，了解课程资料组织方式。
2. 再读 `guide/lab1/00-overview.md` 到 `guide/lab1/12-steps.md`，按实验流程推进。
3. 需要查指令和控制信号时，优先参考：
   - `guide/lab1/02-instructions.md`
   - `guide/lab1/C-control-signals.md`
   - `resources/miniRV-控制信号取值表-完整.md`
   - `design/miniRV-全指令控制信号设计.md`
4. 需要进行 AI 辅助交接或代码理解时，参考 `CLAUDE.md`。

## 基本使用

### 打开工程

使用 Vivado 2023.2 打开：

```text
miniRV/miniRV.xpr
```

### 仿真

在 Vivado GUI 中运行 behavioral simulation，顶层 testbench 为：

```text
miniRV/src/sim/soc_simple_tb.v
```

### 综合、实现和生成 bitstream

使用 Vivado 标准流程：

1. Run Synthesis
2. Run Implementation
3. Generate Bitstream
4. 按课程指导进行下板验证

### 更新指令存储器初始化文件

如需更新 `.asm` 到 `.coe` 的内容，在 Vivado Tcl Console 中执行：

```tcl
source miniRV/update_coe.tcl
```

## 开发约定

- Verilog 代码风格遵循 `guide/02-coding-style.md`。
- 不随意改动顶层模块层次、模块名、实例名和测试框架依赖的接口信号。
- 不随意删除 `RUN_TRACE` 相关宏定义、debug 信号和 `/* verilator public */` 注释。
- 修改 RTL 后，应至少完成 Vivado behavioral simulation；涉及时序、下板或 SoC 外设时，应记录综合、实现、bitstream 或 FPGA 验证结果。
- 大型 Vivado 生成目录、仿真缓存和本地临时文件应谨慎纳入版本管理；后续如调整 `.gitignore`，需在版本日志中说明原因。

## 版本管理与交接日志规范

为便于后续 handoff，本仓库从后续迭代开始必须维护独立版本日志。

### 存储位置

版本管理日志统一存放在：

```text
docs/changelog/CHANGELOG.md
```

如后续单个版本的说明过长，可以在同目录下拆分版本详情文件：

```text
docs/changelog/YYYY-MM-DD-vX.Y.Z.md
```

拆分后，`docs/changelog/CHANGELOG.md` 仍作为总索引，必须链接到对应详情文件。

### 版本号格式

采用语义化版本号：

```text
v主版本.次版本.修订版本
```

示例：

- `v0.1.0`：完成初始可运行功能或阶段性实验功能。
- `v0.2.0`：新增一组指令、模块或验证能力。
- `v0.2.1`：修复 bug、补充注释、修正文档或小范围调整。
- `v1.0.0`：达到阶段验收要求，可作为稳定交付版本。

### 日志条目格式

每个版本必须使用以下 Markdown 格式：

```markdown
## vX.Y.Z - YYYY-MM-DD

### Summary
- 用 1-3 条说明本版本完成了什么。

### Added
- 新增的功能、指令、模块、测试、文档或脚本。

### Changed
- 行为变化、接口变化、目录调整、重构或实现方式变化。

### Fixed
- 修复的问题，尽量说明触发条件和影响范围。

### Verification
- 记录已完成的验证，例如 Vivado behavioral simulation、Trace 测试、综合、下板验证等。
- 如果未验证，必须写明 `Not run` 并说明原因。

### Handoff Notes
- 留给下一位维护者的注意事项、未完成工作、风险点和建议优先级。

### Related Files
- `path/to/file.v`
- `path/to/doc.md`
```

没有内容的分类可以省略，但 `Summary`、`Verification`、`Handoff Notes` 必须保留。

### 提交与日志对应关系

- 每次形成可交接阶段成果时，都应新增或更新一个版本日志条目。
- 一个版本日志条目可以对应多个 commit，但合并或交接前必须保证日志内容完整。
- commit message 建议使用以下前缀：
  - `feat:` 新增功能或指令
  - `fix:` 修复问题
  - `docs:` 文档更新
  - `test:` 测试或验证相关
  - `refactor:` 不改变行为的代码整理
  - `chore:` 工程配置、脚本、依赖或杂项
- 版本日志不替代 commit message；commit message 说明单次修改，版本日志说明阶段性交付。

### Handoff 最低要求

每次交接前，至少确认以下内容已写入 `docs/changelog/CHANGELOG.md`：

1. 当前版本号和日期。
2. 本阶段完成了哪些 RTL、文档或测试工作。
3. 已经跑过哪些验证，结果如何。
4. 尚未完成或存在风险的点。
5. 下一位维护者应优先看的文件。

## 当前待办参考

当前仓库仍处于课程初始工程阶段，后续常见工作包括：

- 补全 miniRV 全 44 条指令的数据通路和控制信号。
- 实现或完善乘法器、除法器。
- 完成 byte/halfword load/store 的地址对齐、写使能和符号扩展逻辑。
- 接入 Trace 测试并记录验证结果。
- 为阶段性成果维护 `docs/changelog/CHANGELOG.md`。

具体任务应以课程要求、`guide/` 文档和实际代码状态为准。
