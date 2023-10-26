2023年7月26日 22点53分

下午两点到6点进行的vp。

做出了4道，是铜尾水平。



I题，高精度。我用py写的。对python的字符串处理不了解，可能自己造了不少轮子在这道题上。赛时不知道`chr()`和`ord()`，一个是转字符，一个是将字符转ascii码，可惜赛时只知道`chr()`，导致`ord()`这个实现浪费了很多的时间。而且在缺少了特判（测试样例造少了），导致wa了两次。

```python
import sys
str = input()
a,b,c = str.split(' ')
a = int(a)
b = int(b)
d = 0

def reverse(str):
    s = ""
    n = len(str)
    for i in range(0,n):
        s += str[n - i - 1]
    return s

c = reverse(c)
tye = {}

i = 0
sk = '0123456789'
for ch in sk:
    tye[ch] = i
    i += 1
sk = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
for ch in sk:
    tye[ch] = i
    i += 1
sk = 'abcdefghijklmnopqrstuvwxyz'
for ch in sk:
    tye[ch] = i
    i += 1

# print()
# print(c)
def judge(c):
    if(tye[c] >= tye['0'] and tye[c] <= tye['9']): 
        return tye[c] - tye['0']
    elif(tye[c] >= tye['A'] and tye[c] <= tye['Z']): 
        return tye[c] - tye['A'] + 10
    else : 
        return tye[c] - tye['a'] + 36

def ret(i):
    asc = 0
    # print(type(i))
    if(i >= 0 and i <= 9) : 

        asc =  i + 48
    elif(i >= 10 and i <= 35): 
        asc = i - 10 + 65
    else : 
        asc = i - 36 + 97
    # print(i,asc)
    return chr(asc)

def other_10(c):
    p = 1
    d = 0
    for i in c:
        d += judge(i) * p
        p *= a
    return d

ans = ""
def ten_other(d):
    ans = ""
    # print(d)
    while d != 0:
        ans += ret(d % b)
        # print(d % b)
        # print(ret(d % b))
        # print(ret(d % b))
        # print(ans)
        d //= b
    return ans

d = other_10(c)
ans = ten_other(d)
# print(ans)    
# print()
n = len(ans)
for i in range(0, n):
    print(ans[n - i - 1],end='')
# ans = reverse(ans)
# print(ans)
if d == 0:
    print(0)
```

G题，队友处理出线段树，我套板子结束了。

```c++
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

// #define Multiple_groups_of_examples
#define IOS std::cout.tie(0);std::cin.tie(0)->sync_with_stdio(false);
#define dbgnb(a) std::cout << #a << " = " << a << '\n';
#define dbgtt cout<<" !!!test!!! "<<endl;
#define rep(i,x,n) for(int i = x; i <= n; i++)

#define all(x) (x).begin(),(x).end()
#define vf first
#define vs second

typedef long long LL;
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 21;


int w[N],n,m;
struct adt {
    int l,r;
    LL a,b,c,d,lazy_a,lazy_b,lazy_c,lazy_d;
    LL max_a,max_b,max_c,max_d;
}tr[N << 2];
// 左子树
inline int ls(int p) {return p<<1; }
// 右子树
inline int rs(int p) {return p<<1|1; }
// 向上更新
void pushup(int u) {
    tr[u].max_a = max(tr[ls(u)].max_a, tr[rs(u)].max_a);
    tr[u].max_b = max(tr[ls(u)].max_b, tr[rs(u)].max_b);
    tr[u].max_c = max(tr[ls(u)].max_c, tr[rs(u)].max_c);
    tr[u].max_d = max(tr[ls(u)].max_d, tr[rs(u)].max_d);
}
// 向下回溯时，先进行更新
void pushdown(int u) { // 懒标记，该节点曾经被修改，但其子节点尚未被更新。
    auto &root = tr[u], &right = tr[rs(u)], &left = tr[ls(u)];
    if(root.lazy_a) {
        right.lazy_a += root.lazy_a; right.max_a += root.lazy_a;
        left.lazy_a += root.lazy_a; left.max_a += root.lazy_a;
        root.lazy_a = 0;
    }
    if(root.lazy_b) {
        right.lazy_b += root.lazy_b; right.max_b += root.lazy_b;
        left.lazy_b += root.lazy_b; left.max_b += root.lazy_b;
        root.lazy_b = 0;
    }
    if(root.lazy_c) {
        right.lazy_c += root.lazy_c; right.max_c += root.lazy_c;
        left.lazy_c += root.lazy_c; left.max_c += root.lazy_c;
        root.lazy_c = 0;
    }
    if(root.lazy_d) {
        right.lazy_d += root.lazy_d; right.max_d += root.lazy_d;
        left.lazy_d += root.lazy_d; left.max_d += root.lazy_d;
        root.lazy_d = 0;
    }

}
// 建树
void build(int u, int l, int r) {
    if(l == r) tr[u] = {l, r, 0, 0,0,0,0,0,0,0,0,0,0,0};
    else {
        tr[u] = {l,r}; // 容易忘
        int mid = l + r >> 1;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
        pushup(u);
    }
}
// // 修改
// void modify(int u, int l, int r, int d, int x) {
//     if(tr[u].l >= l && tr[u].r <= r) {
//         tr[u].sum += (LL)(tr[u].r - tr[u].l + 1)*d;
//         tr[u].add += d;
//     }
//     else {
//         pushdown(u);
//         int mid = tr[u].l + tr[u].r >> 1;
//         if(l <= mid) modify(ls(u), l ,r, d);
//         if(r > mid) modify(rs(u), l, r, d);
//         pushup(u);
//     }
// }
void modify_for_a(int u, int l, int r, int d) {
    // dbgnb(tr[u].lazy_a)
    if(tr[u].l >= l && tr[u].r <= r) {
        tr[u].max_a += d;
        tr[u].lazy_a += d;
    } else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify_for_a(ls(u), l, r, d);
        if(r > mid) modify_for_a(rs(u), l, r,d);
        pushup(u);
    }
}
void modify_for_b(int u, int l, int r, int d) {
    if(tr[u].l >= l && tr[u].r <= r) {
        tr[u].max_b += d;
        tr[u].lazy_b += d;
    } else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify_for_b(ls(u), l, r, d);
        if(r > mid) modify_for_b(rs(u), l, r,d);
        pushup(u);
    }
}

void modify_for_c(int u, int l, int r, int d) {
    if(tr[u].l >= l && tr[u].r <= r) {
        tr[u].max_c += d;
        tr[u].lazy_c += d;
    } else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify_for_c(ls(u), l, r, d);
        if(r > mid) modify_for_c(rs(u), l, r,d);
        pushup(u);
    }
}

void modify_for_d(int u, int l, int r, int d) {
    if(tr[u].l >= l && tr[u].r <= r) {
        tr[u].max_d += d;
        tr[u].lazy_d += d;
    } else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify_for_d(ls(u), l, r, d);
        if(r > mid) modify_for_d(rs(u), l, r,d);
        pushup(u);
    }
}
// 查询
LL query(int u, int l, int r) {
    if(tr[u].l >= l && tr[u].r <= r) {
        return max( max(tr[u].max_a, tr[u].max_b), max(tr[u].max_c, tr[u].max_d));
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    LL ma = -INF;
    if(l <= mid) ma = max(ma, query(ls(u), l, r));
    if(r > mid ) ma = max(ma, query(rs(u), l, r));
    return ma;
}

void inpfile();
void solve() {
    int n,q; cin>>n>>q;
    build(1,1,n);
    string str; int l,r;
    for(int i = 0; i < q; ++i) {
        cin>>str>>l>>r;
        if(str == "MULTIPLY") {
            int x; cin>>x;
            if(x == 2) {
                modify_for_a(1,l,r,1);
            } else if(x == 3) {
                modify_for_b(1,l,r,1);
            } else if(x == 4) {
                modify_for_a(1,l,r,2);
            } else if(x == 5) {
                modify_for_c(1,l,r,1);
            } else if(x == 6) {
                modify_for_a(1,l,r,1);
                modify_for_b(1,l,r,1);
            } else if(x == 7) {
                modify_for_d(1,l,r,1);
            } else if(x == 8) {
                modify_for_a(1,l,r,3);
            } else if(x == 9) {
                modify_for_b(1,l,r,2);
            } else if(x == 10) {
                modify_for_a(1,l,r,1);
                modify_for_c(1,l,r,1);
            }

            // for(int i = 1; i<=n; ++i) cout<<tr[i].max_a<<" ";
            // puts("");
        } else {
            cout<<"ANSWER "<<query(1,l,r)<<endl;
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

其他题，队友a了。

### 总结

这次vp可以。感觉就是板子多点就好了，python精炼一下更好了。

还是特判问题，总是wa一次再ac。

下次注意特判吧。