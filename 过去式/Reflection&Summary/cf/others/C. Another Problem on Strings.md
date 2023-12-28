[Problem - C - Codeforces](https://codeforces.com/contest/165/problem/C)

问题描述：给定一个k和一个01串，求该01串中有多少个'1'个数为k的字串，出现位置不同算不同的子串。

思路：暴力会挂，考虑优化。对于一个字串他满足'1'为k个条件时，它的前面第一个'1'前面是'0'，后面最后一个'1'后面是'0'。可以发现，如果记录第i个'1'和第i-1个'1'之间出现的'0'的个数，那么对于满足条件的右边来说，只需要加上`cnt-k个'1'和cnt-k+1之间的'0'的个数`，`cnt`为第cnt个'1'之前'0'到前一个'1'的'0'的个数。

代码：

```cpp
void solve() {
    int k; cin>>k;
    string str; cin>>str;
    LL ans = 0;
    LL cnt = 0;
    int n = str.size();
    vector<LL> rcd(n + 21); // 用来记录 第cnt个'1'和第cnt-1个'1'之间的'0'的个数
    rcd[0] = 1; // 需要对第0个'1'之前的'0'进行特判
                // 因为 长度为k的全'1'的字串也可能存在
    for(int i = 0; i <= n; ++i) {
        if(str[i] == '1') cnt++; 
        if(cnt >= k) ans += rcd[cnt - k];
        rcd[cnt]++;
    }
    cout<<ans;
}
```

