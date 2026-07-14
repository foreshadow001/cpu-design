下面是提取整理后的 **Markdown** 版本。

| 指令 | opcode | funct3 | funct7 | npc_op | rf_we | rf_wsel | sext_op | alu_op | alub_sel | ram_rop |
|------|--------|--------|--------|---------|-------|----------|----------|--------|-----------|---------|
| ori  | 0010011 | 110 | - | NPC_PC4 | 1 | WB_ALU | EXT_I | OR | ALUB_EXT | 0 |
| lui  | 0110011 | - | - | NPC_PC4 | 1 | WB_EXT | EXT_U | - | - | 0 |
| lw   | 0000011 | 010 | - | NPC_PC4 | 1 | WB_RAM | EXT_I | ADD | ALUB_EXT | WORD |
| beq  | 1100011 | 000 | - | NPC_BRCH | 0 | - | EXT_B | EQ | ALUB_RS2 | 0 |
| jal  | 1101111 | - | - | NPC_JMP | 1 | WB_PC4 | EXT_J | - | - | 0 |

### 宏定义

```verilog
`define NPC_PC4   2'b00
`define NPC_BRCH  2'b01
`define NPC_JMP   2'b10
```

### npc_op 含义

| 宏          | 含义                                  |
| ---------- | ----------------------------------- |
| `NPC_PC4`  | NPC 部件输出 **PC + 4** 作为下一条指令地址。      |
| `NPC_BRCH` | NPC 部件根据 **ALU 标志位** 确定下一条指令地址。     |
| `NPC_JMP`  | NPC 部件输出 **PC + offset** 作为下一条指令地址。 |

如果你准备把这份文档放到 GitHub 或 Typora 中，上述 Markdown 可以直接渲染成与原图基本一致的表格。
