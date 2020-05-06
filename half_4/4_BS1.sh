#!/bin/bash

n=0
while read line; do
	a[$n]=$line
	(( n++ ))
done

for (( i = 0; i < 2 * $n; i++ )); do
	echo -n "${a[$(( i % n ))]} "
done
