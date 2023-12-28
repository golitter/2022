将python的pip进行换源

```cmd
pip config set global.index-url https://mirrors.aliyun.com/pypi/simple/
```

升级pip版本

```cmd
pip install pip -U
```

临时指定pip源

```python
 pip install matplotlib -i  https://pypi.tuna.tsinghua.edu.cn/simple/

```

