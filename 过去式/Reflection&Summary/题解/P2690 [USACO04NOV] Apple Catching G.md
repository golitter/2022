[P2690 [USACO04NOV\] Apple Catching G - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P2690)

问题描述：

​	有两个位置，初始在位置1。在T分钟内，每分钟两个位置之一会掉落苹果，在位置1和位置2有W次转换。求T分组内，最多可获得多少个苹果。

转移方程：
$$
F(i,j,0) = max(F(i-1, j,0) + A[i], F(i-1,j-1,1) + B[i]) \\
F(i,j,1) = max(F(i-1, j,1) + B[i], F(i-1,j-1,0) + A[i])
$$
状态表示：

​	`F(i,j,k)`，k表示在那个位置，`k = 0`时表示在位置1，`k = 1`时表示在位置2。`F(i,j, k)`表示在位置k时i分钟内用了j次转换的最大价值。

边界：
$$
F(i,0,0) = F(i,0,0) + A[i]
$$
不清楚这个算不算是边界，但是个人感觉是一个边界，（可能边界也有可能是一段

目标：
$$
max_{0 \leq k \leq W}(F(T,k,1), F(T,k,0))
$$
代码：

```cpp
void solve() {
    int t,w; cin>>t>>w;
    for(int i = 0; i < t; ++i) {
        int k; cin>>k;
        if(k == 1) {
            A[i + 1] = 1; 
        } else B[i + 1] = 1;
    }
    f[1][0][0] = A[1];
    for(int i = 1; i <= t; ++i) {
        for(int j = 0; j <= w; ++j) {
            if(j == 0) {
                f[i][j][0] = f[i-1][j][0] + A[i];
            } else {
                f[i][j][0] = max(f[i-1][j][0] + A[i], f[i-1][j-1][1] + B[i]);
                f[i][j][1] = max(f[i-1][j][1] + B[i], f[i-1][j-1][0] + A[i]);
            }
        }
    }
    int ma = -INF;
    for(int i = 0; i <= w; ++i) {
        ma = max(ma, f[t][i][0]);
        ma = max(ma, f[t][i][1]);
    }
    cout<<ma;
}
```

