简单dfs（

题目已经给出是以1为根的有根树。

我们要知道1为根的树节点个数，就需要知道1的儿子节点的节点数之和是多少，要知道1的儿子节点的某一个以其为根的树的结点个数，就需要知道...。要想知道1的，就要知道以1的儿子结点为根的树的结点数是多少。因此用递归，对于`v`结点来说，递归找到以`v`为父亲的结点`{u1, u2, u3...u_n}`的结点个数，得到完`{u1,u2,u3...u_n}`后，`v`结点的个数就是`{u1,u2,u3...u_n}`的结点个数 加上 `v`本身。可能表述难以理解。

代码如下：

```cpp
void solve() {
	int n; cin>>n;
	// sz表示以u为根的结点个数
	vector<int> sz(n + 1);
	// 建立单向边，由于题中已经给明是 <父亲结点，儿子结点>
	vector<vector<int>> g(n + 1);
	for(int i = 2; i <= n; ++i) {
		int t; cin>>t;
		g[t].push_back(i);
	}
	// dfs
	auto dfs = [&](auto &&self, int u, int fu) -> void {
		// 本身是1
		sz[u] = 1;
		for(auto y: g[u]) {
			// 如果y这个点是u的父亲结点就重复了，不过这里由于是单向边，没有这个情况（
			if(y == fu) continue;
			// 先让u的儿子结点y递归，找y的结点个数
			self(self, y, u);
			// 加上y的结点个数
			sz[u] += sz[y];
		}
	};
	dfs(dfs, 1,-1);
	for(int i = 1; i <= n; ++i) cout<<sz[i]<<" ";
}
```

