#!/bin/bash

read num
n=${#num}
for (( i = 0; i < n; i++ )); do
    a[$i]=${num:$i:1}
done

maxd=0
ind=0
for (( i = 0; i < n; i++ )); do
    if [ ${a[$i]} -gt $maxd ]; then
        maxd=${a[$i]}
        ind=$i
    fi 
done

if (( n % 2 )); then
    mid=$(( n / 2 ))
    if [ $ind -lt $mid ]; then
        echo -1
    elif [ $ind -gt $mid ]; then
        echo 1
    else
        echo 0
    fi
else
    mid_r=$(( n / 2 ))
    if [ $ind -lt $mid_r ]; then
        echo -1
    else
        echo 1
    fi
fi

exit 0;
