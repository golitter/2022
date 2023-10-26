[Problem - B - Codeforces](https://codeforces.com/contest/126/problem/B)

需要找到既是S的前缀又是S的后缀同时又在S中间出现过的最长子串

前缀数组。

```cpp
vector<int> prefix_function(string s) { 
  int n = (int)s.length();
  vector<int> nxt(n);
  for (int i = 1; i < n; i++) {
    int j = nxt[i - 1];
    while (j > 0 && s[i] != s[j]) j = nxt[j - 1];
    if (s[i] == s[j]) j++;
    nxt[i] = j;
  }
  return nxt;
}
void inpfile();
void solve() {
    string s; cin>>s;
    auto pre = prefix_function(s);
    int ma = *max_element(pre.begin(), pre.end() - 1);
    int k = pre.back();
    while(k > ma) k = pre[k-1];
    if(k) {
        cout<<s.substr(0,k)<<endl;
    } else puts("Just a legend");
}
```

