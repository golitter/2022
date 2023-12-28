DQL

DQL英文全称是Data Query Language（数据查询语言），数据查询语言，用来查询数据库中表的记录。

查询关键字：`SELECT`

DQL查询语法，语法结构如下：

```sql
SELECT 
	col1, col2 ...
FROM R1, R2 ...
WHERE [condition]
GROUP BY
	group_col1 ...
HAVING 
	[condition after group]
ORDER BY
	order_1 ...
LIMIT
	para
;
```

### 基本查询（不带任何条件）

- 查询多个字段(投影)

```sql
SELECT col1, col2, ... 
FROM table_name;
```

- 查询表的所有字段

```sql
SELECT * FROM table_name;
```

> '*' 代表查询所有字段，在实际开发中尽量少用

- 字段设置别名

```sql
SELECT col1 AS ali_1, col2 AS ali_2 ...
FROM table_name;
/* 或者 */
SELECT col1 ali_1, col2 ali_2 ...
FROM table_name;

```

- 去除重复记录

```sql
SELECT DISTINCT col1, col2 ...
FROM table_name;
```

- select表达式

```sql
SELECT col(type:math) * 3 AS ali_name;
```



### 条件查询

```sql
SELECT col_1 ... 
FROM table_name ...
WHERE [condition];
```

> ##### 阅读和书写查询语句的小技巧
>
> ​	检查一个`SELECT - FROM - WHERE`查询的最简单的方式是，首先查看`FROM`子句，找出该查询涉及了哪些关系（表）。接着查看`WHERE`子句，了解要找出的是什么样的元组（行），它对查询很重要。最后再看`SELECT`子句了解输出结果是哪些。同样地，在写查询语句的时候也要遵循同样的顺序，即先`FROM`再`WHERE`最后`SELECT`。这样做对理解语句非常有用。
>
> ​	---- 数据库系统基础教程中文第三版 p.144

#### 条件

| 比较运算符                   | 功能                                             |
| ---------------------------- | ------------------------------------------------ |
| \>, < , >= , <= , = , **<>** | 大于 小于 大于等于 小于等于 等于 不等于          |
| BETWEEN ... AND ...          | 在某个范围内（含最小值和最大值，即边界）         |
| IN( ... )                    | 在`IN`之后的列表中的值，多选一                   |
| LIKE p                       | 模糊匹配（'-' 匹配单个字符，'%' 匹配任意个字符） |
| IS NULL                      | 是`NULL`                                         |

> 注意 sql中等号为’=‘，不等号为’<>‘。不要跟编程语言的等号'=='，不等号'!='搞乱。



#### 常用的逻辑运算符

| 逻辑运算符 | 功能         |
| ---------- | ------------ |
| AND        | 完全真，并且 |
| OR         | 完全假，或者 |
| NOT        | 非           |

#### 空值和涉及空值的比较

sql允许属性有一个特殊值`NULL`，称作空值(null value)。对于空值有许多不同的解释。

1. 未知值(value unknown)。即知道它有一个值但不知道是什么。
2. 不适用的值(value inapplicable)：”任何值在这里都是没有意义的。
3. 保留的值(value withheld)：“属于某对象但无权知道的值”

在`WHERE`子句中，要考虑元组中的空值可能带来的影响。当对空值进行运算时有两个重要的规则要记住。

- 对NULL和任何值（包括另一个NULL值）进行算术运算，其结果仍然是空值。
- 当使用比较运算符，比较NULL和任意值（包括另一个NULL值）时，结果都为UNKNOWN。

#### 布尔值UNKNOWN

UNKNOWN是另外一个与TRUE和FALSE相同的布尔值。由于NULL的出现，比较结果可能产生第三个布尔值UNKNOWN。

可以用一种简单的方式来记住这个规则。把TRUE看作1（完全真），FALSE看作0（完全假），UNKNOWN看作1/2（即处于真假之间）。

>##### 使用空值的小缺陷
>
>NULL值在sql中通常表示”一个未知的但是的确存在的值“。然而这样表示有时和人们的直觉不符合。例如，x是某个元组的一字段，该字段的域类型是整型。因此可以推断无论整数x的值是什么，0*x的结果都是0.但如果x的值是NULL，0*x则为NULL。同样的x - x 也是如此。

#### 聚合函数

将一列数据作为一个整体，进行纵向计算。

常见的聚合函数

| 函数  | 功能     |
| ----- | -------- |
| count | 统计数量 |
| max   | 最大值   |
| min   | 最小值   |
| avg   | 平均值   |
| sum   | 求和     |

```sql
SELECT AGGR_FUNC FROM table_name;
```

> **NULL值不参与所有聚合函数运算的。**

#### 分组查询

语法：

```sql
SELECT col ... 
FROM ...
[WHERE cond]
GROUP BY col ..
[HAVING cond];
```

> `WHERE`和`HAVING`的区别
>
> - 执行时机不同：`WHERE`是分组之前进行过滤，不满足`WHERE`条件，不参与分组；而`HAVING`是分组之后对结果进行过滤。
> - 判断条件不同：`WHERE`不能对聚合函数进行判断，而`HAVING`可以。

**注意事项**

- 分组之后，查询的字段一般为聚合函数和分组字段，查询其他字段没有意义。
- 执行顺序： `WHERE`  > 聚合函数 > `HAVING`
- 支持多字段分组，具体语法为： `GROUP BY col1, col2 ... `

#### 排序查询

语法：

```sql
SELECT col ...
FROM ...
ORDER BY col sort_type, col [ASC] ;
```

排序方式（从表头到表尾）：

- `ASC`：升序（默认）
- `DESC`：降序

#### 分页查询

分页操作在业务系统开发时，也是非常常见的一个功能，我们在网站中看到的各种各样的分页条，后台 都需要借助于数据库的分页操作。

语法：

```sql
SELECT col ...
FROM ...
LIMIT st_, query_cnt;
```

>注意事项：
>
>- 起始索引从0开始，骑士索引 = （查询页码 - 1）*每页显示记录数。
>- 分页查询是数据库的方言，不同的数据库有不同的实现，MySQL中是`LIMIT`。
>- 如果查询的第一页数据，起始索引可以省略，直接简写为`LIMIT 10`。

