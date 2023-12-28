[Dashboard - CodeTON Round 6 (Div. 1 + Div. 2, Rated, Prizes!) - Codeforces](https://codeforces.com/contest/1870)



A题，构造一个数组，长度为n，mex为k，数组最大值小于等于x，求数组和最大值。

这题，读懂题意后就知道算法怎么写了，后面都是边界问题。刚开始想的是`k > n || k > x`就构造不出来，但是样例没过，之后发现`k >= x + 2`一定构造不出来，否则一定可以构造出来。对于可以构造出来的情况，为了最大化，前`k-1`个值需要最小，只需要一个就行，满足条件即可。之后全是最大值即可，注意k和x相等的情况，这时是`x-1`，其他是`x`。

这题很简单，但是边界的考虑一直没想出来，直到10分钟才写出来。（可能有点紧张了，太激动

```cpp
void solve() {
    LL n,k,x; cin>>n>>k>>x;
    if(k > n || k > x+1) {
        puts("-1");
    } else {
        LL ans = 0;
        LL t = k-1;
        ans = t * (t + 1) / 2;
        if(x != k)
            ans += (n - k) * x;
        else ans += (n - k) * (x - 1);
        cout<<ans<<endl;
    }
}
```

B题，给数组a和b，bi可以进行操作`a | b1 | b2 | b3 ... `，之后求x，`x = a1^ a2 ^ a3 ... `，求经过任意操作后的最小值和最大值是多少。赛时乱搞过的，当时发现，先对初始a进行异或得到的值一定是有用的。只要进行了操作，就会有可能让a中所有元素的一位为1，使答案变大，但是又因为分奇偶，所有ma和mi值是前后操作的min、max取值。

```cpp
void solve() {
    int n,m; cin>>n>>m;
    vector<LL> a(n), b(m);
    LL x = 0;
    for(auto &t: a) cin>>t,x ^= t;
    for(auto &t: b) cin>>t;
    LL ma = x, mi = x;
    LL v = 0;
    for(auto t: b) v |= t;
    for(auto &t: a) t |= v;
    x = 0;
    for(auto t: a) x ^= t;
    cout<<min(mi, x)<<" "<<max(ma,x)<<endl;
}
```

C题，赛时算法是想出来了，但是可能是思维定式吧，感觉很像是数据结构，但是过的人又很多，导致怀疑自己。赛后发现就是这样写，但是从大往小遍历就可以将这些影响给消除。就是很妙，跟离线操作一样。

```cpp
void solve() {
    int n,k; cin>>n>>k;
    vector<int> a(n + 1);
    vector<PII> lr(k + 1, {INF, -INF});
    int ma = 0;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        lr[a[i]] = {min(lr[a[i]].vf, i), max(lr[a[i]].vs, i)};
        ma = max(ma, a[i]);
    }
    int pre = ma;
    for(int i = ma-1; i >= 1; --i) {
        if(lr[i].vf == INF) {
            continue;
        }
        auto tmp = lr[pre];
        lr[i] = {min(lr[i].vf, tmp.vf), max(lr[i].vs, tmp.vs)};
        pre = i;
    }
    for(int i = 1; i <= k; ++i) {
        if(lr[i].vf == INF) cout<<"0 ";
        else cout<<(lr[i].vs - lr[i].vf + 1) * 2<<" ";
    }
    puts("");
}
```

```cpp
void solve() {
    int n,k; cin>>n>>k;
    vector<int> a(n + 1);
    vector<PII> lr(k + 1, {INF, -INF});
    int ma = 0;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        lr[a[i]] = {min(lr[a[i]].vf, i), max(lr[a[i]].vs, i)};
        ma = max(ma, a[i]);
    }
    auto jd = lr;
    for(int i = k-1; i >= 1; --i) {
        lr[i] = {min(lr[i].vf, lr[i+1].vf), max(lr[i].vs, lr[i+1].vs)};
    }
    for(int i = 1; i <= k; ++i) {
        if(jd[i].vf > jd[i].vs) cout<<"0 ";
        else cout<<(lr[i].vs - lr[i].vf + 1) * 2<<" ";
    }
    puts("");
}
```

经过不断实操，感觉用PII处理，l和rmax，min问题有点冗余，直接用两个数组表示l和r更加简单点，而且最后一个换行，中间是空格隔开，感觉用`puts("")`也有点麻烦了，现在学了一手jly的码风，用以下进行了替换。

```cpp
void solve() {
    int n,k; cin>>n>>k;
    vector<int> l(k+1, INF), r(k + 1, -INF);
    for(int i = 1; i <= n; ++i) {
        int t; cin>>t;
        l[t] = min(l[t], i);
        r[t] = i;
    }
    auto sl(l), sr(r);
    for(int i = k-1; i >= 1; --i) {
        l[i] = min(l[i], l[i+1]);
        r[i] = max(r[i], r[i+1]);
    }
    for(int i = 1; i <= k; ++i) {
        if(sl[i] > sr[i]) cout<<0;
        else cout<<(r[i] - l[i] + 1) * 2;
        cout<<" \n"[i == k];
    }
}
```

个人感觉更加简单了。

D题，可后悔贪心。

```cpp
void solve() {
    priority_queue<PII> q;
    int n,k; cin>>n;
    for(int i = 1; i <= n; ++i) {
        int t; cin>>t;
        q.push({-t, i});
    }
    cin>>k;
    int lastpos = 0, lastval = 0;
    vector<int> dif(n + 21);
    while(q.size() && k) {
        auto tmp = q.top(); q.pop();
        int id = tmp.vs, vx = -tmp.vf;
        if(id <= lastpos) continue;
        int t = k / (vx - lastval);
        if(lastpos) t = min(t, -dif[lastpos+1]);
        k -= t * (vx - lastval);
        dif[lastpos+1] += t;
        dif[id+1] -= t;
        lastpos = id;
        lastval = vx;
    }
    for(int i = 1; i <= n; ++i) {
        dif[i] += dif[i-1];
        cout<<dif[i]<<" \n"[i == n];
    }
}
```

## 总结

A题用时太久了，B题也是，感觉这场B是找结论了，没有显式的证明出来。C题往数据结构上想了，可能就偏了，如果想到按照离线的思路，从大到小进行处理则题就迎刃而解了，哎，还是思维跟不上。

cf前三题都没有什么算法，到D才有些算法，还需努力，这几场分一直在掉，难受。

还是之前的错误习惯，**不要紧张、激动**，**不要算法想一半就敲代码，这是半场开香槟，最忌讳了**，

**下一场一定上分** **！！！！！！！**



