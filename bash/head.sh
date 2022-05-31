#!/usr/bin/bash

read -r

head -n 22 | tail -n +12

sort -t $'\t' -k2 -nr
