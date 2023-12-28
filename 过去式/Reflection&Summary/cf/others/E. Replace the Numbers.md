[Problem - E - Codeforces](https://codeforces.com/contest/1620/problem/E)

问题描述：q次操作：

- `1 x`：表示在数组后面添加`x`
- `2 x y`：表示将数组中所有的`x`改为`y`

思路：离线处理，倒叙遍历。`x`和`y`范围是5e5，可以开个数组`f[]`。预处理f，初始化是1到5e5的。之后每经过一次操作二，`f[x] = f[y]`；操作一为：`ans.push_back(f[x])`即可。

代码：

```cpp
void solve() {
    int n; cin>>n;
    vector<int> ans, f(5e5 + 21);
    iota(all(f), 0);
    vector<array<int,3>> ask(n);
    for(auto &t: ask) {
        cin>>t[0];
        if(t[0] == 2) cin>>t[1]>>t[2];
        else cin>>t[1];
    }
    for(int i = n-1; i >= 0; --i) {
        auto ak = ask[i];
        if(ak[0] == 1) ans.push_back(f[ak[1]]);
        else f[ak[1]] = f[ak[2]];
    }
    reverse(all(ans));
    for(auto t: ans) cout<<t<<" ";
}
```

