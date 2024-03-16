[P6208 [USACO06OCT\] Cow Pie Treasures G - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P6208)

思路：动态规划或记忆化搜索，本题解采用记忆化搜索。

可以发现，对于一个遍历的终点$(ed_x, ed_y)$可能有不同的中间点（可视为起点）可以到达，每个中间点到终点的路径是固定的。在其他点到达中间点时可以根据现在该点和之前到达中间点的价值进行比较，得到是否从该点进行搜索，这样可以优化。

例如，有中间点$(md_x, md_y)$， $(now_x, now_y)$，同时 $\exists i $，$(x_i, y_i)$已经到达过终点$(ed_x, ed_y)$。

那么就会有：

- 如果$(x_i, y_i)$的值大于等于$(now_x, now_y)$，那么$(now_x, now_y)$到达$(ed_x, ed_y)$的价值和一定不大于$(x_i, y_i)$到$(ed_x, ed_y)$的价值和
- 反之，$(x_i, y_i)$的值小于$(now_x, now_y)$，那么可能存在$(now_x, now_y)$到达$(ed_x, ed_y)$的价值和大于$(x_i, y_i)$到$(ed_x, ed_y)$的价值和。



但是不能以终点到起点来考虑记忆化，因为从终点到起点经过的点可能有多个边，因此需要考虑更多信息，较为繁琐。

代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 121;
int g[N][N], f[N][N];
int n,m,ans;
void dfs(int x, int y, int val) {
    if(x < 1 || x > n || y < 1 || y > m) return ;
    if(f[x][y] && f[x][y] > val) return ;

    f[x][y] = val;
    if(x == n && y == m) ans = max(ans, val);
    dfs(x - 1, y + 1, val + g[x - 1][y + 1]);
    dfs(x, y + 1, val + g[x][y + 1]);
    dfs(x + 1, y + 1, val + g[x + 1][y + 1]);

}
void solve() {
    cin>>n>>m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) cin>>g[i][j];
    }
    f[1][1] = g[1][1];
    dfs(1, 1, g[1][1]);
    cout<<ans<<endl;
}
int main()
{
    solve(); return 0;
}
```

