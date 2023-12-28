我在windows上的WSL2中安装docker失败的原因有很多。有时是apt-get安装出现问题（ubuntu上的包管理不熟），有时是docker里面内容安装错误，还有就是WSL2上的systemctl目前不能用。

配完这个WSL2环境，感觉通过vscode连接WSL2比vscode的remote-ssh要更加便捷。但是现在认为可能现在WSL2只是便捷，但是真用来做工作还是有很多不足的，因为有的命令在WSL2内还不能用，而且可能有的错误还跟windows本地环境有关。现在还是VM更加好用吧。

## WSL2安装docker

在WSL2上安装了好几次docker，一直不成功。试了好几次，以为是自己的问题，最后用在菜鸟教程上用docker一个直接安装脚本安装，发现docker官网建议WSL2在windows环境中配docker。

在windows上安装docker [WSL2安装Docker](https://blog.csdn.net/qq_46416934/article/details/126552939)

不过一安装好docker，WSL2又出现问题了，一直让输入密码，但是输入正确的密码就退出了。这个WSL2做点其他的真困难。再次感觉到，重启可以解决几乎所有问题。

