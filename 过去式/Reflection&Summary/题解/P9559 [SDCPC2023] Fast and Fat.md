[P9559 [SDCPC2023\] Fast and Fat - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P9559)

思路：最小值最大，二分答案。

发现对于$w_i \ge w_j$时，第$i$个人速度不变，还是$v_i$，但是第$j$个人速度会变为$v_j - (w_i - w_j)$。直接二分答案的话，假设此时为$mid$，那么速度小于$mid$的人需要人来带，且速度要至少提到$mid$才符合要求。

且对于初始速度已经大于$mid$的来说，可能要带速度小于$mid$的人，而且大于$mid$的人要带的人的体重差也要满足一定条件，即要符合$v_j - (w_i - w_j) \ge mid$，最差情况是$v_j - (w_i - w_j) = mid$，进而得到所承受的最大重量为$w_i = v_j + w_j - mid$。此时发现在最大重量中，$v_j + w_j$是不变的，$v_j + w_j - mid$是单调的。

对于需要两两组合的情况，显示是可能出现经过特定构造可以满足，但是随机分配是不满足的情况，此时还要贪心的进行配对。我们可以复制一份每个人的信息$v,w$。对于其中一个按照$v_i + w_i$进行排序，对于另一个按照$w_i$进行排序，这样就贪心的保证：速度大于$mid$的人可以分配的最大体重的值跟速度小于$mid$的人的最大体重值相配对，次大依次类推，避免出现浪费$v_i + w_i$和$w_j$的情况，且如果这样都不行，那么一定不存在可行方案。

代码如下：

```cpp
void solve() {
    int n; cin>>n;
    vector<array<int,2>> a(n); // v w
    for(auto &t: a) cin>>t[0]>>t[1];
    auto b(a);
    // 按 v + w 进行排序
    sort(a.begin(), a.end(), [](auto pre, auto suf) {
        return pre[0] + pre[1] > suf[0] + suf[1];
    });
    // 按 w 进行排序
    sort(b.begin(), b.end(), [](auto pre, auto suf) {
        return pre[1] > suf[1];
    });
    
    // pre为速度大于mid的，suf是速度小于mid
    // 得到pre可以带的最大体重，suf的体重，进行配对
    auto check = [&](int mid) -> bool {
        vector<int> pre, suf;
        for(int i = 0; i < n; ++i) {
            if(a[i][0] >= mid) pre.push_back(a[i][0] + a[i][1] - mid);
            if(b[i][0] < mid) suf.push_back(b[i][1]);
        }
        // 如果小于mid的人的数量大于速度大于mid的，那么一定不可以
        if(suf.size() > pre.size()) return false;
        int m = suf.size();
        for(int i = 0; i < m; ++i) {
            // 如果速度大于mid的人能带的最大体重小于速度小于mid的体重，那么就不行
            if(suf[i] > pre[i]) return false;
        }
        return true;
    };
    // 最小值最大
    int l = 0, r = 1e9;
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout<<l<<'\n';
}
```

