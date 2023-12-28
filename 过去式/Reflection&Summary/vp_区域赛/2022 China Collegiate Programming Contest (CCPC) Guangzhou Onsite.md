[Problem - E - Codeforces](https://codeforces.com/gym/104053/problem/E)

E. Elevator

题意：有一栋有`m`层的楼，有`n`部电梯从1到m。第`i`个电梯再`ai`时刻上升。每一层有一个按钮，可以让第一个到达该层的电梯停1秒，**如果有多个电梯同时到某一层，下标靠前的被视为第一台到的电梯。**

现在要求第i个可以第一个到`m`层楼至少要按多少次按钮，输出`i`为1到`n`的答案。

思路：离线处理 + 树状数组

用`array<int,2>`或者`PII`存入`ai`和`i`值，按照`ai`从小到大排序。按`ai`从小到大依次处理得到`i`的答案。

对于第`i`个下标来说，答案就是前面处理的数量 乘以 当前`ai` ， 之后 减去 前面处理的`aj`之和，再加上前面处理的下标在当前`i`前面的，因为它们是`ai - aj + 1`，而在当前下标之后的是`ai - aj`。

注意第一层和第`m`层按电梯没有用（

具体代码实现：

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
void solve() {
	int n,m; cin>>n>>m;
	Fenwick<int> tr(n + 1);
	vector<array<int,2>> sg(n);
	for(int i = 1; i <= n; ++i) {
		cin>>sg[i-1][0];
		sg[i-1][1] = i;
	}
	sort(all(sg));
	int sum = 0;
	vector<int> ans(n + 1);
	for(int i = 0; i < n; ++i) {
		int id = sg[i][1];
		int v = sg[i][0];
		sum += v;
		ans[id] = (v * (i + 1)) - sum + tr.sum(1,id);
		tr.modify(id, 1);
		if(ans[id] > m - 2) ans[id] = -1;
	}
	for(int i = 1; i <= n; ++i) cout<<ans[i]<<'\n';
}
#ifdef int_to_long_long
signed main()
#else
int main()
#endif

{
	IOS;
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

