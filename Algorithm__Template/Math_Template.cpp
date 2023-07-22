/**
 * 简单结论 conclusion
 * 最大公约数 gcd
 * 基础数论-质数： prime
 * 线性逆元 inv
 * 快速幂 qmi
 * 排列组合 permutation_and_combination
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1e5 + 21;

namespace golitter {
namespace conclusion {

/**
 * 四面八方：y = -x + b , y = x + b , y = b, x = a 的结论
 * 恒有： y + x === ;
 *       y - x === ;
 *        b  === ;
 *        a  === ;
 * url: https://codeforces.com/contest/1850/problem/G
*/

}}

namespace golitter {
namespace gcd {
int gcd(int a, int b) {
    return b ? gcd(b, b%a) : a;
}
}}

namespace golitter {
namespace inv {
LL mod = 131;
// A / B % mod == A * inv(B, mod) % mod;
LL inv(LL a) {
    if(a == 0 || a == 1) return a;
    return (mod - mod/a) * inv(mod % a) % mod;
}
LL inv(LL x, LL mod) {
    if(x == 0 || x == 1) return x;
    return (mod - mod/x) * inv(mod % x) % mod;
}
}}

namespace golitter {
namespace prime {

// 判断质数
bool isPrime(int x) {
    if(x < 2) return false;
    for(int i = 2; i <= x / i; ++i) {
        if(x % i == 0) return false;
    }
    return true;
}

// 试除法分解质因数
void divide(int x) {
    for(int i = 2; i <= x / i; ++i) {
        if(x % i == 0) {
            int s = 0;
            while(x % i == 0) x /= i, s++;
            cout<<i<<" "<<s<<endl;
        }
    }
    if(x > 1) cout<<x<<" "<<1<<endl;
}

// 线性筛
int primes[N],cnt; bool st[N];
void get_primes(int n) {
    for(int i = 2; i <= n; ++i) {
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; ++j) {
            st[ primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

// 试除法求约数
vector<int> get_divisors(int x) {
    vector<int> res;
    for(int i = 1; i <= x / i; ++i) {
        if(x % i == 0) {
            res.push_back(i);
            if(i != x / i) res.push_back(x / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

/**

如果 N = p1^c1 * p2^c2 * ... *pk^ck
约数个数： (c1 + 1) * (c2 + 1) * ... * (ck + 1)
约数之和： (p1^0 + p1^1 + ... + p1^c1) * ... * (pk^0 + pk^1 + ... + pk^ck)

*/

}}

namespace golitter {
namespace qmi {
int m,k,p; // 求 m ^ k mod p
int qmi(int m, int k, int p) {
    int res = 1 % p, t = m;
    while(k) {
        if(k & 1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}


}}

namespace golitter {
namespace permutation_and_combination {
int C[N][N]; // C[a][b] 表示从a个苹果中选取b个的方案数
const int MOD = 1e9 + 33;
void comb(int n) {
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= i; ++j) {
            if(!j) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
}


}}