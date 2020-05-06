#!/bin/bash

read h m H M

ans=0
while [[ $h -ne $H || $m -ne $M ]]; do
    if [ $m -eq 30 ]; then
        (( ans++ ))
    elif [ $m -eq 0 ]; then
        cnt=$h
        if [ $cnt -gt 12 ]; then
            cnt=$(( cnt - 12 ))
        elif [ $cnt -eq 0 ]; then
            cnt=12
        fi
        ans=$(( ans + cnt ))
    fi

    (( m++ ))
    if [ $m -ge 60 ]; then
        (( h++ ))
        if [ $h -ge 24 ]; then
            h=$(( h - 24 ))
        fi
        m=$(( m - 60 ))
    fi
done

if [ $m -eq 30 ]; then
        (( ans++ ))
    elif [ $m -eq 0 ]; then
        cnt=$h
        if [ $cnt -gt 12 ]; then
            cnt=$(( cnt - 12 ))
        elif [ $cnt -eq 0 ]; then
            cnt=12
        fi
        ans=$(( ans + cnt ))
    fi

echo $ans

exit 0;
