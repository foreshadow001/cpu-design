# EGO1 FPGA 开发板使用须知

本课程在 T2210、T2507 实验室使用 **EGO1 FPGA 开发板** 进行 CPU 下板验证。

---

## 核心芯片

| 参数 | 规格 |
|------|------|
| FPGA 芯片型号 | XC7A35TCSG324-1（Xilinx Artix-7 系列） |
| 逻辑资源 | 5200 个逻辑片（Logic Slices） |
| Block RAM | 50 个 36Kb Block RAM |
| DSP 单元 | 90 个 DSP48E1 |
| 时钟管理 | 5 个时钟管理单元（CMT） |
| 内部时钟频率 | 最高可达 450MHz |

---

## 接口与连接

### USB 接口

- **USB Type-C** JTAG 接口，用于程序下载与调试
- 集成了电源与数据传输功能

### 电源开关

- 开发板上有一个电源拨码开关，用于控制开发板的电源通断

---

## 时钟与复位

### 时钟源

- 板上集成 **100MHz** 有源晶振
- 连接到 FPGA 的 **P17** 引脚

### 复位按键

- **S6** 按键开关
- 连接到 FPGA 的 **P15** 引脚
- **低电平有效（LOW active）**

---

## 输入输出设备

### 拨码开关（DIP Switch）

- 8 个独立拨码开关 + 邻近的 8 位开关
- **向上拨动（UP）= 高电平（HIGH）**

### 按键开关

- **S0 ~ S4**，共 5 个通用按键
- **按下 = 高电平（HIGH）**

### 七段数码管（7-seg Display）

- 共阴极（Common Cathode）
- **高电平有效** 点亮数码管段位 / 位选

### LED 指示灯

- **16 个 LED**
- **高电平点亮（HIGH active）**

---

## 引脚约束

EGO1 开发板的引脚约束文件为 `ego1_pin.xdc`，模板工程已提供基本的约束配置。在添加新的外设接口时，需要参考该文件进行引脚分配。

主要约束语法示例：

```tcl
# 语法：set_property PACKAGE_PIN (pin location) [get_ports (port name)]
set_property PACKAGE_PIN P5 [get_ports sw_i[0]]
set_property PACKAGE_PIN F6 [get_ports led_o[0]]

# IO 电平标准
set_property IOSTANDARD LVCMOS33 [get_ports sw_i[0]]
set_property IOSTANDARD LVCMOS33 [get_ports led_o[0]]
```

IO 电平标准统一设置为 **LVCMOS33**（高电平 3.3V，低电平 0.0V）。

也可以直接在开发板的丝印上读取引脚编号。例如，观察开发板最右侧的拨码开关下方丝印着 "SW0-W4"，表示拨码开关 SW0 对应 FPGA 的 W4 引脚。

---

## 安全注意事项

1. **不得将开发板带出实验室！**
2. **严禁触摸芯片和电路**，避免静电损坏
3. 保持开发板远离 **水和灰尘**
4. 妥善保管开发板的 **防静电袋**
5. 使用完毕后应断开电源连接

---

## 常见问题

### Autoconnect 失败

如果 Vivado 中 Auto Connect 无法识别到开发板：

1. 确保 USB 数据线正确连接 JTAG 接口
2. 确保电源连接正常
3. 确保开发板右上角的电源拨码开关处于 **ON** 状态
4. 在 Vivado Hardware Manager 中重启 server
5. 更换数据线或换一块开发板尝试
6. 检查并安装驱动：`C:\Xilinx\Vivado\2018.3\data\xicom\cable_drivers\nt64\digilent\install_digilent.exe`

### 生成比特流速度慢

- 代码越复杂、IROM 中程序越大，综合/实现/比特流生成时间越长（可能需几十分钟）
- 检查工程名和路径是否包含 **中文或空格**
- 关闭工程后清理临时文件，保留 `.xpr` 和 `.srcs` 目录即可
