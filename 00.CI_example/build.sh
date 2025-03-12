#!/bin/bash

set +e

rm example_test example *.o 2>/dev/null

set -e

COMMONFLAGS="-std=c++17"
CCFLAGS="${COMMONFLAGS} -Werror -Wpedantic -Wall $(pkgconf --cflags gtest)"
LDFLAGS="${COMMONFLAGS} $(pkgconf --libs gtest) -lgtest_main -lpthread"

echo "CCFLAGS: $CCFLAGS"
echo "LDFLAGS: $LDFLAGS"

g++ $CCFLAGS -c lib.cc
# g++ $CCFLAGS -c example.cc
g++ $CCFLAGS -c lib_test.cc

# g++ -o example example.o lib.o
g++ -o example_test lib_test.o lib.o $LDFLAGS
