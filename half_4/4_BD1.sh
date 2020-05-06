#!/bin/bash

read n
for (( i = 0; i < n; i++ )); do
    read -a s
    for (( j = 0; j < n; j++ )); do
        a[$(( i * n + j ))]=${s[$j]}
    done
done

for (( k = 0; k < n; k++ )); do
    for (( i = 0; i < n; i++ )); do
        for (( j = 0; j < n; j++ )); do  
            val=$(( ${a[$(( i * n + k ))]} + ${a[$(( k * n + j ))]} ))
            if [ $val -lt ${a[$(( i * n + j ))]} ]; then
                a[$(( i * n + j ))]=$val
            fi
        done
    done
done

for (( i = 0; i < n; i++ )); do
    for (( j = 0; j < n - 1; j++ )); do
        echo -n "${a[$(( i * n + j ))]} "
    done
    echo ${a[$(( i * n + n - 1 ))]}
done

exit 0
