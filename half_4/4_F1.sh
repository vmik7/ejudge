#!/bin/bash

read template
template=^\($template\)$
while read line; do
	if [[ $line =~ $template ]]; then
		echo YES
	else
		echo NO
	fi
done

exit 0
