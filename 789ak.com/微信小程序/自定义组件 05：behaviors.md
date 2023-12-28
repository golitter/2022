behaviors是小程序中，用于实现组件间代码共享的特性，类似于Vue.js中的“mixins”。

#### behaviors的工作方式

每个behavior可以包含一组属性、数据、生命周期函数和方法。组件引用它时，它的属性、数据和方法会被合并到组件中。

每个组件可以引用多个behavior，behavior也可以引用其他behavior。

#### 创建behavior

在根目录创建behaviors目录，在该目录下创建.js文件。

调用Behavior(Object object)方法即可创建一个共享的behavior实例对象，供所有的组件使用：

```js
module.exports = Behavior({
  data:{
    username: "golitter",
  },
  properties: {

  },
  methods: {}
})
```

#### 导入并使用behavior

在组件中，使用require()方法导入需要的behavior，挂载后即可访问behavior中的数据或方法。

```js
const myBehavior = require("../../behaviors/my-bahavior")
```

#### 同名字段的覆盖和组合规则

组件和它引入的behavior中可以包含同名的字段，此时可以参考如下3中同名时的处理规则。

1. 同名的数据字段（data)
2. 同名的属性（properties）或方法（methods）
3. 同名的生命周期函数

