在分文件编译时对于模板编程遇到的一些问题：显示"underfined reference to ..."。

```text
.
├── CMakeLists.txt
├── README.md
├── build
├── include
│   ├── node.h
│   └── skip_list.h
├── main.cpp
└── src
    ├── node.cpp
    └── skip_list.cpp

3 directories, 7 files
```



![image-20240122135809673](c++%E6%A8%A1%E6%9D%BF%E7%BC%96%E7%A8%8B%E5%88%86%E6%96%87%E4%BB%B6%E7%BC%96%E7%A8%8B%E9%97%AE%E9%A2%98.assets/image-20240122135809673.png)

我检查了好久，且问了chatgpt未找到解决措施。

但是随着不断的排除，最终将问题定位到头文件和源文件没有链接上。我突然想到最早学C++模板编程时，他们是建议用`.hpp`来定义和实现的，但是现在我是分文件编程可能有问题。之后我又在网上搜索，找到了两个解决方法。

## 直接包含源文件

```cpp
#include <iostream>
#include "node.h"
```

将`node.h`换为`node.cpp`，即可。

```cpp
#include <iostream>
#include "node.cpp"
```

这是因为在`.cpp`文件内含有`.h`文件，就相当去编译器知道了头文件和源文件。

![image-20240122140544522](c++%E6%A8%A1%E6%9D%BF%E7%BC%96%E7%A8%8B%E5%88%86%E6%96%87%E4%BB%B6%E7%BC%96%E7%A8%8B%E9%97%AE%E9%A2%98.assets/image-20240122140544522.png)

![image-20240122140600573](c++%E6%A8%A1%E6%9D%BF%E7%BC%96%E7%A8%8B%E5%88%86%E6%96%87%E4%BB%B6%E7%BC%96%E7%A8%8B%E9%97%AE%E9%A2%98.assets/image-20240122140600573.png)



## 将定义和实现写入到一个`.hpp`文件内

```shell
.
├── CMakeLists.txt
├── README.md
├── include
│   ├── node.hpp
│   └── skip_list.hpp
├── introduction(原版)
│   └── 模板采用分文件编程错误x
│       ├── CMakeLists.txt
│       ├── README.md
│       ├── build
│       ├── include
│       │   ├── node.h
│       │   └── skip_list.h
│       ├── main.cpp
│       └── src
│           ├── node.cpp
│           └── skip_list.cpp
└── main.cpp

6 directories, 12 files
```



![image-20240122143529298](c++%E6%A8%A1%E6%9D%BF%E7%BC%96%E7%A8%8B%E5%88%86%E6%96%87%E4%BB%B6%E7%BC%96%E7%A8%8B%E9%97%AE%E9%A2%98.assets/image-20240122143529298.png)





[C++模板笔记八：类模板分文件编写_有类模板的对象怎么分成头文件-CSDN博客](https://blog.csdn.net/xiaoyaolangwj/article/details/122734302)