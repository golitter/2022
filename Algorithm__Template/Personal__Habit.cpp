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