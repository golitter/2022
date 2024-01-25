根据这个UML图进行cmake的实践

![image-20240121114636995](%E4%BD%BF%E7%94%A8cmake%E8%BF%9B%E8%A1%8C%E5%AE%8C%E6%88%90%E5%BC%80%E5%8F%91%E5%AE%9E%E8%B7%B5.assets/image-20240121114636995.png)

首先按照[使用vscode在wsl2中配置clangd环境-CSDN博客](https://blog.csdn.net/qq_63432403/article/details/135726686?spm=1001.2014.3001.5502)的内容先创建出cmake项目。

之后在项目目录中创建`include`和`src`目录。

根据UML图，首先要完成`Gun`类的实现。分别在`include`，`src`目录下创建头文件和源文件，写入要求逻辑。

![image-20240121115226347](%E4%BD%BF%E7%94%A8cmake%E8%BF%9B%E8%A1%8C%E5%AE%8C%E6%88%90%E5%BC%80%E5%8F%91%E5%AE%9E%E8%B7%B5.assets/image-20240121115226347.png)

之后按照上面步骤实现`Soldier`的实现。

![image-20240121115306280](%E4%BD%BF%E7%94%A8cmake%E8%BF%9B%E8%A1%8C%E5%AE%8C%E6%88%90%E5%BC%80%E5%8F%91%E5%AE%9E%E8%B7%B5.assets/image-20240121115306280.png)



在`main.cpp`内进行测试。

![image-20240121115348042](%E4%BD%BF%E7%94%A8cmake%E8%BF%9B%E8%A1%8C%E5%AE%8C%E6%88%90%E5%BC%80%E5%8F%91%E5%AE%9E%E8%B7%B5.assets/image-20240121115348042.png)



最后在`CMakeLists.txt`内进行描述。

```cmake
cmake_minimum_required(VERSION 3.0.0)
project(TEST VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()
# 这行代码的作用是将当前源代码目录（${CMAKE_SOURCE_DIR}）和相对路径./include添加到项目的包含目录中。
include_directories(${CMAKE_SOURCE_DIR} ./include)
# 添加可执行文件TEST，它由main.cpp、Gun.cpp和Soldier.cpp这三个源文件构建而成。
add_executable(TEST main.cpp src/Gun.cpp src/Soldier.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

```

> 如果没有将`./include`添加到项目的包含目录下，编译器就无法找到自定义的头文件。
>
> 在CMake中，`include_directories`用于指定项目的头文件搜索路径，以便编译器能够找到头文件。在这个实践中，它告诉CMake在搜索头文件时包括当前源代码目录和`./include`目录。

点击`生成`即可产生可执行文件。

![image-20240121115816241](%E4%BD%BF%E7%94%A8cmake%E8%BF%9B%E8%A1%8C%E5%AE%8C%E6%88%90%E5%BC%80%E5%8F%91%E5%AE%9E%E8%B7%B5.assets/image-20240121115816241.png)



测试调试

![image-20240121115847571](%E4%BD%BF%E7%94%A8cmake%E8%BF%9B%E8%A1%8C%E5%AE%8C%E6%88%90%E5%BC%80%E5%8F%91%E5%AE%9E%E8%B7%B5.assets/image-20240121115847571.png)

https://www.bilibili.com/video/BV1fy4y1b7TC/?p=22&spm_id_from=333.1007.top_right_bar_window_history.content.click