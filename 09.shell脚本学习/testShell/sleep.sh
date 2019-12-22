#!/bin/bash
#文件名: sleep.sh
echo Count:
tput sc
# 循环40秒
for count in `seq 0 40`
do
tput rc
tput ed
echo -n $count
sleep 1
done
:q