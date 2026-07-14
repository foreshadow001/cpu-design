| 单元部件 | 取指单元 |  |  |  | 译码单元 |  |  |  |  | 执行单元 |  | 存储单元 |  |  |  |
|----------|----------|--|--|--|----------|--|--|--|--|----------|--|----------|--|--|--|
| 部件 | PC | NPC |  |  | RF |  |  |  | SEXT | ALU |  | MREQ |  | MEXT |  |
| 输入 | npc | PC | offset | br | rR1 | rR2 | wR | wD | imm | A | B | addr | wd | din | b_offs |
| ori | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | IN.inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| lui | NPC.npc | PC.pc | - | - | - | - | IN.inst[11:7] | SEXT.ext | IN.inst[31:12] | - | - | - | - | - | - |
| lw | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | MEXT.ext | IN.inst[31:20] | RF.rD1 | SEXT.ext | ALU.C | - | IN.rd | ALU.C[1:0] |
| beq | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | - | - | IN.inst[31\|7\|30:25\|11:8] | RF.rD1 | RF.rD2 | - | - | - | - |
| jal | NPC.npc | PC.pc | SEXT.ext | - | - | - | IN.inst[11:7] | NPC.pc4 | IN.inst[31\|19:12\|20\|30:21] | - | - | - | - | - | - |
| 完整 | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C / SEXT.ext / MEXT.ext / NPC.pc4 | IN.inst[31:20] / IN.inst[31:12] / IN.inst[31\|7\|30:25\|11:8] / IN.inst[31\|19:12\|20\|30:21] | RF.rD1 | RF.rD2 / SEXT.ext | ALU.C | - | IN.rd | ALU.C[1:0] || 单元部件 | 取指单元 |  |  |  | 译码单元 |  |  |  |  | 执行单元 |  | 存储单元 |  |  |  |
|----------|----------|--|--|--|----------|--|--|--|--|----------|--|----------|--|--|--|
| 部件 | PC | NPC |  |  | RF |  |  |  | SEXT | ALU |  | MREQ |  | MEXT |  |
| 输入 | npc | PC | offset | br | rR1 | rR2 | wR | wD | imm | A | B | addr | wd | din | b_offs |
| ori | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | ALU.C | IN.inst[31:20] | RF.rD1 | SEXT.ext | - | - | - | - |
| lui | NPC.npc | PC.pc | - | - | - | - | IN.inst[11:7] | SEXT.ext | IN.inst[31:12] | - | - | - | - | - | - |
| lw | NPC.npc | PC.pc | - | - | IN.inst[19:15] | - | IN.inst[11:7] | MEXT.ext | IN.inst[31:20] | RF.rD1 | SEXT.ext | ALU.C | - | IN.rd | ALU.C[1:0] |
| beq | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | - | - | IN.inst[31\|7\|30:25\|11:8] | RF.rD1 | RF.rD2 | - | - | - | - |
| jal | NPC.npc | PC.pc | SEXT.ext | - | - | - | IN.inst[11:7] | NPC.pc4 | IN.inst[31\|19:12\|20\|30:21] | - | - | - | - | - | - |
| 完整 | NPC.npc | PC.pc | SEXT.ext | ALU.br | IN.inst[19:15] | IN.inst[24:20] | IN.inst[11:7] | ALU.C / SEXT.ext / MEXT.ext / NPC.pc4 | IN.inst[31:20] / IN.inst[31:12] / IN.inst[31\|7\|30:25\|11:8] / IN.inst[31\|19:12\|20\|30:21] | RF.rD1 | RF.rD2 / SEXT.ext | ALU.C | - | IN.rd | ALU.C[1:0] |