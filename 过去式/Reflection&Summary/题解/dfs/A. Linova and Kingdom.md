[Problem - 1336A - Codeforces](https://codeforces.com/problemset/problem/1336/A)

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
#include <cmath>
#include <functional>
#include <bitset>
#include <algorithm>
using namespace std;

// #define Multiple_groups_of_examples
// #define int_to_long_long
#define IOS std::cout.tie(0);std::cin.tie(0)->sync_with_stdio(false); // 开IOS，需要保证只使用Cpp io流 *
#define dbgnb(a) std::cout << #a << " = " << a << '\n';
#define dbgtt cout<<" !!!test!!! "<<'\n';
#define rep(i,x,n) for(int i = x; i <= n; i++)

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define vf first
#define vs second
#define int int
typedef long long LL;
#ifdef int_to_long_long
#define int long long
#endif
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 21;

void inpfile();
void solve() {
    int n,k; cin>>n>>k;
    vector<int>  dep(n + 1), sz(n + 1), val(n + 1);
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; ++i) {
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](auto &&dfs, int u, int fu, int d) -> int {
        int siz = 1;
        for(auto y: g[u]) {
            if(y == fu) continue;
            siz += dfs(dfs, y, u, d + 1);
        }
        sz[u] = siz;
        val[u] = d  - siz;
        return siz;
    };
    dfs(dfs, 1, -1, 1);
    sort(val.begin() + 1, val.end(), [&](auto pre, auto suf) {
        return pre > suf;
    });
    cout<<accumulate(val.begin() + 1, val.begin() + k + 1, 0LL)<<'\n';
}
#ifdef int_to_long_long
signed main()
#else
int main()
#endif

{
    #ifdef Multiple_groups_of_examples
    int T; cin>>T;
    while(T--)
    #endif
    solve();
    return 0;
}
void inpfile() {
    #define MY_TEST
    #ifdef MY_TEST
    freopen("ANSWER.txt", "w",stdout);
    #endif
}
```

