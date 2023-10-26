[Problem - 1765N - Codeforces](https://codeforces.com/problemset/problem/1765/N)

![image-20231004212521844](https://cdn.789ak.com/img/image-20231004212521844.png)

发现如果是无前导0最小数那么在保证删除k个数时第1位是最小的，第二位一定是相对最小的，且答案第一位和第二位在原位置的间隔是小于等于还可以删除的位数的。

因此，对于原数字长度位`n`，要删除`k`，那么答案长度为`n - k`，这`n - k`位每一个都是优先选小的，如果不能再选较大值（对于首位比较特殊，不能出现前导零，因此首位从1开始），可以从第1位开始进行枚举0到9将`n - k`位进行填充。

每一次选完后，这一个数前面可能还有没有选的，但是由于已经选过该位，再选前面的会导致答案变大，因此不要。

可以用10个队列存入每一个数的下标，用一个变量`last`记录上一个在原数字中选择的数的下标。对每一位依次遍历0到9这10个队列，如果当前数字队列满足条件：

- 这个数字的下标大于等于上一个下标+1
- 这个数字的下标跟上一个下标之间差值小于等于还可以删除的次数

满足这些条件时表示下一位是该数字，之后将这个`last`和还能删除的位进行更新，退出循环到下一位进行判断即可。

代码：

```cpp
void solve() {
    string s; cin>>s;
    int k; cin>>k;
    int n = s.size();
    queue<int> q[10];
    for(int i = 0; i < n; ++i) q[s[i] - '0'].push(i);
    string ans = "";
    int last = 0, len = n - k;
    for(int i = 0; i < len; ++i) {
        for(int j = (i == 0); j < 10; ++j) {
            // 如果数字下标小于等于上一个下标，进行出队（因为以后都用不上了，大于上一位的下标才是可能有用的
            while(q[j].size() && q[j].front() < last) q[j].pop();
            // 如果满足当前位和上一位之间差值是小于等于还可以删除的数次数，表示可以
            if(q[j].size() && q[j].front() - last <= k) {
                ans += j + '0';
                k -= q[j].front() - last;
                last = q[j].front() + 1;
                break;
            }
        }
    }
    cout<<ans<<endl;
}
```

[CF1765N Number Reduction - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/solution/CF1765N)