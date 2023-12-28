```bash
# 运算符 格式 $((expr))  $[expr] -- [] 可以不用空格
a=1
a=$(( $a + 3))
a=$[ $a + 34]
```





```bash
# if-elif-else 格式
if [ $a -gt 1 ] # if 和 [] 之间有空格，[]之间也有空格 *必须*
then
	echo "a > 1"
elif [ $a -eq 1 ]
then
	echo "a == 1"
else
	echo "a < 1"
fi
```

```bash
# case-esac 格式
case $a in
"1")
	echo "this is 1"
;;  # break
"2")
	echo "this is 2"
;;
*) # default
	echo "this is *"
;;
esac
```

```bash
# loop语句 格式
a=1
sum=0
for((i = 0; i <= 100; ++i)) # 1
do
sum=$[$sum+$i]
done

echo $sum
for i in pwd, clear # 2
do
    echo "this is ${i}"
done
```

```bash
# while 格式
a=1
sum=0
while [ $a -le 100 ]
do
    sum=$[$sum + $a]
    a=$[$a + 1]
done
echo $sum
```

```bash
# read语法格式
#read [ -t seconds ] [ -p "sentence" ] rlt
read -t 12 -p "Please enter your name in 12 seconds : " nn
echo $nn
:<<!
在12秒内输入名字
!
```

```bash
# function
function sum() {
    if [ $1 -eq 0 ]
    then
        echo  0
        return 0
    fi 
    sum=$(sum $[$1 - 1])
    echo $[$sum + $1]
}
echo $(sum 10)
```

