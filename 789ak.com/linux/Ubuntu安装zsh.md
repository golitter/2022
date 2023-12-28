安装zsh

```bash
sudo apt install zsh
```

安装git（如果有跳过）

```shell
sudo apt install git
```

[(1条消息) 关于Git这一篇就够了_17岁boy想当攻城狮的博客-CSDN博客](https://blog.csdn.net/bjbz_cxy/article/details/116703787?ops_request_misc=%7B%22request%5Fid%22%3A%22168931395316800225528792%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=168931395316800225528792&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-116703787-null-null.142^v88^insert_down28v1,239^v2^insert_chatgpt&utm_term=git&spm=1018.2226.3001.4187)

安装oh my zsh

```bash
git clone https://github.com/robbyrussell/oh-my-zsh
```

 切换目录到oh-my-zsh文件夹下的tools文件夹

```shell
cd ~/oh-my-zsh/tools
```

用`ls`可以看到一个install.sh文件

运行该文件

```shell
bash install.sh
```

出现彩色的 oh my zsh 表示安装成功



### 配置插件

zsh-autosuggestions，历史命令智能提示插件。能帮助我们快速执行历史命令。

```shell
git clone https://github.com/zsh-users/zsh-autosuggestions.git 
# https://github.com/zsh-users/zsh-autosuggestions
```

```shell
vim ~/.zshrc # 添加插件
source /home/golitter/oh-my-zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh
```

![image-20230714135722300](https://cdn.789ak.com/img/image-20230714135722300.png)

![image-20230714131610823](https://cdn.789ak.com/img/image-20230714131610823.png)

zsh-syntax-highlighting，语法高亮插件。当你输入时，这个插件将帮助你纠错。

```shell
git clone git@github.com:zsh-users/zsh-syntax-highlighting.git
# https://github.com/zsh-users/zsh-syntax-highlighting
```

```shell
vim ~/.zshrc # 添加插件
source /home/golitter/oh-my-zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
```

![image-20230714135736276](https://cdn.789ak.com/img/image-20230714135736276.png)

![image-20230714135747195](https://cdn.789ak.com/img/image-20230714135747195.png)

### 配置主题

查看主题

```shell
cd ~/.oh-my-zsh/themes
```

![image-20230714135911107](https://cdn.789ak.com/img/image-20230714135911107.png)

可以在官网[Oh My Zsh - a delightful & open source framework for Zsh](https://ohmyz.sh/)上查看合适的主题。

配置.zshrc文件，将ZSH_THEME进行修改即可。

我用的主题是 agnoster

![image-20230714140104866](https://cdn.789ak.com/img/image-20230714140104866.png)



### 后续

#### 报错

```shell
[oh-my-zsh] plugin 'zsh-autosuggestions' not found [oh-my-zsh] plugin 'zsh-syntax-highlighting' not found
```

解决方案 ： 将zsh-au zsh-syn 目录从`~/on.../plugins/`复制到`~/.on.../plugins`即可（注意**`.`**）

[(1条消息) Ubuntu版本安装zsh、配置ohmyzsh及插件、主题更换_ubuntu ohmyzsh_浩崽的笔记的博客-CSDN博客](https://blog.csdn.net/qq_51692609/article/details/121228694?ops_request_misc=%7B%22request%5Fid%22%3A%22168930820616800180667954%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=168930820616800180667954&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-2-121228694-null-null.142^v88^insert_down28v1,239^v2^insert_chatgpt&utm_term=ubuntu 安装zsh&spm=1018.2226.3001.4187)



