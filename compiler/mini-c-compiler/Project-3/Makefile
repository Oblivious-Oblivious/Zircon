CC = gcc
OPT = -O2 -march=native
VERSION = -std=c89
OUTPUT = a.out

HEADERS =
LIBS =
FLAGS =
WARNINGS =

LEX = lexer.l
LEX_OUT = lex.yy.c
YACC = parser.y
YACC_OUT = parser.tab

all: parser

flex: $(LEX)
	flex $^

yacc: $(YACC)
	bison -d $^

parser: flex yacc
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(LIBS) $(FLAGS) $(WARNINGS) -o $(OUTPUT) $(YACC_OUT).c

clean:
	rm -f $(LEX_OUT) $(YACC_OUT).c $(YACC_OUT).h $(OUTPUT)
