在vscode中安装这三个插件（clangd需要科学上网或者从VSIX安装）

![image-20240121103403291](%E4%BD%BF%E7%94%A8vscode%E5%9C%A8wsl2%E4%B8%AD%E9%85%8D%E7%BD%AEclangd%E7%8E%AF%E5%A2%83.assets/image-20240121103403291.png)



之后创建一个空目录并进去。

使用快捷键`ctrl+shift+p`，输入命令 `Cmake:Quick Start`

![image-20240121103649991](%E4%BD%BF%E7%94%A8vscode%E5%9C%A8wsl2%E4%B8%AD%E9%85%8D%E7%BD%AEclangd%E7%8E%AF%E5%A2%83.assets/image-20240121103649991.png)

根据步骤选择。注意在创建CMakeLists.txt这一步选择跳过，直接输入`enter`，在最后一步选择`可执行文件`。

![image-20240121103729935](%E4%BD%BF%E7%94%A8vscode%E5%9C%A8wsl2%E4%B8%AD%E9%85%8D%E7%BD%AEclangd%E7%8E%AF%E5%A2%83.assets/image-20240121103729935.png)

之后，cmake就帮我们创建好项目了。

![image-20240121103903273](%E4%BD%BF%E7%94%A8vscode%E5%9C%A8wsl2%E4%B8%AD%E9%85%8D%E7%BD%AEclangd%E7%8E%AF%E5%A2%83.assets/image-20240121103903273.png)



设置clangd编译目录

打开设置，在设置中输入`clang`，找到`clangd: Arguments`

![image-20240121104023908](%E4%BD%BF%E7%94%A8vscode%E5%9C%A8wsl2%E4%B8%AD%E9%85%8D%E7%BD%AEclangd%E7%8E%AF%E5%A2%83.assets/image-20240121104023908.png)

点击添加项，并输入参数

```text
--compile-commands-dir=${workspaceFolder}/build
```



点击右下角的`生成`，进行可执行文件的产生。

![image-20240121104234844](%E4%BD%BF%E7%94%A8vscode%E5%9C%A8wsl2%E4%B8%AD%E9%85%8D%E7%BD%AEclangd%E7%8E%AF%E5%A2%83.assets/image-20240121104234844.png)

进入`build`目录下，命令行输入`./项目名`，可以看见输入内容。

![image-20240121104334605](%E4%BD%BF%E7%94%A8vscode%E5%9C%A8wsl2%E4%B8%AD%E9%85%8D%E7%BD%AEclangd%E7%8E%AF%E5%A2%83.assets/image-20240121104334605.png)



点击`生成`旁边的debug按钮进行debug。



![image-20240121104458828](%E4%BD%BF%E7%94%A8vscode%E5%9C%A8wsl2%E4%B8%AD%E9%85%8D%E7%BD%AEclangd%E7%8E%AF%E5%A2%83.assets/image-20240121104458828.png)

![image-20240121104445108](%E4%BD%BF%E7%94%A8vscode%E5%9C%A8wsl2%E4%B8%AD%E9%85%8D%E7%BD%AEclangd%E7%8E%AF%E5%A2%83.assets/image-20240121104445108.png)

正常运行。



到此，环境已经配置好了。



[无痛VSCode+clangd+lldb+cmake配置C/C++开发环境 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/650472549)