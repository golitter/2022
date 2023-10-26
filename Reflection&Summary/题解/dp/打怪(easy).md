[B-打怪(easy)_第二十届同济大学程序设计竞赛（同步赛） (nowcoder.com)](https://ac.nowcoder.com/acm/contest/59248/B)

问题描述：初始攻击是1，防御是0，血量无穷。怪物防御力永远为0，只有初始血量和攻击力。双方每次受到的攻击会掉`对手攻击-自己防御`的血量。每打死一个怪会掉一个金币，可以用一个金币提高自己一攻击力或者一防御力。问在不再受到伤害之前受到的最小伤害是多少。

思路：几个月前想的是枚举，发现错了。

现在发现，这题有重叠子问题和无后效性，可以用dp。

每打死一个怪可以提高攻击力或者防御力，等价于，每次是攻击提高或者防御提高，状态表示可以得出。

状态表示：`F(i,j)`表示防御为i，攻击为j时受到的最少伤害。

转移方程：
$$
F(i,j) = \begin{cases}
i \gt 0 \quad min(F(i,j),F(i-1,j) + reduce(i-1,j)) \\
j \gt 1 \quad min(F(i,j), F(i,j-1) + reduce(i,j-1))
\end{cases}
$$
其中`reduce`函数为在攻击为atk，防御为df时打死一个怪自己受到的伤害。

```cpp
int reduce(int df, int atk) {
	int t = m / atk + (m % atk == 0 ? 0 : 1);
	t--; // 简单模拟可以知道
	return t * (n - df);
}
```

边界：
$$
F(i_{0 \le i \le n},j_{1 \le j \le m}) \begin{cases}
i =  0 且j = 1 \quad 1 \\
else \quad inf
\end{cases}
$$
目标：
$$
min(F(n,j_{1 \le j \le m}), F(i_{0 \le i \le n},m))
$$


代码：

```cpp
const int N = 2e3 + 21;
int f[N][N]; // 防御力 i， 攻击力 j
void inpfile();
void solve() {
    int n,m; cin>>n>>m; // 攻击，血量
    auto reduce = [&](int df, int atk) -> int {
        int t = m / atk + (m % atk == 0 ? 0 : 1);
        t--;
        return t * (n - df);
    };
    memset(f, 0x3f, sizeof(f));
    f[0][1] = 0;
    rep(i,0,n) {
        rep(j,1,m) {
            if(i > 0) f[i][j] = min(f[i][j], f[i-1][j] + reduce(i-1,j));
            if(j > 1) f[i][j] = min(f[i][j], f[i][j-1] + reduce(i,j-1));
        }
    }
    int ans = INF;
    rep(i,1,m) ans = min(ans, f[n][i]);
    rep(i,0,n) ans = min(ans, f[i][m]);
    cout<<ans;
}
```

