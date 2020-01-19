
## 静态局部变量的初始化
- [参考](https://www.cnblogs.com/novice-dxx/p/7094690.html)
- 在C++中，初始化时在执行相关代码时才会进行初始化
- 在C中，初始化发生在代码执行之前，编译阶段分配好内存之后，就会进行初始化
```
在不确定编译器是否会对多线程环境下静态局部变量初始化加锁的情况下，尽量不要使用初始化的局部静态变量
```

## new与malloc
- [参考](https://www.cnblogs.com/QG-whz/p/5140930.html)
- 申请内存位置
```
new操作符从自由存储区（free store）上为对象动态分配内存空间，而malloc函数从堆上动态分配内存
自由存储区是C++基于new操作符的一个抽象概念, 取决于operator new 的实现细节
```
- new返回类型安全性
- 内存分配失败
```
new内存分配失败时，会抛出bac_alloc异常
malloc分配内存失败时返回NULL
```
- new不需要指定内存大小
- new调用构造函数/析构函数
- 数组的处理
```
new[]与delete[]来专门处理数组类型
```
- opeartor new /operator delete可以被重载
- 重新分配内存
```
malloc分配的内存后，可以使用realloc函数进行内存重新分配实现内存的扩充
```

---
[目录](./README.md)

[主目录](../README.md)