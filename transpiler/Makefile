YFLAGS = -d
OBJFLAGS = -O3
CCFLAGS = -lfl -O3
PROGRAM = transpiler
LEXER = tokens
PARSER = grammar
CC = gcc

HEADERS = $(PARSER).tab.h
OBJS = $(PARSER).tab.o lex.yy.o
SRCS = $(PARSER).tab.c lex.yy.c

all: $(PROGRAM)

.c.o: $(SRCS)
	$(CC) -c $*.c -o $@ $(OBJFLAGS)
grammar.tab.c: $(PARSER).y
	bison $(YFLAGS) $(PARSER).y
lex.yy.c: $(LEXER).l
	flex $(LEXER).l
$(PROGRAM): $(OBJS)
	$(CC) $(OBJS) -o $@ $(CCFLAGS)
clean:
	rm -r $(OBJS) $(SRCS) $(HEADERS) $(PROGRAM)
