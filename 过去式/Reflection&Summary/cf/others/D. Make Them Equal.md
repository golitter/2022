[Problem - D - Codeforces](https://codeforces.com/contest/1633/problem/D)

![image-20231115212247443](https://cdn.789ak.com/img/image-20231115212247443.png)

![image-20231115212306654](https://cdn.789ak.com/img/image-20231115212306654.png)

输出值不超过k次操作后的最大值。

看b数组的大小，b数组元素是小于1000的正整数。从1到bi如果可以，那么最多是大概10次的，因为是指数递增的，例如：1 -> 2 -> 4 -> 8 -> 16 -> 32 -> 64 -> 128 -> 256 -> 512 -> 1024。对于每个ai到bi的这个操作是互不影响的，同时ai操作一下但是不等于bi对答案没有贡献的，那么就可以把ai到bi的次数预处理出来，之后01背包。**从1到bi的操作次数当作01背包的体积，ci当作01背包的价值。**

发现01背包的话，k可能1e6，时间复杂度是`O(1e6 * 1e3)`，时间上不够，但是根据之前的发现，最多不超过11、12次就可以，因为k最多是`12 * 1000`，即`1e4`，现在时间复杂度是可以过这题的。

代码如下：

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
vector<int> v(1200, INF);
void inpfile();
void solve() {
	int n,k; cin>>n>>k;
	k = min(12000, k);
	vector<int> f(k + 1);
	vector<int> a(n + 1), w(n + 1);
	for(int i = 1; i <= n; ++i) {
		cin>>a[i];
		// 操作次数当作01背包的体积
		a[i] = v[ a[i]];
	}
	// ci作为01背包的价值
	for(int i = 1; i <= n; ++i) cin>>w[i];
	for(int i = 1; i <= n; ++i) {
		for(int j = k; j >= a[i]; --j) f[j] = max(f[j], f[j - a[i]] + w[i]);
	}
	cout<<f[k]<<'\n';
}
#ifdef int_to_long_long
signed main()
#else
int main()
#endif

{
	// 预处理出从1到u需要的最少次数
	v[1] = 0;
	for(int i = 1; i <= 1000; ++i) {
		for(int j = 1; j <= i; ++j) {
			int u = i + i / j;
			if(u <= 1000) v[u] = min(v[u], v[i] + 1);
		}
	}
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

