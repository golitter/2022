之前文件上传到github上了，但是现在又想要把它删除但是没有找到方法，在网上搜索了很久才找到个有用的。

删除文件

```bash
git rm filename
git commit -m "删除"
```

但是这时候`git push`发现没有效果。

之后还要：

清除缓存：

```bash
git rm -r --cached .
git add .
```

提交记录：

```bash
git commit -m "删除"
git push
```

