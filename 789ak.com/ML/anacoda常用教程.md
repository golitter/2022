### 查看当前的所有环境

```cmd
conda info --envs
-- 或
conda env list
```

### 创建虚拟环境

创建一个python版本为beta的虚拟环境名为env_name的虚拟环境。

```cmd
conda create -n env_name [ python=beta ]
```

### 删除虚拟环境

```cmd
conda remove -n env_name --all
```

#### 激活虚拟环境

```cmd
conda activate env_name
```

#### 关闭虚拟环境

```cmd
conda deactivate env_name
```

#### 虚拟环境内安装包操作

##### 如果没有进入要安装包的虚拟环境

```cmd
# 查看指定环境下已安装的package
conda list -n env_name
# 安装指定环境下某个package
conda install -n env_name [package]
# 删除指定环境下某个package
conda remove -n env_name [package]
# 更新指定环境下某个package
conda update -n env_name [package]
```

##### 进入到了要安装包的虚拟环境

```cmd
# 查看已安装的package
conda list
# 安装某个package
conda install [package]
# 删除某个package
conda remove [package]
# 更新某个package
conda update [package]

# 更新conda，保持conda最新
conda update conda
```

##### 导出虚拟环境yaml文件

```cmd
conda env export > environment.yaml -- 导出
conda env create -f environment.yaml -- 导入
```

##### pip导入虚拟环境包信息

```cmd
pip freeze > requirements.txt -- 导出
pip install -r requirements.txt -- 导入
```

