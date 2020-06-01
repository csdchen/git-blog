- 进程内存信息
```
pmap -d [pid]
```

- 内核信息
```
uname -a
cat /proc/version
```

- 系统环境变量
```
sysctl -a
```

- 网络端口查看
    - 程序运行的端口 netstat -ap | grep "程序名"
    - 常用端口查看   netstat -lntup
        - l:listening
        - n:num
        - t:tcp
        - u:udp
        - p:process