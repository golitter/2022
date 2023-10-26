[Problem - 1862D - Codeforces](https://codeforces.com/problemset/problem/1862/D)

[Ice Cream Balls - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/CF1862D)

有 �*t* 组数据。每组数据给定 �(1≤�≤1018)*n*(1≤*n*≤1018)。

你可以使用任意两个数字组成一个二元组。

两个二元组被认为是不同的，那么这两个二元组中的元素在经过调换顺序后不同。例如，{1,2}={2,1},{1,1}≠{1,2}{1,2}={2,1},{1,1}={1,2}。

如果你选择了数字 1,1,21,1,2，那么你只能得到两个二元组：{1,1},{1,2}{1,1},{1,2}。

现在请你求出至少要**多少个数字**才能**刚好**得到 �*n* 个不同的二元组。

保证答案一定存在。

思路：

如果全是不同的数字，那么方案数就是
$$
C_m^2
$$
如果有相同的数字，对方案数的贡献只是加1。因此，首选不同的，还剩下的用相同的数字代替。

接下来，就是简单的二分答案，因为这个具有单调性。

```cpp
const LL INF = INT_MAX;
const int N = 2e5 + 21;

void inpfile();
void solve() {
    LL n; cin>>n;
    LL l = 0, r = INF;
    LL ans = INF;
    auto check = [&](LL mid) -> bool {
        return mid * (mid - 1) / 2 <= n;
    };
    while(l < r) {
        LL mid = l + r + 1 >> 1;
        if(check(mid)) {
            l = mid;
        } else r = mid - 1;
    }
    cout<<l + n - l * (l - 1) / 2<<endl;
}
```

