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
LL a[N];
LL b[N];
void inpfile();
void solve() {
    LL n,m; cin>>n>>m;
    rep(i,1,n) cin>>a[i];   
    LL l = 0, r = 1e18+1;
    auto check = [&](LL mid) -> bool {
        LL now = 0; // now记录当前机器人用了多少步
        rep(i,1,n) b[i] = 0; // 将b数组（d数组）进行置零
        rep(i,1,n) {
            if(i == n) { // 如果当前位置是最后一个需要特判，是否已经大于等于mid，已经则continue，否则则进行叠加
                if(b[i] >= mid) continue;
            }
            // 走到当前位置，机器人用了一次，b数组加上ai一次
            now ++; 
            b[i] += a[i];
            LL last = mid - b[i]; // 还差多少才满足 bi >= mid
            if(last <= 0) continue; // 如果差值小于等于 表示已经符合，机器人走到下一个位置即可
            LL cnt = last / a[i] + (last % a[i] == 0 ? 0 : 1); // 否则，机器人需要来回摆动多少次
            now += cnt * 2LL; // 摆动次数 * 2 是机器人又用了多少次
            b[i] += a[i] * cnt; // 当前位置进行叠加
            b[i + 1] += a[i + 1] * cnt; // 同时机器人摆动时向右边的位置也进行了叠加
            if(now > m) { // 机器人走的次数大于now，表示不可能，返回 false
                return false;
            }
        }
        return now <= m;
    };
    if(m < n) {
        puts("0");
        return ;
    }
    while(l < r) {
        LL mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    cout<<l<<endl;
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