## bash

## for 循环
```
for i in 1 2 3 4 5; do
    echo "for ${i}"
done
```

```
for file in `ls /etc`; do
或
for file in $(ls /etc); do
    echo "${file}"
done
```

## if
```
if condition
then
    commond
fi
```

```
if condition
then
    commond
elif condition
then
    commond
else
    commond
fi
```

## switch开关
```
#!/bin/bash

num=1
case $num in
    1 )
        echo "1"
        ;;
    2 )
        echo "2"
        ;;
    3 )
        echo "3"
        ;;
    * )
        echo "not 1 2 3"
        ;;
esac
#输出：1

#!/bin/bash

num=1
case $num in
    1 )
        echo "1"
        ;;&  #有条件向后匹配
    2 )
        echo "2"
        ;;
    3 )
        echo "3"
        ;;
    * )
        echo "not 1 2 3"
        ;;
esac
#输出：
    1
    not 1 2 3

#!/bin/bash

num=1
case $num in
    1 )
        echo "1"
        ;& #无条件向后匹配
    2 )
        echo "2"
        ;;
    3 )
        echo "3"
        ;;
    * )
        echo "not 1 2 3"
        ;;
esac
#输出：
    1
    2
```

## 参数传递
```
$0 - 脚本本身
$1 - 第一个参数
$# - 参数个数

``` 