[Problem - G - Codeforces](https://codeforces.com/contest/1899/problem/G)

题目大意：给一个以1为根的有根树，和一个排列p，q次询问。每次询问给出`l, r, x`，问在以x为根的子树内是否存在一个节点在排列`[pl, pr]`内。

思路：子树节点处理是dfs序。问题转换为在`[pl, pr]`内是否有值在以x为根的子树内存在。

可以离线处理出`[p1, pr]`和`[1, p(l-1)]`内的值在以x为根的子树内的个数，通过判断这两个区间的值是否相等进而可以得到是否以x为根的子树在排列`[pl, pr]`内存在。

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
/**
 * https://zhuanlan.zhihu.com/p/667469838
 * 只需要求出前缀[1, r] 和前缀[1, l-1]里区间内点的个数,如果相等,说明区间[l, r] 内没有新增的点,所以离线下来用树状数组维护一下区间和即可
*/

template <class T>
struct Fenwick { 
    int n;
    vector<T> a;
    Fenwick(const int &n = 0) : n(n), a(n, T()) {}
    void modify(int i, T x) {
        for (i++; i <= n; i += i & -i) {
            a[i - 1] += x;
        }
    }
    T get(int i) {
        T res = T();
        for (; i > 0; i -= i & -i) {
            res += a[i - 1];
        }
        return res;
    }
    T sum(int l, int r) { // [l, r] *这里已经改过
        return get(r + 1) - get(l);
    }
    int kth(T k) {
        int x = 0;
        for (int i = 1 << __lg(n); i; i >>= 1) {
            if (x + i <= n && k >= a[x + i - 1]) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};

void inpfile();
void solve() {
	int n,q; cin>>n>>q;
	vector<vector<int>> g(n + 1);
	for(int i = 1; i < n; ++i) {
		int u,v; cin>>u>>v;
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
    dfs(dfs, 1,-1);

    // 读入排列
	vector<int> p(n + 1);
	for(int i = 1; i <= n; ++i) cin>>p[i];

    // 离线答案，[1, l - 1] 和 [1, r] 内
	vector<array<int,2>> ans(q + 1);
	vector<vector<array<int,3>>> qry(n + 1);
    // 离线读入询问操作
	for(int i = 1; i <= q; ++i) {
		int l,r,x; cin>>l>>r>>x;
        // 向l-1内存入 l范围的信息
		qry[l-1].push_back({x, i, 0});
        // 向r内存入 r范围的信息
		qry[r].push_back({x, i, 1});
	}
	Fenwick<int> tr(n + 1);

	for(int i = 1; i <= n; ++i) { // 按从1到n进行处理
		tr.modify(l[p[i]], 1);
		for(auto tmp: qry[i]) {
            // x是以x为根的子树，id是询问id，k表示是l范围还是r范围内的信息
			int x = tmp[0], id =tmp[1], k = tmp[2];
            // 向第id个答案的l或r范围内存入信息， [1, l - 1] 或 [1, r] 的信息
			ans[id][k] = tr.sum(l[x], r[x]);
		}
	}
	for(int i = 1; i <= q; ++i) {
        // 如果 [1, l - 1] 和 [1, r] 的值相同，表示以x为根的子树的节点内没有 [l, r] 范围的排列值
		puts(ans[i][0] != ans[i][1] ? "YES" : "NO");
	}
	puts("");
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







[Codeforces Round 909 (Div. 3) A - G - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/667469838)