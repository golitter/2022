## 导出插件

```shell
code --list-extensions > plugins
```

![image-20240119140006615](vscode%E5%AF%BC%E5%87%BA%E3%80%81%E5%AF%BC%E5%85%A5%E5%85%A8%E9%83%A8%E6%8F%92%E4%BB%B6.assets/image-20240119140006615.png)

![image-20240119140020689](vscode%E5%AF%BC%E5%87%BA%E3%80%81%E5%AF%BC%E5%85%A5%E5%85%A8%E9%83%A8%E6%8F%92%E4%BB%B6.assets/image-20240119140020689.png)

## 导入插件

将要导入的插件文本位置与终端位置一致

```shell
Get-Content plugins | ForEach-Object { code --install-extension $_ }
```





[在VSCode中导出安装的所有插件并在其他计算机进行导入-CSDN博客](https://blog.csdn.net/weixin_42064877/article/details/131610718?ops_request_misc=%7B%22request%5Fid%22%3A%22170564341016800213050560%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=170564341016800213050560&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~baidu_landing_v2~default-1-131610718-null-null.142^v99^pc_search_result_base3&utm_term=vscode如何导出安装的插件&spm=1018.2226.3001.4187)

