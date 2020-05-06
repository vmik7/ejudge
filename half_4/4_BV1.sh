#!/bin/bash

read NT
for (( T = 0; T < NT; T++ )); do
    read n
    s=1
    for (( i = 2; i <= n; i++ )); do
        s="${s}*$i"
    done
    res=`echo $s | BC_LINE_LENGTH=0 bc`
    echo $res
done

exit 0;
