CC=gcc
FLAGS=-Wall -g

all: StrList StrList.o Main.o

StrList: Main.o StrList.o
	$(CC) $(FLAGS) Main.o StrList.o -o StrList

Main.o: Main.c
	$(CC) $(FLAGS) -c Main.c

StrList.o: StrList.c StrList.h
	$(CC) $(FLAGS) -c StrList.c

clean:
	rm -f *.o Main
