#!/usr/bin/python3

import random

random.seed()
size = 1000
size1 = size - 1
maxint = 500

finput = open("stInput.h", 'w')

finput.write('float GlobalStructure[1000][1000] = { \n')

x = []
negatives = 0
for e in range(size):
    y = []
    for f in range(size):
        num = random.randrange(-maxint, maxint)
        if (num < 0):
            negatives = negatives + 1
        y.append(num)
    x.append(y)
    
for j in range(len(x)):
    finput.write('{')
    for k in range(len(x[j])):
        finput.write(str(x[j][k]))
        if k != size1:
            finput.write(', ')
    finput.write('}\n')
    if j != size1:
        finput.write(', ')
finput.write('};')
