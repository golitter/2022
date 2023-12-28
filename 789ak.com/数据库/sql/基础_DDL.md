## DDL

数据定义语言(Data Definition Language)，用来定义数据库对象（数据库，表，字段）。

### 数据库操作

- 查询所有数据库

```sql
SHOW DATABASES;
```

- 查询当前数据库

```sql
SHOW database();
```

- 创建数据库

```sql
CREATE DATABASE (IF NOT EXISTS) database_name [DEFAULT CHARSET charset] [COLLATE sort_rule];
```

- 删除数据库

```sql
DROP DATABASE [IF EXISTS] database_name;
```

- 切换数据库

```sql
USE database_name;
```

### 表操作 - 查询操作

- 查询当前数据库所有表

```sql
SHOW TABLES;
```

- 查看指定表结构

```sql
DESC table_name;
```

- 查询指定表的建表语句

```sql
SHOW CREATE TABLE table_name;
```

- 创建表结构

```sql
CREATE TABLE table_name (
	var1_name type comment 'com1',
	var2_name type comment 'com2'
	) comment 'com_table_1';
```

### sql的数据类型

| 类型                       | 说明                                                         |
| -------------------------- | ------------------------------------------------------------ |
| CHAR(size)                 | 用于表示固定长度的字符串，该字符串可以包含数字、字母和特殊字符。size 的大小可以是从 0 到 255 个字符，默认值为 1。 |
| VARCHAR(size)              | 用于表示可变长度的字符串，该字符串可以包含数字、字母和特殊字符。size 的大小可以是从 0 到 65535 个字符。 |
| TINYTEXT                   | 表示一个最大长度为 255（28-1）的字符串文本。                 |
| TEXT(size)                 | 表示一个最大长度为 65,535（216-1）的字符串文本，也即 64KB。  |
| MEDIUMTEXT                 | 表示一个最大长度为 16,777,215（224-1）的字符串文本，也即 16MB。 |
| LONGTEXT                   | 表示一个最大长度为 4,294,967,295（232-1）的字符串文本，也即 4GB。 |
| ENUM(val1, val2, val3,...) | 字符串枚举类型，最多可以包含 65,535 个枚举值。插入的数据必须位于列表中，并且只能命中其中一个值；如果不在，将插入一个空值。 |
| SET( val1,val2,val3,....)  | 字符串集合类型，最多可以列出 64 个值。插入的数据可以命中其中的一个或者多个值，如果没有命中，将插入一个空值。 |





### 表操作 - 修改

- 添加字段

```sql
ALTER TABLE table_name ADD col_name type [COMMENT 'comment'] [rule];
```

- 修改数据类型

```sql
ALTER TABLE table_name MODIFY col_name type [Com];
```

- 修改字段名和字段类型

```sql
ALTER TABLE table_name old_name new_name type [Com];
```

- 删除字段

```sql
ALTER TABLE table_name DROP col_name;
```

- 修改表名

```sql
ALTER TABLE table_name RENAME TO new_table_name;
```

### 表操作 - 删除

- 删除表

```sql
DROP TABLE [IF EXISTS ] table_name;
```

- 删除指定表，并重新创建表(删除表内数据)

```sql
TRUNCATE TABLE table_name;
```



数据库系统基础教程

[SQL教程 - 廖雪峰的官方网站 (liaoxuefeng.com)](https://www.liaoxuefeng.com/wiki/1177760294764384)

[(1条消息) 【SQL】之数据类型_sql 数据类型_MojitO_o的博客-CSDN博客](https://blog.csdn.net/weixin_44016186/article/details/124312947)

[SQL数据类型汇总 (biancheng.net)](http://c.biancheng.net/sql/data-types.html)

[SQL 数据类型 (w3school.com.cn)](https://www.w3school.com.cn/sql/sql_datatypes.asp)

