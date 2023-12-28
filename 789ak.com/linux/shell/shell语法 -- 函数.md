> bash中的函数类似于C/C++中的函数，但return的返回值与C/C++不同，返回的是exit code，取值为0-255，0表示正常结束。
>
> 如果想获取函数的输出结果，可以通过echo输出到stdout中，然后通过$(function_name)来获取stdout中的结果。
>
> 函数的return值可以通过$?来获取。

### 系统函数

##### basename

基本语法：`basename [string  pathname] [suffix] `

功能描述：basename命令会删除掉所有的前缀包括最后一个（'/'）字符，然后将字符串显示出来。

basename可以理解为取路径里的文件名称。

- 如果指明了后缀，basename会将pathname或string中的suffix去掉。

##### dirname

dirname文件绝对路径

功能描述：从给定的包含绝对路径的文件名中去除文件名（非目录部分），然后返回剩下的路径（目录的部分）。

dirname可以理解为取文件路径的绝对路径名称。

## 函数

1. 必须在调用函数之前，先声明函数，shell脚本是逐行运行的。不会像其他语言一样先编译。
2. 函数返回值，只能通过`$?`系统变量获得，可以显示加：return返回，如果不加，将以最后一条命令运行结束，作为返回值。return后跟数值n(0-255)。

格式：

```
[function] func_name() {  # function关键字可以省略
    语句1
    语句2
    ...
}
```

```
#! /bin/bash

func() {
        name="golitter"
        echo "Hello, ${name}"
}

func
```

获取 return值 $?

stdout值 $(func)
不写return时，默认return 0。

e.g.

```
#! /bin/bash

func() {
        name="golitter"
        echo "Hello, ${name}"
}

oup=$(func)
ret=$?

echo "the stdout : ${oup}"
echo "return : ${ret}"
```

函数的输入参数
在函数内，$1表示第一个输入参数，$2表示第二个输入参数，依此类推。

注意：函数内的$0仍然是文件名，而不是函数名。

函数内的局部变量
可以在函数内定义局部变量，作用范围仅在当前函数内。

可以在递归函数中定义局部变量。