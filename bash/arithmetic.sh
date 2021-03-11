#!/usr/bin/bash

read expr

res=$(echo "$expr" | bc -l)

printf "%.3f\n" $res
