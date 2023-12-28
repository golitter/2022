## 将numpy转换为pandas的DataFrame

```python
pd_file = pd.DataFrame(np_file, columns = [
	..len(columns)
])
```

```python
pd_file = pd.DataFrame(a, index=['a', 'b', 'c'], columns=['a', 'b', 'c', 'd'])
```



## 将pandas转换为numpy

```python
np_file = np.array(pd_file)
```

