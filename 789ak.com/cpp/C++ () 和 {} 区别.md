C++11以后，对象的初始化可以通过三种方式给出：(), = 和 {}。

{} 初始化列表（Uniform Initiaization）。

使用{}的初始化方式称为适用于任何对象初始化的场景。

{} 的新特性：
<ul>
 	<li>禁止基础类型的隐性转换</li>
</ul>
<pre class="EnlighterJSRAW" data-enlighter-language="cpp" data-enlighter-theme="monokai">int a(3.01); // a = 3
int a = true; // a = 1
int a{4.3}; // 报错</pre>
<ul>
 	<li>避免将对象的默认构造转换成函数声明的情况发生</li>
</ul>
<pre class="EnlighterJSRAW" data-enlighter-language="cpp" data-enlighter-theme="monokai">A A(); // 声明一个返回值为A的函数A()
A A{}; // 声明一个A数据类型的元素，并调用默认构造函数</pre>
<ul>
 	<li>当使用 {} 初始化auto变量时，类型推断是std::initializer_list，而不是其他数据类型</li>
</ul>
<pre class="EnlighterJSRAW" data-enlighter-language="cpp" data-enlighter-theme="monokai">auto f{1}; // f 是 std::initializer_list 类型</pre>
有std::initializer_list类型的构造函数时，优先调用std::initializer_list类型的构造函数。

如果是{}的空参列表，则调用默认构造函数。

&nbsp;

<a href="https://blog.csdn.net/zqxf123456789/article/details/107128067?ops_request_misc=&amp;request_id=&amp;biz_id=102&amp;utm_term=c++%20()%20%7B%7D&amp;utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-4-107128067.142^v73^control,201^v4^add_ask,239^v1^insert_chatgpt&amp;spm=1018.2226.3001.4187">[C++] - 创建对象时 () 和 {} 的区别</a>

<a href="https://blog.csdn.net/liangxiangbin/article/details/116173053?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167603571416800184159801%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&amp;request_id=167603571416800184159801&amp;biz_id=0&amp;utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-1-116173053-null-null.142^v73^control,201^v4^add_ask,239^v1^insert_chatgpt&amp;utm_term=initializer_list&amp;spm=1018.2226.3001.4187">initializer_list使用</a>

&nbsp;

