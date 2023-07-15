```java
public class lab {
    
    public static void main(String[] args) {
        System.out.println("Hello World");
    } 
}
```

这是一个lab.java内的文件内容。

运行后会出现“Hello World”。

将lab.java转为lab.class

```
javac lab.java 
```

运行类

```
java lab
```

如果加上注释可能会报错

```java
// public class lab 表示 lab是一个public的类
// lab { } 表示一个类的开始和结束
// public static void main(String[] args) 表示一个主方法，即我们程序的入口
// main {} 表示方法的开始和结束
// sout -- 输出
// 分号 ; 表示语句结束
public class lab {
    
    public static void main(String[] args) {
        System.out.println("Hello World");
    } 
}
```

这是因为编码出错了

![image-20230706143520077](https://cdn.789ak.com/img/image-20230706143520077.png)

换成gb2312即可。

![image-20230706143602834](https://cdn.789ak.com/img/image-20230706143602834.png)

总结：

有了可执行的java程序（lab.class字节码文件）。通过运行工具java.exe对字节码文件进行执行，本质就是.class装载到JVM机执行。

当.java文件修改，需要重新进行编译。

### Java开发注意事项和细节说明：

1. java源文件以.java为扩展名。源文件的基本组成部分是类（class），如本类中的lab类。

2. java应用程序的执行入口是main()方法。它有固定的书写格式：

   ```java
   public static void main(String[] args) {...}
   ```

3. java语言严格区分大小写。

4. java方法由一条条语句构成，每个语句以";"结束。

5. 大括号都是成对出现的。缺一不可。

6. 一个源文件中最多只能有一个public类，其他类的个数不限。

7. 如果源文件包含一个public类，则文件名必须按该类名命名。

8. 一个源文件中最多只能有一个public类。其他类的个数不限，也可以将main方法写在非public类中，然后指定运行非public类，这样入口方法就是非public的main方法。

### Java代码规范

1. 类、方法的注释，要以javadoc的方式来写
2. 非javadoc的注释，往往是给代码的维护者看的，着重告诉读者为什么这样写，如何修改，注意说明问题等
3. 使用tab操作，实现缩进，默认整体向右边移动，用shift + tab 整体向左移
4. 运算符和 = 两边习惯性各加一个空格
5. 源代码要使用utf-编码
6. 行宽不要超过80字符
7. 代码编写次行和行尾风格。