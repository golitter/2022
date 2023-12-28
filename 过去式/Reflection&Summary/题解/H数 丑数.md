[P1748 H数 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1748)

```cpp
void solve() {
    int n; cin>>n;
    if(!n) {
        puts("0");
        return ;
    }
    set<LL> s;
    s.insert(1);
    auto it = s.begin();
    for(int i = 1; i < n; ++i) {
        auto v = *it;
        s.insert({v*2,v*3,v*5,v*7});
        it++;
    }
    cout<<*it;
}
```



```cpp
void solve() {
    int k,n; cin>>n;
    k = 4;
    vector<LL> a({2,3,5,7});
    // for(auto &t: a) cin>>t;
    priority_queue<LL,vector<LL>, greater<LL>> miq;
    miq.push(1);
    set<LL> s;
    s.insert(1);
    int now = 0;
    LL ans = 0;
    while(now < n) {
        now++;
        ans = miq.top(); miq.pop();
        for(int i = 0; i < k; ++i) {
            LL val = ans * a[i];
            if(s.count(val) == 0) {
                s.insert(val);
                miq.push(val);
            }
        }
    }
    cout<<ans;
}
```







[P2723 [USACO3.1\] 丑数 Humble Numbers - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P2723)

```cpp
void solve() {
    int k,n; cin>>k>>n;
    vector<LL> a(k);
    for(auto &t: a) cin>>t;
    priority_queue<LL,vector<LL>, greater<LL>> miq;
    miq.push(1);
    set<LL> s;
    s.insert(1);
    int now = 0;
    LL ans = 0;
    while(now <= n) {
        now++;
        ans = miq.top(); miq.pop();
        for(int i = 0; i < k; ++i) {
            LL val = ans * a[i];
            if(s.count(val) == 0) {
                s.insert(val);
                miq.push(val);
            }
        }
    }
    cout<<ans;
}
```

