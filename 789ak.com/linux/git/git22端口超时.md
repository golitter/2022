笔记本换了个主板后，将内容用git上传到GitHub时发现22端口超时。

![image-20240119152920539](git22%E7%AB%AF%E5%8F%A3%E8%B6%85%E6%97%B6.assets/image-20240119152920539.png)

以为是网络啥的原因，但是用`ssh -T git@github.com`进行多次测试，发现不是网络问题。按照网上操作，在`.ssh`文件夹内将`config`文件进行修改，改成：

```shell
Host github.com
User YourEmail（你的邮箱）
Hostname ssh.github.com
PreferredAuthentications publickey
IdentityFile ~/.ssh/id_rsa
Port 443
```

之后再次运行发现可以了。



[git------connect to host github.com port 22: Connection timed out解决办法-CSDN博客](https://blog.csdn.net/glenshappy/article/details/118296313?ops_request_misc=&request_id=&biz_id=102&utm_term=$ git push ssh: connect to hos&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-1-118296313.142^v99^pc_search_result_base3&spm=1018.2226.3001.4187)



