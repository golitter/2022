[Problem - 1646C - Codeforces](https://codeforces.com/problemset/problem/1646/C)

我们称一个数 �*m* 是好数，当且仅当 �*m* 为形如 �!*d*! 或者 2�2*d* 的数。现在给定一个整数 �*n*，请求出最小的整数 �*k*，使得 �*n* 可以表示成 �*k* 个**互不相同**的好数的和。

数据范围：

- �*t* 组数据，1⩽�⩽1001⩽*t*⩽100。
- 1⩽�⩽10121⩽*n*⩽1012。



思路：预处理出1到14阶乘，跑组合数，注意剪枝即可。

```cpp
__builtin_popcount(x); // 返回x值有多少个1。
```

```cpp
void solve() {
    LL n; cin>>n;
    auto get_fact = [&](auto&&self, LL val) -> LL {
        if(val == 1) return 1;
        else return val * self(self,val-1);
    };
    int ans = __builtin_popcountll(n);
    vector<LL> fact(24);
    for(int i = 1; i <= 14; ++i) fact[i] = get_fact(get_fact, i);
    auto dfs = [&](auto &&self, int stp, int cnt, LL val) -> void {
        if(stp > 14) {
            int tmp = cnt + __builtin_popcountll(val);
            ans = min(ans, tmp);
            return ;
        }
        if(val - fact[stp] >= 0 && cnt + 1 < ans) self(self,stp+1, cnt+1, val - fact[stp]);
        self(self, stp + 1, cnt, val);
    };
    dfs(dfs,1,0,n);
    cout<<ans<<endl;
}
```

