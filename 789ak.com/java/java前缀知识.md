## Java技术体系平台

- SE（Standard Edition）标准版

支持面向桌面级应用（如Windows下的应用程序）的Java平台。提供了完整的Java核心API，此版本以前称为J2SE。

- EE（Enterprise Edition）企业版

是为开发企业环境下的应用程序提供的一套解决方案。该技术体系中包含的技术如：Servlet、Jsp等，主要针对于Web应用程序开发。版本以前称为J2EE。

- ME（Micro Edition）小型版

支持Java程序运行在移动终端（手机，PDA）上的平台，对Java API有所精简，并加入了针对移动终端的支持，此版本以前称为J2ME。

## Java重要特点

1. Java语言是面向对象的（oop）
2. Java语言是健壮的。Java的强类型机制、异常处理、垃圾的自动收集等是Java程序健壮性的重要保证。
3. Java语言是跨平台性的。
4. Java语言是解释型的。

> 解释型语言：JavaScript，PHP，java
>
> 编译型语言：C/C++
>
> 区别是：解释型语言，编译后的代码不能直接被机器执行，需要解释器来执行，编译型语言编译后的代码可以直接被机器执行。

## Java运行机制及运行过程

Java核心机制 - Java虚拟机[ JVM - java virtual machine]

JVM是一个虚拟的计算机，具有指令集并使用不同的存储区域。负责执行指令，管理数据、内存、寄存器，包含在JDK中。

对于不同的平台，有不同的虚拟机。

Java虚拟机机制屏蔽了底层运行平台的差别，实现了“一次编译，到处运行”。

### JDK

JDK的全称（Java Development Kit，Java开发工具包）

JDK = JRE + Java的开发工具

JDK是提供给Java开发人员使用的，其中包含了Java的开发工具，也包括了JRE。所以安装了JDK，就不用安装JRE。

### JRE

JRE（Java Runtime Environment，Java运行环境）

JRE= JVM + Java的核心类库。

包括Java虚拟机（JVM Java Virtual Machine）和Java程序所需的核心类库等，如果想要运行一个开发好的Java程序，计算机中只需要安装JRE即可。

## JDK、JRE和JVM的关系

JDK = JRE + 开发工具集（例如Javac，java编辑工具等）

JRE = JVM + Java SE标准类库（java核心类库）

JDK = JVM + Java SE标准类库 + 开发工具集

如果只想要运行开发好的.class文件，只需要JRE即可。

