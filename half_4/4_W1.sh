#!/bin/bash

read n
a[0]=1; a[1]=0
b[0]=0; b[1]=0

for (( i = 0; i < n; i++ )); do
    pa=$(( ${a[0]} * 4 ))
    pb=$(( ${a[0]} * 6 ))
    a[1]=${a[0]}
    b[1]=${b[0]}
    a[0]=$pa
    b[0]=$pb
done

echo $(( ${a[0]} + ${a[1]} + ${b[0]} + ${b[1]} ))

exit 0;
