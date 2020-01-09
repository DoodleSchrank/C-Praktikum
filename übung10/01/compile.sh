#!/bin/sh
gcc -c -ggdb -Og 10_modularitaet_01.c
gcc -c libmatrix.c
ar rcs libmatrix.a libmatrix.o
gcc -Og -o modularitaet 10_modularitaet_01.o -L. -lmatrix

