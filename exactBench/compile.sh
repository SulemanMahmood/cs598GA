#!/bin/bash

#COMPILER=gcc # Please adapt this line to your favorite compiler.
COMPILER=patmos-clang

OPTIONS=" -O2 -Wall -Wno-unknown-pragmas -Werror "

#EXEC= # Adapt if the executable is to be executed via another program
#EXEC=valgrind\ -q
EXEC=pasim

PASS=0
FAIL_COMP=0
FAIL_EXEC=0

for dir in */; do

    cd "$dir"

    printf "Entering ${dir} \n"

    for BENCH in */; do
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
        
        cd ..
    done

    printf "Leaving ${dir} \n\n"
    
    cd ..
done

echo "PASS: $PASS, FAIL_COMP: $FAIL_COMP, FAIL_EXEC: $FAIL_EXEC"
