#!/bin/bash

template='^[_.]{1}[0-9]+[a-zA-Z]*_?$'

read n
for (( i = 0; i < n; i++ )); do
    read s
    if [[ $s =~ $template ]]; then
        echo VALID
    else
        echo INVALID
    fi
done

exit 0;
