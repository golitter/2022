/**
 * 不定向输入       UndirectedInput
 * 二分         binary
 * 离散化       discretization
 * 基础dp模板 
 * 搜索         Bfs_Dfs
 * STL
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream> // 需要包含这个头文件
using namespace std;


namespace golitter {
namespace UndirectedInput {
#include <sstream> // 需要包含这个头文件
void solve() {
    stringstream put_str;
    string str;
    getline(cin, str); // 获取一行字符串
    int n(0), p;
    put_str<<str; // 将str重定向输入到put_str
    while(put_str>>p) n++; // 从put_str重定向读入数据
    cout<<n;
}

}}

namespace golitter {
namespace binary {

bool check(int mid) {
    ;
}
void solve() {
    int l,r;
    int ans;
    while(l <= r) {
        int mid = l + r >> 1;
        if(check(mid)) {
            // ans = mid; // 最小值最大
            l = mid + 1;
        } else {
            // ans = mid; // 最大值最小
            r = mid - 1;
        }
    }
    {
        // 最大值最小
        while(l < r) {
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        } // output: r
    }
    {
        // 最小值最大
        while(l < r ) {
            int mid = (l + r + 1) >> 1;
            if(check(mid)) l = mid;
            else r = mid - 1;
        } // output: l
    }
}

}}

namespace golitter {
namespace discretization {

const int N = 333;
int a[N],last[N],id[N];
void test1() { // 重复数字一样 1 222 222     -----> 1 2 2 url: https://www.luogu.com.cn/record/115366968
    int n; cin>>n; for(int i = 1; i <= n; ++i) cin>>a[i],id[i] = a[i];
    sort(id+1, id+1+n);
    int cnt = unique(id+1, id+n+1) - id - 1;
    for(int i = 1; i <= n; ++i) {
        last[i] = lower_bound(id+1, id+cnt+1, a[i]) - id;
    }
    {        // STL处理
            // n
        vector<int> a,id,last; id.assign(a.begin(), a.end());
        sort(id.begin(), id.end());
        id.erase(unique(id.begin(), id.end()), id.end());
        for(int i = 0; i < n; ++i) {
            last[i] = lower_bound(id.begin(), id.end(),a[i]) - id.begin();
        }
    }
}

void solve() {
        ;
    }

}}


namespace golitter {
namespace dp_template {
const int N = 1e5 + 21;
int a[N];
// 最长上升子序列 
int LIS()
{
    int n; cin>>n;
    for(int i = 1; i <= n; ++i) cin>>a[i]; 
    vector<int> f;
    for(int i = 1; i <= n; ++i)  {
        auto pos = lower_bound(f.begin(), f.end(), a[i]);
        if(pos == f.end()) {
            f.push_back(a[i]);
        } else *pos = a[i];
    }
    cout<<f.size();

    return 0;
}

}}

#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
namespace golitter {
namespace STL {
void Vector() {
    /**
     * vector<int> vi || vi(n)
     * size()     返回元素个数
     * clear()    清空
     * front() back()   第一个，最后一个元素
     * []
    */
}
void String() {
    /**
     * string str;
     * substr(pos, len);
     * size()
     * reverse(bg, ed);
    */
}
void Queue() {
    /**
     * queue<int> q;
     * size()
     * clear()
     * push()
     * front()
     * pop()
    */
}
void Priority_queue() {
    /**
     * priority_queue<int> heap 大顶堆 [大的在上面]
     * priority_queue<int, vector<int>, greater<int>> q; 小顶堆 [小的在上面]
     * size()    push()     pop()     top()
    */
}
void Stack() {
    /**
     * stack<int> s;
     * size()
     * clear()
     * push()
     * pop()
     * top()
    */
}
void Map() {
    /**
     * size()   clear()
     *     
     * multimap:
     *  multimap<PII,PII> mmpp;
     * mmpp.insert(pair<PII,PII>({x1,y1}, {x2,y2}));
     * count()    find()
     * 
     * ** multimap不支持 [] 操作。** *
    */
}
void Set() {
    /**
     * set<int> s;
     * insert()   erase()
     * count()
    */
}
void Unordered_All() {
    /**
     * 
    */
}
}}

namespace golitter {
namespace Bfs_Dfs {
// void dfs(int k)
// 　{
// 　  if  (到目的地) 输出解;
// 　　　else
// 　　　　for (i=1;i<=算符种数;i++)
// 　　　　　if  (满足条件) 
// 　　　　　　　{
// 　　　　　　　　保存结果;
// 　　　                  Search(k+1)
//                              恢复：保存结果之前的状态{回溯一步}
// 　　　　　　　}
// 　}

// void bfs() {
//     // queue
// }
}}