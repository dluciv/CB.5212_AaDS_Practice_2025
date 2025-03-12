#!/bin/bash

set +e

rm example_test example *.o 2>/dev/null

set -ex

COMMON_FLAGS="-std=c++17"
CCFLAGS="${COMMON_FLAGS} -Werror -Wpedantic -Wall"
LDFLAGS="${COMMON_FLAGS}"
GTEST_CCFLAGS="$(pkgconf --cflags gtest) $(pkgconf --cflags gmock)"
GTEST_LDFLAGS="$(pkgconf --libs gtest) $(pkgconf --libs gmock) -lgmock_main -lpthread"

g++ $CCFLAGS -c lib.cc
g++ $CCFLAGS -c example.cc
g++ $CCFLAGS $GTEST_CCFLAGS -c lib_test.cc
g++ $CCFLAGS $GTEST_CCFLAGS -c lib_mock.cc

g++ -o example example.o lib.o
g++ -o example_test lib_test.o lib_mock.o lib.o $LDFLAGS $GTEST_LDFLAGS
