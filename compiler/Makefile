CC = gcc
OPT = -O2 -march=native
VERSION = -std=c99
OUTPUT = a.out

FLAGS =
WARNINGS =
HEADERS =
LIBS =

SRC = main2.c
SRC_OUT = object.h

all: compiler

compiler:
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(WARNINGS) $(FLAGS) $(LIBS) -o $(OUTPUT) $(SRC)
	./a.out Test.co

clean:
	rm -f $(OUTPUT) $(SRC_OUT)
