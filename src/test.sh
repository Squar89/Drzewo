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
counter=0;
failed=0;

echo "Testing $prog with tests from $directory"

for test in $directory/*.in; do
    ((counter++));
    if [ $debugMode == 0 ]; then
        ./$prog < $test > test.out
        if [ "$(diff ${test::-3}.out test.out)" != "" ]; then
            echo ${test::-3}.out
            ((failed++))
        fi
    else
        ./$prog -v < $test > test.out 2> test.err
        if [ "$(diff ${test::-3}.out test.out)" != "" ]; then
            echo ${test::-3}.out
            ((failed++));
        elif [ "$(diff ${test::-3}.err test.err)" != "" ]; then
            echo ${test::-3}.err
            ((failed++));
        fi
    fi
done

if [ $failed == 0 ]; then
    echo "All tests passed (Total of $counter)"
else
    echo "$failed/$counter tests failed"
fi

rm -f test.out test.err