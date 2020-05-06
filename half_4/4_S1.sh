#!/bin/bash

read t
while [[ $t -gt 0 ]]; do
    read n
    read -a a

    k=$(( n / 2 ))

    for (( i = 0; i < k; i++ )); do
        for (( j = i + 1; j < k; j++)); do
            if [[ ${a[$j]} -lt ${a[$i]} ]]; then
                tmp=${a[$i]}
                a[$i]=${a[$j]}
                a[$j]=$tmp
            fi
        done
    done

    for (( i = n - k; i < n; i++ )); do
        for (( j = i + 1; j < n; j++)); do
            if [[ ${a[$j]} -gt ${a[$i]} ]]; then
                tmp=${a[$i]}
                a[$i]=${a[$j]}
                a[$j]=$tmp
            fi
        done
    done

    for (( i = 0; i < n; i++ )); do
        echo ${a[$i]}
    done

    t=$(( t - 1 ))
done

exit 0
