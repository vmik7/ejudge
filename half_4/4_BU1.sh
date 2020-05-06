#!/bin/bash

r="[aA]"

i=0
while read s; do
    if [[ $s =~ $r ]]; then
        continue
    fi
    ans[$i]=$s
    (( i++ ))
done
echo ${ans[@]}

exit 0
