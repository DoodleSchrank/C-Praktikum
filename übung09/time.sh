#!/bin/sh

(time ./exercise09-3O0) 2> times.txt
(time ./exercise09-3O1) 2>> times.txt
(time ./exercise09-3O2) 2>> times.txt
(time ./exercise09-3O3) 2>> times.txt
(time ./exercise09-3O3unroll) 2>> times.txt

