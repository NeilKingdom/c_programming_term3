CC=gcc
CCFLAGS=-g -ansi -Wall -pedantic
LIBS=-lm
PROGRAM=lab6
DEPS=make_account.h
OBJ=menu.o make_account.o

%.o: %.c $(DEPS)
	$(CC) $< -c -o $@ $(CCFLAGS)

run: $(OBJ)
	$(CC) $^ -o $(PROGRAM) $(CCFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm *.o $(PROGRAM)
