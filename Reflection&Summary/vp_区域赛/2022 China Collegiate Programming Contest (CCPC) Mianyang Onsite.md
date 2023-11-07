[Dashboard - 2022 China Collegiate Programming Contest (CCPC) Mianyang Onsite - Codeforces](https://codeforces.com/gym/104065)

# C. Catch You Catch Me

从1的儿子结点开始求深度即可。

```cpp
void solve() {
	int n; cin>>n;
	vector<vector<int>> g(n + 1);
	for(int i = 2; i <= n; ++i) {
		int u,v; cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 0;
	for(auto y: g[1]) {
		if(y == 1) continue;
		int dep = 0;
		auto dfs = [&](auto &&self, int u, int fu, int d) -> void {
			dep = max(dep, d);
			for(auto x: g[u]) {
				if(x == fu) continue;
				self(self, x, u, d + 1);
			}
		};
		dfs(dfs, y,1, 1);
		ans += dep;
	}
	cout<<ans<<endl;
}
```

# G. Let Them Eat Cake

按题意进行模拟即可。时间复杂度是`O(nlogn)`，因为每次两个基本上是有一个是要删除的，大概的时间复杂度为`O(nlogn)`，可过。

注意只有一个数的处理。

```cpp
void solve() {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &t: a) cin>>t;
	int last = n, cnt = 0;
	while(1) {
		if(last == 1) break;
		cnt++;
		vector<int> b;
		for(int i = 0; i < last; ++i) {
			if(i == 0) {
				if(a[i + 1] < a[i]) b.push_back(a[i]);
			} else if(i == last - 1) {
				if(a[i-1] < a[i]) b.push_back(a[i]);
			} else {
				if(a[i - 1] < a[i] && a[i + 1] < a[i]) b.push_back(a[i]);
			}
		}
		a = b;
		last = a.size();
	}
	cout<<cnt<<'\n';
}
```

# H. Life is Hard and Undecidable, but...

对角线完美满足所有条件。

```cpp
void solve() {
	int k; cin>>k;
	int n = 2 * k - 1;
	cout<<n<<'\n';
	for(int i = 1; i <= n; ++i) cout<<i<<' '<<i<<'\n';
}
```

# M. Rock-Paper-Scissors Pyramid

最后的一个一定是在整个过程中赢的次数最多的。

同时，由于从多到少，那么它一定是从其当前位赢了往上它前面的，且在后面也没有输。可以用一个栈来维护赢了前面的符合或者下标。

```cpp
void solve() {
	string s; cin>>s;
	vector<int> a;
	int len = s.size();
	// 后一个赢前一个
	auto check = [&](char pre, char suf) -> bool {
		if(pre == 'R' && suf == 'P') return 1;
		if(pre == 'P' && suf == 'S') return 1;
		if(pre == 'S' && suf == 'R') return 1;
		return 0;
	};
	for(int i = 0; i < len; ++i) {
		while(a.size() && check(s[a.back()], s[i])) a.pop_back();
		a.push_back(i);
	}
	cout<<s[a[0]]<<'\n';
}
```











[2022中国大学生程序设计竞赛(绵阳站)题解 - China Collegiate Programming Contest 2022 (Mianyang Site) Tutorial (codeforces.com)](https://codeforces.com/gym/104065/attachments/download/17935/CCPC_2022_Mianyang_Tutorial.pdf)

