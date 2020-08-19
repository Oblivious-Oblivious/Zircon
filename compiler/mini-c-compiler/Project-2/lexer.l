%{

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/* #include "symboltable.h" */
#include "parser.tab.h"

int comment_start = 0;

%}

letter [a-zA-Z]
digit [0-9]
ws  [ \t\r\f\v]+
identifier (_|{letter})({letter}|{digit}|_){0,31}
hex [0-9a-f]

%x COMMENT

%%

"int"                             { return INT; }
"long"                            { return LONG; }
"long long"                       { return LONG_LONG; }
"short"                           { return SHORT; }
"signed"                          { return SIGNED; }
"unsigned"                        { return UNSIGNED; }
"for"                             { return FOR; }
"while"                           { return WHILE; }
"break"                           { return BREAK; }
"continue"                        { return CONTINUE; }
"if"                              { return IF; }
"else"                            { return ELSE; }
"return"                          { return RETURN; }

{identifier}                      {
  yylval.entry = insert(symbol_table, yytext, INT_MAX);
  return IDENTIFIER;
}

{ws}                              ;

[+\-]?[0][x|X]{hex}+[lLuU]?       {
  yylval.dval = (int)strtol(yytext, NULL, 16);
  return HEX_CONSTANT;

}
[+\-]?{digit}+[lLuU]?             {
  yylval.dval = atoi(yytext);
  return DEC_CONSTANT;
}

"/*"                              {
  comment_start = yylineno;
  BEGIN COMMENT;
}
<COMMENT>.|{ws}                      ;
<COMMENT>\n                          { yylineno++; }
<COMMENT>"*/"                        { BEGIN INITIAL; }
<COMMENT>"/*"                        { printf("Line %3d: Nested comments are not valid!\n", yylineno); }
<COMMENT><<EOF>>                     {
  printf("Line %3d: Unterminated comment\n", comment_start);
  yyterminate();
}
"//".*                               ;

\"[^\"\n]*\"                         {
  if(yytext[yyleng - 2] == '\\') {
    yyless(yyleng - 1);
    yymore();
  }
  else {
    insert(constant_table, yytext, INT_MAX);
    return STRING;
  }
}

\"[^\"\n]*$               { printf("Line %3d: Unterminated string %s\n", yylineno, yytext); }
{digit}+({letter}|_)+	    { printf("Line %3d: Illegal identifier name %s\n", yylineno, yytext); }
\n                        { yylineno++; }

"--"			                { return DECR; }
"++"			                { return INCR; }
"+="                      { return ADD_EQ; }
"-="                      { return SUB_EQ; }
"*="                      { return MUL_EQ; }
"/="                      { return DIV_EQ; }
"%="                      { return MOD_EQ; }
"&&"			                { return AND; }
"||"			                { return OR; }
"<="			                { return LESS_EQ; }
">="			                { return GREATER_EQ; }
"=="			                { return EQ; }
"!="		                  { return NOT_EQ; }
.                         { return yytext[0]; }

%%

int yywrap(void) {
    return 1;
}