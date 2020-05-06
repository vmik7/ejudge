#!/bin/bash

ipv4="^(([0-9]|([1-9][0-9])|(1[0-9][0-9])|(2[0-4][0-9])|(25[0-5]))\.){3}([0-9]|([1-9][0-9])|(1[0-9][0-9])|(2[0-4][0-9])|(25[0-5]))$"
ipv6="^([0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4}$"

read n
for (( i = 0; i < n; i++ )); do
    read s
    if [[ $s =~ $ipv4 ]]; then
        echo IPv4
    elif [[ $s =~ $ipv6 ]]; then
        echo IPv6
    else
        echo Neither
    fi
done

exit 0;
