# gdb调试
1. 调试已经运行的进程
```
gdb -p pid进程id
gdb -p pid进程id -x 命令脚本
例如
    b xx.cpp:行号 if xx1 == num
    p xx2
    bt
    c
    q

```
```
退出调试 Ctrl+c quit
```
2. 执行dump文件
```
gdb xx.exe xx.dump
```
3. gdb修改运行值
```
set var value = 1  // 把value设为1
```
4. up/down 上下查看栈信息
5. layout 用于分割窗口
```
layout src
```