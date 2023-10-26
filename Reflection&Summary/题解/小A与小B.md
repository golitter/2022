[E-小A与小B_【2023陕西暑假集训】一场快乐的比赛 (nowcoder.com)](https://ac.nowcoder.com/acm/contest/63827/E)

双向广搜，一个简单bfs，一个01bfs。

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

void inpfile();
void solve() {
    int n,m; cin>>n>>m;
    PII Asit,Bsit;
    vector<vector<char>> ph(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m));
    rep(i,0,n-1) {
        rep(j,0,m-1) {
            cin>>ph[i][j];
            if(ph[i][j] == 'C') Asit = {i,j};
            if(ph[i][j] == 'D') Bsit = {i,j};
        }
    }
    // dbgtt
    vector<int> fAx({-1, -1, -1, 1, 1, 1, 0, 0}), fAy({-1, 0, 1, -1, 0, 1, -1, 1}); // A 走的方向

    vector<int> fBx({1,-1, 0, 0}), fBy({0,0,1,-1}); // B 走的方向
    deque<array<int,4>> who; // x, y cnt, 1是A， 3是B
    vis[Asit.vf][Asit.vs] = 1;
    vis[Bsit.vf][Bsit.vs] = 1;
    who.push_front({Bsit.vf, Bsit.vs, 0,3});
    who.push_front({Asit.vf, Asit.vs, 0, 1});

    vis[Asit.vf][Asit.vs] = 1;
    vis[Bsit.vf][Bsit.vs] = 2;
    auto check = [&](int x, int y) -> bool { // check是否位置不合法
        if(x < 0 || x >= n || y < 0 || y >= m) return true;
        return false;
    };
    map<PII,int> mpii; // 记录cnt
    /**
     * 队列里的cnt可以用mpii代替
    */
    mpii[Asit] = 0;
    mpii[Bsit] = 0;
    int mi = INF;
    int ans = INF;
    while(who.size()) {
        auto tmp = who.front(); who.pop_front(); 
        int x = tmp[0], y = tmp[1], cnt = tmp[2], now = tmp[3];
        if(cnt > ans + 3) continue; // 做个剪枝，当已经有答案了，且当前cnt大于ans比较多，continue
        /**
         * 这里不能直接搜到结果就break。
         * 因为这两个人走的每个位置都是一个比较大的范围，可能先得到的答案不对。
         * 但是跑完全图可能超时，因此用个剪枝
        */
        if(now == 3 || now == 2) { // 是B
            rep(i,0,3) {
                int xx = x + fBx[i], yy = y + fBy[i];
                if(check(xx,yy)) continue;
                if(ph[xx][yy] == '#') continue;
                if(ph[xx][yy] == 'C') {
                        int luj = mpii[{xx,yy}];
                        int buj = cnt;
                        if(now == 3) buj++;
                        mi = max(luj, buj);
                        ans = min(mi, ans);
                        break;
                }
                if(vis[xx][yy] == 2 || vis[xx][yy] == 3) continue;
                if(vis[xx][yy] == 0) {
                    /**
                     * 这一步的B走到这，该位置没有被访问过。
                     * 有两种情况：
                     *      一，走了一次
                     *          还有一次的免费机会
                     *      二，走了两次
                     *          没有免费的机会了，又是一次轮回（
                     * 如果now == 3，表示还有新的两段开始，时间要加一
                     * 如果now == 2，表示之前用了记时间，还有一次的免费步数。
                     * 因此，采用 01bfs
                    */
                    vis[xx][yy] = 2;
                    int buj = cnt;
                    if(now == 3) buj++;
                    int nn = (now == 3 ? 2 : 3);
                    mpii[{xx,yy}] = buj;
                    if(now == 3) { // 
                        who.push_front({xx,yy,buj,nn}); // now == 3, 01bfs = 0
                    } else who.push_back({xx,yy,buj,nn}); // now == 2, 01bfs = 1
                } else {
                    if(vis[xx][yy] == 1) {
                        /**
                         * 这里记录时间，
                         * 两个时间取最大的，
                         * 对ans求最小的。
                         * （之前看成了求距离了！
                        */
                        int luj = mpii[{xx,yy}];
                        int buj = cnt;
                        if(now == 3) buj++;
                        mi = max(luj, buj);
                        ans = min(mi, ans);
                        break;
                    } else {
                        continue;
                    }
                }
            }

        } else { // A
            rep(i,0,7) {
                /**
                 * 同B，简单bfs
                */
                int xx = x +fAx[i], yy = y + fAy[i];
                if(check(xx,yy)) continue;
                if(ph[xx][yy] == '#') continue;
                if(ph[xx][yy] == 'D') {
                        int luj = mpii[{xx,yy}];
                        int buj = cnt + 1;
                        mi = max(luj, buj);
                        ans = min(mi, ans);

                        break;

                }
                if(vis[xx][yy] == 1) continue;
                if(vis[xx][yy] == 0) {
                    vis[xx][yy] = 1;
                    int buj = cnt + 1;
                    mpii[{xx,yy}] = buj;
                    who.push_back({xx,yy,buj,1});
                } else {
                    if(vis[xx][yy] != 1) {
                        int luj = mpii[{xx,yy}];
                        int buj = cnt + 1;
                        mi = max(luj, buj);
                        ans = min(mi, ans);
                        break;
                    } else {
                        continue;
                    }
                }
            }
        }
    }
    if(ans == INF) puts("NO");
    else {
        puts("YES");
        cout<<ans;
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

