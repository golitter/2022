### 数据绑定

数据绑定的基本原则

- 在data中定义数据
- 在WXML中使用数据

#### 在data中定义数据

类似于Vue的插值语法。在data中定义数据，用{{}}使用定义的数据。

Mustache语法格式：把data中的数据绑定到页面渲染，使用Mustache语法（{{}}双大括号）将变量包起来即可。

![image-20230428232724853](http://cdn.789ak.com/img/image-20230428232724853.png)

#### Mustache语法的应用场景

- 绑定内容
- 绑定属性
- 运算（三元运算、算术运算）

##### 动态绑定

![image-20230428233156105](http://cdn.789ak.com/img/image-20230428233156105.png)

运算

![image-20230428233308119](http://cdn.789ak.com/img/image-20230428233308119.png)

### 事件绑定

事件是**渲染层到逻辑层的通讯方式**。通过事件可以将用户在渲染层产生的行为，反馈到逻辑层进行业务处理。

小程序中常用的事件：

![image-20230428233451553](http://cdn.789ak.com/img/image-20230428233451553.png)

事件对象的属性列表。

当事件回调触发的时候，会收到一个事件对象event，它的详细属性如下：

![image-20230428233614562](http://cdn.789ak.com/img/image-20230428233614562.png)

- target和currentTarget的区别

  target是触发该事件的源头组件，二currentTarget则是当前事件所绑定的组件。

  点击内部，点击事件以冒泡方式扩散。e.target是内部的组件。

### 事件绑定语法格式 - bindtap

通过bindtap等为组件绑定触摸事件。

![image-20230428234014003](http://cdn.789ak.com/img/image-20230428234014003.png)

#### 在事件处理函数中为data中的数据赋值

调用this.setData(dataObject)方法，可以给页面data中数据重新赋值。

![image-20230428234201626](http://cdn.789ak.com/img/image-20230428234201626.png)

#### 事件传参

小程序中的事件传参比较特殊，不能再绑定事件的同时为事件处理函数传递参数。

![image-20230428234357645](http://cdn.789ak.com/img/image-20230428234357645.png)

因为小程序会把bindtap的属性值统一当作事件名称处理，即调用abc(234)函数。

**可以为组件提供data- *的自定义属性传参，其他 *代表的是参数名称。

再函数内，通过e.target.dataset.*来获取传递的参数。

![image-20230428235234704](http://cdn.789ak.com/img/image-20230428235234704.png)

### bindinput

再小程序中，通过input事件来响应文本框的输入事件，语法格式：

```html
<input bindinput="input_func"/>
```

![image-20230429000044815](http://cdn.789ak.com/img/image-20230429000044815.png)

实现文本框和data之间的数据同步

步骤：

- 定义数据
- 渲染结构
- 美化样式
- 绑定input事件处理函数

![image-20230429000741106](http://cdn.789ak.com/img/image-20230429000741106.png)