[BFS练习1 - 题目 - Daimayuan Online Judge](http://oj.daimayuan.top/course/11/problem/147)

问题描述：

![image-20230905004357773](https://cdn.789ak.com/img/image-20230905004357773.png)

刚开始吓一跳，以为有什么更简单的呢，因为每一次都要走一次bfs，看了数据范围后，感觉跑一次bfs进行记录即可。

代码：

```cpp
void solve() {
	int a,k; cin>>a>>k;
	int l = 1, r = 100000;
	queue<int> q;
	q.push(a);
	vector<int> f(r+1, -1);
	f[a] = 0;
	while(q.size()) {
		int x = q.front(); q.pop();
		for(int i = 0; i < 4; ++i) {
			int xx = 0;
			if(i == 0) xx = x + 1;
			if(i == 1) xx = x * 2;
			if(i == 2) xx = x * 3;
			if(i == 3) xx = x - 1;
			if(xx < l || xx > r) continue;
			if(f[xx] != -1) continue;
			f[xx] = f[x] + 1;
			q.push(xx);
		}
	}
	for(int i = 0; i < k; ++i) {
		int t; cin>>t;
		cout<<f[t]<<" ";
	}
}
```

