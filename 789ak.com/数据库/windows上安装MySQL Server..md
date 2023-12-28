进入官网 [MySQL](https://www.mysql.com/)

找到 下载，并点进入。

![image-20230622162948906](http://cdn.789ak.com/img/image-20230622162948906.png)

往下翻，找到社区下载，进入页面

![image-20230622163059621](http://cdn.789ak.com/img/image-20230622163059621.png)

选择 Mysql community Server

![image-20230622163135399](http://cdn.789ak.com/img/image-20230622163135399.png)

选择系统，下载

![image-20230622170827619](http://cdn.789ak.com/img/image-20230622170827619.png)

之后解压。

![image-20230622170859266](http://cdn.789ak.com/img/image-20230622170859266.png)

将解压文件夹下的bin路径添加到变量值中

![image-20230622171036335](http://cdn.789ak.com/img/image-20230622171036335.png)

配置初始化的my.ini文件

```
[mysqld]
# 设置3306端口
port=3306
# 设置mysql的安装目录
basedir=E:\\software\\mysql\\mysql-8.0.11-winx64   # 切记此处一定要用双斜杠\\，单斜杠我这里会出错，不过看别人的教程，有的是单斜杠。自己尝试吧
# 设置mysql数据库的数据的存放目录
datadir=E:\\software\\mysql\\mysql-8.0.11-winx64\\Data   # 此处同上
# 允许最大连接数
max_connections=200
# 允许连接失败的次数。这是为了防止有人从该主机试图攻击数据库系统
max_connect_errors=10
# 服务端使用的字符集默认为UTF8
character-set-server=utf8
# 创建新表时将使用的默认存储引擎
default-storage-engine=INNODB
# 默认使用“mysql_native_password”插件认证
default_authentication_plugin=mysql_native_password
[mysql]
# 设置mysql客户端默认字符集
default-character-set=utf8
[client]
# 设置mysql客户端连接服务端时默认使用的端口
port=3306
default-character-set=utf8
```

![image-20230622171418783](http://cdn.789ak.com/img/image-20230622171418783.png)

以管理员身份运行cmd

![image-20230622171501121](http://cdn.789ak.com/img/image-20230622171501121.png)

在MySQL安装目录的 bin 目录下执行命令

```
mysqld --initialize --console
```

执行完成后，会打印 root 用户的初始默认密码

![image-20230622171602297](http://cdn.789ak.com/img/image-20230622171602297.png)

安装服务

```
mysqld --install
```

卸载

```
sc delete MySQL/mysqld -remove卸载 MySQL 服务
```

进入mysql

```
mysql -u root -p
```

输入初始得密码

更改密码

```sql
ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'newpassword';  
```







[MySQL-mysql 8.0.11安装教程 - Laumians - 博客园 (cnblogs.com)](https://www.cnblogs.com/laumians-notes/p/9069498.html)

[超详细MySQL安装及基本使用教程_mysql安装教程_一切还不都是因为菜的博客-CSDN博客](https://blog.csdn.net/theLostLamb/article/details/78797643)