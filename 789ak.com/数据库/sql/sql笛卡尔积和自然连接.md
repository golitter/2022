### SQL中的[笛卡尔积](https://baike.baidu.com/item/%E7%AC%9B%E5%8D%A1%E5%B0%94%E4%B9%98%E7%A7%AF/6323173?fromtitle=%E7%AC%9B%E5%8D%A1%E5%B0%94%E7%A7%AF&fromid=1434391&fr=aladdin)

即`AxB`。可以简单理解为两个集合的乘积。

SQL语法

```sql
SELECT * FROM tb1 CROSS JOIN tb2;
-- 等价于
SELECT * FROM tb1, tb2;
-- 等价于
SELECT * FROM tb1 INNER JOIN tb2; -- 这是内连接
```

> `**CROSS JOIN`不能加`ON`。**

从行和列两个维度来观察上例笛卡尔积的结果集可以发现: 

- 结果集的行是表1的行数乘表2的行数（2x3） 

- 结果集的列是表1的列加表2的列（3+4）



SQL中的笛卡尔积可以与SQL内连接相互转化。笛卡尔积加查询条件等价于内连接查询。

```sql
SELECT * FROM tb1, tb2
WHERE tb1.id = tb2.id;
-- 等价于
SELECT * FROM tb1 INNER JOIN tb2;
```



> - 从结果上来看：内连接不加关联条件的结果就是笛卡尔
> - 从执行效率和底层实现来看，内连接和笛卡尔积有区别，内连接会先通过on条件过滤两张表的数据，再取交集；笛卡尔积会先将两个表取乘积再过滤数据，所以理论上内连接效率更高
> - 笛卡尔积在表数据量大的情况下查询结果会倍增，实际应用中要加查询条件过滤数据
> - 怎么理解笛卡尔积中的查询条件，可以将笛卡尔积sql转化成内连接sql去理解



### SQL中的自然连接

特殊的等值连接，要求多个表有相同的属性字段，条件为相同的属性字段值相等，且再将表中重复的属性字段去掉，称为自然连接。

```sql
SELECT * FROM tb1 NATURAL tb2;
```



![image-20230625180624351](http://cdn.789ak.com/img/image-20230625180624351.png)



[(1条消息) SQL 中的笛卡尔积_笛卡尔积sql_deelless的博客-CSDN博客](https://blog.csdn.net/weixin_43078114/article/details/128131481)

[SQL连接的理解和使用（内连接：自然连接&等值连接，外连接：左连接&右连接&全外连接）_sql自然连接_海蒂°的博客-CSDN博客](https://blog.csdn.net/qq_41592346/article/details/129874625?ops_request_misc=%7B%22request%5Fid%22%3A%22168768748416800222860944%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=168768748416800222860944&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-129874625-null-null.142^v88^control_2,239^v2^insert_chatgpt&utm_term=sql中的自然连接&spm=1018.2226.3001.4187)