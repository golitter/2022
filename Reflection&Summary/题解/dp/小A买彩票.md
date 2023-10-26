[小A买彩票 (nowcoder.com)](https://ac.nowcoder.com/acm/problem/23413)

问题描述：一张彩票3元，连续购买n张彩票，问不亏本的概率是多少。

思路：具有无后效性，用dp。状态表示为到第i张彩票时中了j元。
$$
F(i,j) = \sum_{k=1}^4F(i-1, j - k \ge 0 \quad \and \quad j - k)
$$
总的情况数是`4^n`，满足不亏本的情况是`F(n, [3n, 4n])`。

求的结果表示为`ans / gcd(4^n, ans) + "/" + 4^n / gcd(4^n, ans)`

边界：当买第0张彩票不亏本的情况为1。
$$
F(0,0) = 1
$$
代码：

```cpp
LL f[33][200];
void inpfile();
void solve() {
    int n; cin>>n;
    f[0][0] = 1;
    rep(i,1,n) {
        rep(j,1,i*4) {
            rep(k,1,4) {
                if(j - k >= 0) {
                    f[i][j] += f[i-1][j - k];
                }
            }
        }
    }
    LL al = 1LL<<(n<<1);
    LL cnt = 0;
    rep(i,3*n,4*n) cnt += f[n][i];
    int cs = __gcd(cnt,al);
    cout<<cnt/cs<<'/'<<al/cs;
}
```



