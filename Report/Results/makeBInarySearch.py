#!/usr/bin/python3
from scipy.interpolate import spline
import numpy as np
import matplotlib.pyplot as plt
import math

f = open ('BinarySearch', 'r')
t = open ('binarysearchtable.tex', 'w')

exact = f.readline().split(',')

knobs = 12
approx = []
for i in range(knobs):
    approx.append(f.readline().split(','))

for i in range(knobs):
    wcet = float(approx[i][2])
    exactt = float(exact[2])
    approx[i].append('%.2f' % (wcet * 100/ exactt))

f.close()

# Table
t.write('\\begin{table}[]\n')
t.write('  \\centering\n')
t.write('  \\caption{Binary Search Results}\n')
t.write('  \\label{bsearchT}\n')
t.write('  \\begin{tabular}{|l|l|l|}\n')
t.write('    \\hline\n')
t.write('    \\textbf{Neighborhood Size} & \\textbf{Accuracy}     & \\textbf{WCET}           \\\\ \\hline\n')
for i in range(knobs):
    t.write(approx[i][1] +  ' &  ' + approx[i][3] + '&' + approx[i][-1] + '   \\\\ \\hline\n')
t.write('  \\end{tabular}\n')
t.write('\\end{table}\n')
t.close()

# figure 1 Accuracy vs log(Neighborhood Size)
x = []
y = []

for i in range(knobs):
    x.append(math.log(float(approx[i][1]),2))
    y.append(float(approx[i][3]))

plt.plot(x,y,'bo-')

# xnew = np.linspace(x[0],x[-1],300)
# smooth = spline(x,y,xnew)
# plt.plot(xnew,smooth)

plt.xlabel('log(Neighborhood Size)')
plt.ylabel('Accuracy')
plt.savefig('binarysearch1.eps')
plt.close()

# figure 2 WCET vs log(Neighborhood Size)
z = []
for i in range(knobs):
    z.append(float(approx[i][-1]))

plt.plot(x,z,'bo-')

# xnew = np.linspace(x[0],x[-1],300)
# smooth = spline(x,z,xnew)
# plt.plot(xnew,smooth)

plt.xlabel('log(Neighborhood Size)')
plt.ylabel('WCET')
plt.savefig('binarysearch2.eps')
plt.close()

# figure 3 WCET vs Accuracy

plt.plot(y,z,'bo-')

# xnew = np.linspace(y[0],y[-1],300)
# smooth = spline(y,z,xnew)
# plt.plot(xnew,smooth)

plt.xlabel('Accuracy')
plt.ylabel('WCET')
plt.savefig('binarysearch3.eps')
plt.close()
