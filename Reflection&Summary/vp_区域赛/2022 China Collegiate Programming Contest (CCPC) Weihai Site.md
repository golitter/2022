[Dashboard - 2022 China Collegiate Programming Contest (CCPC) Weihai Site - Codeforces](https://codeforces.com/gym/104023)

A题。类似于moba游戏，n支冠军队伍，每个冠军队伍中的人的游戏位置是固定的，再给m个人和他们对应的游戏位置（人名唯一，不会有一个人不同游戏位置的情况），求最多组成多少个队伍，队伍内至少有一个得过冠军。

先找到m个人最多可以组成多少个队伍，之后跟m个人中的得过冠军的人数进行min即可。

```cpp
void solve() {
    int n; cin>>n;
    set<string> s;
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j <= 5; ++j) {
            string str; cin>>str;
            s.insert(str);
        }
    }
    vector<int> a(6), b(6); 
    int m; cin>>m;
    for(int i = 0; i < m; ++i) {
        string str; int pos; cin>>str>>pos;
        if(s.count(str)) b[pos]++;
        a[pos]++;
    }
    a[0] = INF;
    int bs = accumulate(all(b), 0LL);
    int now = *min_element(all(a));
    int ans = min(now, bs);
    cout<<ans<<endl;
}
```

J题，博弈，但是又不像博弈。F和P玩游戏。一个长度为n的数组，里面元素初始都是正整数，有k个限制：每一个限制表示数组内值为x出现的次数的最多数量是y。每次操作可以让一个数减一，如果出现以下情况则游戏结束：

- 选择一个元素减一后，存在限制矛盾
- 数组内元素全为0

不能再操作的人输，找到谁赢。（题目保证，初始元素都是满足限制的）

可以直接发现对于每一次，结束的条件都是元素不能再往下减的，否则就是向最下面减，如果到达最下面元素的最大限制个数则最下面元素向上移动一之后再操作。观察输入，有y等于0的情况。这时候无论值多大都不能减到y，最多减到`y + 1`。综上，该题所有性质都找到了。移动奇偶就是答案了。

一种做法是遍历数组，找满足的最小可到达的值。可以用优先队列（不用也行，反正基本上快速可以找到的放法有很多），每一次找到最小的`y = 0`前面的值，将当前元素减到此，之后再将这个数量进行减减，防止与限制矛盾。

```cpp
void solve() {
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(auto &t: a) cin>>t;
    priority_queue<int,vector<int>,greater<int>> q;
    map<int,int> mii;
    for(int i = 0; i < k; ++i) {
        int x,y; cin>>x>>y;
        // y 等于0，表示大于x的值最好的可能是减到x + 1，直接将x + 1这个临界点放入队列
        if(!y) q.push(x+1);
        // 否则，将每个x出现的限制保存
        else mii[x] = y;
    }
    // now记录当前到哪个位置了
    int now = 0;
    LL cnt = 0;
    sort(all(a));
    for(auto t: a) {
        // 找到离t最近的临界点
        while(q.size() && q.top() <= t) {
            now = q.top();
            q.pop();
        }
        cnt += t - now;
        mii[now]--;
        // 如果该临界点为0，则now这个值的限制满足了，之后不能不能再减到该元素了，至少是该元素+1
        if(mii[now] == 0) {
            q.push(now+1);
        }
    }
    puts(cnt % 2 ? "Pico" : "FuuFuu");
}
```



另一种做法是按照`y = 0`进行划分，将所有元素划分为每一块，小于最小的y，使`ai < y`，之后对于每一个块进行第一种操作，算法复杂度为排序`O(nlog(n))`，核心操作`O(n)`。但是wa2，简单对拍没有找到问题，大对拍我datamaker造不出来（，细节太多了，难找，有空了再看

```cpp
void solve() {
    int n,k; cin>>n>>k;
    map<int,int> mp;
    vector<int> a(n);
    for(auto &t: a) cin>>t;
    a.push_back(-1);
    vector<int> pos;
    for(int i = 0; i < k; ++i) {
        int x,y; cin>>x>>y;
        if(y == 0) {
            pos.push_back(x);
        } else mp[x] = y;
    }
    pos.push_back(INF);
    sort(all(a)); sort(all(pos));
    int np = 0;
    map<int,vector<int>> mivi;
    for(auto t: a) {
        if(t <= pos[np]) mivi[pos[np]].push_back(t);
        else  {
            mivi[pos[++np]].push_back(t);
        }
    }
    LL cnt = 0;
    int last = 0, now;
    for(auto tt: mivi) {
        auto vs = tt.vs;
        now = last;
        for(auto t: vs) {
            if(t == -1) continue;
            cnt += t - now;
            mp[now]--;
            if(mp[now] == 0) now++;
        }
        last = tt.vf + 1;
    }
    puts(cnt % 2 ? "Pico" : "FuuFuu");
}
```

[2022 ccpc 威海 (2022 China Collegiate Programming Contest (CCPC) Weihai Site) - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/592928859)