[Problem - F - Codeforces](https://codeforces.com/contest/1791/problem/F)

![image-20231012185114964](https://cdn.789ak.com/img/image-20231012185114964.png)



# `set`

```cpp
void solve() {
    int n,q; cin>>n>>q;
    vector<int> a(n + 1);
    set<int> s;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        if(a[i] >= 10) s.insert(i);
    }
    auto calc = [&](int x) -> int {
        int tmp = 0;
        while(x) {
            tmp += x % 10;
            x /= 10;
        }
        return tmp;
    };
    while(q--) {
        int op,l,r;
        cin>>op;
        if(op == 1) {
            cin>>l>>r;
            // auto t = lower_bound(all(s),l);
            auto t = s.lower_bound(l);
            while(t != s.end() && *t <= r) {
                l = *t;
                a[l] = calc(a[l]);
                if(a[l] < 10) {
                    s.erase(l);
                }
                t = s.lower_bound(l+1);
                // t = lower_bound(all(s), l+1);
            }
        } else {
            cin>>l;
            cout<<a[l]<<endl;
        }
    }
}
```

# 线段树

```cpp
#define Multiple_groups_of_examples
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

int calc(int x) {
    int tmp = 0; while(x) {tmp += x % 10; x /= 10; } return tmp;
}
int w[N],n,m; // 注意 w[N] 开LL ( https://www.luogu.com.cn/problem/P2357
struct SegTree {
    int l,r,val,tag;
}tr[N << 2];
// 左子树
inline int ls(int p) {return p<<1; }
// 右子树
inline int rs(int p) {return p<<1|1; }
// 向上更新
void pushup(int u) {
    tr[u].tag = tr[ls(u)].tag & tr[rs(u)].tag;
}

// 建树
void build(int u, int l, int r) {
    if(l == r) {
        tr[u] = {l,r,w[l], w[l] < 10};
    }
    else {
        tr[u] = {l,r}; // 容易忘
        int mid = l + r >> 1;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
        pushup(u);
    }
}
// 修改
void modify(int u, int l, int r) {
    if(tr[u].l >= l && tr[u].r <= r && tr[u].tag) {
        return ;
    }
    // if(tr[u].l > r || tr[u].r < l) return ;
    if(tr[u].l == tr[u].r) {
        // cout<<tr[u].l<<" "<<tr[u].r<<" "<<tr[u].val<<"  "<<l<<" "<<r<<endl;
        tr[u].val = calc(tr[u].val);
        tr[u].tag = tr[u].val < 10;
        return ;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if(l <= mid) modify(ls(u), l, r);
    if(r > mid) modify(rs(u), l, r);
    pushup(u);
}
// 查询
LL query(int u, int l, int r) {
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].val;
    int mid = tr[u].l + tr[u].r >> 1;
    if(l <= mid) return query(ls(u), l,r);
    return query(rs(u), l, r);
}
void solve() {
    cin>>n>>m;
    for(int i = 1; i <= n; ++i) cin>>w[i];
    build(1, 1, n);
    while(m--) {
        int op,l,r; cin>>op;
        if(op == 1) {
            cin>>l>>r;
            modify(1,l,r);
        } else {
            cin>>l;
            cout<<query(1,l,l)<<endl;
        }
    }
}
```

