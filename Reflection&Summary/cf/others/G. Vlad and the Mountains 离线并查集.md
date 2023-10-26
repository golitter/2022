[Problem - G - Codeforces](https://codeforces.com/contest/1851/problem/G)

问题描述：n个点，m条边，点权为h，从i到j要消耗`hj - hi`能量，如果值为负数则表示恢复能量。给q次询问，每次给出`s t e`表示起点、终点、初始能量，在移动过程中能量不能小于0，为是否可以从s走到t。

思路：如果每次都是减去`hj - hi`的值的话，可以形成一个折线图，总的花费是`hs - ht`，所以只需要在s到t的路径上满足所有的点都是`hk <= max(hs, ht) + e`就一定是可以走到的，即`hb <= ha + e`。传递性和连通性，要用到并查集。将所有小于`max(hs, ht) + e`的边的最大点权放入到一个集合中，之后判断a和b是否在同一个集合即可。可是每一次查询都需要重新并查集这无异于暴力。

考虑离线操作：将边的最大点权和查询qry的`ha + e`排序，遍历qry，每次将边最大点权小于等于`ha + e`的放入并查集中（因为是一定可以的，对qry的`ha + e`进行排序后，插入的一定是当前的，对前面的没有影响。），之后按编号顺序进行输出即可。

```cpp
void solve() {
    int n,m; cin>>n>>m;
    vector<int> p(n + 1),h(n + 1);
    vector<array<int,3>> edges(m);

    // 并查集
    iota(all(p),0);
    auto find = [&](auto &&self, int x) -> int {
        return p[x] == x ? x : p[x] = self(self, p[x]);
    };
    auto merge = [&](int u, int v) -> void {
        int fv = find(find,v), fu = find(find, u);
        if(fv != fu) {
            p[fv] = fu;
        }
    };

    for(int i = 1; i <= n; ++i) cin>>h[i];
    for(int i = 0; i < m; ++i) {
        int u,v; cin>>u>>v;
        // 对于(u,v)而言，只有最大值跟e有关
        edges[i] = {max(h[u], h[v]), u,v};
    }
    int q; cin>>q;
    vector<array<int,4>> qry(q);
    for(int i = 0; i < q; ++i) {
        int s,t,e; cin>>s>>t>>e;
        // 将 hs + e 进行处理
        qry[i] = {h[s] + e, s, t, i}; // i 表示qry编号
    }
    // 排序
    sort(all(qry));
    sort(all(edges));
    // 答案编号
    vector<int> ans(q);
    int pos = 0;
    for(auto t: qry) {
        int h = t[0], u = t[1], v = t[2], id = t[3];
        // 将 边的最大点权跟 ha + e 进行比较，如果小于则在以e为初始能量的这两个是可以到的。
        while(pos < m && edges[pos][0] <= h) {
            merge(edges[pos][1], edges[pos][2]);
            pos++;
        }
        // 得到第id个查询的编号
        ans[id] = (find(find, u) == find(find, v));
    }
    // 输出
    for(auto t: ans) {
        puts(t ? "YES" : "NO");
    }
    puts("");
}
```

[(26 封私信 / 13 条消息) Codeforces Round 888 (Div. 3) - 搜索结果 - 知乎 (zhihu.com)](https://www.zhihu.com/search?type=content&q=Codeforces Round 888 (Div. 3))