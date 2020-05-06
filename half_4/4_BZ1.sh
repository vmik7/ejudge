#!/bin/bash

read NT
for (( T = 0; T < NT; T++ )); do
    read s
    s=`echo $s | sed 's/< */</g'`
    s=`echo $s | grep -Eo '<[^/> ]+'`
    s=`echo $s | sed 's/<//g'`
    res="$res $s"
done

n=0
for s in $res; do
    find=0
    for (( i = 0; i < n; i++ )); do
        if [[ ${a[$i]} == $s ]]; then
            find=1
            break
        fi
    done
    if [[ $find -eq 0 ]]; then
        a[$n]=$s
        (( n++ ))
    fi
done

for (( i = 0; i < n; i++ )); do
    for (( j = i + 1; j < n; j++ )); do
        if [[ ${a[$i]} > ${a[$j]} ]]; then
            tmp=${a[$i]}
            a[$i]=${a[$j]}
            a[$j]=$tmp
        fi
    done
done

ans=`echo ${a[@]} | sed 's/ /;/g'`
echo $ans

exit 0;
