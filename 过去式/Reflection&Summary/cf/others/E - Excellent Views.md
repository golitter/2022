[Problem - E - Codeforces](https://codeforces.com/gym/103185/problem/E)

问题描述：数组H大小都不相同。从i到j是可行的，当且仅当
$$
不存在k，使 \\
|i - k| \leq |i - j|, \quad H_k > H_j
$$


暴力 `O(n * n)`，从当前点向两边进行扩散。

```cpp
void solve() {

    int n;cin>>n;
    for(int i = 1; i <= n; ++i) cin>>a[i];
    for(int i = 1; i <= n; ++i) {
        int ma = -INF;
        int cnt = 0;
        int len = max(i - 1, n - i);
        for(int j = 0; j <= len; ++j) {
            int lvidx = i - j, rvidx = i + j;
            if(lvidx < 1) {
                ma = max({ma, a[rvidx]});
                if(a[rvidx] >= ma) cnt++;

            } else {
                ma = max({ma, a[lvidx], a[rvidx]});
                if(a[lvidx] >= ma) cnt++;
                if(a[rvidx] >= ma) cnt++;
            }
        }
        cout<<cnt - 2<<" ";
    }
}
```

优化：单调栈，对于i算出到左边和到右边第一个大于下标为i的元素值得长度或下标，用差分对半记录即可。

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
#include <stack>
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
/**
 * https://codeforces.com/gym/103185/problem/E
 * 题意：对每一个i找到满足条件的j, 其中条件为：不存在k, 使 abs(i - k) <= abs(i - j) && Hj  < Hk 成立
 * 解法：std：https://github.com/Diego1149/ICPC-Latam-2020 （好像是用线段树写的
 *      other：https://blog.csdn.net/m0_53807008/article/details/119065842
 * 
 * 思路：单调栈
 *      两次单调栈。这里为了简单，假设 1 <= i < j <= n
 *      第一次找 对于j来说，从i到j中满足条件的元素（这里j是题意中的i。
 *      第二次找，对于i来说，从i到j中满足条件的元素（这里i就是题意中的i。
 * e.g. 下标：      ... 符合条件的  i  符合条件的 ...
 *      对于第一次来说：
 *          比a[i]小的最大元素（记为A）下标找到，将比a[i]小的最大元素下标对应得pre数组赋值 i - 1，表示，最后一个小于A的下标位置。
 *          对于那个最大元素下标（记为idx），使 idx 对应的元素可以worth的长度为 [idx, i - 1]的一半。
 *          记录用差分记录即可。
 *      第二次，倒着来一边，同第一次。
*/
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 21;
int a[N];
int pre[N], suf[N];
int lef[N], rig[N];
void inpfile();
void solve() {
    int n; cin>>n;
    for(int i = 1; i <= n; ++i) cin>>a[i];
    a[n+1] = INF; // 让 n + 1 等于inf， 0 等于inf，因为要让所以的都出栈
    stack<int> sk;
        // 考虑a[i]对左边的贡献
    sk.push(1);
    for(int i = 2; i <= n+1; ++i) {
        // 如果当前 H 大于 上一个H，将上一个H对应的下标进行记录
        while(sk.size() && a[i] > a[ sk.top()]) {
            pre[ sk.top()] = i - 1; // 将i - 1进行赋值，表示到i - 1 ，大于的条件一直是成立的
            sk.pop();
        }
        sk.push(i);
    }
    for(int i = 1; i <= n; ++i) {
        lef[i+1]++; // 将i + 1 先进行++，表示有一个贡献
        if(pre[i] != n) // 如果等于n，表示，恒成立，不用--，
                        // 否则，只能到达 (i + pre[i]) / 2 的下标，利用差分 就是 [ r + 1]--
            lef[ (i + pre[i]) / 2 + 1]--;
    }
        // 考虑a[i]对右边的贡献
    // 思路及代码同上
    sk.push(n);
    a[0] = INF;
    for(int i = n - 1; i >= 0; --i) {
        while(sk.size() && a[i] > a[ sk.top()]) {
            suf[ sk.top()] = i + 1;
            sk.pop();
        }
        sk.push(i);
    }
    for(int i = 1; i <= n; ++i) {
        rig[i-1]++;
        if(suf[i] != 1)
            rig[ (i + suf[i] + 1) / 2 - 1]--;
    }
    // 差分前缀和
    for(int i = 1; i <= n; ++i) lef[i] += lef[i-1];
    for(int i = n; i >= 1; --i) rig[i] += rig[i+1];
    
    for(int i = 1; i <= n; ++i) cout<<lef[i] + rig[i]<<" ";
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

[Gym - 103185E E - Excellent Views_流锡的博客-CSDN博客](https://blog.csdn.net/m0_53807008/article/details/119065842)