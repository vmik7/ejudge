#!/bin/bash

read num
n=${#num}
for (( i = 0; i < n; i++ )); do
    a[$i]=${num:$i:1}
    b[$i]=${num:$i:1}
done

for (( i = 0; i < n; i++ )); do
    for (( j = 0; j < n; j++ )); do
        if [ ${b[$j]} -gt ${b[$i]} ]; then
            tmp=${b[$i]}
            b[$i]=${b[$j]}
            b[$j]=$tmp
        fi
    done
done

k=$(( (n - 1) / 2 ))
d=${b[$k]}
echo $d

cnt=0
for (( i = 0; i < n; i++ )); do
    if [ ${a[$i]} -ne $d ]; then
        echo -n ${a[$i]}
        (( cnt++ ))
    fi
done
if [ $cnt -ne 0 ]; then
    echo
else
    echo NULL
fi

exit 0;
