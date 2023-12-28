在C++11中，lambda表达式函数递归往往会带上`<functional>`头文件。书写形式如下：

```c++
    function<int(int)> fib = [&fib] (int n) {
        if(n <= 2) return 1;
        else return fib(n-1) + fib(n-2);
    };
	cout<<fib(5);
```

还有相对简单点的第二种写法（C++14）：

```c++
    auto fib = [](auto && fib, int n)  -> int {
        if(n <= 2) return 1;
        else return fib(fib, n - 1) + fib(fib, n - 2);
    };
    cout<<fib(fib,5);
```

对于第二种，`auto && fib`的作用是为了在 lambda 表达式内部能够递归调用自身。在 C++14 中，lambda 表达式默认是无法直接递归调用的，因为在 lambda 内部无法访问到自身的定义。

使用 `auto &&fib` 的方式，实际上是将递归函数对象传递给 lambda 表达式本身，通过递归调用传递进来的函数对象来实现递归。

具体原理是这样的：

1. `auto &&fib` 定义了一个右值引用类型的函数对象，这个函数对象被称为 `fib`。
2. 在 lambda 表达式内部，`fib` 可以被直接调用，因为它是一个函数对象。
3. 在递归调用时，`fib` 会被传递给自身，从而完成对自身的递归调用。

这种技巧可以绕过对 lambda 表达式递归调用的限制，实现了在 lambda 表达式内部递归调用自身的需求。



[(7条消息) C++ 实现lambda递归调用（C++11 - C++23）_c++ lambda 递归_J__M__C的博客-CSDN博客](https://blog.csdn.net/J__M__C/article/details/125437699?ops_request_misc=&request_id=&biz_id=102&utm_term=lambda表达式泛型递归&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-125437699.142^v91^insert_down1,239^v3^control&spm=1018.2226.3001.4187)

chatGPT