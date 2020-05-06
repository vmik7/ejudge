#!/bin/bash

read t
for (( T = 0; T < t; T++ )); do
	read n
	
	ans=0
	
	(( ans += n / 500 ))
	(( n %= 500 ))
	
	(( ans += n / 200 ))
	(( n %= 200 ))
	
	(( ans += n / 100 ))
	(( n %= 100 ))
	
	(( ans += n / 50 ))
	(( n %= 50 ))
	
	(( ans += n / 20 ))
	(( n %= 20 ))
	
	(( ans += n / 10 ))
	(( n %= 10 ))
	
	if [ $n -eq 0 ]; then
		echo $ans
	else
		echo '-1'
	fi
done
