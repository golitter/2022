# 基于七牛云和PicGo的图床搭建

第一次搭建的博客因为误操作且没有备份导致无法访问和恢复。第二次搭建吸取了第一次的错误，并且准备用图床进行图片的访问。

需要用到的：

七牛云，

PicGo，

Typora，

已备案域名。

## 七牛云和域名

进入七牛云的页面，登录/注册、实名。

![image-20230409234053812](http://cdn.789ak.com/img/image-20230409234053812.png)

点击 ”新建空间”

![image-20230409234153564](http://cdn.789ak.com/img/image-20230409234153564.png)

注意选择 “公用”

![image-20230409234243713](http://cdn.789ak.com/img/image-20230409234243713.png)

之后在域名服务商处进行域名解析。

选择“CNAME”类型，主机记录就是要绑定七牛云的子域名（这里用cdn，也可以换其他名字），跳转域名任意一个域名都可以。

![image-20230409234611077](http://cdn.789ak.com/img/image-20230409234611077.png)

找到绑定域名。

![image-20230409234754766](http://cdn.789ak.com/img/image-20230409234754766.png)

加速域名，填写刚刚解析的。使用场景是“图片小文件”，其他不更改。

![image-20230409234925160](http://cdn.789ak.com/img/image-20230409234925160.png)

点击创建后，有一个域名管理验证。

在服务商处进行“TXT”类型的域名解析，将主机记录和记录值都进行填写。

![image-20230409235152196](http://cdn.789ak.com/img/image-20230409235152196.png)

成功后将CNAME的域名进行复制，来到域名服务商处，将之前随便填写的域名进行替换。

![image-20230410000051222](http://cdn.789ak.com/img/image-20230410000051222.png)

## PicGo

在[Releases · Molunerfinn/PicGo (github.com)](https://github.com/Molunerfinn/PicGo/releases)进行安装。

![image-20230409235441400](http://cdn.789ak.com/img/image-20230409235441400.png)

下载安装完成后，打开PicGo。

找到图床设置，找到七牛云。

![image-20230409235612335](http://cdn.789ak.com/img/image-20230409235612335.png)

AccessKey和SecretKey在密钥管理内。

![image-20230409235647555](http://cdn.789ak.com/img/image-20230409235647555.png)

![image-20230409235659644](http://cdn.789ak.com/img/image-20230409235659644.png)

Bucket是创建的存储空间名字。访问网址是刚刚解析的cdn.网址。

存储区域是：华东：z0；华北：z1；华南：z2：北美：na0：东南亚：as0

## Typora

打开Typora，点击 “文件” --> ”偏好设置“。

进行这样的选择。

![image-20230410000359399](http://cdn.789ak.com/img/image-20230410000359399.png)

选择好后，点击 ”验证图片上传选项“，查看是否成功。

![image-20230410000451522](http://cdn.789ak.com/img/image-20230410000451522.png)

这样就完成了！！！



网站markdown显示错误，而其他地方显示正常。

原因：再主域名内添加了cdn子域名，而在添加域名处又添加了域名，导致产生了 “Failed to load resource: the server responded with a status of 403 (Forbidden)”

处理：将跟主域名同一管理栏处的子域名cdn删除即可。

![image-20230410232156934](http://cdn.789ak.com/img/image-20230410232156934.png)

![image-20230410232211386](http://cdn.789ak.com/img/image-20230410232211386.png)

