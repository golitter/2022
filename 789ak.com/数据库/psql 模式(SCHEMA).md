<blockquote>模式是数据库领域的一个基本概念，有些数据库把模式和用户合二为一了，而postgresql则是有清晰的模式定义。

模式是数据库中的一个概念，可以理解为一个命名空间或目录，不同模式下可以有相同名称的表、函数等对象而不会产生冲突。提出模式的概念是为了方便管理，只要有权限，各个模式的对象都可以互相调用。

在postgresql中，一个数据库包含一个或多个模式，模式内又包含表、函数等内容。不同数据库表示不一样。</blockquote>
模式优点：

<ul>
 	<li>允许多个用户使用一个数据库而不会彼此干扰。</li>
 	<li>把数据库对象组织成逻辑组，让它们更便于管理。</li>
 	<li>第三方的应用可以放在不同的模式中，这样它们就不会和其它对象的名字冲突。</li>
</ul>
语法：
<pre class="EnlighterJSRAW" data-enlighter-language="postgresql" data-enlighter-theme="atomic">--- 创建模式
CREATE SCHEMA schemaname [ AUTHORIZATION username ... ] ;
--- 查看已有模式
    \dn
--- 删除模式
DROP SCHEMA schemaname;
</pre>
模式搜索路径
<blockquote>全称的名字写起来非常费劲，并且我们最好不要在应用里直接写上特定的模式名。因此，表通常都是用未修饰的名字引用的，这样的名字里只有表名字。系统通过查找一个搜索路径来判断一个表究竟是哪个表，这个路径是一个需要查找的模式列表。 在搜索路径里找到的第一个表将被当作选定的表。如果在搜索路径中没有匹配表，那么就报告一个错误，即使匹配表的名字在数据库其它的模式中存在也如此。

在搜索路径中的第一个模式叫做当前模式。除了是搜索的第一个模式之外， 它还是在 CREATE TABLE 没有声明模式名的时候，新建表所在的地方。</blockquote>
语法：
<pre class="EnlighterJSRAW" data-enlighter-language="postgresql" data-enlighter-theme="atomic">SHOW search_path;</pre>
修改默认模式：
<pre class="EnlighterJSRAW" data-enlighter-language="postgresql" data-enlighter-theme="atomic">SET search_path TO selfschema ,public;</pre>
模式的权限：

默认情况下，用户无法访问模式中不属于他们的对象。如果要访问，就要为模式赋予 "USAGE" 权限。
<pre class="EnlighterJSRAW" data-enlighter-language="postgresql" data-enlighter-theme="atomic">REVOKE CREATE ON SCHEMA schemaname FROM PUBLIC；
--- schemaname是模式名，PUBLIC是所有用户的意思。</pre>
模式的可移植性：
<blockquote>SQL标准中，同一个模式下的对象是不能被不同的用户拥有的，同时也没有public模式的概念。有些数据库也没有模式的概念。</blockquote>
<a href="https://blog.csdn.net/hmxz2nn/article/details/82715192?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167662430316782425147057%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&amp;request_id=167662430316782425147057&amp;biz_id=0&amp;utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-82715192-null-null.142^v73^control,201^v4^add_ask,239^v2^insert_chatgpt&amp;utm_term=psql%20%E6%A8%A1%E5%BC%8F&amp;spm=1018.2226.3001.4187">PostgreSQL 模式介绍</a>

