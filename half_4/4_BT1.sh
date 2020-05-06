#!/bin/bash

i=0
while read s; do
    ans[$i]=$(echo $s | sed s/^[A-Z]/./ )
    (( i++ ))
done
echo ${ans[@]}

exit 0
