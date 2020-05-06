#!/bin/bash

read t
while [[ $t -gt 0 ]]; do
    read n
    read -a a

    cnt=0
    for (( i = 0; i < n; i++ )); do
        find=0
        for (( j = 2; j * j <= ${a[$i]}; j++ )); do 
            if (( ${a[$i]} % j == 0 )); then
                find=1
                break
            fi
        done
        if [[ $find -eq 1 || ${a[$i]} -eq 1 ]]; then
            echo ${a[$i]}
            (( cnt++ ))
        fi
    done

    if [ $cnt -eq 0 ]; then
        echo -1
    fi

    t=$(( t - 1 ))
done

exit 0
