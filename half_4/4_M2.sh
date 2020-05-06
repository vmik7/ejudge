#!/bin/bash

read n k
if [ $n -le $k ]; then
    echo 2
else
    echo $(( (2 * n + k - 1) / k ))
fi

exit 0
