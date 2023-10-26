[Problem - D - Codeforces](https://codeforces.com/contest/471/problem/D)



给两堵墙，问 a 墙中与 b 墙顶部形状相同的区间有多少个。

差分 + KMP

```cpp
vector<int> prefix_function(const vector<int>& s) { 
    int n = (int)s.size();
    vector<int> nxt(n);
    for (int i = 1; i < n; i++) {
        int j = nxt[i - 1];
        while (j > 0 && s[i] != s[j]) j = nxt[j - 1];
        if (s[i] == s[j]) j++;
        nxt[i] = j;
    }
    return nxt;
}
// 在字符串text中查找pattern字符串
vector<int> find_occurrences(const vector<int>& text, const vector<int>& pattern) {
    // string cur = pattern + '#' + text; // 加一个两个字符串中不存在的字符，表示最长前缀为n咯

    int sz1 = text.size(), sz2 = pattern.size();
    vector<int> cur(sz1 + 1 + sz2);
    int pos = 0;
    while(pos < sz2) cur[pos] = pattern[pos],pos++;
    cur[pos] = -INF; pos++;
    while(pos < sz1 + 1 + sz2) cur[pos] = text[pos - 1 - sz2], pos++;
    // for(auto t: cur) cout<<t<<" ";
    vector<int> v;
    vector<int> lps = prefix_function(cur);
    for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
        if (lps[i] == sz2)
        v.push_back(i - 2 * sz2);
    }
    return v;
}

void inpfile();
void solve() {
    int n,k; cin>>n>>k;
    vector<int> a(n), b(k);
    for(auto &t: a ) cin>>t;
    for(auto &t: b) cin>>t;
    auto aa(a), bb(b);
    for(int i = 0; i < n-1; ++i) {
        aa[i] = aa[i+1] - aa[i];
    }
    for(int i = 0; i < k-1; ++i) {
        bb[i] = bb[i+1] - bb[i];
    }
    bb.erase(bb.end() - 1);
    auto tp = find_occurrences(aa,bb);
    cout<<tp.size();
}
```

