#!/bin/bash

rm a.out

CCOPT="$(pkgconf --cflags eigen3 openblas) -D EIGEN_USE_BLAS -D EIGEN_USE_LAPACKE"
LDOPT="$(pkgconf --libs eigen3 openblas)"

g++ $CCOPT $LDOPT ttt.cc
