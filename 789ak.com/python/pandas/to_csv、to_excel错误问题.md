> 使用`df.to_csv()`和`df.to_excel()`报错问题。使用`to_csc()`打开乱码，使用`to_excel()`报错等。

### `to_csc()`乱码问题

设置参数`encoding = utf-8-sig`（带“sig”不乱码，不带就乱码）

```python
df.to_csv("./test.csv", encoding = "utf-8-sig")
```

### `to_excel()`报错问题

可能是没有导入`xlsxwriter`这个模块。

```python
df.to_excel("test.xls", engine = "xlsxwriter", encoding = "utf-8")
```



[pandas.to_csv乱码、丢失行、自动换行如何处理](https://blog.csdn.net/Today_history/article/details/127517276?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522168294595716800197047922%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=168294595716800197047922&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-127517276-null-null.142%5Ev86%5Ewechat,239%5Ev2%5Einsert_chatgpt&utm_term=to_csv%E4%B9%B1%E7%A0%81&spm=1018.2226.3001.4187)