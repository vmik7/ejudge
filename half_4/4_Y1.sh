#!/bin/bash

read n m
for (( i = 0; i < n; i++ )); do
    read -a t
    for (( j = 0; j < m; j++ )); do
        a[$(( i * m + j ))]=${t[$j]}
    done
done

dp[0]=${a[0]}
for (( i = 1; i < n; i++ )); do
    dp[$(( i * m ))]=$(( ${dp[$(( (i - 1) * m ))]} + ${a[$(( i * m ))]} ))
done
for (( j = 1; j < m; j++ )); do
    dp[$j]=$(( ${dp[$(( j - 1 ))]} + ${a[$j]} ))
done
for (( i = 1; i < n; i++ )); do
    for (( j = 1; j < m; j++ )); do
        res1=$(( ${a[$(( i * m + j ))]} + ${dp[$(( (i - 1) * m + j ))]}))
        res2=$(( ${a[$(( i * m + j ))]} + ${dp[$(( i * m + (j - 1) ))]}))
        if [ $res1 -lt $res2 ]; then
            dp[$(( i * m + j ))]=$res1
        else
            dp[$(( i * m + j ))]=$res2
        fi
    done
done

echo ${dp[$(( (n - 1) * m + (m - 1) ))]}


exit 0
