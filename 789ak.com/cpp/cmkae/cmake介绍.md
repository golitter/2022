CMake是一个跨平台的安装/编译工具，它能用简单的语句描述所有平台的安装/编译过程。通常在UNIX环境下，CMake根据CMakeLists.txt生成Makefile，在Makefile中定义了具体的编译过程。

![image-20240120150611598](cmake%E4%BB%8B%E7%BB%8D.assets/image-20240120150611598.png)

左边图示是未使用cmake的构建项目的流程图，右边是使用cmake构建的，可以看到用cmake构建的项目会更见便捷。



## 语法特性介绍

**基本语法格式：指令(参数1 参数2 ...)**

- 参数用**括弧**括起来
- 参数之间使用**空格**或**分号**分开

**指令是大小写无关的，参数和变量是大小写相关的**

**变量使用`${}`方式取值，但是在`IF`控制语句中直接使用变量名**

## 重要指令

- `cmake_minimum_required` - 指定cmake的最小版本要求

  语法：

  ```cmake
  cmake_minimum_required(VERSION versionNumber [FATAL_ERROR])
  ```

  e.g.

  ```cmake
  # cmake最小版本要求为3.22
  cmake_minimum_required(VERSION 3.22)
  ```

- `project` - 定义工程名称，并可以指定工程支持的语言

  语法：

  ```cmake
  project(projectName [CXX][C])
  ```

  e.g.

  ```cmake
  # 指定工程名为PJ1
  project(PJ1)
  ```

- `set` - 显示的定义变量

  语法：

  ```cmake
  set(VAR [VALUE] [CACHE TYPE DOCSTRING][FORCE])
  ```

  e.g.

  ```cmake
  #定义SRC变量，其值为 a.cpp b.cpp
  set(SRC a.cpp b.cpp)
  ```

- `include_directories` - 向工程添加多个特定的头文件搜索路径

  语法：

  ```cmake
  include_directories([AFTER | BEFORE][SYSTEM] dir1 dir2 ..)
  ```

  e.g.

  ```cmake
  # 将/usr/include/myincludefolder 和 ./include 添加到库文件搜索路径
  include_directories(/usr/include/myincludefolder ./include)
  ```

- `link_directories` - 向工程添加多个特定的库文件搜索路径

  语法：

  ```cmake
  link_directories(dir1 dir2 ...)
  ```

  e.g.

  ```cmake
  # 将/usr/lib/mylib 添加到库文件搜索路径
  link_directories(/usr/lib/mylib)
  ```

- `add_library` - 生成库文件

  语法：

  ```cmake
  add_library(libname [SHARED | STATIC | MODULE] [EXCLUDE_FROM_ALL] src1 src2)
  ```

  e.g.

  ```cmake
  # 通过变量SRC生成libhello.so 共享库
  add_library(hello SHARED ${SRC})
  ```

- `add_compile_options` - 添加编译参数

  语法：

  ```cmake
  add_compile_options(<opt> ...)
  ```

  e.g.

  ```cmake
  # 添加参数 -Wall -std=c++11
  add_compile_options(-Wall -std=c++11 -o2)
  ```

- `add_executable` - 生成可执行文件

  语法：

  ```cmake
  add_executable(exename src1 src2 ..)
  ```

  e.g.

  ```cmake
  # 编译main.cpp 生成可执行文件为main
  add_executable(main main.cpp)
  ```

- `target_link_libraries` - 为`target`添加需要链接的共享库

  语法：

  ```cmake
  target_link_libraries(target library1<debug | optimized> ...)
  ```

  e.g.

  ```cmake
  # 将hello动态库文件链接到可执行文件main
  target_link_libraries(main hello)
  ```

- `add_subdirectory` - 向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制存放的位置

  语法：

  ```cmake
  add_subdirectory(source_dir [binary_dir][EXCLUDE_FROM_ALL])
  ```

  e.g.

  ```cmake
  # 添加src子目录，src中需要有一个CMakeLists.txt文件
  add_subdirectory(src)
  ```

- `aux_source_directory` - 发现一个目录下所有的源代码文件并将列表存储在一个变量中，这个指令临时被用来自动构建源文件列表

  语法：

  ```cmake
  aux_source_directory(dir VARIABLE)
  ```

  e.g.

  ```cmake
  # 定义SRC变量，其值为当前目录下所有的源代码文件
  aux_source_directory(. SRC)
  # 编译SRC变量所代表的源代码文件，生成main可执行文件
  add_executable(main ${SRC})
  ```

  











[6.1Cross-platform development 6.2 语法特性介绍_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1fy4y1b7TC?p=16&vd_source=13dfbe5ed2deada83969fafa995ccff6)