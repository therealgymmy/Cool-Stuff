strict:
	gcc -O2 -std=c99 -fstrict-aliasing -Wstrict-aliasing test.c -S -o strict.s
	gcc -O2 -std=c99 -fstrict-aliasing -Wstrict-aliasing main.c test.c -o strict

nostrict:
	gcc -O2 -std=c99 -fno-strict-aliasing -Wstrict-aliasing test.c -S -o nostrict.s
	gcc -O2 -std=c99 -fno-strict-aliasing -Wstrict-aliasing main.c test.c -o nostrict
