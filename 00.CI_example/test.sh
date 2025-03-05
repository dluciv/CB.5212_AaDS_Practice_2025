#!/bin/bash

set -e

# Smoke tests
./example
python3 --version
g++ --version

# Unit tests
./example_test

echo Вроде всё неплохо
