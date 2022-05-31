#!/usr/bin/bash

# read -rd '^D' input
#
# old_ifs="$IFS"
# IFS="\n"
#
# for line in $input; do
#     echo $line | cut -c 3 -
# done


while read; do
    echo "$REPLY" | cut -f 2-
done
