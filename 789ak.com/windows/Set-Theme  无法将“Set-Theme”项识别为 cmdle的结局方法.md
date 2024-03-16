Set-Theme : 无法将“Set-Theme”项识别为 cmdle的结局方法

```powershell
Import-Module posh-git 
Import-Module oh-my-posh 
Set-Theme Agnoster
```

将`Set-Theme`更改为`Set-PoshPrompt`即可。

```powershell
Import-Module posh-git 
Import-Module oh-my-posh 
Set-PoshPrompt Agnoster
```

