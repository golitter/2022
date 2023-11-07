cfdiv2 #907场的F是牛客原题，过的很多，作为数据结构手竟然没有做过&据说很典，实在是太差劲了，于是第二天就来做这道题。

牛客：[华华和月月种树 (nowcoder.com)](https://ac.nowcoder.com/acm/problem/23051?&headNav=acm)

cf：[Problem - F - Codeforces](https://codeforces.com/contest/1891/problem/F)

牛客题意描述（cf的差不多）：有`n`个操作：

- `1 i`：表示节点`i`长出了一个新的儿子节点，权值为0，编号为当前最大编号+1
- `2 i a`：使以`i`为根的子树中节点加上`a`
- `3 i`：询问`i`节点的权值

这一题由于是动态的，不能一遍得到，但是又不能每次加点后来个build。但是发现求的是第`i`个节点的权值，根据dfs序的性质，我们可以求出最终态的dfs序。由于每个节点都是其中一个已经存在的节点的儿子节点，所以用终态dfs序建好线段树后，在遍历`n`次操作时：

- 如果是加点操作那么就需要记录当前这个点的权值，因为这个点在没有加上之前，该点权值一定是0，但是前面可能对终态该点祖先节点进行了操作2，要将之前对该点的加权值给撤销掉，因此需要记录加之前该点权值。之后查询到该点时，答案就是查询到该点的值减去org【该点对应的dfs序下标】（org数组是：添加该点之前，该点有的权值。
- 区间操作同基础线段树
- 查询点`i`：`i`点权值减去org【`i`点对应的dfs序下标】

因此代码实现为：

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
    int n = fread();
    vector<int> a(n + 1);
    vector<vector<int>> g(n+1);
    // 离线存储操作
    vector<array<int,3>> ask(n);
    int now = 1; // now加点的编号
    for(int i = 0; i < n; ++i) {
        ask[i][0] = fread(), ask[i][1] = fread();
        ask[i][1]++;
        if(ask[i][0] == 1) {
            int u = ask[i][1];
            // 这里给出顺序了 i是父节点，因此不用建双边
            g[u].push_back(++now);
            // 将加后的点编号存入
            ask[i][2] = now;
        } else if(ask[i][0] == 2) ask[i][2] = fread();
    }

    // dfs序求法
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
    dfs(dfs, 1,-1);

    // 建树
    tree.build(1,1,now);
    vector<int> org(n + 1);
    for(int i = 0; i < n; ++i) {
        // 操作1：获得在v点插入之前，v点权值被加了多少
        if(ask[i][0] == 1) {
            int v = ask[i][2], u = ask[i][1];
            org[l[v]] += tree.query(1, l[u], l[u]);
        } else if(ask[i][0] == 2) { // 正常修改即可
            int x = ask[i][1], y = ask[i][2];
            tree.modify(1,l[x], r[x], y);
        } else {
            int x = ask[i][1];
            // 查询到的值 - x插入之前被加了多少
            cout<<tree.query(1, l[x], l[x]) - org[l[x]]<<'\n';
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

cfdiv2 #907F是最后输出所有节点权值，数组需要开大点，不然会wa35。（感觉是牛客数据弱，没有cf第35那个数据，那个数据可能是`n`个操作全是插入点。

cfdiv2 #907F AC代码：

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
// const int N = 2e5 + 21;


struct SegTree {
    static const int N = 5e5 + 21;
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
    int n = fread();
    vector<int> a(n + 1);
    vector<vector<int>> g(n+21);
    vector<array<int,3>> ask(n);
    int now = 1;
    for(int i = 0; i < n; ++i) {
        ask[i][0] = fread(), ask[i][1] = fread();
        // ask[i][1]++;
        if(ask[i][0] == 1) {
            int u = ask[i][1];
            g[u].push_back(++now);
            ask[i][2] = now;
        } else if(ask[i][0] == 2) ask[i][2] = fread();
    }
    vector<int> l(n + 21), r(n + 21);
    int cnt = 0;
    auto dfs = [&](auto &&self, int u, int fa) -> void {
        l[u] = ++cnt;
        for(auto y: g[u]) {
            if(y == fa) continue;
            self(self, y,u);
        }
        r[u] = cnt;
    };
    dfs(dfs, 1,-1);
    // for(int i = 1; i <= n; ++i) tree.w[l[i]] = 0;
    tree.build(1,1,now);
    vector<int> org(n + 21);
    for(int i = 0; i < n; ++i) {
        if(ask[i][0] == 1) {
            int v = ask[i][2], u = ask[i][1];
            org[l[v]] += tree.query(1, l[u], l[u]);
        } else if(ask[i][0] == 2) {
            int x = ask[i][1], y = ask[i][2];
            tree.modify(1,l[x], r[x], y);
        } else {
            // int x = ask[i][1];
            // cout<<tree.query(1, l[x], l[x]) - org[l[x]]<<' ';
        }
    }
    for(int i = 1; i <= now; ++i) cout<<tree.query(1, l[i], l[i]) - org[l[i]]<<" ";
    puts("");
    for(int i = 0; i <= n; ++i) tree.w[i] = 0;
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

