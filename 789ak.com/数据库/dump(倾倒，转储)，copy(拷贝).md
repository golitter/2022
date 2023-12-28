>

dump(倾倒，转储)，copy(拷贝)
<pre class="code">    # 数据库 
# 将databaseName转储到 "path/name"路径下
 :$ pg_dump databaseName &gt; "path/name"

 # 将 "path/name" 的.sql文件转储到databaseName内
 :$ pg_dump databaseName &lt; "path/name"

 # 将"path/name"的.sql文件存入postgresql
 :$ psql -f path/name

     # 表
 #将tableName导出到 "path/name"：
 =# COPY tableName to 'path/name' WITH CSV HEADER ;

 # 将 "path/name"的文件导入到tableName内：
 =# COPY tableName from 'path/name' ;</pre>
CSV (comma separated values) ：是一种文件类型，可以用电子表格软件打开。

<img class="alignnone wp-image-353 size-full" src="https://789ak.com/wp-content/uploads/2023/02/Pasted-6.png" />

&nbsp;

<a href="https://www.lanqiao.cn/courses/2782">oeasy 教您玩转 SQL (PostgreSQL 数据库)_PostgreSQL - 蓝桥云课 (lanqiao.cn)</a>

&nbsp;