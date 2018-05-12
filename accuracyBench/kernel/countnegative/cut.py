#!/usr/bin/python3

f = open('sortInput.h')
x = f.read(100000)

beg = 0
i = 0

while i < 101:
    loc = x.find('}', beg)
    beg = loc+1
    i = i + 1
x = x[:loc+3]

step = 60
beg = 0
fin = x.find(',',beg + step)
while fin != -1:
    print(x[beg:fin+1])
    beg = fin + 1
    fin = x.find(',',beg + step)
print(x[beg:])

f.close()
