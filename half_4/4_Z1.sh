#!/bin/bash

read s

n=${#s}
if [ $n -eq 1 ]; then
    echo 0
    exit 0
fi

i=0
while [[ $(( i + 1 )) -lt $n && ${s:$i:1} -ge ${s:$(( i + 1 )):1} ]]; do
    (( i++ ))
done

for (( j = 0; j < n; j++ )); do
    if [ $j -ne $i ]; then
        echo -n ${s:$j:1}
    fi
done
echo

exit 0
