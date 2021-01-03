CC=gcc
CCFLAGS=-g -ansi -Wall -pedantic
LIBS=-lm
PROGRAM=Lab6
DEPS=makeaccount.h
OBJ=menu.o makeaccount.o

%.o: %.c $(DEPS)
	$(CC) $< -c -o $@ $(CCFLAGS)

run: $(OBJ)
	$(CC) $^ -o $(PROGRAM) $(CCFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm *.o $(PROGRAM)
