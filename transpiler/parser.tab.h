/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    OBJECT = 258,                  /* OBJECT  */
    MODEL = 259,                   /* MODEL  */
    PROTOCOL = 260,                /* PROTOCOL  */
    INIT = 261,                    /* INIT  */
    DEFER = 262,                   /* DEFER  */
    FIELDS = 263,                  /* FIELDS  */
    IMPLEMENTS = 264,              /* IMPLEMENTS  */
    MESSAGE = 265,                 /* MESSAGE  */
    SUPERMESSAGE = 266,            /* SUPERMESSAGE  */
    IMPORT = 267,                  /* IMPORT  */
    AUTO = 268,                    /* AUTO  */
    BREAK = 269,                   /* BREAK  */
    CASE = 270,                    /* CASE  */
    CHAR = 271,                    /* CHAR  */
    CONST = 272,                   /* CONST  */
    CONTINUE = 273,                /* CONTINUE  */
    DEFAULT = 274,                 /* DEFAULT  */
    DO = 275,                      /* DO  */
    DOUBLE = 276,                  /* DOUBLE  */
    ELSE = 277,                    /* ELSE  */
    ENUM = 278,                    /* ENUM  */
    EXTERN = 279,                  /* EXTERN  */
    FLOAT = 280,                   /* FLOAT  */
    FOR = 281,                     /* FOR  */
    GOTO = 282,                    /* GOTO  */
    IF = 283,                      /* IF  */
    INT = 284,                     /* INT  */
    LONG = 285,                    /* LONG  */
    REGISTER = 286,                /* REGISTER  */
    RETURN = 287,                  /* RETURN  */
    SHORT = 288,                   /* SHORT  */
    SIGNED = 289,                  /* SIGNED  */
    SIZEOF = 290,                  /* SIZEOF  */
    STATIC = 291,                  /* STATIC  */
    STRUCT = 292,                  /* STRUCT  */
    SWITCH = 293,                  /* SWITCH  */
    TYPEDEF = 294,                 /* TYPEDEF  */
    UNION = 295,                   /* UNION  */
    UNSIGNED = 296,                /* UNSIGNED  */
    VOID = 297,                    /* VOID  */
    VOLATILE = 298,                /* VOLATILE  */
    WHILE = 299,                   /* WHILE  */
    BOOL = 300,                    /* BOOL  */
    COMPLEX = 301,                 /* COMPLEX  */
    IMAGINARY = 302,               /* IMAGINARY  */
    INLINE = 303,                  /* INLINE  */
    RESTRICT = 304,                /* RESTRICT  */
    ALIGNAS = 305,                 /* ALIGNAS  */
    ALIGNOF = 306,                 /* ALIGNOF  */
    ATOMIC = 307,                  /* ATOMIC  */
    GENERIC = 308,                 /* GENERIC  */
    NORETURN = 309,                /* NORETURN  */
    STATIC_ASSERT = 310,           /* STATIC_ASSERT  */
    THREAD_LOCAL = 311,            /* THREAD_LOCAL  */
    SEND = 312,                    /* SEND  */
    INCR = 313,                    /* INCR  */
    DECR = 314,                    /* DECR  */
    EQ = 315,                      /* EQ  */
    NOT_EQ = 316,                  /* NOT_EQ  */
    GREATER_EQ = 317,              /* GREATER_EQ  */
    LESS_EQ = 318,                 /* LESS_EQ  */
    AND = 319,                     /* AND  */
    OR = 320,                      /* OR  */
    SHIFT_LEFT = 321,              /* SHIFT_LEFT  */
    SHIFT_RIGHT = 322,             /* SHIFT_RIGHT  */
    ADD_EQ = 323,                  /* ADD_EQ  */
    SUB_EQ = 324,                  /* SUB_EQ  */
    MUL_EQ = 325,                  /* MUL_EQ  */
    DIV_EQ = 326,                  /* DIV_EQ  */
    MOD_EQ = 327,                  /* MOD_EQ  */
    SHIFT_LEFT_EQ = 328,           /* SHIFT_LEFT_EQ  */
    SHIFT_RIGHT_EQ = 329,          /* SHIFT_RIGHT_EQ  */
    AND_EQ = 330,                  /* AND_EQ  */
    XOR_EQ = 331,                  /* XOR_EQ  */
    OR_EQ = 332,                   /* OR_EQ  */
    ACCESS = 333,                  /* ACCESS  */
    VARIABLE_ARGUMENTS = 334,      /* VARIABLE_ARGUMENTS  */
    DEFINE = 335,                  /* DEFINE  */
    INCLUDE = 336,                 /* INCLUDE  */
    IFDEF = 337,                   /* IFDEF  */
    UNDEF = 338,                   /* UNDEF  */
    IFNDEF = 339,                  /* IFNDEF  */
    PRE_IF = 340,                  /* PRE_IF  */
    PRE_ELIF = 341,                /* PRE_ELIF  */
    PRE_ELSE = 342,                /* PRE_ELSE  */
    ENDIF = 343,                   /* ENDIF  */
    ERROR = 344,                   /* ERROR  */
    WARNING = 345,                 /* WARNING  */
    PRAGMA = 346,                  /* PRAGMA  */
    LINE = 347,                    /* LINE  */
    DEFINED = 348,                 /* DEFINED  */
    PRE_CONC = 349,                /* PRE_CONC  */
    TYPEDEF_NAME = 350,            /* TYPEDEF_NAME  */
    INT_CONSTANT = 351,            /* INT_CONSTANT  */
    FLOAT_CONSTANT = 352,          /* FLOAT_CONSTANT  */
    ENUMERATION_CONSTANT = 353,    /* ENUMERATION_CONSTANT  */
    IDENTIFIER = 354,              /* IDENTIFIER  */
    STRING = 355,                  /* STRING  */
    FUNC_NAME = 356,               /* FUNC_NAME  */
    HEADER = 357                   /* HEADER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "parser.y"

    string *String;
    vector *Vector;

#line 171 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
