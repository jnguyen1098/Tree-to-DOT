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
	diff -u <(./$(EXE)) old

lint:
	make cppcheck
	make splint
	make clang-analyze
	make clang-tidy
	make clang-format

cppcheck:
	@echo "Running cppcheck"
	cppcheck --enable=all -I$(INC) --inconclusive -v $(SRC)

splint:
	@echo "Running splint"
	splint -I$(INC) $(SRC)/*.c

clang-analyze:
	@echo "Running clang's static analyzer"
	clang --analyze $(SRC)/*.c -I$(INC)

clang-tidy:
	@echo "Running clang-tidy"
	clang-tidy -checks=* $(SRC)/*.c -- -I$(INC)

clang-format:
	@echo "Running clang-format"
	diff -u <(clang-format $(INC)/*.h) <(cat $(INC)/*.h)
	diff -u <(clang-format $(SRC)/*.c) <(cat $(SRC)/*.c)

clean:
	rm -rf $(EXE) $(OBJS) *.plist

.PHONY: all run test lint cppcheck splint clang-analyze clang-tidy clang-format clean
