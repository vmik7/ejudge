#!/bin/bash

read s
echo "scale = 3; $s" | bc -l
