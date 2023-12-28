[Problem - 1862C - Codeforces](https://codeforces.com/problemset/problem/1862/C)

[Flower City Fence - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/CF1862C)

思路：

关于`y = x`对称的话，每一列翻下来也是原来的形状。

代码：

```cpp
int a[N], dif[N];
void solve() {
    int n; cin>>n;
    int ma = -INF;
    rep(i,1,n) cin>>a[i], ma = max(ma, a[i]), dif[i] = 0;
    if(ma > n) {
        puts("NO");
        return ;
    }
    rep(i,1,n) dif[1]++, dif[a[i] + 1]--;
    rep(i,1,n) {
        dif[i] += dif[i-1];
        if(dif[i] != a[i]) {
            puts("NO");
            return ;
        }
    }
    puts("YES");
}
```

