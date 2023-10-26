[F - LIS on Tree (atcoder.jp)](https://atcoder.jp/contests/abc165/tasks/abc165_f)

问题描述：树上LIS。

普通LIS。`O(n * n)`。

```cpp
void solve() {
    int n; cin>>n;
    vector<int> f(n + 1),a(n+1);
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        f[i] = 1;
        for(int j = 1; j < i; ++j) {
            if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
        }
    }
    cout<<*max_element(all(f));
}
```

二分优化。`O(n * log(n))`。

```cpp
/// 版本1
void solve() {
    vector<int> f;
    int n; cin>>n;
    for(int i = 0; i < n; ++i) {
        int t; cin>>t;
        auto pos = lower_bound(all(f), t);
        if(pos == f.end()) f.push_back(t);
        else *pos = t;
    }
    cout<<f.size();
}
```

```cpp
/// 版本2
void solve() {
    int n; cin>>n;
    vector<int> f(n,INF);
    int ans = -1;
    for(int i = 0; i < n; ++i) {
        int t; cin>>t;
        int pos = lower_bound(all(f), t) - f.begin();
        f[pos] = t;
        ans = max(ans, pos);
    }
    cout<<ans + 1;
}
```

对于树上LIS来说，如果只考虑一条链的话，就是裸LIS。由于对于一个父节点，它的儿子节点都共用父节点往上的那一条链上的权值，而且遍历完1个儿子节点，对其余的儿子节点的操作中需要将这个儿子节点的操作撤销掉。这个撤销很像回溯。数据范围很大，需要LIS优化，如果用版本1的LIS，每次需要判断是改回还是删除，可能删除这个操作会超时；用版本2的LIS，只需要考虑改回就行，更简单些。

具体代码思路：无向树建树。遍历到节点`u`时，计算到这个节点`u`的LIS长度，之后将节点`u`的权值加入到LIS数组中，找儿子节点，最后再将 “之前节点`u`的权重加入到LIS数组中” 的这一步进行回溯/撤销。

具体代码：

```cpp
// 版本2 AC代码
void solve() {
    int n; cin>>n; 
    vector<vector<int>> g(n+1);
    vector<int> val(n + 1),f(n+1, INF), ans(n + 1);
    for(int i = 1; i <= n; ++i) cin>>val[i];
    for(int i = 1; i < n; ++i) {
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](auto &&dfs, int u, int fu) -> void {
        // 找到第一个大于等于val[u]的位置
        int pos = lower_bound(f.begin()+1, f.end(), val[u]) - f.begin(); 
        int tmp = f[pos]; // 记录这个位置的权重，因为要撤销/回溯
        f[pos] = val[u]; // 将pos位置更改为val[u]
        ans[u] = max(ans[fu], pos); // 求LIS长度
        for(auto y: g[u]) {
            if(y == fu) continue;
            dfs(dfs, y,u);
        }
        // 进行撤销操作
        f[pos] = tmp;
    };
    dfs(dfs, 1, 0);
    for(int i = 1; i <= n; ++i) cout<<ans[i]<<endl;
}
```

```cpp
// 版本1 RE代码 可能还有错误没有找到》
void solve() {
    int n; cin>>n; 
    vector<vector<int>> g(n+1);
    vector<int> val(n + 1),f, ans(n + 1);
    for(int i = 1; i <= n; ++i) cin>>val[i];
    for(int i = 1; i < n; ++i) {
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](auto &&dfs, int u, int fu) -> void {
        int tag = 0;
        auto pos = lower_bound(all(f), val[u]);
        int len = pos - f.begin() + 1;
        if(pos == f.end()) {
            tag = -1;
            f.push_back(val[u]);
        } else {
            tag = *pos;
            *pos = val[u];
        }
        ans[u] = len;
        for(auto y: g[u]) {
            if(y == fu) continue;
            dfs(dfs, y,u);
        }
        if(tag == -1) {
            f.erase(f.end()-1);
        } else *pos = tag;
    };
    dfs(dfs, 1, 0);
    for(int i = 1; i <= n; ++i) cout<<ans[i]<<endl;
}
```

