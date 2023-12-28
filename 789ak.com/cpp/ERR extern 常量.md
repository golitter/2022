# ERR extern 常量

A.cpp:
<pre class="code"> <span style="background-color: #f5f5f5; font-family: Consolas, Monaco, monospace;">const int FUNC_CONST_VALUE = 12345;</span></pre>
B.cpp:
<pre class="code"> extern const int FUNC_CONST_VALUE;</pre>
在B.cpp中运行错误。

&nbsp;

该错误明显是因为程序使用了未定义的变量而报的错。

A.cpp 加上 extern即可：
<pre class="code">  extern <span style="background-color: #f5f5f5; font-family: Consolas, Monaco, monospace;">const int FUNC_CONST_VALUE = 12345;</span></pre>
<a href="https://blog.csdn.net/qq_33659478/article/details/109199310?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167515428116800215010728%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&amp;request_id=167515428116800215010728&amp;biz_id=0&amp;utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-2-109199310-null-null.142^v71^control,201^v4^add_ask&amp;utm_term=extern%20%E5%B8%B8%E9%87%8F&amp;spm=1018.2226.3001.4187">C++全局常量声明和定义extern</a>

