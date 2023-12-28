在frp目录中新建start.txt。

向其中写入：

```text
@echo off
:home
frpc -c frpc.ini
goto home
```

找到“任务计划程序”打开。

![image-20230830141256528](https://cdn.789ak.com/img/image-20230830141256528.png)

点击右侧“创建任务”。

![image-20230830141409946](C:\Users\19819\AppData\Roaming\Typora\typora-user-images\image-20230830141409946.png)

![image-20230830141525411](https://cdn.789ak.com/img/image-20230830141525411.png)

之后点击“触发器”。

![image-20230830141612426](https://cdn.789ak.com/img/image-20230830141612426.png)

![image-20230830141700245](https://cdn.789ak.com/img/image-20230830141700245.png)

之后是“操作”。

![image-20230830141728631](https://cdn.789ak.com/img/image-20230830141728631.png)

点击“新建”。添加脚本路径。



![image-20230830141827902](https://cdn.789ak.com/img/image-20230830141827902.png)

![image-20230830141847209](https://cdn.789ak.com/img/image-20230830141847209.png)

![image-20230830141905554](https://cdn.789ak.com/img/image-20230830141905554.png)

点击“条件”。

![image-20230830141949448](https://cdn.789ak.com/img/image-20230830141949448.png)

![image-20230830142024224](https://cdn.789ak.com/img/image-20230830142024224.png)