#!/bin/bash

n=63
m=100
len=16
st=49
h=62
cnt=1

function ind {
    echo $(( $1 * $m + $2 ))
}

for (( i = 0; i < n; i++ )); do
    for (( j = 0; j < m; j++ )); do
        a[`ind $i $j`]='_'
    done
done

read N 
for (( i = 0; i < N; i++ )); do
    for (( k = 1; k <= len; k++ )); do
        pos=$st
        for (( j = 0; j < cnt; j++ )); do
            a[`ind $h $pos`]=1
            pos=$(( pos + 4 * len ))
        done
        (( h-- ))
    done
    for (( k = 1; k <= len; k++ )); do
        pos=$st
        for (( j = 0; j < cnt; j++ )); do
            a[`ind $h $(( pos - k ))`]=1
            a[`ind $h $(( pos + k ))`]=1
            pos=$(( pos + 4 * len ))
        done
        (( h-- ))
    done
    st=$(( st - len ))
    len=$(( len / 2 ))
    cnt=$(( cnt * 2 ))
done

for (( i = 0; i < n; i++ )); do
    for (( j = 0; j < m; j++ )); do
        echo -n ${a[`ind $i $j`]}
    done
    echo
done

exit 0;
