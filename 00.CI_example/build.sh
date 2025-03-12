#!/bin/bash

set +e

rm example_test example *.o 2>/dev/null

set -e

if [[ -n "$GITHUB_ENV" ]]; then
  source $GITHUB_ENV
fi

find .
# gtest_install

echo CCOPT: $CCOPT

g++ $CCOPT -c lib.cc
g++ $CCOPT -c example.cc
g++ $CCOPT -c lib_test.cc

g++ $CCOPT -o example example.o lib.o
g++ $CCOPT -o example_test -lgtest lib_test.o lib.o
