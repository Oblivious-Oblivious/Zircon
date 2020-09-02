CC = gcc
OPT = -O2 -march=native
#VERSION = -std=c89
OUTPUT = zircon

FLAGS =
WARNINGS =
YACC_WARNINGS =
HEADERS =
LIBS =

LEX = lexer.l
LEX_OUT = lex.yy.c
YACC = parser.y
YACC_OUT = parser.tab
COMPILE = $(YACC_OUT).c $(LEX_OUT) string.c vector.c hashmap.c

all: compiler

flex:
	flex $(LEX)

bison:
	bison -d $(YACC_WARNINGS) $(YACC)

compiler: flex bison
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(WARNINGS) $(FLAGS) $(LIBS) -o $(OUTPUT) $(COMPILE)
	cp $(OUTPUT) testcases/objects/

clean:
	rm -f testcases/objects/$(OUTPUT)
	rm -f $(OUTPUT) $(LEX_OUT) $(YACC_OUT).c $(YACC_OUT).h out.c out Object.h
