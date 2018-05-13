#!/usr/bin/python3

import random

random.seed()
size = 6
size1 = size - 1
samples = 1000
samples1 = samples - 1
maxint = 32768

finput = open('ludcmpInput.h', 'w')
finput.write('typedef struct abc{ \n')
finput.write('  float farray['+ str(size) + ']['+str(size)+'];\n')
finput.write('  double darray['+ str(size) + ']['+str(size)+'];\n')
finput.write('} xyz;\n\n')

finput.write('xyz GlobalStructure[' + str(samples) + '] = { \n')

for i in range(samples):
    finput.write('{')
    x = []
    for e in range(size):
        y = []
        for f in range(size):
            num = random.randrange(-maxint, maxint)
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
    finput.write('},\n ')

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
    finput.write('} ')
    
    
    finput.write('}\n')
    if i != samples1:
        finput.write(', ')
finput.write('};\n')
    
