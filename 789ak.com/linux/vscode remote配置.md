使用vscode的插件remote-ssh进行linux的远程控制。

在vscode上安装完remote-ssh插件后，还需要安装openssh-client。

### openssh-client安装

先`win + R`打开cmd，输入`ssh`，查看是否已经安装了。

![image-20230715134811234](https://cdn.789ak.com/img/image-20230715134811234.png)

如果没有安装，用管理员权限打开powershell

运行以下代码，查看信息

```cmd
Get-WindowsCapability -Online | Where-Object Name -like 'OpenSSH*'
```

如果client和server都没有安装，会显示如下内容：

```cmd
Name  : OpenSSH.Client~~~~0.0.1.0
State : NotPresent

Name  : OpenSSH.Server~~~~0.0.1.0
State : NotPresent
```

安装client组件：

```cmd
Add-WindowsCapability -Online -Name OpenSSH.Client~~~~0.0.1.0
```

安装成功后，`win + R`在cmd里输入`ssh`，查看是否出现上面第一图的相关内容，出现表明安装成功。

并且，openssh-client的ssh.exe默认在`C:\\Windows\\System32\\OpenSSH\\ssh.exe`。

### remote-ssh配置

打开remote-ssh插件，点击加号进行远程控制。

![image-20230715135547792](https://cdn.789ak.com/img/image-20230715135547792.png)

输入linux的用户名和ip。

![image-20230715135639608](https://cdn.789ak.com/img/image-20230715135639608.png)

之后继续，选择linux。

![image-20230715135724226](https://cdn.789ak.com/img/image-20230715135724226.png)

输入密码即可进入。

![image-20230715135801244](https://cdn.789ak.com/img/image-20230715135801244.png)



### 免密码进入

在windows上进行ssh-keygen配置。

将公钥输入到服务器的`.ssh/authorized_keys`中即可。





[(1条消息) windows 安装 OpenSSH_Fighting_1997的博客-CSDN博客](https://blog.csdn.net/frighting_ing/article/details/122705781?ops_request_misc=%7B%22request%5Fid%22%3A%22168939799616800215087719%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=168939799616800215087719&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-2-122705781-null-null.142^v88^insert_down28v1,239^v2^insert_chatgpt&utm_term=openssh&spm=1018.2226.3001.4187)

[(1条消息) vscode 插件 remote-ssh的安装及使用_vscode安装remote-ssh___pop_的博客-CSDN博客](https://blog.csdn.net/u011011827/article/details/130826996?ops_request_misc=&request_id=&biz_id=102&utm_term=vscode remote ssh.exe&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-1-130826996.142^v88^insert_down28v1,239^v2^insert_chatgpt&spm=1018.2226.3001.4187)