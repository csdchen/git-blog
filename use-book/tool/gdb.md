
1. 调试已经运行的进程
```
gdb -p pid进程id -x 命令脚本
例如
    b xx.cpp:行号 if xx1 == num
    p xx2
    bt
    c
    q


gdb -p pid进程id
```
[例子]()

2. 调试core文件
```
gdb XXX.exe core-file
```

3. return 与 finish
```
1. return - 立即中断当前函数运行并返回, 当前函数的剩余语句将不被执行, 设定当前函数的返回值
2. finish - 程序执行到当前函数返回之后停止，当前函数的剩余语句将会正常运行
```

4. l list 查看源代码

5. 修改变量
```
set val=xxx
print val=xxx
set width是GDB的命令，所以，出现了“Invalid syntax in expression”的设置错误
使用set var命令来告诉GDB，width不是你GDB的参数，而是程序的变量名，如：
(gdb) set var width=47
```

6. 设置观察点
```
watch <expr>
为表达式（变量）expr设置一个观察点。一量表达式值有变化时，马上停住程序。

rwatch <expr>
当表达式（变量）expr被读时，停住程序。

awatch <expr>
当表达式（变量）的值被读或被写时，停住程序
```

7. 查看信息
```
info break 查看断点
info watchpoints 查看观察点
```

8. 维护停止点
    - 清除
    ```
    clear 清除所有断点

    ```

9. 执行
    - s 有函数调用，进入该函数
    - n 不进入该函数
    - u 跳出循环体

10. 栈
    - bt
    - bt <n>  - 打印栈顶上n层的栈信息
    - bt <-n> - 打印栈底下n层的栈信息
    - up <n>   - 向栈的上面移动n层
    - down <n> - 向栈的下面移动n层
    - info frame   - 打印出更为详细的当前栈层的信息
    - info args    - 打印出当前函数的参数名及其值。
    - info locals  - 打印出当前函数中所有局部变量及其值。
    - info catch   - 打印出当前的函数中的异常处理信息

11. 跳转执行
```
jump file:line
最好是同一个函数中进行跳转
```

12. 显示选项
    - set pretty on  - 显示结构体时会比较漂亮
    ```
    $1 = {
    next = 0x0,
    flags = {
    sweet = 1,
    sour = 1
    },
    meat = 0x54 "Pork"
    }
    ```
    - set pretty off
    ```
    $1 = {next = 0x0, flags = {sweet = 1, sour = 1}, meat = 0x54 "Pork"}
    ```
    - set union on   - 显式其内的联合体数据
    - set print static-members on - 显示其中的静态数据成员
    - set print object on - 如果一个对象指针指向其派生类，如果打开这个选项，GDB会自动按照虚方法调用的规则显示输出

13. 自定义用户命令
    - 基本实例
    ```
    define 名字
        命令块
    end
    ```
    - ~/.gdbinit 放在尾部
    - 
