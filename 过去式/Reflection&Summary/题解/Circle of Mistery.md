[B-Circle of Mistery_2023牛客暑期多校训练营5 (nowcoder.com)](https://ac.nowcoder.com/acm/contest/57359/B)

[题解 | #2023牛客暑期多校训练营5#_牛客博客 (nowcoder.net)](https://blog.nowcoder.net/n/63fe0d0073124bb7ad1ceafe28cc74a2?f=comment)

问题描述：构造一个排列，使`i -> pi ->...`构成至少一个环，求这个排列最少的逆序对个数。

思路：

找结论：*使一个长度为n的排列形成一个大环所需要花费的最小逆序对数为 n - 1*。之后，用优先队列维护`[l, r]`中至少需要多少个才满足这个条件。

```cpp
        for(int j = i; j < n; ++j) {
            if(w[j] >= 0) {
                now += w[j];
                x++; 
            } else heap.push(w[j]);

            while(heap.size()) {
                auto tmp = heap.top();
                if(now + tmp >= k) { 
                    now += tmp;
                    /**
                     * 进队列的都是负数，x 代表的是去掉这些 
                    */
                    x++;
                    heap.pop();
                } else break;
            }
            if(now >= k && x) // 第一次大于k就可以结束了，对答案没有影响，因为后面还会用优先队列
            // j - i + (j - i - (x - 1)) 表示 [i, j] 这个区间内至少需要多少个满足这个条件 now > k;
                ans = min(ans, j - i + (j - i - (x - 1)));
```

AC代码：

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
/**
 * 结论：使一个长度为n的排列形成一个大环所需要花费的最小逆序对数为 n - 1
 * 证明：数学归纳法
 * 
 * 换题：至少需要几个数，使其和大于等于k
 *      1次 sort，
 *      多次，该解法：优先队列 + 贪心 得到最有可能的解
 * 
 *  由于区间的延长会使得区间长度
    减一这条贡献增大，所以我们舍弃的点的数量一定会严格减小。我们找到第一个可能满足条件的后缀
    （即正数和大于等于 ）并用贪心求出至少要舍弃多少点，接下来不断加入元素并查验是否能舍弃更少
    的点使得区间满足条件。在这一过程中使用优先队列维护所有可能被舍弃的点即可达到 O(n ** 2 * log2(n)) 的
    复杂度。

*/
void inpfile();
void solve() {
    int n,k; cin>>n>>k;
    vector<int> w(n);
    for(auto &t: w) cin>>t;
    int ans = INF;
    for(int i = 0; i < n; ++i) {
        if(w[i] >= k) { // 如果一个元素自环就可以满足条件，答案就是0
            ans = 0;
            break;
        }
        priority_queue<int> heap;
        int x = 0; // 
        int now = 0;
        for(int j = i; j < n; ++j) {
            if(w[j] >= 0) {
                now += w[j];
                x++; 
            } else heap.push(w[j]);

            while(heap.size()) {
                auto tmp = heap.top();
                if(now + tmp >= k) { 
                    now += tmp;
                    /**
                     * 进队列的都是负数，x 代表的是去掉这些 
                    */
                    x++;
                    heap.pop();
                } else break;
            }
            if(now >= k && x) // 第一次大于k就可以结束了，对答案没有影响，因为后面还会用优先队列
            // j - i + (j - i - (x - 1)) 表示 [i, j] 这个区间内至少需要多少个满足这个条件 now > k;
                ans = min(ans, j - i + (j - i - (x - 1)));
        }
    }
    if(ans == INF) cout<<-1;
    else cout<<ans;
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

