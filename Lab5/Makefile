#
# Sample Makefile
# Surbhi Bahri, FAIR, August 2017
#
# This makefile builds a simple application that contains a main module
# (specified by the EXE variable) and a predefined list of additional modules
# (specified by the MODS variable). If there are any external library
# dependencies (e.g., the math library, "-lm"), list them in the LIBS variable.
#
# For easier debugging and testing, this makefile can be set up to run the
# program in addition to compiling it. To do this, use the "run" or "cleanrun"
# targets (the latter also runs the "clean" target to force a rebuild). To
# change how the compiled executable is executed, modify the "run" target.
#
# This version of the Makefile includes support for building a test suite. The
# recommended framework is Check (http://check.sourceforge.net/). To build and
# run the test suite, execute the "test" target. The test suite must be located
# in a module called "testsuite". There are provisions for separate compilation
# and linking flags for building the test suite.
#
# To change the default build target (which executes when you just type
# "make"), change the right-hand side of the definition of the "default"
# target.
#
# By default, this makefile will build the project with debugging symbols and
# without optimization. To change this, edit or remove the "-g" and "-O0"
# options in CFLAGS and LDFLAGS accordingly.
#
# By default, this makefile build the application using the GNU C compiler,
# adhering to the C99 standard with all warnings enabled.


# application-specific settings and run target

EXE=main
TEST=test_llist
MODS=llist.o
LIBS=

default: $(EXE)

run: $(EXE)
	./$(EXE)

test: $(TEST)
	./$(TEST)


# compiler/linker settings

CC=gcc
CFLAGS=-g -O0 -Wall -pedantic -ansi
LDFLAGS=-g -O0

TESTCFLAGS=$(CFLAGS) -Wno-gnu-zero-variadic-macro-arguments
TESTLIBS=-lcheck -lm -lpthread -lrt


# build targets

$(EXE): $(EXE).o $(MODS)
	$(CC) $(LDFLAGS) -o $(EXE) $^ $(LIBS)

$(TEST): $(TEST).o $(MODS)
	$(CC) $(TESTLDFLAGS) -o $(TEST) $^ $(LIBS) $(TESTLIBS)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

$(TEST).o: $(TEST).c
	$(CC) -c $(TESTCFLAGS) $<

clean:
	rm -f $(EXE) $(EXE).o $(TEST) $(TEST).o $(MODS)

cleanrun: clean $(EXE) run
cleantest: clean $(TEST) test

.PHONY: default clean run cleanrun test cleantest

