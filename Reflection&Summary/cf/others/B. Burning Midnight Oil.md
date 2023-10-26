[Problem - B - Codeforces](https://codeforces.com/contest/165/problem/B)

问题描述：给定n和k，求满足以下条件的最小的v。
$$
n \ge \sum_{i=0}^{\infty}[ \frac v {k^i}]
$$
具有单调性，用二分。二分答案，最大值最小。

代码：

```cpp
void solve() {
    LL n,k; cin>>n>>k;
    auto check = [&](LL mid) -> bool {
        LL sum = mid;
        LL p = k;
        while(n/p) {
            sum += mid/p;
            p *= k;
        }
        return sum >= n;
    };
    LL l = 0, r = 1e9;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout<<r;
}
```

