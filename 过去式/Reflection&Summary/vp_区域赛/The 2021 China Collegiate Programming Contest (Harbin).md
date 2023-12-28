[Dashboard - The 2021 China Collegiate Programming Contest (Harbin) - Codeforces](https://codeforces.com/gym/103447)

# J

给一个`n * m`的矩阵，求该矩阵中有少个数既是改行最小，也是该列最小的。

数据范围是1000，可以先预处理行、列最小值，之后挨个判断是不是行最小且列最小的。

预处理：`O(1e6)`，挨个判断：`O(1e6)`，时间上够。

```cpp
void solve() {
    int n,m; cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> row(n, INF), col(m, INF);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin>>a[i][j];
            row[i] = min(row[i], a[i][j]);
            col[j] = min(col[j], a[i][j]);
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cnt += (a[i][j] == row[i] && a[i][j] == col[j]);
        }
    }
    cout<<cnt<<endl;
}
```

# B

给长度为n(1e5)的数组A，`1 <= Ai <= 100`，让找最长的一个序列满足：
$$
A_{b_1} + A_{b_2} = A_{b_3} + A_{b_4} = ... = A_{b_{m-1}} + A_{b_m}
$$
且
$$
1 \le b_1 \lt b_2 \lt b_3 \lt ... \lt b_m \le n
$$
观察Ai每个值都是1到100的，很小。且`Ai + Aj`的值是在2到200之间的。

同时，b是递增的。

我们可以考虑从前往后找值，使到t值时，前面有`sum - t`存在，那么计数加2，就这样从2到200进行枚举即可。如果是存在一个交叉的区间是满足相加是sum的，那么只能贡献2个，剩下的就不行。

例如：1 2 4 3 1 4。`sum = 5`是最多的：4。如果选`1 4`，那么那个2，就没有贡献，如果选`2 3`，那么那个`1 4`就没有贡献。交叉的最多贡献2个。

因此，从2到200枚举sum，暴力找满足条件的，贡献加2并清空数组继续。找每个sum中最大的贡献就是答案。

```cpp
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto &t: a) cin>>t;
    int ma = 0;
    array<int, 221> mp;
    mp.fill(0);
    for(int i = 2; i <= 200; ++i) {
        int cnt = 0;
        mp.fill(0);
        for(auto &t: a) {
            if(t >= i) continue;
            if(mp[i - t]) cnt += 2, mp.fill(0);
            else mp[t]++; 
        }
        ma = max(ma, cnt);
    }
    cout<<ma<<endl;
}
```

# I

长度为n的数组A，可以用任意次操作，求最少操作次使A全为0。操作是，选m个元素下标，`B1 B2 ... Bm`，让`Abi`减少·`1 << i`。一个元素可以在一次操作中出现不止一次。

发现，这个操作只对二进制下1的个数有关。我们不去考虑每个元素怎么操作，怎么分。我们考虑这个数组的所有元素二进制下1的位置的个数怎么变化。

第一个样例

```text
5
1 2 3 4 5
```

在二进制下的表示

```text
001 010 011 100 101
```

总的二进制位置数量

```text
2 1 0
2 2 3
```

按从小到大

```text
0 1 2
3 2 2
```

因为操作中一个元素可以出现任意次，所以用两次操作，可以让`3 2 2`转为`1 0 0`，之后再用一次操作转为全0。

同理，剩下俩样例都是这样。

n最多1e5，表示有一位最多是1e5个。如果在第一个非0和最后一个非0的位置中间存在有0，那么高位就要向低位填充，即高位减一，低位加2，经过一直这样操作，就存在一个从最低位开始只有一个连续的非0段。那么可以用操作来消去。这样一直循环判断，时间赋值度`O(1e5 * 30)`，可以过。

```cpp
void solve() {
    int n; cin>>n;
    vector<int> a(34);
    for(int i = 0; i < n; ++i) {
        int t; cin>>t;
        auto calc = [&](int x) -> void {
            int p = 0;
            while(x) {
                a[p++] += (x % 2);
                x /= 2;
            }
        };
        calc(t);
    }
    int ans = 0, r = 0;
    // 找高位非0位置
    auto find_r = [&]() -> void {
        r = 0;
        for(int i = 0; i <= 30; ++i) {
            if(a[i] == 0) continue;
            r = i;
        }
    };
    // 从低位到非0高位减去这段最小的
    auto sub = [&]() -> void {
        int mi = INF;
        for(int i = 0; i <= r; ++i) {
            mi = min(mi, a[i]);
        }
        ans += mi;
        for(int i = 0; i <= r; ++i) {
            a[i] -= mi;
        }
    };
    
    // 先找高位r，减去，再找高位r
    find_r();
    sub();
    find_r();

    while(true) {
        // 用高位填充低位0
        int p = -1;
        for(int i = 0; i <= r; ++i) {
            if(a[i] == 0 && p == -1) {
                p = i;
                continue;
            }
            if(a[i] != 0 && p != -1) {
                a[p] = 2;
                for(int j = p + 1; j < i; ++j) a[j] = 1;
                a[i]--;
                if(a[i] == 0) p = i;
                else p = -1;
            }
        }
        if(p != -1) r = max(0, p-1);
        sub();
        find_r();
        // 如果高位就是0，表示只能全a[0]次操作
        if(r == 0) {
            ans += a[0];
            break;
        }
    }
    cout<<ans<<endl;
}
```



# D

两个数，不超过LL范围，让两个数分区去掉**相同**的数，还使这俩数的相除得到的分数是相同的。输出最简的经操作过的俩数。

俩数最多18位，搜索会爆，但是`1 << 18`不会爆，大概是1e6，那就是状压，枚举子集。先枚举分子可以的情况，之后在枚举分母可能的情况，判断是否做分分数相同。

不过这题比较恶心的是，在输出时忽略前导零，但是在删除时，还要加上前导零。因为每次都是这俩数减去一个**共同的数**，在删除时要考虑前导零。

因此需要加上一个map进行映射，将删除的数字用字符串进行拼接，排序，和删除后得到的数放入同一个pair中。对分母/分子继续枚举子集，根据：
$$
\frac{a} b = \frac x y
$$
得到分子/分母，判断分母/分子删除的数拼接的字符串在和得到的分子/分母是否在map中存在，存在找分子最小的即可。

**注意会爆LL，需要int128，不过只需要在做乘除时用int128，其他时候不用。**

```cpp
void solve() {
    int a,b; cin>>a>>b;
    string sa = to_string(a), sb = to_string(b);
    int alen = sa.length(), blen = sb.length();
    map<pair<string,int>, int> mp, mp2;
    for(int i = 0; i <= (1 << alen); ++i) {
        string del = "";
        int now = 0;
        for(int j = 0; j < alen; ++j) {
            if( (i >> j) & 1) {
                del += sa[j];
            } else now = now * 10 + (sa[j] - '0');
        }
        sort(all(del));
        mp[{del, now}] = 1;
    }
    int tp = LONG_LONG_MAX, btm;
    for(int i = 0; i <= (1 << blen); ++i) {
        string del = "";
        int now = 0;
        for(int j = 0; j < blen; ++j) {
            if( (i >> j) & 1) {
                del += sb[j];
            } else now = now * 10 + sb[j] - '0';
        }
        sort(all(del));
        if(!now) continue;
        if((__int128_t) a * now % (__int128_t)b) continue;
        int p = (__int128_t)a * now / b;
        if(mp.find({del, p}) != mp.end()) {
            if(p < tp) {
                tp = p;
                btm = now;
            }
        }
    }
    cout<<tp<<" "<<btm<<'\n';
}
```



不过我vp时，枚举子集枚举的是分子，之后找分母，找有无符合的分母。最后再判断前导0和位数什么的，结果wa9。不知道哪里错了，对拍没对出来（要改动数字的数据随机很难产生阿



[2021CCPC 哈尔滨(B D E I J)_.Ashy.的博客-CSDN博客](https://blog.csdn.net/woshilichunyang/article/details/132884126)