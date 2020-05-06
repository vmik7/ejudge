#!/bin/bash

read n
read -a arr

for (( i = 0; i < n; i++ )); do
	if [ ${a[${arr[$i]}]} == ""]; then
		(( a[${arr[$i]}] = 1 ))
	else
		(( a[${arr[$i]}]++ ))
	fi
done

maxv=0
for i in ${a[@]}; do
	if [ $i -gt $maxv ]; then
		maxv=$i
	fi
done

echo $maxv
