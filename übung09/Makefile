
all: exercise09-1.2GNU.i exercise09-1.2BSD.i exercise09-1.2XOPEN.i exercise09-1.2POSIX.i exercise09-3O0 exercise09-3O1 exercise09-3O2 exercise09-3O3 exercise09-3O3unroll exercise09-3O0.s exercise09-3O1.s exercise09-3O2.s exercise09-3O3.s exercise09-3O3unroll.s exercise09-2

exercise09-1.2GNU.i: exercise09-1.2.c
	cpp -D GNU exercise09-1.2.c > exercise09-1.2GNU.i
exercise09-1.2BSD.i: exercise09-1.2.c
	cpp -D BSD exercise09-1.2.c > exercise09-1.2BSD.i
exercise09-1.2XOPEN.i: exercise09-1.2.c
	cpp -D XOPEN exercise09-1.2.c > exercise09-1.2XOPEN.i
exercise09-1.2POSIX.i: exercise09-1.2.c
	cpp -D POSIX exercise09-1.2.c > exercise09-1.2POSIX.i

#exercise09-2.i: exercise09-2.c
#	cpp exercise09-2.c > $@
#exercise09-2.s: exercise09-2.i
#	gcc -S exercise09-2.i
#exercise09-2.o: exercise09-2.s
#	as -o $@ exercise09-2.s
#exercise09-2: exercise09-2.o:
#	gcc -o $@ exercise09-2.o

exercise09-3O0: exercise09-3.c
	gcc -O0 -o $@ exercise09-3.c
exercise09-3O1: exercise09-3.c
	gcc -O1 -o $@ exercise09-3.c
exercise09-3O2: exercise09-3.c
	gcc -O2 -o $@ exercise09-3.c
exercise09-3O3: exercise09-3.c
	gcc -O3 -o $@ exercise09-3.c
exercise09-3O3unroll: exercise09-3.c
	gcc -O3 -funroll-loops -o $@ exercise09-3.c

exercise09-3O0.s: exercise09-3.i
	gcc -S -O0 -o $@ exercise09-3.i
exercise09-3O1.s: exercise09-3.i
	gcc -S -O1 -o $@ exercise09-3.i
exercise09-3O2.s: exercise09-3.i
	gcc -S -O2 -o $@ exercise09-3.i
exercise09-3O3.s: exercise09-3.i
	gcc -S -O3 -o $@ exercise09-3.i
exercise09-3O3unroll.s: exercise09-3.i
	gcc -S -O3 -funroll-loops -o $@ exercise09-3.i
	
exercise09-3.i: exercise09-3.c
	cpp exercise09-3.c > exercise09-3.i

clean:
	rm *.i
	rm *.s
	#rm *.o
	rm exercise09-3O0 exercise09-3O1 exercise09-3O2 exercise09-3O3 exercise09-3O3unroll exercise09-2
