# makefile for tree_to_dot

EXE = tree
OBJS = tree_to_dot.o
DEPS = cdot/cdot.h

all $(EXE): $(OBJS) $(DEPS)
	$(CC) $(OBJS) -o $(EXE)

run: $(EXE)
	./$(EXE)

clean:
	rm -rf $(EXE) $(OBJS)

.PHONY: all clean
