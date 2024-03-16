[Problem - 199D - Codeforces](https://codeforces.com/problemset/problem/199/D)

题目大意：有一个两个垂直的平行墙壁组成的一个峡谷。一个人初始是在左边墙壁第一层。在每个墙壁上有些障碍点，用`X`表示，这些障碍点不能被到达。，他可以执行以下三个操作：

- 向当前墙壁往上爬一层
- 向当前墙壁往下爬一层
- 向对面墙壁往上爬`k`层

同时，初始时在第0层有水，他每次执行完以上任意一个操作后，水位会上升一层。求是否可以安全的到n层以上。

这题是一个游戏背景，可能描述的不够清晰，下面是`DeepL`的翻译：

![image-20231114153722099](https://cdn.789ak.com/img/image-20231114153722099.png)

这题是一个显然的搜索，用dfs或者bfs都可以实现。如果dfs和bfs都可以实现，用bfs会更好（

这题的思路就是：用一个队列存入每次的当前层数、水位层数和在左边还是在右边 这三个变量。之后的处理跟其他bfs没有太大区别，判断超界，当前位置小于水位位置就continue，根据在左墙壁或者在右墙壁进行判断即可。

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

void inpfile();
void solve() {
	// 这个代码是从0开始的，即 [0, n-1]
	int n,k; cin>>n>>k;
	string left,right; cin>>left>>right;
	vector<vector<int>> vis(2, vector<int>(n));
	vector<int> fx{1,-1, k}; // 三个操作
	queue<array<int,3>> q; // 当前位置，水位位置，左边还是右边
	q.push({0, 0, 0});
	// 布尔值，判断是否已经可以合法的大于等于n了，
	bool ok = false;

	// 开始bfs
	while(q.size()) {
		auto tmp = q.front(); q.pop();
		// 记录上次的位置，当前水位，上次在那个墙壁
		int last = tmp[0], water = tmp[1] + 1, fg = tmp[2];
		// 进行判断
		for(int i = 0; i < 3; ++i) {
			int now = last + fx[i];
			ok |= now >= n; // 如果now直接大于n了，表示可以

			// 判断是否超界
			if(now < 0 || now >= n) continue;
			// 判断是否现在位置 小于 水位  （等于水位可以
			if(now < water) continue;
			// 在左墙壁
			if(fg == 0) {
				if(i < 2) {
					// 已经到过了，或者这个位置不能到达
					if(vis[fg][now] || left[now] == 'X') continue;
					// 否则，入队
					vis[fg][now] = 1;
					q.push({now, water, 0});
				} else {
					// 也类似
					if(vis[!fg][now] || right[now] == 'X') continue;
					vis[!fg][now] = 1;
					q.push({now, water, 1});
				}
			} else { // 在右墙壁，同上
				if(i < 2) {
					if(vis[fg][now] || right[now] == 'X') continue;
					vis[fg][now] = 1;
					q.push({now, water, 1});
				} else {
					if(vis[!fg][now] || left[now] == 'X') continue;
					vis[!fg][now] = 1;
					q.push({now, water, 0});
				}
			}
		}
	}
	puts(ok ? "YES" : "NO");
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

