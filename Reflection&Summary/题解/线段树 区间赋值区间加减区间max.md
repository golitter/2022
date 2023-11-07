线段树好题：[P1253 扶苏的问题 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1253)

区间赋值 + 区间加减 + 求区间最大。



对于区间赋值和区间加减来说，需要两个懒标记，一个表示赋值`cover`，一个表示加减`add`。

区间赋值的优先级大于区间加减。

对于区间赋值来说，需要将区间加减的标记重置，因为赋值完后，之前的区间加减队现在的值没有影响。

```cpp
void coverdown(int u) {
    auto &root = tr[u], &right = tr[rs(u)], &left = tr[ls(u)];
    if(root.cover != -INF) {
        left.add = right.add = 0;
        left.ma = right.ma = root.cover;
        left.cover = right.cover = root.cover;
        root.cover = -INF;
    }
}
```



对于区间加减来说，需要先用区间赋值得到最新的值，之后再进行加减操作。

```cpp
void sumdown(int u) {
    auto &root = tr[u], &right = tr[rs(u)], &left = tr[ls(u)];
    if(root.add) {
        coverdown(u);
        left.ma += root.add; right.ma += root.add;
        left.add += root.add; right.add += root.add;
        root.add = 0;
    }    
}
```

线段树中一般的pushdown的顺序不变，但是在pushdown函数中，需要先执行coverdown再执行sumdown。

```cpp
void pushdown(int u) {
    coverdown(u); sumdown(u);
}
```

区间加减时，只需要先进行区间赋值就行。

```cpp
void modify_add(int u, int l, int r, int d) {
    if(tr[u].l >= l && tr[u].r <= r) {
        coverdown(u);
        tr[u].ma += d;
        tr[u].add += d;
    }
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify_add(ls(u), l ,r, d);
        if(r > mid) modify_add(rs(u), l, r, d);
        pushup(u);
    }
}
```

区间赋值时，需要先将区间加减懒标记重置，其他一样。

```cpp
void modify_cover(int u, int l, int r, int d) {
    if(tr[u].l >= l && tr[u].r <= r) {
        tr[u].add = 0;
        tr[u].ma = d;
        tr[u].cover = d;
    } else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify_cover(ls(u), l, r, d);
        if(r > mid) modify_cover(rs(u), l, r, d);
        pushup(u);
    }
}
```



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
#define IOS std::cout.tie(0);std::cin.tie(0)->sync_with_stdio(false);
#define dbgnb(a) std::cout << #a << " = " << a << '\n';
#define dbgtt cout<<" !!!test!!! "<<endl;
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

const int INF = 1e18;
const int N = 1e6 + 21;


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

int w[N],n,m; // 注意 w[N] 开LL ( https://www.luogu.com.cn/problem/P2357
struct adt {
    int l,r;
    int ma,add,cover;
}tr[N << 2];
// 左子树
inline int ls(int p) {return p<<1; }
// 右子树
inline int rs(int p) {return p<<1|1; }
// 向上更新
void pushup(int u) {
    tr[u].ma = max(tr[ls(u)].ma, tr[rs(u)].ma);
}

void coverdown(int u) {
    auto &root = tr[u], &right = tr[rs(u)], &left = tr[ls(u)];
    if(root.cover != -INF) {
        left.add = right.add = 0;
        left.ma = right.ma = root.cover;
        left.cover = right.cover = root.cover;
        root.cover = -INF;
    }
}
void sumdown(int u) {
    auto &root = tr[u], &right = tr[rs(u)], &left = tr[ls(u)];
    if(root.add) {
        coverdown(u);
        left.ma += root.add; right.ma += root.add;
        left.add += root.add; right.add += root.add;
        root.add = 0;
    }    
}
void pushdown(int u) {
    coverdown(u); sumdown(u);
}
// 建树
void build(int u, int l, int r) {
    if(l == r) tr[u] = {l, r, w[r], 0, -INF};
    else {
        tr[u] = {l,r, 0, 0, -INF}; // 容易忘
        int mid = l + r >> 1;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
        pushup(u);
    }
}
// 修改
void modify_add(int u, int l, int r, int d) {
    if(tr[u].l >= l && tr[u].r <= r) {
        coverdown(u);
        tr[u].ma += d;
        tr[u].add += d;
    }
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify_add(ls(u), l ,r, d);
        if(r > mid) modify_add(rs(u), l, r, d);
        pushup(u);
    }
}
void modify_cover(int u, int l, int r, int d) {
    if(tr[u].l >= l && tr[u].r <= r) {
        tr[u].add = 0;
        tr[u].ma = d;
        tr[u].cover = d;
    } else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify_cover(ls(u), l, r, d);
        if(r > mid) modify_cover(rs(u), l, r, d);
        pushup(u);
    }
}
// 查询
LL query(int u, int l, int r) {
    if(tr[u].l >= l && tr[u].r <= r) {
        return tr[u].ma;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    LL res = -INF;
    if(l <= mid) res = query(ls(u), l, r);
    if(r > mid ) res =max(res, query(rs(u), l, r));
    return res;
}

void inpfile();
void solve() {
    int n,q; cin>>n>>q;
    for(int i = 1; i <= n; ++i) w[i] = fread();
    build(1,1,n);
    while(q--) {
        // int opt,l,r,x; cin>>opt>>l>>r;
        int opt = fread(), l = fread(), r = fread();
        if(opt == 1) {
            // cin>>x;
            int x = fread();
            modify_cover(1,l,r,x);
        } else if(opt == 2) {
            // cin>>x;
            int x = fread();
            modify_add(1,l,r,x);
        } else {
            cout<<query(1,l,r)<<'\n';
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

[记录详情 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/record/132389923)

![image-20231030001146973](C:\Users\19819\AppData\Roaming\Typora\typora-user-images\image-20231030001146973.png)



[P1253 扶苏的问题 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/solution/P1253)