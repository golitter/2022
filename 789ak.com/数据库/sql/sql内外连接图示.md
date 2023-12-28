student表数据：

| id   | name     |
| ---- | -------- |
| 34   | name     |
| 22   | golitter |
| 66   | kerwin   |
| 123  | yh       |
| 12   | golemon  |

score表数据：

| id   | score |
| ---- | ----- |
| 34   | 80    |
| 22   | 98    |
| 66   | 33    |
| 45   | 100   |

## 内连接
1、[内连接](https://so.csdn.net/so/search?q=内连接&spm=1001.2101.3001.7020):俗称左右拼接连接；
2、内连接特点：满足连接条件的才会出现在结果里面；

```sql
SELECT 查询字段 FROM 表1 [INNER] JOIN 表2 ON 表1.关系字段=表2.关系字段；（等值连接）

SELECT 查询字段 FROM 表1 [INNER]  JOIN 表2 ON 表1.关系字段=表2.关系字段；

-- 也可写成where条件形式：
SELECT 查询字段 FROM 表1,表2  WHERE  表1.关系字段=表2.关系字段；
```

>注意点：
>（1）内连接的表必须是要有关系的表（即具有相同意义字段的表）
>（2）当查询的字段同时出现在连接的表当中，必须明确说明是那个表里的字段，不然会出现错误；

```sql
SELECT * FROM student INNER JOIN score;
```

![image-20230625171649310](http://cdn.789ak.com/img/image-20230625171649310.png)

```sql
SELECT * FROM student, score;
```

![image-20230625171839101](http://cdn.789ak.com/img/image-20230625171839101.png)

## 外连接

外连接分为三种：左外连接，右外连接，全外连接。对应SQL：LEFT/RIGHT/FULL OUTER JOIN。

- 左连接

```sql
SELECT * FROM student LEFT OUTER JOIN score
ON student.id = score.id;
```

![image-20230625173621246](http://cdn.789ak.com/img/image-20230625173621246.png)



- 右连接

```sql
SELECT * FROM student RIGHT OUTER JOIN score
ON student.id = score.id;
```

![image-20230625172729708](http://cdn.789ak.com/img/image-20230625172729708.png)

- 全连接

```sql
SELECT * FROM student FULL OUTER JOIN score
ON student.id = score.id;
```

Mysql 不支持`FULL OUTER JOIN`这个操作，可以用`UNION`来实现全连接操作。

![image-20230625173248971](http://cdn.789ak.com/img/image-20230625173248971.png)



图示更加清晰地感觉是[SQL语法——内连接、外连接（左外连接、右外连接、全外链接） - 墨天轮 (modb.pro)](https://www.modb.pro/db/509240)这篇文章。

![image-20230625173930751](http://cdn.789ak.com/img/image-20230625173930751.png)

![image-20230625174014597](http://cdn.789ak.com/img/image-20230625174014597.png)

![image-20230625174044816](http://cdn.789ak.com/img/image-20230625174044816.png)



[SQL连接的理解和使用（内连接：自然连接&等值连接，外连接：左连接&右连接&全外连接）_sql自然连接_海蒂°的博客-CSDN博客](https://blog.csdn.net/qq_41592346/article/details/129874625?ops_request_misc=%7B%22request%5Fid%22%3A%22168768748416800222860944%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=168768748416800222860944&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-129874625-null-null.142^v88^control_2,239^v2^insert_chatgpt&utm_term=sql中的自然连接&spm=1018.2226.3001.4187)

[查询数据 - 廖雪峰的官方网站 (liaoxuefeng.com)](https://www.liaoxuefeng.com/wiki/1177760294764384/1179610544539040)

[SQL语法——内连接、外连接（左外连接、右外连接、全外链接） - 墨天轮 (modb.pro)](https://www.modb.pro/db/509240)

[(1条消息) SQL的内外连接方式_sql内连接_just Liu的博客-CSDN博客](https://blog.csdn.net/weixin_43657184/article/details/126036585)