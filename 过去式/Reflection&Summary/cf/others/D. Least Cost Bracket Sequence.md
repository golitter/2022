[Problem - D - Codeforces](https://codeforces.com/contest/3/problem/D)

题目大意：给一个只包含`(`，`)`，`?`三个字符的字符串。每个`?`可以转为`(`或者`)`，对于第$i$个`?`转为`(`需要花费$a_i$，转为`)`需要花费$b_i$。现在问能否让该字符串转为合法的括号匹配，如果可以找到最小花费并输出转为的括号匹配。

思路：`?`的情况可以转为`(`，也可以转为`)`，是动态的，处理起来麻烦。我们可以将`?`全都先转为同一种，记录总花销，之后根据情况替换为另一个，这样虽然也是动态的，但是要维护的状态少了很多。

在此，将`?`先全部转为`)`，对于中间态而言，左边`(`可以多，但是`)`数量一定小于等于左边。用括号匹配的类似操作进行计数，`(`进行累加计数，对于其他的，如果是`?`先贪心的转为`)`，之后让计数减一。根据计数值进行贪心的更改：将原来`?`转`)`的替换为`(`，并将计数值和字符串状态进行更新。贪心的时候需要找到中间值$i$前面的`?`中$a_i - b_i$最小那个`?`进行转换。

代码如下：

```cpp
void solve() {
	string s; cin>>s;
	priority_queue<PII> heap;
	int n = s.size();
	vector<array<int,2>> a(n); // (val, )val
	int ans = 0;
	// 先得到 ? -> ) 的总花销
	for(int i = 0; i < n; ++i) {
		if(s[i] == '?') {
			cin>>a[i][0]>>a[i][1];
			ans += a[i][1];
		}
	}
	// 判断括号序列是否合法
	bool ok = 1;
	int cnt = 0; // 计数

	for(int i = 0; i < n; ++i) {
		if(!ok) break;
		if(s[i] == '(') cnt++;
		else {
			// 如果不是 ( 优先转为 ) ，并计算差值，
			cnt--;
			if(s[i] == '?') heap.push({a[i][1] - a[i][0], i}), s[i] = ')';
			// 如果是计数是负数
			// 将前面的 ( ? -> ) ) -> ( 转为 (
			// 并更新计数和字符串值
			if(cnt < 0) {
				if(heap.size() == 0) ok = 0;
				else {
					auto tmp = heap.top(); heap.pop();
					ans -= tmp.first;
					cnt += 2;
					s[tmp.second] = '(';
				}
			}
		}
	}
	if(cnt || !ok) puts("-1");
	else {
		cout<<ans<<'\n';
		cout<<s<<'\n';
	}
}
```

