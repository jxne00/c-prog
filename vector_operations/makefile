all: main

main: main.o arrays.o
	gcc -o main main.o arrays.o

main.o: main.c arrays.h
	gcc -c main.c

arrays.o: arrays.c arrays.h
	gcc -c arrays.c

clean:
	rm -f main *.o

run: all
	./main