#!/usr/bin/python3

import random

random.seed()
size = 8192
maxint = 32768
finput = open('searchInput.h', 'w')
for i in range(10):
    finput.write('int binInput' + str(i) + '[' + str(size) + '] = { \n')

    x = set()
    while(len(x) < size):
        x.add(random.randrange(maxint))

    x = sorted(x)

    endj = size - 1
    
    for j in range(size):
        finput.write(str(x[j]))
        if j != (size - 1):
            finput.write(', ')
        if (j % 10) == 0:
            finput.write('\n')

    finput.write(' }; \n\n')
