[PTA | 程序设计类实验辅助教学平台 (pintia.cn)](https://pintia.cn/problem-sets/1571150153619189760/exam/problems/1571150314621562880?type=7&page=0)

2022ICPC网络赛。

## A题

```cpp
void solve() {
    int n,q; cin>>n>>q;
    string s; cin>>s;
    s = " " + s;
    vector<int> sum(n + 21), pre(n + 21), suf(n + 21);
    int last = -1;
    // 间隔处理
    for(int i = 1; i <= n; ++i) {
        if(s[i] == '1') {
            if(last != i-1) sum[i] = 1, last = i;
            else sum[i] = 0, last = -1;
        }
        sum[i] += sum[i-1];
    }
    // 找第i个值第一个右边的'0'，pre[i] + i --> 即为此
    for(int i = n; i >= 1; --i) {
        if(s[i] == '1') pre[i] = pre[i+1] + 1;
        else pre[i] = 0;
    }
    // 找第i个值第一个左边的'0'，suf[i] + i --> 即为此
    for(int i = 1; i <= n; ++i) {
        if(s[i] == '1') suf[i] = suf[i-1] + 1;
        else suf[i] = 0;
    }
    while(q--) {
        int l,r; cin>>l>>r;
        int len = r - l + 1; len /= 3;
        int tmp = 0;
        int l0 = l + pre[l], r0 = r - suf[r];
        if(l0 >= r0) {
            tmp = (r - l + 1) / 2;
        } else {
            tmp = sum[r0] - sum[l0-1] + (pre[l] + suf[r] + 1) / 2;
        }
        cout<<max(0, len - tmp)<<endl;
    }

}
```

这一块很妙：

```cpp
// 找第i个值第一个右边的'0'，pre[i] + i --> 即为此
    for(int i = n; i >= 1; --i) {
        if(s[i] == '1') pre[i] = pre[i+1] + 1;
        else pre[i] = 0;
    }
    // 找第i个值第一个左边的'0'，suf[i] + i --> 即为此
    for(int i = 1; i <= n; ++i) {
        if(s[i] == '1') suf[i] = suf[i-1] + 1;
        else suf[i] = 0;
    }
```

## C题

度为0或1的点不能缩点，其他都可以用缩点的操作消掉。

```cpp
void solve() {
    int n; cin>>n;
    vector<int> osi(n + 1);
    for(int i = 1; i < n; ++i) {
        int u,v; cin>>u>>v;
        osi[u]++, osi[v]++;
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(osi[i] <= 1) cnt++;
    }
    cout<<cnt<<endl;
}
```



## D题

vp的时候那榜以为是比赛的榜呢，谁知道是还带补题的榜呢。思路没问题，就是不敢写，以为是签到题呢。

大水题

```cpp
__builtin_ctz
__builtin_popcount
```



```cpp
void solve() {
    int n; cin>>n;
    bitset<31> a;
    vector<int> ans;
    int cnt = 0;
    auto dfs = [&](auto &&dfs, int u) -> void {
        if(u > 30) {
            if(cnt) return ;
            int tmp = a.to_ulong();
            ans.push_back(tmp);
            return ;
        }
        if(cnt) {
            cnt--;
            a[u] = 1;
            dfs(dfs,u+1);
            a[u] = 0;
            cnt++;
        }
        dfs(dfs,u+1);
    };
    for(int i = 0; i < 15; ++i) {
        for(int j = 0; j <= i; ++j) a[j] = 0;
        a[i+1] = 1;
        cnt = i;
        dfs(dfs,i+2);
    }
    sort(all(ans));
    while(n--) {
        int l,r; cin>>l>>r;
        auto pos = lower_bound(all(ans), l);
        if(pos == ans.end() || *pos > r) cout<<-1<<endl;
        else cout<<*pos<<endl;
    }
}
```

## H题

将`repeat ... for x times`当作`(...) * x`，用stack模拟即可。

```cpp
void solve() {
    string str;
    stack<int> s;
    int ans = 0;
    auto MOD = [&](int &a, int b) -> void {
        a = (a + b) % mod;
    };
    while(cin>>str, str != "fin") {
        if(str == "library") {
            if(!s.size()) MOD(ans,1);
            else s.push(1);
        }
        if(str == "repeat") {
            s.push(-1);
        }
        int tmp = 0;
        bool isnum = true;
        int len = str.size();
        int now = 0;
        while(now < len) {
            if(isdigit(str[now])) {
                tmp = tmp * 10 + str[now] - '0';
            } else {
                isnum = false;
                break;
            }
            now++;
        }
        if(isnum) {
            int last = 0;
            while(s.size() && s.top() != -1) {
                last += s.top(); s.pop();
            }
            tmp %= mod;
            last %= mod;
            s.pop(); // -1 (
            int val = last * tmp % mod;
            if(!s.size()) {
                MOD(ans, val); 
            } else {
                s.push(val);
            }
        }
    }
    cout<<ans<<endl;
}
```

