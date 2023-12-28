[Problem - 1830A - Codeforces](https://codeforces.com/problemset/problem/1830/A)

问题描述：

科皮尔-科帕克（Copil Copac）得到一个由 $n-1$条边组成的列表，该列表描述了一棵由 $n$个顶点组成的树。他决定用下面的算法来绘制它：

- 步骤 $0$：绘制第一个顶点（顶点$1$）。进入步骤 $1$。
- 步骤 $1$：对于输入中的每一条边，依次绘制：如果这条边连接了一个已绘制的顶点$u$和一个未绘制的顶点$v$，则绘制未绘制的顶点$v$和这条边。检查完每一条边后，进入步骤$2$。
- 步骤 $2$：如果所有顶点都绘制完毕，则终止算法。否则，转到步骤 $1$。

读取次数定义为 Copil Copac 执行步骤 $1$的次数。

请计算 Copil Copac 绘制这棵树所需的读数。

> 插件 cf better

问题简化：建树，按建树顺序进行绘制。对于第i个边，可以向`j > i`的边进行绘制不消耗次数，否则需要花一次绘制。问绘制需要的次数。

思路：类似树形dp。

代码：

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <random>
#include <sstream>
#include <numeric>
#include <stdio.h>
#include <functional>
#include <bitset>
#include <algorithm>
using namespace std;

#define Multiple_groups_of_examples
#define IOS std::cout.tie(0);std::cin.tie(0)->sync_with_stdio(false);
#define dbgnb(a) std::cout << #a << " = " << a << '\n';
#define dbgtt cout<<" !!!test!!! "<<endl;
#define rep(i,x,n) for(int i = x; i <= n; i++)

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define vf first
#define vs second

typedef long long LL;
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 21;

void inpfile();
void solve() {
    int n; cin>>n;
    vector<vector<PII>> g(n+1); // PII({ 点u，输入顺序})
    for(int i = 2; i <= n ; ++i) {
        int u,v; cin>>u>>v;
        // 无向 
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    // f[i] 表示 到结点i用了多少个次数
    vector<int> f(n + 1);
    int ans = 0; // 记录答案
    f[1] = 1; // 第一个节点需要一次
    auto vis(f); // 是否走过，走过不走，也可以不用这个vis数组，因为 y == fu || idx == fi 就已经将这个判断过了（

    //  当前节点  当前节点的父亲节点  这个节点的边的输入顺序编号
    auto dfs = [&](auto &&dfs, int u, int fu, int fi) -> void {
        for(auto t: g[u]) {
            // 得到 儿子节点 和 <u,y> 边的编号
            int y = t.vf, idx = t.vs;
            if(y == fu || idx == fi) continue;
            if(vis[y]) continue;
            vis[y] = 1;
            // 如果 <u,y> 的输入编号 小于 <fu,u> 的输入编号则需要消耗次数
            f[y] = f[u] + (idx < fi);
            dfs(dfs, y,u,idx);
        }
        // 更新答案，肯定最大的，因为题要求是全部绘制完需要的次数
        ans = max(ans, f[u]);
    };
    dfs(dfs,1,-1,0);
    cout<<ans<<endl;
}
int main()
{
    #ifdef Multiple_groups_of_examples
    int T; cin>>T;
    while(T--)
    #endif
    solve();
    return 0;
}
void inpfile() {
    #define mytest
    #ifdef mytest
    freopen("ANSWER.txt", "w",stdout);
    #endif
}
```

