#!/bin/bash

set +e

rm example_test example *.o 2>/dev/null

set -e

COMMONFLAGS=-Werror -Wpedantic -Wall -std=c++17
CCFLAGS=$COMMONFLAGS $(pkgconf --cflags gtest)
LDFLAGS=$COMMONFLAGS $(pkgconf --libs gtest) -pthread

echo "CCFLAGS: $CCFLAGS"
echo "LDFLAGS: $LDFLAGS"

g++ $CCFLAGS -c lib.cc
g++ $CCFLAGS -c example.cc
g++ $CCFLAGS -c lib_test.cc

g++ $LDFLAGS -o example example.o lib.o
g++ $LDFLAGS -lgtest_main -o example_test lib_test.o lib.o
