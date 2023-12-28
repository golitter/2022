#### 基于回调函数的异步API的缺点

默认情况下，小程序官方提供的异步API都是基于回调函数实现的。

API Promise化：指的是通过额外的配置，将官方提供的、基于回调函数的异步API升级改造为基于Promise的异步API，从而提高代码的可读性、维护性，避免回调地狱。

在小程序中，实现API Promise化主要依赖于miniprogram-api-promise这个第三方npm包。

```bash
npm i --save miniprogram-api-promise
```

安装后记得构建npm组件。

```js
import {promisifyAll} from "miniprogram-api-promise"
const wxp = wx.p = {}

promisifyAll(wx, wxp)
```

```js
// 页面.js文件
async get__info() {
    const res = await wx.p.request({
      method: 'GET',
      url: 'https://www.escook.cn/api/get',
      data: {
        name:"golitter",
        age:20
      }
    })
    console.log(res)
  },
```

