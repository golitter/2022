今天，想着将之前鸽的Unet网络模型给实现一下，结果发现，在vscode中运行python脚本，显示没有这包，没有那包。但是在其他的ipynb中是有的，感觉很奇怪。我检查了一下python版本，发现不是我深度学习的python3.8版本，而是默认的3.10。

然后我想在vscode的终端中显式的调用conda虚拟环境中的python，但是conda命令却用不了。经过一顿分析和搜索，终于找到了原因：vscode终端的powershell脚本执行策略受限。

在每次打开vscode终端后，总是显示：

```powershell
Windows PowerShell
版权所有（C） Microsoft Corporation。保留所有权利。

安装最新的 PowerShell，了解新功能和改进！https://aka.ms/PSWindows

. : 无法加载文件 C:\Users\87897\Documents\WindowsPowerShell\profile.ps1，因为在此系统上禁止运行脚本。有关详细信息，请参
阅 https:/go.microsoft.com/fwlink/?LinkID=135170 中的 about_Execution_Policies。
所在位置 行:1 字符: 3
+ . 'C:\Users\87897\Documents\WindowsPowerShell\profile.ps1'
+   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    + CategoryInfo          : SecurityError: (:) []，PSSecurityException

```

这表示powershell脚本执行策略受限。

解决方案：

以**管理员**权限打开powershell。

```powershell
set-ExecutionPolicy RemoteSigned
```

之后输入`Y`，表示同意。

最后检查是否成功：

```powershell
get-ExecutionPolicy
```

如果是`RemoteSigned`表示可以了，如果是`Restricted`则没有成功。



然后就可以快乐的深度学习了。（就会发现是码的错了

![image-20230924213154707](https://cdn.789ak.com/img/image-20230924213154707.png)