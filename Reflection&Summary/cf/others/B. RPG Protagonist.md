[Problem - B - Codeforces](https://codeforces.com/contest/1400/problem/B)

shit模拟。

```cpp
void solve() {
    int f,p; cin>>f>>p;
    int cnts,s,cntw,w; cin>>cnts>>cntw>>s>>w;
    if(s > w) swap(s,w), swap(cnts,cntw);
    auto calc = [&](int nows) -> int {
        if(nows * s > f) return 0;
        int tmp = nows;
        int cs = cnts - nows;
        int lastf = f - nows * s;
        int fw = lastf / w;
        tmp += min(fw, cntw);
        int cw = cntw - min(fw, cntw);

        int ps = p / s;
        // tmp += min(ps, cs);
        int lastp = p % s;
        if(ps > cs) {
            tmp += cs;
            lastp += (ps - cs) * s;
        } else {
            tmp += ps;
        }
        int pw = lastp / w;
        tmp += min(pw, cw);
        return tmp;

    };
    int ans = 0;
    rep(i,0,cnts) {
        ans = max(ans, calc(i));
        // cout<<ans<<endl;
    }
    cout<<ans<<endl;
}
```

