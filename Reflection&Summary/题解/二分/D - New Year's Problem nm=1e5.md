[Problem - D - Codeforces](https://codeforces.com/contest/1619/problem/D)

题目大意：m个商店，n个朋友，要向朋友送礼物，限制是只能在n-1个商店内为n个朋友选择礼物。每个礼物对不同的朋友有不同的开心值。矩阵`M[i, j]`表示第i个商店对第j个朋友的开心值（如果选的话。现在要求最大的每个朋友的最小开心值。

解题思路：最小值最大，二分答案，二分开心值。如果进行check？发现如果这个二分值可以那么一定满足：

- 每个朋友在不同的商店中都存在一个大于等于mid的开心值
- 由于n个朋友要去n-1个商店，因此一定有一个商店给两个朋友买了礼物。因此，一定存在一个商店有大于等于2个开心值是大于等于mid的

根据以上进行即可。

`n * m <= 1e5`直接开数组会TLE，以下是解决方案：

#### vector

注意：**n * m <= 1e5 **，可以用vector动态开。

```cpp
vector<vector<int>> a(n,vector<int>(m)); // n * m
vector<vector<int>> a(m, vector<int>(n)); // m * n
```

#### 二维压缩为一维

`M[i, j]`可以用以下进行表示

```cpp
const int N = 2e5 + 21;
a[N];
a[(i-1)*n+j]; // i * j
```

代码：

```cpp
void solve() {
    int m,n; cin>>m>>n;
    // 按照朋友序号存入各个商店的开心值
    // 初始多加一个0，表示如果不可能时，那么就是0
    vector<vector<int>> a(n, {0});
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            int t; cin>>t;
            a[j].push_back(t);
        }
    }
    auto check = [&](int mid) -> bool {
        // 先判断是否每个朋友都存在开心值大于等于mid的
        for(int i = 0; i < n; ++i) {
            bool ok = false;
            for(int j = 0; j <= m; ++j) ok |= a[i][j] >= mid;
            if(!ok) return false; 
        }
        // 再判断是否存在一个商店存在开心值大于等于mid的个数大于1
        for(int i = 0; i <= m; ++i) {
            int cnt = 0;
            for(int j = 0; j < n; ++j) cnt += a[j][i] >= mid;
            if(cnt >= 2) return true;
        }
        return false;
    };
    // 最小值最大模板
    int l = 0, r = 1e9 + 21;
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout<<l<<'\n';
}
```





[CF1619D New Year's Problem - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/solution/CF1619D)