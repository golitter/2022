[P3906 Geodetic集合 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P3906)

从$u$和$v$各走一次最短路，之后判断$d[u] + d[v] == d(u,v)$是否满足即可。

由于边权为1且$n$很小，方法有很多，用两边dijkstra来写，代码如下：

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 21;
const int INF = 0x3f3f3f3f;
using PII = pair<int,int>;
int e[N], ne[N], h[N], idx, d1[N], d2[N],vis1[N], vis2[N];
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}
void solve() {
    int n, m; cin>>n>>m;
    memset(h, -1, sizeof(h));
    for(int i = 0, u,v; i < m; ++i) {
        cin>>u>>v;
        add(u,v); add(v, u);
    }
    int q; cin>>q;
    while(q--) {
        int u,v; cin>>u>>v;
        auto calc = [&]() -> void {
            for(int i = 0; i < idx; ++i) d1[i] = d2[i] = INF, vis1[i] = vis2[i] = 0;
            // d1 u
            priority_queue<PII, vector<PII>, greater<PII>> q;
            q.push({0, u});
            d1[u] = 0;
            while(q.size()) {
                auto tmp = q.top(); q.pop();
                int x = tmp.second, dis = tmp.first;
                if(vis1[x]) continue;
                vis1[x] = 1;
                for(int i = h[x]; ~i; i = ne[i]) {
                    int y = e[i];
                    if(d1[y] > dis + 1) {
                        d1[y] = dis + 1;
                        q.push({d1[y], y});
                    } 
                }
            }
            q = priority_queue<PII, vector<PII>, greater<PII>>();
            q.push({0, v});
            d2[v] = 0;
            while(q.size()) {
                auto tmp = q.top(); q.pop();
                int x = tmp.second, dis = tmp.first;
                if(vis2[x]) continue;
                vis2[x] = 1;
                for(int i = h[x]; ~i; i = ne[i]) {
                    int y = e[i];
                    if(d2[y] > dis + 1) {
                        d2[y] = dis + 1;
                        q.push({d2[y], y});
                    }
                }
            }
            for(int i = 1; i <= n; ++i) {
                // if(u == i || i == v) continue;
                if(d1[i] + d2[i] == d1[v]) {
                    cout<<i<<' ';
                }
            }
            cout<<endl;
        };
        calc();
    }
}
int main()
{
    solve(); return 0;
}
```

