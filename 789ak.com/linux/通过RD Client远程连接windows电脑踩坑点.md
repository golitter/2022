通过RD Client远程连接windows电脑操作的个人踩坑点，记录下来，防止下一次还犯。

配置：

- win10专业版
- 腾讯云服务器
- Ubuntu22.04
- 小米平板
- RD client



### 首先是安装frp

这一部分参考的是：[通过RD Client远程连接windows电脑（平板，手机等设备远程连接电脑）_muci_的博客-CSDN博客](https://blog.csdn.net/xiaofuchen_muci/article/details/128156293)这一篇博文。

遇到的问题有：

#### linux防火墙和端口的开放

- 腾讯云云服务器的防火墙设置：

![image-20230831022523800](https://cdn.789ak.com/img/image-20230831022523800.png)

在这里进行设置即可。

- 端口的开放

用的`ufw`，参考博文：[ufw的基本使用_LimeSea的博客-CSDN博客](https://blog.csdn.net/qq_45928255/article/details/122644336?ops_request_misc=%7B%22request%5Fid%22%3A%22169341995916800182134084%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=169341995916800182134084&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-122644336-null-null.142^v93^insert_down1&utm_term=ufw&spm=1018.2226.3001.4187)。

### 访问服务端的Dashbord

- 用户名和密码

![image-20230831022726895](https://cdn.789ak.com/img/image-20230831022726895.png)

### 客户端配置

- frpc版本问题

我的电脑是windows，所以要选windows版本的。我参考的博文是mac的，我无脑照抄导致浪费了好久。

![image-20230831022852309](https://cdn.789ak.com/img/image-20230831022852309.png)

### 开机自启动frpc

参考博文[Windows设置开机启动frpc（超详细图文教程）_彬彬笔记 (binbinbiji.com)](https://www.binbinbiji.com/windows/2811.html)

- 输入密码无效

选上”不存储密码“，就不用输入密码了。

![image-20230831023143602](https://cdn.789ak.com/img/image-20230831023143602.png)

### RD client连接电脑

- 用用户账户或者微软账户不行

对于win10，只需注销，然后用微软账号密码解锁一遍系统即可。而win11无法通过微软账户密码登陆，在系统登录微软账号的情况下，只能通过windows hello（面部、指纹和pin）登陆。

参考[(22 封私信 / 83 条消息) 微软账号用户如何设置远程桌面？ - 知乎 (zhihu.com)](https://www.zhihu.com/question/34011808/answer/2958175085?utm_id=0)里面用户名为`dtcyh1017`的win11教程成功连上（虽然电脑是win10的）。

