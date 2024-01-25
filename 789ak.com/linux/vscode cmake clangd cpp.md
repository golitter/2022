

在wsl2上安装`cmake`和`clangd`

```shell
sudo apt install cmake
sudo apt install clang clangd
```

在vscode中，下载 clangd 和 cmake tool 工具集就可以了，但是注意一点，clangd的代码分析跟微软提供的c/c++代码分析有一定的冲突，所以需要禁用掉c/c++那个代码分析，只需要在vscode的settings.json里面加入

```text
    "C_Cpp.intelliSenseEngine": "disabled",
```

### cmake, 启动！

在某一个文件夹中创建以下目录即可，一个main.cpp文件，一个CMakeLists.txt文件，然后一个build文件夹，build文件夹里面是生成的可执行文件。

```text
.
├── build
├── CMakeLists.txt
└── main.cpp
```

在cmake中写上

```cmake
# cmake版本的需求，写上去就行
cmake_minimum_required(VERSION 3.22)

# 设置 c++ 版本为 17
set(CMAKE_CXX_STANDARD 17)

# 将c++项目的版本必须设置成 17 这个版本
# 必须要的，因为这个选项会将 -std=c++17 导入到 compile_commands.json里面,供clangd分析
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# 必须，这句话是导出 compile_commands.json 文件的
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 项目名字
project(cpp_study)
# 可执行文件，会生成一个cpp_study的可执行文件
add_executable(cpp_study main.cpp)
```

这样之后。执行一下操作：

```text
cd build 
cmake .. # 生成MakeFile文件
make -j8 # 意思是构建可执行文件
```

然后就会生成compile_commands.json文件了，clangd就会进行工作，如果不能工作，那么就使用命令ctrl + shift + p 搜索clangdr,重启clangd,

之后在main.cpp里面clangd就会进行分析了，注意：如果clangd要分析c++17等比较高版本的代码，那么所有的指令必须要落实到compile_commands.json里面，比如说这次我们生成的文件里面就是这个。

```text
[{
  "directory": "/home/xxx/acm_c++/build",
  "command": "/usr/bin/c++   -std=gnu++17 -o CMakeFiles/cpp_study.dir/main.cpp.o -c /home/lzc/acm_c++/main.cpp",
  "file": "/home/lzc/acm_c++/main.cpp"
}]
```

注意，这个命令里面的-std=gun++17,就是上如要写的版本信息，要加入到里面，clangd才会分析相关代码，如果不加入，那么就会缺失一些信息，比如说std::is_same_v<xxx,xxxx>这样的就提示分析不出来。。





[在vscode中使用cmake + clangd 编写c++项目或算法竞赛 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/673706131)