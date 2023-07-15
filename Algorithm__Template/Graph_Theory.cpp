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
int idx; // 
// <u   , -- c -- , v>  ( u --- w --> v
void add(int u, int v, int c) {
    e[idx] = v, w[idx] = c, ne[idx] = h[u], h[u] = idx++;
}
