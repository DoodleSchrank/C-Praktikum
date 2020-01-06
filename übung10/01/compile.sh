#!/bin/sh
gcc -c 10_modularitaet_00.c
gcc -c libcoord.c
ar rcs libcoord.a libcoord.o
gcc -o modularitaet 10_modularitaet_00.o -L. -lcoord

