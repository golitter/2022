/**
 * 常规字符串处理    STRING
 * KMP              KMP
 * trie      字典树 trie
 * manacher 马拉车 manacher
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

namespace golitter {
namespace STRING {
    /**
     * 字符串输入
    */
void String_Input() {
    // 1. string
    string str; getline(cin,str); // 一行
    // 2. 从下标1开始
    char ph[33]; cin>>ph + 1;
}
    /**
     * 子字符串
    */
void subString() {
    string str,sub; int pos, length;
    // 获取字串 从str的pos下标开始获取，子字符串的长度为length
    sub = str.substr(pos,length);
    // 获取substring在string中存在的下标位置，如果不存在为-1
    int pos = str.find(sub); // 注意：如果直接判断 str.find() == ... ，可能错误，因为str.find返回为size_t，没有进行隐式转换。
}
    /**
     * 字符串转换
    */
void String_Transform() {
    string str;
    // 全部转换为大写字母
    transform(str.begin(), str.end(),str.begin(), ::toupper);
    // 全部转换为小写字母
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    // 翻转
    reverse(str.begin(), str.end());
    /**
     * 字符串和数字之间的转换
    */
   int i; double d; float f;
   // 数字转字符串 -- to_string
   str = to_string(i); str = to_string(d); str = to_string(f);
   // 字符串转数字 -- sto / 数据类型前缀
   i = stoi(str); d = stod(str); f = stof(str);
   long long ll = stoll(str);
}
}}

namespace golitter {
namespace KMP {
/**
 * 
 * 给定一个长度为 n 的字符串 s，其 前缀函数 被定义为一个长度为 n 的数组 nxt。 其中 nxt[i] 的定义是：
* 如果子串 s[i] 有一对相等的真前缀与真后缀：s[k-1] 和 s[i - (k - 1)i]，那么 nxt[i] 就是这个相等的真前缀（或者真后缀，因为它们相等））的长度，也就是 nxt[i]=k；
* 如果不止有一对相等的，那么 pi[i] 就是其中最长的那一对的长度；
* 如果没有相等的，那么 nxt[i]=0。
* 简单来说 nxt[i] 就是，子串 s[i] 最长的相等的真前缀与真后缀的长度。
*/
vector<int> prefix_function(string s) { 
  int n = (int)s.length();
  vector<int> nxt(n);
  for (int i = 1; i < n; i++) {
    int j = nxt[i - 1];
    while (j > 0 && s[i] != s[j]) j = nxt[j - 1];
    if (s[i] == s[j]) j++;
    nxt[i] = j;
  }
  return nxt;
}

}}

namespace golitter {
namespace trie {
    
const int N = 2e5 + 21;
int tr[N][26],idx;
int cnt[N];
void insert(string str) {
    int p = 0;
    for(auto t: str) {
        int u = t - '0';
        if(!tr[p][u]) tr[p][u] = ++ idx;
        p = tr[p][u];
    }
    cnt[p]++;
}
int query(string str) {
    int p = 0;
    for(auto t: str) {
        int u = t - '0';
        if(!tr[p][u]) return 0;
        p = tr[p][u];
    }
    return cnt[p];
}

}
namespace trie_01 { // XOR https://zhuanlan.zhihu.com/p/373477543?utm_id=0

const int N = 1e5 + 21;
const int  M = N * 31;
int tr[M][2], a[N], idx;
int s[N];
void insert(int x) {
    int p = 0;
    for(int i = 30; i >= 0; --i) {
        int u = x >> i & 1; // 获得x二进制表示的第i位数
        if(!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
    }
}
int query(int x) {
    int p = 0, res = 0;
    for(int i = 30; i >= 0; --i) {
        int u = x >> i & 1;
        if(tr[p][!u]) {
            p = tr[p][!u];
            res += 1<<i;
        } else {
            p = tr[p][u];
            // res = res << 1 + u;
        }
    }
    return res;
}
void solve() {
    int n; //idx = 0;
    for(int i = 0; i <= n; ++i) {
        tr[i][1] = 0; tr[i][0] = 0;
        s[i] = 0;
    }
    n = fread();
    int res = 0;
    for(int i = 1; i <= n; ++i) a[i] = fread();
    rep(i,1,n) {
        s[i] = s[i-1] ^ a[i];
    }
    rep(i,0,n) {
        insert(s[i]);
        int t = query(s[i]);
        res = max(res,  t);
    }
    cout<<res<<'\n';
}
}
}


namespace golitter {
namespace manacher {
// https://zhuanlan.zhihu.com/p/549242325

vector<int> manacher(string &a) {// max(vector<int> P.size() ) - 1;
    string b = "$|";
    for(auto t: a) {
        b += t;
        b += '|';
    }
    int len = b.size();
    vector<int> hw(len);
    int maxright(0), mid(0);
    for(int i = 1; i < len; ++i) {
        if(i < maxright) hw[i] = min(hw[mid*2 - i], hw[mid] + mid - i);
        else hw[i] = 1;
        while(b[i - hw[i]] == b[i + hw[i]]) hw[i]++;
        if(i + hw[i] > maxright) {
            maxright = i + hw[i];
            mid = i;
        }
    }
    a = b;
    return hw;
}

}}