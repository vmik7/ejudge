#!/bin/bash

i=1
n=1
while [ $i -lt 100000 ]; do
    for (( j = n; j >= 1; j-- )); do
        a[$i]="$j/$(( n + 1 - j ))"
        (( i++ ))
    done
    (( n++ ))
done

while read i; do
    echo ${a[$i]}
done

exit 0
