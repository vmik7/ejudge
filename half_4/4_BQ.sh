#!/bin/bash

read n m

i=0
while read line; do
	a[$i]=$line
	(( i++ ))
done

for (( i = $n; i <= $m; i++ )); do
	echo -n "${a[$i]} "
done
