#!/bin/bash

read t
for (( T = 0; T < t; T++ )); do
	read l w h
	echo $(( ((l + l + w + w) * h + 15) / 16 ))
done
