#!/bin/sh
cpp exercise09-2.c > exercise09-2.i
gcc -S exercise09-2.i
as -o exercise09-2.o exercise09-2.s
gcc -o exercise09-2 exercise09-2.o
