用`Connection`获得了数据库连接对象后，可以用`Statement`类型进行数据库操作。

在`Statement`对象中，有三种，分别是`Statement`，`PrepareStatement`，`CallableStatement`。

这三个的区别在于：

- `Statement`
  - 用于执行不带参数的简单`SQL`语句
- `PreparedStatement`
  - 用于执行带或者不带参数的`SQL`语句
  - `SQL`语句会预编译在数据库系统
  - 执行速度快于`Statement`对象
- `CallableStatement`
  - 用于执行数据库存储过程的调用

## `Statement`

`Statement`用于执行静态的`SQL`语句。通过`con.createStatement()`创建一个`Statement`对象之后，调用`executeQuery(sql)`函数进行`SQL`操作。

`executeQuery`函数原型：

```java
public ResultSet executeQuery(String sql) throws SQLException
```

这个方法接受一个 SQL 查询字符串作为参数，并返回一个 `ResultSet` 对象，该对象包含查询结果。如果查询失败，则抛出 `SQLException` 异常。

> 当使用`Statement`或`PreparedStatement`对象执行查询语句时，会返回一个`ResultSet`对象，它包含了查询结果的数据。通过`ResultSet`对象，可以遍历结果集的行，并获取每一行中的列数据。
>
> ResultSet对象维护一个指向其当前数据行的游标，并提供了多种常用的方法来访问数据。
>
> 1. **next()**：将光标移动到下一行。当ResultSet对象中没有更多行时，它返回false，因此可以在while循环中使用它进行迭代。
> 2. **getString(columnName)**：根据列名获取整行的字符串。
> 3. **getString(int columnIndex)**：根据列的索引位置获取整行的字符串。
> 4. **getInt(columnName)**：根据列名获取整行的int值。
> 5. **getInt(int columnIndex)**：根据列的索引位置获取整行的int值。
> 6. **close()**：关闭ResultSet对象，释放资源。
>
> 这些方法可以根据需要选择使用，以高效地访问和处理查询结果。

在数据库中模糊查找`airports`表中符合`name`的`Name`，并逐个打印出来。

```java
    public static void findAirportByName(String name) {
        try {
            Statement stat = con.createStatement();
            System.out.println(name);
            ResultSet res = stat.executeQuery("SELECT * FROM airports WHERE Name LIKE '%" + name + "%'");

            while(res.next()) {
                System.out.println(
                        "id: " + res.getInt(1) + " Name: " + res.getString(2) + " Address: " + res.getString(3) +
                                " Type: " + res.getString(4) + " Phone: " + res.getString(5) + " Level: " + res.getString(6)
                );
            }
        } catch (SQLException ex) {

        }
    }
```

![image-20231221222213560](JDBC%E6%95%B0%E6%8D%AE%E5%BA%93%E6%93%8D%E4%BD%9C.assets/image-20231221222213560.png)

## `PrepareStatement`

`PrepareStatement`是预编译的`Statement`对象。在`prepareStatement`方法中使用占位符(`?`)来代替具体的参数值，然后使用`set`方法设置参数的值。最后调用`execute`方法进行执行。

> 预编译是指在执行SQL语句之前，将SQL语句发送到数据库进行预处理，以提高执行效率和安全性。

`set`方法的函数原型：

```java
void setXXX(parameterIndex idx, x val); // XXX 为Int String 等
```

**其中`parameterIndex idx`中的下标从1开始。**

`execute`方法的返回值为布尔值，成功执行返回`true`；否则，返回`false`。

向数据库中插入一条机场信息。

```java
    public static void addNewAirPort() {
        try
        {
            ps=con.prepareStatement("insert into airports (Id, Name, Address, Type, Phone, Level) values (?, ?, ?, ?, ?, ?)");
            ps.setInt(1, 42);
            ps.setString(2, "abcdef");
            ps.setString(3, "Shanghai");
            ps.setString(4, "BBB");
            ps.setString(5, "1232323");
            ps.setString(6, "Sk");

            ps.execute();

        }
        catch(SQLException ex)//捕捉并处理SQL异常(创建数据库连接对象的时候或者执行SQL语句的时候)
        {
            System.out.println(ex.toString());
        }
    }
```

![image-20231221223209651](JDBC%E6%95%B0%E6%8D%AE%E5%BA%93%E6%93%8D%E4%BD%9C.assets/image-20231221223209651.png)



[【JDBC】Java连接MySQL数据库-CSDN博客](https://blog.csdn.net/qq_61635026/article/details/131637051?ops_request_misc=&request_id=&biz_id=102&utm_term=jdbc mysql&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-7-131637051.142^v96^pc_search_result_base3&spm=1018.2226.3001.4187)