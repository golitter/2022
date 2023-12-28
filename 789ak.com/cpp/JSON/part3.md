将实现的Json解析器的浅拷贝改为深拷贝。

本来想将联合体内的指针用智能指针代替的，但是联合体内不支持用智能指针。

只要将copy()函数用深拷贝来改就行了，因为Json()和operator=()都调用的是copy()函数。

需要分配内存的只有字符串、数组、对象类型，因此用了copy_string() copy_array() copy_object() 来实现。

在对数组进行深拷贝更改时，发现确定了数据类型，但是没有分配内存。

<img class="alignnone wp-image-481 size-full" src="https://789ak.com/wp-content/uploads/2023/02/Pasted-34.png" />

然后发现，在copy()函数内，没有给地址分配内存。

<img class="alignnone wp-image-481 size-full" src="https://789ak.com/wp-content/uploads/2023/02/Pasted-34.png" />

<img class="alignnone wp-image-482 size-full" src="https://789ak.com/wp-content/uploads/2023/02/Pasted-35.png" />

改为深拷贝后，相应的比较函数也要由原来的浅拷贝改为深拷贝。
<pre class="EnlighterJSRAW" data-enlighter-language="cpp" data-enlighter-theme="monokai">// 等号重载
bool operator == (const Json &amp; other);
bool operator != (const Json &amp; other);
bool compare(const Json&amp; other);
bool compare_array(const Json&amp; array);
bool compare_object(const Json&amp; object);</pre>
将运算符重载，里面用compare()函数，compare()函数内部对数组类型和对象类型进行对比。
<pre class="EnlighterJSRAW" data-enlighter-language="cpp" data-enlighter-theme="monokai">bool Json::compare_array(const Json&amp; array) {
    int other_length = (array.m_value.m_arrayaddress)-&gt;size();
    int this_length = (m_value.m_arrayaddress)-&gt;size();
    if(other_length != this_length) {
        return false;
    }

    for(auto other_it = (array.m_value.m_arrayaddress)-&gt;begin(), this_it = (m_value.m_arrayaddress)-&gt;begin(); this_it != (m_value.m_arrayaddress)-&gt;end(); ++other_it, ++this_it) {
        if(!this_it-&gt;compare(*other_it)) return false;
    }
    return true;

}
bool Json::compare_object(const Json&amp; object) {
    int other_length = (object.m_value.m_objectaddress)-&gt;size();
    int this_length = (m_value.m_objectaddress)-&gt;size();
    if(other_length != this_length) {
        return false;
    }
    for(auto other_it = (object.m_value.m_objectaddress)-&gt;begin(), this_it = (m_value.m_objectaddress)-&gt;begin(); this_it != (m_value.m_objectaddress)-&gt;end();++other_it, ++this_it) {
        if(other_it-&gt;first != this_it-&gt;first) {
            return false;
        }
        if(! ((this_it-&gt;second).compare(other_it-&gt;second))) {
            return false;
        }
    }
    return true;
}</pre>
&nbsp;

又用断言assert(&lt;assert.h&gt;)对std::logic_error()语句进行debug版本的更改。

<img class="alignnone wp-image-485 size-full" src="https://789ak.com/wp-content/uploads/2023/02/Pasted-36.png" />

C++ map是基于红黑树，插入键值对后会自动进行排序。因此将map改为unordered_map(哈希map)来减少排序的时间。

&nbsp;

<a href="https://blog.csdn.net/dbdxnuliba/article/details/90286748?ops_request_misc=&amp;request_id=&amp;biz_id=102&amp;utm_term=%E5%9C%A8%E8%81%94%E5%90%88%E4%BD%93%E5%86%85%E4%BD%BF%E7%94%A8%E6%99%BA%E8%83%BD%E6%8C%87%E9%92%88&amp;utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-1-90286748.142%5Ev73%5Econtrol">智能指针的使用注意事项</a>

&nbsp;