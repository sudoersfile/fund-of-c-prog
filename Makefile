# Sample make file for the group project. Modify this accordingly.
# The makefile should produce 'main.out'

# Compiler options
CC = gcc
CCFLAGS = -Wall -ansi # Allow warnings for now
# CCFLAGS = -Wall -Werror -ansi -lm

# Folders
BIN := ./bin
OBJ := ./obj
SRC := ./src
TST := ./test

# TODO: Ed expects the executable to be in the root directory.
PROGRAM := $(BIN)/main.out
SOURCES := $(wildcard $(SRC)/*.c)
OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

# To compile the program, we need the objects files
$(PROGRAM): $(OBJECTS)
	@echo 'Compiling program...'
	@$(CC) $^ -o $@
	@echo 'Done.'
	@echo

# To create the object files, we need the source files
$(OBJ)/%.o: $(SRC)/%.c creating_objects
	@$(CC) $(CCFLAGS) -c $< -o $@

creating_objects:
	@echo 'Creating objects...'

# Run command
.PHONY: run
run: $(PROGRAM)
	@$(PROGRAM)

# Clean command
.PHONY: clean
clean:
	@rm -rf $(OBJ)/*.o
	@rm -rf $(BIN)/*
