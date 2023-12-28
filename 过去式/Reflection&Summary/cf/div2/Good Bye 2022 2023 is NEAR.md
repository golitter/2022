[Dashboard - Good Bye 2022: 2023 is NEAR - Codeforces](https://codeforces.com/contest/1770)

A题，优先队列。

```cpp
void solve() {
    int n,m; cin>>n>>m;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i = 0; i < n; ++i) {
        int t; cin>>t;
        q.push(t);
    }
    for(int i = 0; i < m; ++i) {
        int t; cin>>t;
        q.pop();
        q.push(t);
    }
    int sum = 0;
    while(q.size()) {
        sum += q.top();
        q.pop();
    }
    cout<<sum<<endl;
}
```

B题，刚开始打表，找到了很奇怪的规律，k = 2/3时不一致，其他都是只影响了1的位置，就这样我打表找规律找了一个多小时，最后也没有找到k = 3时的规律。最后准备手推一下k = 3，发现了一个更简单的规律，遂结束。

**以后这种要输出很多的规律题不要贸然打表，因为有很多种情况，打表的不知道是哪种情况，但是也是对的，这样对于打表找规律来说反而是一个累赘（如果只有一个解的除外，打出的表一定是唯一的那个正确结果**

```cpp
void solve() {
    auto dab = [&](int n, int k) -> void {
        vector<int> pp;
        bool ok = false;
        vector<int> a(n);
        iota(all(a),1);
        // for(auto t: a) cout<<t<<" "; puts("");
        int tmp = INF;
        do {
        // for(auto t: a) cout<<t<<" "; puts("");
            int ans = -INF;
            for(int i = 0; i + k - 1 < n; ++i) {
                int mi = INF, ma = -INF;
                // cout<<i<<" "<<i + k + 1<<endl;
                for(int j = i; j <= i + k - 1; ++j) {
                    mi = min(mi, a[j]);
                    ma = max(ma, a[j]);
                }
                ans = max(ans, mi + ma);
            }
            // tmp = max(tmp, ans);
            if(tmp > ans) {
                // tmp = ans;
                // pp.assign(all(a));
                if(ok && tmp == ans) {
                    int fg = -1;
                    for(int i = 0; i < n; ++i) {
                        if(a[i] > pp[i]) fg = 0;
                        if(a[i] < pp[i]) fg = 1;
                        if(fg != -1) break;
                    }
                    if(fg == 1) {
                        pp.assign(all(a));
                    }
                } else {
                    pp.assign(all(a));
                    ok = true;
                }
                tmp = ans;
            }
        } while(next_permutation(all(a)));
        cout<<n<<" "<<k<<" "<<tmp<<"   ";
        for(auto t: pp) cout<<t<<" "; puts("");
    
        // do {
        //     int ans = -INF;
        //     for(int i = 0; i + k - 1 < n; ++i) {
        //         int mi = INF, ma = -INF;
        //         for(int j = i; j <= i + k - 1; ++j) {
        //             mi = min(mi, a[j]);
        //             ma = max(ma, a[j]);
        //         }
        //         ans = max(ans, mi + ma);
        //     }
        //     // tmp = max(tmp, ans);
        //     if(tmp == ans) {
        //         for(auto t: a) cout<<t<<" "; puts("");
        //         // // tmp = ans;
        //         // // pp.assign(all(a));
        //         // if(ok && tmp == ans) {
        //         //     int fg = -1;
        //         //     for(int i = 0; i < n; ++i) {
        //         //         if(a[i] > pp[i]) fg = 0;
        //         //         if(a[i] < pp[i]) fg = 1;
        //         //         if(fg != -1) break;
        //         //     }
        //         //     if(fg == 1) {
        //         //         pp.assign(all(a));
        //         //     }
        //         // } else {
        //         //     pp.assign(all(a));
        //         //     ok = true;
        //         // }
        //         // tmp = ans;
        //     }
        // } while(next_permutation(all(a)));

    };
    // dab(5,3);
    // dab(5,1);
    // for(int i = 1; i <= 10; ++i) {
    //     for(int j = 1; j <= i; ++j) {
    //         dab(i,j);
    //     }
    // }
    // int n,k; cin>>n>>k;
    // vector<int> a(n + 1);
    // if(k != 1) {
    //     a[1] = n, a[k] = 1;
    //     set<int> s;
    //     s.insert(1); s.insert(n);
    //     int p = 2;
    //     for(int i = 1; i <= n; ++i) {
    //         if(a[i]) continue;
    //         while(s.count(p)) ++p;
    //         a[i] = p;
    //         s.insert(p);
    //         ++p;
    //     }
    // } else {
    //     for(int i = 1;  i<= n; ++i) a[i] = i;
    // }
    // for(int i = 1; i <= n; ++i) cout<<a[i]<<" \n"[i == n];

    // int n,k; cin>>n>>k;
    // vector<int> a(n + 1);
    // k = n - k + 1;
    // a[k] = 1;
    // // set<int> s;
    // // s.insert(1);
    // int p = 2;
    // for(int i = 1; i <= n; ++i) {
    //     if(a[i]) continue;
    //     // while(s.count(p)) ++p;
    //     a[i] = p;
    //     // s.insert(p);
    //     ++p;
    // }
    // for(int i = 1; i <= n;++i) cout<<a[i]<<" \n"[i == n];
    int n,k; cin>>n>>k;
    vector<int> a(n + 1);
    set<int> s;
    int p = 1;
    for(int i = k; i < n; i += k) a[i] = p, s.insert(p), ++p;
    p = n;
    for(int i = 1; i <= n; ++i) {
        // if(s.count(i)) continue;
        while(s.count(p)) --p;
        if(a[i]) continue;
        a[i] = p;
        s.insert(p);
        --p;
    }
    for(int i = 1; i <= n; ++i) cout<<a[i]<<" \n"[i == n];
}
```

C题，找是否存在一个值x，满足所有的都是`gcd(ai + x, aj + x) == 1`。

```cpp
// https://zhuanlan.zhihu.com/p/595701279
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    map<int,int> mp;
    for(auto &t: a) cin>>t,mp[t]++;
    for(auto t: mp) if(t.vs >= 2) {puts("NO"); return ; }
    mp.clear();
    for(int i = 2; i <= n; ++i) {
        mp.clear();
        for(auto t: a) mp[t % i]++;
        int cnt = 0;
        for(auto t: mp) cnt += t.vs >= 2;
        if(cnt == i) {
            puts("NO");
            return ;
        }
    }
    puts("YES");
}
```

# 总结

这次很快就找到了A题的trick，但是对于B题来说，我用的打表这个trick由于在答案不唯一时难以找到较明显的规律，导致耽搁了一个多小时，**下次注意！！！**

C题是真不会。。。