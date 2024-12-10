CC = gcc
CFLAGS = -g -Wall
PROGRAMS = readDictionary.o main.o main check.o

all: $(PROGRAMS)

clean: 
	rm -f *.o *~

readDictionary.o: readDictionary.c define.h readDictionary.h
	$(CC) $(CFLAGS) -c $^

check.o: check.c define.h check.h
	$(CC) $(CFLAGS) -c $^

main.o: main.c define.h readDictionary.h check.h
	$(CC) $(CFLAGS) -c $^

main: main.o readDictionary.o check.o
	$(CC) $(CFLAGS) -o $@ $^