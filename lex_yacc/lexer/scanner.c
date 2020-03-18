#include <stdio.h>
#include "scanner.h"

extern int yylex();
extern int yylineno;
extern char *yytext;

char *names[] = {
    NULL,
    "db_type",
    "db_name",
    "db_table_prefix",
    "db_port"
};

int main(void) {
    int value_token;

    int name_token = yylex();
    while(name_token) {
        /* printf("%d\n", name_token); */
        if(yylex() != COLON) {
            printf("Syntax error in line %d, Expected a ':' but found '%s'\n", yylineno, yytext);
            return 1;
        }
        value_token = yylex();
        switch (name_token) {
            case TYPE:
            case NAME:
            case TABLE_PREFIX:
                if(value_token != IDENTIFIER) {
                    printf("Syntax error in line %d, Expected an identifier but found '%s'\n", yylineno, yytext);
                    return 1;
                }
                printf("%s is set to %s\n", names[name_token], yytext);
                break;
            case PORT:
                if(value_token != INTEGER) {
                    printf("Syntax error in line %d, Expected an integer but found '%s'\n", yylineno, yytext);
                    return 1;
                }
                printf("%s is set to %s\n", names[name_token], yytext);
                break;
            default:
                printf("Syntax error in line %d\n", yylineno);
                break;
                
        }
        name_token = yylex();
    }
    return 0;
}
