#!/bin/bash

read n
for (( i = 0; i < n; i++ )); do
    read s
    t="$t $s"
done

read q
for (( i = 0; i < q; i++ )); do
    read s
    ans=(`echo $t | grep -Eo "[a-zA-Z0-9_]+$s[a-zA-Z0-9_]+"`)
    echo ${#ans[@]}
done

exit 0;
