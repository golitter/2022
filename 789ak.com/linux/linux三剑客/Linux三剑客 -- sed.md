sed 是 Stream Editor（字符编辑器）的缩写。sed 是操作、过滤和转换文本内容的强大工具。

命令格式：

```bash
sed  [options] [swd内置字符] [file]
```

### 参数

| 参数 | 解释                                                   |
| :--- | :----------------------------------------------------- |
| -n   | 取消 sed 的输出，常常与 sed 内置命令 -p 一起使用       |
| -i   | **直接将修改结果写入文件，如果不用，则是在内存中显示** |
| -e   | 多次编辑，不需要管道符                                 |
| -r   | 支持正则扩展                                           |

### 内置命令字符

| 内置命令          | 解释                                                  |
| :---------------- | :---------------------------------------------------- |
| a                 | apeend，对文本进行最佳，再指定行后面添加一行/多行文本 |
| d                 | 删除匹配行                                            |
| i                 | insert 表示插入文本                                   |
| p                 | print 打印                                            |
| s/正则/替换内容/g | 正则匹配，然后替换文件，结尾 g 表示全局匹配           |

### 匹配范围

| 范围      | 解释                                     |
| :-------- | :--------------------------------------- |
| 空地址    | 全文处理                                 |
| 单地址    | 指定某一行                               |
| /pattern/ | 被匹配的每一行                           |
| 范围区间  | 10,20 十到二十行，10,+5 第十行向下五行， |
| 步长      | 1~2 表示 1,3,4,5 行，2~2 表示 2,4,6,8 行 |

**注意 '.' 转义**

e.g.

```bash
# 将[2,3]行打印到屏幕上
sed -n "2, 3p" test.txt
# 不带p就不打印，不带"-n"就全局输出

# 将匹配到的"golitter"所在行打印到屏幕
sed -n "/golitter/p" test.txt

# 将匹配到的"golitter"所在行不打印，其他显示到屏幕上
sed -n "/golitter/d" test.txt
# 但是原内容不删除

# 持久化删除"golitter"字符串
sed -i "/golitter/d" test.txt

# 将文件中的"golitter"替换为"golemon"
sed -i "s/golitter/golemon/g" test.txt

# 多次修改
sed -i -e "s/golemon/golitter" -e "s/I/He/g" -e "s/am/is/g" test.txt

#在第二行追加内容
sed -i "2a I am golemon\." test.txt

# 追加多行
sed -i "2a I am golemon\. \n She is Amy\." test.txt

# 在第一行进行插入内容
sed -i "1i bcd" test.txt
```

