[Problem - C - Codeforces](https://codeforces.com/contest/1482/problem/C)

感觉很经典

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
void solve() {
    int n,m; cin>>n>>m;
    map<int,int> mp;
    bool ok = true;
    vector<vector<int>> a(m + 1);
    for(int i = 1; i <= m; ++i) {
        int k; cin>>k;
        a[i].resize(k);
        for(auto &t: a[i]) {
            cin>>t;   
        }
        if(k == 1) {
            mp[a[i][0]]++;
            if(mp[a[i][0]] > (m + 1) / 2) ok = false;
        }
    }
    if(!ok) {
        cout<<"NO\n";
        return ;
    } 
    cout<<"YES\n";
    for(int i = 1; i <= m; ++i) {
        int d = 0, mi = INF;
        int o = 0;
        if(a[i].size() == 1) o = a[i][0];
        else {
            for(auto &t: a[i]) {
                if(mp[t] < mi) {
                    mi = mp[t];
                    d = t;
                }
            }
            mp[d]++;
            o = d;
        }
        cout<<o<<" \n"[i == m];
    }
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

