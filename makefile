mycomp: mycomp.o helpers.o complex.o
	gcc -ansi -Wall -pedantic mycomp.o helpers.o complex.o -o mycomp -lm 
mycomp.o: mycomp.c helpers.h
	gcc -c -Wall -ansi -pedantic mycomp.c -o mycomp.o
helpers.o: helpers.c helpers.h
	gcc -c -Wall -ansi -pedantic helpers.c -o helpers.o
complex.o: complex.c complex.h 
	gcc -c -Wall -ansi -pedantic complex.c -o complex.o 

