DML英文全称是Data Manipulation Language（数据操作语言），用来对数据库中表的数据记录进行增、删、改操作。

- 添加数据（INSERT）
- 修改数据（UPDATE）
- 删除数据（DELETE）

### 添加数据

- 给指定字段添加数据

```sql
INSERT INTO table_name(col1, col2 ...) 
	VALUES(val1, val2 ...);
```

- 给全部字段添加数据

```sql
INSERT INTO table_name 
	VALUES(val1, val2, ... , val_last);
```

> - 插入数据时，指定的字段顺序需要与值的顺序一一对应
> - 字符串和日期数据应该包含在引导中
> - 插入的数据大小，应该在字段的规定范围内

- 批量添加数据

```sql
INSERT INTO table_name
	VALUES (all_1),
	(all_2),
	...
	;
```

### 修改数据

```sql
UPDATE table_name SET col_1 = val_1, col_2 = val_2, ...
WHERE [condition];
```

> 修改语句的条件可以有，也可以没有，如果没有条件，则会修改整张表的所有数据。

### 删除数据

```sql
DELETE FROM table_name 
WHERE [condition];
```

> - `DELETE`语句的条件可以有，也可以没有，如果没有，则会删除整张表的数据
> - `DELETE`语句不能删除某个字段的值（可以使用`UPDATE`将字段值设置为`NULL`既可

