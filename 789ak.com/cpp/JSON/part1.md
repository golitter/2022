JSON（<a href="https://baike.baidu.com/item/JavaScript?fromModule=lemma_inlink" target="_blank" rel="noopener" data-log="summary">JavaScript</a> Object Notation, JS对象简谱）是一种轻量级的数据交换格式。它基于 <a href="https://baike.baidu.com/item/ECMAScript?fromModule=lemma_inlink" target="_blank" rel="noopener" data-log="summary">ECMAScript</a>（European Computer Manufacturers Association, 欧洲计算机协会制定的js规范）的一个子集，采用完全独立于编程语言的文本格式来存储和表示数据。简洁和清晰的层次结构使得 JSON 成为理想的数据交换语言。 易于人阅读和编写，同时也易于机器解析和生成，并有效地提升网络传输效率。

第一个练手项目，用C++实现JSON解析器，工具是vscode，cmake，git。
<div>
<div>为了防止可能跟其他的命名产生冲突，用命名空间进行隔离。</div>
<div>
<pre class="code">namespace golitter {
namespace json{
...
}}</pre>
</div>
</div>
首先是要做一个类似于JavaS cript的动态类型。
用枚举来判断静态的数据类型。

<div>
<div></div>
<div>
<pre class="code"> enum Type {
json_null = 0,
json_bool,
json_int,
json_double,
json_string,
json_array,
json_object
};</pre>
</div>
用联合体存储数据内容。

&nbsp; 
<pre class="EnlighterJSRAW" data-enlighter-language="cpp" data-enlighter-theme="monokai">union Value {
bool m_bool;
int m_int;
double m_double;
std::string* m_stringaddress;
std::vector&lt;Json&gt; * m_arrayaddress;
std::map&lt;string,Json&gt; * m_objectaddress;
};</pre>
&nbsp;

定义两个变量，一个用来判断当前数据的类型，一个保存数据内容。

&nbsp;
<pre class="EnlighterJSRAW" data-enlighter-language="generic">Type m_type;
Value m_value;</pre>
&nbsp;

首先是将动态数据类型写出来，之后是将他进行静态类型的转换。

<img class="wp-image-394 size-full aligncenter" src="https://789ak.com/wp-content/uploads/2023/02/Pasted-8.png" />

通过构造函数初始化来完成动态类型Json的构造。

<img class="wp-image-395 size-full aligncenter" src="https://789ak.com/wp-content/uploads/2023/02/Pasted-9.png" />

用基本数据类型运算符重载，将Json类型向基本数据类型转换。

&nbsp;
<pre class="EnlighterJSRAW" data-enlighter-language="generic">operator bool();

operator int();

operator double();

operator string();</pre>
&nbsp;

之后是数组和对象类型的动态实现，和Json.str()的实现。

<img class="wp-image-398 size-full aligncenter" src="https://789ak.com/wp-content/uploads/2023/02/Pasted-10.png" />

对数组用中括号([])重载，和向后添加元素函数(append)实现。

&nbsp;

&nbsp;
<div>
<div>
<div></div>
</div>
<div>
<pre class="EnlighterJSRAW" data-enlighter-language="cpp" data-enlighter-theme="monokai" data-enlighter-highlight="1,2-6,9">Json&amp; Json::operator [] (int index ) {
    /**
     * 先判断是不是数组类型，
     * 不是将类型设置为数组类型，并赋予初始化指针
    */
    if(m_type != json_array) {
        m_type = json_array;
        m_value.m_arrayaddress = new std::vector&lt;Json&gt;();
    }
    if(index &lt; 0) {
        throw new std::logic_error("error: array index &lt; 0");
    }
    /**
     * index用size_t的话，会与后面 对象的中括号重载产生模糊。
     * 因为数组下标 arr[index]在书写读入时，默认是int，因而于size_t不符合，且和其他重载不同而错误。
     * https://blog.csdn.net/xinqjl/article/details/103108569/
    */
    int length = (m_value.m_arrayaddress)-&gt;size();
    /**
     * 下标数字 大于 当前数组长度，将两者中间的元素添加且赋空。
    */
    if(index &gt;= length) {
        for(int i =  length; i &lt;= index; ++i) {
            (m_value.m_arrayaddress)-&gt;push_back(Json());
        }
    }
    return ( (m_value.m_arrayaddress)-&gt;at(index) );
}
    operator string();</pre>
&nbsp;

</div>
<div>
<div>
<pre class="EnlighterJSRAW" data-enlighter-language="cpp" data-enlighter-theme="monokai" data-enlighter-highlight="1,2-6,9">void Json::append(const Json &amp; other ) {
    /**
     * Json类型不是数组，先清除其他的内容，防止内存泄漏，
     * 再赋予为数组类型
    */
    if(m_type != json_array) {
        clear();
        m_type = json_array;
        m_value.m_arrayaddress = new std::vector&lt;Json&gt;();
    }
    (m_value.m_arrayaddress)-&gt;push_back(other);
}</pre>
&nbsp;

</div>
<div>对象类型与数组类型相似，用中括号重载和赋值重载。</div>
<div>
<div>
<div>
<pre class="EnlighterJSRAW" data-enlighter-language="cpp" data-enlighter-theme="monokai" data-enlighter-highlight="1,2-6,9">Json&amp; Json::operator [] (const char * key) {
    /**
     * 将const char * 的字符串转为string字符串，并调用string字符串的函数
    */
    string name(key);
    return ( *(this) )[name];
}
Json&amp; Json::operator [] (const string &amp; key) {
    if(m_type != json_object) {
        clear();
        m_type = json_object;
        // 对象的初始化指针
        m_value.m_objectaddress = new std::map&lt;string, Json&gt;();
    }
    return ( *(m_value.m_objectaddress) )[key]; // 即 (map&lt;&gt;)[key]
}
/// @brief Json的拷贝
/// @param other Json数据
void Json::operator = (const Json &amp; other) {
    // 先清除，再拷贝
    clear();
    copy(other);
}</pre>
&nbsp;

</div>
</div>
将Json用字符串形式返回，用switch利用递归思想返回。

<img class="alignnone wp-image-401 size-full aligncenter" src="https://789ak.com/wp-content/uploads/2023/02/Pasted-11.png" />

</div>
<div></div>
</div>
</div>
</div>