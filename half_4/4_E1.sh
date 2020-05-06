#!/bin/bash

read a
read b

if [[ 0 -ne $(echo $a | grep -c $b) ]]; then
    echo YES
else
    echo NO
fi

exit 0
