/**
 * cf中不要轻易使用memset
 * t = 1e5 n 永远等于 1 -> G
 * 
 * 
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <random>
#include <sstream>
#include <numeric>
#include <stdio.h>
#include <algorithm>
using namespace std;

// #define codeforces_Multiple_groups_of_examples
#define rep(i,x,n) for(int i = x; i <= n; i++)

#define vf first
#define vs second

typedef long long LL;
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 21;

// #define int long long


// 当输入数据大于 1e6 时用快读
inline int fread() // 快读
{
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

void numeric() { // 数学
    LL k = 1e17;
    // cmath库里的数学尽量先乘个 1.0
    double d = sqrt(k * k); // × 会爆 原因：k*k 计算完转double，但是LL超了，因此是计算错误
    double d = sqrt(1.0 * k * k); // √
    // 同理LL
    int ik = 3;
    LL l = (LL)ik * ik; // 麻烦
    LL l = 1LL * ik * ik; // 敲代码好敲些
}

void inpfile();
void solve() {
    
    map<int,int> mii;
    unordered_map<int,int> umii;
    set<int> si;
    
    int n; cin>>n;
    vector<int> vi(n);
    vector<PII> vpi(n);
    vector<vector<int>> f(n, vector<int>(2,0));
}
int main() // signed main()
{
    #ifdef codeforces_Multiple_groups_of_examples
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