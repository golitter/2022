[Problem - 1481C - Codeforces](https://codeforces.com/problemset/problem/1481/C)

![image-20231213205011448](C.%20Fence%20Painting.assets/image-20231213205011448.png)

思路：逆序考虑，因为每一块木板都是被最后一次粉刷所决定的。

从后往前开始，对于$c_i$来说，

- 如果这个颜色还有没有涂的木板，那么涂到其中一个木板即可
- 如果这个颜色下没有未涂的木板，找到一个已经土过的木板
- 如果这个颜色没有被涂，且没有已经被涂的木板，那么涂到一个相同木板上
- 如果这个颜色没有被涂，却没有已经被涂的木板，同时也没有相同木板，那么**无解**。

最后再检验一下，是否可行即可。

代码如下：

```cpp
void solve() {
	int n,m; cin>>n>>m;
	bool ok = true;
	int pos = -1;
	vector<int> a(n + 1), b(a), c(m + 1),ans(m + 1), e(n + 1, -1);
	/**
	 * ans存第j个人涂哪个木板
	 * e存第z个颜色的最远位置
	*/
	vector<vector<int>> g(n + 1);
	for(int i = 1 ; i <= n; ++i) cin>>a[i];
	for(int i = 1; i <= n; ++i) cin>>b[i];
	for(int i = 1; i <= m; ++i) cin>>c[i];
	for(int i = 1;  i <= n; ++i) {
		// 不相同表示，需要更改，先进行标记
		if(a[i] != b[i]) g[b[i]].push_back(i);
		e[b[i]] = i;
	}

	for(int i = m; i >= 1; --i) {
		// 现在木板中，没有将木板颜色更改为ci的需求
		if(g[c[i]].size() == 0) {
			// 如果是-1，表示没有已经被涂色的
			if(pos == -1) {
				// 如果这个ci颜色在木板中不存在，结束
				if(e[c[i]] == -1) {
					ok = false;
					break;
				}
				// 否则涂到相同木板上
				pos = e[c[i]];
			}
		} else {
			// 位置更新
			pos = g[c[i]].back();
			g[c[i]].pop_back();
			a[pos] = b[pos];
		}
		// 第i个人要涂的位置
		ans[i] = pos;
	}

	// 检查一下是否符合
	for(int i = 1; i <= n; ++i) ok &= a[i] == b[i];
	if(ok) {
		cout<<"YES\n";
		for(int i = 1; i <= m; ++i) cout<<ans[i]<<" \n"[i == m];
	} else cout<<"NO\n";
}
```



[CF1481C Fence Painting - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/solution/CF1481C)