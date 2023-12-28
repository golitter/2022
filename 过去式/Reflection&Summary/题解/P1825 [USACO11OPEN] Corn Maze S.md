带传送门的bfs。

传送门是双向的，且每个是只有一对，用字符`A` - `Z`表示。

题目保证了一定有解，不会出现在两个传送门之间来回跳的情况。

简单bfs代码如下：

```cpp
void solve() {
    int n,m; cin>>n>>m;
    vector<string> ph(n);
    for(auto &t: ph) cin>>t;
    vector<vector<int>> vis(n, vector<int>(m));
    
    // x, y, cnt  横纵坐标 从起点到(x,y)的用时
    queue<array<int,3>> q; // x, y, cnt;

    // 存入每一对传送门的两个位置信息
    map<char, vector<array<int,2>>> mp;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(ph[i][j] == '@') {
                // 将起点push到队列
                q.push({i,j, 0});
                vis[i][j] = 1;
                // break;
            }
            // 将传送门存入
            if(ph[i][j] != '@' && ph[i][j] != '=' && ph[i][j] != '#' && ph[i][j] != '.') {
                mp[ph[i][j]].push_back({i,j});
            }
        }
    }
    while(q.size()) {
        auto tmp = q.front(); q.pop();
        int x = tmp[0], y = tmp[1], ct = tmp[2];
        for(int i = 0;i < 4; ++i) {
            int xx = x + fx[i], yy = y + fy[i];
            if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            if(ph[xx][yy] == '#' || vis[xx][yy]) continue;
            if(ph[xx][yy] == '=') {
                cout<<ct+1<<endl;
                return ;
            }
            if(ph[xx][yy] == '.') {
                vis[xx][yy] = 1;
                q.push({xx, yy, ct + 1});
            } else {
                // 如果是传送门，则要进行传送
                auto va = mp[ph[xx][yy]];
                for(auto &t: va) {
                    int sx = t[0], sy = t[1];
                    if(sx == xx && sy == yy) continue;
                    q.push({sx,sy,ct+1});
                }
            }
        }
    }
}
```



