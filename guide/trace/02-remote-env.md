# A. 远程平台使用指南

> **Warning:** 严禁使用远程实验环境做与教学无关事宜，杜绝使用公共资源挖矿等，一经发现将严肃处理，感谢配合！

## 1. 速查信息

远程实验平台 IP 地址：**10.249.12.98**，端口号：**6666**

> **提示：** 用户名和初始密码都是 **你的学号**，出于安全考虑，建议你初次登录后修改初始密码。

远程实验平台共有 8 个计算节点，每一个计算节点都提供相同的服务，可能你每次登录的计算节点会不一样，但无须担心，你看到的文件都是一样的。

> [图片描述] 远程实验平台计算节点架构示意图，展示 8 个计算节点连接到共享存储

## 2. 快速入门

### 2.1 环境准备

需要配合远程实验平台使用的软件：

- MobaXterm

> **不要用 VSCode 连接远程平台！** 由于服务器资源有限，请尽量不使用 VSCode 连接远程平台（回想一下计算机系统实验的远程平台使用体验）。

### 2.2 使用 MobaXterm

#### 2.2.1 SSH 登录

MobaXterm 是一款远程控制工具，支持创建 SSH、Telnet、Rsh、Xdmc、RDP、VNC、FTP、SFTP、串口（Serial COM）、本地 Shell、Mosh、AWS、WSL（微软子系统）等超多连接功能。MobaXterm 提供了人性化的操作界面，支持与主流的操作系统连接进行控制和管理操作，功能十分强大。

打开 MobaXterm，单击打开位于左上角的工具 `Session`，选择 `New sessions` 打开新建窗口，选择 `SSH`，输入远程服务器的 IP 地址、登陆用户名及端口（**端口号：6666**），点击 OK。

> [图片描述] MobaXterm 新建 SSH Session 的配置界面，填入远程主机 IP 地址、用户名和端口号

在弹出的对话框中，选择 SSH。

> [图片描述] MobaXterm 选择 SSH 连接类型的对话框

SSH 配置信息如下：

> [图片描述] MobaXterm SSH 配置完成后的界面

输入密码：

> [图片描述] MobaXterm 输入密码的界面

进入终端。

> [图片描述] MobaXterm 成功连接远程平台后的终端界面

#### 2.2.2 FTP 文件传输

SSH 远程登录完毕，双击左下角的 `Sftp`，就出现了远程服务器的文件目录。

> [图片描述] MobaXterm 左侧 SFTP 文件浏览界面

接下来可以点击按钮 `Upload to current folder` 或者 `Download selected files`，在 Windows 系统和远程实验平台之间上传或下载文件。

> **注意事项：** 使用完毕后，需在 MobaXterm 中输入 `exit` 命令退出！

### 2.3 下载 Trace 测试包

接下来，我们将 `cdp-tests` 测试源码包复制到自己的工作空间。

参考测试框架说明，在终端中执行相应的 `git clone` 命令下载测试框架：

```bash
# miniRV 指令集
git clone https://gitee.com/hitsz-cslab/cdp-tests.git

# miniLA 指令集
git clone -b miniLA https://gitee.com/hitsz-cslab/cdp-tests.git
```

你应该会看到这样的输出：

```
 1|Cloning into 'cdp-tests'...
 2|done.
```

这代表你已经将 `cdp-tests` 的副本下载到自己的工作空间了。

### 2.4 编译测试

在终端中进入 `cdp-tests` 目录并执行 `make` 命令：

```bash
cd cdp-tests
make
```

此时，提示 top 模块有错误，这时你就可以在 `mySoC` 目录下添加你自己的 CPU 代码了，详见测试框架说明。

## 3. 一些进阶指引

### 3.1 使用 SSH 密钥快捷认证

有没有感觉每次都要输入密码非常麻烦？SSH 密钥可以让认证流程自动化，大大解放双手。

在 **本地** Windows 下，以管理员身份打开 CMD，输入：

```bash
ssh-keygen
```

跟随指引，一路回车，便可完成 SSH 密钥的生成。**请务必保存好自己的私钥，不要泄露！**

> [图片描述] Windows 命令行下执行 ssh-keygen 的界面

接下来，将私钥加入到自己的身份认证中。在终端继续输入：

```bash
ssh-add 你的私钥的完整路径
# 例如：
ssh-add C:\Users\willson\.ssh\id_rsa_priv_20210909
```

在你的 Windows 上将公钥文件打开（用你喜欢的纯文本编辑器，比如记事本或者 VS Code），复制其中的内容。

最后，登录你想要快捷认证的计算节点的终端，并执行下面的命令：

```bash
mkdir -p ~/.ssh
vi ~/.ssh/authorized_keys
```

这会打开一个文件编辑界面。按下 `i` 按键，进入编辑模式，并粘贴到上面节点终端中编辑界面的一个新行里。按下 `Esc`，按下 `:wq` 可保存并退出。如果不放心，可以 `cat ~/.ssh/authorized_keys` 并检查输出和你刚才贴进去的是不是一样的。

配置完成后，下次你从 Windows 登陆时，应该就无需密码认证了。

## 4. Q&A

### 4.1 我不是 Windows 10 系统，这会带来什么问题吗？

#### 4.1.1 我在使用 Linux/macOS？

Visual Studio Code 也有 Linux 版和 macOS 版，具体操作大同小异，毕竟环境主要在服务器上。

#### 4.1.2 我正在使用旧的 Windows 版本/我没有更新我的 Windows 10 系统？

请更新你的系统。使用过时的系统有各种各样的风险，其中最大的是与时代脱轨。

#### 4.1.3 我正在使用 Windows 11？

此教程完全兼容 Windows 11。

### 4.2 我输入的所有命令看起来都是对的，但是为什么运行失败了？

确保你输入的是正常的半角英文字符与英文标点符号。

> [图片描述] 展示全角字符（错误）与半角字符（正确）的对比示例

这可以通过一起按下 Shift + 空格，或者切换到英文输入法解决。

**永远不要在中文输入法下输入命令！**
