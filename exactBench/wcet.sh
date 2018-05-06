#!/bin/bash

for BENCH in `cat ./../projects.txt`; do
    cd "$BENCH"
    echo $BENCH
    if [ -f a.out ]; then
        time platin wcet -i simple.pml -b a.out --report #&>/dev/null
    fi 
    
    cd ../..
done
