all: main

main: main.o roman.o
	gcc -o main main.o roman.o

main.o: main.c roman.h
	gcc -c main.c

roman.o: roman.c roman.h
	gcc -c roman.c

clean:
	rm -f main *.o

run: all
	./main