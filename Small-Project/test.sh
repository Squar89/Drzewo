#!/bin/bash

debugMode=0;

if [ "$1" == "-v" ]; then
    debugMode=1
    prog=$2
    directory=$3
else
    prog=$1
    directory=$2
fi

for test in 