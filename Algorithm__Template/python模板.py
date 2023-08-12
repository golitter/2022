import sys 
def read(): # 快读模板
    return sys.stdin.readline().strip()

# 二维开1010 1010
dp = [[0] * 1010 for _ in range(1010)]

# 循环读取到文件末尾
try:
    while True:
        s = input()
except:
    pass

# 读取n,m，再读取n个数，m行
n, m = (int(_) for _ in input().strip().split(" "))
a = [int(_) for _ in input().strip().split(" ")]
for i in range(m):
    s = input()

# 读取的第二种方法，map映射
a1 = list(map(int, input().split()))

# 输出n个数在一行（无行尾空格）
ans = [1, 2, 3, 4]
for j in ans[:-1]:
    print(j, end=" ")
print(ans[-1])
