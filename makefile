CC=gcc
FLAGS=-Wall -g

all: Main StrList.o Main.o

Main: Main.o StrList.o
	$(CC) $(FLAGS) Main.o StrList.o -o Main

Main.o: Main.c
	$(CC) $(FLAGS) -c Main.c

StrList.o: StrList.c StrList.h
	$(CC) $(FLAGS) -c StrList.c

clean:
	rm -f *.o Main