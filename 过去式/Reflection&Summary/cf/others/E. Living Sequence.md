[Problem - 1811E - Codeforces](https://codeforces.com/problemset/problem/1811/E)

问题描述：正整数中不能有4，问第k个数是多少

思路：不能选4，那就只有`{0,1,2,3,5,6,7,8,9}`，可以发现这可以当作九进制，将k转为9进制，对于大于等于4的进行++操作，这样就避免了4的存在。

代码：

```cpp
void solve() {
    LL n; cin>>n;
    vector<int> ans;
    while(n) {
        ans.push_back(n%9);
        n /= 9;
    }
    reverse(all(ans));
    for(auto &t: ans) if(t >= 4) t++;
    for(auto t: ans) cout<<t;
    puts("");
}
```

