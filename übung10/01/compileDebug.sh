#!/bin/sh
gcc -c -ggdb 10_modularitaet_01.c
gcc -c -ggdb libmatrix.c
ar rcs libmatrix.a libmatrix.o
gcc -ggdb -o modularitaet 10_modularitaet_01.o -L. -lmatrix

