[Problem - E - Codeforces](https://codeforces.com/contest/242/problem/E)

![image-20231114022626849](https://cdn.789ak.com/img/image-20231114022626849.png)

区间求和，区间异或的操作跟线段树的区间求和、区间相见相似，考虑用线段树。

发现数组初始值最多是1e6，有不到25位，可以知道异或最大值是这些位数全是1的情况。

发现可以对每一位进行运算就和。

我们开23个线段树表示每一位的情况，根据位运算求出每一位的贡献即可。

**注意ans需要开LL，且数组不能开大，不能全用`long long`**。

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
// #define int_to_long_long
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

// 异或 线段树板子
struct SegTree {
    static const int N = 1e5 + 21;
    struct node {
        int l, r;
        LL sum,lz;
    }tr[N << 2];
    // 左子树
	int w[N];
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
        if(root.lz) {
            right.lz ^=1; right.sum = (right.r - right.l + 1 - right.sum);
            left.lz ^= 1; left.sum = (left.r - left.l + 1 - left.sum);
            root.lz = 0;
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
            tr[u].lz ^= 1;
			tr[u].sum = (tr[u].r - tr[u].l + 1 - tr[u].sum);
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
}tree[23];

void inpfile();
void solve() {
	int n; cin>>n;
	vector<int> ad(n + 1);
	for(int i = 1; i <= n; ++i) cin>>ad[i];
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 22; ++j) {
			// ad[i] 的第j位是0还是1
			tree[j].w[i] = (ad[i] >> j) & 1;
		}
	}
	// 建树
	for(int i = 0; i < 22; ++i) tree[i].build(1,1,n);
	int q; cin>>q;
	while(q--) {
		int opt, x, y, v;
		cin>>opt>>x>>y;
		if(opt == 1) {
			LL ans = 0;
			// 求出每一位的贡献相加即为答案
			for(int i = 0; i < 22; ++i) ans += (LL)tree[i].query(1,x,y) * (1 << i);
			cout<<ans<<endl;
		} else {
			cin>>v;
			for(int i = 0; i < 22; ++i) {
				// 每一位进行修改
				int t = (v >> i) & 1;
				if(!t) continue;
				tree[i].modify(1,x,y,1);
			}
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

















[XOR on Segment - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/CF242E)

[CF242E XOR on Segment （拆位线段树）_牛客博客 (nowcoder.net)](https://blog.nowcoder.net/n/ef1e21e142f240f6b520795523c4ccce)