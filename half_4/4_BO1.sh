#!/bin/bash

read n
read -a arr

for (( i = 0; i <= 100; i++ )); do
	(( a[$i] = 0 ))
done

for (( i = 0; i < n; i++ )); do
	(( a[${arr[$i]}]++ ))
done

for (( i = 0; i <= 100; i++ )); do
	if [ ${a[$i]} == 1 ]; then
		ans=$i
	fi
done

echo $ans
