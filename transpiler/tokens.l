L    [a-zA-Z_]

%{

#define YYSTYPE char*
#include <stdio.h>
#include <string.h>
#include "grammar.tab.h"

#define token(__TOKEN) do { \
    yylval = strdup(yytext); \
    return __TOKEN; \
} while(0)

extern char *yylval;

%}

%%

object                 token(OBJECT);
model                  token(MODEL);
protocol               token(PROTOCOL);

self                   token(SELF);

[a-zA-Z_][a-zA-Z0-9_]+ token(IDENT);
L?\"(\\.|[^\\"\n])*\"  token(STRING_LITERAL);

"("                    token(LEFT_PAREN);
")"                    token(RIGHT_PAREN);
"{"                    token(LEFT_CURLY);
"}"                    token(RIGHT_CURLY);
":"                    token(COLON);
";"                    token(SEMICOLON);
"*"                    token(POINTER);
"|>"                   token(SEND);
"->"                   token(ACCESS);

%%

int yywrap(void) {
    return 1;
}
