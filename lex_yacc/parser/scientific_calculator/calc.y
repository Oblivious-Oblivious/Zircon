%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>

    extern int yylineno;
    extern void yyerror(char *s);
    extern int yylex(void);
    //extern int yyparse(void);
%}

%union {
    double p;
}
%token <p> num
%token SIN COS TAN LOG LN SQRT SQUARE CUBE

%left '+' '-' /* Lowest precedence */
%left '*' '/' /* Highest precedence */
%nonassoc uminu /* No associativity */
%type <p> exp /* Set a type for the nonterminal */

%%

ss      : exp         { printf("%g\n", $1); }

exp     : exp '+' exp        { $$ = $1 + $3; }
        | exp '-' exp        { $$ = $1 - $3; }
        | exp '*' exp        { $$ = $1 * $3; }
        | exp '/' exp        {
            if($3 == 0) {
                printf("Error: Can't divide by zero\n");
                exit(0);
            }
            else $$ = $1 / $3;
        }
        | '-' exp            { $$ = -$2; }
        | '(' exp ')'        { $$ = $2; }
        | SIN '(' exp ')'    { $$ = sin($3); }
        | COS '(' exp ')'    { $$ = cos($3); }
        | TAN '(' exp ')'    { $$ = tan($3); }
        | LOG '(' exp ')'    { $$ = log($3); }
        | SQRT '(' exp ')'   { $$ = sqrt($3); }
        | SQUARE '(' exp ')' { $$ = $3 * $3; }
        | CUBE '(' exp ')'   { $$ = $3 * $3 * $3; }
        | num
        ;
%%

int main(void) {
    do {
        printf("-> ");
        yyparse();
    } while(1);
}

void yyerror(char *s) {
    printf("Syntax error on line %d\n", yylineno);
}
