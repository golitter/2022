OS开始讲多线程编程了，在WSL2上安装gcc发现报错。

![image-20230505212428536](http://cdn.789ak.com/img/image-20230505212428536.png)

WSL打不开了，最后没办法只好把wsl这个linux注销了。

```cmd
wslconfig /u wsl_linux_name
```

又从新开始。

先进行更新包管理。

```bash
sudo apt-get update
sudo apt-get upgrade
```

再进行gcc的安装。

```bash
sudo apt-get install build-essential
```

发现gcc就安装成功了。显示：![image-20230505212907515](http://cdn.789ak.com/img/image-20230505212907515.png)

总结一下：就是感觉不要乱换源。之前换了个阿里的源，结果安装时显示缺这缺那的，但是不换源就直接安装成功了。（可能是这个原因）