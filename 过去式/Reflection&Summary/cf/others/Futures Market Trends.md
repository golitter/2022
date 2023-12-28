[F (codeforces.com)](https://codeforces.com/gym/104013/problem/F)

问题描述：给定A和D的计算公式，给d和P，求在d数组中连续（区间）内有几个正相关，几个负相关的数目。

其中，公式如下：
$$
A = \frac1n \sum_{i=1}^{n}(c_i - c_{i-1}) \\
D = \sqrt { \frac1n \sum_{i=1}^{n} (c_i - c_{i-1} - A)^2 }
$$
暴力 `O(n * n * )`：进行暴力枚举即可。

优化：可以从公式下手

- A

用前缀和维护`Ci - Ci-1`，除法很简单就是长度啥的。

- D

用前缀和维护`(Ci - Ci-1) * (Ci - Ci-1)`，将公式拆开。
$$
(c_i - c_{i-1} -A)^2 = \\
(c_i - c_{i-1})^2 + A^2 - 2A(c_i - c_{i-1}) \\
$$
此时，可以发现，只有A是无法进行预处理存储，其他的`(Ci - Ci-1) * (Ci - Ci-1)` 和 `Ci - Ci-1`都是可以用前缀和预处理。当将A求出后，用前缀和可以轻松得到`A*A + 2 * A * (Ci - Ci-1)`的值，只需要将$\sum$拆开就会发现。
$$
D = \sqrt{ \frac 1n (premul[n] - premul[1] + nA^2 - 2nA(presum[n] - presum[1])}
$$
代码：

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
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 21;
int a[N];
double premul[N], presum[N];
void inpfile();
void solve() {
    int d; double P; cin>>d>>P;
    int pos = 0, neg = 0;
    for(int i = 1; i <= d; ++i) {
        cin>>a[i];
        presum[i] = presum[i-1] + a[i] - a[i-1];
        premul[i] = premul[i-1] + pow(a[i] - a[i-1], 2);
    }
    for(int i = 2; i <= d; ++i) {
        double A = 0, D = 0;
        for(int j = i + 1; j <= d; ++j) {
            A = presum[j] - presum[i-1];
            A /= (j - i + 1);
            D = premul[j] - premul[i-1] + A * A * (j - i + 1) - 2 * (presum[j] - presum[i-1]) * A;
            D = sqrt(D/(j - i + 1));
            if(fabs(A) <= 1e-8) continue;
            if(fabs(D) <= 1e-8) {
                if(A > 0) pos++;
                if(A < 0) neg++;
            } else {
                if(A / D - P >= 1e-8) pos++;
                if(A / D + P <= 1e-8) neg++;
            }
        }
    }
    cout<<pos<<" "<<neg;
}
int main()
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

