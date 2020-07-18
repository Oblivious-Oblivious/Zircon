%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YYSTYPE char*

/* Parser definitions */
int yylex(void);
void yyerror(char*);
char *progname;
char *yylval;

%}

%token OBJECT MODEL PROTOCOL SELF
%token LEFT_PAREN RIGHT_PAREN LEFT_CURLY RIGHT_CURLY COLON SEMICOLON
%token SEND ACCESS POINTER
%token STRING_LITERAL IDENT EOLN

%%

transpile      : /* nothing */
               | transpile echo_identifier
               ;
echo_identifier: OBJECT IDENT {
                    printf("Parsed object: %s\n", $2);
               }
               | MODEL IDENT {
                    printf("Parsed model: %s\n", $2);
               }
               | PROTOCOL IDENT {
                    printf("Parsed protocol: %s\n", $2);
               }
               | IDENT {
                    printf("Valid identifier: %s\n", $1);
               }
               | STRING_LITERAL {
                    printf("Valid string literal: %s\n", $1);
               }
               | LEFT_PAREN {
                    printf("Left paren");
               }
               | IDENT SEND IDENT {
                    printf("%s sends to %s\n", $1, $3);
               }
               | LEFT_PAREN IDENT POINTER RIGHT_PAREN SELF SEND STRING_LITERAL SEND LEFT_PAREN IDENT POINTER RIGHT_PAREN COLON IDENT SEND LEFT_CURLY IDENT RIGHT_CURLY {
                    printf("%s%s%s%s %s %s %s %s %s%s%s%s%s %s %s %s %s %s\n",
                    $1, $2, $3, $4, $5, $6, $7, $8, $9,
                    $10, $11, $12, $13, $14, $15, $16, $17, $18);
               }
               ;

%%

void warning(char *s, char *t) {
    fprintf(stderr, "%s: %s at %s:%d\n", progname, s, __FILE__, __LINE__);
    if(t) fprintf(stderr, "%s at %s:%d\n", t, __FILE__, __LINE__);
}

void yyerror(char *s) {
    warning(s, (char*)0);
    yyparse();
}

int main(int argc, char **argv) {
    progname = argv[0];
    return yyparse();
}
