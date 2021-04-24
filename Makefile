# Sample make file for the group project. Modify this accordingly.
# The makefile should produce 'main.out'

# Compiler options
CC = gcc
CFLAGS = -Wall -Werror -ansi

# Program name
PRG = main

# Dependencies
OUT = $(PRG).out
OBJ = ./obj
SRC = ./src

# TODO - Edit rules below

$(OUT): main.o
	$(CC) $(CFLAGS) -o main.out main.o

$(OUT): main.c
	$(CC) $(CFLAGS) -c -o main.o main.c
