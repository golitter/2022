[Problem - C - Codeforces](https://codeforces.com/contest/1623/problem/C)

问题描述：给一个长度为n的数组。执行以下操作：i 从3 到 n 遍历，每次选择一个d，满足`0<=3d<=a[i] , a[i] -= 3d,a[i-1] += d , a[i-2] += 2d`。
$$
满足条件：3d \in [0, \quad a[i]]有： \\
a[i] -= 3d \\
a[i-1] += d \\
a[i-2] += 2d
$$
求数组中最小值的最大值。

思路：最小值最大值，二分答案。每一次都尽可能减去满足条件的最大的`d`。如果按照题意进行顺序进行操作，会发现在当前位置满足`a[i] > mid`的条件难以判断；倒序进行则可以将这个给轻松判断。

**注意：虽然是倒叙，但是实际操作还是按照题意的正序操作。所以`d_max = a[i] / 3`，因为如果`3d > a[i]`对于题意正序操作来说是错误的，当前`a[i]`只能往前移动最多`a[i]`个，其余的都不是i位置的，而是，它后面元素向前移动的。**

代码：

```cpp
void solve() {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &t: a) cin>>t;
	auto check = [&](int mid) -> bool {
		auto b(a);
		for(int i = n-1; i >= 2; --i) {
			if(b[i] < mid) return false;
			int d = min(a[i] / 3, (b[i] - mid) / 3);
			b[i-1] += d;
			b[i-2] += 2 * d;
		}
		return b[0] >= mid && b[1] >= mid;
	};
	int l = 0, r = 1e9;
	while(l < r) {
		int mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout<<l<<endl;
}
```



