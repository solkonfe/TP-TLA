#!/bin/bash

for (( c=1; c<=7; c++ ))
do
    cat src/tests/test${c} | bin/Compiler > logs/testlogs/test${c}log.txt
done