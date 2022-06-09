#!/bin/python3

import math
import os
import random
import re
import sys

def runStair(n, posibleSteps, currentPath):
    pathsTaken = 0

    for step in posibleSteps:
        count = sum(currentPath + [step])
        if count < n:
            pathsTaken += runStair(n, posibleSteps, currentPath + [step])
        elif count == n:
            pathsTaken += 1
            break

    return pathsTaken

def stepPerms(n):
    posibleSteps = [1, 2, 3]
    stepsTaken = runStair(n, posibleSteps, [])

    return stepsTaken % (pow(10, 10) + 7)


print(stepPerms(36))
