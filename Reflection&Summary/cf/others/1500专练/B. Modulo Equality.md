[Problem - 1269B - Codeforces](https://codeforces.com/problemset/problem/1269/B)

对于任意要满足该条件的md就是，a0到所有bi的差值等，直接枚举这个就行。
$$
(bi - a0 + m) \% m
$$
如果是：
$$
(a0 - bi + m) \% m
$$
就不对了。

需要注意。

这题我刚开始想的是`O(n*n)`的，但是发现可以省略一个n，直接用bi到a的一个固定值就行，因为一定是满足a的这种情况的。可以。（有提高

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <random>
#include <sstream>
#include <numeric>
#include <stdio.h>
#include <functional>
#include <bitset>
#include <algorithm>
using namespace std;

// #define Multiple_groups_of_examples
#define IOS std::cout.tie(0);std::cin.tie(0)->sync_with_stdio(false);
#define dbgnb(a) std::cout << #a << " = " << a << '\n';
#define dbgtt cout<<" !!!test!!! "<<endl;
#define rep(i,x,n) for(int i = x; i <= n; i++)

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define vf first
#define vs second

typedef long long LL;
#define int long long
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 21;

void inpfile();
void solve() {
    int n,m; cin>>n>>m;
    vector<int> a(n),b(n);
    map<int,int> miia,miib;
    for(auto &t: a) cin>>t, miia[t]++;
    for(auto &t: b) cin>>t, miib[t]++;
    sort(all(b));
    int ans = 0x7fffffff;
    for(int i = 0; i < n; ++i) {
        // int md = (a[0] - b[i]) % m;
        // md = (md + m) % m;
        int md = (b[i] - a[0] + m) % m;
        bool ok = true;
        // for(auto t: miia) {
        //     int now = (t.vf + md) % m;
        //     ok &= miib[now] == t.vs;
        // }
        auto tmp(a);
        for(auto &t: tmp) t = (t + md) % m;
        sort(all(tmp));
        for(int j = 0; j < n; ++j) ok &= tmp[j] == b[j];
        if(ok) ans = min(ans, md);
    }
    cout<<ans;
}
signed main()
{
    #ifdef Multiple_groups_of_examples
    int T; cin>>T;
    while(T--)
    #endif
    solve();
    return 0;
}
void inpfile() {
    #define mytest
    #ifdef mytest
    freopen("ANSWER.txt", "w",stdout);
    #endif
}
```

