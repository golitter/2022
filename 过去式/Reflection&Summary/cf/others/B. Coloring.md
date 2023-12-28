[Problem - B - Codeforces](https://codeforces.com/contest/1774/problem/B)

抽屉原理。

比如说，举个栗子，一条长 1313 的纸条，连续 33 格中不能有相同。

接下来，假设第一格被涂上了红色。由于题设，第二格和第三格就不能涂红色。

为了涂得多一点，第四格能涂，就涂上第四格。

同理，接下来涂第七格、第十格、第十三格。

抽屉原理，也称为鸽笼原理或鸽巢原理，是组合数学中的一条重要原理。它的基本思想是：如果有m个物体要放进n个抽屉，当m > n时，至少有一个抽屉内会放入2个或更多个物体。

```cpp
void solve() {
    int n,m,k; cin>>n>>m>>k;
    bool ok = true;
    int p = n / k;
    int cnt = n - p * k;
    for(int i = 0; i < m ;++i) {
        int t; cin>>t;
        ok &= (t <= p + 1);
        if(t == p+1) cnt--;
    }
    puts(ok && cnt >= 0 ? "YES" : "NO");
}
```

我用`t / k`为什么不对呢。

