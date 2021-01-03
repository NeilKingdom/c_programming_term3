CC=gcc

CCFLAGS=-g -ansi -Wall -pedantic

AOFILES=02_Dice_A.o

BOFILES=02_Dice_B.o

AHEADERS=02_Dice_A.h

BHEADERS=02_Dice_B.h

EXE=Assignment_2

%.o: %.c $(AHEADERS) $(BHEADERS) 
	$(CC) $< -c $(CCFLAGS)

parta: $(AOFILES) 
	$(CC) $^ -o $(EXE) $(CCFLAGS)

partb: $(BOFILES) 
	$(CC) $^ -o $(EXE) $(CCFLAGS)
