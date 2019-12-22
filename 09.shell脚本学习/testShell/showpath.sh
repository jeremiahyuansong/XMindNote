#!/bin/bash

for d in `find . -type d`;
do
echo `find $d -type f | wc -l` files in $d;
done
