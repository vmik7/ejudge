#!/bin/bash

read t
while [[ $t -gt 0 ]]; do
    read n m d

    for (( i = 0; i < n; i++ )); do
        read s
        tmp=( $s )
        for (( j = 0; j < m; j++ )); do
            x=$(( i * m + j ))
            a[$x]=${tmp[$j]}
        done
    done

    cnt=$(( n * m ))
    for (( i = 0; i < cnt; i++ )); do
        for (( j = i + 1; j < cnt; j++ )); do
            if [[ ${a[$i]} -gt ${a[$j]} ]]; then
                tmp=${a[$j]}
                a[$j]=${a[$i]}
                a[$i]=$tmp
            fi
        done
    done
    
    pos=$(( cnt / 2 ))

    ok=1
    ans=0
    for (( i = 0; i < cnt; i++ )); do
        if (( ${a[$i]} % d != ${a[0]} % d )); then
            ok=0
            break
        fi
        if [[ $i -lt $pos ]]; then
            ans=$(( ans + (${a[$pos]} - ${a[$i]}) / d ))
        else
            ans=$(( ans + (${a[$i]} - ${a[$pos]}) / d ))
        fi
    done

    if [[ $ok -eq 0 ]]; then
        echo -1
    else
        echo $ans
    fi

    t=$(( t - 1 ))
done

exit 0
