TEST=test_set
MODS=set_A.o
test: $(TEST)
./$(TEST) # This will compile and run your test
TESTCFLAGS=$(CFLAGS) -Wno-gnu-zero-variadic-macro-arguments
TESTLIBS=-lcheck -lm -lpthread -lrt
$(TEST): $(TEST).o $(MODS)
$(CC) $(TESTLDFLAGS) -o $(TEST) $^ $(LIBS) $(TESTLIBS)
$(TEST).o: $(TEST).c
$(CC) -c $(TESTCFLAGS) $<
