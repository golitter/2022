[Problem - D - Codeforces](https://codeforces.com/contest/1779/problem/D)

问题描述：剪发，将数组a减为数组b，有m个剪刀，每个剪刀只可以用一次且可以在任意区间内剪发，将长度大于mi的减为mi。现在有m数组，数组元素是第i个剪刀可以剪到mi，问能否将a减为b。

洛谷翻译：

![image-20230921114344917](https://cdn.789ak.com/img/image-20230921114344917.png)

思路：一定是先减最长的，再减短的。在减的时候会将这个a数组渐渐减成多个数组，再对这些数组进行这些操作，判断给出的m数组是否满足可以进行这些操作。

如果是`b[0]`，因为是第一个，所以一定需要一个剪刀`m = b[0]`。

到`b[1]`时，有三种情况：

- `b[1] < b[0]`：因为接下来要减的少，所以也要用一个剪刀`m = b[1]`。
- `b[1] = b[0]`：相同，上一个可以被覆盖，不需要额外操作。
- `b[1] > b[0]`：这是，由于`b[1] > b[0]`，前面大于`b[1]`的剪刀都不可以用。因为如果用了，那么`a[1]`就会小于`b[1]`，此时不满足条件。

发现此时具有单调栈性质：通过从0到n-1进行遍历b数组，先将栈中小于bi的出栈，之后判断是否为空或者已经存在栈中（sk.top() == bi)，如果为空或者bi不在栈中，入栈，表示一定需要这个

代码：

```cpp
void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(auto &t: a) cin>>t;
    for(auto &t: b) cin>>t;
    bool ok = true;
    for(int i = 0; i < n; ++i) if(a[i] < b[i]) ok = false;
    map<int,int> mii;
    int m; cin>>m;
    for(int i = 0; i < m; ++i) {
        int t; cin>>t;
        mii[t]++;
    }
    stack<int> sk;
    for(int i = 0; i < n; ++i) {
        while(sk.size() && sk.top() < b[i]) sk.pop();
        if(a[i] == b[i]) continue;
        if(sk.empty() || sk.top() != b[i]) {
            sk.push(b[i]);
            mii[b[i]]--;
        }
    }
    for(auto t: mii) {
        ok &= t.vs >= 0;
    }
    puts(ok ? "YES" : "NO");
}
```

