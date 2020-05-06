#!/bin/bash

read -a a

ans=0
for (( i = 1; i <= ${a[0]}; i++ )); do
	if [[ $((${a[$i]} <= 544)) -ne 0 && $ans -eq 0 ]]; then
		ans=$i
	fi
done

if [ $ans -eq 0 ]; then
	echo 'No crash'
else
	echo "Crash $ans"
fi
