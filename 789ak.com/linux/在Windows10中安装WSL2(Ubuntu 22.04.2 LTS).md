# 在Windows10中安装WSL2(Ubuntu 22.04.2 LTS)

## WSL1 和 WSL2

WSL 1 于 2016 首次发布，在 windows 系统中可以使用linux系统。

但是WSL1的缺点有：

- 文件 I/O 慢，尤其是在大量IO操作时，例如使用 git 克隆仓库；
- 不支持内核程序；

WSL 2 针对以上两个缺点进行了修正：

- 相比较于 WSL 1 使用翻译层将 linux 系统调用转化成 windows 系统调用，WSL 2 使用了一个轻量级的、无需维护的虚拟机，并在这个虚拟机中运行了一个完整的 linux 内核。
- WSL 2 使用一个 VHD 虚拟磁盘文件作为 linux 发行版的根目录，其中使用 ext4文件系统格式，极大提升了IO性能。

两者的特性

![image-20230421214452778](http://cdn.789ak.com/img/image-20230421214452778.png)

## 安装WSL2，并下载linux系统

若要更新到 WSL 2，需要运行 Windows 10。

- 对于 x64 系统：版本 1903 或更高版本，内部版本为 18362 或更高版本。
- 对于 ARM64 系统：版本 2004 或更高版本，内部版本为 19041 或更高版本。

安装WSL2的详细步骤官网上都有：[旧版 WSL 的手动安装步骤 | Microsoft Learn](https://learn.microsoft.com/zh-cn/windows/wsl/install-manual#step-3—enable-virtual-machine-feature)



之后是安装linux系统，这里以Ubuntu 22.04 LTS为例。

打开微软商店，搜索linux，找到Ubuntu 22.04 LTS进行安装。地址：https://www.microsoft.com/store/apps/9PN20MSR04DW

下载好后，等几分钟进行初始化。

之后进行用户名和密码的配置。

![image-20230421214516663](http://cdn.789ak.com/img/image-20230421214516663.png)

安装好linux后，可以将包管理进行换源，让下载速度更快。

以管理员权限打开cmd终端。

![image-20230421203610902](http://cdn.789ak.com/img/image-20230421203610902.png)

输入以下命令，查看linux发行版列表。

```
wsl -l -v
```

可以看到VERSION为 2。

![image-20230421203659515](http://cdn.789ak.com/img/image-20230421203659515.png)

这就表明成功安装上了WSL2版本。

如果version为2，说明已经安装为wsl2版本，如果为1，输入以下代码：

```
wsl --set-version Ubuntu-22.04 2 #将Ubuntu-22.04替换为你所下载安装的Linux分发版名称
```



如果还不成功，再进行详细的搜索等来转换为wSL2版本。

## WSL2修改安装目录

WSL镜像文件默认安装的时候会安装在C盘，会占用C盘很大的空间。导致C盘吃紧，因此需要迁移到非系统盘。

```
# 查看WSL分发版本
wsl -l --all -v

# 停止WSL
wsl --shutdown

# 导出WSL镜像
wsl --export Ubuntu-22.04  "E:\Linux_store\Ubuntu.tar"

# 注销Ubuntu
wsl --unregister Ubuntu-22.04

# 导入WSL镜像
wsl --import Ubuntu-22.04 "E:\Linux_store" "E:\Linux_store\Ubuntu.tar"  --version 2

# 设置默认登录用户(可以通过 /etc/passwd 文件查看)
Ubuntu2204 config --default-user golitter
```

cmd终端命令行运行

```
Ubuntu2204.exe
```

## 使用vscode配置sl2

在vscode上安装插件“WSL"(以前叫”Remote WSL“吧 ( )。

![image-20230421213730877](http://cdn.789ak.com/img/image-20230421213730877.png)

点击左下角角标

![image-20230421213759597](http://cdn.789ak.com/img/image-20230421213759597.png)

选择”connect WSL“ ，连接到WSL。

![image-20230421213833548](http://cdn.789ak.com/img/image-20230421213833548.png)

Ctrl + · 就可以使用了。

![image-20230421213921281](http://cdn.789ak.com/img/image-20230421213921281.png)



可能常用到的命令：

```bash
wsl -l -v # 查看linux
wslconfig /u wsl_linux_name # 注销linux，重新开始。
```



## 遇到的问题

访问不了wsl2的linux目录，但是重启后又可以访问。



[WSL2 修改安装目录 - 哔哩哔哩 (bilibili.com)](https://www.bilibili.com/read/cv17865605)

[(5条消息) Windows将WSL 1升级为WSL2_wsl1升级到wsl2_Xeon-Shao的博客-CSDN博客](https://blog.csdn.net/sdujava2011/article/details/123813570)

[在Windows11中安装WSL2(Ubuntu20.04)并配置数据分析环境(anaconda、pyspark) - 哔哩哔哩 (bilibili.com)](https://www.bilibili.com/read/cv16825907/)