#!/bin/bash
gcc -c -fPIC libmatrix.c
gcc -shared -o libmatrix.so libmatrix.o
gcc -o modularitaetShared 10_modularitaet_01.c -lmatrix -L. -Wl,-rpath,"\$ORIGIN"


#Output von time:
#./compileShared.sh  0.07s user 0.02s system 98% cpu 0.089 total
#./modularitaetShared  0.00s user 0.00s system 83% cpu 0.003 total
