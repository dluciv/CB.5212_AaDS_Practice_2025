#!/bin/bash

set +e

rm example_test example *.o 2>/dev/null

set -e

g++ -c lib.cc
g++ -c example.cc
g++ -c lib_test.cc

g++ -o example example.o lib.o
g++ -o example_test -lgtest -lgtest_main -lpthread lib_test.o lib.o
