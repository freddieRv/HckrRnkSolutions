#!/usr/bin/bash

read N

count=0

for (( i = 0; i < $N; i++ )); do
    read n
    count=$((count + n))
done

avg=$((count / N))

printf "%.3e\n" $avg
