#!/bin/bash

read n

# (2)  2 2
# (4)  1 3
# (8)  3 6
# (16) 5 11

sum=2
z=2
d=2

for (( i = 1; i < n; i++ )); do
    sum=$(( sum * 2 ))
    payed=$(( (sum + d) / 2 ))
    z=$(( sum - payed ))
    d=$(( sum + d - payed ))
done

echo "$z $d"

exit 0;
