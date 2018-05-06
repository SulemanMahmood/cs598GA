#!/bin/bash

EXEC=pasim

PASS=0
FAIL_COMP=0
FAIL_EXEC=0

for BENCH in `cat ./../projects.txt`; do
    cd "$BENCH"
    echo $BENCH
    if [ -f a.out ]; then
        time $EXEC -v ./a.out #&>/dev/null
        RETURNVALUE=$(echo $?)
        if [ $RETURNVALUE -eq 0 ]; then
            printf "passed. \n"
            ((PASS++))
        else
            printf "failed (wrong return value $RETURNVALUE). \n"
            ((FAIL_EXEC++))
        fi
    else
        printf "failed (compiled with errors/warnings). \n"
        ((FAIL_COMP++))
    fi 
    
    cd ../..
done

echo "PASS: $PASS, FAIL_COMP: $FAIL_COMP, FAIL_EXEC: $FAIL_EXEC"
