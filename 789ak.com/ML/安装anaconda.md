进入官网[Anaconda | The World’s Most Popular Data Science Platform](https://www.anaconda.com/)

点击下载对应的版本

![image-20230705111805797](https://cdn.789ak.com/img/image-20230705111805797.png)

点击Next，到用户设置时，建议All。

![image-20230705112016231](https://cdn.789ak.com/img/image-20230705112016231.png)

设置好存储文件位置。

![image-20230705112309416](https://cdn.789ak.com/img/image-20230705112309416.png)

![image-20230705112317296](https://cdn.789ak.com/img/image-20230705112317296.png)

安装好后进行环境配置。

打开“系统属性-高级-环境变量-user的用户变量-选择Path-编辑”
即编辑Path的环境变量。
在变量值后面依次添加之前要求记住的自己的安装路径（例如我的）

```
E:\Anacoda_store
E:\Anacoda_store\Scripts
E:\Anacoda_store\Library\bin
E:\Anacoda_store\Library\mingw-w64\bin
```

![image-20230705113816823](https://cdn.789ak.com/img/image-20230705113816823.png)

之后可以简单通过cmd输入conda 命令检查下安装配置是否成功：

![image-20230705113846357](https://cdn.789ak.com/img/image-20230705113846357.png)

![image-20230705113920646](https://cdn.789ak.com/img/image-20230705113920646.png)

以上就将anaconda配置好了。

配置国内镜像源，继续在cmd里，通过输入下面命令配置为清华源：

```

conda config --add channels    https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
conda config --add channels    https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/
conda config --add channels    https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/conda-forge/


```







[(7条消息) 最新Anaconda3的安装配置及使用教程（详细过程）_HowieXue的博客-CSDN博客](https://blog.csdn.net/HowieXue/article/details/118442904?ops_request_misc=%7B%22request%5Fid%22%3A%22168852785516800222815553%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=168852785516800222815553&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-2-118442904-null-null.142^v88^insert_down28v1,239^v2^insert_chatgpt&utm_term=anaconda安装教程&spm=1018.2226.3001.4187)

[(7条消息) 史上最全最详细的Anaconda安装教程_OSurer的博客-CSDN博客](https://blog.csdn.net/wq_ocean_/article/details/103889237?ops_request_misc=%7B%22request%5Fid%22%3A%22168852785516800222815553%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=168852785516800222815553&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-103889237-null-null.142^v88^insert_down28v1,239^v2^insert_chatgpt&utm_term=anaconda安装教程&spm=1018.2226.3001.4187)