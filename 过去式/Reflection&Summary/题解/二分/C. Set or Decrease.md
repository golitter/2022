[Problem - 1622C - Codeforces](https://codeforces.com/problemset/problem/1622/C)

前缀和 + 二分

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
    int n; cin>>n;
    LL k; cin>>k;
    vector<LL> a(n + 1), sum(n + 1);
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    sort(a.begin() + 1, a.end());
    for(int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }
    auto check = [&](LL mid) -> bool {
        LL mds = 1e18;
        for(LL i = max(0LL, mid - n + 1); i <= mid; ++i) {
            LL j = mid - i;
            LL tot = sum[n] - ( (sum[n] - sum[n - j]) - j * (a[1] - i)) - i;
            mds = min(mds, tot);
        }
        return mds <= k;
    };
    LL l = 0, r = sum[n] - k, ans;
    while(l < r) {
        LL mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout<<max(0LL, r)<<'\n';
    // cout<<r<<'\n';

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

