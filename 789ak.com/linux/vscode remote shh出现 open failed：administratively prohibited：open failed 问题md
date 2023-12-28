# vscode remote shh出现 open failed：administratively prohibited：open failed 问题

**问题：**

```
Connected to SSH Host - Please do not close this terminal
channel 2: open failed: administratively prohibited: open failed
channel 3: open failed: administratively prohibited: open failed
channel 2: open failed: administratively prohibited: open failed
```

**解决方案：**在vscode的remote-ssh配置里，把remote.SSH.remoteServerListenOnSocket的勾去掉，然后kill掉linux上所有vscode-server，删除~/.vscode-server目录。重新进行连接就正常了。

