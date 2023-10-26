# E. Power of Points

[Problem - 1857E - Codeforces](https://codeforces.com/problemset/problem/1857/E)

题意：

给你 $n$ 个点，其整数坐标为 $x_1,\dots x_n$，它们位于一条数线上。

对于某个整数$s$，我们构建线段\[$s,x_1$\], \[$s,x_2$\],$\dots$,\[$s,x_n$\]。注意，如果是$x_i&lt;s$，那么线段看起来就像\[$x_i,s$\]。线段\[$a, b$\] 覆盖了所有的整数点$a, a+1, a+2, \dots, b$。

我们把点 $p$ 的幂定义为与坐标 $p$ 的点相交的线段数，记为 $f_p$。

你的任务是计算每个 $s \in \{x_1,\dots,x_n\}$ 的 $\sum\limits_{p=1}^{10^9}f_p$ ，即从 $1$ 到 $10^9$ 所有整数点的 $f_p$ 之和。

例如，如果初始坐标为 $[1,2,5,7,1]$，我们选择 $s=5$，那么线段将是$[1,5]$,$[2,5]$,$[5,5]$,$[5,7]$,$[1,5]$.这些点的幂将是$f_1=2, f_2=3, f_3=3, f_4=3, f_5=5, f_6=1, f_7=1, f_8=0, \dots, f_{10^9}=0$.它们的和为 $2+3+3+3+5+1+1=18$。

思路：说了这么多就是对每个xi求一个值，这个值得定义是：
$$
\sum_i^n( | p - x_i| + 1)
$$
带绝对值不好计算。取绝对值之后就有两种。

- `p > xi`

$$
\sum_i^k(p - x_i + 1) = k * p - \sum_i^k(x_i) - k
$$

- `p < xi`

$$
\sum_i^k(x_i - p + 1) = \sum_i^k(x_i) - (n - k + 1) * p + n - k
$$

对这两个式子进行观察，发现每次加一其实就是`n`，之后前面得`p - xi` 和 `xi - p`其实就是前后缀跟p操作一系列操作的结果。
$$
\sum_i^n(|x_k - x_i| + 1) = k * x_k - \sum_i^k(x_i) + \sum_k^n(x_i) - (n - i + 1) * x_k + n
$$


进而转换为：排序后对第k个，`k * xk - pre[k]`，`suf[k] - (n - k + 1) * xk`，`n`的相加结果。

代码（记得LL）：

```cpp
void solve() {
    int n; cin>>n;
    vector<PII> a(n + 21);
    for(int i = 1; i <= n ;++i) {
        int t; cin>>t;
        a[i] = {t,i};
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    vector<int> pre(n + 21), suf(n + 21);
    for(int i = 1; i <= n; ++i) {
        pre[i] = pre[i-1] + a[i].vf;
    }
    for(int i = n; i >= 1; --i) {
        suf[i] = suf[i+1] + a[i].vf;
    }
    vector<int> ans(n + 21);
    for(int i = 1; i <= n; ++i) {
        int x = a[i].vf;
        int pr = i * x - pre[i] + n;
        int sf = suf[i] - (n - i + 1) * x;
        ans[a[i].vs] = pr + sf;
    }
    for(int i = 1; i <= n; ++i) cout<<ans[i]<<" \n"[i == n];
}
```



# C. Pull Your Luck

[Problem - 1804C - Codeforces](https://codeforces.com/problemset/problem/1804/C)

题意：

![image-20231002235053424](https://cdn.789ak.com/img/image-20231002235053424.png)

思路：当等于2n时：
$$
f(2n) = \frac{2n(2n + 1)}{2} = n(2n + 1)
$$
此时，`(x + f(2n)) %n == x`进行循环，因此进行枚举即可。

```python
_ = int(input())
for __ in range(_):
    n,x,p = list(map(int, input().split(" ")))
    ok = False
    for i in range(1,min(2 * n, p) + 1):
        k = i * (i + 1) // 2
        if((k + x) % n == 0):
            ok = True
            break
    
    print("Yes" if ok else "No")
```

[CF1804C Pull Your Luck - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/solution/CF1804C)



# F. Range Update Point Query

[Problem - 1791F - Codeforces](https://codeforces.com/problemset/problem/1791/F)

![image-20231002235621960](https://cdn.789ak.com/img/image-20231002235621960.png)

## 解法一：线段树

区间修改用暴力，如果区间内都是小于10的表示这个区间不用再进行操作，可以知道这个每个位置的操作最多2、3次就不再进行操作。

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

int calc(int x) {
    int tmp = 0; while(x) {tmp += x % 10; x /= 10; } return tmp;
}
int w[N],n,m; // 注意 w[N] 开LL ( https://www.luogu.com.cn/problem/P2357
struct SegTree {
    int l,r,val,tag;
}tr[N << 2];
// 左子树
inline int ls(int p) {return p<<1; }
// 右子树
inline int rs(int p) {return p<<1|1; }
// 向上更新
void pushup(int u) {
    tr[u].tag = tr[ls(u)].tag & tr[rs(u)].tag;
}

// 建树
void build(int u, int l, int r) {
    if(l == r) {
        tr[u] = {l,r,w[l], w[l] < 10};
    }
    else {
        tr[u] = {l,r}; // 容易忘
        int mid = l + r >> 1;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
        pushup(u);
    }
}
// 修改
void modify(int u, int l, int r) {
    if(tr[u].l >= l && tr[u].r <= r && tr[u].tag) {
        return ;
    }
    if(tr[u].l == tr[u].r) {
        tr[u].val = calc(tr[u].val);
        tr[u].tag = tr[u].val < 10;
        return ;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if(l <= mid) modify(ls(u), l, r);
    if(r > mid) modify(rs(u), l, r);
    pushup(u);
}
// 查询
LL query(int u, int l, int r) {
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].val;
    int mid = tr[u].l + tr[u].r >> 1;
    if(l <= mid) return query(ls(u), l,r);
    return query(rs(u), l, r);
}
void solve() {
    cin>>n>>m;
    for(int i = 1; i <= n; ++i) cin>>w[i];
    build(1, 1, n);
    while(m--) {
        int op,l,r; cin>>op;
        if(op == 1) {
            cin>>l>>r;
            modify(1,l,r);
        } else {
            cin>>l;
            cout<<query(1,l,l)<<endl;
        }
    }
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

## 解法二

其实可能就是解法一的简化版。因为每个位置最多操作2次就不再进行操作了，只需要维护一个还需要进行操作的一个元素下标，每次区间操作对这个还要操作的元素下标进行查找，复杂度线段树差不多。

**注意：对set用lower_bound函数时一定要用set自带的，`s.lower_bound(l)`，而不是`lower_bound(all(s), l)`，这题亲测会TLE3（**

```cpp
void solve() {
    int n,q; cin>>n>>q;
    vector<int> a(n + 1);
    set<int> s;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        if(a[i] >= 10) s.insert(i);
    }
    auto calc = [&](int x) -> int {
        int tmp = 0;
        while(x) {
            tmp += x % 10;
            x /= 10;
        }
        return tmp;
    };
    while(q--) {
        int op,l,r;
        cin>>op;
        if(op == 1) {
            cin>>l>>r;
            auto t = s.lower_bound(l);
            while(t != s.end() && *t <= r) {
                l = *t;
                a[l] = calc(a[l]);
                if(a[l] < 10) {
                    s.erase(l);
                }
                t = s.lower_bound(l+1);
            }
        } else {
            cin>>l;
            cout<<a[l]<<endl;
        }
    }
}
```

