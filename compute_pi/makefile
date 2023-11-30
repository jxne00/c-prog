all: main

main: main.o pi.o
	gcc -o main main.o pi.o

main.o: main.c pi.h
	gcc -c main.c

pi.o: pi.c pi.h
	gcc -c pi.c

clean:
	rm -f main *.o

run: all
	./main s