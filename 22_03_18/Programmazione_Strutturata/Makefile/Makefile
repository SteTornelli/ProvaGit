all: main

main: main.o fatt.o hello.o
	gcc main.o fatt.o hello.o -o main

main.o: main.c
	gcc -c main.c

fatt.o: fatt.c
	gcc -c fatt.c

hello.o: hello.c
	gcc -c hello.c

clean:
	rm *.o main
