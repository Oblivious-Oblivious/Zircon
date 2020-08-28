O  [0-7]
D  [0-9]
NZ [1-9]
L  [a-zA-Z_]
A  [a-zA-Z_0-9]
AD [a-zA-Z_0-9.]
H  [a-fA-F0-9]
HP (0[xX])
E  ([Ee][+-]?{D}+)
P  ([Pp][+-]?{D}+)
FS (f|F|l|L)
IS (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP (u|U|L)
SP (u8|u|U|L)
ES (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS [ \t\v\n\f]

%{

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "string.h"
#include "hashmap.h"
#include "parser.tab.h"

#define tokenize(__TOKEN) do { \
    yylval.String = new_string(yytext); \
    return __TOKEN; \
} while(0)

extern hashmap *typedef_names;
extern hashmap *enum_constants;

extern void yyerror(const char*);
static int tokenize_type(void);

size_t comment_start = 0;

int sym_type(char *identifier) {
    if(hashmap_get(typedef_names, identifier) != NULL)
        return TYPEDEF_NAME;
    else if(hashmap_get(enum_constants, identifier) != NULL)
        return ENUMERATION_CONSTANT;
    return IDENTIFIER;
}

%}

%x COMMENT

%%

"object"                               tokenize(OBJECT);
"model"                                tokenize(MODEL);
"protocol"                             tokenize(PROTOCOL);

"init"                                 tokenize(INIT);
"defer"                                tokenize(DEFER);
"fields"                               tokenize(FIELDS);

"implements"                           tokenize(IMPLEMENTS);
"message"                              tokenize(MESSAGE);
"supermessage"                         tokenize(SUPERMESSAGE);

"auto"                                 tokenize(AUTO);
"break"                                tokenize(BREAK);
"case"                                 tokenize(CASE);
"char"                                 tokenize(CHAR);
"const"                                tokenize(CONST);
"continue"                             tokenize(CONTINUE);
"default"                              tokenize(DEFAULT);
"do"                                   tokenize(DO);
"double"                               tokenize(DOUBLE);
"else"                                 tokenize(ELSE);
"enum"                                 tokenize(ENUM);
"extern"                               tokenize(EXTERN);
"float"                                tokenize(FLOAT);
"for"                                  tokenize(FOR);
"goto"                                 tokenize(GOTO);
"if"                                   tokenize(IF);
"int"                                  tokenize(INT);
"long"                                 tokenize(LONG);
"register"                             tokenize(REGISTER);
"return"                               tokenize(RETURN);
"short"                                tokenize(SHORT);
"signed"                               tokenize(SIGNED);
"sizeof"                               tokenize(SIZEOF);
"static"                               tokenize(STATIC);
"struct"                               tokenize(STRUCT);
"switch"                               tokenize(SWITCH);
"typedef"                              tokenize(TYPEDEF);
"union"                                tokenize(UNION);
"unsigned"                             tokenize(UNSIGNED);
"void"                                 tokenize(VOID);
"volatile"                             tokenize(VOLATILE);
"while"                                tokenize(WHILE);

"_Bool"                                tokenize(BOOL);
"_Complex"                             tokenize(COMPLEX);
"_Imaginary"                           tokenize(IMAGINARY);
"inline"                               tokenize(INLINE);
"restrict"                             tokenize(RESTRICT);

"_Alignas"                             tokenize(ALIGNAS);
"_Alignof"                             tokenize(ALIGNOF);
"_Atomic"                              tokenize(ATOMIC);
"_Generic"                             tokenize(GENERIC);
"_Noreturn"                            tokenize(NORETURN);
"_Static_assert"                       tokenize(STATIC_ASSERT);
"_Thread_local"                        tokenize(THREAD_LOCAL);
"__func__"                             tokenize(FUNC_NAME);

"|>"                                   tokenize(SEND);
"@"                                    tokenize('@');

"("                                    tokenize('(');
")"                                    tokenize(')');
("["|"<:")                             tokenize('[');
("]"|":>")                             tokenize(']');
("{"|"<%")                             tokenize('{');
("}"|"%>")                             tokenize('}');
":"                                    tokenize(':');
";"                                    tokenize(';');
","                                    tokenize(',');
"+"                                    tokenize('+');
"-"                                    tokenize('-');
"*"                                    tokenize('*');
"/"                                    tokenize('/');
"%"                                    tokenize('%');
"++"                                   tokenize(INCR);
"--"                                   tokenize(DECR);

"=="                                   tokenize(EQ);
"!="                                   tokenize(NOT_EQ);
">"                                    tokenize('>');
"<"                                    tokenize('<');
">="                                   tokenize(GREATER_EQ);
"<="                                   tokenize(LESS_EQ);

"&&"                                   tokenize(AND);
"||"                                   tokenize(OR);
"!"                                    tokenize('!');

"&"                                    tokenize('&');
"|"                                    tokenize('|');
"^"                                    tokenize('^');
"~"                                    tokenize('~');
"<<"                                   tokenize(SHIFT_LEFT);
">>"                                   tokenize(SHIFT_RIGHT);

"="                                    tokenize('=');
"+="                                   tokenize(ADD_EQ);
"-="                                   tokenize(SUB_EQ);
"*="                                   tokenize(MUL_EQ);
"/="                                   tokenize(DIV_EQ);
"%="                                   tokenize(MOD_EQ);
"<<="                                  tokenize(SHIFT_LEFT_EQ);
">>="                                  tokenize(SHIFT_RIGHT_EQ);
"&="                                   tokenize(AND_EQ);
"|="                                   tokenize(OR_EQ);
"^="                                   tokenize(XOR_EQ);

"?"                                    tokenize('?');
"."                                    tokenize('.');
"->"                                   tokenize(ACCESS);

"..."                                  tokenize(VARIABLE_ARGUMENTS);

"/*"                                   {
    comment_start = yylineno;
    BEGIN COMMENT;
}
<COMMENT>\n                            yylineno++;
<COMMENT>.|{WS}                        ;
<COMMENT>"*/"                          BEGIN INITIAL;
<COMMENT>"/*"                          yyerror("invalid nested comments");
<COMMENT><<EOF>>                       {
    yyerror("unterminated comment");
    yyterminate();
}
"//".*                                 ;

"#import"                              tokenize(IMPORT);

"#define"                              tokenize(DEFINE);
"#include"                             tokenize(INCLUDE);
"#ifdef"                               tokenize(IFDEF);
"#undef"                               tokenize(UNDEF);
"#ifndef"                              tokenize(IFNDEF);
"#if"                                  tokenize(PRE_IF);
"#elif"                                tokenize(PRE_ELIF);
"#else"                                tokenize(PRE_ELSE);
"#endif"                               tokenize(ENDIF);
"#error"                               tokenize(ERROR);
"#warning"                             tokenize(WARNING);
"#pragma"                              tokenize(PRAGMA);
"#line"                                tokenize(LINE);
"#"                                    tokenize('#');
"##"                                   tokenize(PRE_CONC);

"defined"                              tokenize(DEFINED);

{L}{A}*                                return tokenize_type();
{L}{AD}*                               tokenize(HEADER);

{HP}{H}+{IS}?                          tokenize(INT_CONSTANT);
{NZ}{D}*{IS}?                          tokenize(INT_CONSTANT);
"0"{O}*{IS}?                           tokenize(INT_CONSTANT);
{CP}?"'"([^'\\\n]|{ES})+"'"            tokenize(INT_CONSTANT);

{D}+{E}{FS}?                           tokenize(FLOAT_CONSTANT);
{D}*"."{D}+{E}?{FS}?                   tokenize(FLOAT_CONSTANT);
{D}+"."{E}?{FS}?                       tokenize(FLOAT_CONSTANT);
{HP}{H}+{P}{FS}?                       tokenize(FLOAT_CONSTANT);
{HP}{H}*"."{H}+{P}{FS}?                tokenize(FLOAT_CONSTANT);
{HP}{H}+"."{P}{FS}?                    tokenize(FLOAT_CONSTANT);

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+      tokenize(STRING);

\"[^\"\n]*$                            yyerror("unterminated string");
{D}+({L}|_)+                           yyerror("illegal identifier name");

\n                                     yylineno++;

{WS}+                                  {}
.                                      {}

%%

int yywrap(void) {
    return 1;
}

static int tokenize_type(void) {
    switch(sym_type(yytext)) {
        case TYPEDEF_NAME:         tokenize(TYPEDEF_NAME);
        case ENUMERATION_CONSTANT: tokenize(ENUMERATION_CONSTANT);
        default:                   tokenize(IDENTIFIER);
    }
}