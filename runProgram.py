#!/usr/bin/python3
import sys, argparse, os, shutil, subprocess, json, shlex
from multiprocessing import Process, Queue
import time

def runCommand(command):
    x = subprocess.run([command], stderr=subprocess.PIPE, stdout=subprocess.PIPE, shell=True)
    if x.returncode != 0:
        exit("FAILED : " + command)
    return str(x.stderr) + str(x.stdout)

def runProgram(programName):
    os.chdir(programName)

    options = " -O1 -Wall -Wno-unknown-pragmas -Werror "
    compiler = "patmos-clang"

    runCommand(compiler + options + "*.c")
    runCommand(compiler + options + '-mserialize=simple.pml *.c')
    runTimeOutput = runCommand("pasim -v ./a.out ")
    wcet = runCommand("platin wcet -i simple.pml -b a.out --report")
    
    executionTime = runTimeOutput[runTimeOutput.find("Cycles:")+7:]
    executionTime = int(executionTime[:executionTime.find("\\n")].strip())

    wcet = wcet[wcet.find("cycles:")+7:]
    wcet = int(wcet[:wcet.find("\\n")].strip())
    
    output=programName + "      " + str(executionTime) + "         " + str(wcet) + '\n'
    print(output)
        
def main():
    try:
        programName = sys.argv[1]
    except:
        exit("usage: ./runProgram.py <program>")

    runProgram(programName)
    

if __name__ == '__main__':
    main()
