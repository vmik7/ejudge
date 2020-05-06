#!/bin/bash

read n m
if (( (n - 1 + (m - 1) * n) % 2 )); then
    echo first
else
    echo second
fi

exit 0
