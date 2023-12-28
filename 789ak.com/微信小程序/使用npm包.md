### 小程序对npm的支持与限制

目前，小程序中已经支持使用npm安装第三方包，从而来提高小程序的开发效率。但是在小程序中使用npm包有如下三个限制：

1. 不支持依赖于Node.js内置库的包
2. 不支持依赖于浏览器内置对象的包
3. 不支持依赖于C++插件的包

> 能供小程序使用的包不多。

#### 什么是Vant Weapp

Vant Weapp是一个开源的一套小程序UI组件库，助力开发者快速搭建小程序应用。[介绍 - Vant Weapp (youzan.github.io)](https://youzan.github.io/vant-weapp/#/home)

安装Vant组件

在小程序项目中，安装Vant组件库主要分为如下3步：

1. 通过npm安装
2. 构建npm包
3. 修改app.json

在[快速上手 - Vant Weapp (youzan.github.io)](https://youzan.github.io/vant-weapp/#/quickstart)处有详细介绍。

> 关于构建npm包。虽然直接下载后，不删除“miniprogram_npm”目录直接进行构建在“miniprogram_npm"中也会有内容，但是运行好像不行。还是建议删除"miniprogram_npm"，再进行构建npm。

修改app.json文件

```json
"usingComponents": {
    "my-test1":"/components/test1/test",
    "van-button":"@vant/weapp/button/index"
  }
```

#### 定制全局主题样式

[使用 CSS 自定义属性（变量） - CSS：层叠样式表 | MDN (mozilla.org)](https://developer.mozilla.org/zh-CN/docs/Web/CSS/Using_CSS_custom_properties)