### 2

[(3条消息) ubuntu安装mysql8.0_破 风的博客-CSDN博客](https://blog.csdn.net/qq_38935605/article/details/127509902?ops_request_misc=%7B%22request%5Fid%22%3A%22168982868416800215016834%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=168982868416800215016834&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-2-127509902-null-null.142^v90^insert_down1,239^v2^insert_chatgpt&utm_term=ubuntu安装mysql8.0&spm=1018.2226.3001.4187)

[(3条消息) Ubuntu 安装指定版本 Mysql，并设置远程连接（以安装mysql 5.5 为例）_ubuntu安装指定版本mysql_仲夏夜之梦~的博客-CSDN博客](https://blog.csdn.net/challenglistic/article/details/129247697)







### 1



[(3条消息) ubuntu篇---ubuntu安装mysql教程_心惠天意的博客-CSDN博客](https://blog.csdn.net/m0_46825740/article/details/128145298?ops_request_misc=&request_id=&biz_id=102&utm_term=ubuntu安装mysql&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-128145298.nonecase&spm=1018.2226.3001.4187)

[(3条消息) 允许任意IP访问mysql数据库_mysql允许其他ip访问数据库_hello world227的博客-CSDN博客](https://blog.csdn.net/mengniu666/article/details/129680530?ops_request_misc=%7B%22request%5Fid%22%3A%22168982548216782427489209%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=168982548216782427489209&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~baidu_landing_v2~default-4-129680530-null-null.142^v90^insert_down1,239^v2^insert_chatgpt&utm_term=mysql允许其他主机连接&spm=1018.2226.3001.4187)

```shell
-- 方便复制粘贴

mysql -uroot -p

use mysql;

select host,user from user;

update user set host ='%' where user ='root';

flush privileges;


```

![image-20230720121656253](https://cdn.789ak.com/img/image-20230720121656253.png)



# ERROR 1045 (28000): Access denied for user 'root'@'localhost' (using password: YES)`

没有启动 `sudo service mysql restart`



![image-20230720122458556](https://cdn.789ak.com/img/image-20230720122458556.png)

```shell
sudo systemctl start firewalld.service
sudo firewall-cmd --zone=public --add-port=3306/tcp --permanent
sudo firewall-cmd --reload

```

