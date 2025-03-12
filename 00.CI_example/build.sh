#!/bin/bash

set +e

rm example_test example *.o 2>/dev/null

set -e

if [[ -n "$GITHUB_ENV" ]]; then
  source $GITHUB_ENV
fi

GTEST_HOME=/home/runner/work/CB.5212_AaDS_Practice_2025/CB.5212_AaDS_Practice_2025/gtest_install

CCOPT=$CCOPT -I$GTEST_HOME/include -L$GTEST_HOME/lib

echo CCOPT: $CCOPT

g++ $CCOPT -c lib.cc
g++ $CCOPT -c example.cc
g++ $CCOPT -c lib_test.cc

g++ $CCOPT -o example example.o lib.o
g++ $CCOPT -o example_test -lgtest lib_test.o lib.o
