在windows上的`powershell`上配置`oh-my-posh`，使其更像在linux用`oh-my-zsh`。

- 首先打开`powershell`，输入：

```shell
winget install JanDeDobbeleer.OhMyPosh -s winget
```

安装`on-my-posh.exe`和`oh-my-posh`上最新的主题。

之后重启`powershell`。

- 打开配置文件

```powershell
# 如果之前没有配置文件，就新建一个 PowerShell 配置文件
if (!(Test-Path -Path $PROFILE )) { New-Item -Type File -Path $PROFILE -Force }
# 用记事本打开配置文件
notepad $PROFILE
```

```powershell
Import-Module posh-git 
Import-Module oh-my-posh
# 设置主题为Agnoster
Set-PoshPrompt Agnoster
```

之后重启即可。

![image-20240309155856409](%E9%85%8D%E7%BD%AEoh-my-posh.assets/image-20240309155856409.png)

由于windows缺少一些支持的字体，所以看见的是乱码的情况。

在[Nerd Fonts - Iconic font aggregator, glyphs/icons collection, & fonts patcher](https://www.nerdfonts.com/font-downloads)上找字体进行下载。

推荐使用`Meslo Nerd Font`，

![image-20240309160219257](%E9%85%8D%E7%BD%AEoh-my-posh.assets/image-20240309160219257.png)

![image-20240309160227931](%E9%85%8D%E7%BD%AEoh-my-posh.assets/image-20240309160227931.png)

下载完成进行解压后，打开目录：全选进行字体安装

![image-20240309160518963](%E9%85%8D%E7%BD%AEoh-my-posh.assets/image-20240309160518963.png)

在终端默认值中进行设置：

![image-20240309160602876](%E9%85%8D%E7%BD%AEoh-my-posh.assets/image-20240309160602876.png)

之后就配置好了。

![image-20240309160638694](%E9%85%8D%E7%BD%AEoh-my-posh.assets/image-20240309160638694.png)



在`vscode`终端中配置，打开`setting.json`，进行设置

```json
    "terminal.integrated.fontFamily": "MesloLGM Nerd Font",
```



![image-20240309160729828](%E9%85%8D%E7%BD%AEoh-my-posh.assets/image-20240309160729828.png)

![image-20240309160757652](%E9%85%8D%E7%BD%AEoh-my-posh.assets/image-20240309160757652.png)



## 待解决

windows10默认的`powershell`字体选项中没有`Meslo Nerd Font`，仍然乱码。

![image-20240309161032203](%E9%85%8D%E7%BD%AEoh-my-posh.assets/image-20240309161032203.png)





[5 个 PowerShell 主题，让你的 Windows 终端更好看 - 少数派 (sspai.com)](https://sspai.com/post/52907)

[Windows Terminal 快速配置 oh-my-posh_windows 设备oh-my-posh字体-CSDN博客](https://blog.csdn.net/uddiqpl/article/details/128330212?ops_request_misc=&request_id=&biz_id=102&utm_term=oh-my-posh字体&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-2-128330212.142^v99^pc_search_result_base3&spm=1018.2226.3001.4187)

[Fonts | Oh My Posh](https://ohmyposh.dev/docs/installation/fonts)

