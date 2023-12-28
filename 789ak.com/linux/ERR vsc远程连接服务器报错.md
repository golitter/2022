今天突发奇想想要登入一下阿里云服务器，发现在vscode上远程连接错误。

找了一下之前用hexo搭建的博客内容，仍然没有找到问题。在网上搜索后发现了解决方法。

服务器重置过，导致跟我本地的"known_hosts"文件内的ssh重复了，一直重复报错。当我把文件内关于服务器的ssh删除后，连接成功了。

<a href="https://blog.csdn.net/xiaoxiaosunzhao/article/details/105984177?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167542206016800192286854%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&amp;request_id=167542206016800192286854&amp;biz_id=0&amp;utm_medium=distribute.pc_search_result.none-task-blog-2~all~baidu_landing_v2~default-1-105984177-null-null.142^v73^control,201^v4^add_ask,239^v1^control&amp;utm_term=Got%20some%20output%2C%20clearing%20connection%20timeout&amp;spm=1018.2226.3001.4187">Virtual Studio Code Remote遇到的各种坑 </a>

<a href="https://golitter.github.io/">https://golitter.github.io/</a>

&nbsp;

2023年3月29日 10点30分 更新：

前几天把c盘清理了清理，结果发现vscode的remote ssh用不了了，捣鼓了好久都没有成功。

昨天把openssh卸载后重新安装后，发现有tunnel，但是没有terminal。

<img class="alignnone wp-image-750 size-full" src="https://789ak.com/wp-content/uploads/2023/02/Pasted-84.png" />

但是点击ssh tunnel后就显示了terminal。

<img class="alignnone wp-image-751 size-full" src="https://789ak.com/wp-content/uploads/2023/02/Pasted-85.png" />