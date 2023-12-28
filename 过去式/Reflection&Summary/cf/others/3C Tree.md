## C. Infected Tree

[Problem - C - Codeforces](https://codeforces.com/contest/1689/problem/C)

问题描述：一个二叉树，根节点被感染了，可以通过删除一个节点使这个树分成两个部分，从而使分离开的子树无法被感染，求这样操作，有最多多少个节点是未被感染的（删除的节点不算未被感染的）。

思路：树形dp。`f[u]`表示为`u`被感染后他的子树有最多多少个的节点未被感染。如果`u`是叶子节点，那么就是0；如果`u`只要一个节点，那么就是`siz[v] - 1`；如果有两个节点，那么就是`max(siz[v1] - 1 + f[v2], siz[v2] - 1 + f[v1])`。
$$
F(u) = \begin{cases}
叶子节点 \quad 0 \\
一个子节点 \quad siz[v] - 1 \\
两个子节点 \quad max(siz[v1]- 1 + f[v2], siz[v2] - 1 + f[v1])
\end{cases}
$$
边界：无。

目标：
$$
F(1)
$$


注意事项：`u`的子节点不是`g[u].size()`，由于建树是双向边，因此多一个`<u, fu>`这条边。而且，也不能单纯直接令`v1 = g[u][0], v2 = g[u][1]`，原因同上。但是可以用两个变量去处理`v1 v2`。

代码：

```cpp
void solve() {
    int n; cin>>n;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; ++i) {
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> f(n + 1), siz(n + 1);
    auto dfs = [&](auto &&dfs, int u, int fu) -> void {
        siz[u] = 1;
        int cnt = 0;
        PII son = {-1,-1};
        for(auto y: g[u]) {
            if(y == fu) continue;
            dfs(dfs, y,u);
            cnt++;
            if(son.vf == -1) son.vf = y;
            else son.vs = y;
            siz[u] += siz[y];
        }
        if(cnt == 0) {
            f[u] = 0;
        }
        if(cnt == 1) {
            f[u] = siz[ son.vf] - 1;
        }
        if(cnt == 2) {
            int v1 = son.vf, v2 = son.vs;
            f[u] = max(siz[v1] - 1 + f[v2], siz[v2] - 1 + f[v1]);
        }
    };
    dfs(dfs,1,-1);
    cout<<f[1]<<endl;
}
```

## C. Kefa and Park

[Problem - C - Codeforces](https://codeforces.com/contest/580/problem/C)

问题描述：一个树，叶子节点有餐馆，从根节点出发到餐馆求有多少条路。限制条件是在一条路中，不能走**连续**k个点权为1的点。

思路：记录一条路径上连续的1的个数，如果连续的1的个数大于k，则后面怎么都到达不了，否则就有可能。之后叶子节点能否到达即可。

代码：

```cpp
void solve() {
    int n,k; cin>>n>>k;
    vector<int> vw(n + 1),lnow(n + 1), leaf(n + 1);
    vector<vector<int>> g(n + 1);
    for(int i = 1; i <= n; ++i) cin>>vw[i];
    for(int i = 1; i < n; ++i) {
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&] (auto &&dfs, int u, int fu) -> void {
        for(auto y: g[u]) {
            if(y == fu) continue;
            if(vw[y] == 0) {
                lnow[y] = 0;
            } else {
                lnow[y] = lnow[u] + 1;
            }
            if(lnow[y] > k) continue;
            dfs(dfs, y,u);
        }
        if(g[u].size() == 1) leaf[u] = 1;
    };
    // 对根节点连续1进行处理
    lnow[1] = vw[1];
    dfs(dfs,1,-1);
    int ans = 0;
    for(int i = 2; i <= n; ++i) if(leaf[i]) ans += 1;
    cout<<ans;
}
```

## C. k-Tree

[Problem - C - Codeforces](https://codeforces.com/contest/431/problem/C)

问题描述：一个满k叉树，对于一个节点来说，它到它k个节点的边权分为1...k。求从根节点出发，到路径和为n且存在一条大于等于d的边权的个数。

思路：像是数字三角形的那个dp，数据范围很小。而且只有一个特殊状态，是否大于d了。设状态为从根节点到一个节点的路径和为i时，存在了大于d的边和不存在大于d的边。

状态转移方程：
$$
F(i,j) = \begin{cases}
w < d \quad F(i,0) += F(i - w,0); \quad F(i,1) += F(i - w,1) \\
w \ge d \quad F(i,1) += F(i-w,1) + F(i-w,0) \\
\end{cases} \\
w为<u,v>的边权
$$
边界：
$$
F(0,0) = 1
$$
目标：
$$
F(n,1)
$$
注意: 如果`w > i`那这个`i - w`就是负数，不合法，因此遍历的应该是`min(w,i)`。

代码：

```cpp
const LL mod = 1000000007;
LL f[N][N];
void inpfile();
void solve() {
    int n,k,d; cin>>n>>k>>d;
    f[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= min(i,k); ++j) {
            if(j < d) f[i][0] += f[i - j][0], f[i][1] += f[i-j][1];
            else f[i][1] += f[i-j][1] + f[i-j][0];
            f[i][0] %= mod;
            f[i][1] %= mod;
        }
    }
    cout<<f[n][1];
}
```



