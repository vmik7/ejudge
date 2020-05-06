#!/bin/bash

function chk {
    s=$1
    l=0
    r=$(( ${#s} - 1 ))
    while [[ $l -lt $r ]]; do
        if [[ ${s:$l:1} != ${s:$r:1} ]]; then
            return 1
        fi
        (( l++ ))
        (( r-- ))
    done
    return 0
}

while read s; do
    if chk $s; then
        echo $s
    fi
done

exit 0;
