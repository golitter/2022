[Dashboard - Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2) - Codeforces](https://codeforces.com/contest/1864)

A题，贪心即可。

```cpp
void solve() {
    int x,y,n; cin>>x>>y>>n;
    vector<int> a(n + 1);
    a[1] = x, a[n] = y;
    int dif = 1;
    for(int i = n-1; i > 1; --i) a[i] = a[i+1] - dif, dif++;
    bool ok = true;
    vector<int> b;
    for(int i = 1; i < n; ++i) b.push_back(a[i+1] - a[i]);
    for(int i = 1; i < b.size(); ++i) {
        ok &= b[i] < b[i-1];
    } 
    if(ok) {
        for(int i = 1; i <= n; ++i) cout<<a[i]<<" \n"[i == n];
    } else {
        puts("-1");
    }
}
```

B题，发现k为偶数时交换奇偶后都可以，否则就是奇偶。

```cpp
void solve() {
    int n,k; cin>>n>>k;
    string s; cin>>s;
    vector<char> a,b;
    for(int i = 0; i < n; ++i) {
        if(i&1) b.push_back(s[i]);
        else a.push_back(s[i]);
    }
    sort(all(a)); sort(all(b));
    s.assign(n, '0');
    int pos = 0;
    for(int i = 0; i < n; i += 2) s[i] = a[pos++];
    pos = 0;
    for(int i = 1; i < n; i += 2) s[i] = b[pos++];
    if(k%2 == 0) sort(all(s));
    cout<<s<<endl;
}
```

C题，dfs。

```cpp
void solve() {
    int n; cin>>n;
    int now = 1;
    bool ok = false;
    map<int,int> mp;
    vector<int> ans;
    ans.push_back(1);
    auto dfs = [&](auto &&self, int last) -> void {
        if(ok) return ;
        mp[-last]++;
        for(auto &t: mp) {
            if(-t.vf + last < n && t.vs < 3) {
                mp[t.vf]++;
                ans.push_back(last - t.vf);
                self(self, last-t.vf);
                mp[t.vf]--;
                ans.pop_back();
            } else if(-t.vf + last == n && t.vs < 3) {
                ans.push_back(n);
                cout<<ans.size()<<endl;
                reverse(all(ans));
                for(auto &t: ans) cout<<t<<" "; puts("");
                ok = 1;
                return ;
            }
        }
    };
    dfs(dfs, 1);
}
```

D题，将公式展开化简，枚举i即可知道j，从而找次数。

```cpp
void solve() {
    int n; cin>>n;
    vector<string> g(n + 1);
    for(int i = 1; i <= n; ++i) {
        cin>>g[i];
        g[i] = " " + g[i];
    }
    BIT btr(2 * n);
    int cnt = 0;
    for(int len = 2; len <= n * 2; ++len) {
        for(int i = 1; i < len && i <= n; ++i) {
            int j = len - i;
            if(j > n) continue;
            int v = g[i][j] - '0';
            v += btr.sum(i - j + n);
            if(v & 1) {
                ++cnt;
                btr.add(i - j + n, 1);
            }
        }
    }
    cout<<cnt<<endl;
}
```

