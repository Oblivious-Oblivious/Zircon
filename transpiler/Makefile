CC = gcc
OPT = -march=native -O2
VERSION = -std=c89
OUTPUT = zircon

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic -Wmissing-prototypes -Wstrict-prototypes
WARNINGS = -Wno-unused-function
#YACC_WARNINGS = -Wcounterexamples
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
	cp $(OUTPUT) ../examples/

clean:
	rm -f ../examples/$(OUTPUT)
	rm -f $(OUTPUT) $(LEX_OUT) $(YACC_OUT).c $(YACC_OUT).h out.c out Object.h
