#!/bin/bash

COMPILER=patmos-clang
EXEC=pasim
BENCH=$1

OPTIONS=" -O1 -Wall -Wno-unknown-pragmas -Werror "

cd "$BENCH"

printf "Checking ${BENCH} ... \n"
if [ -f a.out ]; then
    rm a.out
fi

if [ -f *.o ]; then
    rm *.o
fi

$COMPILER $OPTIONS *.c # &>/dev/null
$COMPILER $OPTIONS -mserialize=simple.pml *.c
$EXEC -v ./a.out
RETURNVALUE=$(echo $?)
if [ $RETURNVALUE -eq 0 ]; then
    printf "passed. \n"
else
    printf "failed (wrong return value $RETURNVALUE). \n"
fi
platin wcet -i simple.pml -b a.out --report
