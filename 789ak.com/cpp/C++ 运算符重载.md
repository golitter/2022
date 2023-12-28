操作者是C ++的关键字，它和运算符一起使用，表示一个运算符函数，理解时应将运算符=整体上视为一个函数名。
<blockquote>运算符重载，就是对已有运算符进行重新定义，以适应不同的数据类型。

运算符的目的是让语法更加简洁。

不能改变本来意思。

本质是一种函数调用，函数同一的名字叫operator。

可以写成全局或成员函数。全局双目运算符左面是第一个参数，右边是第二个参数。成员双目运算符左边是this，右边是第一个参数。

<span style="color: #ff0000;">除了赋值号(=)，其他运算符重载都可以被派生类继承。</span></blockquote>
对于++ --来说用占位符可以区分前置和后置递增、递减。
<pre class="EnlighterJSRAW" data-enlighter-language="cpp" data-enlighter-theme="monokai">A&amp; operator++() {
    this-&gt;a++;
    this-&gt;b++;
    return *this;
}
A operator++(int) { // int 占位参数 可以区分前置和后置递增
// 返回是值，不是引用
    A tmp = *this;
    ++(*this);
    return tmp;
}</pre>
C++ 默认赋值函数是值复制，可能导致堆内异常。
<pre class="EnlighterJSRAW" data-enlighter-language="cpp" data-enlighter-theme="monokai">A&amp; operator= (A&amp; T) {
    // 先清除，再赋值，防止堆区内存重复释放
}</pre>
() 函数对象(仿函数)：定义了调用操作符() 的类对象。当用该对象调用此操作符时，其表现形式如同普通函数调用一般。因此取名叫函数对象，它是一个类，不是一个函数。它的使用很灵活，常跟stl结合。

<strong>常规建议：</strong>
<ul>
 	<li>所有一元运算符  --  成员函数</li>
 	<li>= () [] -&gt; -&gt;*   --  必须是成员函数</li>
 	<li>+= -= /= *= ^= &amp;= != %= &gt;&gt;= &lt;&lt;=  --  成员函数</li>
 	<li>其他二元运算符  --  非成员</li>
</ul>
&nbsp;

<a href="https://www.bilibili.com/video/BV1FU4y187rD/?p=362&amp;spm_id_from=333.337.top_right_bar_window_history.content.click&amp;vd_source=13dfbe5ed2deada83969fafa995ccff6">09-右移运算符重载_哔哩哔哩_bilibili</a>

&nbsp;

