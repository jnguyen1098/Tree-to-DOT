# makefile for tree_to_dot

SHELL=/bin/bash

EXE = tree
OBJS = tree_to_dot.o
DEPS = cdot/cdot.h

SRC = "."
INC = cdot

all $(EXE): $(OBJS) $(DEPS)
	$(CC) $(OBJS) -o $(EXE)

run: $(EXE)
	./$(EXE)

test: $(EXE)
	diff -u <(./$(EXE)) old_output.out

lint:
	make -f lintfile lint

clean:
	rm -rf $(EXE) $(OBJS) *.plist

.PHONY: all run test lint clean
