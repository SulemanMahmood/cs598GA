#!/bin/bash

#COMPILER=gcc # Please adapt this line to your favorite compiler.
COMPILER=patmos-clang

OPTIONS=" -O1 -Wall -Wno-unknown-pragmas -Werror "

for BENCH in `cat ./../projects.txt`; do
    cd "$BENCH"
    
    printf "Checking ${BENCH} ... \n"
    if [ -f a.out ]; then
        rm a.out
    fi
    
    if [ -f *.o ]; then
        rm *.o
    fi
    
    
    # Please remove '&>/dev/null' to identify the warnings (if any)
    $COMPILER $OPTIONS *.c # &>/dev/null
    $COMPILER $OPTIONS -mserialize=simple.pml *.c
    
    cd ../..
done
