用apt-get安装docker会产生这个问题

```
E:Unable to lock the administration directory (/var/lib/dpkg/), is another process using it?
```

可以使用

```
sudo dpkg --clear-avail
```

使用后产生： “dpkg: error : dpkg status database is locked by another process"

这时再使用

```
suod rm /var/lib/dpkg/lock
sudo dpkg --clear-avail
```

再运行apt-get时会出现： ”E: dpkg was interrupted, you must manually run 'sudo dpkg --configure -a' to correct the problem"

使用以下命名

```
sudo dpkg --configure -a
```

到这里如果之前下载的安装包没有出错，会接着安装

如果报了这个错误：“E: Could not get lock /var/cache/apt/archives/lock - open (11: Resources temporarily unavailable)

​	E: Unable to lock directory /var/cache/apt/archives/"

处理办法为

```
sudo rm -rf /var/cache/apt/archives/lock
sudo apt-get update
```

如果报错：”dpkg: error: parsing file '/var/lib/dpkg/updates/0006' near line 0: newline in field name '#padding' "

仍然使用

```
sudo dpkg --clear avail
```





[ubuntu apt-get 安装错误总结-clark (lofter.com)](http://fengmm521.lofter.com/post/2a9e99_d61dc96)