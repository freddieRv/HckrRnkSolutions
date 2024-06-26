#!/bin/python3

import math
import os
import random
import re
import sys

def runStair(n, posibleSteps, currentPath):
    pathsTaken = 0

    # print("Current path: ", currentPath)

    for i in range(0, len(posibleSteps), 1):
        no_steps = (n - sum(currentPath)) // posibleSteps[i]
        posiblePath = currentPath + [posibleSteps[i]] * no_steps
        reminder = (n - sum(posiblePath)) % posibleSteps[i]

        # print("Posible path: ", posiblePath)
        # print("Reminder: ", reminder)

        if sum(posiblePath) < n and no_steps > 0:
            # print("recursing")
            if reminder != 0 and no_steps > 1:
                removed_steps = 1
                while removed_steps < no_steps:
                    # print("Special case!")
                    pathsTaken += runStair(n, posibleSteps[i+1:], currentPath + [posibleSteps[i]] * removed_steps)
                    removed_steps += 1

            pathsTaken += runStair(n, posibleSteps[i+1:], posiblePath)

        elif sum(posiblePath) == n:
            if len(set(posiblePath)) > 1:
                toadd = 0

                if len(set(posiblePath)) == len(posiblePath):
                    toadd = math.factorial(len(posiblePath))
                else:
                    stepsCount = {}
                    for step in posiblePath:
                        stepsCount[step] = 1 + stepsCount.get(step, 0)

                    print(stepsCount)

                    m = len(posiblePath)
                    for count in stepsCount.values():
                        toadd += math.factorial(m) // (math.factorial(count) * math.factorial(m - count))

                    toadd //= 2


            else:
                removed_steps = 1
                while removed_steps < no_steps:
                    # print("Special case 2!")
                    pathsTaken += runStair(n, posibleSteps[i+1:], currentPath + [posibleSteps[i]] * removed_steps)
                    removed_steps += 1

                pathsTaken += 1
                print("Adding 1 for path: ", posiblePath)

    return pathsTaken

def stepPerms(n):
    posibleSteps = [3, 2, 1]
    pathsTaken = runStair(n, posibleSteps, [])
    return pathsTaken % (pow(10, 10) + 7)

#print(stepPerms(36))
print(stepPerms(8))
