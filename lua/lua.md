- 导入模块
```lua
dofile("filedir")
require("filedir")
```

- 传值与传引用
```
除了table是引用传递外，其余基本都是值传递
local a = { x = 100 }
local b = a
b.x = 200
print("a.x = ", a.x)    -- a.x = 200
```

- Lua中的逻辑运算符：与(and)、或(or)和非(not)
    - 所有的逻辑运算符将false和nil视为假，其他任何东西视为真，`0`也视为真
    - "a and b or c ",这类似于C语言中的表达式 a ? b : c
    ```lua
    a = b and c  -- 如果它的第一个操作数为假，就返回第一个操作数；不然返回第二个操作数
    ```

- `ipairs` `pairs`
```
ipairs不能返回nil,只能返回数字0，如果遇到nil则退出
```
```lua
local tabFiles = {
[3] = "test2",
[6] = "test3",
[4] = "test1"
}

for k, v in pairs(tabFiles) do
    print(k, v)
end

for k, v in ipairs(tabFiles) do
    print(k, v)     -- find [1] throw error
end
```

- 元方法
    - __index
    ```
    在调用table不存在的字段时，会调用__index元方法
    __index元方法可以是不一定是一个函数，还可以是一个table。如果是一个函数，则以table和不存在的key作为参数方位该函数，
    例如：__index = function(t,key)
    ```
    - __newindex
    ```
    当对table中不存在的索引赋值时，解释器就会查找__newindex元方法。如果有这个元方法，就调用这个元方法，而不是执行复制
    ```
    - getmetatable(table)
    - setmetatable(table, 元方法/table)
    - [`调用实例`](src/memory.lua)
- 垃圾回收
    - collectgarbage(opt,[,arg])
        - "stop" 停止垃圾收集器
        - "restart"
        - "collect" 执行一次全垃圾收集循环
        - "count" 返回当前Lua中使用的内存量(以KB为单位)
        - "step" 单步执行一个垃圾收
        - [`调用实例`](src/memory.lua)
    - 堆栈用完没有及时恢复
    - 没有及时使用垃圾回收
    - 在函数异常返回或者正常处理返回时，堆栈要进行恢复
    ```
    lua_pop(L, 1);
    // 恢复之前的栈顶位置
    lua_settop(L, 0);
    ```
    - 在调用lua_pcall()时，要调用lua_gc(L, LUA_GCCOLLECT, 0)

## cpp
- <a href="http://www.lua.org/download.html">下载地址</a>
```
1. 添加现有项: src目录下所有的*.c *.h， lua.h lua.hpp lua.c luac.c不用添加
2. c/c++/附加加含目录 src
```
- [调用实例](./src/main.cpp)