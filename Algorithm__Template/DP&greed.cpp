/**
 * 
 * 能用动态规划解决的问题，需要满足三个条件：最优子结构，无后效性和子问题重叠。
 * 
 * 
 * 
 * 区间DP：interval
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
#include <queue>
#include <ctime>
#include <random>
#include <sstream>
#include <numeric>
#include <stack>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define Multiple_groups_of_examples
#define rep(i,x,n) for(int i = x; i <= n; i++)
#define vf first
#define vs second

typedef long long LL;
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const int N = 1e2 + 21;

namespace golitter {
namespace interval {

string str;
int f[N][N];
void inpfile();
void solve() {
    // 求括号串的最少添加数
    // https://blog.csdn.net/weixin_43517157/article/details/106093699
    int len = str.size();
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) if(i == j) f[i][j] = 1; else f[i][j] = 0;
    }
    for(int i = len - 1; i >= 0; --i) {
        for(int j = i + 1; j < len; ++j) {
            f[i][j] = len;
            if( (str[i] == '(' && str[j] == ')') || ( str[i] == '[' && str[j] == ']')) {
                f[i][j] = min(f[i][j], f[i+1][j-1]);
            }
            for(int k = i; k < j; ++k) {
                f[i][j] = min(f[i][j], f[i][k] + f[k+1][j]);
            }
        }
    }
    // 将长度减去括号串的最少添加数就是最大匹配数
    cout<<len - f[0][len-1]<<endl;
}

}}