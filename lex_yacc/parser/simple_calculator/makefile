calc: lex.yy.c y.tab.c
	gcc -g lex.yy.c y.tab.c -o calc

lexer: y.tab.c calc.l
	lex calc.l

parser: calc.y
	yacc -d calc.y

clean:
	rm -rf lex.yy.c y.tab.c y.tab.h calc

