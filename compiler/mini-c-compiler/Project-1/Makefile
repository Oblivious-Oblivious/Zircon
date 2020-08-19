CC = gcc
OPT = -O2 -march=native
VERSION = -std=c89
OUTPUT = a.out

HEADERS =
LIBS =
FLAGS =
WARNINGS =

INPUT = lexer.l
SRC = lex.yy.c

all: lexer

flex: $(INPUT)
	flex $^

lexer: flex
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(LIBS) $(FLAGS) $(WARNINGS) -o $(OUTPUT) $(SRC)
	./a.out testcases/test5.c

clean:
	rm -f $(SRC) $(OUTPUT)
