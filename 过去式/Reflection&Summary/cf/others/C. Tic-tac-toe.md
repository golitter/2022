[Problem - C - Codeforces](https://codeforces.com/contest/3/problem/C)

![image-20231126001519574](https://cdn.789ak.com/img/image-20231126001519574.png)

思路：搜索，判断合法性。从起始态用搜索进行模拟，这样可以避免后面判断合法性这一繁琐的步骤。用一个map进行映射当前态及对应的结果。剪枝：如果当前字符串已经被搜索过，则直接跳过去。

代码实现：

```cpp
void solve() {
	array<string, 3> st;
	cin>>st[0]>>st[1]>>st[2];
	array<string, 3> ph;
	ph[0] = "...";
	ph[1] = "..."; ph[2] = "...";
	map<array<string,3>, string> mp;
	// 判断是否赢
	auto check = [&](char ch) -> bool {
		// 行
		for(int i = 0; i < 3; ++i) {
			bool ok = true;
			for(int j = 0; j < 3; ++j) {
				ok &= ph[i][j] == ch;
			}
			if(ok) return 1;
		}
		// 列
		for(int i = 0; i < 3; ++i) {
			bool ok = true;
			for(int j = 0; j < 3; ++j) {
				ok &= ph[j][i] == ch;
			}
			if(ok) return 1;
		}
		// 对角线
		if(ph[0][0] == ch && ph[1][1] == ch && ph[2][2] == ch) return 1;
		if(ph[2][0] == ch && ph[1][1] == ch && ph[0][2] == ch) return 1;
		return 0;
	};

	// 先是A X
	// B 0
	// 从起始态进行搜索
	auto dfs = [&](auto&& self, int step) -> void {
		if(check('X')) {
			mp[ph] = "the first player won";
			return ;
		} else if(check('0')) {
			mp[ph] = "the second player won";
			return ;
		} else if(step == 9) {
			mp[ph] = "draw";
			return ;
		}
		mp[ph] = step % 2 == 0 ? "first" : "second";
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j) {
				if(ph[i][j] != '.') continue;
				ph[i][j] = step % 2 == 0 ? 'X' : '0';
				if(mp.find(ph) == mp.end())
					self(self, step + 1);
				ph[i][j] = '.';
			}
		}
	};
	dfs(dfs, 0);
	// 如果在合法态中没有找到就是非法的。
	if(mp.find(st) == mp.end()) cout<<"illegal";
	else {
		cout<<mp[st];
	}
}
```

