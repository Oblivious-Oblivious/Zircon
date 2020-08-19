%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "symboltable.h"
#include "tokens.h"

entry_t **symbol_table;
entry_t **constant_table;
int comment_start = 0;

%}

letter [a-zA-Z]
digit [0-9]
ws  [ \t\r\f\v]+
identifier (_|{letter})({letter}|{digit}|_){0,31}
hex [0-9a-f]

%x COMMENT
%x PREPROCCESSOR

%%

"int"                             { printf("\t%-30s : %3d\n", yytext, INT); }
"long"                            { printf("\t%-30s : %3d\n", yytext, LONG); }
"long long"                       { printf("\t%-30s : %3d\n", yytext, LONG_LONG); }
"short"                           { printf("\t%-30s : %3d\n", yytext, SHORT); }
"signed"                          { printf("\t%-30s : %3d\n", yytext, SIGNED); }
"unsigned"                        { printf("\t%-30s : %3d\n", yytext, UNSIGNED); }
"for"                             { printf("\t%-30s : %3d\n", yytext, FOR); }
"break"                           { printf("\t%-30s : %3d\n", yytext, BREAK); }
"continue"                        { printf("\t%-30s : %3d\n", yytext, CONTINUE); }
"if"                              { printf("\t%-30s : %3d\n", yytext, IF); }
"else"                            { printf("\t%-30s : %3d\n", yytext, ELSE); }
"return"                          { printf("\t%-30s : %3d\n", yytext, RETURN); }

{identifier}                      {
  printf("\t%-30s : %3d\n", yytext,IDENTIFIER);
  insert(symbol_table, yytext, IDENTIFIER);
}

{ws}                              ;

[+\-]?[0][x|X]{hex}+[lLuU]?       {
  printf("\t%-30s : %3d\n", yytext, HEX_CONSTANT);
  insert(constant_table, yytext, HEX_CONSTANT);
}

[+\-]?{digit}+[lLuU]?             {
  printf("\t%-30s : %3d\n", yytext,DEC_CONSTANT);
  insert(constant_table, yytext, DEC_CONSTANT);
}

"/*"                              {
  comment_start = yylineno;
  BEGIN COMMENT;
}

<COMMENT>.|{ws}                   ;
<COMMENT>\n                       { yylineno++; }
<COMMENT>"*/"                     { BEGIN INITIAL; }
<COMMENT>"/*"                     { printf("Line %3d: Nested comments are not valid!\n", yylineno); }
<COMMENT><<EOF>>                  {
  printf("Line %3d: Unterminated comment\n", comment_start);
  yyterminate();
}
^"#include"                       { BEGIN PREPROCCESSOR; }
<PREPROCCESSOR>"<"[^<>\n]+">"     { printf("\t%-30s : %3d\n", yytext, HEADER_FILE); }
<PREPROCCESSOR>{ws}               ;
<PREPROCCESSOR>\"[^"\n]+\"        { printf("\t%-30s : %3d\n", yytext, HEADER_FILE); }
<PREPROCCESSOR>\n                 {
  yylineno++;
  BEGIN INITIAL;
}
<PREPROCCESSOR>.                  { printf("Line %3d: Illegal header file format \n", yylineno); }
"//".*                            ;

\"[^\"\n]*\"                      {
  if(yytext[yyleng - 2] == '\\') { /* check if it was an escaped quote */
    yyless(yyleng - 1); /* push the quote back if it was escaped */
    yymore();
  }
  else
    insert(constant_table, yytext, STRING);
}

\"[^\"\n]*$                       { printf("Line %3d: Unterminated string %s\n",yylineno,yytext);}
{digit}+({letter}|_)+	            { printf("Line %3d: Illegal identifier name %s\n",yylineno,yytext);}

\n                                { yylineno++; }

"--"			                        { printf("\t%-30s : %3d\n", yytext, DECR); }
"++"			                        { printf("\t%-30s : %3d\n", yytext, INCR); }
"->"			                        { printf("\t%-30s : %3d\n", yytext, ACCESS); }
"&&"			                        { printf("\t%-30s : %3d\n", yytext, AND); }
"||"			                        { printf("\t%-30s : %3d\n", yytext, OR); }
"<="			                        { printf("\t%-30s : %3d\n", yytext, LESS_EQ); }
">="			                        { printf("\t%-30s : %3d\n", yytext, GREATER_EQ); }
"=="			                        { printf("\t%-30s : %3d\n", yytext, EQ); }
"!="		                          { printf("\t%-30s : %3d\n", yytext, NOT_EQ); }
";"			                          { printf("\t%-30s : %3d\n", yytext, DELIMITER); }
"{"                               { printf("\t%-30s : %3d\n", yytext, LEFT_CURLY); }
"}"                               { printf("\t%-30s : %3d\n", yytext, RIGHT_CURLY); }
","			                          { printf("\t%-30s : %3d\n", yytext, COMMA); }
"="			                          { printf("\t%-30s : %3d\n", yytext, ASSIGN); }
"("			                          { printf("\t%-30s : %3d\n", yytext, LEFT_PAREN); }
")"			                          { printf("\t%-30s : %3d\n", yytext, RIGHT_PAREN); }
"["                               { printf("\t%-30s : %3d\n", yytext, LEFT_BRACKET); }
"]"                               { printf("\t%-30s : %3d\n", yytext, RIGHT_BRACKET); }
"-"			                          { printf("\t%-30s : %3d\n", yytext, MINUS); }
"+"			                          { printf("\t%-30s : %3d\n", yytext, PLUS); }
"*"			                          { printf("\t%-30s : %3d\n", yytext, STAR); }
"/"		                            { printf("\t%-30s : %3d\n", yytext, FW_SLASH); }
"%"			                          { printf("\t%-30s : %3d\n", yytext, MOD); }
"<"			                          { printf("\t%-30s : %3d\n", yytext, LESS); }
">"			                          { printf("\t%-30s : %3d\n", yytext, GREATER); }
.                                 { printf("Line %3d: Illegal character %s\n", yylineno, yytext); }

%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
  assert(argc == 2 && argv && argv[1]);
  yyin = fopen(argv[1], "r");

  symbol_table = create_table();
  constant_table = create_table();
  yylex();

  printf("\n\tSymbol table");
  display(symbol_table);
  
  printf("\n\tConstants Table");
  display(constant_table);
}
