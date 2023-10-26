[Dashboard - Pinely Round 2 (Div. 1 + Div. 2) - Codeforces](https://codeforces.com/contest/1863)

赛时：2 out of 9。

A挺简单的，看懂题面就行。

B有一点难度，但是看起来像快排，LIS，模拟了一下找到了正确方法。

C挺简单的，但是没对。原因：**在读完题面后基本思路就有了，模拟了一下发现是对的就开始写了，但是写的时候变了，不知道为什么跟开始的思路不一样，导致一直按照这个来写，导致wa了好久。**

C题就是就是取模什么的，但是我的那个方法造的很麻烦，我的是将空缺的放到前面，取个模，经过简单判断来确定位置。在简单判断模块中，由于我造的和模拟的样例都是数据量小的没有找到bug，一直wa5，错误原因是`k % (n + 1)`这一块的判断。

参考了jly和tourist的代码，发现他们的代码码风很好，跟我的高度吻合（。发现了更加简单的做法。就是将空缺的代码放到最后面，之后将前面一段移到后面即可。

同时也学到了一个新的stl函数`rotate(first, middle, last)`，将区间`[first, middle)`移到`[middle, last)`后面。虽然感觉学这个好似没有什么用对于我而言，但是搞不好我以后算法能力特别强的时候需要频繁用到这个函数呢，就像`max_element()`，`count()`这些对于我来说是比较常见的函数一样。



D题是赛后补的，也没有涉及到算法。行和列一定都是有偶数个可填充的才能构造成。

我第一次构造的方法是，行和列还差多少就优先少的来，但是是不对的，构造问题：

```
# 上面还有一行
me:

.WB.
.WB.
BWWB

std:

.WB.
.BW.
BWBW
```

之后发现，既然一定是偶数个存在，那么可以每次操作对行或列的两个一起进行操作。

```
XO
OX
```

代码：

```cpp
void solve() {
    int n,m; cin>>n>>m;
    vector<string> ph(n);
    vector<int> col(m), row(n);
    vector<int> c[m], r[n];
    for(auto &t: ph) cin>>t;
    rep(i,0,n-1) {
        rep(j,0,m-1) {
            if(ph[i][j] != '.') row[i]++, col[j]++;
            auto ch = ph[i][j];
            if(ch == 'L') c[j].push_back(i);
            if(ch == 'U') r[i].push_back(j);
        }
    }
    bool fg = false;
    rep(i,0,n-1) if(row[i] % 2 != 0) fg = true;
    rep(j,0,m-1) if(col[j] % 2 ) fg = true;
    if(fg) {
        puts("-1");
        return ;
    }
    // row.assign(n,0), col.assign(n,0);
    // vf vs   ==>  W, B
    rep(i,0,n-1) {
        int len = r[i].size();
        for(int j = 0; j < len; j += 2) {
            int y = r[i][j], yy = r[i][j+1];
            ph[i][y] = ph[i+1][yy] = 'W';
            ph[i+1][y] = ph[i][yy] = 'B';
        }
    }
    rep(j,0,m-1) {
        int len = c[j].size();
        for(int i = 0; i < len; i += 2) {
            int y = c[j][i], yy = c[j][i+1];
            ph[y][j] = ph[yy][j+1] = 'W';
            ph[y][j+1] = ph[yy][j] = 'B';
        }
    }
    for(auto t: ph) {
        cout<<t<<endl;
    }
}
```



### 总结

- **一定 一定 一定 要仔细读题**，记住：对于我这个水平的acmer是不需要争抢时间的，首要保证是AC。不能因为为了快那么一点时间，而飞快的读题，导致错误一些重要的hint而`dont AC`，这是**得不偿失的**。
- 每次比赛完都要补题，** 不仅仅是将没做出来的补了，还要将我AC的跟std题解和rand上知名大佬的算法进行比较，让我的代码更加精简。

