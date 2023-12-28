常用的三种dfs序

- 欧拉序

每经过一次该点记录一次的序列。

- dfs序

记录入栈和出栈的序列。

- dfn序

只记录入栈的序列。



# dfs序

DFS 序列是指 DFS 调用过程中访问的节点编号的序列。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200827153551991.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NjIyMTk0Ng==,size_16,color_FFFFFF,t_70#pic_center)

如何求dfs序？可以用以下代码来找dfs序。

```cpp
    vector<vector<int>> g(n+1);
    for(int i = 1; i < n; ++i) {
        // u,v 建图
        int u,v; u = fread(); v = fread();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // dfs序的左右端点
    // 表示以x为根的子树的左右端点位置
    vector<int> l(n + 1), r(n + 1);
    int cnt = 0;
    // 一个dfs找dfs序
    auto dfs = [&](auto &&self, int u, int fa) -> void {
        l[u] = ++cnt;
        for(auto y: g[u]) {
            if(y == fa) continue;
            self(self, y,u);
        }
        r[u] = cnt;
    };
    dfs(dfs, k,-1);
```

一道简单的dfs序的问题。

题目链接：[求和 (nowcoder.com)](https://ac.nowcoder.com/acm/problem/204871)

问题描述：`n`个节点，`n - 1`条边，根节点为`k`。现在又`m`个操作。

- `1 a x`：将节点a的权值加上x
- `2 a`：求a节点的子树上所有节点的和（包括a节点本身）

思路，发现以a为根的子树权值和是一个非线性的，不能用树状数组或者线段树来做。但是dfs序却有一个天然的顺序可以来处理。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200827153551991.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NjIyMTk0Ng==,size_16,color_FFFFFF,t_70#pic_center)

观察上图：

- 以5为根的子树序列在dfs序中的排序是：`1 2 3 4 5 6 7 8`

- 以8为根的子树序列在dfs序中的排序是：`2 3`

- 以2为根的子树序列在dfs序中的排序是：`3`

- 以1为根的子树序列在dfs序中的排序是：`4 5 6 7 8`

...

**我们发现，每个子树都对应 DFS 序列中的连续一段（一段区间）。**

> [DFS（图论） - OI Wiki (oi-wiki.org)](https://oi-wiki.org/graph/dfs/)

因此本题思路就是：用dfs序将非序列顺序转线性序列。之后就是单点修改，区间查询，可以用树状数组或者线段树来进行求解。

本人是用线段树来进行处理的（线段树大法好

AC代码：

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

// #define Multiple_groups_of_examples
#define int_to_long_long
#define IOS std::cout.tie(0);std::cin.tie(0)->sync_with_stdio(false); // 开IOS，需要保证只使用Cpp io流 *
#define dbgnb(a) std::cout << #a << " = " << a << '\n';
#define dbgtt cout<<" !!!test!!! "<<'\n';
#define rep(i,x,n) for(int i = x; i <= n; i++)

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define vf first
#define vs second

typedef long long LL;
#ifdef int_to_long_long
#define int long long
#endif
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 21;


struct SegTree {
    static const int N = 1e6 + 21;
    struct node {
        int l, r, mi;
        LL sum,add;
    }tr[N << 2];
    int w[N];
    // 左子树
    inline int ls(int p) {return p<<1; }
    // 右子树
    inline int rs(int p) {return p<<1|1; }
    // 向上更新
    void pushup(int u) {
        tr[u].sum = tr[ls(u)].sum + tr[rs(u)].sum;
        tr[u].mi = min(tr[ls(u)].mi, tr[rs(u)].mi);
    }
    // 向下回溯时，先进行更新
    void pushdown(int u) { // 懒标记，该节点曾经被修改，但其子节点尚未被更新。
        auto &root = tr[u], &right = tr[rs(u)], &left = tr[ls(u)];
        if(root.add) {
            right.add += root.add; right.sum += (LL)(right.r - right.l + 1)*root.add; right.mi -= root.add;
            left.add += root.add; left.sum += (LL)(left.r - left.l + 1)*root.add; left.mi -= root.add;
            root.add = 0;
        }

    }
    // 建树
    void build(int u, int l, int r) {
        if(l == r) tr[u] = {l, r, w[r], w[r], 0};
        else {
            tr[u] = {l,r}; // 容易忘
            int mid = l + r >> 1;
            build(ls(u), l, mid), build(rs(u), mid + 1, r);
            pushup(u);
        }
    }
    // 修改
    void modify(int u, int l, int r, int d) {
        if(tr[u].l >= l && tr[u].r <= r) {
            tr[u].sum += (LL)(tr[u].r - tr[u].l + 1)*d;
            tr[u].add += d;
        }
        else {
            pushdown(u);
            int mid = tr[u].l + tr[u].r >> 1;
            if(l <= mid) modify(ls(u), l ,r, d);
            if(r > mid) modify(rs(u), l, r, d);
            pushup(u);
        }
    }
    // 查询
    LL query(int u, int l, int r) {
        if(tr[u].l >= l && tr[u].r <= r) {
            return tr[u].sum;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        LL sum = 0;
        if(l <= mid) sum = query(ls(u), l, r);
        if(r > mid ) sum += query(rs(u), l, r);
        return sum;
    }
}tree;
// 当输入数据大于 1e6 时用快读
inline int fread() // 快读
{
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * f;
}
void inpfile();
void solve() {
    // int n,m,k; cin>>n>>m>>k;
    int n = fread(), m = fread(), k = fread();
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) a[i] = fread();
    vector<vector<int>> g(n+1);
    for(int i = 1; i < n; ++i) {
        int u,v; u = fread(); v = fread();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> l(n + 1), r(n + 1);
    int cnt = 0;
    auto dfs = [&](auto &&self, int u, int fa) -> void {
        l[u] = ++cnt;
        for(auto y: g[u]) {
            if(y == fa) continue;
            self(self, y,u);
        }
        r[u] = cnt;
    };
    dfs(dfs, k,-1);
    for(int i = 1; i <= n; ++i) tree.w[l[i]] = a[i];
    tree.build(1,1,n);
    while(m--) {
        int opt,x,y; opt = fread();
        if(opt == 2) {
            // cin>>x>>y;
            x = fread();
            cout<<tree.query(1, l[x], r[x])<<'\n';
        } else {
            x = fread(), y = fread();
            tree.modify(1,l[x],l[x],y);
        }
    }
}
#ifdef int_to_long_long
signed main()
#else
int main()
#endif

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



还有一个好题是这几天cfdiv2的F，这个F是牛客上的一个原题。

牛客：[华华和月月种树 (nowcoder.com)](https://ac.nowcoder.com/acm/problem/23051?&headNav=acm)

cf：[Problem - F - Codeforces](https://codeforces.com/contest/1891/problem/F)

个人题解链接：[离线处理 + dfs序 + 区间修改 + 单点查询-CSDN博客](https://blog.csdn.net/qq_63432403/article/details/134144255?csdn_share_tail={"type"%3A"blog"%2C"rType"%3A"article"%2C"rId"%3A"134144255"%2C"source"%3A"qq_63432403"})

[dfs序（基础讲解）-CSDN博客](https://blog.csdn.net/weixin_46221946/article/details/108261347)

[树 DFS序 详解[完全版\]_千杯湖底沙.的博客-CSDN博客](https://blog.csdn.net/qq_39670434/article/details/78425125?ops_request_misc=%7B%22request%5Fid%22%3A%22169234467016800225512881%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=169234467016800225512881&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-78425125-null-null.142^v93^insert_down1&utm_term=dfs序&spm=1018.2226.3001.4187)