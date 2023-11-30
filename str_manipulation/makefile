all: main

main: main.o str.o
	gcc -o main main.o str.o

main.o: main.c str.h
	gcc -c main.c

str.o: str.c str.h
	gcc -c str.c

clean:
	rm -f main *.o

run: all
	./main