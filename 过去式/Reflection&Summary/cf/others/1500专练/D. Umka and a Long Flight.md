[Problem - 1811D - Codeforces](https://codeforces.com/problemset/problem/1811/D)

### 题目大意

- 给你一个整数 �*n* 和一个长为 ��+1*F**n*+1 宽为 ��*F**n* 的矩形。
- 数组 �*F* 为斐波那契数列，且 �1=1*F*1=1，�2=2*F*2=2。
- 问能否把该矩形分为几个最多有一对相同的正方形，其中第 �*x* 行，第 �*y* 列的必须单独划分为一个 1×11×1 的小正方形。

显然，边长为1的小方格一定要用2个，剩下的就是用2，3，...n阶的斐波那契数去拼凑。

那么我们可以贪心地从大的开始放，假设给定的边长为1的小方格是如下黑色方格，则：

1、如果黑色小方格所处位置比矩形的宽F[n]大，则可以将左边的大方格切掉（边长为F[n]），剩余右边部分翻转一下（使其长在水平方向，宽在竖直方向），那么黑色方格的坐标需要进行变换：(x,y) -> (F[n + 1] - y + 1,x)。

2、如果黑色小方格所处位置比F[n - 1]（要切去的右边大正方形边长为矩形的[宽F](https://www.zhihu.com/search?q=宽F&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"article"%2C"sourceId"%3A"619641668"})[n]，则左侧剩余部分长度就是F[n + 1] - F[n] = F[n - 1]，即由[斐波那契公式](https://www.zhihu.com/search?q=斐波那契公式&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"article"%2C"sourceId"%3A"619641668"})得出）要小，即黑色方格在大方格的左边，则“切掉”右边的大方格，并将左边剩余部分翻转一下（使其长在水平方向，宽在竖直方向），那么黑色方格的坐标就需要进行变换：由（x,y）-> (y,x)。

```cpp
vector<LL> fac(51);
void inpfile();
void solve() {
    LL n,x,y; cin>>n>>x>>y;
    auto dfs = [&](auto &&self, int n, int x, int y) -> bool {
        if(n == 1) return 1;
        if(y > fac[n]) return self(self, n-1, fac[n+1] - y + 1, x);
        else if(y <= fac[n-1]) return self(self, n-1, y, x);
        else return false;
    };
    puts(dfs(dfs, n,x,y) ? "YES" : "NO");
}
int main()
{
    fac[0] = 1, fac[1] = 1;
    for(int i = 2; i <= 45; ++i) fac[i] = fac[i-1] + fac[i-2];
    #ifdef Multiple_groups_of_examples
    int T; cin>>T;
    while(T--)
    #endif
    solve();
    return 0;
}
```

