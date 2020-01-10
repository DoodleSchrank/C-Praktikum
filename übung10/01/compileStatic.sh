#!/bin/sh
gcc -c 10_modularitaet_01.c
gcc -c libmatrix.c
ar rcs libmatrix.a libmatrix.o
gcc -o modularitaetStatic 10_modularitaet_01.o -L. -lmatrix



#Output von time:
#./compileStatic.sh  0.07s user 0.04s system 86% cpu 0.124 total
#./modularitaetStatic  0.00s user 0.00s system 81% cpu 0.003 total


