突发奇想，想要将自己的c++压行之后交上去。但是苦于手动压行效率太低，在网上搜索压行网站没有找到，突然发现压行不就是检查检查去个换行符吗。于是心血来潮，用python实现了一个简易压行程序。

首先，宏定义等带`#`的文件不能跟压行，会报错。其次是行注释要删除，不能这一行后面都被注释掉了。

因此，我用一个变量`txt`表示压行之后的内容，每次用`line`读取行字符串内容。将`line`字符串中`//`后面的内容舍去。

用`strip`函数得到`line`剔除空格和换行符等。如果`line`里有`#`字符，就不进行换行。由于不换行需要考虑压行后的`txt`字符串中是否有换行符`\n`，如果已经有了，则不用再`txt`后面再加入`\n`，否则需要在`txt`字符串后添加换行符。由于后面的行也不能在该行后面，所以在`line`字符串后添加换行符。将`line`拼接到`txt`后面即可。

```python
with open(file=r"lab.cpp", mode="r", encoding="utf-8") as fb:
    # 考虑第一行就是#等，txt初始化为 `\n`
    txt = "\n"
    while True:
        # 循环读入行
        line = fb.readline()
        # 如果是空，则结束
        if not line:
            break

        # 有 "//" ，舍去 "//" 后面的内容
        if line.find("//") != -1:
            line = line[: line.find("//")]

        # 将line剔除前后的空格和换行
        line = line.strip()

        # 如果该行有'#'，该行需要单独一行
        if line.find("#") != -1:
            # 如果txt已经有换行，则不需要再添，否则需要添加换行
            if txt[-1] != '\n': txt += "\n"
            line += "\n"
        txt += line
    
    # 输出到 压行.cpp 文件内
    with open(file = r"压行.cpp", mode="w", encoding="utf-8") as f:
        print(txt, file=f)
    print("ok")

```

效果：

![image-20231129021717548](https://cdn.789ak.com/img/image-20231129021717548.png)