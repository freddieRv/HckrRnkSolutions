#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumSwaps function below.

def minimumSwaps(arr):
    swaps = 0
    swaped = True

    while swaped:
        swaped = False
        for i in range(len(arr) - 1):
            if arr[i] > arr[i + 1]:
                swaped = True
                swaps += 1
                tmp = arr[i + 1]
                arr[i + 1] = arr[i]
                arr[i] = tmp

                print(arr)

    return swaps


if __name__ == '__main__':
    print(minimumSwaps([4, 3, 1, 2]))
