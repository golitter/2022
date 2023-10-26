[Problem - C - Codeforces](https://codeforces.com/contest/1795/problem/C)

问题描述：n个人杯茶。第一个数组a表示第i杯茶有ai毫升，第二个数组b表示，第i个人品尝茶的毫升ai。总共会进行n轮品茶，在第j轮中，第i个人会品第`i - j + 1`杯茶bi毫升，之后ai减少bi，如果ai不足bi则ai减到0，第i个人喝了`min(ai,bi)`，ai为0。求每个人总共喝到的茶毫升量。

思路：根据条件可以知道，第i个人最多会喝到`1 ... i`杯茶，对于第j个茶来说，依次喝它的人顺序为`j j+1 j+2 ...`。按照题意考虑或者更加简单的操作，应该按照第j个茶来进行处理。因为，如果是按第i个人进行处理的话，它会喝`i-1, ...1`，其中前面的茶可能已经没有了，这时还需要多几步进行判断；而考虑第j个茶而言，是从`j j+1 ...`进行考虑，如果喝的少于bi,这时尽管也是需要判断但是由于是正序考虑更加符合人的逻辑，不容易犯错。（

对于第j个茶而言，可以喝它的有`j j+1 j+2 ...`，找到第一个k，使`bj + ... bk`之和大于等于ai，这时第j个茶就为0，不能再被k后面的人喝了。所以，朴素算法就是，找第j个茶第一个k，从j到k之间的人下标进行++。这个算法是`O(n*n)`，但是可以发现`bj + ...`这个处理可以用前缀和表示。

如果先求出b数组前缀和pre，对于第j个而言，它的贡献是j到k，那么就是二分找在pre数组中大于`pre[j-1] + aj`，为什么是这个式子呢，因为`pre[j-1]`一定是大于等于`pre[j-1]`的，所以找的一个前缀和范围就是在j到k之间的和，再将j到k之间进行++，此时可以用差分进行优化。

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

void inpfile();
void solve() {
    int n; cin>>n;
    // a b 不解释
    // pre b数组前缀和
    // dif 差分：完整bi的次数  dif数组注意开大点，因为 dif[j+1] 这一步会溢出，如果开的恰好（
    // resi 喝的小于bi的毫升总值
    vector<LL> a(n + 1), b(a), pre(a), resi(a), dif(n+2);
    for(int i = 1; i <= n; ++i) cin>>a[i];
    for(int i = 1; i <= n; ++i) cin>>b[i];
    for(int i = 1; i <= n; ++i) pre[i] = pre[i-1] + b[i];
    for(int i = 1; i <= n; ++i) {
        // j 表示第j个人喝的是小于bj的
        int j = upper_bound(pre.begin()+1, pre.end(), pre[i-1] + a[i]) - pre.begin() - 1;
        // 差分记录
        dif[i]++, dif[j+1]--;
        if(j + 1 <= n) {
            resi[j+1] += a[i] - (pre[j] - pre[i-1]);
        }
    }
    for(int i = 1; i <= n; ++i) {
        dif[i] += dif[i-1];
        // 输出：完整bi数量 * bi + 不完整的bi之和
        cout<<dif[i] * b[i] + resi[i]<<" \n"[i == n];
    }
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

