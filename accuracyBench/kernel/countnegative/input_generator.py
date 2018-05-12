#!/usr/bin/python3

import random

random.seed()
size = 100
size1 = size - 1
samples = 1000
samples1 = samples - 1
maxint = 32768

finput = open('sortInput.h', 'w')
finput.write('typedef struct abc{')
finput.write('  int array['+ str(size) + ']['+str(size)+'];')
finput.write('  int negatives;')
finput.write('} xyz;\n\n')

finput.write('xyz GlobalStructure[1000] = { \n')

for i in range(samples):
    finput.write('{')
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
        
    finput.write('{')
    for j in range(len(x)):
        finput.write('{')
        for k in range(len(x[j])):
            finput.write(str(x[j][k]))
            if k != size1:
                finput.write(', ')
        finput.write('}')
        if j != size1:
            finput.write(', ')
    finput.write('}, ')
    finput.write(str(negatives))
    finput.write('}')
    if i != samples1:
        finput.write(', ')
finput.write('};')
    
