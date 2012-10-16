opt:
	gcc -std=c99 -fstrict-aliasing -O2 -S -o optimized.s reset.c -DOPT
	gcc -std=c99 -fstrict-aliasing -O2 -o reset.o -c reset.c -DOPT
	gcc -std=c99 -fstrict-aliasing -O2 -o main.o -c main.c -DOPT
	gcc -std=c99 -fstrict-aliasing -O2 -o optimized reset.o main.o -DOPT

slow:
	gcc -std=c99 -fno-strict-aliasing -O2 -S -o slow.s reset.c
	gcc -std=c99 -fno-strict-aliasing -O2 -o reset.o -c reset.c
	gcc -std=c99 -fno-strict-aliasing -O2 -o main.o -c main.c
	gcc -std=c99 -fno-strict-aliasing -O2 -o slow reset.o main.o

clean:
	rm *.o
