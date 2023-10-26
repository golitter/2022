[2018青岛ICPC（ZOJ） [Cloned\] - Virtual Judge (vjudge.net)](https://vjudge.net/contest/471322#problem/E)

问题描述：一个机器人可以走m步，每走一步可以给走到的那一个位置的花浇水，（如果要给一个位置的花浇多次，那么需要再回到这个位置才可以）。现在给了数组a，表示第i个花浇一次水会增加价值ai。求经过最多m步浇水，这一行花最小价值的最大值是多少。

思路：二分答案，经典的最小值最大。那么如何考虑对一个花进行多次浇水的最优情况，那就是来回摆动进行对一个花进行浇水。

因此二分check函数是： 先走到当前位置，如果当前的di值小于mid，那么就对当前位置和下一个位置i+1进行a的累加，直到当前位置的di大于等于mid。需要特判`n > m`的情况。

AC代码：

```cpp
const int N = 2e5 + 21;
LL a[N];
LL b[N];
void inpfile();
void solve() {
    LL n,m; cin>>n>>m;
    rep(i,1,n) cin>>a[i];   
    LL l = 0, r = 1e18+1;
    auto check = [&](LL mid) -> bool {
        LL now = 0; // now记录当前机器人用了多少步
        rep(i,1,n) b[i] = 0; // 将b数组（d数组）进行置零
        rep(i,1,n) {
            if(i == n) { // 如果当前位置是最后一个需要特判，是否已经大于等于mid，已经则continue，否则则进行叠加
                if(b[i] >= mid) continue;
            }
            // 走到当前位置，机器人用了一次，b数组加上ai一次
            now ++; 
            b[i] += a[i];
            LL last = mid - b[i]; // 还差多少才满足 bi >= mid
            if(last <= 0) continue; // 如果差值小于等于 表示已经符合，机器人走到下一个位置即可
            LL cnt = last / a[i] + (last % a[i] == 0 ? 0 : 1); // 否则，机器人需要来回摆动多少次
            now += cnt * 2LL; // 摆动次数 * 2 是机器人又用了多少次
            b[i] += a[i] * cnt; // 当前位置进行叠加
            b[i + 1] += a[i + 1] * cnt; // 同时机器人摆动时向右边的位置也进行了叠加
            if(now > m) { // 机器人走的次数大于now，表示不可能，返回 false
                return false;
            }
        }
        return now <= m;
    };
    if(m < n) {
        puts("0");
        return ;
    }
    while(l < r) {
        LL mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    cout<<l<<endl;
}
```

