#!/bin/bash

read n
read -a a

mini=0; maxi=0
for (( i = 1; i < n; i++ )); do
	if [ ${a[$i]} -lt ${a[$mini]} ]; then
		mini=$i
	fi
	if [ ${a[$i]} -gt ${a[$maxi]} ]; then
		maxi=$i
	fi
done

if [ $maxi -lt $mini ]; then
	t=$mini; mini=$maxi; maxi=$t
fi

l=$(( mini + 1 )); r=$(( maxi - 1 ))
while [ $l -lt $r ]; do
	t=${a[$l]}; a[$l]=${a[$r]}; a[$r]=$t
	(( l++ ))
	(( r-- ))
done

for (( i = 0; i < n; i++ )); do
	echo ${a[$i]}
done
