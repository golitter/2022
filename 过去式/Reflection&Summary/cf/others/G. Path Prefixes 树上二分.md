[Problem - G - Codeforces](https://codeforces.com/contest/1714/problem/G)

问题描述：以1为根的树，节点编号从到n。每条边有两个权重a和b。令从1到i（i >= 2）的路径中，A为ai前缀和。求1到i的最长b前缀和不大于A。

思路：从1到i的这个一定是一条链，可以用dfs，求出1到i之间的所有a数组和b数组前缀和。让求的是最大b前缀，发现a和b都是正的，对于找最大不大于A的，这具有单调性，最小值最大，可以二分答案。因此，本题就是dfs时二分答案即可。

代码：

```cpp
#define int long long
void solve() {
    int n; cin>>n;
    vector<vector<array<int,3>>> g(n + 1); // u -> v,a,b
    for(int i = 2; i <= n; ++i) {
        int p,a,b; cin>>p>>a>>b;
        g[p].push_back({i,a,b});
    }
    vector<int> sumb(n+1),f(n+1);
    auto dfs = [&](auto &&dfs, int u, int sma, int smb, int dep) -> void {
        sumb[dep] = smb;
        int l = 0, r = dep;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if(sumb[mid] <= sma) l = mid;
            else r = mid - 1; 
        }
        f[u] = l;
        for(auto t: g[u]) {
            int y = t[0], a = t[1], b = t[2];
            dfs(dfs, y, sma + a, smb + b, dep+1);
        }
    };
    dfs(dfs, 1,0,0,0);
    for(int i = 2; i <= n; ++i) cout<<f[i]<<" \n"[i == n];
}
```

