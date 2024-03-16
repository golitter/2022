[Problem - I - Codeforces](https://codeforces.com/gym/103687/problem/I)

题目大意：给一个字符串$str$，有$q$次博弈。每次博弈给出$l,r$表示字符串左右边界，每次一个人可以从该子串的首或尾删除一个字符，如果操作前后是回文串则操作的人输。询问谁会赢，`Putata`先手。

思路：发现只要初始的子串$s_l...s_r$是回文串则游戏结束，`Budada`赢；否则，两人都不会删除一个使其成为回文串，但是当删除到只剩一个字符时一定是回文串，游戏结束。

因此，判断初始字串是否为回文串，不是回文串判断字符串奇偶即结束。

快速判子串是否为回文串采用哈希。感觉偏板子（

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
#include <cmath>
#include <functional>
#include <bitset>
#include <algorithm>
using namespace std;

// #define Multiple_groups_of_examples
// #define int_to_long_long
#define IOS std::cout.tie(0);std::cin.tie(0)->sync_with_stdio(false); // 开IOS，需要保证只使用Cpp io流 *
#define dbgnb(a) std::cout << #a << " = " << a << '\n';
#define dbgtt cout<<" !!!test!!! "<<'\n';
#define rep(i,x,n) for(int i = x; i <= n; i++)

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define vf first
#define vs second

typedef long long LL;
#ifdef int_to_long_long
#define int long long
#endif
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 21;
class strHash {
	typedef unsigned long long ULL;
public:
	strHash(const string& s) {
		this->str = "^" + s;
		dispose();
	}
	ULL get(int l, int r) {
		return h[r] - h[l - 1] * p[r - l + 1];
	}
    ULL get_syb(int l, int r) {
        return sybh[l] - sybh[r + 1] * p[r - l + 1];
    }
    bool same(int l, int r) {
        return get(l, r) == get_syb(l ,r);
    }
private:
	void dispose() {
		len = str.size();
		h.assign(len + 21, 0); p.assign(len + 21, 0);
        sybh.assign(len + 21, 0);
		h[0] = p[0] = 1;
		for(int i = 1; i <= len; ++i) {
			h[i] = h[i-1] * P + str[i];
			p[i] = p[i - 1] * P;
		}
        for(int i = len; i >= 1; --i) {
            sybh[i] = sybh[i + 1] * P + str[i];
        }
	}

	const ULL P = 11451;
	string str;
	ULL len;
	vector<ULL> h,p;
    vector<ULL> sybh;
};

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
void inpfile();
void solve() {
    // int n,q; cin>>n>>q;
    int n = fread(), q = fread();
    string s; cin>>s;
    strHash has1s(s);
    while(q--) {
        // int l,r; cin>>l>>r;
        int l = fread(), r = fread();
        if(has1s.same(l, r)) puts("Budada");
        else {
            puts( (r - l + 1) % 2 == 0 ? "Budada" : "Putata");
        }
    }
}
#ifdef int_to_long_long
signed main()
#else
int main()
#endif

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

