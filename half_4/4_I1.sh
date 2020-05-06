#!/bin/bash

read n k

for (( i = 1; i <= k; i++ )); do
    for (( j = 1; j <= n; j++ )); do
        ind=$(( i * n + j ))
        if [ $i -eq 1 ]; then
            dp[$ind]="1"
        else
            dp[$ind]="0"
        fi
    done
done

for (( i = 1; i < k; i++ )); do
    for (( j = 1; j <= n; j++ )); do
        for (( x = 1; j * x <= n; x++ )); do
            ind_to=$(( (i + 1) * n + j * x ))
            ind_from=$(( i * n + j ))
            dp[$ind_to]=$(( ${dp[$ind_from]} + ${dp[$ind_to]} ))
        done
    done
done

sum=0
for (( i = 1; i <= n; i++)); do
    ind=$(( k * n + i ))
    sum=$(( $sum + ${dp[$ind]} ))
done

echo $sum

exit 0
