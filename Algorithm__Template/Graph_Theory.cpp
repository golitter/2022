/**
 * 链式前向星 
 * 最短路：
 *          https://www.acwing.com/blog/content/462/
 * 最小生成树：
 *          
 * 
*/

#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e3;
const int INF = 0x3f3f3f3f;

// 链式前向星
int h[N]; // 链表头，初始为-1 memset(h, -1, sizeof(h));
int e[N]; // 链表内容
int ne[N]; // 链表中指向下一个元素的指针
int w[N]; // 链表内容的权重
bool vis[N];
int idx; // 
// <u   , -- c -- , v>  ( u --- w --> v
void add(int u, int v, int c) {
    e[idx] = v, w[idx] = c, ne[idx] = h[u], h[u] = idx++;
}
void init() {
    memset(h, -1, sizeof(h));
}
void dfs(int u) {
    vis[u] = 1;
    for (int i = h[u]; ~i; i = ne[i]) {
        if (!vis[e[i]]) {
            dfs(e[i]);
        }
    }
}


#include <vector>
// 邻接表
vector<vector<int> > adj;
void add() {
    int u,v;
    adj[u].push_back(v);
}
void dfs(int u) {
    if(vis[u]) return ;
    vis[u] = true;
    for(int i = 0; i < adj[u].size(); ++i) {
        dfs(adj[u][i]);
    }
}