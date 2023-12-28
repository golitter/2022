在WSL中默认是没有安装OpenSSH，需要自己安装。

安装

```shell
sudo apt update
sudo apt install openssh-server
```

检查是否安装成功

```shell
ssh -V
```

配置ssh

```shell
sudo vim /etc/ssh/ssh_config
```

设置端口

```ssh
Port 22
```

启动ssh服务

```shell
sudo service ssh start
```

xftp连接

```shell
主机地址：127.0.0.1
用户：linux中的用户
密码：linux中的密码
```





[WSL 开启ssh_wsl 安装ssh_geniusNMRobot的博客-CSDN博客](https://blog.csdn.net/geniusChinaHN/article/details/131570648?ops_request_misc=%7B%22request%5Fid%22%3A%22169329306616800226519079%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=169329306616800226519079&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-131570648-null-null.142^v93^insert_down1&utm_term=wsl ssh&spm=1018.2226.3001.4187)