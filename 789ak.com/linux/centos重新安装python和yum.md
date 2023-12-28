本来想把python2.7更改为python3.8的，但是一顿操作，导致yum用不了了。在网上搜索资料，终于将yum又给安装回来了。
<h3>yum</h3>
安装yum需要安装python和yum。

首先将python卸载完全。
<pre class="EnlighterJSRAW" data-enlighter-language="generic" data-enlighter-theme="atomic">## 强制删除已安装python程序及其关联程序
rpm -qa|grep python|xargs rpm -ev --allmatches --nodeps 

## 删除所有残余文件 xargs:允许你对输出执行其他某些命令
whereis python |xargs rm -frv 

## 验证删除，返回无结果
whereis python</pre>
&nbsp;

卸载yum
<pre class="EnlighterJSRAW" data-enlighter-language="generic" data-enlighter-theme="atomic">## 强制删除已安装的yum程序及其他关联
rpm -qa|grep yum|xargs rpm -ev --allmatches --nodeps

## 验证删除
whereis yum |xargs rm -frv</pre>
&nbsp;

创建python和yum目录
<pre class="EnlighterJSRAW" data-enlighter-language="generic" data-enlighter-theme="atomic">## 创建python.rpm存放文件夹
mkdir /usr/local/src/python

## 创建yum.rpm存放文件夹
mkdir /usr/local/src/yum</pre>
&nbsp;

查看centos的版本号
<pre class="EnlighterJSRAW" data-enlighter-language="generic" data-enlighter-theme="atomic">## 查看本机的系统版本
cat /etc/redhat-release</pre>
&nbsp;

下载python的rpm包
<pre class="EnlighterJSRAW" data-enlighter-language="generic" data-enlighter-theme="atomic">wget http://mirrors.ustc.edu.cn/centos/7.9.2009/os/x86_64/Packages/rpm-python-4.11.3-45.el7.x86_64.rpm

wget http://mirrors.ustc.edu.cn/centos/7.9.2009/os/x86_64/Packages/python-urlgrabber-3.10-10.el7.noarch.rpm

wget http://mirrors.ustc.edu.cn/centos/7.9.2009/os/x86_64/Packages/python-setuptools-0.9.8-7.el7.noarch.rpm

wget http://mirrors.ustc.edu.cn/centos/7.9.2009/os/x86_64/Packages/python-pycurl-7.19.0-19.el7.x86_64.rpm

wget http://mirrors.ustc.edu.cn/centos/7.9.2009/os/x86_64/Packages/python-libs-2.7.5-89.el7.x86_64.rpm

wget http://mirrors.ustc.edu.cn/centos/7.9.2009/os/x86_64/Packages/python-iniparse-0.4-9.el7.noarch.rpm

wget http://mirrors.ustc.edu.cn/centos/7.9.2009/os/x86_64/Packages/python-devel-2.7.5-89.el7.x86_64.rpm

wget http://mirrors.ustc.edu.cn/centos/7.9.2009/os/x86_64/Packages/python-2.7.5-89.el7.x86_64.rpm

## centos7 版本 安装yum时需要该依赖
wget http://mirrors.ustc.edu.cn/centos/7.9.2009/os/x86_64/Packages/python-kitchen-1.1.1-5.el7.noarch.rpm

## centos7 版本 安装yum时需要该依赖
wget http://mirrors.ustc.edu.cn/centos/7.9.2009/os/x86_64/Packages/libxml2-python-2.9.1-6.el7.5.x86_64.rpm</pre>
&nbsp;

下载yum的rpm包
<pre class="EnlighterJSRAW" data-enlighter-language="generic" data-enlighter-theme="atomic">wget http://mirrors.ustc.edu.cn/centos/7.9.2009/os/x86_64/Packages/yum-3.4.3-168.el7.centos.noarch.rpm

wget http://mirrors.ustc.edu.cn/centos/7.9.2009/os/x86_64/Packages/yum-metadata-parser-1.1.4-10.el7.x86_64.rpm

wget http://mirrors.ustc.edu.cn/centos/7.9.2009/os/x86_64/Packages/yum-plugin-aliases-1.1.31-54.el7_8.noarch.rpm

wget http://mirrors.ustc.edu.cn/centos/7.9.2009/os/x86_64/Packages/yum-plugin-fastestmirror-1.1.31-54.el7_8.noarch.rpm

wget http://mirrors.ustc.edu.cn/centos/7.9.2009/os/x86_64/Packages/yum-plugin-protectbase-1.1.31-54.el7_8.noarch.rpm

wget http://mirrors.ustc.edu.cn/centos/7.9.2009/os/x86_64/Packages/yum-utils-1.1.31-54.el7_8.noarch.rpm</pre>
&nbsp;

安装python的rpm包
<pre class="EnlighterJSRAW" data-enlighter-language="generic" data-enlighter-theme="atomic">## 进入下载的文件夹
cd /usr/local/src/python 

## 执行安装
rpm -ivh python-* *-python-*

# 出现安装包的依赖问题，可以使用强制安装，--nodeps --force为不考虑依赖包，强制安装，如下解决即可：
# 我弄了半天，发现需要这个命令
#rpm -ivh python-* *-python-* --nodeps --force
</pre>
&nbsp;

安装yum的rpm包
<pre class="EnlighterJSRAW" data-enlighter-language="generic" data-enlighter-theme="atomic">## 进入下载的文件夹
cd /usr/local/src/yum

## 安装
rpm -ivh yum-*

## 如果遇到有些依赖没有，需要自行去http://mirrors.ustc.edu.cn/centos/7.9.2009/os/x86_64/Packages/ 下载
例如：我的就需要下面的依赖</pre>
&nbsp;
<h3>python3.8</h3>
复现一个深度学习代码，要求python3.8才能安装某些库。

安装编译需要工具：
<pre class="EnlighterJSRAW" data-enlighter-language="generic" data-enlighter-theme="atomic">yum -y groupinstall "Development tools"
yum -y install zlib-devel bzip2-devel openssl-devel ncurses-devel sqlite-devel readline-devel tk-devel gdbm-devel db4-devel libpcap-devel xz-devel
yum install libffi-devel -y
</pre>
&nbsp;

下载python包：
<pre class="EnlighterJSRAW" data-enlighter-language="generic" data-enlighter-theme="atomic">wget https://www.python.org/ftp/python/3.8.3/Python-3.8.3.tgz
# 建议用下面的网址来安装，因为python官网下载速度很慢！！！
# wget https://repo.huaweicloud.com/python/3.8.5/Python-3.8.5.tgz
tar -zxvf  Python-3.8.3.tgz
</pre>
&nbsp;

编译：
<pre class="EnlighterJSRAW" data-enlighter-language="generic" data-enlighter-theme="atomic">mkdir /usr/local/python3 #创建编译安装目录
cd Python-3.8.3
./configure --prefix=/usr/local/python3
make &amp;&amp; make install</pre>
创建软链接：
<pre class="EnlighterJSRAW" data-enlighter-language="generic" data-enlighter-theme="atomic"># 查看当前python软连接
ll /usr/bin/ |grep python</pre>
删除软链接：
<pre class="EnlighterJSRAW" data-enlighter-language="generic" data-enlighter-theme="atomic">rm -rf /usr/bin/python</pre>
删除默认软链接，为pip3添加新软链接：
<pre class="EnlighterJSRAW" data-enlighter-language="generic" data-enlighter-theme="atomic">rm -rf /usr/bin/pip
#添加 pip3 的软链接 
ln -s /usr/local/python3/bin/pip3 /usr/bin/pip</pre>
&nbsp;

更改yum配置，因为yum需要python2才可以执行：
<pre class="EnlighterJSRAW" data-enlighter-language="generic" data-enlighter-theme="atomic">vi /usr/bin/yum 
把 #! /usr/bin/python 修改为 #! /usr/bin/python2 
vi /usr/libexec/urlgrabber-ext-down 
把 #! /usr/bin/python 修改为 #! /usr/bin/python2
vi /usr/bin/yum-config-manager
#!/usr/bin/python 改为 #!/usr/bin/python2
</pre>
&nbsp;

&nbsp;

<a href="https://blog.csdn.net/WLPJLP/article/details/116590879">Centos7的python2.7和yum完全卸载及重装</a>

<a href="https://blog.csdn.net/fanxl10/article/details/106854062?spm=1001.2014.3001.8078#comments_25841265">Centos7安装Python3.8详细教程</a>

