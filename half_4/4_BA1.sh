#!/bin/bash

read NT
for (( T = 0; T < NT; T++ )); do
    read n
    s=$(echo "sqrt($n)" | bc)
    if (( s * s == n )); then
        echo 1
    else
        echo 0
    fi
done

exit 0
