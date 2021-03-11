#!/usr/bin/bash

read x
read y
read z

if [[ $x -eq $y && $y -eq $z ]]; then
    echo "EQUILATERAL"
elif [[ ($x -eq $y && $x -ne $z) || ($x -eq $z && $x -ne $y) || ($z -eq $y && $x -ne $z) ]]; then
    echo "ISOSCELES"
else
    echo "SCALENE"
fi
