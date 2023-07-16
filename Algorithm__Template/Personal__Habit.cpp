/**
 * 
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


inline int fread() // 快读
{
    int x = 0,f = 1;
    char ch = getchar();
    for(;!isdigit(ch);ch = getchar()) if(ch == '-')f = -f;
    for(;isdigit(ch);ch = getchar()) x = 10 * x + ch - '0';
    return x * f;
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