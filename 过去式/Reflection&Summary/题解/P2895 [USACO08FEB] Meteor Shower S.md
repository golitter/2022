[P2895 [USACO08FEB\] Meteor Shower S - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P2895)

bfs。难点在于处理走到该点时的时间与该处陨石降落的时间的比较。

可以发现，在某处可能有多个陨石降落，但是此题只考虑陨石降落的最小时间。因此，我们可以考虑根据陨石的降落位置和时间，对陨石降落地进行预处理，取最小时间。在此，将二维空间初始化为$INF$，因为题目保证了$T_i \le 1000$，因此等于$INF$的位置一定是没有陨石降落的。根据读入的陨石位置和时间预处理出该处陨石降落的最小时间。

之后进行bfs，在搜到的位置$x,y$处，如果$ph_{x,y} = INF$，表明该处一定没有陨石降落，输出即可。否则，需要判断该处合法：没有超界，没有访问过，到此处的时间大于该处陨石降落的时间。

> 坑点可能还在于：**陨石降落是在$[0, 300]$之间的，但是人是可以走到300之外的位置的。**

代码如下：

```cpp
namespace direction {
namespace d8 {
vector<int> fx({0, 0, 1, 1, 1, -1, -1, -1}), fy({1, -1, 1, 0, -1, 1, 0, -1});
}
namespace d4 {
vector<int> fx({0,0,1,-1}), fy({1,-1,0,0});
}
}
using namespace::direction::d4;

void inpfile();
void solve() {  
    int n; cin>>n;
    vector<vector<int>> ph(310, vector<int> (310, INF));
    vector<vector<int>> vis(310, vector<int>(310));
    for(int i = 0; i < n; ++i) {
        int x,y,t; cin>>x>>y>>t;
        // 预处理陨石位置附近的最小时间
        ph[x][y] = min(ph[x][y], t);
        for(int j = 0; j < 4; ++j) {
            int xx = x + fx[j], yy = y + fy[j];
            // 只用考虑小于0的情况，大于300的不用考虑。因为是陨石下降在[0, 300] 但是人是可以走到300之外的
            if(xx < 0 || yy < 0) continue;
            ph[xx][yy] = min(ph[xx][yy], t);
        }
    }
    queue<array<int,3>> q; // x, y, cnt;
    vis[0][0] = 1;
    q.push({0, 0, 0});
    while(q.size()) {
        auto tmp = q.front(); q.pop();
        int x = tmp[0], y = tmp[1], cnt = tmp[2] + 1;
        // 如果当前位置是INF，表示没有陨石会降落，输出返回即可
        if(ph[x][y] == INF) {
            cout<<cnt - 1<<endl;
            return ;
        }
        
        // 否则该处会用陨石降落，不是安全的地方
        for(int i = 0; i < 4; ++i) {
            int xx = x + fx[i], yy = y + fy[i];
            // 此时需要判断边界，虽然人是可以超出300的，但是显然303要比300003要优，
            // 如果在此不进行判断，则可能会死循环，RE，CE等
            if(xx < 0 || xx > 303 || yy < 0 || yy > 303) continue;
            // 之前走过
            if(vis[xx][yy]) continue;
            // 走到此时，该处就已经有陨石降落
            if(ph[xx][yy] <= cnt) continue;
            vis[xx][yy] = 1;
            q.push({xx, yy, cnt}); 
        }
    }
    cout<<-1<<endl;
} 
```

