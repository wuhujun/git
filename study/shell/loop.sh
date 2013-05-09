#!/bin/bash
filename=sale_record20110701.bcp.Z
result=` expr substr $filename 1 23 `
tail="txt"
c="$result$tail"
echo $c
echo $result
Ui="kin"
echo $Ui
ui=90
echo $ui
ui=what
echo $ui ;
for n in {1..10} 
do
	echo $n
done
#使用expr计算表达式的值。
e=`expr 2 + 10`
echo $e
e=`expr 3 \* 100`
echo $e
e=`expr 34 / 3`
echo $e
a=23 
b=30
e=`expr $a + $b`
echo $e
#在shell脚本中使用浮点数计算
var1=`echo " scale=4; 23.44 / 5" | bc`
echo $var1 
exit 0 
