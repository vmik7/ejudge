#!/bin/bash

read n

sum=0
for (( i=0; i < n; i++ )); do
	read val
	(( sum += val ))
done

echo -n $(( sum / n ))
echo -n '.'
(( sum %= n ))
for (( i=0; i < 3; i++ )); do
	(( sum *= 10 ))
	echo -n $(( sum / n ))
	(( sum %= n ))
done
