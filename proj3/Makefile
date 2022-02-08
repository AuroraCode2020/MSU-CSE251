build : file.o display.o input.o
	gcc -o build file.o display.o input.o

file.o : file.c file.h
	gcc -g -c file.c file.h

display.o : display.c file.h
	gcc -g -c display.c file.h

input.o : input.c file.h
	gcc -g -c input.c file.h

clean :
	rm -f *.o *.h.gch build