### 直接使用list关键字，返回一个list

```python
columns_name1 = list(df)
```

### 链式推导式获取pandas列名的方法

```python
columns_name2 = [ column for column in df ]
```

### 通过columns字段获得，返回一个numpy型的数组

```python
columns_name3 = df.columns
```

