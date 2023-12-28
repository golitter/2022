系统配置：

Linux：阿里云 centos

Windows10（有远程控制）

平板（安装RD Client）
<blockquote>RD Client配置起来较为繁琐，因为它默认只支持局域网下进行使用，所以当我们不能保证在同一网络下使用的话就一定需要内网穿透来解决这个问题。</blockquote>
<a href="https://baike.baidu.com/item/%E5%86%85%E7%BD%91%E7%A9%BF%E9%80%8F/8597835?fr=aladdin"><strong>内网穿透</strong></a>，也即 NAT 穿透，由于大部分的私人设备都不具备公网IP，所以需要通过一台带有公网IP的NAT设备对内网设备形成一对多的映射，在这种情形下，我们的服务器就需要成为一台具有公网IP的NAT设备，对我们的电脑进行映射，使得在其他设备访问服务器时能将收到的数据转发至我们的电脑。

<a href="https://baike.baidu.com/item/%E5%8F%8D%E5%90%91%E4%BB%A3%E7%90%86/7793488?fr=aladdin"><strong>反向代理</strong></a>是指客户端向代理服务器发送请求，代理服务器转发给内网中的真实处理服务器，获取到内容后返回给客户端。这样我们只需要让两台设备都访问NAT服务器，就能实现内网穿透。

以下链接是我在做这个的时候参考的，有不同但是又是同源的，因此就不再重复写了。
<h2>反向代理frp</h2>
<a href="https://blog.csdn.net/xiaofuchen_muci/article/details/128156293">linux安装frp</a>



powershell

安装的客户端是windows的，这个教程的是mac滴。

[frp配置内网穿透教程（超详细）-腾讯云开发者社区-腾讯云 (tencent.com)](https://cloud.tencent.com/developer/article/1837482)

端口开放：在阿里云的安全组内开放端口，还要将linux的这些端口开放。

<a href="https://blog.csdn.net/weixin_45517017/article/details/123618933#:~:text=%E6%B7%BB%E5%8A%A0%E6%8C%87%E5%AE%9A%E9%9C%80%E8%A6%81%E5%BC%80%E6%94%BE%E7%9A%84%E7%AB%AF%E5%8F%A3%EF%BC%9A%20firewall-cmd%20--add-port%3D123%2Ftcp%20--permanent%20%E9%87%8D%E8%BD%BD%E5%85%A5%E6%B7%BB%E5%8A%A0%E7%9A%84%E7%AB%AF%E5%8F%A3%EF%BC%9A%20firewall-cmd,--reload%20%E6%9F%A5%E8%AF%A2%E6%8C%87%E5%AE%9A%E7%AB%AF%E5%8F%A3%E6%98%AF%E5%90%A6%E5%BC%80%E5%90%AF%E6%88%90%E5%8A%9F%EF%BC%9A%20firewall-cmd%20--query-port%3D123%2Ftcp%201%202">linux开放端口</a>

<h2>win开机自动启动frp</h2>
<a href="https://www.binbinbiji.com/windows/2811.html">Windows设置开机启动frpc（超详细图文教程）</a>

<a href="https://blog.csdn.net/qq1170993239/article/details/124421103">frp内网穿透windows配置开机启动</a>

&nbsp;

补充一个win11下的情形。对于win10，只需注销，然后用微软账号密码解锁一遍系统即可。而win11无法通过微软账户密码登陆，在系统登录微软账号的情况下，只能通过windows hello（面部、指纹和pin）登陆。

[(22 封私信 / 82 条消息) 微软账号用户如何设置远程桌面？ - 知乎 (zhihu.com)](https://www.zhihu.com/question/34011808/answer/2958175085?utm_id=0)