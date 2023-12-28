WXS(WeXin Script)是小程序独有的一套脚本语言，结合WXML可以构建出页面的结构。

wxs的应用场景：wxml中无法调用在页面的.js中定义的函数，但是，wxml中可以调用wxs中定义的函数。因此，小程序中wxs的典型应用场景就是“过滤器”。

wxs和js的关系：

虽然wxs的语法类似于js，但是wxs和js是**完全不同的两种语言**。

- wxs有自己的数据类型
- wxs不支持类似于es6及以上的语法形式
- wxs遵循CommonJS规范

### 内嵌wxs脚本

wxs代码可以编写在wxml文件中<wxs\>标签内，就像js代码可以编写在html文件中的<script\>标签内一样。

wxml文件中的每一个<wxs\></wxs\>标签，**必须提供module属性**，用来指定当前wxs的模块名称，方便再wxml中访问模块中的成员。

```js
<view>{{m1.toUpper(username)}}</view>

<wxs module="m1">
	// 将文本转为大写形式 golitter -> GOLITTER
	module.exports.toUpper = function(str) {
	return str.toUpperCase()
	}
</wxs>
```

### 外联wxs脚本

wxs代码还可以编写在以.wxs为后缀的文件内，就像js代码可以编写在以.js为后缀名的文件中一样。

```js
// .wxs
function toLower(str) {
	return str.toLowerCase()
}
module.exports = {
	toLower: toLower
}
```

在wxml中引入外联的wxs脚本时，必须为<wxs\>标签添加module和src属性。

- module用来指定模块的名称
- src用来指定要引入的脚本的路径，且必须是相对路径

```
<view> {{m2.toLower(str)}}</view>

<!-- 引入外联wxs -->
<wxs src="../../utils/tools.wxs" module="m2"></wxs>
```

### wxs的特点

- 与js不同

  为了降低wxs的学习成本，wxs语言在设计时借鉴了大量js语法。但是，本质上wxs和js是完全不同的两种语法。

- 不能作为组件的事件回调

  wxs典型的应用场景就是“过滤器”，经常配合Mustache语法进行使用。但是，在wxs中定义的函数不能作为组件的事件回调函数。

- 隔离性

  隔离性指的是wxs的运行环境和其他js代码是隔离的。

  - wxs不能调用js中定义的函数
  - wxs不能调用小程序提供的API

- 性能好

