## 按行遍历

![image-20230502012404728](http://cdn.789ak.com/img/image-20230502012404728.png)

### 使用df.index df.columns

```python
for i in df.index: # i -> (0, 1)
    for j in df.columns: # j -> (A, B, C)
        print(df.loc[i,j])
```



#### 使用loc或者iloc

```python
df = pd.read_excel("./test.xlsx")
print(df)
for i in range(df.shape[0]):
    for j in range(df.shape[1]):
        print(df.iloc[i,j], end= " ")
    print()
```

### 使用iterrows()方法

iterrows()：按行遍历，将DataFrame的每一行迭代为(index, Series)对，可以通过row[name]对元素进行访问。

```python
for i in df.iterrows():
    print(i)
    # for j in i:
    #     print(j ,end=" ")
    # print()
```

![image-20230502012057741](http://cdn.789ak.com/img/image-20230502012057741.png)

### 按列同理



[Python pandas 按行、按列遍历DataFrame](https://blog.csdn.net/weixin_43115411/article/details/126030711?ops_request_misc=&request_id=&biz_id=102&utm_term=python%20%E9%81%8D%E5%8E%86pandas%20dataframe&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-126030711.142%5Ev86%5Ewechat,239%5Ev2%5Einsert_chatgpt&spm=1018.2226.3001.4187)