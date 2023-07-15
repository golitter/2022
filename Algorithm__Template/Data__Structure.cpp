/**
 * 树状数组 BIT
 * 线段树  SegTree
 * 并查集 DisjointSet
 * 最近公共祖先 LCA
 * 分块 block
 * 
*/
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
#include <algorithm>
using namespace std;

#define rep(i,x,n) for(int i = x; i <= n; i++)

typedef long long LL;
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 21;

namespace golitter {
namespace BIT {
    /**  url: https://ac.nowcoder.com/acm/contest/61132/L
        底部确定，顶部无穷大
        最外面的结点是2的n次方，如上图1，2，4，8的结点
        奇数的结点一定是叶子结点
        数组一定要从1开始
    */
const int N = 5e5 + 21;
int n,m;
int tr[N];
int lowbit(int x) {
    return x & -x;
}
void add(int x, int c) {
    for(; x < N; x += lowbit(x)) tr[x] += c;
}
LL sum(int x) {
    LL res = 0;
    for(; x; x -= lowbit(x)) res += tr[x];
    return res;
}
void solve() {
    cin>>n>>m;
    rep(i,1,n) {
        int x; cin>>x;
        add(i, x);
    }
    rep(i,1,m) {
        int a,b,c; cin>>a>>b>>c;
        if(a == 1) {
            add(b,c);
        } else {
            cout<<sum(c) - sum(b-1)<<endl;
        }
    }
}

}}

namespace golitter {
namespace SegTree {
    /**
 * 小区间的值更新大区间的值
 * 问题满足：区间加法： [l, r] 可以用 [l, mid] 和 [mid+1, r]的值产生
 *      不满足的问题：区间的众数，区间最长连续问题，最长不下降问题
 *      
 * 解题步骤： 建树，
*/

int w[N],n,m;
struct adt {
    int l,r;
    LL sum,add;
}tr[N << 2];
// 左子树
inline int ls(int p) {return p<<1; }
// 右子树
inline int rs(int p) {return p<<1|1; }
// 向上更新
void pushup(int u) {
    tr[u].sum = tr[ls(u)].sum + tr[rs(u)].sum;
}
// 向下回溯时，先进行更新
void pushdown(int u) { // 懒标记，该节点曾经被修改，但其子节点尚未被更新。
    auto &root = tr[u], &right = tr[rs(u)], &left = tr[ls(u)];
    if(root.add) {
        right.add += root.add; right.sum += (LL)(right.r - right.l + 1)*root.add;
        left.add += root.add; left.sum += (LL)(left.r - left.l + 1)*root.add;
        root.add = 0;
    }

}
// 建树
void build(int u, int l, int r) {
    if(l == r) tr[u] = {l, r, w[r], 0};
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
    LL sum(0);
    if(l <= mid) sum = query(ls(u), l, r);
    if(r > mid ) sum += query(rs(u), l, r);
    return sum;
}
void solve() {
    cin>>n>>m; 
    for(int i = 1; i <= n; ++i) cin>>w[i];
    build(1, 1, n);
    // cout<<tr[1].sum<<endl;
    int xx, yy;
    int op;
    while(m--) {
        cin>>op>>xx>>yy;
        if(op == 1) {
            cin>>op;
            modify(1, xx, yy, op);
        } else {
            cout<<query(1, xx, yy); puts("");
        }
    }
}
/**
 * 建树时 向下回溯对父节点进行更新
 * modily时 向下回溯要先对左右节点进行更新，之后再对父节点进行更新
 * query时 向下回溯要先对左右节点进行更新
 * 
*/

}}




namespace golitter {
namespace LCA {

const int N = 10e5 + 21;
const int M = 2*N;
int h[M],e[M],ne[M],idx;
int dep[N],root,n,m,t;
int fa[N][20];
void add(int u,int v) { //
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}
void bfs() { // 找深度 + 预处理
    memset(dep, 0x3f, sizeof(dep));
    dep[0] = 0, dep[root] = 1;
    queue<int> q;
    q.push(root);
    while (q.size())
    {
        int x = q.front(); q.pop();
        for(int i = h[x]; ~i; i = ne[i]) {
            int y = e[i];
            if(dep[y] > dep[x]) {
                dep[y] = dep[x] + 1;
                q.push(y);
                fa[y][0] = x;
                for(int k = 1; k <= t; k++) {
                    fa[y][k] = fa[ fa[y][k-1]][k-1];
                }
            }
        }
    }
    
}
int lca(int x, int y) {
    if(dep[y] > dep[x]) swap(x,y); // 让x深度最大，从x到y找
    for(int k = t; k >= 0; --k) {
        if(dep[ fa[x][k]] >= dep[y]) x = fa[x][k];
    }
    if(x == y) return x;
    for(int k = t; k >= 0; --k) {
        if(fa[x][k] != fa[y][k]) {
            x = fa[x][k], y = fa[y][k];
        }
    }
    return fa[x][0];
}
void solve() {
    t = 15;
    cin>>n>>m>>root;
    memset(h, -1, sizeof(h));
    for(int i = 1; i < n; ++i) {
        int u,v; cin>>u>>v;
        add(u,v); add(v,u);
    }
    bfs();
    for(int i  = 0; i < m; ++i) {
        int u,v; cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
}

}}


namespace golitter {
namespace DisjointSet {
#include <unordered_map>

const int N = 234;
int fa[N];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void solve() {
    int n,m; cin>>n>>m;
    for(int i = 1; i <= n; ++i) fa[i] = i;
    while(m--) {
        int a,b; char opt[2];
        scanf("%s%d%d", opt, &a, &b);
        if(opt[0] == 'M') {
            fa[find(a)] = find(b); // 合并
        } else {
            if(find(a) == find(b)) {
                puts("Yes");
            } else puts("No");
        }
    }
}

/**
 * 离散化处理：
 *      https://www.acwing.com/solution/content/112727/
 * int find(int x ,unordered<int,int>& umii) {
 *      return umii[x] == x ? x : umii[x] = find(umii[x], umii);
 * }
 * 合并： umii[ find(x, umii)] = umii[ find(y, umii)];
 * 判断是否联通： find(x, umii) == find(y, umii)
*/

}}

namespace golitter {
namespace block {
/**
 * 
 * https://www.bilibili.com/video/BV1ms411t7xu/?spm_id_from=333.337.search-card.all.click&vd_source=13dfbe5ed2deada83969fafa995ccff6
 * 
 * belong 表示这个数在哪个块里面
 * block 块大小
 * lb 数所在的左边界
 * rb 数所在的右边界
 * 
*/
const int N = 2e5 + 21;
int belong[N], block, lb[N], rb[N],n,num;
void build() {
    block = sqrt(n);
    num = n / block; if(n%block) num++;
    for(int i = 1; i <= num; ++i) {
        lb[i] = (i-1)*block + 1, rb[i] = min(i*block, n);
    }
    for(int i = 1; i <= n; ++i) {
        belong[i] = (i-1)/block + 1;
    }
}   

}}


void inpfile() {
    #define mytest
    #ifdef mytest
    freopen("ANSWER.txt", "w",stdout);
    #endif
}
