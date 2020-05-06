#!/bin/bash

read n
read -a a

maxi=0; mini=0
for (( i = 1; i < n; i++ )); do
	if [ ${a[$i]} -gt ${a[$maxi]} ]; then
		maxi=$i
	fi
	if [ ${a[$i]} -lt ${a[$mini]} ]; then
		mini=$i
	fi
done

t=${a[$mini]}; a[$mini]=${a[$maxi]}; a[$maxi]=$t

for (( i = 0; i < n; i++ )); do
	echo "${a[$i]}"
done
