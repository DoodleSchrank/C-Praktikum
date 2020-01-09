#!/bin/sh
gcc -c -ggdb -Og 10_modularitaet_01.c
gcc -c -ggdb -Og libmatrix.c
ar rcs libmatrix.a libmatrix.o
gcc -ggdb -Og -o modularitaet 10_modularitaet_01.o -L. -lmatrix

