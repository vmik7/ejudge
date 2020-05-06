#!/bin/bash

read n
for (( i = 0; i < n; i++ )); do
    read s
    t=$t$s
done
t=$(echo $t | sed 's/<\/a>/@/g')
t=$(echo $t | grep -Eo '<a[^@]*@')
t=$(echo $t | sed 's/ *<a[^>]href=\"//g')
t=$(echo $t | sed 's/<[^<>]*>//g')
t=$(echo $t | sed 's/\"[^>]*> */,/g')
t=$(echo $t | sed 's/ *@ */@/g')

for (( i = 0; i < ${#t}; i++ )); do
    if [[ ${t:i:1} == '@' ]]; then
        echo
    else
        echo -n "${t:i:1}"
    fi
done

exit 0;
