[Problem - B - Codeforces](https://codeforces.com/contest/1/problem/B)

问题描述：excel有两种情况，

- `Rr_nCc_n`：`R行数C列数`
- `ZZZ(列数)行数`。

对这两个进行相互转换。



细节：

- 准确判断这两种情况

```cpp
string str; cin>>str;
auto posR = str.find("R"), posC = str.find("C");
bool fg = false;
if(isdigit(str[posR+1])) fg = true;
if(fg && posR != -1 && posC != -1 && posR < posC) {
	// 第一种情况
} else {
	// 第二种情况
}
```

- 十进制到26进制（带字母）：注意 'A'，'Z'。

```cpp
col += ( (cv % 26 == 0 ? 25 : cv % 26 - 1) + 'A');
if(cv % 26 == 0) cv--;
cv /= 26;
```

AC代码：

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
    int n; cin>>n;
    while(n--) {
        string str; cin>>str;
        auto posR = str.find("R"), posC = str.find("C");
        bool fg = false;
        if(isdigit(str[posR+1])) fg = true;
        if(fg && posR != -1 && posC != -1 && posR < posC) {
            // R ... C ...
            int rv = 0, cv = 0;
            posR++;
            while(isdigit(str[posR])) {
                rv = rv * 10 + str[posR] - '0';
                posR++;
            }
            posR++;
            while(isdigit(str[posR])) {
                cv = cv * 10 + str[posR] - '0';
                posR++;
            }
            string col = "";
            while(cv) {
                col += ( (cv % 26 == 0 ? 25 : cv % 26 - 1) + 'A');
                if(cv % 26 == 0) cv--;
                cv /= 26;
            }
            reverse(all(col));
            cout<<col; cout<<rv<<endl;
        }  else {
            int pos = 0;
            while(isalpha(str[pos])) {
                pos++;
            }
            int rv = 0;
            string s = "";
            for(int i = 0; i < pos; ++i) {
                s += str[i];
            }
            int cv = 0;
            for(int i = 0; i < pos; ++i) {
                cv = cv * 26 + (s[i] - 'A' + 1);
            }
            while(isdigit(str[pos])) {
                rv = rv * 10 + str[pos] - '0';
                pos++;
            }
            cout<<'R'<<rv<<'C'<<cv<<endl;
        }
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




