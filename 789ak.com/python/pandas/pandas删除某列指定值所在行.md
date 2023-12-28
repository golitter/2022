### `data.dropna()`

`data.dropna()`默认删除带空缺值的所有行。

dropna()的参数如下：

```python
data.dropna(
	axis = 0,
    how = "any",
    thresh = None,
    subset = None,
    inplace = False
)
```

##### axis确定删除存在缺失值的行或者列

`axis = 0` 或者 `axis = "index"`删除含有缺失值的行。

`axis = 1`或者`axis = "columns"·删除含有缺失值的列。

##### `how`确定当存在缺失值时，是否删除行或者列

`how = "all"`表示删除全是缺失值的行（列）

`how = "any"`表示删除只要有缺失值的行（列）

##### `thresh = n`表示保留至少含有n个非na数值的行

##### `subset`确定要在那些列中查找缺失值

##### `inplace`确定是否直接在原DataFrame上修改

### `data.drop()`

默认参数

```python
默认参数：
data.drop(
    labels=None,
    axis=0,
    index=None,
    columns=None,
    level=None,
    inplace=False,
    errors='raise',
)
```

##### `labels`指定要删除的行或列的名称

```
#参数axis为0表示在行上搜索名为“姓名”的对象，然后删除对象“姓名”对应的行。
data.drop("姓名",axis = 0)
 
#参数axis为1表示在列上搜索名为“姓名”的对象，然后删除对象“姓名”对应的列。
data.drop("姓名"，axis = 1)
```



##### index指定要删除的行

```python
# 删除data中索引为0和1的行。
data.drop(index = [0, 1])
```

##### columns指定要删除的列

```python
# 删除data中列名为"name"和"age"的列
data.drop(columns = ["name", "age"])
```

