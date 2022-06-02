#!/bin/bash

rm -rf logs

mkdir logs
mkdir logs/testlogs

for (( c=1; c<=15; c++ ))
do
    cat tests/test${c} | bin/Compiler &> logs/testlogs/test${c}log.log
done
