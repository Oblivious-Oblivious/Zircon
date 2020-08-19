CC = g++
OPT = -O2 -march=native
VERSION = -std=c++11
OUTPUT = icg

HEADERS =
LIBS =
FLAGS =
WARNINGS =

LEX = lexer.l
LEX_OUT = lex.yy.c
YACC = parser.y
YACC_OUT = parser
ICG_OUT = ICG.code

all: compiler

flex: $(LEX)
	flex $^

yacc: $(YACC)
	bison -d -v $^

compiler: flex yacc
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(LIBS) $(FLAGS) $(WARNINGS) -o $(OUTPUT) $(YACC_OUT).tab.c

clean:
	mv parser.y _parser.y
	rm -f $(LEX_OUT) $(YACC_OUT).* $(ICG_OUT) $(OUTPUT)
	mv _parser.y parser.y
