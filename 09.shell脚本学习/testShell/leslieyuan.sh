#!/usr/bin
test="1-2-3-4"
oldIFS=$IFS
IFS=-
for item in $test;
do
    echo $item;
done
IFS=$oldIFS

