#!/bin/bash

reg="^[a-zA-Z0-9][a-zA-Z0-9_.-]*[a-zA-Z0-9]@[a-zA-Z0-9]+\.[a-zA-Z]{2,4}$"

read t
for (( i=0; i<t; i++ )); do
    read s
    if [[ $s =~ $reg ]]; then
        echo YES
    else
        echo NO
    fi
done

exit 0
