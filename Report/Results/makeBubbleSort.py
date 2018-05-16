#!/usr/bin/python3
from scipy.interpolate import spline
import numpy as np
import matplotlib.pyplot as plt
import math

f = open ('BubbleSort', 'r')
t = open ('bubblesorttable.tex', 'w')

exact = f.readline().split(',')

knobs = 9
approx = []
for i in range(knobs):
    approx.append(f.readline().split(','))

for i in range(knobs):
    approx[i].append('%.2f' % (100 / float(approx[i][1])))
    wcet = float(approx[i][2])
    exactt = float(exact[2])
    approx[i].append('%.2f' % (wcet * 100/ exactt))

f.close()

# Table
t.write('\\begin{table}[]\n')
t.write('  \\centering\n')
t.write('  \\caption{Bubblesort Results}\n')
t.write('  \\label{bubblesortT}\n')
t.write('  \\begin{tabular}{|l|l|l|l|}\n')
t.write('    \\hline\n')
t.write('    \\textbf{Skipped Iterations} & \\textbf{Accuracy}  & \\textbf{Standard Dev.}  & \\textbf{WCET}           \\\\ \\hline\n')
for i in range(knobs):
    t.write(approx[i][-2] +  '\\% &  ' + approx[i][3] + '\\% &' + approx[i][4].strip() + '\\% &'  +  approx[i][-1] + '\\%   \\\\ \\hline\n')
t.write('  \\end{tabular}\n')
t.write('\\end{table}\n')
t.close()

# figure 1 Accuracy vs log(Skip %age)
x = []
y = []

for i in range(knobs):
    x.append(float(approx[i][-2]))
    y.append(float(approx[i][3]))

plt.plot(x,y,'bo-')

# xnew = np.linspace(x[0],x[-1],300)
# smooth = spline(x,y,xnew)
# plt.plot(xnew,smooth)

plt.xlabel('Skipped Iterations %age')
plt.ylabel('Accuracy')
plt.savefig('bubblesort1.eps')
plt.close()

# figure 2 WCET vs log(Neighborhood Size)
z = []
for i in range(knobs):
    z.append(float(approx[i][-1]))

plt.plot(x,z,'bo-')

# xnew = np.linspace(x[0],x[-1],300)
# smooth = spline(x,z,xnew)
# plt.plot(xnew,smooth)

plt.xlabel('Skipped Iterations %age')
plt.ylabel('WCET')
plt.savefig('bubblesort2.eps')
plt.close()

# figure 3 WCET vs Accuracy

plt.plot(y,z,'bo-')

# xnew = np.linspace(y[0],y[-1],300)
# smooth = spline(y,z,xnew)
# plt.plot(xnew,smooth)

plt.xlabel('Accuracy')
plt.ylabel('WCET')
plt.savefig('bubblesort3.eps')
plt.close()
