#!/bin/bash

function get_val {
    num=$1
    n=${#num}
    res=0
    for (( i = 0; i < n; i++ )); do
        res=$(( res * 10 + ${num:$i:1} ))
    done
    echo $res
}
function to_num {
    a=("$@")
    for i in ${a[@]}; do
        echo -n $i
    done
    echo
}
function to_arr {
    num=$1
    n=${#num}
    for (( i = 0; i < n; i++ )); do
        a[$i]=${num:$i:1}
    done
    echo ${a[@]}
}
function sort_num {
    num=$1
    l=$2
    r=${#num}
    a=(`to_arr $num`)
    for (( i = l; i < r; i++ )); do
        for (( j = i + 1; j < r; j++ )); do
            if [ ${a[$i]} -gt ${a[$j]} ]; then
                tmp=${a[$i]}
                a[$i]=${a[$j]}
                a[$j]=$tmp
            fi
        done
    done
    echo `to_num ${a[@]}`
}
function next_perm {
    num=$1
    n=${#num}
    a=(`to_arr $num`)

    if [ $n -le 1 ]; then
        echo $num
        return 0
    fi
    
    i=$(( n - 2 ))
    while [[ $i -ge 0 && ${a[$i]} -ge ${a[$(( i + 1 ))]} ]]; do
        (( i-- ))
    done

    if [ $i -lt 0 ]; then
        echo $num
        return 0
    fi

    j=$(( i + 1 ))
    for (( k = j; k < n; k++ )); do
        if [[ ${a[$k]} > ${a[$i]} && ${a[$k]} < ${a[$j]} ]]; then
            j=$k
        fi
    done

    tmp=${a[$i]}
    a[$i]=${a[$j]}
    a[$j]=$tmp

    num=`to_num ${a[@]}`
    echo `sort_num $num $(( i + 1 ))`
    return 1
}

read a b c

c_arr=`to_arr $c`
b_arr=`to_arr $b`
for (( i = 0; i < 10; i++ )); do
    b_cnt[$i]=0
done
for i in ${b_arr[@]}; do
    (( b_cnt[$i]++ ))
done

a=`sort_num $a`
while [ `get_val $a` -le `get_val $c` ]; do
    res=$(( `get_val $c` - `get_val $a` ))
    for (( i = 0; i < ${#b} - ${#res}; i++ )); do
        res="0${res}"
    done

    res_arr=`to_arr $res`
    for (( i = 0; i < 10; i++ )); do
        res_cnt[$i]=0
    done
    for i in ${res_arr[@]}; do
        (( res_cnt[$i]++ ))
    done

    if [[ ${b_cnt[@]} == ${res_cnt[@]} ]]; then
        echo YES
        echo "$a $res"
        exit 0
    fi
    a=`next_perm $a`
    if [ $? -eq 0 ]; then
        break
    fi
done

echo NO

exit 0
