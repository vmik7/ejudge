#!/bin/bash

s=(6 28 496 8128 33550336)

read t
while [[ $t -gt 0 ]]; do
    read n
    read -a a

    cnt=0
    for (( i = 0; i < n; i++ )); do
        for (( j = 0; j < 5; j++ )); do 
            if [ ${a[$i]} -eq ${s[$j]} ]; then
                echo ${a[$i]}
                (( cnt++ ))
                break
            fi
        done
    done

    if [ $cnt -eq 0 ]; then
        echo -1
    fi

    t=$(( t - 1 ))
done

exit 0
