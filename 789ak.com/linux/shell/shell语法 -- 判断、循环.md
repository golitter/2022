#### 判断语句

```
if [ condition ];then
    语句1
    语句2
    ...
fi
# or
if [ condition ]
then
	...
if
```

e.g.

```
#! /bin/bash
a=3
b=4
if [ $a -lt  $b ];then
        echo "a < b"
fi
```

##### 单层if-else

```
if [ condition ]
then
    语句1
    语句2
    ...
else
    语句1
    语句2
    ...
fi
```

e.g

```
#! /bin/bash

a=3
if [ $a -gt 1 ];
then
        echo "a > 1"
else
        echo "a < 1"
fi
```

##### 多层if-else-elif-else

```
if [ condition ]
then
    语句1
    语句2
    ...
elif [ condition ]
then
    语句1
    语句2
    ...
elif [ condition ]
then
    语句1
    语句2
else
    语句1
    语句2
    ...
fi
```

e.g.

```
#! /bin/bash

if [ $1 -gt 10 ];then
        echo "$1 > 10"
elif [ $1 -gt 5 ];then
        echo "$1 > 5"
elif [ $1 -gt 0 ];then
        echo "$1 > 0"
else
        echo "$1 <= 0"
fi
```

注意事项：

- [ condition ] 中括号和条件判断式之间必须有空格
- if后要有空格

#### case ... esac形式

```
case $变量名称 in
    值1)
        语句1
        语句2
        ...
        ;;  # 类似于C/C++中的break
    值2)
        语句1
        语句2
        ...
        ;;
    *)  # 类似于C/C++中的default
        语句1
        语句2
        ...
        ;;
esac
```

e.g.

```
#! /bin/bash

a=10

case $a in
        1)
        echo '$a is 1'
        ;;
        2)
        echo '$a is 2'
        ;;
        3)
        echo '$a is 3'
        ;;
        *)
        echo '$a is *'
        ;;
esac
```

注意事项：

- case行尾必须为单词“in”，每一个模式匹配必须以右括号“)”结束。
- 双分号“;;“表示命令序列结束。
- 最后的”*)”表示默认模式。



#### for…in…do…done

```
for var in val1 val2 val3
do
    语句1
    语句2
    ...
done
```

e.g.

```
#! /bin/bash

for i in 1 2 3 4;
do
        echo $i
done
# input: 1\n2\n3\n4\n
```

#### for ((…;…;…)) do…done

```
for ((expression; condition; expression))
do
    语句1
    语句2
done
```

e.g.

```
#! /bin/bash

for((i=1; i < 10; ++i));do
        echo "$i"
done
```

#### while…do…done循环

```
while condition
do
    语句1
    语句2
    ...
done
```

e.g.

```
#! /bin/bash

while read i;
do
        if (( $i == 1));then
        break;
        else
                echo "no"
        fi
done  
```

#### until…do…done循环

```
until condition
do
    语句1
    语句2
    ...
done
```

e.g.

```
#! /bin/bash

i=0
until (( i == 1));
do
        read i
done
```

break命令

- 跳出当前一层循环，注意与C/C++不同的是：break不能跳出case语句。

continue命令

- 跳出当前循环。