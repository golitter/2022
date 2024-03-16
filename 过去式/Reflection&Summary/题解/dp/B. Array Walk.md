[Problem - B - Codeforces](https://codeforces.com/contest/1389/problem/B)

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

#define Multiple_groups_of_examples
// #define int_to_long_long
#define IOS std::cout.tie(0);std::cin.tie(0)->sync_with_stdio(false); // 开IOS，需要保证只使用Cpp io流 *
#define dbgnb(a) std::cout << #a << " = " << a << '\n';
#define dbgtt cout<<" !!!test!!! "<<'\n';
#define rep(i,x,n) for(int i = x; i <= n; i++)

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define vf first
#define vs second

typedef long long LL;
#ifdef int_to_long_long
#define int long long
#endif
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 21;

void inpfile();

// https://www.luogu.com.cn/problem/solution/CF1389B
void solve() {
    int n,k,z; cin>>n>>k>>z;
    vector<vector<int>> f(n + 1, vector<int>(10));
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) cin>>a[i];
    /**
     * f(i, j) 表示用了i次向左移动，到达j时的最大价值
     * 
    */
    int ans = -INF;
    for(int i = 0; i <= z; ++i) {
        for(int j = 1; j <= n; ++j) {
            f[j][i] = f[j - 1][i] + a[j];
            if(i && j != n) f[j][i] = max(f[j][i], f[j + 1][i - 1] + a[j]);
            if(j - 1 + i * 2 == k) ans = max(ans, f[j][i]);
        }
   }
   cout<<ans<<'\n';
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
    #define mytest
    #ifdef mytest
    freopen("ANSWER.txt", "w",stdout);
    #endif
}
```

