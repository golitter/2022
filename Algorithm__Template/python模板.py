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

# 排序
    # `sort()`是在原来数据上直接进行排序，返回值是None，
    # `sorted()`是返回原来数据的排序结果，不在原数据上排序。
l = [
    [1,3],
    [34,34],
    [3434,1],
    [2,3434]
]
l.sort(key=lambda x: (-x[0], x[1])) # 第一位是降序，第二位升序

# 翻转
    # 操作同排序。`reverse()`是在原来数据上进行的翻转，更改了原来数据；
    # 而`reversed()`则是返回一个翻转后的内容的迭代器，对原来数据不进行翻转。
s[::-1]

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


# 高精度
#  * 使用python char a = 'a'; ord(a) == 97 将字符转为对应的ASCII码
#  *                          chr(97) == 'a' 将ascii码转为对应的字符