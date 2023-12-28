之前在centos7上下的postgresql，它的数据库实例在 "var/lib/pgsql/" 下。这就导致了系统用户的"postgres"的家目录跟postgresql数据库目录不在同一目录下。因此，今天趁着有闲暇时间把数据库装到"postgres"目录下，顺便把版本从11升到12。

首先是下载postgresql。根据官网提示可以一键完成。<a href="https://www.postgresql.org/download/linux/redhat/">PostgreSQL: Linux downloads (Red Hat family)</a>

<img class="alignnone wp-image-347 size-full" src="https://789ak.com/wp-content/uploads/2023/02/Pasted-4.png" />

选择好版本后，点击 "Copy Script" 复制安装命令，即可一键安装。

安装完后，就有了一个用户 -- postgres。把这个用户删除。
<pre class="code"> userdel -g 701 postgres
 # 如果之前安装过或什么的导致有进程还在，删除不了的，用 "kill id" 删除进程，再用上面命令。</pre>
随后再添加"postgres"用户，将"postgres"的HOME目录建在 "/home"下：

&nbsp;
<pre class="code"> groupadd -g 701 postgres
 useradd -g 701 -u 701 -s /bin/bash -m postgres</pre>
接着配置postgres用户的".bashrc"内容。

&nbsp;

切换为postgres，"cd ~" 进入postgres的家目录下。打开".bashrc"文件, " vim .bashrc" 。

将下面内容放在文件最后。
<pre class="code"> export PATH=/usr/pgsql-12/bin:$PATH
 export LD_LIBRARY_PATH=/usr/pgsql-12/lib:$LD_LIBRARY_PATH
 export PGDATA=/home/postgres/pgdata 
 # $PGDATA环境变量制定的数据库是 "/home/postgres/pgdata"
 export PGHOST=/tmp</pre>
之后打开"/home/postgres/pgdata/postgresql.conf" , " vim /home/postgres/pgdata/postgresql.conf "。

&nbsp;

在文件末尾添加以下内容：
<pre class="code"> unix_socket_directories = '/tmp' # 注意：前面没有 '#'，可能新的一行首位有'#'，去掉\
 # 添加这个</pre>
之后就完成了。

&nbsp;
<pre class="code"> 每次都要启动postgresql服务：
 # 我的centos7的是 
systemctl start postgresql-12 # -&lt;版本号&gt;
也可以用pg_ctl，pgctl是管理postgresql数据库的服务工具
pg_ctl start</pre>
&nbsp;

&nbsp;

<a href="https://blog.csdn.net/u012190388/article/details/128025382">Centos下安装postgreSQL </a>

<a href="https://blog.csdn.net/qq_44653106/article/details/126442493">解决：“userdel: user xxxx is currently used by process xxx” 的问题</a>

PostgreSQL修炼之道：从小工到专家 [第二版] P10, P27