/**
 * 最大公约数 gcd
 * 线性逆元 inv
*/

#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;

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
    return (mod - mod/x) * inv(mod % a) % mod;
}
}}