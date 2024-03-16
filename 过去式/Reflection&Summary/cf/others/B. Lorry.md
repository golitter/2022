[Problem - B - Codeforces](https://codeforces.com/contest/3/problem/B)

题目大意：给物品数量$n$，体积为$v_{(0 \le v \le 1e9)}$，第一行读入$n, v$，之后$n$行，读入$n$个物品，之后每行依次是体积和价值，其中**体积要么是1要么是2**。要求输出价值和最大，且依次输出所选物品的编号。

思路：发现，体积$v$很大，用01背包一定不行，01背包优化的事件复杂度是$O(v)$，也过不去。但是发现物品的体积**要么是1要么是2**。我们可以将物品按其体积分为两类，分别表示体积为1的物品和体积为2的物品。之后对于相同体积的物品来说，我们优先考虑其**价值最大的那个**，所以要对物品进行排序。之后枚举物品体积为1的数量$i$，得到在物品体积为1的数量$i$的条件下，得到的最大值，不断的进行更新即可。

代码如下：

```cpp
void solve() {
	int n,V; cin>>n>>V;
	// [0, 0] -> 物品价值，物品编号
	vector<array<int,2>> t1, t2;
	t1.push_back({0, 0});
	t2.push_back({0, 0});
	for(int i = 0; i < n; ++i) {
		int v, w; cin>>v>>w;
		if(v == 1) t1.push_back({w, i + 1});
		else t2.push_back({w, i + 1});
	}
	// 得到物品体积为1的数量，和2的数量
	int len1 = t1.size() - 1, len2 = t2.size() - 1;

	// 对物品按照价值从大到小进行排序
	sort(t1.begin() + 1, t1.end(), [&](auto pre, auto suf) {
		return pre[0] > suf[0];
	});
	sort(t2.begin() + 1, t2.end(), [&](auto pre, auto suf) {
		return pre[0] > suf[0];
	});
	// 得到体积为2的物品的前缀和
	vector<int> pre(len2 + 1);
	for(int i = 1; i <= len2; ++i) {
		pre[i] = pre[i - 1] + t2[i][0];
	}
	// 最大值，当前体积为1的物品之和
	int ma = 0, sum = 0;
	// 最大值时体积为的个数和体积为2的个数
	int ans1 = 0, ans2 = 0;
	// 枚举体积为1的数量，得到最大值
	for(int i = 0; i <= len1; ++i) {
		if(i > V) break;
		int j = min( (V - i) / 2, len2);
		sum += t1[i][0];
		if(sum + pre[j] > ma) {
			ma = sum + pre[j];
			ans1 = i; ans2 = j;
		}
	}
	// 输出即可
	cout<<ma<<'\n';
	for(int i = 1; i <= ans1; ++i) cout<<t1[i][1]<<' ';
	for(int i = 1; i <= ans2; ++i) cout<<t2[i][1]<<' ';
}
```

刚开始写的时候，发现定义比较麻烦，就用了map进行映射，发现要处理边界问题，还不如上面简介呢（

```cpp
void solve() {
	int n,v; cin>>n>>v;
	map<int, vector<array<int,2>> > mp;
	for(int i = 0; i < n; ++i) {
		int v,w; cin>>v>>w;
		mp[v].push_back({w, i + 1});
	}
	for(int i = 1; i < 3; ++i) {
		sort(all(mp[i]), [&](auto pre, auto suf) {
			return pre[0] > suf[0];
		});
	}
	int vlen2 = mp[2].size();
	vector<int> pre(vlen2 + 1);
	auto v2(mp[2]);
	for(int i = 0; i < vlen2; ++i) {
		pre[i + 1] = pre[i] + v2[i][0];
	}
	int sum = 0, ma = 0, need1 = 0, need2 = 0;
	auto v1(mp[1]);
	int vlen1 = n - vlen2;
	ma = pre[min(v / 2, vlen2)]; need2 = min(v / 2, vlen2);
	for(int i = 1; i <= vlen1; ++i) {
		if(i > v) break;
		sum += v1[i-1][0];
		int j = min( (v - i) / 2, vlen2);
		if(sum + pre[j] >  ma) {
			ma = sum + pre[j];
			need1 = i; need2 = j;
		}
	}
	cout<<ma<<'\n';
	for(int i = 0; i < need1; ++i) {
		cout<<v1[i][1]<<' ';
	}
	for(int i = 0; i < need2; ++i) {
		cout<<v2[i][1]<<' ';
	}
}
```



