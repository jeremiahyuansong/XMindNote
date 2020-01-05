# !/bin/bash
# 文件名: filestat.sh
if [ $# -ne 1 ];
then
echo "Usage is $0 basepath";
exit
fi
path=$1
declare -A statarray;
while read line;
do
ftype=`file -b "$line" | cut -d, -f1`
let statarray["$ftype"]++;
# 此处利用了子进程 使用<重定向输入
done <( find $path -type f -print )
echo ============ File types and counts =============
for ftype in "${!statarray[@]}";
do
echo $ftype : ${statarray["$ftype"]}
done
