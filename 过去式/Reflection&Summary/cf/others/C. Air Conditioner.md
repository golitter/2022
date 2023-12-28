[Problem - C - Codeforces](https://codeforces.com/contest/1304/problem/C)

判断是否有交集，之后更新集合区间。

对于两个集合`[l1, r1]`和`[l2, r2]`，如果无交集，那么一定是这种情况，一个集合的左边界大于另一个集合的右边界，且右边界小于另一个集合的左边界。

这样判断集合是否成交集，题就做完了。

```cpp
void solve() {
    int n,m; cin>>n>>m;
    bool ok = true;
    int p = 0;
    int st = 0, ed = 0;
    for(int i = 0; i < n; ++i) {
        int t,l,r; cin>>t>>l>>r;
        if(i == 0) st = m - t, ed = m + t;
        else st -= (t - p), ed += (t - p);
        ok &= !(ed < l || st > r);
        st = max(st, l), ed = min(ed, r);
        // cout<<st<<" "<<ed<<endl;
        p = t;
    }
    puts(ok ? "YES" : "NO");
}
```

