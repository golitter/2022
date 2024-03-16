[B-S 老师的签到_牛客挑战赛73 (nowcoder.com)](https://ac.nowcoder.com/acm/contest/76652/B)

一个矩阵中，找到从左上角到右下角的一个字典序最小的方案，其中限制了走的方向：只能向下或向右。

我用刚开始用的是bfs，在处理上有很多细节要考虑，看了题解发现跟题解的思路差不多，但是处理上冗余了很多（所以来写个题解记录一下

思路：根据题意的要求，我们可以发现从左上角到右下角形成的路径一定是$n+m-1$个字符。同时，对于向下走的长度$x$和向右走的长度$y$来说，$x+y$相同的点一定会对路径产生一个贡献，且这个点是全部$x+y$相同的点的最小字符。这个过程就像是分层图一样，固定$x+y$的点在相同的层，并由$x+y$构成的层向$x+y+1$构成的层扩散。

因此，我们可以初始时定义两个存储$i$层和$i+1$层的点的信息，由$G(i) \longrightarrow G(i+1)$扩散，之后$G(i+1)$成为新的$G(i)$再次扩散，这样不断扩散。同时记得将访问过的$(x,y)$进行标记，防止重复遍历。

代码如下：

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 10) + 21;
char g[N][N];
int vis[N][N];
char ans[N * 2];
int main()
{
    int n,m; cin>>n>>m;
    for(int i = 1; i <= n ;++i) cin>>g[i] + 1;
    int c = 0;
    vector<pair<int,int>> q[2];
    int w = 0;
    ans[w] = g[1][1]; vis[1][1] = 1;
    q[c].push_back({1, 1});
    for(int i = 1; i <= n + m - 2; ++i) {
        c ^= 1; q[c].clear();
        // 此时q[c]相当去下一个层信息，
        // 而q[c ^ 1]相等于当前层信息
        char mi = 'z';
        // 从当前层得到最小的字符
        for(auto &t: q[c ^ 1]) {
            int x = t.first, y = t.second;
            if(x < n) mi = min(mi, g[x + 1][y]);
            if(y < m) mi = min(mi, g[x][y + 1]);
        }
        // 记录贡献
        ans[++w] = mi;

        // 根据当前层信息，处理出下一层的信息
        for(auto &t: q[c ^ 1]) {
            int x = t.first, y = t.second;
            if(x < n && g[x + 1][y] == mi && !vis[x + 1][y]) {
                vis[x + 1][y] = 1;
                q[c].push_back({x + 1, y});
            }
            if(y < m && g[x][y + 1] == mi && !vis[x][y + 1]) {
                vis[x][y + 1] = 1;
                q[c].push_back({x, y + 1});
            }
        }
    }
    cout<<ans;
}
```

