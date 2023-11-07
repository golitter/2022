这一题数据范围很小，根据题意打表就行（

这里提供一个非打表的题解。

将每个豆子看成n行字符串。第`x`级豆子的行数是第`x - 1`级豆子行数的两倍。好豆子的前n行是由第`x - 1`级的两个坏豆子拼接得到，后n行是由第`x - 1`级坏豆子和好豆子拼接得到；坏豆子同理。

考虑用`map`将第`x`级和对应好豆子、坏豆子进行映射，第1级进行预处理，从2开始依次进行拼接即可。

```cpp
void solve() {
	int n; cin>>n;
	// 第x级的 好豆子、坏豆子
	map<int,vector<string>> good, bad;
	// 第1级的手动敲（
	good[1].push_back("**");
	good[1].push_back("*.");
	bad[1].push_back("..");
	bad[1].push_back(".*");
	// 从2到4处理
	for(int i = 2; i <= 4; ++i) {
		// 得到前一级的好豆子、坏豆子的字符串
		auto g = good[i-1], b = bad[i-1];
		// 先处理好豆子
		for(auto &t: b) {
			// 坏 + 坏
			string s = t + t;
			good[i].push_back(s);
		}
		for(int j = 0; j < g.size(); ++j) {
			// 坏 + 好
			string s = b[j] + g[j];
			good[i].push_back(s);
		}

		// 处理坏豆子
		for(auto &t: g) {
			// 好 + 好
			string s = t + t;
			bad[i].push_back(s);
		}
		for(int j = 0; j < g.size(); ++j) {
			// 好 + 坏
			string s = g[j] + b[j];
			bad[i].push_back(s);
		}
	}
	// 输出
	for(auto &t: good[n]) {
		cout<<t<<endl;
	}
}
```

