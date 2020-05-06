#!/bin/bash

read n
read s
read -a c

ans=0
for i in $s; do
    if [ $i -eq 0 ]; then
        continue
    fi
    ans=$(( ans + ${c[$(( $i - 1 ))]} ))
done

echo $ans

exit 0
