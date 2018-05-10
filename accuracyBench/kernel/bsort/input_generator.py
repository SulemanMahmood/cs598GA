#!/usr/bin/python3

import random

def countInversions(x):
    inversions = 0
    for i in range(len(x)):
        for j in range(i,len(x)):
            if x[i] > x[j]:
                inversions = inversions + 1
    return inversions

random.seed()
x = list(range(1000))

finput = open('sortInput.h', 'w')
finput.write('typedef struct abc{')
finput.write('  int array[1000];')
finput.write('  int inversions;')
finput.write('} xyz;\n\n')

finput.write('xyz GlobalStructure[1000] = { \n')


for i in range(1000):
    random.shuffle(x);
    finput.write('{')
    finput.write('{')
    for j in range(1000):
        finput.write(str(x[j]))
        if j != (1000 - 1):
            finput.write(', ')
    
    finput.write('},')
    finput.write(str(countInversions(x)))
    finput.write('},\n')

finput.write('};');
