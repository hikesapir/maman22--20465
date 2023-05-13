test: mycomp.o helpers.o util.o
	gcc -ansi -Wall -pedantic mycomp.c -o test
mycomp.o: mycomp.c helpers.h util.h
	gcc -c -Wall -ansi -pedantic mycomp.c -o mycomp.o
helpers.o: helpers.c helpers.h util.h exceptions.h
	gcc -c -Wall -ansi -pedantic helpers.c -o helpers.o
util.o: util.c util.h 
	gcc -c -Wall -ansi -pedantic util.c -o util.o


test: mycomp.o helpers.o complex.o
	gcc -ansi -Wall -pedantic mycomp.o helpers.o complex.o -o test -lm
mycomp.o: mycomp.c helpers.h
	gcc -c -Wall -ansi -pedantic mycomp.c -o mycomp.o
helpers.o: helpers.c exceptions.h
	gcc -c -Wall -ansi -pedantic helpers.c -o helpers.o
complex.o: complex.c complex.h 
	gcc -c -Wall -ansi -pedantic complex.c -o complex.o 