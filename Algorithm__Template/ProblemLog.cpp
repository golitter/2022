/**
 * niukeduoxiao
 * cf
 * 
*/
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
#include <algorithm>
using namespace std;

// #define Multiple_groups_of_examples
#define IOS std::cout.tie(0);std::cin.tie(0)->sync_with_stdio(false);
#define dbgnb(a) std::cout << #a << " = " << a << '\n';
#define dbgtt cout<<" !!!test!!! "<<endl;
#define rep(i,x,n) for(int i = x; i <= n; i++)

#define all(x) (x).begin(),(x).end()
#define vf first
#define vs second

typedef long long LL;
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 21;


namespace golitter {
namespace niukeduoxiao {
namespace Three { // 2023年7月24日 20点44分
/**
 * 注意特判
*/

/**
 * 转化题意：// https://ac.nowcoder.com/acm/contest/57357/D
 *      n*n 01字符串，可对行/列进行翻转(0 -> 1, 1 -> 0)，问最少多少次将n*n字符串转为全0/全1。
 * 
 * 赛时想法：
 *      将原始字符串转为全0或全1，用了好多特判。
 * 答案解法：
 *      转为与第一行相同或第一列相同 + 对行列1的分析。 
 * 反思：
 * 想到算法不要紧，还要认真的找其他优化细节。
*/
void solve_D() {
    int n; cin>>n;
    vector<string> s(n);
    rep(i,0,n-1) cin>>s[i];
    // rr 按行进行查找
    // cc 按列进行查找
    int rr = 0, cc = 0;
    string z = s[0], f = s[0];
    // z 为第一行字符串，f进行翻转
    for(auto &t: f) if(t == '1') t = '0'; else t = '1';
    // 行首1个数
    int rr1 = count(s[0].begin(), s[0].end(), '1');


    for(int i = 1; i < n; ++i) {
        if(s[i] == z) ;
        else if(s[i] == f) rr ++;
        else { // 存在第三种情况 -1
            puts("-1");
            return ;
        }
    }
    int res = INF;
    // rr, n - rr 相同与不相同是相对的，因此需要选一个相对较小的
    // rr1, n - rr1 转换次数少的 转0/1
    res = min(rr, n - rr) + min(rr1, n - rr1);
    int cc1 = 0; // 列首1个数
    for(int i = 0; i < n; ++i) {
        cc1 += s[i][0] - '0';
    }
    for(int i = 1; i < n; ++i) {
        bool zt = true, ft = true;
        for(int j = 0; j < n; ++j) {
            if(s[j][i] != s[j][0]) zt = false; 
        }
        for(int j = 0; j < n; ++j) {
            if(s[j][i] == s[j][0]) ft = false; 
        }
        if(zt) ;
        else if(ft) cc++;
        else { // 同行操作
            puts("-1");
            return ;
        }
    }
    res = min(res, min(cc, n - cc) + min(cc1, n - cc1));
    cout<<res;
}

/**
 * 转化题意：// https://ac.nowcoder.com/acm/contest/57357/E
 *      n点m边边权为1有向图，求dfs树是否都是最短路树 
 * 赛时想法：
 *      无
 * 题解：
 *      因为权重都是1，重边自环可以用set去重。用向前星存边点信息，加一个dist数组记录到root的距离，之后dfs遍历即可。
 * 反思：
 *      题意抽象，转换具象。
*/
// E 题
const int N = 5e5 + 21;
int e[N], ne[N], h[N],idx;
int dist[N];
bool vis[N];
int n,m;
bool fg;
set<int> hasver;
void add(int u, int v) {
    e[idx] = v; ne[idx] = h[u]; h[u] = idx++;
}
void dfs(int u, int fu) { // dfs遍历
    // hasver.insert(u); // 当前dfs路径插入u点
    for(int i = h[u]; ~i && fg; i = ne[i]) {
        int y = e[i];
        if(vis[y] == 1) continue;
        // if(hasver.count(y) != 0) continue; // 如果现在路径中存在该点，不再进行接下来的遍历
        if(!dist[y]) dist[y] = dist[u] + 1; // 如果距离为0，表名该点在之前的dfs树路径中没有出现过
        else if(dist[y] != dist[u] + 1) { // 如果之前在dfs路径中出现，且现在的dfs树路径中<u,1>长度不等于之前的dist，表示不能满足所有的树都是最短路
            fg = false;
            return ;
        }
        vis[u] = 1;
        dfs(y,u);
        vis[u] = 0;
    }   
    // hasver.erase(u); // 当前点向下回溯完后，删除当前点
}
void solve_E() {
    idx = 0;
    cin>>n>>m;

    memset(h, -1, sizeof(int)*(n + 21)); // memset(h, -1, sizeof(h)) 会超时
    memset(dist, 0, sizeof(int)*(n + 21));
    memset(vis, 0, sizeof(bool)*(n + 21));
    set<PII> spii;
    hasver.clear();
    for(int i = 0; i < m; ++i) {
        int u,v; cin>>u>>v;
        if(u != v && spii.count({u,v}) == 0) {
            add(u,v);
            spii.insert({u,v});
        }
    }
    fg = true;
    vis[1] = 1;
    dfs(1,-1);
    if(!fg) puts("No");
    else puts("Yes");


}



/**
 * 转化题意： // https://ac.nowcoder.com/acm/contest/57357/G
 *      求n*m的字符有多少个中心对称的子串
 * 赛时思路：
 * 无
 * 题解：
 *      二维马拉车，二维马拉车就是二维哈希中心对称进行比较的
 *      用二维哈希的话，这题就是个比较板的题咯
 * 反思：
 *      之前没有二维哈希板子
*/

const int B[] = {223333333, 773333333}; // P1 P2
const int P = 1000002233;

LL *p[2];

void init(int N) { // 初始化
    p[0] = new LL [N];
    p[1] = new LL [N];
    p[0][0] = p[1][0] = 1;
    for (int i = 1; i < N; i++) {
        p[0][i] = p[0][i - 1] * B[0] % P;
        p[1][i] = p[1][i - 1] * B[1] % P;
    }
}


struct StringHash2D { // 字符串二维哈希 板子来源：https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63032157
    using LL = long long;
    int n, m;// n * m 
    vector<vector<LL>> h;
    StringHash2D(const vector<string> &a) {
        n = a.size(); 
        m = (n == 0 ? 0 : a[0].size());
        h.assign(n + 1, {});
        for (int i = 0; i <= n; i++) { // 分配 n * m 
            h[i].assign(m + 1, 0);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) { // 二维哈希
                h[i + 1][j + 1] = (h[i][j + 1] * B[0] % P + h[i + 1][j] * B[1] % P + 
                    (P - h[i][j]) * B[0] % P * B[1] % P + a[i][j]) % P; 
            }
        }
    }

    LL get(int x1, int y1, int x2, int y2) { // p1 = (x1, y1), p2 = (x2, y2) [p1, p2)
        return (h[x2][y2] + h[x1][y1] * p[0][x2 - x1] % P * p[1][y2 - y1] % P + 
            (P - h[x1][y2]) * p[0][x2 - x1] % P + (P - h[x2][y1]) * p[1][y2 - y1] % P) % P;
    } 
};
void solve_G() {
    // dbgtt
    int n,m; cin>>n>>m;
    vector<string> a(n);
    // dbgtt
    init(2e3 + 21);
    // dbgtt
    for(auto &t: a) cin>>t;
    // dbgtt
    auto b = a;
    for(int i = 0; i < n; ++i) { // b 为a的翻转
        for(int j = 0; j < m; ++j) b[i][j] = a[n - i - 1][ m - j - 1];
    }
    StringHash2D strhs1(a), strhs2(b);
    auto isSame = [&](int x1, int y1, int x2, int y2) -> bool {
        return strhs1.get(x1,y1,x2,y2) == strhs2.get(n - x2,m - y2,n - x1,m - y1);
    };
    LL ans = 0;
    // dbgtt
    // 奇数
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            int l = 1, r = min( min(i + 1, n - i), min(j + 1, m - j));
            // dbgtt
            while(l <= r) {
                int x = (l + r)/2;
                if(isSame(i - x + 1, j - x + 1, i + x, j + x)) l = x + 1;
                else r = x - 1;
            }
            ans += l - 1;
        }
    }
    // dbgtt
    // 偶数
    // dbgnb(ans);
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < m; ++j) {
            int l = 1, r = min( min(i, n - i), min(j, m - j));
            while(l <= r) {
                int x = (l + r)/2;
                if(isSame(i - x, j - x, i + x, j + x)) l = x + 1;
                else r = x - 1;
            }
            ans += l - 1;
        }
    }
    cout<<ans;
}

}}}

namespace golitter {
namespace cf {
namespace div2_887 {

/**
 * 转化题意：// https://codeforces.com/contest/1853/problem/B
 *      输入n, k。类似斐波那契数列 f(k) = n; f(k-2) + f(k-1) = f(k) f(i) >= 0，非负数。求满足要求的数列有多少个。
 * 赛时思路：
 *      推公式， f(k) = fib(k - 2) + fib(k - 3) ，爆LL。
 *      范围 n = 2e5, k = 1e9，当时感觉暴力 n * k 一定超时，没写暴力。
 * 解题：
 *      暴力，fib是呈指数递增的，三四十次就爆int了，int ~ 2e9，因此暴力不会挂，时间复杂度 O(n * 50) -> O(2e5 * 50)
 * 反思：
 * 时间复杂度是算的越来越差了，之前的调和级数O(nlog(n))也是，算时间复杂度要认真点。 
*/
void solve_B() {
    int n,k; cin>>n>>k;
    int cnt = 0;
    for(int i = 0; i <= n; ++i) {
        int suf = n, pre = i;
        bool fg = true;
        for(int j = 0; j < k - 2; ++j) {
            int ssuf = pre;
            pre = suf - ssuf;
            suf = ssuf;
            if(pre > suf) fg = false;
            if(pre < 0 || suf < 0) fg = false;
            if(!fg) break; 
        }
        if(fg) cnt++;
    }
    cout<<cnt<<endl;
}
/**
 * 转化题意： // https://codeforces.com/contest/1853/problem/C
 *      给定n个数，表示每次删除第ai个数，经过k次后最小值是多少
 * 赛时思路：
 *      无
 * 解题：
 *      反向模拟，如果 x 位于 ai 和 ai+1 之间，它将移动到 x - i  的新位置，因为在它之前的 i 个位置已经被删除了。
*/
void solve_C_1() {
    int n,k; cin>>n>>k;
    vector<int> vi(n);
    for(auto &t: vi) cin>>t, --t;
    LL ans = 0;
    for(int i = 0; i < n; ++i) {
        if(ans < vi[i]) break;
        if(ans >= vi[i] + 1LL * i * (k - 1)) ans += k;
        else ans += (ans - vi[i]) / i + 1;
    }
    cout<<ans + 1<<endl;
}
void solve_C_2() {
    int n,k; cin>>n>>k;
    vector<int> vi(n);
    for(auto &t: vi) cin>>t;
    LL ans = 1;
    int j = 0;
    while(k--) {
        while(j < n && vi[j] <= ans + j) ++j;
        ans += j;
    }
    cout<<ans<<endl;
}


}

namespace div3_888 {
/**
 * A ~ C 题意理解错了，没有真正看题就做题，导致有好多细节没有注意到，下次注意，不能在这里出错了。
*/

/**
 * D // https://codeforces.com/contest/1851/problem/D
 * 题意：
 *      1到n的排列得到的前缀和少了一个元素，请问根据现在的前缀和数组能不能得到一个排列。
 * 赛时思路：
 *      赛时开始没有读到排列，导致错了好久。发现对于1到n的排列，总和为 n * (n + 1) / 2。
 *      要么在结尾丢，要么在尾前丢。根据这个性质，可以先求出差分数组，然后找大于n获得存在两次的那个数，
 * 同时找在1到n中没有存在的数的和和次数。如果只存在一个不存在的数，表示在尾，其他表示在非尾位置。
 * 判断一下 未出现数和 与 大于n或者存在两次的数 是否相等即可。
 * 总结
 *      少看了题，等把题意真正理解了，发现时间不多了。
 *      看题一定要认真，做到不遗漏。
*/

void solve_D() {
    int n; cin>>n;
    vector<LL> vi(n);
    for(int i = 1; i < n; ++i) cin>>vi[i];
    vector<LL> f(n+1);
    LL cnt = 0, tg = -1, sum = 0;
    for(int i = 1; i < n; ++i) {
        LL t = vi[i] - vi[i-1];
        if(t >= 1 && t <= n && !f[t]) f[t] = 1;
        else tg = t;
    }
    for(int i = 1; i <= n; ++i) {
        if(!f[i]) cnt++, sum += i;
    }
    if(tg == -1) tg = sum;
    if(cnt <= 2 && tg == sum) {
        puts("YES");
    } else puts("NO");
}



/**
 * DAG 记忆化dfs dp 有向图的dp。
 * E // https://codeforces.com/contest/1851/problem/E
 * lambda表达式函数递归形式  https://blog.csdn.net/J__M__C/article/details/125437699?ops_request_misc=&request_id=&biz_id=102&utm_term=lambda%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B3%9B%E5%9E%8B%E9%80%92%E5%BD%92&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-125437699.142^v91^insert_down1,239^v3^control&spm=1018.2226.3001.4187
*/

void solve() {
    int n,m; cin>>n>>m;
    vector<int> cost(n);
    for(auto &t: cost) cin>>t;
    for(int i = 0; i < m; ++i) {
        int a; cin>>a;
        cost[a-1] = 0;
    }
    vector<vector<int>> g(n);
    for(int i = 0; i < n; ++i) {
        int t; cin>>t;
        for(int j = 0; j < t; ++j) {
            int a; cin>>a;
            g[i].push_back(a-1);
        }
    }
    vector<int> f(n, -1);
    auto dfs = [&](auto &&dfs, int x) -> int {
        if(f[x] != -1) return f[x];
        if(g[x].empty()) return f[x] = cost[x];
        int ans = 0;
        for(auto t: g[x]) {
            ans += dfs(dfs, t);
        }
        return f[x] = min(ans, cost[x]);
    };
    for(int i = 0; i < n; ++i) cout<<dfs(dfs,i)<<" "; puts("");
}

}

}}