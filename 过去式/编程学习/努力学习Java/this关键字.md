java虚拟机会给每个对象分配this，代表当前对象。



```java
class Person {
    String name;
    int age;
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
}
```

简单的说，哪个对象调用，this就代表哪个对象。

this的注意事项和使用细节

1. this关键字可以用来访问本类的属性、方法和构造器
2. this用于区分当前类的属性和局部变量
3. 访问成员方法的语法：this.方法名(参数列表)
4. 访问构造器语法：this(参数列表)；**只能在构造器中使用**
5. this不能在类定义的外部使用，只能在类定义的方法中使用



![image-20230713154556972](https://cdn.789ak.com/img/image-20230713154556972.png)

