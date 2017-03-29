#!/bin/bash

if [ "$1" == "-v" ]; then
    debugMode=1
    prog=$2
    directory=$3
else
    debugMode=0
    prog=$1
    directory=$2
fi

for test in $directory/*.in; do
    if [ $debugMode == 0 ]; then
        time ./$prog < $test > test.out
        if [ "$(diff ${test::-3}.out test.out)" != "" ]; then
            echo ${test::-3}.out
        fi
    else
        ./$prog -v < $test > test.out 2> test.err
        if [ "$(diff ${test::-3}.out test.out)" != "" ]; then
            echo ${test::-3}.out
        elif [ "$(diff ${test::-3}.err test.err)" != "" ]; then
            echo ${test::-3}.err
        fi
    fi
done
rm -f test.out test.err