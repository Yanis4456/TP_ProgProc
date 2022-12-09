

srcdir=src/
bindir=bin/
savedir=save/
docdir=doc/



CC=gcc
CP=cp 
RM=rm
SRC= $(wildcard $(srcdir)*.c)
HEAD= $(filter-out main.h,$(SRC:.c=.h))
OBJ= $(subst $(srcdir),$(bindir),$(SRC:.c=.o))
PROG= exec


bin/%.o: src/%.c 
	$(CC) -c $< -o $@




$(PROG): $(OBJ)
	$(CC) $^ -o bin/$@ 

.PHONY: clean
.PHONY: run
clean:
	-$(RM) -if bin/$(PROG) bin/*.o


run:
	./$(bindir)exec 

