[Problem - C - Codeforces](https://codeforces.com/contest/1805/problem/C)

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

#define Multiple_groups_of_examples
#define int_to_long_long
#define IOS std::cout.tie(0);std::cin.tie(0)->sync_with_stdio(false);
#define dbgnb(a) std::cout << #a << " = " << a << '\n';
#define dbgtt cout<<" !!!test!!! "<<endl;
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
void solve() {
    int n,m; cin>>n>>m;
    vector<int> aa(n);
    vector<array<int,3>> abc(m);
    for(auto &t: aa) cin>>t;
    for(auto &t: abc) cin>>t[0]>>t[1]>>t[2];
    sort(all(aa));
    aa.erase(unique(all(aa)), aa.end());
    auto check = [&](int x, array<int,3> cba) -> bool {
        return (x - cba[1]) * (x - cba[1]) - 4 * cba[0] * cba[2] < 0;
    };
    for(auto t: abc) {
        int a = t[0], b = t[1], c = t[2];
        if(c < 0) {
            puts("NO");
            continue;
        } else {
            auto k = lower_bound(all(aa), b);
            if(k != aa.end() && check(*k, t)) {
                puts("YES"); cout<<*k<<endl;
                continue;
            }
            if(k != aa.begin() && check(*(k-1), t)) {
                puts("YES"); cout<<*(k-1)<<endl;
                continue;
            }
        }
        puts("NO");
    }
    puts("");
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

