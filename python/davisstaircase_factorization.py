#!/bin/python3

import math
import os
import random
import re
import sys

def runStair(n, posibleSteps, currentPath):
    pathsTaken = 0

    for i in range(0, len(posibleSteps), 1):
        no_steps = (n - sum(currentPath)) // posibleSteps[i]

        posiblePath = currentPath + [posibleSteps[i]] * no_steps
        reminder = (n - sum(posiblePath)) % posibleSteps[i]

        # print("Posible path: ", posiblePath)
        print("Reminder: ", reminder)

        if sum(posiblePath) < n:

            if reminder != 0 and no_steps > 1:
                removed_steps = 1

                while removed_steps < no_steps:
                    print("Special case!")
                    pathsTaken += runStair(n, posibleSteps[i+1:], currentPath + [posibleSteps[i]] * removed_steps)
                    removed_steps += 1

            pathsTaken += runStair(n, posibleSteps[i+1:], posiblePath)

        elif sum(posiblePath) == n:
            if len(set(posiblePath)) > 1:

                # This needs fixing - is also not factorial(len(posiblePath))
                pathsTaken += len(posiblePath)
                print("Adding SMTH for path: ", posiblePath)
            else:
                pathsTaken += 1
                print("Adding 1 for path: ", posiblePath)

    return pathsTaken

def stepPerms(n):
    posibleSteps = [3, 2, 1]
    pathsTaken = runStair(n, posibleSteps, [])
    return pathsTaken % (pow(10, 10) + 7)

print(stepPerms(7))
