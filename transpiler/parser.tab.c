/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stdboolean.h"
#include "string.h"
#include "hashmap.h"

/* Parser definitions */
int yylex(void);
void yyerror(char*);

/* Result of the parsed file */
string *translation;
bool main_flag = false;

/* Hashmaps containing special identifiers */
hashmap *typedef_names;
hashmap *object_names;
hashmap *enum_constants;

/****/
hashmap *models;
hashmap *protocols;
hashmap *objects;
/****/

static char replace_spaces(char c) {
    if(c == ' ') return '_';
    return c;
}


#line 108 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_OBJECT = 3,                     /* OBJECT  */
  YYSYMBOL_MODEL = 4,                      /* MODEL  */
  YYSYMBOL_PROTOCOL = 5,                   /* PROTOCOL  */
  YYSYMBOL_INIT = 6,                       /* INIT  */
  YYSYMBOL_DEFER = 7,                      /* DEFER  */
  YYSYMBOL_FIELDS = 8,                     /* FIELDS  */
  YYSYMBOL_IMPLEMENTS = 9,                 /* IMPLEMENTS  */
  YYSYMBOL_MESSAGE = 10,                   /* MESSAGE  */
  YYSYMBOL_SUPERMESSAGE = 11,              /* SUPERMESSAGE  */
  YYSYMBOL_IMPORT = 12,                    /* IMPORT  */
  YYSYMBOL_AUTO = 13,                      /* AUTO  */
  YYSYMBOL_BREAK = 14,                     /* BREAK  */
  YYSYMBOL_CASE = 15,                      /* CASE  */
  YYSYMBOL_CHAR = 16,                      /* CHAR  */
  YYSYMBOL_CONST = 17,                     /* CONST  */
  YYSYMBOL_CONTINUE = 18,                  /* CONTINUE  */
  YYSYMBOL_DEFAULT = 19,                   /* DEFAULT  */
  YYSYMBOL_DO = 20,                        /* DO  */
  YYSYMBOL_DOUBLE = 21,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_ENUM = 23,                      /* ENUM  */
  YYSYMBOL_EXTERN = 24,                    /* EXTERN  */
  YYSYMBOL_FLOAT = 25,                     /* FLOAT  */
  YYSYMBOL_FOR = 26,                       /* FOR  */
  YYSYMBOL_GOTO = 27,                      /* GOTO  */
  YYSYMBOL_IF = 28,                        /* IF  */
  YYSYMBOL_INT = 29,                       /* INT  */
  YYSYMBOL_LONG = 30,                      /* LONG  */
  YYSYMBOL_REGISTER = 31,                  /* REGISTER  */
  YYSYMBOL_RETURN = 32,                    /* RETURN  */
  YYSYMBOL_SHORT = 33,                     /* SHORT  */
  YYSYMBOL_SIGNED = 34,                    /* SIGNED  */
  YYSYMBOL_SIZEOF = 35,                    /* SIZEOF  */
  YYSYMBOL_STATIC = 36,                    /* STATIC  */
  YYSYMBOL_STRUCT = 37,                    /* STRUCT  */
  YYSYMBOL_SWITCH = 38,                    /* SWITCH  */
  YYSYMBOL_TYPEDEF = 39,                   /* TYPEDEF  */
  YYSYMBOL_UNION = 40,                     /* UNION  */
  YYSYMBOL_UNSIGNED = 41,                  /* UNSIGNED  */
  YYSYMBOL_VOID = 42,                      /* VOID  */
  YYSYMBOL_VOLATILE = 43,                  /* VOLATILE  */
  YYSYMBOL_WHILE = 44,                     /* WHILE  */
  YYSYMBOL_BOOL = 45,                      /* BOOL  */
  YYSYMBOL_COMPLEX = 46,                   /* COMPLEX  */
  YYSYMBOL_IMAGINARY = 47,                 /* IMAGINARY  */
  YYSYMBOL_INLINE = 48,                    /* INLINE  */
  YYSYMBOL_RESTRICT = 49,                  /* RESTRICT  */
  YYSYMBOL_ALIGNAS = 50,                   /* ALIGNAS  */
  YYSYMBOL_ALIGNOF = 51,                   /* ALIGNOF  */
  YYSYMBOL_ATOMIC = 52,                    /* ATOMIC  */
  YYSYMBOL_GENERIC = 53,                   /* GENERIC  */
  YYSYMBOL_NORETURN = 54,                  /* NORETURN  */
  YYSYMBOL_STATIC_ASSERT = 55,             /* STATIC_ASSERT  */
  YYSYMBOL_THREAD_LOCAL = 56,              /* THREAD_LOCAL  */
  YYSYMBOL_SEND = 57,                      /* SEND  */
  YYSYMBOL_INCR = 58,                      /* INCR  */
  YYSYMBOL_DECR = 59,                      /* DECR  */
  YYSYMBOL_EQ = 60,                        /* EQ  */
  YYSYMBOL_NOT_EQ = 61,                    /* NOT_EQ  */
  YYSYMBOL_GREATER_EQ = 62,                /* GREATER_EQ  */
  YYSYMBOL_LESS_EQ = 63,                   /* LESS_EQ  */
  YYSYMBOL_AND = 64,                       /* AND  */
  YYSYMBOL_OR = 65,                        /* OR  */
  YYSYMBOL_SHIFT_LEFT = 66,                /* SHIFT_LEFT  */
  YYSYMBOL_SHIFT_RIGHT = 67,               /* SHIFT_RIGHT  */
  YYSYMBOL_ADD_EQ = 68,                    /* ADD_EQ  */
  YYSYMBOL_SUB_EQ = 69,                    /* SUB_EQ  */
  YYSYMBOL_MUL_EQ = 70,                    /* MUL_EQ  */
  YYSYMBOL_DIV_EQ = 71,                    /* DIV_EQ  */
  YYSYMBOL_MOD_EQ = 72,                    /* MOD_EQ  */
  YYSYMBOL_SHIFT_LEFT_EQ = 73,             /* SHIFT_LEFT_EQ  */
  YYSYMBOL_SHIFT_RIGHT_EQ = 74,            /* SHIFT_RIGHT_EQ  */
  YYSYMBOL_AND_EQ = 75,                    /* AND_EQ  */
  YYSYMBOL_XOR_EQ = 76,                    /* XOR_EQ  */
  YYSYMBOL_OR_EQ = 77,                     /* OR_EQ  */
  YYSYMBOL_ACCESS = 78,                    /* ACCESS  */
  YYSYMBOL_VARIABLE_ARGUMENTS = 79,        /* VARIABLE_ARGUMENTS  */
  YYSYMBOL_DEFINE = 80,                    /* DEFINE  */
  YYSYMBOL_INCLUDE = 81,                   /* INCLUDE  */
  YYSYMBOL_IFDEF = 82,                     /* IFDEF  */
  YYSYMBOL_UNDEF = 83,                     /* UNDEF  */
  YYSYMBOL_IFNDEF = 84,                    /* IFNDEF  */
  YYSYMBOL_PRE_IF = 85,                    /* PRE_IF  */
  YYSYMBOL_PRE_ELIF = 86,                  /* PRE_ELIF  */
  YYSYMBOL_PRE_ELSE = 87,                  /* PRE_ELSE  */
  YYSYMBOL_ENDIF = 88,                     /* ENDIF  */
  YYSYMBOL_ERROR = 89,                     /* ERROR  */
  YYSYMBOL_WARNING = 90,                   /* WARNING  */
  YYSYMBOL_PRAGMA = 91,                    /* PRAGMA  */
  YYSYMBOL_LINE = 92,                      /* LINE  */
  YYSYMBOL_DEFINED = 93,                   /* DEFINED  */
  YYSYMBOL_PRE_CONC = 94,                  /* PRE_CONC  */
  YYSYMBOL_TYPEDEF_NAME = 95,              /* TYPEDEF_NAME  */
  YYSYMBOL_INT_CONSTANT = 96,              /* INT_CONSTANT  */
  YYSYMBOL_FLOAT_CONSTANT = 97,            /* FLOAT_CONSTANT  */
  YYSYMBOL_ENUMERATION_CONSTANT = 98,      /* ENUMERATION_CONSTANT  */
  YYSYMBOL_IDENTIFIER = 99,                /* IDENTIFIER  */
  YYSYMBOL_STRING = 100,                   /* STRING  */
  YYSYMBOL_FUNC_NAME = 101,                /* FUNC_NAME  */
  YYSYMBOL_HEADER = 102,                   /* HEADER  */
  YYSYMBOL_103_ = 103,                     /* '('  */
  YYSYMBOL_104_ = 104,                     /* ')'  */
  YYSYMBOL_105_ = 105,                     /* ','  */
  YYSYMBOL_106_ = 106,                     /* ':'  */
  YYSYMBOL_107_ = 107,                     /* '['  */
  YYSYMBOL_108_ = 108,                     /* ']'  */
  YYSYMBOL_109_ = 109,                     /* '.'  */
  YYSYMBOL_110_ = 110,                     /* '{'  */
  YYSYMBOL_111_ = 111,                     /* '}'  */
  YYSYMBOL_112_ = 112,                     /* '&'  */
  YYSYMBOL_113_ = 113,                     /* '*'  */
  YYSYMBOL_114_ = 114,                     /* '+'  */
  YYSYMBOL_115_ = 115,                     /* '-'  */
  YYSYMBOL_116_ = 116,                     /* '~'  */
  YYSYMBOL_117_ = 117,                     /* '!'  */
  YYSYMBOL_118_ = 118,                     /* '/'  */
  YYSYMBOL_119_ = 119,                     /* '%'  */
  YYSYMBOL_120_ = 120,                     /* '<'  */
  YYSYMBOL_121_ = 121,                     /* '>'  */
  YYSYMBOL_122_ = 122,                     /* '^'  */
  YYSYMBOL_123_ = 123,                     /* '|'  */
  YYSYMBOL_124_ = 124,                     /* '?'  */
  YYSYMBOL_125_ = 125,                     /* '='  */
  YYSYMBOL_126_ = 126,                     /* ';'  */
  YYSYMBOL_YYACCEPT = 127,                 /* $accept  */
  YYSYMBOL_primary_expression = 128,       /* primary_expression  */
  YYSYMBOL_constant = 129,                 /* constant  */
  YYSYMBOL_enumeration_constant = 130,     /* enumeration_constant  */
  YYSYMBOL_string = 131,                   /* string  */
  YYSYMBOL_generic_selection = 132,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 133,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 134,      /* generic_association  */
  YYSYMBOL_postfix_expression = 135,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 136, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 137,         /* unary_expression  */
  YYSYMBOL_unary_operator = 138,           /* unary_operator  */
  YYSYMBOL_cast_expression = 139,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 140, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 141,      /* additive_expression  */
  YYSYMBOL_shift_expression = 142,         /* shift_expression  */
  YYSYMBOL_relational_expression = 143,    /* relational_expression  */
  YYSYMBOL_equality_expression = 144,      /* equality_expression  */
  YYSYMBOL_and_expression = 145,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 146,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 147,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 148,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 149,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 150,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 151,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 152,      /* assignment_operator  */
  YYSYMBOL_expression = 153,               /* expression  */
  YYSYMBOL_constant_expression = 154,      /* constant_expression  */
  YYSYMBOL_declaration = 155,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 156,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 157,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 158,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 159,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 160,           /* type_specifier  */
  YYSYMBOL_object_specifier = 161,         /* object_specifier  */
  YYSYMBOL_object_declaration_list = 162,  /* object_declaration_list  */
  YYSYMBOL_object_declaration = 163,       /* object_declaration  */
  YYSYMBOL_fields_declaration = 164,       /* fields_declaration  */
  YYSYMBOL_abstract_message_declaration_list = 165, /* abstract_message_declaration_list  */
  YYSYMBOL_abstract_message_declaration = 166, /* abstract_message_declaration  */
  YYSYMBOL_message_declaration_list = 167, /* message_declaration_list  */
  YYSYMBOL_message_declaration = 168,      /* message_declaration  */
  YYSYMBOL_constructor_declaration = 169,  /* constructor_declaration  */
  YYSYMBOL_destructor_declaration = 170,   /* destructor_declaration  */
  YYSYMBOL_declaration_specifiers_or_pointer = 171, /* declaration_specifiers_or_pointer  */
  YYSYMBOL_self_or_super = 172,            /* self_or_super  */
  YYSYMBOL_model = 173,                    /* model  */
  YYSYMBOL_protocol = 174,                 /* protocol  */
  YYSYMBOL_object = 175,                   /* object  */
  YYSYMBOL_struct_or_union_specifier = 176, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 177,          /* struct_or_union  */
  YYSYMBOL_object_parameter_type_list = 178, /* object_parameter_type_list  */
  YYSYMBOL_object_parameter_type = 179,    /* object_parameter_type  */
  YYSYMBOL_model_declaration_list = 180,   /* model_declaration_list  */
  YYSYMBOL_model_declaration = 181,        /* model_declaration  */
  YYSYMBOL_struct_declaration_list = 182,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 183,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 184, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 185,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 186,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 187,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 188,          /* enumerator_list  */
  YYSYMBOL_enumerator = 189,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 190,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 191,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 192,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 193,      /* alignment_specifier  */
  YYSYMBOL_declarator = 194,               /* declarator  */
  YYSYMBOL_direct_declarator = 195,        /* direct_declarator  */
  YYSYMBOL_pointer = 196,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 197,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 198,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 199,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 200,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 201,          /* identifier_list  */
  YYSYMBOL_type_name = 202,                /* type_name  */
  YYSYMBOL_abstract_declarator = 203,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 204, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 205,              /* initializer  */
  YYSYMBOL_initializer_list = 206,         /* initializer_list  */
  YYSYMBOL_designation = 207,              /* designation  */
  YYSYMBOL_designator_list = 208,          /* designator_list  */
  YYSYMBOL_designator = 209,               /* designator  */
  YYSYMBOL_static_assert_declaration = 210, /* static_assert_declaration  */
  YYSYMBOL_statement = 211,                /* statement  */
  YYSYMBOL_labeled_statement = 212,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 213,       /* compound_statement  */
  YYSYMBOL_block_item_list = 214,          /* block_item_list  */
  YYSYMBOL_block_item = 215,               /* block_item  */
  YYSYMBOL_expression_statement = 216,     /* expression_statement  */
  YYSYMBOL_selection_statement = 217,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 218,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 219,           /* jump_statement  */
  YYSYMBOL_translation_unit = 220,         /* translation_unit  */
  YYSYMBOL_external_declaration = 221,     /* external_declaration  */
  YYSYMBOL_function_definition = 222,      /* function_definition  */
  YYSYMBOL_declaration_list = 223,         /* declaration_list  */
  YYSYMBOL_preprocessor_directive = 224,   /* preprocessor_directive  */
  YYSYMBOL_preprocessor_control_line = 225, /* preprocessor_control_line  */
  YYSYMBOL_preprocessor_constant_expression = 226, /* preprocessor_constant_expression  */
  YYSYMBOL_preprocessor_conditional = 227, /* preprocessor_conditional  */
  YYSYMBOL_preprocessor_if_line = 228,     /* preprocessor_if_line  */
  YYSYMBOL_preprocessor_elif_line = 229,   /* preprocessor_elif_line  */
  YYSYMBOL_preprocessor_else_line = 230,   /* preprocessor_else_line  */
  YYSYMBOL_preprocessor_if_part = 231,     /* preprocessor_if_part  */
  YYSYMBOL_preprocessor_elif_parts = 232,  /* preprocessor_elif_parts  */
  YYSYMBOL_preprocessor_else_part = 233    /* preprocessor_else_part  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  192
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3819

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  127
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  107
/* YYNRULES -- Number of rules.  */
#define YYNRULES  351
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  648

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   357


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   117,     2,     2,     2,   119,   112,     2,
     103,   104,   113,   114,   105,   115,   109,   118,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   106,   126,
     120,   125,   121,   124,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   107,     2,   108,   122,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   110,   123,   111,   116,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    92,    92,    95,    98,   101,   106,   112,   115,   118,
     124,   133,   136,   142,   152,   155,   163,   168,   175,   178,
     184,   188,   194,   212,   228,   246,   262,   267,   272,   276,
     280,   287,   297,   300,   308,   311,   315,   319,   323,   327,
     332,   340,   343,   346,   349,   352,   355,   361,   364,   373,
     376,   381,   386,   394,   397,   402,   410,   413,   418,   426,
     429,   434,   439,   444,   452,   455,   460,   468,   471,   479,
     482,   490,   493,   501,   504,   512,   515,   523,   526,   536,
     539,   547,   550,   553,   556,   559,   562,   565,   568,   571,
     574,   577,   583,   586,   590,   596,   600,   605,   611,   615,
     618,   622,   625,   629,   632,   636,   639,   643,   649,   652,
     660,   665,   671,   674,   677,   680,   683,   686,   692,   695,
     698,   701,   704,   707,   710,   713,   716,   719,   722,   725,
     728,   732,   736,   740,   746,   763,   786,  1259,  1747,  1750,
    1757,  1760,  1766,  1770,  1783,  1796,  1803,  1807,  1817,  1825,
    1835,  1839,  1849,  1857,  1865,  1873,  1881,  1884,  1890,  1908,
    1919,  1922,  1929,  1938,  1944,  1950,  1956,  1962,  1972,  1982,
    1985,  1991,  1995,  2005,  2012,  2016,  2023,  2031,  2034,  2041,
    2045,  2050,  2056,  2060,  2063,  2067,  2073,  2076,  2084,  2088,
    2093,  2099,  2105,  2111,  2121,  2131,  2141,  2144,  2152,  2157,
    2163,  2171,  2174,  2177,  2180,  2186,  2189,  2195,  2200,  2208,
    2212,  2218,  2221,  2226,  2230,  2234,  2242,  2249,  2255,  2263,
    2270,  2276,  2282,  2288,  2292,  2301,  2306,  2310,  2314,  2320,
    2323,  2330,  2334,  2340,  2343,  2351,  2358,  2362,  2366,  2372,
    2375,  2383,  2387,  2393,  2397,  2400,  2406,  2411,  2414,  2417,
    2423,  2428,  2435,  2441,  2446,  2451,  2455,  2459,  2466,  2472,
    2479,  2487,  2493,  2499,  2502,  2507,  2511,  2520,  2525,  2530,
    2536,  2540,  2543,  2548,  2556,  2563,  2566,  2573,  2578,  2585,
    2595,  2598,  2601,  2604,  2607,  2610,  2616,  2624,  2630,  2637,
    2640,  2648,  2651,  2658,  2661,  2667,  2670,  2677,  2685,  2691,
    2700,  2706,  2713,  2720,  2728,  2735,  2746,  2754,  2758,  2762,
    2766,  2774,  2778,  2785,  2788,  2791,  2794,  2800,  2818,  2837,
    2840,  2847,  2850,  2853,  2859,  2866,  2871,  2880,  2887,  2892,
    2898,  2921,  2925,  2931,  2935,  2939,  2943,  2950,  2955,  2960,
    2967,  2971,  2977,  2985,  2990,  2995,  3003,  3011,  3018,  3026,
    3031,  3040
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "OBJECT", "MODEL",
  "PROTOCOL", "INIT", "DEFER", "FIELDS", "IMPLEMENTS", "MESSAGE",
  "SUPERMESSAGE", "IMPORT", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT",
  "FOR", "GOTO", "IF", "INT", "LONG", "REGISTER", "RETURN", "SHORT",
  "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDEF", "UNION",
  "UNSIGNED", "VOID", "VOLATILE", "WHILE", "BOOL", "COMPLEX", "IMAGINARY",
  "INLINE", "RESTRICT", "ALIGNAS", "ALIGNOF", "ATOMIC", "GENERIC",
  "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "SEND", "INCR", "DECR",
  "EQ", "NOT_EQ", "GREATER_EQ", "LESS_EQ", "AND", "OR", "SHIFT_LEFT",
  "SHIFT_RIGHT", "ADD_EQ", "SUB_EQ", "MUL_EQ", "DIV_EQ", "MOD_EQ",
  "SHIFT_LEFT_EQ", "SHIFT_RIGHT_EQ", "AND_EQ", "XOR_EQ", "OR_EQ", "ACCESS",
  "VARIABLE_ARGUMENTS", "DEFINE", "INCLUDE", "IFDEF", "UNDEF", "IFNDEF",
  "PRE_IF", "PRE_ELIF", "PRE_ELSE", "ENDIF", "ERROR", "WARNING", "PRAGMA",
  "LINE", "DEFINED", "PRE_CONC", "TYPEDEF_NAME", "INT_CONSTANT",
  "FLOAT_CONSTANT", "ENUMERATION_CONSTANT", "IDENTIFIER", "STRING",
  "FUNC_NAME", "HEADER", "'('", "')'", "','", "':'", "'['", "']'", "'.'",
  "'{'", "'}'", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'",
  "'<'", "'>'", "'^'", "'|'", "'?'", "'='", "';'", "$accept",
  "primary_expression", "constant", "enumeration_constant", "string",
  "generic_selection", "generic_assoc_list", "generic_association",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "object_specifier", "object_declaration_list",
  "object_declaration", "fields_declaration",
  "abstract_message_declaration_list", "abstract_message_declaration",
  "message_declaration_list", "message_declaration",
  "constructor_declaration", "destructor_declaration",
  "declaration_specifiers_or_pointer", "self_or_super", "model",
  "protocol", "object", "struct_or_union_specifier", "struct_or_union",
  "object_parameter_type_list", "object_parameter_type",
  "model_declaration_list", "model_declaration", "struct_declaration_list",
  "struct_declaration", "specifier_qualifier_list",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "atomic_type_specifier",
  "type_qualifier", "function_specifier", "alignment_specifier",
  "declarator", "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator",
  "static_assert_declaration", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", "preprocessor_directive",
  "preprocessor_control_line", "preprocessor_constant_expression",
  "preprocessor_conditional", "preprocessor_if_line",
  "preprocessor_elif_line", "preprocessor_else_line",
  "preprocessor_if_part", "preprocessor_elif_parts",
  "preprocessor_else_part", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,    40,    41,    44,    58,    91,    93,    46,
     123,   125,    38,    42,    43,    45,   126,    33,    47,    37,
      60,    62,    94,   124,    63,    61,    59
};
#endif

#define YYPACT_NINF (-547)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-239)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     989,  -547,  -547,  -547,    -8,  -547,  -547,  -547,  -547,    46,
    -547,  -547,  -547,  -547,  -547,  -547,  -547,  3537,  -547,  -547,
    -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,
      40,    68,    74,    79,  -547,   131,  -547,  3562,  3562,   143,
     -55,   146,   149,   155,  3588,   162,   172,   175,   183,    71,
     190,  -547,  -547,  -547,  -547,  -547,  -547,   739,  -547,  -547,
    -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,   340,  -547,
    3588,  -547,   139,    16,   198,    21,   237,   171,   170,   178,
     239,   -19,  -547,  -547,  -547,    54,  3160,  3160,  -547,   211,
     224,   228,  -547,    66,  -547,  -547,  3160,  3160,  3160,  -547,
     883,  -547,  -547,  -547,  -547,  -547,  -547,   989,   199,  -547,
     205,   251,   190,   739,  -547,   739,  3724,  3724,  3588,  3588,
     739,  -547,  -547,  3024,  -547,   236,  -547,  -547,  -547,  -547,
    -547,  -547,  -547,   250,  -547,   274,  3588,   472,  -547,  -547,
     209,  3724,   118,  3724,   267,  -547,  -547,   286,  3588,  3286,
    3588,   289,  -547,  3588,  3588,  3588,  3588,  3588,  3588,  3588,
    3588,  3588,  3588,  3588,  3588,  3588,  3588,  3588,  3588,  3588,
    3588,  3588,  -547,    92,   257,  -547,   -78,  -547,   641,    94,
     109,  -547,  -547,  -547,   292,   388,   395,   295,  2869,  -547,
    -547,  -547,  -547,  -547,   989,  3588,  -547,  -547,   989,   989,
     235,   324,   251,  -547,   288,    27,  -547,   310,   311,   315,
     316,   318,   320,   322,   319,  -547,  -547,    54,  3092,   308,
    -547,   327,   329,  -547,  -547,  -547,  -547,  -547,  -547,  -547,
    -547,  -547,  -547,  -547,  -547,  3588,  -547,  3588,  -547,  1945,
    1979,   137,  -547,   160,  -547,  3353,  -547,   329,  -547,   225,
     112,  -547,  -547,  -547,  -547,   139,   139,    16,    16,   198,
     198,   198,   198,    21,    21,   237,   171,   170,   178,   239,
     231,   331,  -547,  -547,  -547,   257,    92,  -547,  1094,  3378,
    -547,  2560,  2699,  2008,    94,  3160,   342,   343,  2869,   682,
    -547,    60,  -547,  -547,   989,   989,   989,   351,  -547,    50,
    3588,   -22,  -547,   332,  -547,  -547,  -547,  -547,  3690,   346,
     332,   323,  -547,  -547,  -547,  -547,  3588,  -547,  -547,  1945,
    -547,    55,   347,   345,  -547,   348,  2287,  -547,   349,   352,
    2083,   160,  2743,  2110,  3261,  -547,  -547,  -547,  3588,  -547,
    -547,  -547,  -547,   330,  3588,   335,   356,  1646,   350,   364,
     361,  2761,   362,   363,   385,  -547,  -547,   -77,  -547,  -547,
    -547,  -547,  1208,  -547,  -547,  -547,  -547,  -547,  3261,  -547,
    -547,  -547,  -547,  3160,  -547,   386,   240,  2287,  -547,   359,
     387,  2185,   379,   103,  2392,  -547,   383,    12,  1685,  -547,
    -547,  3588,  -547,   -67,  -547,   390,   989,  -547,    29,  -547,
    -547,  -547,  -547,   391,   243,  -547,   393,   396,  -547,   213,
     397,  1903,  -547,    86,  -547,  -547,  2936,  -547,   399,  2287,
    -547,  -547,  3588,  -547,   400,  -547,   405,  2287,  -547,   402,
     406,  2212,  3588,   404,  -547,    85,  3378,   -16,  -547,  -547,
    -547,   398,  -547,  1646,   450,  1542,   392,  3588,  -547,   -58,
    3588,  3588,  1646,  -547,  -547,  -547,   108,  -547,  -547,   414,
     409,  2287,  -547,  -547,  3588,  -547,   411,   416,  -547,   -47,
    -547,  -547,   422,   423,    33,  -547,  -547,   103,  -547,  3588,
    -547,  3588,  -547,  3690,  3588,   401,   259,   428,  1903,  -547,
    -547,  -547,   420,   421,  -547,  -547,   427,  2287,  -547,  -547,
    3588,  -547,   429,   430,  -547,  3169,  -547,  -547,  -547,  -547,
    1646,  -547,   433,  2830,  2830,  -547,   252,  -547,   254,   264,
    -547,  3194,  -547,  -547,  -547,   442,   443,  -547,  -547,  -547,
    3160,   -50,  -547,  3160,   272,  -547,   447,   447,   448,  3160,
      36,  -547,  -547,    23,  -547,  -547,  -547,  -547,  -547,  -547,
    -547,  -547,  -547,    92,  -547,  -547,  -547,   444,   445,  -547,
    -547,  -547,  -547,  3378,  -547,  3588,  3445,  3470,  1646,  1646,
    1646,  -547,  -547,  -547,   455,  -547,  -547,   457,   453,   423,
    -547,  -547,  1861,   460,  -547,  -547,  -547,  -547,  -547,  -547,
    -547,   277,  1646,   279,  1646,   287,   543,  -547,  -547,   467,
     461,    33,  -547,   473,  -547,  2434,   467,   446,  -547,  1646,
    -547,  1646,  1646,  -547,   512,    92,    49,   449,  -547,   513,
    -547,  -547,  -547,  -547,   471,  -547,  -547,  2476,   474,   -31,
    -547,  2518,   516,  2980,  -547,  -547,  1322,   451,  1752,   -20,
    -547,  -547,  -547,  2611,  2655,  1436,  -547,  -547
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   165,   163,   164,     0,   116,   119,   201,   124,     0,
     113,   123,   121,   122,   117,   120,   125,     0,   114,   169,
     112,   170,   126,   118,   203,   127,   128,   129,   205,   202,
       0,     0,   204,     0,   206,     0,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,     7,     8,     9,     2,    11,    12,     0,    41,    42,
      43,    44,    45,    46,    18,     3,     4,     6,    34,    47,
       0,    49,    53,    56,    59,    64,    67,    69,    71,    73,
      75,    77,    94,   339,   315,     0,    99,   101,   316,     0,
       0,     0,   131,     0,   132,   130,   103,   105,   107,    97,
       0,   311,   314,   313,   322,   323,   321,     0,     0,   330,
     195,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,    35,    36,   325,   329,     0,   344,   333,   345,   343,
     334,   335,   336,   331,   338,     0,    25,    47,    79,    92,
       0,   183,   242,   185,     0,    28,    29,     0,    23,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   211,     0,   228,    95,     0,   108,   111,   210,
       0,   133,    98,   100,     0,     0,     0,   168,     0,   102,
     104,   106,     1,   312,   348,     0,   347,   340,     0,     0,
       0,     0,     0,    10,   199,     0,   196,     0,     0,     0,
       0,     0,     0,     0,     0,   324,   319,     0,   327,     0,
     332,     0,    24,    32,    85,    86,    82,    83,    84,    87,
      88,    89,    90,    91,    81,     0,     5,     0,   182,     0,
       0,   244,   241,   245,   184,     0,    27,    22,    20,     0,
       0,    26,    50,    51,    52,    54,    55,    57,    58,    63,
      62,    60,    61,    65,    66,    68,    70,    72,    74,    76,
       0,     0,   204,   229,   227,   226,     0,    96,     0,     0,
     318,     0,     0,     0,   209,     0,     0,     0,     0,     0,
     177,     0,   181,   346,   349,   351,     0,     0,   342,     0,
       0,     0,   191,    39,   208,   207,    40,   200,     0,     0,
       0,   111,   326,   320,   328,   337,     0,    80,    93,     0,
     263,   238,     0,   232,   233,     0,     0,   247,    42,     0,
       0,   243,     0,     0,     0,    48,    21,    19,     0,   212,
     230,   225,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,   289,   295,     0,   293,   294,
     280,   281,     0,   291,   282,   283,   284,   285,     0,   269,
     110,   317,   239,     0,   223,     0,     0,     0,   213,    42,
       0,     0,   160,     0,     0,   174,     0,     0,     0,   166,
     178,     0,   179,     0,   186,   190,   350,   341,     0,   193,
     198,   192,   197,     0,     0,    14,     0,     0,    33,   160,
       0,     0,   236,   244,   237,   264,     0,   246,     0,     0,
     248,   254,     0,   253,     0,   265,     0,     0,   255,    42,
       0,     0,     0,     0,   271,     0,     0,     0,   275,    78,
     308,     0,   307,     0,     0,     0,     0,     0,   309,     0,
       0,     0,     0,   296,   290,   292,     0,   222,   224,     0,
       0,     0,   214,   221,     0,   220,    42,     0,   161,     0,
     134,   175,     0,     0,     0,   167,   188,     0,   180,     0,
     194,     0,    13,     0,     0,     0,   228,     0,     0,   231,
     234,   250,     0,     0,   252,   266,     0,     0,   256,   262,
       0,   261,     0,     0,   278,     0,    30,   270,   274,   276,
       0,   288,     0,     0,     0,   306,     0,   310,     0,     0,
     286,     0,   267,   240,   216,     0,     0,   217,   219,   176,
       0,     0,   146,     0,     0,   171,     0,     0,     0,     0,
       0,   138,   140,   141,   150,   156,   157,   187,   189,    17,
      15,    16,   279,     0,   249,   251,   258,     0,     0,   259,
     277,    31,   273,     0,   287,     0,     0,     0,     0,     0,
       0,   268,   215,   218,     0,   135,   147,     0,     0,     0,
     158,   159,     0,     0,   136,   139,   151,   235,   257,   260,
     272,     0,     0,     0,     0,     0,   298,   299,   300,     0,
       0,     0,   172,     0,   142,     0,     0,     0,   304,     0,
     302,     0,     0,   162,     0,     0,     0,     0,   145,     0,
     301,   305,   303,   297,     0,   173,   137,     0,     0,     0,
     143,     0,     0,     0,   148,   144,     0,     0,     0,     0,
     152,   153,   149,   101,   103,     0,   154,   155
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -547,  -547,  -547,  -547,  -547,  -547,  -547,    93,  -547,   216,
     317,  -547,   -35,   238,   242,   180,   245,   412,   413,   415,
     410,   417,  -547,   260,   384,  -547,   -44,   -11,  -106,     0,
    -547,   305,  -547,   -42,  -547,   -17,  -506,  -547,  -547,    51,
    -547,    43,  -547,  -547,  -307,   -18,  -547,  -547,  -547,  -547,
    -547,   -43,    10,  -546,  -362,   304,  -275,  -138,   212,   122,
    -547,   403,  -269,  -547,   -53,  -547,  -547,   -84,  -172,   -60,
    -189,  -280,  -547,   184,  -547,   -97,  -121,  -230,  -272,   241,
    -451,  -547,   166,  -164,  -341,  -547,  -147,  -547,  -352,  -365,
    -547,  -547,  -547,   -82,   -91,  -547,   432,  -547,  -547,  -547,
    -547,  -547,   407,  -547,  -547,  -547,   408
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    64,    65,   204,    66,    67,   404,   405,    68,   222,
     137,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,   138,   139,   235,   357,    83,    84,   382,
     176,   177,    86,    87,    88,   540,   541,   542,   531,   532,
     543,   544,   545,   546,   383,   614,    89,    90,    91,    92,
      93,   534,   535,   384,   385,   289,   290,   142,   393,   394,
      94,   205,   206,    95,    96,    97,    98,   271,   179,   180,
     275,   322,   323,   324,   376,   144,   325,   243,   434,   435,
     436,   437,   438,    99,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   100,   101,   102,   218,   103,   104,   105,
     106,   107,   198,   199,   108,   200,   201
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,   178,   375,   238,   143,   244,   444,   370,   284,   193,
     455,   331,   410,   140,   390,   141,   207,   216,   209,   210,
     211,   242,   471,   214,   292,   194,   633,   276,   237,   536,
     537,   280,   402,   129,   585,   152,   605,   645,   477,   536,
     537,   538,   536,   537,   538,   124,   170,   237,   277,   453,
     291,   330,   426,   530,   563,   536,   537,   538,   477,   478,
     143,   575,   143,   143,   143,   125,   410,   143,   517,   140,
     563,   141,   216,   141,   141,   141,   140,   203,   141,   529,
     514,   631,   241,   160,   161,   579,   182,   183,   143,   401,
     143,   432,   109,   433,   381,   634,   189,   190,   191,   141,
      85,   141,   511,   193,   208,   171,   250,    85,   213,   508,
     585,   520,   313,   390,   274,   473,   294,   295,   252,   253,
     254,   273,   474,   217,   292,   292,   539,   270,   203,   402,
     156,   157,   301,   311,   371,   143,   539,   419,   302,   539,
     480,   162,   163,   115,   431,   110,   141,   584,   566,   567,
     291,   291,   539,   172,   172,   398,   111,   173,   411,   172,
     626,   399,   240,   173,   507,   187,   391,   174,   174,   564,
     134,   116,   358,   174,   135,   313,   188,   117,   217,   241,
     175,   410,   118,   331,   293,   172,   392,   273,   461,   411,
     505,   172,   311,   240,    85,   173,   506,   282,    85,    85,
     414,   283,   172,   193,   193,   174,   173,   395,   172,   391,
     335,   406,   173,   521,   396,   341,   174,   237,   217,   522,
     337,   239,   340,   574,   292,   240,   577,   596,   597,   598,
     273,   174,   583,   562,   119,   143,   143,   412,   497,   321,
     239,   284,   123,   471,   240,   126,   141,   141,   127,   562,
     291,   608,   153,   610,   128,   143,   358,   154,   155,   241,
      82,   413,   130,   332,   158,   159,   141,   333,   621,   471,
     622,   623,   131,   273,     7,   132,     7,   340,   217,   133,
     273,   217,   321,   166,   641,   195,   196,   197,   414,   400,
     136,   590,   167,   647,    85,    85,    85,   164,   165,   395,
      24,   168,    24,   169,    82,   193,    29,   449,    29,   272,
     184,   272,   172,   236,   237,   202,   411,    69,  -238,   409,
     240,   195,   196,   185,   273,   412,   486,   186,   340,   336,
     316,   577,   321,   441,   114,   143,   237,   338,   219,   513,
     259,   260,   261,   262,   458,   459,   141,   482,   483,   413,
     203,   413,   220,   637,   121,   122,   568,   237,   569,   237,
      82,    69,   217,  -161,   247,   249,   340,    82,   570,   237,
     174,   245,   174,   221,   273,    82,   578,   579,   340,    82,
     476,   607,   237,   609,   237,   246,   406,    69,   251,   580,
     581,   611,   237,   395,   255,   256,    85,   286,   145,   146,
     257,   258,   285,   516,   287,   288,   518,   519,   340,   263,
     264,   321,   298,   300,   303,   304,   321,    69,   147,   305,
     306,   503,   307,   310,    69,   308,   274,   309,   413,   314,
     143,   315,    69,   273,   316,   339,    69,   386,   387,   397,
     148,   141,   334,   149,   340,   217,   407,   150,   279,   151,
     416,   415,   417,   445,    82,    82,   440,   420,    82,    82,
     421,   442,   443,   446,   447,   450,   451,   462,   548,   587,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,   409,   640,
     457,   452,   468,   472,   512,   463,   479,   481,   646,   484,
     485,   487,   212,   504,   510,   238,   244,   491,   494,   495,
     498,    69,    69,   523,   499,    69,    69,   524,   515,   527,
     223,   591,   593,   595,   528,   530,   533,   552,   554,   555,
     358,   625,   223,   223,   553,   556,   565,   559,   560,   358,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     572,   573,   588,   589,    82,    82,    82,   278,   582,   599,
      82,   600,    69,   601,   606,   612,   613,   615,   617,   624,
     628,   629,   620,   636,   632,   627,   550,   642,   265,   268,
     266,   342,   576,   267,   616,   644,   586,   269,   619,   602,
     644,   644,   388,   639,   140,   469,   643,   234,   439,   547,
     490,   643,   643,   509,    82,   299,     0,   296,   297,   456,
     281,    69,    69,    69,     0,     0,     0,    69,     0,   317,
       0,   318,     0,     0,   329,     0,     0,     0,     0,     0,
       0,     0,     0,   321,     0,     0,   217,     0,     0,     0,
       0,     0,     0,   183,   189,   217,     0,     0,     0,     0,
       0,    82,     0,     0,     5,    69,    82,     6,     7,     0,
       0,    69,     8,   369,     9,    10,    11,   380,     0,     0,
      12,    13,    14,     0,    15,    16,     0,    18,    19,     0,
      20,    21,    22,    23,    24,     0,    25,    26,    27,    28,
      29,    30,    82,    32,     0,    34,    35,    36,     6,     7,
     408,     0,     0,     8,     0,     9,     0,    11,    69,     0,
     418,    12,    13,    69,   424,    15,    16,   430,   369,    19,
       0,     0,    21,    22,    23,    24,     0,    25,    26,    27,
       0,    29,     0,     0,    32,     0,   181,    35,     0,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,   278,   369,     0,     0,     6,     7,     0,     0,     0,
       8,   460,     9,     0,    11,   467,   279,     0,    12,    13,
       0,     0,    15,    16,    17,     0,    19,   181,     0,    21,
      22,    23,    24,     0,    25,    26,    27,     0,    29,     0,
      31,    32,    33,   389,     0,     0,    69,    37,    38,     0,
       0,     0,     0,   492,     0,     0,   493,     0,     0,     0,
       0,   496,     0,     0,     0,   502,     0,     0,     0,     0,
     369,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    51,    52,    53,    54,    55,
      56,     0,    57,     0,     0,   525,     0,     0,   526,     0,
       0,    58,    59,    60,    61,    62,    63,     0,     0,     0,
       0,     0,     0,     0,     0,   549,     0,     0,   551,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   557,     0,   192,   558,     0,     1,     2,     3,   369,
       0,     0,     0,     0,     0,     4,     5,     0,     0,     6,
       7,     0,     0,     0,     8,   369,     9,    10,    11,     0,
       0,     0,    12,    13,    14,     0,    15,    16,    17,    18,
      19,     0,    20,    21,    22,    23,    24,     0,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       0,    37,    38,     0,     0,     0,     0,   369,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    40,    41,    42,    43,    44,     0,
       0,     0,    45,    46,    47,    48,    49,     0,    50,    51,
      52,    53,    54,    55,    56,     0,    57,     0,     0,     0,
       0,     0,     1,     2,     3,    58,    59,    60,    61,    62,
      63,     4,     5,     0,     0,     6,     7,     0,     0,     0,
       8,     0,     9,    10,    11,     0,     0,     0,    12,    13,
      14,     0,    15,    16,    17,    18,    19,     0,    20,    21,
      22,    23,    24,     0,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,    37,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
      40,    41,    42,    43,    44,     0,     0,     0,    45,    46,
      47,    48,    49,     0,    50,    51,    52,    53,    54,    55,
      56,     0,    57,     0,     0,     0,     0,     0,     0,     0,
       0,    58,    59,    60,    61,    62,    63,     5,   343,   344,
       6,     7,   345,   346,   347,     8,     0,     9,    10,    11,
     348,   349,   350,    12,    13,    14,   351,    15,    16,    17,
      18,    19,   352,    20,    21,    22,    23,    24,   353,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     0,    37,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
      51,    52,    53,   354,    55,    56,     0,    57,     0,     0,
       0,     0,     0,     0,   278,   355,    58,    59,    60,    61,
      62,    63,     0,     0,     0,     0,     0,     0,     0,     0,
     356,     5,   343,   344,     6,     7,   345,   346,   347,     8,
       0,     9,    10,    11,   348,   349,   350,    12,    13,    14,
     351,    15,    16,    17,    18,    19,   352,    20,    21,    22,
      23,    24,   353,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     0,    37,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,   354,    55,    56,
       0,    57,     0,     0,     0,     0,     0,     0,   278,   454,
      58,    59,    60,    61,    62,    63,     0,     0,     0,     0,
       0,     0,     0,     0,   356,     5,   343,   344,     6,     7,
     345,   346,   347,     8,     0,     9,    10,    11,   348,   349,
     350,    12,    13,    14,   351,    15,    16,    17,    18,    19,
     352,    20,    21,    22,    23,    24,   353,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     0,
      37,    38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    51,    52,
      53,   354,    55,    56,     0,   638,     0,     0,     0,     0,
       0,     0,   278,     0,    58,    59,    60,    61,    62,    63,
       0,     0,     0,     0,     0,     0,     0,     0,   356,     5,
     343,   344,     6,     7,   345,   346,   347,     8,     0,     9,
      10,    11,   348,   349,   350,    12,    13,    14,   351,    15,
      16,    17,    18,    19,   352,    20,    21,    22,    23,    24,
     353,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    51,    52,    53,   354,    55,    56,     0,    57,
       0,     0,     0,     0,     0,     0,   278,     0,    58,    59,
      60,    61,    62,    63,     0,     5,     0,     0,     6,     7,
       0,     0,   356,     8,     0,     9,    10,    11,     0,     0,
       0,    12,    13,    14,     0,    15,    16,    17,    18,    19,
       0,    20,    21,    22,    23,    24,     0,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     0,
      37,    38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    51,    52,
      53,    54,    55,    56,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,    63,
     343,   344,     0,     0,   345,   346,   347,     0,   356,     0,
       0,     0,   348,   349,   350,     0,     0,     0,   351,     0,
       0,    17,     0,     0,   352,     0,     0,     0,     0,     0,
     353,     0,     0,     0,     0,     0,     0,    31,     0,    33,
       0,     6,     7,     0,    37,    38,     8,     0,     9,     0,
      11,     0,     0,     0,    12,    13,     0,     0,    15,    16,
       0,     0,    19,     0,     0,    21,    22,    23,    24,     0,
      25,    26,    27,     0,    29,     0,     0,    32,     0,     0,
      35,   112,    51,    52,    53,   354,    55,    56,     0,    57,
       0,     0,     0,     0,     0,     0,   278,     0,    58,    59,
      60,    61,    62,    63,     0,     5,     0,     0,     6,     7,
       0,     0,   356,     8,     0,     9,    10,    11,     0,     0,
     181,    12,    13,    14,     0,    15,    16,    17,    18,    19,
       0,    20,    21,    22,    23,    24,   475,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,    36,     0,
      37,    38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    51,    52,
      53,    54,    55,    56,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,    63,
     603,     0,     0,     0,     5,     0,     0,     6,     7,     0,
       0,     0,     8,     0,     9,    10,    11,     0,     0,     0,
      12,    13,    14,     0,    15,    16,     0,    18,    19,     0,
      20,    21,    22,    23,    24,     0,    25,    26,    27,    28,
      29,    30,     0,    32,     0,    34,     5,    36,     0,     6,
       7,     0,     0,     0,     8,     0,     9,    10,    11,     0,
       0,     0,    12,    13,    14,     0,    15,    16,     0,    18,
      19,     0,    20,    21,    22,    23,    24,     0,    25,    26,
      27,    28,    29,    30,     0,    32,   181,    34,     5,    36,
       0,     6,     7,     0,     0,     0,     8,     0,     9,    10,
      11,     0,   604,     0,    12,    13,    14,     0,    15,    16,
       0,    18,    19,     0,    20,    21,    22,    23,    24,     0,
      25,    26,    27,    28,    29,    30,     7,    32,   181,    34,
       0,    36,   172,     0,     0,     0,   488,   320,     0,     0,
     240,     0,     0,     0,    17,   326,   174,     0,     0,     0,
       0,     0,    24,     0,     0,     7,     0,     0,    29,     0,
      31,   272,    33,     0,     0,     0,     0,    37,    38,     0,
     181,     0,     0,    17,   377,     0,     0,     0,   319,   320,
       0,    24,   240,     0,     0,     0,     0,    29,   174,    31,
     272,    33,     0,     0,     0,     0,    37,    38,     0,     0,
       0,     0,     0,     0,   112,    51,    52,    53,    54,    55,
      56,     0,    57,     0,     0,     0,     0,   327,     0,     0,
       0,    58,   328,    60,    61,    62,    63,     0,     0,     0,
       7,     0,     0,   112,    51,    52,    53,    54,    55,    56,
       0,    57,     0,     0,     0,     0,   378,     0,    17,   422,
      58,   379,    60,    61,    62,    63,    24,     7,     0,     0,
       0,     0,    29,     0,    31,   272,    33,     0,     0,     0,
       0,    37,    38,     0,     0,    17,   427,     0,     0,     0,
       0,     0,     0,    24,     0,     0,     0,     0,     0,    29,
       0,    31,   272,    33,     0,     0,     0,     0,    37,    38,
       0,     0,     0,     0,     0,     0,     0,     0,   112,    51,
      52,    53,    54,    55,    56,     0,    57,     0,     0,     0,
       0,   423,     0,     0,     0,    58,    59,    60,    61,    62,
      63,     0,     7,     0,     0,   112,    51,    52,    53,    54,
      55,    56,     0,    57,     0,     0,     0,     0,   428,     0,
      17,   464,    58,   429,    60,    61,    62,    63,    24,     7,
       0,     0,     0,     0,    29,     0,    31,   272,    33,     0,
       0,     0,     0,    37,    38,     0,     0,    17,   500,     0,
       0,     0,     0,     0,     0,    24,     0,     0,     0,     0,
       0,    29,     0,    31,   272,    33,     0,     0,     0,     0,
      37,    38,     0,     0,     0,     0,     0,     0,     0,     0,
     112,    51,    52,    53,    54,    55,    56,     0,    57,     0,
       0,     0,     0,   465,     0,     0,     0,    58,   466,    60,
      61,    62,    63,     0,     7,     0,     0,   112,    51,    52,
      53,    54,    55,    56,     0,    57,     0,     0,     0,     0,
     501,     0,    17,     0,    58,    59,    60,    61,    62,    63,
      24,     0,     0,     0,     0,     0,    29,     0,    31,   272,
      33,     0,     0,     0,     0,    37,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,    51,    52,    53,    54,    55,    56,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,    62,    63,     5,     0,     0,     6,     7,
       0,     0,     0,     8,     0,     9,    10,    11,     0,     0,
       0,    12,    13,    14,     0,    15,    16,     0,    18,    19,
       0,    20,    21,    22,    23,    24,     0,    25,    26,    27,
      28,    29,    30,     0,    32,     0,    34,     5,    36,     0,
       6,     7,     0,     0,     0,     8,     0,     9,    10,    11,
       0,     0,     0,    12,    13,    14,     0,    15,    16,     0,
      18,    19,     0,    20,    21,    22,    23,    24,     0,    25,
      26,    27,    28,    29,    30,     0,    32,   181,    34,     5,
      36,     0,     6,     7,     0,     0,     0,     8,     0,     9,
      10,    11,     0,   470,     0,    12,    13,    14,     0,    15,
      16,     0,    18,    19,     0,    20,    21,    22,    23,    24,
       0,    25,    26,    27,    28,    29,    30,     0,    32,   181,
      34,     5,    36,     0,     6,     7,     0,     0,     0,     8,
       0,     9,    10,    11,     0,   618,     0,    12,    13,    14,
       0,    15,    16,     0,    18,    19,     0,    20,    21,    22,
      23,    24,     0,    25,    26,    27,    28,    29,    30,     0,
      32,   181,    34,     5,    36,     0,     6,     7,     0,     0,
       0,     8,     0,     9,    10,    11,     0,   630,     0,    12,
      13,    14,     0,    15,    16,     0,    18,    19,     0,    20,
      21,    22,    23,    24,     0,    25,    26,    27,    28,    29,
      30,     0,    32,   181,    34,    35,    36,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     0,     6,     7,   635,
       0,     0,     8,     0,     9,    10,    11,     0,     0,     0,
      12,    13,    14,     0,    15,    16,     0,    18,    19,     0,
      20,    21,    22,    23,    24,   181,    25,    26,    27,    28,
      29,    30,     0,    32,     0,    34,     0,    36,     5,     0,
     278,     6,     7,     0,     0,     0,     8,     0,     9,    10,
      11,     0,     0,     0,    12,    13,    14,     0,    15,    16,
       0,    18,    19,     0,    20,    21,    22,    23,    24,     0,
      25,    26,    27,    28,    29,    30,   181,    32,     0,    34,
       0,    36,     5,     0,  -183,     6,     7,     0,  -183,     0,
       8,     0,     9,    10,    11,     0,     0,     0,    12,    13,
      14,     0,    15,    16,     0,    18,    19,     0,    20,    21,
      22,    23,    24,     0,    25,    26,    27,    28,    29,    30,
     181,    32,     0,    34,     0,    36,     5,     0,  -185,     6,
       7,     0,  -185,     0,     8,     0,     9,    10,    11,     0,
       0,     0,    12,    13,    14,     0,    15,    16,     0,    18,
      19,     0,    20,    21,    22,    23,    24,     0,    25,    26,
      27,    28,    29,    30,   181,    32,    17,    34,   372,    36,
       0,     0,   373,   374,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,    33,     0,     0,     0,     0,    37,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   181,     0,
       0,     0,     0,     0,     0,     0,   373,   425,     0,     0,
       0,     0,     0,     0,     0,     0,   112,    51,    52,    53,
      54,    55,    56,     0,    57,    17,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,    61,    62,    63,     0,
       0,    31,     0,    33,     0,     6,     7,   448,    37,    38,
       8,     0,     9,     0,    11,     0,     0,     0,    12,    13,
       0,     0,    15,    16,     0,     0,    19,     0,     0,    21,
      22,    23,    24,     0,    25,    26,    27,     0,    29,     0,
       0,    32,     0,     0,    35,   112,    51,    52,    53,    54,
      55,    56,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,    63,     0,     5,
       0,     0,     6,     7,     0,     0,   356,     8,     0,     9,
      10,    11,     0,     0,   181,    12,    13,    14,     0,    15,
      16,     0,    18,    19,     0,    20,    21,    22,    23,    24,
       0,    25,    26,    27,    28,    29,    30,     0,    32,     0,
      34,     0,    36,     5,     0,     0,     6,     7,     0,     0,
       0,     8,     0,     9,    10,    11,     0,     0,     0,    12,
      13,    14,     0,    15,    16,   489,    18,    19,     0,    20,
      21,    22,    23,    24,     0,    25,    26,    27,    28,    29,
      30,   181,    32,     0,    34,     0,    36,     5,     0,   373,
       6,     7,     0,     0,     0,     8,     0,     9,    10,    11,
       0,     0,     0,    12,    13,    14,     0,    15,    16,     0,
      18,    19,     0,    20,    21,    22,    23,    24,     0,    25,
      26,    27,    28,    29,    30,   181,    32,     0,    34,    35,
      36,     0,     0,   373,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     6,     7,
       0,     0,     0,     8,     0,     9,    10,    11,     0,   181,
       0,    12,    13,    14,   215,    15,    16,     0,    18,    19,
       0,    20,    21,    22,    23,    24,     0,    25,    26,    27,
      28,    29,    30,     0,    32,     0,    34,    35,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     6,     7,     0,     0,
       0,     8,     0,     9,    10,    11,     0,   181,     0,    12,
      13,    14,   312,    15,    16,     0,    18,    19,     0,    20,
      21,    22,    23,    24,    17,    25,    26,    27,    28,    29,
      30,     0,    32,     0,    34,     0,    36,     0,     0,     0,
      31,     0,    33,     0,     0,     0,     0,    37,    38,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    31,     0,    33,     0,     0,
       0,     0,    37,    38,     0,   181,     0,     0,     0,     0,
       0,     0,     0,     0,   112,    51,    52,    53,    54,    55,
      56,     0,    57,     0,     0,     0,   432,     0,   433,   368,
     561,    58,    59,    60,    61,    62,    63,     0,     0,   112,
      51,    52,    53,    54,    55,    56,    17,    57,     0,     0,
       0,   432,     0,   433,   368,   571,    58,    59,    60,    61,
      62,    63,    31,     0,    33,     0,     0,     0,     0,    37,
      38,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,    33,
       0,     0,     0,     0,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   112,    51,    52,    53,
      54,    55,    56,     0,    57,     0,     0,     0,   432,     0,
     433,   368,     0,    58,    59,    60,    61,    62,    63,     0,
       0,   112,    51,    52,    53,    54,    55,    56,    17,    57,
     248,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,    62,    63,    31,     0,    33,     0,     0,     0,
       0,    37,    38,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
       0,    33,     0,     0,     0,     0,    37,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,    51,
      52,    53,    54,    55,    56,     0,    57,     0,     0,     0,
       0,     0,     0,   334,     0,    58,    59,    60,    61,    62,
      63,     0,     0,   112,    51,    52,    53,    54,    55,    56,
      17,    57,     0,     0,     0,     0,     0,     0,   368,     0,
      58,    59,    60,    61,    62,    63,    31,     0,    33,     0,
       0,     0,     0,    37,    38,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,     0,    33,     0,     0,     0,     0,    37,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,    51,    52,    53,    54,    55,    56,     0,    57,   592,
       0,     0,     0,     0,     0,     0,     0,    58,    59,    60,
      61,    62,    63,     0,     0,   112,    51,    52,    53,    54,
      55,    56,    17,    57,   594,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,    63,    31,     0,
      33,     0,     0,     0,     0,    37,    38,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,     0,    33,     0,     0,     0,     0,
      37,    38,     0,    17,     0,     0,     0,     0,     0,     0,
       0,     0,   112,    51,    52,    53,    54,    55,    56,    31,
     113,    33,     0,     0,     0,     0,    37,    38,     0,    58,
      59,    60,    61,    62,    63,     0,     0,   112,    51,    52,
      53,    54,    55,    56,     0,   120,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,    63,
       0,     0,     0,   112,    51,    52,    53,    54,    55,    56,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
      58,    59,    60,    61,    62,    63,     6,     7,     0,   403,
       0,     8,     0,     9,     0,    11,     0,     0,     0,    12,
      13,     0,     0,    15,    16,     0,     0,    19,     0,     0,
      21,    22,    23,    24,     0,    25,    26,    27,     0,    29,
       6,     7,    32,     0,     0,     8,     0,     9,     0,    11,
       0,     0,     0,    12,    13,     0,     0,    15,    16,     0,
       0,    19,     0,     0,    21,    22,    23,    24,     0,    25,
      26,    27,     0,    29,     0,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181
};

static const yytype_int16 yycheck[] =
{
       0,    85,   282,   141,    57,   143,   347,   279,   180,   100,
     362,   241,   319,    57,   289,    57,   113,   123,   115,   116,
     117,   142,   384,   120,   188,   107,    57,   105,   105,     6,
       7,   178,   301,    44,   540,    70,   582,    57,   105,     6,
       7,     8,     6,     7,     8,   100,    65,   105,   126,   126,
     188,   240,   332,   103,   505,     6,     7,     8,   105,   126,
     113,   111,   115,   116,   117,   120,   373,   120,   126,   113,
     521,   113,   178,   115,   116,   117,   120,    99,   120,   126,
     445,   627,   142,    62,    63,   105,    86,    87,   141,   111,
     143,   107,   100,   109,   283,   126,    96,    97,    98,   141,
     100,   143,   443,   194,   115,   124,   150,   107,   119,   125,
     616,   452,   218,   388,   174,   103,   198,   199,   153,   154,
     155,   174,   110,   123,   288,   289,   103,   171,    99,   398,
     114,   115,   105,   217,   281,   188,   103,   326,   111,   103,
     111,   120,   121,   103,   333,    99,   188,   111,   513,   514,
     288,   289,   103,    99,    99,   105,   110,   103,   103,    99,
     111,   111,   107,   103,   436,    99,   106,   113,   113,   510,
      99,   103,   278,   113,   103,   281,   110,   103,   178,   239,
     126,   488,   103,   413,   195,    99,   126,   240,   377,   103,
     105,    99,   276,   107,   194,   103,   111,   103,   198,   199,
     321,   107,    99,   294,   295,   113,   103,   291,    99,   106,
     245,   308,   103,   105,   296,   275,   113,   105,   218,   111,
     108,   103,   275,   530,   388,   107,   533,   568,   569,   570,
     283,   113,   539,   505,   103,   288,   289,   321,   427,   239,
     103,   413,    99,   605,   107,    99,   288,   289,    99,   521,
     388,   592,   113,   594,    99,   308,   362,   118,   119,   319,
       0,   321,   100,   103,    66,    67,   308,   107,   609,   631,
     611,   612,   100,   326,    17,   100,    17,   330,   278,    96,
     333,   281,   282,   112,   636,    86,    87,    88,   409,   300,
     100,   563,   122,   645,   294,   295,   296,    60,    61,   383,
      43,   123,    43,    64,    44,   396,    49,   351,    49,    52,
      99,    52,    99,   104,   105,   110,   103,     0,   105,   319,
     107,    86,    87,    99,   377,   409,   113,    99,   381,   104,
     105,   638,   332,   344,    17,   388,   105,   106,   102,   445,
     160,   161,   162,   163,   104,   105,   388,   104,   105,   409,
      99,   411,   102,   633,    37,    38,   104,   105,   104,   105,
     100,    44,   362,   104,   148,   149,   419,   107,   104,   105,
     113,   104,   113,    99,   427,   115,   104,   105,   431,   119,
     391,   104,   105,   104,   105,    99,   483,    70,    99,   536,
     537,   104,   105,   477,   156,   157,   396,     9,    58,    59,
     158,   159,   110,   447,     9,   110,   450,   451,   461,   164,
     165,   411,    88,   125,   104,   104,   416,   100,    78,   104,
     104,   432,   104,   104,   107,   105,   486,   105,   488,   121,
     483,   104,   115,   486,   105,   104,   119,    95,    95,    88,
     100,   483,   110,   103,   497,   445,   100,   107,   125,   109,
     105,   104,   104,   103,   194,   195,   126,   108,   198,   199,
     108,   126,   106,    99,   103,   103,   103,   108,   479,   553,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   488,   636,
     104,   106,   113,   110,    44,   108,   106,   106,   645,   106,
     104,   104,   118,    99,   106,   643,   644,   108,   108,   104,
     108,   194,   195,    99,   108,   198,   199,   108,   126,   108,
     136,   565,   566,   567,   108,   103,   103,   126,   108,   108,
     636,   615,   148,   149,   106,   108,   103,   108,   108,   645,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
     108,   108,   108,   108,   294,   295,   296,   110,   110,   104,
     300,   104,   245,   110,   104,    22,    99,   106,    95,    57,
      57,   100,   126,    57,   100,   126,   483,   126,   166,   169,
     167,   276,   531,   168,   601,   638,   543,   170,   606,   579,
     643,   644,   288,   636,   638,   383,   638,   125,   338,   477,
     416,   643,   644,   437,   344,   202,    -1,   200,   200,   368,
     178,   294,   295,   296,    -1,    -1,    -1,   300,    -1,   235,
      -1,   237,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   633,    -1,    -1,   636,    -1,    -1,    -1,
      -1,    -1,    -1,   643,   644,   645,    -1,    -1,    -1,    -1,
      -1,   391,    -1,    -1,    13,   338,   396,    16,    17,    -1,
      -1,   344,    21,   279,    23,    24,    25,   283,    -1,    -1,
      29,    30,    31,    -1,    33,    34,    -1,    36,    37,    -1,
      39,    40,    41,    42,    43,    -1,    45,    46,    47,    48,
      49,    50,   432,    52,    -1,    54,    55,    56,    16,    17,
     316,    -1,    -1,    21,    -1,    23,    -1,    25,   391,    -1,
     326,    29,    30,   396,   330,    33,    34,   333,   334,    37,
      -1,    -1,    40,    41,    42,    43,    -1,    45,    46,    47,
      -1,    49,    -1,    -1,    52,    -1,    95,    55,    -1,   479,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   432,
      -1,   110,   368,    -1,    -1,    16,    17,    -1,    -1,    -1,
      21,   377,    23,    -1,    25,   381,   125,    -1,    29,    30,
      -1,    -1,    33,    34,    35,    -1,    37,    95,    -1,    40,
      41,    42,    43,    -1,    45,    46,    47,    -1,    49,    -1,
      51,    52,    53,   111,    -1,    -1,   479,    58,    59,    -1,
      -1,    -1,    -1,   419,    -1,    -1,   422,    -1,    -1,    -1,
      -1,   427,    -1,    -1,    -1,   431,    -1,    -1,    -1,    -1,
     436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
     101,    -1,   103,    -1,    -1,   461,    -1,    -1,   464,    -1,
      -1,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   481,    -1,    -1,   484,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   497,    -1,     0,   500,    -1,     3,     4,     5,   505,
      -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    16,
      17,    -1,    -1,    -1,    21,   521,    23,    24,    25,    -1,
      -1,    -1,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    -1,    39,    40,    41,    42,    43,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    -1,    -1,    -1,    -1,   563,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    81,    82,    83,    84,    85,    -1,
      -1,    -1,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    99,   100,   101,    -1,   103,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,   112,   113,   114,   115,   116,
     117,    12,    13,    -1,    -1,    16,    17,    -1,    -1,    -1,
      21,    -1,    23,    24,    25,    -1,    -1,    -1,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    -1,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      81,    82,    83,    84,    85,    -1,    -1,    -1,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    99,   100,
     101,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,   101,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,   101,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,   110,    -1,   112,   113,   114,   115,   116,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,   101,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,   112,   113,
     114,   115,   116,   117,    -1,    13,    -1,    -1,    16,    17,
      -1,    -1,   126,    21,    -1,    23,    24,    25,    -1,    -1,
      -1,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      -1,    39,    40,    41,    42,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
      14,    15,    -1,    -1,    18,    19,    20,    -1,   126,    -1,
      -1,    -1,    26,    27,    28,    -1,    -1,    -1,    32,    -1,
      -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,
      -1,    16,    17,    -1,    58,    59,    21,    -1,    23,    -1,
      25,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,    34,
      -1,    -1,    37,    -1,    -1,    40,    41,    42,    43,    -1,
      45,    46,    47,    -1,    49,    -1,    -1,    52,    -1,    -1,
      55,    95,    96,    97,    98,    99,   100,   101,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,   112,   113,
     114,   115,   116,   117,    -1,    13,    -1,    -1,    16,    17,
      -1,    -1,   126,    21,    -1,    23,    24,    25,    -1,    -1,
      95,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      -1,    39,    40,    41,    42,    43,   111,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    -1,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
       9,    -1,    -1,    -1,    13,    -1,    -1,    16,    17,    -1,
      -1,    -1,    21,    -1,    23,    24,    25,    -1,    -1,    -1,
      29,    30,    31,    -1,    33,    34,    -1,    36,    37,    -1,
      39,    40,    41,    42,    43,    -1,    45,    46,    47,    48,
      49,    50,    -1,    52,    -1,    54,    13,    56,    -1,    16,
      17,    -1,    -1,    -1,    21,    -1,    23,    24,    25,    -1,
      -1,    -1,    29,    30,    31,    -1,    33,    34,    -1,    36,
      37,    -1,    39,    40,    41,    42,    43,    -1,    45,    46,
      47,    48,    49,    50,    -1,    52,    95,    54,    13,    56,
      -1,    16,    17,    -1,    -1,    -1,    21,    -1,    23,    24,
      25,    -1,   111,    -1,    29,    30,    31,    -1,    33,    34,
      -1,    36,    37,    -1,    39,    40,    41,    42,    43,    -1,
      45,    46,    47,    48,    49,    50,    17,    52,    95,    54,
      -1,    56,    99,    -1,    -1,    -1,   103,   104,    -1,    -1,
     107,    -1,    -1,    -1,    35,    36,   113,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    17,    -1,    -1,    49,    -1,
      51,    52,    53,    -1,    -1,    -1,    -1,    58,    59,    -1,
      95,    -1,    -1,    35,    36,    -1,    -1,    -1,   103,   104,
      -1,    43,   107,    -1,    -1,    -1,    -1,    49,   113,    51,
      52,    53,    -1,    -1,    -1,    -1,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
     101,    -1,   103,    -1,    -1,    -1,    -1,   108,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
      17,    -1,    -1,    95,    96,    97,    98,    99,   100,   101,
      -1,   103,    -1,    -1,    -1,    -1,   108,    -1,    35,    36,
     112,   113,   114,   115,   116,   117,    43,    17,    -1,    -1,
      -1,    -1,    49,    -1,    51,    52,    53,    -1,    -1,    -1,
      -1,    58,    59,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,   101,    -1,   103,    -1,    -1,    -1,
      -1,   108,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,    -1,    17,    -1,    -1,    95,    96,    97,    98,    99,
     100,   101,    -1,   103,    -1,    -1,    -1,    -1,   108,    -1,
      35,    36,   112,   113,   114,   115,   116,   117,    43,    17,
      -1,    -1,    -1,    -1,    49,    -1,    51,    52,    53,    -1,
      -1,    -1,    -1,    58,    59,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,    -1,
      -1,    -1,    -1,   108,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,    -1,    17,    -1,    -1,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,    -1,    -1,    -1,    -1,
     108,    -1,    35,    -1,   112,   113,   114,   115,   116,   117,
      43,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,
      53,    -1,    -1,    -1,    -1,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,    13,    -1,    -1,    16,    17,
      -1,    -1,    -1,    21,    -1,    23,    24,    25,    -1,    -1,
      -1,    29,    30,    31,    -1,    33,    34,    -1,    36,    37,
      -1,    39,    40,    41,    42,    43,    -1,    45,    46,    47,
      48,    49,    50,    -1,    52,    -1,    54,    13,    56,    -1,
      16,    17,    -1,    -1,    -1,    21,    -1,    23,    24,    25,
      -1,    -1,    -1,    29,    30,    31,    -1,    33,    34,    -1,
      36,    37,    -1,    39,    40,    41,    42,    43,    -1,    45,
      46,    47,    48,    49,    50,    -1,    52,    95,    54,    13,
      56,    -1,    16,    17,    -1,    -1,    -1,    21,    -1,    23,
      24,    25,    -1,   111,    -1,    29,    30,    31,    -1,    33,
      34,    -1,    36,    37,    -1,    39,    40,    41,    42,    43,
      -1,    45,    46,    47,    48,    49,    50,    -1,    52,    95,
      54,    13,    56,    -1,    16,    17,    -1,    -1,    -1,    21,
      -1,    23,    24,    25,    -1,   111,    -1,    29,    30,    31,
      -1,    33,    34,    -1,    36,    37,    -1,    39,    40,    41,
      42,    43,    -1,    45,    46,    47,    48,    49,    50,    -1,
      52,    95,    54,    13,    56,    -1,    16,    17,    -1,    -1,
      -1,    21,    -1,    23,    24,    25,    -1,   111,    -1,    29,
      30,    31,    -1,    33,    34,    -1,    36,    37,    -1,    39,
      40,    41,    42,    43,    -1,    45,    46,    47,    48,    49,
      50,    -1,    52,    95,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    16,    17,   111,
      -1,    -1,    21,    -1,    23,    24,    25,    -1,    -1,    -1,
      29,    30,    31,    -1,    33,    34,    -1,    36,    37,    -1,
      39,    40,    41,    42,    43,    95,    45,    46,    47,    48,
      49,    50,    -1,    52,    -1,    54,    -1,    56,    13,    -1,
     110,    16,    17,    -1,    -1,    -1,    21,    -1,    23,    24,
      25,    -1,    -1,    -1,    29,    30,    31,    -1,    33,    34,
      -1,    36,    37,    -1,    39,    40,    41,    42,    43,    -1,
      45,    46,    47,    48,    49,    50,    95,    52,    -1,    54,
      -1,    56,    13,    -1,   103,    16,    17,    -1,   107,    -1,
      21,    -1,    23,    24,    25,    -1,    -1,    -1,    29,    30,
      31,    -1,    33,    34,    -1,    36,    37,    -1,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    48,    49,    50,
      95,    52,    -1,    54,    -1,    56,    13,    -1,   103,    16,
      17,    -1,   107,    -1,    21,    -1,    23,    24,    25,    -1,
      -1,    -1,    29,    30,    31,    -1,    33,    34,    -1,    36,
      37,    -1,    39,    40,    41,    42,    43,    -1,    45,    46,
      47,    48,    49,    50,    95,    52,    35,    54,    99,    56,
      -1,    -1,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    53,    -1,    -1,    -1,    -1,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,   101,    -1,   103,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,    -1,
      -1,    51,    -1,    53,    -1,    16,    17,   126,    58,    59,
      21,    -1,    23,    -1,    25,    -1,    -1,    -1,    29,    30,
      -1,    -1,    33,    34,    -1,    -1,    37,    -1,    -1,    40,
      41,    42,    43,    -1,    45,    46,    47,    -1,    49,    -1,
      -1,    52,    -1,    -1,    55,    95,    96,    97,    98,    99,
     100,   101,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,    -1,    13,
      -1,    -1,    16,    17,    -1,    -1,   126,    21,    -1,    23,
      24,    25,    -1,    -1,    95,    29,    30,    31,    -1,    33,
      34,    -1,    36,    37,    -1,    39,    40,    41,    42,    43,
      -1,    45,    46,    47,    48,    49,    50,    -1,    52,    -1,
      54,    -1,    56,    13,    -1,    -1,    16,    17,    -1,    -1,
      -1,    21,    -1,    23,    24,    25,    -1,    -1,    -1,    29,
      30,    31,    -1,    33,    34,    79,    36,    37,    -1,    39,
      40,    41,    42,    43,    -1,    45,    46,    47,    48,    49,
      50,    95,    52,    -1,    54,    -1,    56,    13,    -1,   103,
      16,    17,    -1,    -1,    -1,    21,    -1,    23,    24,    25,
      -1,    -1,    -1,    29,    30,    31,    -1,    33,    34,    -1,
      36,    37,    -1,    39,    40,    41,    42,    43,    -1,    45,
      46,    47,    48,    49,    50,    95,    52,    -1,    54,    55,
      56,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    16,    17,
      -1,    -1,    -1,    21,    -1,    23,    24,    25,    -1,    95,
      -1,    29,    30,    31,   100,    33,    34,    -1,    36,    37,
      -1,    39,    40,    41,    42,    43,    -1,    45,    46,    47,
      48,    49,    50,    -1,    52,    -1,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    16,    17,    -1,    -1,
      -1,    21,    -1,    23,    24,    25,    -1,    95,    -1,    29,
      30,    31,   100,    33,    34,    -1,    36,    37,    -1,    39,
      40,    41,    42,    43,    35,    45,    46,    47,    48,    49,
      50,    -1,    52,    -1,    54,    -1,    56,    -1,    -1,    -1,
      51,    -1,    53,    -1,    -1,    -1,    -1,    58,    59,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,
      -1,    -1,    58,    59,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
     101,    -1,   103,    -1,    -1,    -1,   107,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    95,
      96,    97,    98,    99,   100,   101,    35,   103,    -1,    -1,
      -1,   107,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    51,    -1,    53,    -1,    -1,    -1,    -1,    58,
      59,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,
      -1,    -1,    -1,    -1,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,   101,    -1,   103,    -1,    -1,    -1,   107,    -1,
     109,   110,    -1,   112,   113,   114,   115,   116,   117,    -1,
      -1,    95,    96,    97,    98,    99,   100,   101,    35,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,    51,    -1,    53,    -1,    -1,    -1,
      -1,    58,    59,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    53,    -1,    -1,    -1,    -1,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,   101,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,   110,    -1,   112,   113,   114,   115,   116,
     117,    -1,    -1,    95,    96,    97,    98,    99,   100,   101,
      35,   103,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,
     112,   113,   114,   115,   116,   117,    51,    -1,    53,    -1,
      -1,    -1,    -1,    58,    59,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    53,    -1,    -1,    -1,    -1,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,    -1,    -1,    95,    96,    97,    98,    99,
     100,   101,    35,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,    51,    -1,
      53,    -1,    -1,    -1,    -1,    58,    59,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    -1,    -1,
      58,    59,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,   101,    51,
     103,    53,    -1,    -1,    -1,    -1,    58,    59,    -1,   112,
     113,   114,   115,   116,   117,    -1,    -1,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,   101,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,    16,    17,    -1,    19,
      -1,    21,    -1,    23,    -1,    25,    -1,    -1,    -1,    29,
      30,    -1,    -1,    33,    34,    -1,    -1,    37,    -1,    -1,
      40,    41,    42,    43,    -1,    45,    46,    47,    -1,    49,
      16,    17,    52,    -1,    -1,    21,    -1,    23,    -1,    25,
      -1,    -1,    -1,    29,    30,    -1,    -1,    33,    34,    -1,
      -1,    37,    -1,    -1,    40,    41,    42,    43,    -1,    45,
      46,    47,    -1,    49,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    12,    13,    16,    17,    21,    23,
      24,    25,    29,    30,    31,    33,    34,    35,    36,    37,
      39,    40,    41,    42,    43,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    58,    59,    80,
      81,    82,    83,    84,    85,    89,    90,    91,    92,    93,
      95,    96,    97,    98,    99,   100,   101,   103,   112,   113,
     114,   115,   116,   117,   128,   129,   131,   132,   135,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   154,   155,   156,   159,   160,   161,   173,
     174,   175,   176,   177,   187,   190,   191,   192,   193,   210,
     220,   221,   222,   224,   225,   226,   227,   228,   231,   100,
      99,   110,    95,   103,   137,   103,   103,   103,   103,   103,
     103,   137,   137,    99,   100,   120,    99,    99,    99,   154,
     100,   100,   100,    96,    99,   103,   100,   137,   150,   151,
     153,   160,   184,   191,   202,    58,    59,    78,   100,   103,
     107,   109,   139,   113,   118,   119,   114,   115,    66,    67,
      62,    63,   120,   121,    60,    61,   112,   122,   123,    64,
      65,   124,    99,   103,   113,   126,   157,   158,   194,   195,
     196,    95,   156,   156,    99,    99,    99,    99,   110,   156,
     156,   156,     0,   221,   220,    86,    87,    88,   229,   230,
     232,   233,   110,    99,   130,   188,   189,   202,   154,   202,
     202,   202,   151,   154,   202,   100,   155,   156,   223,   102,
     102,    99,   136,   151,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,   125,   152,   104,   105,   184,   103,
     107,   196,   203,   204,   184,   104,    99,   136,   104,   136,
     153,    99,   139,   139,   139,   140,   140,   141,   141,   142,
     142,   142,   142,   143,   143,   144,   145,   146,   147,   148,
     153,   194,    52,   191,   196,   197,   105,   126,   110,   125,
     213,   223,   103,   107,   195,   110,     9,     9,   110,   182,
     183,   184,   210,   154,   220,   220,   229,   233,    88,   188,
     125,   105,   111,   104,   104,   104,   104,   104,   105,   105,
     104,   194,   100,   155,   121,   104,   105,   151,   151,   103,
     104,   156,   198,   199,   200,   203,    36,   108,   113,   151,
     197,   204,   103,   107,   110,   139,   104,   108,   106,   104,
     191,   196,   158,    14,    15,    18,    19,    20,    26,    27,
      28,    32,    38,    44,    99,   111,   126,   153,   155,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   110,   151,
     205,   213,    99,   103,   104,   198,   201,    36,   108,   113,
     151,   197,   156,   171,   180,   181,    95,    95,   182,   111,
     183,   106,   126,   185,   186,   194,   220,    88,   105,   111,
     154,   111,   189,    19,   133,   134,   202,   100,   151,   156,
     171,   103,   194,   196,   203,   104,   105,   104,   151,   197,
     108,   108,    36,   108,   151,   104,   198,    36,   108,   113,
     151,   197,   107,   109,   205,   206,   207,   208,   209,   150,
     126,   154,   126,   106,   211,   103,    99,   103,   126,   153,
     103,   103,   106,   126,   111,   215,   206,   104,   104,   105,
     151,   197,   108,   108,    36,   108,   113,   151,   113,   185,
     111,   181,   110,   103,   110,   111,   154,   105,   126,   106,
     111,   106,   104,   105,   106,   104,   113,   104,   103,    79,
     200,   108,   151,   151,   108,   104,   151,   197,   108,   108,
      36,   108,   151,   154,    99,   105,   111,   205,   125,   209,
     106,   211,    44,   155,   216,   126,   153,   126,   153,   153,
     211,   105,   111,    99,   108,   151,   151,   108,   108,   126,
     103,   165,   166,   103,   178,   179,     6,     7,     8,   103,
     162,   163,   164,   167,   168,   169,   170,   186,   154,   151,
     134,   151,   126,   106,   108,   108,   108,   151,   151,   108,
     108,   111,   205,   207,   211,   103,   216,   216,   104,   104,
     104,   111,   108,   108,   171,   111,   166,   171,   104,   105,
     213,   213,   110,   171,   111,   163,   168,   194,   108,   108,
     205,   153,   104,   153,   104,   153,   211,   211,   211,   104,
     104,   110,   179,     9,   111,   180,   104,   104,   211,   104,
     211,   104,    22,    99,   172,   106,   162,    95,   111,   172,
     126,   211,   211,   211,    57,   194,   111,   126,    57,   100,
     111,   180,   100,    57,   126,   111,    57,   198,   103,   178,
     213,   215,   126,   160,   191,    57,   213,   215
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   127,   128,   128,   128,   128,   128,   129,   129,   129,
     130,   131,   131,   132,   133,   133,   134,   134,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   136,   136,   137,   137,   137,   137,   137,   137,
     137,   138,   138,   138,   138,   138,   138,   139,   139,   140,
     140,   140,   140,   141,   141,   141,   142,   142,   142,   143,
     143,   143,   143,   143,   144,   144,   144,   145,   145,   146,
     146,   147,   147,   148,   148,   149,   149,   150,   150,   151,
     151,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   153,   153,   154,   155,   155,   155,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   157,   157,
     158,   158,   159,   159,   159,   159,   159,   159,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   161,   161,   161,   161,   162,   162,
     163,   163,   164,   164,   164,   164,   165,   165,   166,   166,
     167,   167,   168,   168,   168,   168,   168,   168,   169,   170,
     171,   171,   172,   173,   174,   175,   176,   176,   176,   177,
     177,   178,   178,   179,   180,   180,   181,   182,   182,   183,
     183,   183,   184,   184,   184,   184,   185,   185,   186,   186,
     186,   187,   187,   187,   187,   187,   188,   188,   189,   189,
     190,   191,   191,   191,   191,   192,   192,   193,   193,   194,
     194,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   196,   196,   196,   196,   197,
     197,   198,   198,   199,   199,   200,   200,   200,   200,   201,
     201,   202,   202,   203,   203,   203,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   205,   205,   205,
     206,   206,   206,   206,   207,   208,   208,   209,   209,   210,
     211,   211,   211,   211,   211,   211,   212,   212,   212,   213,
     213,   214,   214,   215,   215,   216,   216,   217,   217,   217,
     218,   218,   218,   218,   218,   218,   219,   219,   219,   219,
     219,   220,   220,   221,   221,   221,   221,   222,   222,   223,
     223,   224,   224,   224,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   226,   226,   226,
     227,   227,   227,   228,   228,   228,   229,   230,   231,   232,
     232,   233
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     6,     1,     3,     3,     3,     1,     4,
       3,     4,     3,     2,     3,     2,     3,     3,     2,     2,
       6,     7,     1,     3,     1,     2,     2,     2,     2,     4,
       4,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     3,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     7,     7,    10,     1,     2,
       1,     1,     3,     6,     7,     4,     1,     2,     7,     9,
       1,     2,     8,     8,    10,    10,     1,     1,     2,     2,
       1,     2,     1,     1,     1,     1,     4,     5,     2,     1,
       1,     1,     3,     5,     1,     2,     3,     1,     2,     2,
       3,     1,     2,     1,     2,     1,     1,     3,     2,     3,
       1,     4,     5,     5,     6,     2,     1,     3,     3,     1,
       4,     1,     1,     1,     1,     1,     1,     4,     4,     2,
       1,     1,     3,     3,     4,     6,     5,     5,     6,     5,
       4,     4,     4,     3,     4,     3,     2,     2,     1,     1,
       2,     3,     1,     1,     3,     5,     2,     2,     1,     1,
       3,     2,     1,     2,     1,     1,     3,     2,     3,     5,
       4,     5,     4,     3,     3,     3,     4,     6,     5,     5,
       6,     4,     4,     2,     3,     3,     4,     3,     4,     1,
       2,     1,     4,     3,     2,     1,     2,     3,     2,     7,
       1,     1,     1,     1,     1,     1,     3,     4,     3,     2,
       3,     1,     2,     1,     1,     1,     2,     7,     5,     5,
       5,     7,     6,     7,     6,     7,     3,     2,     2,     2,
       3,     1,     2,     1,     1,     1,     1,     4,     3,     1,
       2,     1,     1,     1,     3,     2,     4,     3,     4,     2,
       2,     2,     3,     2,     2,     2,     2,     4,     2,     1,
       2,     4,     3,     2,     2,     2,     2,     1,     2,     2,
       3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* primary_expression: IDENTIFIER  */
#line 92 "parser.y"
                 {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 2468 "parser.tab.c"
    break;

  case 3: /* primary_expression: constant  */
#line 95 "parser.y"
               {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 2476 "parser.tab.c"
    break;

  case 4: /* primary_expression: string  */
#line 98 "parser.y"
             {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 2484 "parser.tab.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 101 "parser.y"
                         {
        (yyval.String) = new_string("(");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ')');
    }
#line 2494 "parser.tab.c"
    break;

  case 6: /* primary_expression: generic_selection  */
#line 106 "parser.y"
                         {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 2502 "parser.tab.c"
    break;

  case 7: /* constant: INT_CONSTANT  */
#line 112 "parser.y"
                   {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 2510 "parser.tab.c"
    break;

  case 8: /* constant: FLOAT_CONSTANT  */
#line 115 "parser.y"
                     {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 2518 "parser.tab.c"
    break;

  case 9: /* constant: ENUMERATION_CONSTANT  */
#line 118 "parser.y"
                           {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 2526 "parser.tab.c"
    break;

  case 10: /* enumeration_constant: IDENTIFIER  */
#line 124 "parser.y"
                 {
          (yyval.String) = string_dup((yyvsp[0].String));
          /****/
          /* if(hashmap_get(enum_constants, string_get($1)) == NULL)
              hashmap_add(enum_constants, string_get($1), $1); */
    }
#line 2537 "parser.tab.c"
    break;

  case 11: /* string: STRING  */
#line 133 "parser.y"
             {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 2545 "parser.tab.c"
    break;

  case 12: /* string: FUNC_NAME  */
#line 136 "parser.y"
                {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 2553 "parser.tab.c"
    break;

  case 13: /* generic_selection: GENERIC '(' assignment_expression ',' generic_assoc_list ')'  */
#line 142 "parser.y"
                                                                   {
        (yyval.String) = new_string("_Generic(");
        string_add_str((yyval.String), string_get((yyvsp[-3].String)));
        string_add_char((yyval.String), ',');
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ')');
    }
#line 2565 "parser.tab.c"
    break;

  case 14: /* generic_assoc_list: generic_association  */
#line 152 "parser.y"
                          {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 2573 "parser.tab.c"
    break;

  case 15: /* generic_assoc_list: generic_assoc_list ',' generic_association  */
#line 155 "parser.y"
                                                 {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_char((yyval.String), ',');
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 2583 "parser.tab.c"
    break;

  case 16: /* generic_association: type_name ':' assignment_expression  */
#line 163 "parser.y"
                                          {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), ": ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 2593 "parser.tab.c"
    break;

  case 17: /* generic_association: DEFAULT ':' assignment_expression  */
#line 168 "parser.y"
                                        {
        (yyval.String) = new_string("default: ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 2602 "parser.tab.c"
    break;

  case 18: /* postfix_expression: primary_expression  */
#line 175 "parser.y"
                         {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 2610 "parser.tab.c"
    break;

  case 19: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 178 "parser.y"
                                            {
        (yyval.String) = string_dup((yyvsp[-3].String));
        string_add_char((yyval.String), '[');
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 2621 "parser.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression '(' ')'  */
#line 184 "parser.y"
                                 {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), "()");
    }
#line 2630 "parser.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 188 "parser.y"
                                                          {
        (yyval.String) = string_dup((yyvsp[-3].String));
        string_add_char((yyval.String), '(');
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ')');
    }
#line 2641 "parser.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression STRING argument_expression_list  */
#line 194 "parser.y"
                                                         {
        /* TODO -> ADDED HERE */
        (yyval.String) = new_string("");

        /* Remove quotations */
        string_skip((yyvsp[-1].String), 1);
        string_shorten((yyvsp[-1].String), string_length((yyvsp[-1].String)) - 2);

        /* Replace spaces */
        (yyvsp[-1].String) = string_map((yyvsp[-1].String), (stringlambda)replace_spaces);

        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), '(');
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), ", ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        string_add_char((yyval.String), ')');
    }
#line 2664 "parser.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression STRING  */
#line 212 "parser.y"
                                {
        /* TODO -> ADDED HERE */
        (yyval.String) = new_string("");

        /* Remove quotations */
        string_skip((yyvsp[0].String), 1);
        string_shorten((yyvsp[0].String), string_length((yyvsp[0].String)) - 1);

        /* Replace spaces */
        (yyvsp[0].String) = string_map((yyvsp[0].String), (stringlambda)replace_spaces);

        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        string_add_char((yyval.String), '(');
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ')');
    }
#line 2685 "parser.tab.c"
    break;

  case 24: /* postfix_expression: TYPEDEF_NAME STRING argument_expression_list  */
#line 228 "parser.y"
                                                   {
        /* TODO -> ADDED HERE */
        (yyval.String) = new_string("");
        
        /* Remove quotations */
        string_skip((yyvsp[-1].String), 1);
        string_shorten((yyvsp[-1].String), string_length((yyvsp[-1].String)) - 2);

        /* Replace spaces */
        (yyvsp[-1].String) = string_map((yyvsp[-1].String), (stringlambda)replace_spaces);

        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), '(');
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), ", ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        string_add_char((yyval.String), ')');
    }
#line 2708 "parser.tab.c"
    break;

  case 25: /* postfix_expression: TYPEDEF_NAME STRING  */
#line 246 "parser.y"
                          {
        /* TODO -> ADDED HERE */
        (yyval.String) = new_string("");

        /* Remove quotations */
        string_skip((yyvsp[0].String), 1);
        string_shorten((yyvsp[0].String), string_length((yyvsp[0].String)) - 1);

        /* Replace spaces */
        (yyvsp[0].String) = string_map((yyvsp[0].String), (stringlambda)replace_spaces);

        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        string_add_char((yyval.String), '(');
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ')');
    }
#line 2729 "parser.tab.c"
    break;

  case 26: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 262 "parser.y"
                                        {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_char((yyval.String), '.');
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 2739 "parser.tab.c"
    break;

  case 27: /* postfix_expression: postfix_expression ACCESS IDENTIFIER  */
#line 267 "parser.y"
                                           {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), "->");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 2749 "parser.tab.c"
    break;

  case 28: /* postfix_expression: postfix_expression INCR  */
#line 272 "parser.y"
                              {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), "++");
    }
#line 2758 "parser.tab.c"
    break;

  case 29: /* postfix_expression: postfix_expression DECR  */
#line 276 "parser.y"
                              {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), "--");
    }
#line 2767 "parser.tab.c"
    break;

  case 30: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 280 "parser.y"
                                                 {
        (yyval.String) = new_string("(");
        string_add_str((yyval.String), string_get((yyvsp[-4].String)));
        string_add_str((yyval.String), ") {\n");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_str((yyval.String), "\n}\n");
    }
#line 2779 "parser.tab.c"
    break;

  case 31: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 287 "parser.y"
                                                     {
        (yyval.String) = new_string("(");
        string_add_str((yyval.String), string_get((yyvsp[-5].String)));
        string_add_str((yyval.String), ") {\n");
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), ",\n}\n");
    }
#line 2791 "parser.tab.c"
    break;

  case 32: /* argument_expression_list: assignment_expression  */
#line 297 "parser.y"
                            {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 2799 "parser.tab.c"
    break;

  case 33: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 300 "parser.y"
                                                         {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_char((yyval.String), ',');
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 2809 "parser.tab.c"
    break;

  case 34: /* unary_expression: postfix_expression  */
#line 308 "parser.y"
                         {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 2817 "parser.tab.c"
    break;

  case 35: /* unary_expression: INCR unary_expression  */
#line 311 "parser.y"
                            {
        (yyval.String) = new_string("++");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 2826 "parser.tab.c"
    break;

  case 36: /* unary_expression: DECR unary_expression  */
#line 315 "parser.y"
                            {
        (yyval.String) = new_string("--");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 2835 "parser.tab.c"
    break;

  case 37: /* unary_expression: unary_operator cast_expression  */
#line 319 "parser.y"
                                     {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 2844 "parser.tab.c"
    break;

  case 38: /* unary_expression: SIZEOF unary_expression  */
#line 323 "parser.y"
                              {
        (yyval.String) = new_string("sizeof ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 2853 "parser.tab.c"
    break;

  case 39: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 327 "parser.y"
                               {
        (yyval.String) = new_string("sizeof(");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ')');
    }
#line 2863 "parser.tab.c"
    break;

  case 40: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 332 "parser.y"
                                {
        (yyval.String) = new_string("_Alignof(");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ')');
    }
#line 2873 "parser.tab.c"
    break;

  case 41: /* unary_operator: '&'  */
#line 340 "parser.y"
          {
        (yyval.String) = new_string("&");
    }
#line 2881 "parser.tab.c"
    break;

  case 42: /* unary_operator: '*'  */
#line 343 "parser.y"
          {
        (yyval.String) = new_string("*");
    }
#line 2889 "parser.tab.c"
    break;

  case 43: /* unary_operator: '+'  */
#line 346 "parser.y"
          {
        (yyval.String) = new_string("+");
    }
#line 2897 "parser.tab.c"
    break;

  case 44: /* unary_operator: '-'  */
#line 349 "parser.y"
          {
        (yyval.String) = new_string("-");
    }
#line 2905 "parser.tab.c"
    break;

  case 45: /* unary_operator: '~'  */
#line 352 "parser.y"
          {
        (yyval.String) = new_string("~");
    }
#line 2913 "parser.tab.c"
    break;

  case 46: /* unary_operator: '!'  */
#line 355 "parser.y"
          {
        (yyval.String) = new_string("!");
    }
#line 2921 "parser.tab.c"
    break;

  case 47: /* cast_expression: unary_expression  */
#line 361 "parser.y"
                       {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 2929 "parser.tab.c"
    break;

  case 48: /* cast_expression: '(' type_name ')' cast_expression  */
#line 364 "parser.y"
                                        {
        (yyval.String) = new_string("(");
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_char((yyval.String), ')');
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 2940 "parser.tab.c"
    break;

  case 49: /* multiplicative_expression: cast_expression  */
#line 373 "parser.y"
                      {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 2948 "parser.tab.c"
    break;

  case 50: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 376 "parser.y"
                                                    {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " * ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 2958 "parser.tab.c"
    break;

  case 51: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 381 "parser.y"
                                                    {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " / ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 2968 "parser.tab.c"
    break;

  case 52: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 386 "parser.y"
                                                    {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " % ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 2978 "parser.tab.c"
    break;

  case 53: /* additive_expression: multiplicative_expression  */
#line 394 "parser.y"
                                {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 2986 "parser.tab.c"
    break;

  case 54: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 397 "parser.y"
                                                        {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " + ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 2996 "parser.tab.c"
    break;

  case 55: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 402 "parser.y"
                                                        {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " - ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3006 "parser.tab.c"
    break;

  case 56: /* shift_expression: additive_expression  */
#line 410 "parser.y"
                          {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3014 "parser.tab.c"
    break;

  case 57: /* shift_expression: shift_expression SHIFT_LEFT additive_expression  */
#line 413 "parser.y"
                                                      {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " << ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3024 "parser.tab.c"
    break;

  case 58: /* shift_expression: shift_expression SHIFT_RIGHT additive_expression  */
#line 418 "parser.y"
                                                       {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " >> ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3034 "parser.tab.c"
    break;

  case 59: /* relational_expression: shift_expression  */
#line 426 "parser.y"
                       {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3042 "parser.tab.c"
    break;

  case 60: /* relational_expression: relational_expression '<' shift_expression  */
#line 429 "parser.y"
                                                 {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " < ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3052 "parser.tab.c"
    break;

  case 61: /* relational_expression: relational_expression '>' shift_expression  */
#line 434 "parser.y"
                                                 {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " > ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3062 "parser.tab.c"
    break;

  case 62: /* relational_expression: relational_expression LESS_EQ shift_expression  */
#line 439 "parser.y"
                                                     {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " <= ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3072 "parser.tab.c"
    break;

  case 63: /* relational_expression: relational_expression GREATER_EQ shift_expression  */
#line 444 "parser.y"
                                                        {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " >= ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3082 "parser.tab.c"
    break;

  case 64: /* equality_expression: relational_expression  */
#line 452 "parser.y"
                            {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3090 "parser.tab.c"
    break;

  case 65: /* equality_expression: equality_expression EQ relational_expression  */
#line 455 "parser.y"
                                                   {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " == ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3100 "parser.tab.c"
    break;

  case 66: /* equality_expression: equality_expression NOT_EQ relational_expression  */
#line 460 "parser.y"
                                                       {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " != ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3110 "parser.tab.c"
    break;

  case 67: /* and_expression: equality_expression  */
#line 468 "parser.y"
                          {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3118 "parser.tab.c"
    break;

  case 68: /* and_expression: and_expression '&' equality_expression  */
#line 471 "parser.y"
                                             {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " & ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3128 "parser.tab.c"
    break;

  case 69: /* exclusive_or_expression: and_expression  */
#line 479 "parser.y"
                     {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3136 "parser.tab.c"
    break;

  case 70: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 482 "parser.y"
                                                 {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " ^ ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3146 "parser.tab.c"
    break;

  case 71: /* inclusive_or_expression: exclusive_or_expression  */
#line 490 "parser.y"
                              {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3154 "parser.tab.c"
    break;

  case 72: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 493 "parser.y"
                                                          {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " | ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3164 "parser.tab.c"
    break;

  case 73: /* logical_and_expression: inclusive_or_expression  */
#line 501 "parser.y"
                              {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3172 "parser.tab.c"
    break;

  case 74: /* logical_and_expression: logical_and_expression AND inclusive_or_expression  */
#line 504 "parser.y"
                                                         {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " && ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3182 "parser.tab.c"
    break;

  case 75: /* logical_or_expression: logical_and_expression  */
#line 512 "parser.y"
                             {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3190 "parser.tab.c"
    break;

  case 76: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 515 "parser.y"
                                                      {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " || ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3200 "parser.tab.c"
    break;

  case 77: /* conditional_expression: logical_or_expression  */
#line 523 "parser.y"
                            {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3208 "parser.tab.c"
    break;

  case 78: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 526 "parser.y"
                                                                      {
        (yyval.String) = string_dup((yyvsp[-4].String));
        string_add_str((yyval.String), " ? ");
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), " : ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3220 "parser.tab.c"
    break;

  case 79: /* assignment_expression: conditional_expression  */
#line 536 "parser.y"
                             {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3228 "parser.tab.c"
    break;

  case 80: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 539 "parser.y"
                                                                 {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3238 "parser.tab.c"
    break;

  case 81: /* assignment_operator: '='  */
#line 547 "parser.y"
          {
        (yyval.String) = new_string("=");
    }
#line 3246 "parser.tab.c"
    break;

  case 82: /* assignment_operator: MUL_EQ  */
#line 550 "parser.y"
             {
        (yyval.String) = new_string("*=");
    }
#line 3254 "parser.tab.c"
    break;

  case 83: /* assignment_operator: DIV_EQ  */
#line 553 "parser.y"
             {
        (yyval.String) = new_string("/=");
    }
#line 3262 "parser.tab.c"
    break;

  case 84: /* assignment_operator: MOD_EQ  */
#line 556 "parser.y"
             {
        (yyval.String) = new_string("%=");
    }
#line 3270 "parser.tab.c"
    break;

  case 85: /* assignment_operator: ADD_EQ  */
#line 559 "parser.y"
             {
        (yyval.String) = new_string("+=");
    }
#line 3278 "parser.tab.c"
    break;

  case 86: /* assignment_operator: SUB_EQ  */
#line 562 "parser.y"
             {
        (yyval.String) = new_string("-=");
    }
#line 3286 "parser.tab.c"
    break;

  case 87: /* assignment_operator: SHIFT_LEFT_EQ  */
#line 565 "parser.y"
                    {
        (yyval.String) = new_string("<<=");
    }
#line 3294 "parser.tab.c"
    break;

  case 88: /* assignment_operator: SHIFT_RIGHT_EQ  */
#line 568 "parser.y"
                     {
        (yyval.String) = new_string(">>=");
    }
#line 3302 "parser.tab.c"
    break;

  case 89: /* assignment_operator: AND_EQ  */
#line 571 "parser.y"
             {
        (yyval.String) = new_string("&=");
    }
#line 3310 "parser.tab.c"
    break;

  case 90: /* assignment_operator: XOR_EQ  */
#line 574 "parser.y"
             {
        (yyval.String) = new_string("^=");
    }
#line 3318 "parser.tab.c"
    break;

  case 91: /* assignment_operator: OR_EQ  */
#line 577 "parser.y"
            {
        (yyval.String) = new_string("|=");
    }
#line 3326 "parser.tab.c"
    break;

  case 92: /* expression: assignment_expression  */
#line 583 "parser.y"
                            {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3334 "parser.tab.c"
    break;

  case 94: /* constant_expression: conditional_expression  */
#line 590 "parser.y"
                             {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3342 "parser.tab.c"
    break;

  case 95: /* declaration: declaration_specifiers ';'  */
#line 596 "parser.y"
                                 {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), ";\n");
    }
#line 3351 "parser.tab.c"
    break;

  case 96: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 600 "parser.y"
                                                      {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_str((yyval.String), ";\n");
    }
#line 3361 "parser.tab.c"
    break;

  case 97: /* declaration: static_assert_declaration  */
#line 605 "parser.y"
                                {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3369 "parser.tab.c"
    break;

  case 98: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 611 "parser.y"
                                                     {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3378 "parser.tab.c"
    break;

  case 99: /* declaration_specifiers: storage_class_specifier  */
#line 615 "parser.y"
                              {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3386 "parser.tab.c"
    break;

  case 100: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 618 "parser.y"
                                            {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3395 "parser.tab.c"
    break;

  case 101: /* declaration_specifiers: type_specifier  */
#line 622 "parser.y"
                     {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3403 "parser.tab.c"
    break;

  case 102: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 625 "parser.y"
                                            {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3412 "parser.tab.c"
    break;

  case 103: /* declaration_specifiers: type_qualifier  */
#line 629 "parser.y"
                     {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3420 "parser.tab.c"
    break;

  case 104: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 632 "parser.y"
                                                {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3429 "parser.tab.c"
    break;

  case 105: /* declaration_specifiers: function_specifier  */
#line 636 "parser.y"
                         {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3437 "parser.tab.c"
    break;

  case 106: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 639 "parser.y"
                                                 {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3446 "parser.tab.c"
    break;

  case 107: /* declaration_specifiers: alignment_specifier  */
#line 643 "parser.y"
                          {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3454 "parser.tab.c"
    break;

  case 108: /* init_declarator_list: init_declarator  */
#line 649 "parser.y"
                      {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3462 "parser.tab.c"
    break;

  case 109: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 652 "parser.y"
                                               {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_char((yyval.String), ',');
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3472 "parser.tab.c"
    break;

  case 110: /* init_declarator: declarator '=' initializer  */
#line 660 "parser.y"
                                 {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " = ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 3482 "parser.tab.c"
    break;

  case 111: /* init_declarator: declarator  */
#line 665 "parser.y"
                 {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3490 "parser.tab.c"
    break;

  case 112: /* storage_class_specifier: TYPEDEF  */
#line 671 "parser.y"
              {
        (yyval.String) = new_string("typedef ");
    }
#line 3498 "parser.tab.c"
    break;

  case 113: /* storage_class_specifier: EXTERN  */
#line 674 "parser.y"
             {
        (yyval.String) = new_string("extern ");
    }
#line 3506 "parser.tab.c"
    break;

  case 114: /* storage_class_specifier: STATIC  */
#line 677 "parser.y"
             {
        (yyval.String) = new_string("static ");
    }
#line 3514 "parser.tab.c"
    break;

  case 115: /* storage_class_specifier: THREAD_LOCAL  */
#line 680 "parser.y"
                   {
        (yyval.String) = new_string("_Thread_local ");
    }
#line 3522 "parser.tab.c"
    break;

  case 116: /* storage_class_specifier: AUTO  */
#line 683 "parser.y"
           {
        (yyval.String) = new_string("auto ");
    }
#line 3530 "parser.tab.c"
    break;

  case 117: /* storage_class_specifier: REGISTER  */
#line 686 "parser.y"
               {
        (yyval.String) = new_string("register ");
    }
#line 3538 "parser.tab.c"
    break;

  case 118: /* type_specifier: VOID  */
#line 692 "parser.y"
           {
        (yyval.String) = new_string("void ");
    }
#line 3546 "parser.tab.c"
    break;

  case 119: /* type_specifier: CHAR  */
#line 695 "parser.y"
           {
        (yyval.String) = new_string("char ");
    }
#line 3554 "parser.tab.c"
    break;

  case 120: /* type_specifier: SHORT  */
#line 698 "parser.y"
            {
        (yyval.String) = new_string("short ");
    }
#line 3562 "parser.tab.c"
    break;

  case 121: /* type_specifier: INT  */
#line 701 "parser.y"
          {
        (yyval.String) = new_string("int ");
    }
#line 3570 "parser.tab.c"
    break;

  case 122: /* type_specifier: LONG  */
#line 704 "parser.y"
           {
        (yyval.String) = new_string("long ");
    }
#line 3578 "parser.tab.c"
    break;

  case 123: /* type_specifier: FLOAT  */
#line 707 "parser.y"
            {
        (yyval.String) = new_string("float ");
    }
#line 3586 "parser.tab.c"
    break;

  case 124: /* type_specifier: DOUBLE  */
#line 710 "parser.y"
             {
        (yyval.String) = new_string("double ");
    }
#line 3594 "parser.tab.c"
    break;

  case 125: /* type_specifier: SIGNED  */
#line 713 "parser.y"
             {
        (yyval.String) = new_string("signed ");
    }
#line 3602 "parser.tab.c"
    break;

  case 126: /* type_specifier: UNSIGNED  */
#line 716 "parser.y"
               {
        (yyval.String) = new_string("unsigned ");
    }
#line 3610 "parser.tab.c"
    break;

  case 127: /* type_specifier: BOOL  */
#line 719 "parser.y"
           {
        (yyval.String) = new_string("_Bool ");
    }
#line 3618 "parser.tab.c"
    break;

  case 128: /* type_specifier: COMPLEX  */
#line 722 "parser.y"
              {
        (yyval.String) = new_string("_Complex ");
    }
#line 3626 "parser.tab.c"
    break;

  case 129: /* type_specifier: IMAGINARY  */
#line 725 "parser.y"
                {
        (yyval.String) = new_string("_Imaginary ");
    }
#line 3634 "parser.tab.c"
    break;

  case 130: /* type_specifier: atomic_type_specifier  */
#line 728 "parser.y"
                            {
        (yyval.String) = string_dup((yyvsp[0].String));
        string_add_char((yyval.String), ' ');
    }
#line 3643 "parser.tab.c"
    break;

  case 131: /* type_specifier: struct_or_union_specifier  */
#line 732 "parser.y"
                                {
        (yyval.String) = string_dup((yyvsp[0].String));
        string_add_char((yyval.String), ' ');
    }
#line 3652 "parser.tab.c"
    break;

  case 132: /* type_specifier: enum_specifier  */
#line 736 "parser.y"
                     {
        (yyval.String) = string_dup((yyvsp[0].String));
        string_add_char((yyval.String), ' ');
    }
#line 3661 "parser.tab.c"
    break;

  case 133: /* type_specifier: TYPEDEF_NAME  */
#line 740 "parser.y"
                   { /* after defined as a typedef_name */
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 3669 "parser.tab.c"
    break;

  case 134: /* object_specifier: model IDENTIFIER '{' model_declaration_list '}'  */
#line 746 "parser.y"
                                                      {
        (yyval.String) = new_string("");

        hashmap *model_fields = new_hashmap();
        int i;
        for(i = 0; i < vector_length((yyvsp[-1].Vector)); i++) {
            vector *current = vector_get((yyvsp[-1].Vector), i);
            /* And a hashmap entry with the variable name and
                store the vector that describes the variable */
            hashmap_add(model_fields, string_get(vector_get(current, 1)), current);
        }
        hashmap_add(models, string_get((yyvsp[-3].String)), model_fields);
        if(hashmap_get(typedef_names, string_get((yyvsp[-3].String))) == NULL)
            hashmap_add(typedef_names, string_get(string_dup((yyvsp[-3].String))), (void*)true);
        // if(hashmap_get(object_names, string_get($2)) == NULL)
        //     hashmap_add(object_names, string_get(string_dup($2)), (void*)true);
    }
#line 3691 "parser.tab.c"
    break;

  case 135: /* object_specifier: protocol IDENTIFIER IMPLEMENTS TYPEDEF_NAME '{' abstract_message_declaration_list '}'  */
#line 763 "parser.y"
                                                                                            {
        (yyval.String) = new_string("");

        // /* contains (superclass): string, and (messages): vector */
        // vector *protocol_entry = new_vector();
        // vector_add(protocol_entry, $4);

        // hashmap *protocol_messages = new_hashmap();
        // int i;
        // for(i = 0; i < vector_length($6); i++) {
        //     vector *current = vector_get($6, i);
        //     /* Add a hashmap entry with the messsage name and 
        //         store the vector that describes the message */
        //     hashmap_add(protocol_messages, string_get(vector_get(current, 2)), current);
        // }
        // vector_add(protocol_entry, protocol_messages);

        // hashmap_add(protocols, string_get($2), protocol_entry);
        // if(hashmap_get(typedef_names, string_get($2)) == NULL)
        //     hashmap_add(typedef_names, string_get(string_dup($2)), (void*)true);
        // if(hashmap_get(object_names, string_get($2)) == NULL)
        //     hashmap_add(object_names, string_get(string_dup($2)), (void*)true);
    }
#line 3719 "parser.tab.c"
    break;

  case 136: /* object_specifier: object IDENTIFIER IMPLEMENTS TYPEDEF_NAME '{' object_declaration_list '}'  */
#line 786 "parser.y"
                                                                                {
        (yyval.String) = new_string("");

        vector *object_entry = new_vector();
        hashmap *object_fields = new_hashmap();
        hashmap *object_messages = new_hashmap();

        /*******/
        vector *object_declaration_fields = vector_get((yyvsp[-1].Vector), 0);
        vector *object_declaration_messages = vector_get((yyvsp[-1].Vector), 1);
        int i;
        for(i = 0; i < vector_length(object_declaration_fields); i++) {
            vector *current = vector_get(object_declaration_fields, i);

            /* Add a hashmap entry with the field name and
                store the vector that describes the field */
            hashmap_add(object_fields, string_get(vector_get(current, 1)), current);
        }
        for(i = 0; i < vector_length(object_declaration_messages); i++) {
            vector *current = vector_get(object_declaration_messages, i);

            /* Add a hashmap entry with the message name and
                store the vector that describes the message */
            hashmap_add(object_messages, string_get(vector_get(current, 2)), current);
        }
        /*******/

        vector_add(object_entry, (yyvsp[-3].String)); /* name */
        vector *object_entry_data = new_vector();
        vector_add(object_entry_data, object_fields);
        vector_add(object_entry_data, new_string(""));
        vector_add(object_entry_data, object_messages);
        vector_add(object_entry, object_entry_data); /* the 3 hashmaps */

        hashmap_add(objects, string_get((yyvsp[-5].String)), object_entry);
        if(hashmap_get(typedef_names, string_get((yyvsp[-5].String))) == NULL)
            hashmap_add(typedef_names, string_get(string_dup((yyvsp[-5].String))), (void*)true);
        if(hashmap_get(object_names, string_get((yyvsp[-5].String))) == NULL)
            hashmap_add(object_names, string_get(string_dup((yyvsp[-5].String))), (void*)true);
        
        /* Translate the parsed data */
        string_add_str((yyval.String), "\n#ifndef __");
        string_add_str((yyval.String), string_get((yyvsp[-5].String)));
        string_add_str((yyval.String), "_\n");
        string_add_str((yyval.String), "#define __");
        string_add_str((yyval.String), string_get((yyvsp[-5].String)));
        string_add_str((yyval.String), "_\n\n");

        string_add_str((yyval.String), "/* INDLUDE SUPER */\n");
        string_add_str((yyval.String), "#include \"");
        string_add_str((yyval.String), string_get((yyvsp[-3].String)));
        string_add_str((yyval.String), ".h\"\n\n");
        string_add_str((yyval.String), "/* REPRESENTATION */\n");
        string_add_str((yyval.String), "struct ");
        string_add_str((yyval.String), string_get((yyvsp[-5].String)));
        string_add_str((yyval.String), " {\n    const struct ");
        string_add_str((yyval.String), string_get((yyvsp[-3].String)));
        string_add_str((yyval.String), " _;\n");
        
        for(i = 0; i < object_fields->alloced; i++) {
            if(object_fields->data[i].in_use != 0) {
                vector *field = object_fields->data[i].data;
                string_add_str((yyval.String), string_get(vector_get(field, 0)));
                // string_add_char($$, ' ');
                string_add_str((yyval.String), string_get(vector_get(field, 1)));
                string_add_str((yyval.String), ";\n");
            }
        }
        string_add_str((yyval.String), "};\n");
        
        /* Count locally defined messages */
        int locally_defined_messages = 0;
        for(i = 0; i < object_messages->alloced; i++) {
            if(object_messages->data[i].in_use != 0) {
                vector *message = object_messages->data[i].data;
                
                /* Remove quotations */
                string *name = vector_get(message, 2);
                string_skip(name, 1);
                string_shorten(name, string_length(name) - 2);

                /* Replace spaces */
                name = string_map(name, (stringlambda)replace_spaces);
                vector_set(message, 2, name);

                if(string_equals(vector_get(message, 1), new_string("self "))) {
                    locally_defined_messages++;
                }
            }
        }

        string *inherited_class = new_string("");        
        if(locally_defined_messages != 0) {
            string_add_str((yyval.String), "struct ");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "Class {\n");

            if(string_equals((yyvsp[-3].String), new_string("Object")))
                string_add_str(inherited_class, "Class");
            else {
                string_add_str(inherited_class, string_get((yyvsp[-3].String)));
                string_add_str(inherited_class, "Class");
            }
            string_add_str((yyval.String), "    const struct ");
            string_add_str((yyval.String), string_get(inherited_class));
            string_add_str((yyval.String), " _;\n");
            for(i = 0; i < object_messages->alloced; i++) {
                if(object_messages->data[i].in_use != 0) {
                    vector *message = object_messages->data[i].data;
                    if(!string_equals(vector_get(message, 2), new_string("new"))
                    && !string_equals(vector_get(message, 2), new_string("defer"))
                    && !string_equals(vector_get(message, 1), new_string("super "))) {
                        string_add_str((yyval.String), "    ");
                        string_add_str((yyval.String), string_get(vector_get(message, 0)));
                        string_add_str((yyval.String), " (*");
                        string_add_str((yyval.String), string_get(vector_get(message, 2)));
                        if(string_length(vector_get(message, 3)) == 0)
                            string_add_str((yyval.String), ")(const void *self");
                        else {
                            string_add_str((yyval.String), ")(const void *self");
                            vector *message_fields = vector_get(message, 3);
                            int j;
                            for(j = 0; j < vector_length(message_fields); j++) {
                                string_add_str((yyval.String), ", ");
                                vector *current_message_fields = vector_get(message_fields, j);
                                string_add_str((yyval.String), string_get(vector_get(current_message_fields, 0)));
                                string_add_str((yyval.String), string_get(vector_get(current_message_fields, 1)));
                            }
                        }
                        string_add_str((yyval.String), ");\n");
                    }
                }
            }
            string_add_str((yyval.String), "};");
        }

        string_add_str((yyval.String), "\n\n");
        string_add_str((yyval.String), "/* DECLARATIONS */\n");
        string_add_str((yyval.String), "const void *");
        string_add_str((yyval.String), string_get((yyvsp[-5].String)));
        string_add_str((yyval.String), ";\n");
        if(locally_defined_messages != 0) {
            string_add_str((yyval.String), "const void *");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "Class;\n");
        }

        string_add_str((yyval.String), "\n/* SELECTORS */\n");
        if(locally_defined_messages != 0) {
            for(i = 0; i < object_messages->alloced; i++) {
                if(object_messages->data[i].in_use != 0) {
                    vector *message = object_messages->data[i].data;
                    if(!string_equals(vector_get(message, 2), new_string("new"))
                    && !string_equals(vector_get(message, 2), new_string("defer"))
                    && !string_equals(vector_get(message, 1), new_string("super "))) {
                        /* Write base call */
                        // string_add_str($$, "void *");
                        string_add_str((yyval.String), string_get(vector_get(message, 0)));
                        string_add_str((yyval.String), string_get(vector_get(message, 2)));
                        if(string_length(vector_get(message, 3)) == 0)
                            string_add_str((yyval.String), "(const void *_self");
                        else {
                            string_add_str((yyval.String), "(const void *_self");
                            vector *message_fields = vector_get(message, 3);
                            int j;
                            for(j = 0; j < vector_length(message_fields); j++) {
                                string_add_str((yyval.String), ", ");
                                vector *current_message_fields = vector_get(message_fields, j);
                                string_add_str((yyval.String), string_get(vector_get(current_message_fields, 0)));
                                string_add_str((yyval.String), string_get(vector_get(current_message_fields, 1)));
                            }
                        }
                        string_add_str((yyval.String), ") {\n");
                        string_add_str((yyval.String), "    const struct ");
                        string_add_str((yyval.String), string_get((yyvsp[-5].String)));
                        string_add_str((yyval.String), "Class *class = classOf(_self);\n\n");
                        string_add_str((yyval.String), "    assert(class->");

                        string *name = vector_get(message, 2);
                        string_add_str((yyval.String), string_get(name));
                        string_add_str((yyval.String), ");\n");
                        string_add_str((yyval.String), "    return class->");
                        string_add_str((yyval.String), string_get(name));
                        string_add_str((yyval.String), "(_self");
                        vector *message_fields = vector_get(message, 3);
                        int j;
                        for(j = 0; j < vector_length(message_fields); j++) {
                            string_add_str((yyval.String), ", ");
                            vector *current_message_fields = vector_get(message_fields, j);
                            string_add_str((yyval.String), string_get(vector_get(current_message_fields, 1)));
                        }
                        string_add_str((yyval.String), ");\n}\n");

                        /* Write super call */
                        // string_add_str($$, "void *");
                        string_add_str((yyval.String), string_get(vector_get(message, 0)));
                        string_add_str((yyval.String), "super_");
                        string_add_str((yyval.String), string_get(vector_get(message, 2)));
                        if(string_length(vector_get(message, 3)) == 0)
                            string_add_str((yyval.String), "(const void *_class, const void *_self");
                        else {
                            string_add_str((yyval.String), "(const void *_class, const void *_self");
                            vector *message_fields = vector_get(message, 3);
                            int j;
                            for(j = 0; j < vector_length(message_fields); j++) {
                                string_add_str((yyval.String), ", ");
                                vector *current_message_fields = vector_get(message_fields, j);
                                string_add_str((yyval.String), string_get(vector_get(current_message_fields, 0)));
                                string_add_str((yyval.String), string_get(vector_get(current_message_fields, 1)));
                            }
                        }
                        string_add_str((yyval.String), ") {\n");
                        string_add_str((yyval.String), "    const struct ");
                        string_add_str((yyval.String), string_get((yyvsp[-5].String)));
                        string_add_str((yyval.String), "Class *superclass = super(_class);\n\n");
                        string_add_str((yyval.String), "    assert(_self && superclass->");
                        string_add_str((yyval.String), string_get(name));
                        string_add_str((yyval.String), ");\n");
                        string_add_str((yyval.String), "    return superclass->");
                        string_add_str((yyval.String), string_get(name));
                        string_add_str((yyval.String), "(_self");
                        for(j = 0; j < vector_length(message_fields); j++) {
                            string_add_str((yyval.String), ", ");
                            vector *current_message_fields = vector_get(message_fields, j);
                            string_add_str((yyval.String), string_get(vector_get(current_message_fields, 1)));
                        }
                        string_add_str((yyval.String), ");\n}\n");
                    }
                }
            }
        }

        string_add_str((yyval.String), "\n/* METHODS */\n");
        bool constructor_is_overriden = false;
        bool destructor_is_overriden = false;
        string *method_on_new;
        string *method_on_defer;
        for(i = 0; i < object_messages->alloced; i++) {
            if(object_messages->data[i].in_use != 0) {
                vector *message = object_messages->data[i].data;
                if(string_equals(vector_get(message, 2), new_string("new"))) {
                    constructor_is_overriden = true;
                    method_on_new = vector_get(message, 4);
                }
                if(string_equals(vector_get(message, 2), new_string("defer"))) {
                    destructor_is_overriden = true;
                    method_on_defer = vector_get(message, 4);
                }
            }
        }

        if(constructor_is_overriden) {
            string_add_str((yyval.String), "void *");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "_ctor(void *_self, va_list *app) {\n");
            string_add_str((yyval.String), "    struct ");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), " *self = super_ctor(");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), ", _self, app);\n\n");

            /***********************************************/
            string_add_str((yyval.String), string_get(method_on_new));
            /***********************************************/
            
            string_add_str((yyval.String), "    return self;\n};\n");
        }
        if(destructor_is_overriden) {
            string_add_str((yyval.String), "void *");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "_dtor(void *_self) {\n");
            string_add_str((yyval.String), "    struct ");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), " *self = super_dtor(");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), ", _self);\n\n");
            string_add_str((yyval.String), string_get(method_on_defer));
            string_add_str((yyval.String), "\n    return 0;\n};\n");
        }

        for(i = 0; i < object_messages->alloced; i++) {
            if(object_messages->data[i].in_use != 0) {
                vector *message = object_messages->data[i].data;
                if(string_equals(vector_get(message, 2), new_string("new"))
                || string_equals(vector_get(message, 2), new_string("defer")))
                    continue;
                string_add_str((yyval.String), string_get(vector_get(message, 0)));
                string_add_char((yyval.String), ' ');
                string_add_str((yyval.String), string_get((yyvsp[-5].String)));
                string_add_str((yyval.String), "_");
                string_add_str((yyval.String), string_get(vector_get(message, 2)));
                if(string_length(vector_get(message, 3)) == 0)
                    string_add_str((yyval.String), "(void *_self");
                else {
                    string_add_str((yyval.String), "(void *_self");
                    vector *message_fields = vector_get(message, 3);
                    int j;
                    for(j = 0; j < vector_length(message_fields); j++) {
                        string_add_str((yyval.String), ", ");
                        vector *current_message_fields = vector_get(message_fields, j);
                        string_add_str((yyval.String), string_get(vector_get(current_message_fields, 0)));
                        string_add_str((yyval.String), string_get(vector_get(current_message_fields, 1)));
                    }
                }
                string_add_str((yyval.String), ") {\n");
                string_add_str((yyval.String), "struct ");
                string_add_str((yyval.String), string_get((yyvsp[-5].String)));
                string_add_str((yyval.String), " *self = _self;\n");
                string_add_str((yyval.String), "struct ");
                string_add_str((yyval.String), string_get((yyvsp[-3].String)));
                string_add_str((yyval.String), " *super = (struct ");
                string_add_str((yyval.String), string_get((yyvsp[-3].String)));
                string_add_str((yyval.String), "*)self;\n\n");
                string_add_str((yyval.String), string_get(vector_get(message, 4)));
                string_add_str((yyval.String), "}\n\n");
            }
        }

        if(locally_defined_messages != 0) {
            string_add_str((yyval.String), "void *");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "Class_ctor(void *_self, va_list *app) {\n");
            string_add_str((yyval.String), "    struct ");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "Class *self = super_ctor(");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "Class, _self, app);\n\n");
            string_add_str((yyval.String), "    typedef void (*voidf)();\n");
            string_add_str((yyval.String), "    voidf selector;\n");
            string_add_str((yyval.String), "#ifdef va_copy\n");
            string_add_str((yyval.String), "    va_list ap;\n");
            string_add_str((yyval.String), "    va_copy(ap, *app);\n");
            string_add_str((yyval.String), "#else\n");
            string_add_str((yyval.String), "    va_list ap = *app;\n");
            string_add_str((yyval.String), "#endif\n");
            string_add_str((yyval.String), "    while((selector = va_arg(ap, voidf))) {\n");
            string_add_str((yyval.String), "        voidf method = va_arg(ap, voidf);\n\n");
            for(i = 0; i < object_messages->alloced; i++) {
                if(object_messages->data[i].in_use != 0) {
                    vector *message = object_messages->data[i].data;
                    if(string_equals(vector_get(message, 2), new_string("new"))
                    || string_equals(vector_get(message, 2), new_string("defer"))
                    || string_equals(vector_get(message, 1), new_string("super ")))
                        continue;
                    string_add_str((yyval.String), "        if(selector == (voidf)");
                    string_add_str((yyval.String), string_get(vector_get(message, 2)));
                    string_add_str((yyval.String), ")\n");
                    string_add_str((yyval.String), "            *(voidf*)&self->");
                    string_add_str((yyval.String), string_get(vector_get(message, 2)));
                    string_add_str((yyval.String), " = method;\n");
                }
            }
            string_add_str((yyval.String), "    }\n");
            string_add_str((yyval.String), "#ifdef va_copy\n");
            string_add_str((yyval.String), "    va_end(ap);\n");
            string_add_str((yyval.String), "#endif\n\n");
            string_add_str((yyval.String), "    return self;\n");
            string_add_str((yyval.String), "}\n");
        }

        string_add_str((yyval.String), "/* INITIALIZATION */\n");
        string_add_str((yyval.String), "void __init_");
        string_add_str((yyval.String), string_get((yyvsp[-5].String)));
        string_add_str((yyval.String), "(void) {\n");
        if(!string_equals((yyvsp[-3].String), new_string("Object"))) {
            string_add_str((yyval.String), "__init_");
            string_add_str((yyval.String), string_get((yyvsp[-3].String)));
            string_add_str((yyval.String), "();\n");
        }

        if(locally_defined_messages != 0) {
            string_add_str((yyval.String), "if(!");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "Class) ");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "Class = new(");
            string_add_str((yyval.String), "Class,\n");
            string_add_char((yyval.String), '\"');
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "Class\",\n");
            if(!string_equals((yyvsp[-3].String), new_string("Object"))) {
                string_add_str((yyval.String), string_get((yyvsp[-3].String)));
                string_add_str((yyval.String), "Class,\n");
            }
            else
                string_add_str((yyval.String), "Class,\n");
            string_add_str((yyval.String), "sizeof(struct ");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "Class),\n");
            string_add_str((yyval.String), "ctor, ");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "Class_ctor,\n");
            string_add_str((yyval.String), "0);\n");

            string_add_str((yyval.String), "if(!");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), ") ");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), " = new(\n");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "Class,\n");
            string_add_char((yyval.String), '\"');
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "\",\n");
            string_add_str((yyval.String), string_get((yyvsp[-3].String)));
            string_add_str((yyval.String), ",\n");
            string_add_str((yyval.String), "sizeof(struct ");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "),\n");

            for(i = 0; i < object_messages->alloced; i++) {
                if(object_messages->data[i].in_use != 0) {
                    vector *message = object_messages->data[i].data;
                    if(!string_equals(vector_get(message, 2), new_string("new"))
                    && !string_equals(vector_get(message, 2), new_string("defer"))) {
                        string_add_str((yyval.String), string_get(vector_get(message, 2)));
                        string_add_str((yyval.String), ", ");
                        string_add_str((yyval.String), string_get((yyvsp[-5].String)));
                        string_add_str((yyval.String), "_");
                        string_add_str((yyval.String), string_get(vector_get(message, 2)));
                        string_add_str((yyval.String), ",\n");
                    }
                }
            }
        }
        else {
            string_add_str((yyval.String), "if(!");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), ") ");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), " = new(\n");
            string_add_str((yyval.String), "Class,\n");
            string_add_char((yyval.String), '\"');
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "\",\n");
            string_add_str((yyval.String), string_get((yyvsp[-3].String)));
            string_add_str((yyval.String), ",\n");
            string_add_str((yyval.String), "sizeof(struct ");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "),\n");

            for(i = 0; i < object_messages->alloced; i++) {
                if(object_messages->data[i].in_use != 0) {
                    vector *message = object_messages->data[i].data;
                    if(!string_equals(vector_get(message, 2), new_string("new"))
                    && !string_equals(vector_get(message, 2), new_string("defer"))) {
                        string_add_str((yyval.String), string_get(vector_get(message, 2)));
                        string_add_str((yyval.String), ", ");
                        string_add_str((yyval.String), string_get((yyvsp[-5].String)));
                        string_add_str((yyval.String), "_");
                        string_add_str((yyval.String), string_get(vector_get(message, 2)));
                        string_add_str((yyval.String), ",\n");
                    }
                }
            }
        }

        if(constructor_is_overriden) {
            string_add_str((yyval.String), "ctor, ");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "_ctor,\n");
        }

        if(destructor_is_overriden) {
            string_add_str((yyval.String), "dtor, ");
            string_add_str((yyval.String), string_get((yyvsp[-5].String)));
            string_add_str((yyval.String), "_dtor,\n");
        }

        string_add_str((yyval.String), "0);\n}\n");

        string_add_str((yyval.String), "#endif\n\n");
    }
#line 4197 "parser.tab.c"
    break;

  case 137: /* object_specifier: object IDENTIFIER IMPLEMENTS TYPEDEF_NAME '(' object_parameter_type_list ')' '{' object_declaration_list '}'  */
#line 1259 "parser.y"
                                                                                                                   {
        /* TODO -> USE STACK TO SAVE OBJECT NAMES */
        (yyval.String) = new_string("");

        vector *object_entry = new_vector();
        hashmap *object_fields = new_hashmap();
        hashmap *object_messages = new_hashmap();

        /*******/
        vector *object_declaration_fields = vector_get((yyvsp[-1].Vector), 0);
        vector *object_declaration_messages = vector_get((yyvsp[-1].Vector), 1);
        int i;
        for(i = 0; i < vector_length(object_declaration_fields); i++) {
            vector *current = vector_get(object_declaration_fields, i);

            /* Add a hashmap entry with the field name and
                store the vector that describes the field */
            hashmap_add(object_fields, string_get(vector_get(current, 1)), current);
        }
        for(i = 0; i < vector_length(object_declaration_messages); i++) {
            vector *current = vector_get(object_declaration_messages, i);

            /* Add a hashmap entry with the message name and
                store the vector that describes the message */
            hashmap_add(object_messages, string_get(vector_get(current, 2)), current);
        }
        /*******/

        vector_add(object_entry, (yyvsp[-6].String)); /* super */
        vector *object_entry_data = new_vector();
        vector_add(object_entry_data, object_fields);
        vector_add(object_entry_data, (yyvsp[-4].Vector));
        vector_add(object_entry_data, object_messages);
        vector_add(object_entry, object_entry_data); /* the 3 hashmaps */

        hashmap_add(objects, string_get((yyvsp[-8].String)), object_entry);
        if(hashmap_get(typedef_names, string_get((yyvsp[-8].String))) == NULL)
            hashmap_add(typedef_names, string_get(string_dup((yyvsp[-8].String))), (void*)true);
        if(hashmap_get(object_names, string_get((yyvsp[-8].String))) == NULL)
            hashmap_add(object_names, string_get(string_dup((yyvsp[-8].String))), (void*)true);
        
        /* Translate the parsed data */
        string_add_str((yyval.String), "\n#ifndef __");
        string_add_str((yyval.String), string_get((yyvsp[-8].String)));
        string_add_str((yyval.String), "_\n");
        string_add_str((yyval.String), "#define __");
        string_add_str((yyval.String), string_get((yyvsp[-8].String)));
        string_add_str((yyval.String), "_\n\n");

        string_add_str((yyval.String), "/* INDLUDE SUPER */\n");
        string_add_str((yyval.String), "#include \"");
        string_add_str((yyval.String), string_get((yyvsp[-6].String)));
        string_add_str((yyval.String), ".h\"\n\n");
        string_add_str((yyval.String), "/* REPRESENTATION */\n");
        string_add_str((yyval.String), "struct ");
        string_add_str((yyval.String), string_get((yyvsp[-8].String)));
        string_add_str((yyval.String), " {\n    const struct ");
        string_add_str((yyval.String), string_get((yyvsp[-6].String)));
        string_add_str((yyval.String), " _;\n");
        
        for(i = 0; i < object_fields->alloced; i++) {
            if(object_fields->data[i].in_use != 0) {
                vector *field = object_fields->data[i].data;
                string_add_str((yyval.String), string_get(vector_get(field, 0)));
                // string_add_char($$, ' ');
                string_add_str((yyval.String), string_get(vector_get(field, 1)));
                string_add_str((yyval.String), ";\n");
            }
        }
        string_add_str((yyval.String), "};\n");
        
        /* Count locally defined messages */
        int locally_defined_messages = 0;
        for(i = 0; i < object_messages->alloced; i++) {
            if(object_messages->data[i].in_use != 0) {
                vector *message = object_messages->data[i].data;
                
                /* Remove quotations */
                string *name = vector_get(message, 2);
                string_skip(name, 1);
                string_shorten(name, string_length(name) - 2);

                /* Replace spaces */
                name = string_map(name, (stringlambda)replace_spaces);
                vector_set(message, 2, name);

                if(string_equals(vector_get(message, 1), new_string("self "))) {
                    locally_defined_messages++;
                }
            }
        }

        string *inherited_class = new_string("");        
        if(locally_defined_messages != 0) {
            string_add_str((yyval.String), "struct ");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "Class {\n");

            if(string_equals((yyvsp[-6].String), new_string("Object")))
                string_add_str(inherited_class, "Class");
            else {
                string_add_str(inherited_class, string_get((yyvsp[-6].String)));
                string_add_str(inherited_class, "Class");
            }
            string_add_str((yyval.String), "    const struct ");
            string_add_str((yyval.String), string_get(inherited_class));
            string_add_str((yyval.String), " _;\n");
            for(i = 0; i < object_messages->alloced; i++) {
                if(object_messages->data[i].in_use != 0) {
                    vector *message = object_messages->data[i].data;
                    if(!string_equals(vector_get(message, 2), new_string("new"))
                    && !string_equals(vector_get(message, 2), new_string("defer"))
                    && !string_equals(vector_get(message, 1), new_string("super "))) {
                        string_add_str((yyval.String), "    ");
                        string_add_str((yyval.String), string_get(vector_get(message, 0)));
                        string_add_str((yyval.String), " (*");
                        string_add_str((yyval.String), string_get(vector_get(message, 2)));
                        if(string_length(vector_get(message, 3)) == 0)
                            string_add_str((yyval.String), ")(const void *self");
                        else {
                            string_add_str((yyval.String), ")(const void *self");
                            vector *message_fields = vector_get(message, 3);
                            int j;
                            for(j = 0; j < vector_length(message_fields); j++) {
                                string_add_str((yyval.String), ", ");
                                vector *current_message_fields = vector_get(message_fields, j);
                                string_add_str((yyval.String), string_get(vector_get(current_message_fields, 0)));
                                string_add_str((yyval.String), string_get(vector_get(current_message_fields, 1)));
                            }
                        }
                        string_add_str((yyval.String), ");\n");
                    }
                }
            }
            string_add_str((yyval.String), "};");
        }

        string_add_str((yyval.String), "\n\n");
        string_add_str((yyval.String), "/* DECLARATIONS */\n");
        string_add_str((yyval.String), "const void *");
        string_add_str((yyval.String), string_get((yyvsp[-8].String)));
        string_add_str((yyval.String), ";\n");
        if(locally_defined_messages != 0) {
            string_add_str((yyval.String), "const void *");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "Class;\n");
        }

        string_add_str((yyval.String), "\n/* SELECTORS */\n");
        if(locally_defined_messages != 0) {
            for(i = 0; i < object_messages->alloced; i++) {
                if(object_messages->data[i].in_use != 0) {
                    vector *message = object_messages->data[i].data;
                    if(!string_equals(vector_get(message, 2), new_string("new"))
                    && !string_equals(vector_get(message, 2), new_string("defer"))
                    && !string_equals(vector_get(message, 1), new_string("super "))) {
                        /* Write base call */
                        // string_add_str($$, "void *");
                        string_add_str((yyval.String), string_get(vector_get(message, 0)));
                        string_add_str((yyval.String), string_get(vector_get(message, 2)));
                        if(string_length(vector_get(message, 3)) == 0)
                            string_add_str((yyval.String), "(const void *_self");
                        else {
                            string_add_str((yyval.String), "(const void *_self");
                            vector *message_fields = vector_get(message, 3);
                            int j;
                            for(j = 0; j < vector_length(message_fields); j++) {
                                string_add_str((yyval.String), ", ");
                                vector *current_message_fields = vector_get(message_fields, j);
                                string_add_str((yyval.String), string_get(vector_get(current_message_fields, 0)));
                                string_add_str((yyval.String), string_get(vector_get(current_message_fields, 1)));
                            }
                        }
                        string_add_str((yyval.String), ") {\n");
                        string_add_str((yyval.String), "    const struct ");
                        string_add_str((yyval.String), string_get((yyvsp[-8].String)));
                        string_add_str((yyval.String), "Class *class = classOf(_self);\n\n");
                        string_add_str((yyval.String), "    assert(class->");

                        string *name = vector_get(message, 2);
                        string_add_str((yyval.String), string_get(name));
                        string_add_str((yyval.String), ");\n");
                        string_add_str((yyval.String), "    return class->");
                        string_add_str((yyval.String), string_get(name));
                        string_add_str((yyval.String), "(_self");
                        vector *message_fields = vector_get(message, 3);
                        int j;
                        for(j = 0; j < vector_length(message_fields); j++) {
                            string_add_str((yyval.String), ", ");
                            vector *current_message_fields = vector_get(message_fields, j);
                            string_add_str((yyval.String), string_get(vector_get(current_message_fields, 1)));
                        }
                        string_add_str((yyval.String), ");\n}\n");

                        /* Write super call */
                        // string_add_str($$, "void *");
                        string_add_str((yyval.String), string_get(vector_get(message, 0)));
                        string_add_str((yyval.String), "super_");
                        string_add_str((yyval.String), string_get(vector_get(message, 2)));
                        if(string_length(vector_get(message, 3)) == 0)
                            string_add_str((yyval.String), "(const void *_class, const void *_self");
                        else {
                            string_add_str((yyval.String), "(const void *_class, const void *_self");
                            vector *message_fields = vector_get(message, 3);
                            int j;
                            for(j = 0; j < vector_length(message_fields); j++) {
                                string_add_str((yyval.String), ", ");
                                vector *current_message_fields = vector_get(message_fields, j);
                                string_add_str((yyval.String), string_get(vector_get(current_message_fields, 0)));
                                string_add_str((yyval.String), string_get(vector_get(current_message_fields, 1)));
                            }
                        }
                        string_add_str((yyval.String), ") {\n");
                        string_add_str((yyval.String), "    const struct ");
                        string_add_str((yyval.String), string_get((yyvsp[-8].String)));
                        string_add_str((yyval.String), "Class *superclass = super(_class);\n\n");
                        string_add_str((yyval.String), "    assert(_self && superclass->");
                        string_add_str((yyval.String), string_get(name));
                        string_add_str((yyval.String), ");\n");
                        string_add_str((yyval.String), "    return superclass->");
                        string_add_str((yyval.String), string_get(name));
                        string_add_str((yyval.String), "(_self");
                        for(j = 0; j < vector_length(message_fields); j++) {
                            string_add_str((yyval.String), ", ");
                            vector *current_message_fields = vector_get(message_fields, j);
                            string_add_str((yyval.String), string_get(vector_get(current_message_fields, 1)));
                        }
                        string_add_str((yyval.String), ");\n}\n");
                    }
                }
            }
        }

        string_add_str((yyval.String), "\n/* METHODS */\n");
        bool constructor_is_overriden = false;
        bool destructor_is_overriden = false;
        string *method_on_new;
        string *method_on_defer;
        for(i = 0; i < object_messages->alloced; i++) {
            if(object_messages->data[i].in_use != 0) {
                vector *message = object_messages->data[i].data;
                if(string_equals(vector_get(message, 2), new_string("new"))) {
                    constructor_is_overriden = true;
                    method_on_new = vector_get(message, 4);
                }
                if(string_equals(vector_get(message, 2), new_string("defer"))) {
                    destructor_is_overriden = true;
                    method_on_defer = vector_get(message, 4);
                }
            }
        }

        if(constructor_is_overriden) {
            string_add_str((yyval.String), "void *");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "_ctor(void *_self, va_list *app) {\n");
            string_add_str((yyval.String), "    struct ");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), " *self = super_ctor(");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), ", _self, app");
            string_add_str((yyval.String), ");\n\n");

            /***********************************************/
            vector *fields = (yyvsp[-4].Vector);
            int k;
            for(k = 0; k < vector_length(fields); k++) {
                vector *current_field = vector_get(fields, k);
                string_add_str((yyval.String), string_get(vector_get(current_field, 0)));
                string_add_str((yyval.String), string_get(vector_get(current_field, 1)));
                string_add_str((yyval.String), " = va_arg(*app, ");
                string_add_str((yyval.String), string_get(vector_get(current_field, 0)));
                string_add_str((yyval.String), ");\n");
            }
            string_add_str((yyval.String), string_get(method_on_new));
            /***********************************************/
            
            string_add_str((yyval.String), "    return self;\n}\n");
        }
        if(destructor_is_overriden) {
            string_add_str((yyval.String), "void *");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "_dtor(void *_self) {\n");
            string_add_str((yyval.String), "    struct ");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), " *self = super_dtor(");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), ", _self);\n\n");
            string_add_str((yyval.String), string_get(method_on_defer));
            string_add_str((yyval.String), "\n    return 0;\n};\n");
        }

        for(i = 0; i < object_messages->alloced; i++) {
            if(object_messages->data[i].in_use != 0) {
                vector *message = object_messages->data[i].data;
                if(string_equals(vector_get(message, 2), new_string("new"))
                || string_equals(vector_get(message, 2), new_string("defer")))
                    continue;
                string_add_str((yyval.String), string_get(vector_get(message, 0)));
                string_add_char((yyval.String), ' ');
                string_add_str((yyval.String), string_get((yyvsp[-8].String)));
                string_add_str((yyval.String), "_");
                string_add_str((yyval.String), string_get(vector_get(message, 2)));
                if(string_length(vector_get(message, 3)) == 0)
                    string_add_str((yyval.String), "(void *_self");
                else {
                    string_add_str((yyval.String), "(void *_self");
                    vector *message_fields = vector_get(message, 3);
                    int j;
                    for(j = 0; j < vector_length(message_fields); j++) {
                        string_add_str((yyval.String), ", ");
                        vector *current_message_fields = vector_get(message_fields, j);
                        string_add_str((yyval.String), string_get(vector_get(current_message_fields, 0)));
                        string_add_str((yyval.String), string_get(vector_get(current_message_fields, 1)));
                    }
                }
                string_add_str((yyval.String), ") {\n");
                string_add_str((yyval.String), "struct ");
                string_add_str((yyval.String), string_get((yyvsp[-8].String)));
                string_add_str((yyval.String), " *self = _self;\n");
                string_add_str((yyval.String), "struct ");
                string_add_str((yyval.String), string_get((yyvsp[-6].String)));
                string_add_str((yyval.String), " *super = (struct ");
                string_add_str((yyval.String), string_get((yyvsp[-6].String)));
                string_add_str((yyval.String), "*)self;\n\n");
                string_add_str((yyval.String), string_get(vector_get(message, 4)));
                string_add_str((yyval.String), "}\n\n");
            }
        }

        if(locally_defined_messages != 0) {
            string_add_str((yyval.String), "void *");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "Class_ctor(void *_self, va_list *app) {\n");
            string_add_str((yyval.String), "    struct ");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "Class *self = super_ctor(");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "Class, _self, app);\n\n");
            string_add_str((yyval.String), "    typedef void (*voidf)();\n");
            string_add_str((yyval.String), "    voidf selector;\n");
            string_add_str((yyval.String), "#ifdef va_copy\n");
            string_add_str((yyval.String), "    va_list ap;\n");
            string_add_str((yyval.String), "    va_copy(ap, *app);\n");
            string_add_str((yyval.String), "#else\n");
            string_add_str((yyval.String), "    va_list ap = *app;\n");
            string_add_str((yyval.String), "#endif\n");
            string_add_str((yyval.String), "    while((selector = va_arg(ap, voidf))) {\n");
            string_add_str((yyval.String), "        voidf method = va_arg(ap, voidf);\n\n");
            for(i = 0; i < object_messages->alloced; i++) {
                if(object_messages->data[i].in_use != 0) {
                    vector *message = object_messages->data[i].data;
                    if(string_equals(vector_get(message, 2), new_string("new"))
                    || string_equals(vector_get(message, 2), new_string("defer"))
                    || string_equals(vector_get(message, 1), new_string("super ")))
                        continue;
                    string_add_str((yyval.String), "        if(selector == (voidf)");
                    string_add_str((yyval.String), string_get(vector_get(message, 2)));
                    string_add_str((yyval.String), ")\n");
                    string_add_str((yyval.String), "            *(voidf*)&self->");
                    string_add_str((yyval.String), string_get(vector_get(message, 2)));
                    string_add_str((yyval.String), " = method;\n");
                }
            }
            string_add_str((yyval.String), "    }\n");
            string_add_str((yyval.String), "#ifdef va_copy\n");
            string_add_str((yyval.String), "    va_end(ap);\n");
            string_add_str((yyval.String), "#endif\n\n");
            string_add_str((yyval.String), "    return self;\n");
            string_add_str((yyval.String), "}\n");
        }

        string_add_str((yyval.String), "/* INITIALIZATION */\n");
        string_add_str((yyval.String), "void __init_");
        string_add_str((yyval.String), string_get((yyvsp[-8].String)));
        string_add_str((yyval.String), "(void) {\n");
        if(!string_equals((yyvsp[-6].String), new_string("Object"))) {
            string_add_str((yyval.String), "__init_");
            string_add_str((yyval.String), string_get((yyvsp[-6].String)));
            string_add_str((yyval.String), "();\n");
        }
        
        if(locally_defined_messages != 0) {
            string_add_str((yyval.String), "if(!");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "Class) ");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "Class = new(");
            string_add_str((yyval.String), "Class,\n");
            string_add_char((yyval.String), '\"');
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "Class\",\n");
            if(!string_equals((yyvsp[-6].String), new_string("Object"))) {
                string_add_str((yyval.String), string_get((yyvsp[-6].String)));
                string_add_str((yyval.String), "Class,\n");
            }
            else
                string_add_str((yyval.String), "Class,\n");
            string_add_str((yyval.String), "sizeof(struct ");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "Class),\n");
            string_add_str((yyval.String), "ctor, ");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "Class_ctor,\n");
            string_add_str((yyval.String), "0);\n");

            string_add_str((yyval.String), "if(!");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), ") ");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), " = new(\n");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "Class,\n");
            string_add_char((yyval.String), '\"');
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "\",\n");
            string_add_str((yyval.String), string_get((yyvsp[-6].String)));
            string_add_str((yyval.String), ",\n");
            string_add_str((yyval.String), "sizeof(struct ");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "),\n");

            for(i = 0; i < object_messages->alloced; i++) {
                if(object_messages->data[i].in_use != 0) {
                    vector *message = object_messages->data[i].data;
                    if(!string_equals(vector_get(message, 2), new_string("new"))
                    && !string_equals(vector_get(message, 2), new_string("defer"))) {
                        string_add_str((yyval.String), string_get(vector_get(message, 2)));
                        string_add_str((yyval.String), ", ");
                        string_add_str((yyval.String), string_get((yyvsp[-8].String)));
                        string_add_str((yyval.String), "_");
                        string_add_str((yyval.String), string_get(vector_get(message, 2)));
                        string_add_str((yyval.String), ",\n");
                    }
                }
            }
        }
        else {
            string_add_str((yyval.String), "if(!");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), ") ");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), " = new(\n");
            string_add_str((yyval.String), "Class,\n");
            string_add_char((yyval.String), '\"');
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "\",\n");
            string_add_str((yyval.String), string_get((yyvsp[-6].String)));
            string_add_str((yyval.String), ",\n");
            string_add_str((yyval.String), "sizeof(struct ");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "),\n");

            for(i = 0; i < object_messages->alloced; i++) {
                if(object_messages->data[i].in_use != 0) {
                    vector *message = object_messages->data[i].data;
                    if(!string_equals(vector_get(message, 2), new_string("new"))
                    && !string_equals(vector_get(message, 2), new_string("defer"))) {
                        string_add_str((yyval.String), string_get(vector_get(message, 2)));
                        string_add_str((yyval.String), ", ");
                        string_add_str((yyval.String), string_get((yyvsp[-8].String)));
                        string_add_str((yyval.String), "_");
                        string_add_str((yyval.String), string_get(vector_get(message, 2)));
                        string_add_str((yyval.String), ",\n");
                    }
                }
            }
        }
        
        if(constructor_is_overriden) {
            string_add_str((yyval.String), "ctor, ");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "_ctor,\n");
        }

        if(destructor_is_overriden) {
            string_add_str((yyval.String), "dtor, ");
            string_add_str((yyval.String), string_get((yyvsp[-8].String)));
            string_add_str((yyval.String), "_dtor,\n");
        }

        string_add_str((yyval.String), "0);\n}\n");

        string_add_str((yyval.String), "#endif\n\n");
    }
#line 4687 "parser.tab.c"
    break;

  case 138: /* object_declaration_list: object_declaration  */
#line 1747 "parser.y"
                         {
        (yyval.Vector) = vector_dup((yyvsp[0].Vector));
    }
#line 4695 "parser.tab.c"
    break;

  case 139: /* object_declaration_list: object_declaration_list object_declaration  */
#line 1750 "parser.y"
                                                 {
        (yyval.Vector) = vector_dup((yyvsp[-1].Vector));
        vector_add((yyval.Vector), (yyvsp[0].Vector));
    }
#line 4704 "parser.tab.c"
    break;

  case 140: /* object_declaration: fields_declaration  */
#line 1757 "parser.y"
                         {
        (yyval.Vector) = vector_dup((yyvsp[0].Vector));
    }
#line 4712 "parser.tab.c"
    break;

  case 141: /* object_declaration: message_declaration_list  */
#line 1760 "parser.y"
                               {
        (yyval.Vector) = vector_dup((yyvsp[0].Vector));
    }
#line 4720 "parser.tab.c"
    break;

  case 142: /* fields_declaration: FIELDS '{' '}'  */
#line 1766 "parser.y"
                     {
        (yyval.Vector) = new_vector();
        vector_add((yyval.Vector), new_vector());
    }
#line 4729 "parser.tab.c"
    break;

  case 143: /* fields_declaration: FIELDS '{' IMPLEMENTS TYPEDEF_NAME ';' '}'  */
#line 1770 "parser.y"
                                                 {
        /* TODO -> ADDED HERE */
        (yyval.Vector) = new_vector();
        vector *current_fields = new_vector();

        hashmap *current_model = hashmap_get(models, string_get((yyvsp[-2].String)));
        int i;
        for(i = 0; i < current_model->alloced; i++)
            if(current_model->data[i].in_use != 0)
                vector_add(current_fields, current_model->data[i].data);
        
        vector_add((yyval.Vector), current_fields);
    }
#line 4747 "parser.tab.c"
    break;

  case 144: /* fields_declaration: FIELDS '{' IMPLEMENTS TYPEDEF_NAME ';' model_declaration_list '}'  */
#line 1783 "parser.y"
                                                                        {
        /* TODO -> ADDED HERE */
        (yyval.Vector) = new_vector();

        hashmap *current_model = hashmap_get(models, string_get((yyvsp[-3].String)));
        int i;
        for(i = 0; i < current_model->alloced; i++)
            if(current_model->data[i].in_use != 0) {
                vector_add((yyvsp[-1].Vector), current_model->data[i].data);
            }
        
        vector_add((yyval.Vector), (yyvsp[-1].Vector));
    }
#line 4765 "parser.tab.c"
    break;

  case 145: /* fields_declaration: FIELDS '{' model_declaration_list '}'  */
#line 1796 "parser.y"
                                            {
        (yyval.Vector) = new_vector();
        vector_add((yyval.Vector), (yyvsp[-1].Vector));
    }
#line 4774 "parser.tab.c"
    break;

  case 146: /* abstract_message_declaration_list: abstract_message_declaration  */
#line 1803 "parser.y"
                                   {
        (yyval.Vector) = new_vector();
        // vector_add($$, $1);
    }
#line 4783 "parser.tab.c"
    break;

  case 147: /* abstract_message_declaration_list: abstract_message_declaration_list abstract_message_declaration  */
#line 1807 "parser.y"
                                                                     {
        (yyval.Vector) = new_vector();
        // int i;
        // for(i = 0; i < vector_length($1); i++)
        //     vector_add($$, vector_get($1, i));
        // vector_add($$, $2);
    }
#line 4795 "parser.tab.c"
    break;

  case 148: /* abstract_message_declaration: '(' declaration_specifiers_or_pointer ')' self_or_super SEND STRING ';'  */
#line 1817 "parser.y"
                                                                              {
        (yyval.Vector) = new_vector();
        // vector_add($$, $2); /* return value */
        // vector_add($$, $4); /* sender */
        // vector_add($$, $6); /* name */
        // vector_add($$, new_string("")); /* parameter entries */
        // vector_add($$, new_string("")); /* method block */
    }
#line 4808 "parser.tab.c"
    break;

  case 149: /* abstract_message_declaration: '(' declaration_specifiers_or_pointer ')' self_or_super SEND STRING SEND parameter_type_list ';'  */
#line 1825 "parser.y"
                                                                                                       {
        (yyval.Vector) = new_vector();
        // vector_add($$, $2); /* return value */
        // vector_add($$, $4); /* sender */
        // vector_add($$, $6); /* name */
        // vector_add($$, $8); /* parameter entries */
        // vector_add($$, new_string("")); /* method block */
    }
#line 4821 "parser.tab.c"
    break;

  case 150: /* message_declaration_list: message_declaration  */
#line 1835 "parser.y"
                          {
        (yyval.Vector) = new_vector();
        vector_add((yyval.Vector), (yyvsp[0].Vector));
    }
#line 4830 "parser.tab.c"
    break;

  case 151: /* message_declaration_list: message_declaration_list message_declaration  */
#line 1839 "parser.y"
                                                   {
        (yyval.Vector) = new_vector();
        int i;
        for(i = 0; i < vector_length((yyvsp[-1].Vector)); i++)
            vector_add((yyval.Vector), vector_get((yyvsp[-1].Vector), i));
        vector_add((yyval.Vector), (yyvsp[0].Vector));
    }
#line 4842 "parser.tab.c"
    break;

  case 152: /* message_declaration: '(' declaration_specifiers_or_pointer ')' self_or_super SEND STRING SEND compound_statement  */
#line 1849 "parser.y"
                                                                                                  {
        (yyval.Vector) = new_vector();
        vector_add((yyval.Vector), (yyvsp[-6].String)); /* return value */
        vector_add((yyval.Vector), (yyvsp[-4].String)); /* sender */
        vector_add((yyval.Vector), (yyvsp[-2].String)); /* name */
        vector_add((yyval.Vector), new_vector()); /* variable entries */
        vector_add((yyval.Vector), (yyvsp[0].String)); /* method block */
    }
#line 4855 "parser.tab.c"
    break;

  case 153: /* message_declaration: '(' declaration_specifiers_or_pointer ')' self_or_super SEND STRING SEND block_item  */
#line 1857 "parser.y"
                                                                                          {
        (yyval.Vector) = new_vector();
        vector_add((yyval.Vector), (yyvsp[-6].String)); /* return vaule */
        vector_add((yyval.Vector), (yyvsp[-4].String)); /* sender */
        vector_add((yyval.Vector), (yyvsp[-2].String)); /* name */
        vector_add((yyval.Vector), new_vector()); /* variable entries */
        vector_add((yyval.Vector), (yyvsp[0].String)); /* method block */
    }
#line 4868 "parser.tab.c"
    break;

  case 154: /* message_declaration: '(' declaration_specifiers_or_pointer ')' self_or_super SEND STRING SEND object_parameter_type_list SEND compound_statement  */
#line 1865 "parser.y"
                                                                                                                                  {
        (yyval.Vector) = new_vector();
        vector_add((yyval.Vector), (yyvsp[-8].String)); /* return value */
        vector_add((yyval.Vector), (yyvsp[-6].String)); /* sender */
        vector_add((yyval.Vector), (yyvsp[-4].String)); /* name */
        vector_add((yyval.Vector), (yyvsp[-2].Vector)); /* variable entries */
        vector_add((yyval.Vector), (yyvsp[0].String)); /* method block */
    }
#line 4881 "parser.tab.c"
    break;

  case 155: /* message_declaration: '(' declaration_specifiers_or_pointer ')' self_or_super SEND STRING SEND object_parameter_type_list SEND block_item  */
#line 1873 "parser.y"
                                                                                                                          {
        (yyval.Vector) = new_vector();
        vector_add((yyval.Vector), (yyvsp[-8].String)); /* return value */
        vector_add((yyval.Vector), (yyvsp[-6].String)); /* sender */
        vector_add((yyval.Vector), (yyvsp[-4].String)); /* name */
        vector_add((yyval.Vector), (yyvsp[-2].Vector)); /* variable entries */
        vector_add((yyval.Vector), (yyvsp[0].String)); /* method block */
    }
#line 4894 "parser.tab.c"
    break;

  case 156: /* message_declaration: constructor_declaration  */
#line 1881 "parser.y"
                              {
        (yyval.Vector) = vector_dup((yyvsp[0].Vector));
    }
#line 4902 "parser.tab.c"
    break;

  case 157: /* message_declaration: destructor_declaration  */
#line 1884 "parser.y"
                             {
        (yyval.Vector) = vector_dup((yyvsp[0].Vector));
    }
#line 4910 "parser.tab.c"
    break;

  case 158: /* constructor_declaration: INIT compound_statement  */
#line 1890 "parser.y"
                              {
        (yyval.Vector) = new_vector();
        vector_add((yyval.Vector), new_string("void ")); /* return value */
        vector_add((yyval.Vector), new_string("super ")); /* sender */
        vector_add((yyval.Vector), new_string("\"new\" ")); /* name */

        vector *params = new_vector();
        vector *param1 = new_vector();
        vector_add(param1, new_string("va_list* "));
        vector_add(param1, new_string("app"));
        vector_add(params, param1);

        vector_add((yyval.Vector), params); /* variable entries */
        vector_add((yyval.Vector), (yyvsp[0].String)); /* method block */
    }
#line 4930 "parser.tab.c"
    break;

  case 159: /* destructor_declaration: DEFER compound_statement  */
#line 1908 "parser.y"
                               {
        (yyval.Vector) = new_vector();
        vector_add((yyval.Vector), new_string("void ")); /* return value */
        vector_add((yyval.Vector), new_string("super ")); /* sender */
        vector_add((yyval.Vector), new_string("\"defer\" ")); /* name */
        vector_add((yyval.Vector), new_vector()); /* variable entries */
        vector_add((yyval.Vector), (yyvsp[0].String)); /* method block */
    }
#line 4943 "parser.tab.c"
    break;

  case 160: /* declaration_specifiers_or_pointer: declaration_specifiers  */
#line 1919 "parser.y"
                             {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 4951 "parser.tab.c"
    break;

  case 161: /* declaration_specifiers_or_pointer: declaration_specifiers '*'  */
#line 1922 "parser.y"
                                 {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_char((yyval.String), '*');
    }
#line 4960 "parser.tab.c"
    break;

  case 162: /* self_or_super: IDENTIFIER  */
#line 1929 "parser.y"
                 {
        if(string_equals((yyvsp[0].String), new_string("self")))
            (yyval.String) = new_string("self ");
        else if(string_equals((yyvsp[0].String), new_string("super")))
            (yyval.String) = new_string("super ");
    }
#line 4971 "parser.tab.c"
    break;

  case 163: /* model: MODEL  */
#line 1938 "parser.y"
            {
        (yyval.String) = new_string("model ");
    }
#line 4979 "parser.tab.c"
    break;

  case 164: /* protocol: PROTOCOL  */
#line 1944 "parser.y"
               {
        (yyval.String) = new_string("protocol ");
    }
#line 4987 "parser.tab.c"
    break;

  case 165: /* object: OBJECT  */
#line 1950 "parser.y"
             {
        (yyval.String) = new_string("object ");
    }
#line 4995 "parser.tab.c"
    break;

  case 166: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 1956 "parser.y"
                                                      {
        (yyval.String) = string_dup((yyvsp[-3].String));
        string_add_str((yyval.String), " {\n");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_str((yyval.String), "\n}\n");
    }
#line 5006 "parser.tab.c"
    break;

  case 167: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 1962 "parser.y"
                                                                 {
        (yyval.String) = string_dup((yyvsp[-4].String));
        string_add_str((yyval.String), string_get((yyvsp[-3].String)));
        string_add_str((yyval.String), " {\n");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_str((yyval.String), "\n}\n");
        /****/
        if(hashmap_get(typedef_names, string_get((yyvsp[-3].String))) == NULL)
            hashmap_add(typedef_names, string_get(string_dup((yyvsp[-3].String))), (void*)true);
    }
#line 5021 "parser.tab.c"
    break;

  case 168: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 1972 "parser.y"
                                 {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        /****/
        if(hashmap_get(typedef_names, string_get((yyvsp[0].String))) == NULL)
            hashmap_add(typedef_names, string_get(string_dup((yyvsp[0].String))), (void*)true);
    }
#line 5033 "parser.tab.c"
    break;

  case 169: /* struct_or_union: STRUCT  */
#line 1982 "parser.y"
             {
        (yyval.String) = new_string("struct ");
    }
#line 5041 "parser.tab.c"
    break;

  case 170: /* struct_or_union: UNION  */
#line 1985 "parser.y"
            {
        (yyval.String) = new_string("union ");
    }
#line 5049 "parser.tab.c"
    break;

  case 171: /* object_parameter_type_list: object_parameter_type  */
#line 1991 "parser.y"
                            {
        (yyval.Vector) = new_vector();
        vector_add((yyval.Vector), (yyvsp[0].Vector));
    }
#line 5058 "parser.tab.c"
    break;

  case 172: /* object_parameter_type_list: object_parameter_type_list ',' object_parameter_type  */
#line 1995 "parser.y"
                                                           {
        (yyval.Vector) = new_vector();
        int i;
        for(i = 0; i < vector_length((yyvsp[-2].Vector)); i++)
            vector_add((yyval.Vector), vector_get((yyvsp[-2].Vector), i));
        vector_add((yyval.Vector), (yyvsp[0].Vector));
    }
#line 5070 "parser.tab.c"
    break;

  case 173: /* object_parameter_type: '(' declaration_specifiers_or_pointer ')' ':' declarator  */
#line 2005 "parser.y"
                                                               {
        (yyval.Vector) = new_vector();
        vector_add((yyval.Vector), (yyvsp[-3].String)); /* type */
        vector_add((yyval.Vector), (yyvsp[0].String)); /* name */
    }
#line 5080 "parser.tab.c"
    break;

  case 174: /* model_declaration_list: model_declaration  */
#line 2012 "parser.y"
                        {
        (yyval.Vector) = vector_dup((yyvsp[0].Vector));
        vector_add((yyval.Vector), (yyvsp[0].Vector)); /* Add the first element */
    }
#line 5089 "parser.tab.c"
    break;

  case 175: /* model_declaration_list: model_declaration_list model_declaration  */
#line 2016 "parser.y"
                                               {
        (yyval.Vector) = vector_dup((yyvsp[-1].Vector));
        vector_add((yyval.Vector), (yyvsp[0].Vector));
    }
#line 5098 "parser.tab.c"
    break;

  case 176: /* model_declaration: declaration_specifiers_or_pointer struct_declarator_list ';'  */
#line 2023 "parser.y"
                                                                   {
        (yyval.Vector) = new_vector();
        vector_add((yyval.Vector), (yyvsp[-2].String)); /* type */
        vector_add((yyval.Vector), (yyvsp[-1].String)); /* name */
    }
#line 5108 "parser.tab.c"
    break;

  case 177: /* struct_declaration_list: struct_declaration  */
#line 2031 "parser.y"
                         {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 5116 "parser.tab.c"
    break;

  case 178: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 2034 "parser.y"
                                                 {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5125 "parser.tab.c"
    break;

  case 179: /* struct_declaration: specifier_qualifier_list ';'  */
#line 2041 "parser.y"
                                   {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), ";\n");
    }
#line 5134 "parser.tab.c"
    break;

  case 180: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 2045 "parser.y"
                                                          {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_str((yyval.String), ";\n");
    }
#line 5144 "parser.tab.c"
    break;

  case 181: /* struct_declaration: static_assert_declaration  */
#line 2050 "parser.y"
                                {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 5152 "parser.tab.c"
    break;

  case 182: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 2056 "parser.y"
                                              {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5161 "parser.tab.c"
    break;

  case 183: /* specifier_qualifier_list: type_specifier  */
#line 2060 "parser.y"
                     {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 5169 "parser.tab.c"
    break;

  case 184: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 2063 "parser.y"
                                              {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5178 "parser.tab.c"
    break;

  case 185: /* specifier_qualifier_list: type_qualifier  */
#line 2067 "parser.y"
                     {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 5186 "parser.tab.c"
    break;

  case 186: /* struct_declarator_list: struct_declarator  */
#line 2073 "parser.y"
                        {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 5194 "parser.tab.c"
    break;

  case 187: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 2076 "parser.y"
                                                   {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), ", ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5204 "parser.tab.c"
    break;

  case 188: /* struct_declarator: ':' constant_expression  */
#line 2084 "parser.y"
                              {
        (yyval.String) = new_string(":");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5213 "parser.tab.c"
    break;

  case 189: /* struct_declarator: declarator ':' constant_expression  */
#line 2088 "parser.y"
                                         {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_char((yyval.String), ':');
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5223 "parser.tab.c"
    break;

  case 190: /* struct_declarator: declarator  */
#line 2093 "parser.y"
                 {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 5231 "parser.tab.c"
    break;

  case 191: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 2099 "parser.y"
                                   {
        (yyval.String) = new_string("enum ");
        string_add_str((yyval.String), " {\n");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_str((yyval.String), "\n}\n");
    }
#line 5242 "parser.tab.c"
    break;

  case 192: /* enum_specifier: ENUM '{' enumerator_list ',' '}'  */
#line 2105 "parser.y"
                                       {
        (yyval.String) = new_string("enum ");
        string_add_str((yyval.String), " {\n");
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), ",\n}\n");
    }
#line 5253 "parser.tab.c"
    break;

  case 193: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 2111 "parser.y"
                                              {
        (yyval.String) = new_string("enum ");
        string_add_str((yyval.String), string_get((yyvsp[-3].String)));
        string_add_str((yyval.String), " {\n");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_str((yyval.String), "\n}\n");
        /****/
        if(hashmap_get(typedef_names, string_get((yyvsp[-3].String))) == NULL)
            hashmap_add(typedef_names, string_get(string_dup((yyvsp[-3].String))), (void*)true);
    }
#line 5268 "parser.tab.c"
    break;

  case 194: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list ',' '}'  */
#line 2121 "parser.y"
                                                  {
        (yyval.String) = new_string("enum ");
        string_add_str((yyval.String), string_get((yyvsp[-4].String)));
        string_add_str((yyval.String), " {\n");
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), ",\n}\n");
        /****/
        if(hashmap_get(typedef_names, string_get((yyvsp[-4].String))) == NULL)
            hashmap_add(typedef_names, string_get(string_dup((yyvsp[-4].String))), (void*)true);
    }
#line 5283 "parser.tab.c"
    break;

  case 195: /* enum_specifier: ENUM IDENTIFIER  */
#line 2131 "parser.y"
                      {
        (yyval.String) = new_string("enum ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        /****/
        if(hashmap_get(typedef_names, string_get((yyvsp[0].String))) == NULL)
            hashmap_add(typedef_names, string_get(string_dup((yyvsp[0].String))), (void*)true);
    }
#line 5295 "parser.tab.c"
    break;

  case 196: /* enumerator_list: enumerator  */
#line 2141 "parser.y"
                 {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 5303 "parser.tab.c"
    break;

  case 197: /* enumerator_list: enumerator_list ',' enumerator  */
#line 2144 "parser.y"
                                     {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), ", ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5313 "parser.tab.c"
    break;

  case 198: /* enumerator: enumeration_constant '=' constant_expression  */
#line 2152 "parser.y"
                                                   {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), " = ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5323 "parser.tab.c"
    break;

  case 199: /* enumerator: enumeration_constant  */
#line 2157 "parser.y"
                           {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 5331 "parser.tab.c"
    break;

  case 200: /* atomic_type_specifier: ATOMIC '(' type_name ')'  */
#line 2163 "parser.y"
                               {
        (yyval.String) = new_string("_Atomic(");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ')');
    }
#line 5341 "parser.tab.c"
    break;

  case 201: /* type_qualifier: CONST  */
#line 2171 "parser.y"
            {
        (yyval.String) = new_string("const ");
    }
#line 5349 "parser.tab.c"
    break;

  case 202: /* type_qualifier: RESTRICT  */
#line 2174 "parser.y"
               {
        (yyval.String) = new_string("restrict ");
    }
#line 5357 "parser.tab.c"
    break;

  case 203: /* type_qualifier: VOLATILE  */
#line 2177 "parser.y"
               {
        (yyval.String) = new_string("volatile ");
    }
#line 5365 "parser.tab.c"
    break;

  case 204: /* type_qualifier: ATOMIC  */
#line 2180 "parser.y"
             {
        (yyval.String) = new_string("atomic ");
    }
#line 5373 "parser.tab.c"
    break;

  case 205: /* function_specifier: INLINE  */
#line 2186 "parser.y"
             {
        (yyval.String) = new_string("inline ");
    }
#line 5381 "parser.tab.c"
    break;

  case 206: /* function_specifier: NORETURN  */
#line 2189 "parser.y"
               {
        (yyval.String) = new_string("noreturn ");
    }
#line 5389 "parser.tab.c"
    break;

  case 207: /* alignment_specifier: ALIGNAS '(' type_name ')'  */
#line 2195 "parser.y"
                                {
        (yyval.String) = new_string("_Alignas(");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ')');
    }
#line 5399 "parser.tab.c"
    break;

  case 208: /* alignment_specifier: ALIGNAS '(' constant_expression ')'  */
#line 2200 "parser.y"
                                          {
        (yyval.String) = new_string("_Alignas(");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ')');
    }
#line 5409 "parser.tab.c"
    break;

  case 209: /* declarator: pointer direct_declarator  */
#line 2208 "parser.y"
                                {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5418 "parser.tab.c"
    break;

  case 210: /* declarator: direct_declarator  */
#line 2212 "parser.y"
                        {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 5426 "parser.tab.c"
    break;

  case 211: /* direct_declarator: IDENTIFIER  */
#line 2218 "parser.y"
                 {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 5434 "parser.tab.c"
    break;

  case 212: /* direct_declarator: '(' declarator ')'  */
#line 2221 "parser.y"
                         {
        (yyval.String) = new_string("(");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ')');
    }
#line 5444 "parser.tab.c"
    break;

  case 213: /* direct_declarator: direct_declarator '[' ']'  */
#line 2226 "parser.y"
                                {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), "[]");
    }
#line 5453 "parser.tab.c"
    break;

  case 214: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 2230 "parser.y"
                                    {
        (yyval.String) = string_dup((yyvsp[-3].String));
        string_add_str((yyval.String), "[*]");
    }
#line 5462 "parser.tab.c"
    break;

  case 215: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 2234 "parser.y"
                                                                                 {
        (yyval.String) = string_dup((yyvsp[-5].String));
        string_add_char((yyval.String), '[');
        string_add_str((yyval.String), "static ");
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 5475 "parser.tab.c"
    break;

  case 216: /* direct_declarator: direct_declarator '[' STATIC assignment_expression ']'  */
#line 2242 "parser.y"
                                                             {
        (yyval.String) = string_dup((yyvsp[-4].String));
        string_add_char((yyval.String), '[');
        string_add_str((yyval.String), "static ");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 5487 "parser.tab.c"
    break;

  case 217: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 2249 "parser.y"
                                                        {
        (yyval.String) = string_dup((yyvsp[-4].String));
        string_add_char((yyval.String), '[');
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), "*]");
    }
#line 5498 "parser.tab.c"
    break;

  case 218: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 2255 "parser.y"
                                                                                 {
        (yyval.String) = string_dup((yyvsp[-5].String));
        string_add_char((yyval.String), '[');
        string_add_str((yyval.String), string_get((yyvsp[-3].String)));
        string_add_str((yyval.String), "static ");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 5511 "parser.tab.c"
    break;

  case 219: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 2263 "parser.y"
                                                                          {
        (yyval.String) = string_dup((yyvsp[-4].String));
        string_add_char((yyval.String), '[');
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 5523 "parser.tab.c"
    break;

  case 220: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 2270 "parser.y"
                                                    {
        (yyval.String) = string_dup((yyvsp[-3].String));
        string_add_char((yyval.String), '[');
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 5534 "parser.tab.c"
    break;

  case 221: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 2276 "parser.y"
                                                      {
        (yyval.String) = string_dup((yyvsp[-3].String));
        string_add_char((yyval.String), '[');
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 5545 "parser.tab.c"
    break;

  case 222: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 2282 "parser.y"
                                                    {
        (yyval.String) = string_dup((yyvsp[-3].String));
        string_add_char((yyval.String), '(');
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ')');
    }
#line 5556 "parser.tab.c"
    break;

  case 223: /* direct_declarator: direct_declarator '(' ')'  */
#line 2288 "parser.y"
                                {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), "()");
    }
#line 5565 "parser.tab.c"
    break;

  case 224: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 2292 "parser.y"
                                                {
        (yyval.String) = string_dup((yyvsp[-3].String));
        string_add_char((yyval.String), '(');
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ')');
    }
#line 5576 "parser.tab.c"
    break;

  case 225: /* pointer: '*' type_qualifier_list pointer  */
#line 2301 "parser.y"
                                      {
        (yyval.String) = new_string("*");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5586 "parser.tab.c"
    break;

  case 226: /* pointer: '*' type_qualifier_list  */
#line 2306 "parser.y"
                              {
        (yyval.String) = new_string("*");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5595 "parser.tab.c"
    break;

  case 227: /* pointer: '*' pointer  */
#line 2310 "parser.y"
                  {
        (yyval.String) = new_string("*");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5604 "parser.tab.c"
    break;

  case 228: /* pointer: '*'  */
#line 2314 "parser.y"
          {
        (yyval.String) = new_string("*");
    }
#line 5612 "parser.tab.c"
    break;

  case 229: /* type_qualifier_list: type_qualifier  */
#line 2320 "parser.y"
                     {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 5620 "parser.tab.c"
    break;

  case 230: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 2323 "parser.y"
                                         {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5629 "parser.tab.c"
    break;

  case 231: /* parameter_type_list: parameter_list ',' VARIABLE_ARGUMENTS  */
#line 2330 "parser.y"
                                            {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), ", ...");
    }
#line 5638 "parser.tab.c"
    break;

  case 232: /* parameter_type_list: parameter_list  */
#line 2334 "parser.y"
                     {
        (yyval.String) = string_dup((yyvsp[0].String)); 
    }
#line 5646 "parser.tab.c"
    break;

  case 233: /* parameter_list: parameter_declaration  */
#line 2340 "parser.y"
                            {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 5654 "parser.tab.c"
    break;

  case 234: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 2343 "parser.y"
                                               {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), ", ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5664 "parser.tab.c"
    break;

  case 235: /* parameter_declaration: '(' declaration_specifiers_or_pointer ')' ':' declarator  */
#line 2351 "parser.y"
                                                               {
        /* TODO -> ADDED HERE */
        (yyval.String) = new_string("(");
        string_add_str((yyval.String), string_get((yyvsp[-3].String)));
        string_add_str((yyval.String), "): ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5676 "parser.tab.c"
    break;

  case 236: /* parameter_declaration: declaration_specifiers declarator  */
#line 2358 "parser.y"
                                        {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5685 "parser.tab.c"
    break;

  case 237: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 2362 "parser.y"
                                                 {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5694 "parser.tab.c"
    break;

  case 238: /* parameter_declaration: declaration_specifiers  */
#line 2366 "parser.y"
                             {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 5702 "parser.tab.c"
    break;

  case 239: /* identifier_list: IDENTIFIER  */
#line 2372 "parser.y"
                 {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 5710 "parser.tab.c"
    break;

  case 240: /* identifier_list: identifier_list ',' IDENTIFIER  */
#line 2375 "parser.y"
                                     {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), ", ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5720 "parser.tab.c"
    break;

  case 241: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 2383 "parser.y"
                                                   {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5729 "parser.tab.c"
    break;

  case 242: /* type_name: specifier_qualifier_list  */
#line 2387 "parser.y"
                               {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 5737 "parser.tab.c"
    break;

  case 243: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 2393 "parser.y"
                                         {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 5746 "parser.tab.c"
    break;

  case 244: /* abstract_declarator: pointer  */
#line 2397 "parser.y"
              {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 5754 "parser.tab.c"
    break;

  case 245: /* abstract_declarator: direct_abstract_declarator  */
#line 2400 "parser.y"
                                 {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 5762 "parser.tab.c"
    break;

  case 246: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 2406 "parser.y"
                                  {
        (yyval.String) = new_string("(");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ')');
    }
#line 5772 "parser.tab.c"
    break;

  case 247: /* direct_abstract_declarator: '[' ']'  */
#line 2411 "parser.y"
              {
        (yyval.String) = new_string("[]");
    }
#line 5780 "parser.tab.c"
    break;

  case 248: /* direct_abstract_declarator: '[' '*' ']'  */
#line 2414 "parser.y"
                  {
        (yyval.String) = new_string("[*]");
    }
#line 5788 "parser.tab.c"
    break;

  case 249: /* direct_abstract_declarator: '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 2417 "parser.y"
                                                               {
        (yyval.String) = new_string("[static ");
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 5799 "parser.tab.c"
    break;

  case 250: /* direct_abstract_declarator: '[' STATIC assignment_expression ']'  */
#line 2423 "parser.y"
                                           {
        (yyval.String) = new_string("[static ");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 5809 "parser.tab.c"
    break;

  case 251: /* direct_abstract_declarator: '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 2428 "parser.y"
                                                               {
        (yyval.String) = new_string("[");
        string_add_str((yyval.String), string_get((yyvsp[-3].String)));
        string_add_str((yyval.String), " static ");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 5821 "parser.tab.c"
    break;

  case 252: /* direct_abstract_declarator: '[' type_qualifier_list assignment_expression ']'  */
#line 2435 "parser.y"
                                                        {
        (yyval.String) = new_string("[");
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 5832 "parser.tab.c"
    break;

  case 253: /* direct_abstract_declarator: '[' type_qualifier_list ']'  */
#line 2441 "parser.y"
                                  {
        (yyval.String) = new_string("[");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 5842 "parser.tab.c"
    break;

  case 254: /* direct_abstract_declarator: '[' assignment_expression ']'  */
#line 2446 "parser.y"
                                    {
        (yyval.String) = new_string("[");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 5852 "parser.tab.c"
    break;

  case 255: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 2451 "parser.y"
                                         {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), "[]");
    }
#line 5861 "parser.tab.c"
    break;

  case 256: /* direct_abstract_declarator: direct_abstract_declarator '[' '*' ']'  */
#line 2455 "parser.y"
                                             {
        (yyval.String) = string_dup((yyvsp[-3].String));
        string_add_str((yyval.String), "[*]");
    }
#line 5870 "parser.tab.c"
    break;

  case 257: /* direct_abstract_declarator: direct_abstract_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 2459 "parser.y"
                                                                                          {
        (yyval.String) = string_dup((yyvsp[-5].String));
        string_add_str((yyval.String), "[static ");
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 5882 "parser.tab.c"
    break;

  case 258: /* direct_abstract_declarator: direct_abstract_declarator '[' STATIC assignment_expression ']'  */
#line 2466 "parser.y"
                                                                      {
        (yyval.String) = string_dup((yyvsp[-4].String));
        string_add_str((yyval.String), "[static ");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 5893 "parser.tab.c"
    break;

  case 259: /* direct_abstract_declarator: direct_abstract_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 2472 "parser.y"
                                                                                   {
        (yyval.String) = string_dup((yyvsp[-4].String));
        string_add_char((yyval.String), '[');
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 5905 "parser.tab.c"
    break;

  case 260: /* direct_abstract_declarator: direct_abstract_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 2479 "parser.y"
                                                                                          {
        (yyval.String) = string_dup((yyvsp[-5].String));
        string_add_char((yyval.String), '[');
        string_add_str((yyval.String), string_get((yyvsp[-3].String)));
        string_add_str((yyval.String), " static ");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 5918 "parser.tab.c"
    break;

  case 261: /* direct_abstract_declarator: direct_abstract_declarator '[' type_qualifier_list ']'  */
#line 2487 "parser.y"
                                                             {
        (yyval.String) = string_dup((yyvsp[-3].String));
        string_add_char((yyval.String), '[');
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 5929 "parser.tab.c"
    break;

  case 262: /* direct_abstract_declarator: direct_abstract_declarator '[' assignment_expression ']'  */
#line 2493 "parser.y"
                                                               {
        (yyval.String) = string_dup((yyvsp[-3].String));
        string_add_char((yyval.String), '[');
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 5940 "parser.tab.c"
    break;

  case 263: /* direct_abstract_declarator: '(' ')'  */
#line 2499 "parser.y"
              {
        (yyval.String) = new_string("()");
    }
#line 5948 "parser.tab.c"
    break;

  case 264: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 2502 "parser.y"
                                  {
        (yyval.String) = new_string("(");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ')');
    }
#line 5958 "parser.tab.c"
    break;

  case 265: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 2507 "parser.y"
                                         {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), "()");
    }
#line 5967 "parser.tab.c"
    break;

  case 266: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 2511 "parser.y"
                                                             {
        (yyval.String) = string_dup((yyvsp[-3].String));
        string_add_char((yyval.String), '(');
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ')');
    }
#line 5978 "parser.tab.c"
    break;

  case 267: /* initializer: '{' initializer_list '}'  */
#line 2520 "parser.y"
                               {
        (yyval.String) = new_string(" {\n");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_str((yyval.String), "\n}\n");
    }
#line 5988 "parser.tab.c"
    break;

  case 268: /* initializer: '{' initializer_list ',' '}'  */
#line 2525 "parser.y"
                                    {
        (yyval.String) = new_string(" {\n");
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), ",\n}\n");
    }
#line 5998 "parser.tab.c"
    break;

  case 269: /* initializer: assignment_expression  */
#line 2530 "parser.y"
                            {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6006 "parser.tab.c"
    break;

  case 270: /* initializer_list: designation initializer  */
#line 2536 "parser.y"
                              {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6015 "parser.tab.c"
    break;

  case 271: /* initializer_list: initializer  */
#line 2540 "parser.y"
                  {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6023 "parser.tab.c"
    break;

  case 272: /* initializer_list: initializer_list ',' designation initializer  */
#line 2543 "parser.y"
                                                   {
        (yyval.String) = string_dup((yyvsp[-3].String));
        string_add_str((yyval.String), ", ");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
    }
#line 6033 "parser.tab.c"
    break;

  case 273: /* initializer_list: initializer_list ',' initializer  */
#line 2548 "parser.y"
                                       {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), ", ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6043 "parser.tab.c"
    break;

  case 274: /* designation: designator_list '='  */
#line 2556 "parser.y"
                          {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), " = ");
    }
#line 6052 "parser.tab.c"
    break;

  case 275: /* designator_list: designator  */
#line 2563 "parser.y"
                 {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6060 "parser.tab.c"
    break;

  case 276: /* designator_list: designator_list designator  */
#line 2566 "parser.y"
                                 {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6069 "parser.tab.c"
    break;

  case 277: /* designator: '[' constant_expression ']'  */
#line 2573 "parser.y"
                                  {
        (yyval.String) = new_string("[");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ']');
    }
#line 6079 "parser.tab.c"
    break;

  case 278: /* designator: '.' IDENTIFIER  */
#line 2578 "parser.y"
                     {
        (yyval.String) = new_string(".");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6088 "parser.tab.c"
    break;

  case 279: /* static_assert_declaration: STATIC_ASSERT '(' constant_expression ',' STRING ')' ';'  */
#line 2585 "parser.y"
                                                               {
        (yyval.String) = new_string("_Static_assert(");
        string_add_str((yyval.String), string_get((yyvsp[-4].String)));
        string_add_str((yyval.String), ", ");
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), ");\n");
    }
#line 6100 "parser.tab.c"
    break;

  case 280: /* statement: labeled_statement  */
#line 2595 "parser.y"
                        {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6108 "parser.tab.c"
    break;

  case 281: /* statement: compound_statement  */
#line 2598 "parser.y"
                         {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6116 "parser.tab.c"
    break;

  case 282: /* statement: expression_statement  */
#line 2601 "parser.y"
                           {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6124 "parser.tab.c"
    break;

  case 283: /* statement: selection_statement  */
#line 2604 "parser.y"
                          {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6132 "parser.tab.c"
    break;

  case 284: /* statement: iteration_statement  */
#line 2607 "parser.y"
                          {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6140 "parser.tab.c"
    break;

  case 285: /* statement: jump_statement  */
#line 2610 "parser.y"
                     {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6148 "parser.tab.c"
    break;

  case 286: /* labeled_statement: IDENTIFIER ':' statement  */
#line 2616 "parser.y"
                               {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), ": ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        /****/
        if(hashmap_get(typedef_names, string_get((yyvsp[-2].String))) == NULL)
            hashmap_add(typedef_names, string_get(string_dup((yyvsp[-2].String))), (void*)true);
    }
#line 6161 "parser.tab.c"
    break;

  case 287: /* labeled_statement: CASE constant_expression ':' statement  */
#line 2624 "parser.y"
                                             {
        (yyval.String) = new_string("case ");
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), ": ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6172 "parser.tab.c"
    break;

  case 288: /* labeled_statement: DEFAULT ':' statement  */
#line 2630 "parser.y"
                            {
        (yyval.String) = new_string("default: ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6181 "parser.tab.c"
    break;

  case 289: /* compound_statement: '{' '}'  */
#line 2637 "parser.y"
              {
        (yyval.String) = new_string("{}\n");
    }
#line 6189 "parser.tab.c"
    break;

  case 290: /* compound_statement: '{' block_item_list '}'  */
#line 2640 "parser.y"
                              {
        (yyval.String) = new_string(" {\n");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_str((yyval.String), "\n}\n");
    }
#line 6199 "parser.tab.c"
    break;

  case 291: /* block_item_list: block_item  */
#line 2648 "parser.y"
                 {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6207 "parser.tab.c"
    break;

  case 292: /* block_item_list: block_item_list block_item  */
#line 2651 "parser.y"
                                 {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6216 "parser.tab.c"
    break;

  case 293: /* block_item: declaration  */
#line 2658 "parser.y"
                  {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6224 "parser.tab.c"
    break;

  case 294: /* block_item: statement  */
#line 2661 "parser.y"
                {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6232 "parser.tab.c"
    break;

  case 295: /* expression_statement: ';'  */
#line 2667 "parser.y"
          {
        (yyval.String) = new_string(";\n");
    }
#line 6240 "parser.tab.c"
    break;

  case 296: /* expression_statement: expression ';'  */
#line 2670 "parser.y"
                     {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), ";\n"/* TODO CAN REMOVE `\n`*/);
    }
#line 6249 "parser.tab.c"
    break;

  case 297: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 2677 "parser.y"
                                                     {
        (yyval.String) = new_string("if(");
        string_add_str((yyval.String), string_get((yyvsp[-4].String)));
        string_add_str((yyval.String), ") ");
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), " else ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6262 "parser.tab.c"
    break;

  case 298: /* selection_statement: IF '(' expression ')' statement  */
#line 2685 "parser.y"
                                      {
        (yyval.String) = new_string("if(");
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), ") ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6273 "parser.tab.c"
    break;

  case 299: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 2691 "parser.y"
                                          {
        (yyval.String) = new_string("switch(");
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), ") ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6284 "parser.tab.c"
    break;

  case 300: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 2700 "parser.y"
                                         {
        (yyval.String) = new_string("while(");
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), ") ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6295 "parser.tab.c"
    break;

  case 301: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 2706 "parser.y"
                                                {
        (yyval.String) = new_string("do ");
        string_add_str((yyval.String), string_get((yyvsp[-5].String)));
        string_add_str((yyval.String), "while(");
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), ");\n");
    }
#line 6307 "parser.tab.c"
    break;

  case 302: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 2713 "parser.y"
                                                                      {
        (yyval.String) = new_string("for(");
        string_add_str((yyval.String), string_get((yyvsp[-3].String)));
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), ") ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6319 "parser.tab.c"
    break;

  case 303: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 2720 "parser.y"
                                                                                 {
        (yyval.String) = new_string("for(");
        string_add_str((yyval.String), string_get((yyvsp[-4].String)));
        string_add_str((yyval.String), string_get((yyvsp[-3].String)));
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), ") ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6332 "parser.tab.c"
    break;

  case 304: /* iteration_statement: FOR '(' declaration expression_statement ')' statement  */
#line 2728 "parser.y"
                                                             {
        (yyval.String) = new_string("for(");
        string_add_str((yyval.String), string_get((yyvsp[-3].String)));
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), ") ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6344 "parser.tab.c"
    break;

  case 305: /* iteration_statement: FOR '(' declaration expression_statement expression ')' statement  */
#line 2735 "parser.y"
                                                                        {
        (yyval.String) = new_string("for(");
        string_add_str((yyval.String), string_get((yyvsp[-4].String)));
        string_add_str((yyval.String), string_get((yyvsp[-3].String)));
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), ") ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6357 "parser.tab.c"
    break;

  case 306: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 2746 "parser.y"
                            {
        (yyval.String) = new_string("goto ");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_str((yyval.String), ";\n");
        /****/
        if(hashmap_get(typedef_names, string_get((yyvsp[-1].String))) == NULL)
            hashmap_add(typedef_names, string_get(string_dup((yyvsp[-1].String))), (void*)true);
    }
#line 6370 "parser.tab.c"
    break;

  case 307: /* jump_statement: CONTINUE ';'  */
#line 2754 "parser.y"
                            {
        (yyval.String) = new_string("continue");
        string_add_str((yyval.String), ";\n");
    }
#line 6379 "parser.tab.c"
    break;

  case 308: /* jump_statement: BREAK ';'  */
#line 2758 "parser.y"
                            {
        (yyval.String) = new_string("break");
        string_add_str((yyval.String), ";\n");
    }
#line 6388 "parser.tab.c"
    break;

  case 309: /* jump_statement: RETURN ';'  */
#line 2762 "parser.y"
                            {
        (yyval.String) = new_string("return");
        string_add_str((yyval.String), ";\n");
    }
#line 6397 "parser.tab.c"
    break;

  case 310: /* jump_statement: RETURN expression ';'  */
#line 2766 "parser.y"
                            {
        (yyval.String) = new_string("return ");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_str((yyval.String), ";\n");
    }
#line 6407 "parser.tab.c"
    break;

  case 311: /* translation_unit: external_declaration  */
#line 2774 "parser.y"
                           {
        /* Get the final declaration */
        string_add_str(translation, string_get((yyvsp[0].String)));
    }
#line 6416 "parser.tab.c"
    break;

  case 312: /* translation_unit: translation_unit external_declaration  */
#line 2778 "parser.y"
                                            {
        /* Get the rest of the declarations */
        string_add_str(translation, string_get((yyvsp[0].String)));
    }
#line 6425 "parser.tab.c"
    break;

  case 313: /* external_declaration: preprocessor_directive  */
#line 2785 "parser.y"
                             {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6433 "parser.tab.c"
    break;

  case 314: /* external_declaration: function_definition  */
#line 2788 "parser.y"
                          {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6441 "parser.tab.c"
    break;

  case 315: /* external_declaration: declaration  */
#line 2791 "parser.y"
                  {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6449 "parser.tab.c"
    break;

  case 316: /* external_declaration: object_specifier  */
#line 2794 "parser.y"
                       {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6457 "parser.tab.c"
    break;

  case 317: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 2800 "parser.y"
                                                                            {
        if(string_equals(string_substring((yyvsp[-2].String), 0, 3), new_string("main"))) {
            (yyval.String) = new_string("void __setup_objects(void);\n");
            string_add_str((yyval.String), string_get((yyvsp[-3].String)));
            string_add_str((yyval.String), string_get((yyvsp[-2].String)));
            string_add_str((yyval.String), string_get((yyvsp[-1].String)));
            string_add_str((yyval.String), " {\n__setup_objects();\n");
            string_add_str((yyval.String), string_get((yyvsp[0].String)));
            string_add_str((yyval.String), "}\n");
            main_flag = true;
        }
        else {
            (yyval.String) = string_dup((yyvsp[-3].String));
            string_add_str((yyval.String), string_get((yyvsp[-2].String)));
            string_add_str((yyval.String), string_get((yyvsp[-1].String)));
            string_add_str((yyval.String), string_get((yyvsp[0].String)));
        }
    }
#line 6480 "parser.tab.c"
    break;

  case 318: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 2818 "parser.y"
                                                           {
        if(string_equals(string_substring((yyvsp[-1].String), 0, 3), new_string("main"))) {
            (yyval.String) = new_string("void __setup_objects(void);\n");
            string_add_str((yyval.String), string_get((yyvsp[-2].String)));
            string_add_str((yyval.String), string_get((yyvsp[-1].String)));
            string_add_str((yyval.String), " {\n__setup_objects();\n");
            string_add_str((yyval.String), string_get((yyvsp[0].String)));
            string_add_str((yyval.String), "}\n");
            main_flag = true;
        }
        else {
            (yyval.String) = string_dup((yyvsp[-2].String));
            string_add_str((yyval.String), string_get((yyvsp[-1].String)));
            string_add_str((yyval.String), string_get((yyvsp[0].String)));
        }
    }
#line 6501 "parser.tab.c"
    break;

  case 319: /* declaration_list: declaration  */
#line 2837 "parser.y"
                  {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6509 "parser.tab.c"
    break;

  case 320: /* declaration_list: declaration_list declaration  */
#line 2840 "parser.y"
                                   {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6518 "parser.tab.c"
    break;

  case 321: /* preprocessor_directive: preprocessor_conditional  */
#line 2847 "parser.y"
                               {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6526 "parser.tab.c"
    break;

  case 322: /* preprocessor_directive: preprocessor_control_line  */
#line 2850 "parser.y"
                                {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6534 "parser.tab.c"
    break;

  case 323: /* preprocessor_directive: preprocessor_constant_expression  */
#line 2853 "parser.y"
                                       {
        (yyval.String) = string_dup((yyvsp[0].String));
    }
#line 6542 "parser.tab.c"
    break;

  case 324: /* preprocessor_control_line: DEFINE IDENTIFIER STRING  */
#line 2859 "parser.y"
                               {
        (yyval.String) = new_string("\n#define ");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ' ');
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        string_add_char((yyval.String), ' ');
    }
#line 6554 "parser.tab.c"
    break;

  case 325: /* preprocessor_control_line: DEFINE IDENTIFIER  */
#line 2866 "parser.y"
                        {
        (yyval.String) = new_string("\n#define ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        string_add_char((yyval.String), ' ');
    }
#line 6564 "parser.tab.c"
    break;

  case 326: /* preprocessor_control_line: DEFINE IDENTIFIER declaration_list STRING  */
#line 2871 "parser.y"
                                                {
        (yyval.String) = new_string("\n#define ");
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_char((yyval.String), ' ');
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ' ');
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        string_add_char((yyval.String), ' ');
    }
#line 6578 "parser.tab.c"
    break;

  case 327: /* preprocessor_control_line: DEFINE IDENTIFIER declaration_list  */
#line 2880 "parser.y"
                                         {
        (yyval.String) = new_string("\n#define ");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ' ');
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        string_add_char((yyval.String), ' ');
    }
#line 6590 "parser.tab.c"
    break;

  case 328: /* preprocessor_control_line: INCLUDE '<' HEADER '>'  */
#line 2887 "parser.y"
                             {
        (yyval.String) = new_string("\n#include <");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_str((yyval.String), ">\n");
    }
#line 6600 "parser.tab.c"
    break;

  case 329: /* preprocessor_control_line: INCLUDE STRING  */
#line 2892 "parser.y"
                     {
        (yyval.String) = new_string("\n#include ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        string_add_char((yyval.String), '\n');
        /* Newline is added on the string */
    }
#line 6611 "parser.tab.c"
    break;

  case 330: /* preprocessor_control_line: IMPORT STRING  */
#line 2898 "parser.y"
                    {
        /* TODO -> ADDED HERE */
        string *import_value = new_string("");
        string_add_str(import_value, string_get((yyvsp[0].String)));

        /* Remove quotations */
        string_skip(import_value, 1);
        string_shorten(import_value, string_length(import_value) - 1);

        /* Add to object names */
        if(hashmap_get(typedef_names, string_get(import_value)) == NULL)
            hashmap_add(typedef_names, string_get(string_dup(import_value)), (void*)true);
        if(hashmap_get(object_names, string_get(import_value)) == NULL)
            hashmap_add(object_names, string_get(string_dup(import_value)), (void*)true);

        /* Add a `.h` */
        string_add_str(import_value, ".h");

        (yyval.String) = new_string("");
        // $$ = new_string("\n#include \"");
        // string_add_str($$, string_get(import_value));
        // string_add_str($$, "\"\n");
    }
#line 6639 "parser.tab.c"
    break;

  case 331: /* preprocessor_control_line: LINE INT_CONSTANT  */
#line 2921 "parser.y"
                        {
        (yyval.String) = new_string("\n#line ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6648 "parser.tab.c"
    break;

  case 332: /* preprocessor_control_line: LINE INT_CONSTANT HEADER  */
#line 2925 "parser.y"
                               {
        (yyval.String) = new_string("\n#line ");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), ' ');
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6659 "parser.tab.c"
    break;

  case 333: /* preprocessor_control_line: UNDEF IDENTIFIER  */
#line 2931 "parser.y"
                       {
        (yyval.String) = new_string("\n#undef ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6668 "parser.tab.c"
    break;

  case 334: /* preprocessor_control_line: ERROR STRING  */
#line 2935 "parser.y"
                   {
        (yyval.String) = new_string("\n#error ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6677 "parser.tab.c"
    break;

  case 335: /* preprocessor_control_line: WARNING STRING  */
#line 2939 "parser.y"
                     {
        (yyval.String) = new_string("\n#warning ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6686 "parser.tab.c"
    break;

  case 336: /* preprocessor_control_line: PRAGMA STRING  */
#line 2943 "parser.y"
                    {
        (yyval.String) = new_string("\n#pragma ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
    }
#line 6695 "parser.tab.c"
    break;

  case 337: /* preprocessor_constant_expression: DEFINED '(' IDENTIFIER ')'  */
#line 2950 "parser.y"
                                 {
        (yyval.String) = new_string("defined(");
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_char((yyval.String), '\n');
    }
#line 6705 "parser.tab.c"
    break;

  case 338: /* preprocessor_constant_expression: DEFINED IDENTIFIER  */
#line 2955 "parser.y"
                         {
        (yyval.String) = new_string("defined ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        string_add_char((yyval.String), '\n');
    }
#line 6715 "parser.tab.c"
    break;

  case 339: /* preprocessor_constant_expression: constant_expression  */
#line 2960 "parser.y"
                          {
        (yyval.String) = string_dup((yyvsp[0].String));
        string_add_char((yyval.String), '\n');
    }
#line 6724 "parser.tab.c"
    break;

  case 340: /* preprocessor_conditional: preprocessor_if_part ENDIF  */
#line 2967 "parser.y"
                                 {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), "\n#endif\n");
    }
#line 6733 "parser.tab.c"
    break;

  case 341: /* preprocessor_conditional: preprocessor_if_part preprocessor_elif_parts preprocessor_else_part ENDIF  */
#line 2971 "parser.y"
                                                                                {
        (yyval.String) = string_dup((yyvsp[-3].String));
        string_add_str((yyval.String), string_get((yyvsp[-2].String)));
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_str((yyval.String), "\n#endif\n");
    }
#line 6744 "parser.tab.c"
    break;

  case 342: /* preprocessor_conditional: preprocessor_if_part preprocessor_else_part ENDIF  */
#line 2977 "parser.y"
                                                        {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_str((yyval.String), "\n#endif\n");
    }
#line 6754 "parser.tab.c"
    break;

  case 343: /* preprocessor_if_line: PRE_IF constant_expression  */
#line 2985 "parser.y"
                                 {
        (yyval.String) = new_string("\n#if ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        string_add_char((yyval.String), ' ');
    }
#line 6764 "parser.tab.c"
    break;

  case 344: /* preprocessor_if_line: IFDEF IDENTIFIER  */
#line 2990 "parser.y"
                       {
        (yyval.String) = new_string("\n#ifdef ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        string_add_char((yyval.String), ' ');
    }
#line 6774 "parser.tab.c"
    break;

  case 345: /* preprocessor_if_line: IFNDEF IDENTIFIER  */
#line 2995 "parser.y"
                        {
        (yyval.String) = new_string("\n#ifndef ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        string_add_char((yyval.String), ' ');
    }
#line 6784 "parser.tab.c"
    break;

  case 346: /* preprocessor_elif_line: PRE_ELIF constant_expression  */
#line 3003 "parser.y"
                                   {
        (yyval.String) = new_string("\n#elif ");
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        string_add_char((yyval.String), ' ');
    }
#line 6794 "parser.tab.c"
    break;

  case 347: /* preprocessor_else_line: PRE_ELSE  */
#line 3011 "parser.y"
               {
        (yyval.String) = new_string("\n#else\n");
        string_add_char((yyval.String), ' ');
    }
#line 6803 "parser.tab.c"
    break;

  case 348: /* preprocessor_if_part: preprocessor_if_line translation_unit  */
#line 3018 "parser.y"
                                            {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        string_add_char((yyval.String), '\n');
    }
#line 6813 "parser.tab.c"
    break;

  case 349: /* preprocessor_elif_parts: preprocessor_elif_line translation_unit  */
#line 3026 "parser.y"
                                              {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        string_add_char((yyval.String), '\n');
    }
#line 6823 "parser.tab.c"
    break;

  case 350: /* preprocessor_elif_parts: preprocessor_elif_parts preprocessor_elif_line translation_unit  */
#line 3031 "parser.y"
                                                                      {
        (yyval.String) = string_dup((yyvsp[-2].String));
        string_add_str((yyval.String), string_get((yyvsp[-1].String)));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        string_add_char((yyval.String), '\n');
    }
#line 6834 "parser.tab.c"
    break;

  case 351: /* preprocessor_else_part: preprocessor_else_line translation_unit  */
#line 3040 "parser.y"
                                              {
        (yyval.String) = string_dup((yyvsp[-1].String));
        string_add_str((yyval.String), string_get((yyvsp[0].String)));
        string_add_char((yyval.String), '\n');
    }
#line 6844 "parser.tab.c"
    break;


#line 6848 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 3047 "parser.y"


extern FILE *yyin;

#define warning(s, t) do { \
    fprintf(stderr, "%s\n", s); \
    if(t) fprintf(stderr, "%s\n", t); \
} while(0);

void yyerror(char *s) {
    fflush(stdout);
    warning(s, (char*)0);
    printf("`%s`\n", string_get(translation));
    /* yyparse(); */
}

static void __setup_hashmaps(void) {
    typedef_names = new_hashmap();
    enum_constants = new_hashmap();
    object_names = new_hashmap();
}

static void __setup_initial_object(void) {
    string *obj = new_string("");
    string_add_str(obj, "#ifndef __OBJECT_H_\n");
    string_add_str(obj, "#define __OBJECT_H_\n\n");
    string_add_str(obj, "#include <assert.h>\n");
    string_add_str(obj, "#include <stdio.h>\n");
    string_add_str(obj, "#include <stdlib.h>\n");
    string_add_str(obj, "#include <string.h>\n");
    string_add_str(obj, "#include <stdarg.h>\n");
    string_add_str(obj, "#include <stddef.h>\n\n");
    string_add_str(obj, "/** @param bool -> A 'big' enough size to hold both 1 and 0 **/\n");
    string_add_str(obj, "typedef unsigned char bool;\n");
    string_add_str(obj, "#define true 1\n");
    string_add_str(obj, "#define false 0\n\n");
    string_add_str(obj, "struct Object {\n");
    string_add_str(obj, "   const struct Class *class;\n");
    string_add_str(obj, "};\n");
    string_add_str(obj, "struct Class {\n");
    string_add_str(obj, "	const struct Object _;\n");
    string_add_str(obj, "	const char *name;\n");
    string_add_str(obj, "	const struct Class *super;\n");
    string_add_str(obj, "	size_t size;\n");
    string_add_str(obj, "	void *(*ctor)(void *self, va_list *app);\n");
    string_add_str(obj, "	void *(*dtor)(void *self);\n");
    string_add_str(obj, "	int (*differ)(const void *self, const void *other);\n");
    string_add_str(obj, "	int (*puto)(const void *self, FILE *fd);\n");
    string_add_str(obj, "};\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static const void *classOf(const void *_self) {\n");
    string_add_str(obj, "	const struct Object *self = _self;\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	assert(_self && self && self->class);\n");
    string_add_str(obj, "	return self->class;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static size_t sizeOf(const void *_self) {\n");
    string_add_str(obj, "	const struct Class *class = classOf(_self);\n");
    string_add_str(obj, "	return class->size;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static const void *super(const void *_self) {\n");
    string_add_str(obj, "	const struct Class *self = _self;\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	assert(_self && self && self->super);\n");
    string_add_str(obj, "	return self->super;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "void *ctor(void *_self, va_list *app) {\n");
    string_add_str(obj, "	const struct Class *class = classOf(_self);\n");
    string_add_str(obj, "	\n");
    string_add_str(obj, "	assert(class->ctor);\n");
    string_add_str(obj, "	return class->ctor(_self, app);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "void *super_ctor(const void *_class, void *_self, va_list *app) {\n");
    string_add_str(obj, "	const struct Class *superclass = super(_class);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	assert(_self && superclass->ctor);\n");
    string_add_str(obj, "	return superclass->ctor(_self, app);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "void *dtor(void *_self) {\n");
    string_add_str(obj, "	const struct Class *class = classOf(_self);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	assert(class->dtor);\n");
    string_add_str(obj, "	return class->dtor(_self);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "void *super_dtor(const void *_class, void *_self) {\n");
    string_add_str(obj, "	const struct Class *superclass = super(_class);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	assert(_self && superclass->dtor);\n");
    string_add_str(obj, "	return superclass->dtor(_self);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "int differ(const void *_self, const void *other) {\n");
    string_add_str(obj, "	const struct Class *class = classOf(_self);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	assert(class->differ);\n");
    string_add_str(obj, "	return class->differ(_self, other);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "int super_differ(const void *_class, const void *_self, const void *other) {\n");
    string_add_str(obj, "	const struct Class *superclass = super(_class);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	assert(_self && superclass->differ);\n");
    string_add_str(obj, "	return superclass->differ(_self, other);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "int puto(const void *_self, FILE *fd) {\n");
    string_add_str(obj, "	const struct Class *class = classOf(_self);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	assert(class->puto);\n");
    string_add_str(obj, "	return class->puto(_self, fd);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "int super_puto(const void *_class, const void *_self, FILE *fd) {\n");
    string_add_str(obj, "	const struct Class *superclass = super(_class);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	assert(_self && superclass->puto);\n");
    string_add_str(obj, "	return superclass->puto(_self, fd);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static void *Object_ctor(void *_self, va_list *app) {\n");
    string_add_str(obj, "	return _self;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static void *Object_dtor(void *_self) {\n");
    string_add_str(obj, "	return _self;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static int Object_differ(const void *_self, const void *other) {\n");
    string_add_str(obj, "	return _self != other;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static int Object_puto(const void *_self, FILE *fd) {\n");
    string_add_str(obj, "	const struct Class *self = classOf(_self);\n");
    string_add_str(obj, "	return fprintf(fd, \"%s at %p\\n\", self->name, _self);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static void *Class_ctor(void *_self, va_list *app) {\n");
    string_add_str(obj, "	struct Class *self = _self;\n");
    string_add_str(obj, "	const size_t offset = offsetof(struct Class, ctor);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	self->name = va_arg(*app, char*);\n");
    string_add_str(obj, "	self->super = va_arg(*app, struct Class*);\n");
    string_add_str(obj, "	self->size = va_arg(*app, size_t);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	assert(self->super);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	memcpy((char*)self + offset, (char*)self->super + offset, sizeOf(self->super) - offset);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	typedef void (*voidf) ();\n");
    string_add_str(obj, "	voidf selector;\n");
    string_add_str(obj, "#ifdef va_copy\n");
    string_add_str(obj, "	va_list ap;\n");
    string_add_str(obj, "	va_copy(ap, *app);\n");
    string_add_str(obj, "#else\n");
    string_add_str(obj, "	va_list ap = *app;\n");
    string_add_str(obj, "#endif\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	while((selector = va_arg(ap, voidf))) {\n");
    string_add_str(obj, "		voidf method = va_arg(ap, voidf);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "		if(selector == (voidf)ctor)\n");
    string_add_str(obj, "			*(voidf*)&self->ctor = method;\n");
    string_add_str(obj, "		else if(selector == (voidf)dtor)\n");
    string_add_str(obj, "			*(voidf*)&self->dtor = method;\n");
    string_add_str(obj, "		else if(selector == (voidf)differ)\n");
    string_add_str(obj, "			*(voidf*)&self->differ = method;\n");
    string_add_str(obj, "		else if(selector == (voidf)puto)\n");
    string_add_str(obj, "			*(voidf*)&self->puto = method;\n");
    string_add_str(obj, "	}\n");
    string_add_str(obj, "#ifdef va_copy\n");
    string_add_str(obj, "    va_end(ap);\n");
    string_add_str(obj, "#endif\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	return self;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static void *Class_dtor(void *_self) {\n");
    string_add_str(obj, "	struct Class *self = _self;\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	fprintf(stderr, \"%s: cannot destroy class\\n\", self->name);\n");
    string_add_str(obj, "	return 0;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static void *new(const void *_class, ...) {\n");
    string_add_str(obj, "	const struct Class *class = _class;\n");
    string_add_str(obj, "	assert(class && class->size);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	struct Object *object;\n");
    string_add_str(obj, "	va_list ap;\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	object = (struct Object*)calloc(1, class->size);\n");
    string_add_str(obj, "	assert(object);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "	object->class = class;\n");
    string_add_str(obj, "	va_start(ap, _class);\n");
    string_add_str(obj, "		object = ctor(object, &ap);\n");
    string_add_str(obj, "	va_end(ap);\n");
    string_add_str(obj, "	return object;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static void defer(void *_self) {\n");
    string_add_str(obj, "	if(_self) free(dtor(_self));\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static const struct Class object [] = {\n");
    string_add_str(obj, "	{\n");
    string_add_str(obj, "		{ object + 1 },\n");
    string_add_str(obj, "		\"Object\",\n");
    string_add_str(obj, "		object,\n");
    string_add_str(obj, "		sizeof(struct Object),\n");
    string_add_str(obj, "		Object_ctor,\n");
    string_add_str(obj, "		Object_dtor,\n");
    string_add_str(obj, "		Object_differ,\n");
    string_add_str(obj, "		Object_puto\n");
    string_add_str(obj, "	},\n");
    string_add_str(obj, "	{\n");
    string_add_str(obj, "		{ object + 1 },\n");
    string_add_str(obj, "		\"Class\",\n");
    string_add_str(obj, "		object,\n");
    string_add_str(obj, "		sizeof(struct Class),\n");
    string_add_str(obj, "		Class_ctor,\n");
    string_add_str(obj, "		Class_dtor,\n");
    string_add_str(obj, "		Object_differ,\n");
    string_add_str(obj, "		Object_puto\n");
    string_add_str(obj, "	}\n");
    string_add_str(obj, "};\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "const void *Object = object;\n");
    string_add_str(obj, "const void *Class = object + 1;\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "#endif\n");

    /*********************************/
    FILE *fp = fopen("Object.h", "w");
    fprintf(fp, "%s", string_get(obj));
    fclose(fp);
    /*********************************/
}

void __setup_objects(void) {
    /* store variable entries -> (vector) */
    models = new_hashmap();

    /* store message entries -> (vector) */
    protocols = new_hashmap();

    /* store vectors of fields parameters and messages */
    objects = new_hashmap();
}

static void write_init_calls(char *o) {
    /* If the node is `Object` we dont need to initialize it */
    if(string_equals(new_string(o), new_string("Object"))) return;

    string_add_str(translation, "    __init_");
    string_add_str(translation, o);
    string_add_str(translation, "();\n");
}
void __setup_init_objects(void) {
    string_add_str(translation, "void __setup_objects(void) {\n");
    hashmap_map(object_names, (lambda)write_init_calls, KEYS);
    string_add_str(translation, "}\n");
}

static void display_strings(char *item) {
    printf("\t%s\n", item);
}
static void display_hashmap(hashmap *map) {
    hashmap_map(map, (lambda)display_strings, KEYS);
}

/**/
static void display_entry(vector *entry) {
    printf("\033[1;36mentry\033[0m: `(%s): %s`\n", string_get(vector_get(entry, 0)), string_get(vector_get(entry, 1)));
}
static void display_hashmap_of_entries(hashmap *variable_entries) {
    hashmap_map(variable_entries, (lambda)display_entry, VALUES);
}
static void iterate_on_models(void) {
    hashmap_map(models, (lambda)display_hashmap_of_entries, VALUES);
}
/**/

/**/
static void display_message(vector *message) {
    int i;
    string *params = new_string("");
    vector *param_vector = vector_get(message, 3);
    for(i = 0; i < vector_length(param_vector); i++) {
        vector *current_param = vector_get(param_vector, i);
        string_add_str(params, vector_get(current_param, 0));
        string_add_str(params, " ");
        string_add_str(params, vector_get(current_param, 1));
    }
    printf("\033[38;5;11mmessage\033[0m: (%s) %s |> %s |> `%s` |> `%s`\n",
        string_get(vector_get(message, 0)),
        string_get(vector_get(message, 1)),
        string_get(vector_get(message, 2)),
        string_get(params),
        string_get(vector_get(message, 4)));
}
/* static void display_hashmap_of_messages(vector *protocol_data) {
    hashmap *messages = vector_get(protocol_data, 1);
    hashmap_map(messages, (lambda)display_message, VALUES);
}
static void iterate_on_protocols(void) {
    hashmap_map(protocols, (lambda)display_hashmap_of_messages, VALUES);
} */
/**/

/**/
static void display_hashmap_of_objects(vector *object_vector) {
    vector *object_data = vector_get(object_vector, 1); /* 0th is name of super */
    printf("\t\033[38;5;78mfields\033[0m\n");
    hashmap_map(vector_get(object_data, 0), (lambda)display_entry, VALUES);
    printf("\t\033[38;5;78mparameters\033[0m\n");
    printf("`%s`\n", string_get(vector_get(object_data, 1)));
    printf("\t\033[38;5;78mmessages\033[0m\n");
    hashmap_map(vector_get(object_data, 2), (lambda)display_message, VALUES);
}
static void iterate_on_objects(void) {
    hashmap_map(objects, (lambda)display_hashmap_of_objects, VALUES);
}
/**/

int main(int argc, char **argv) {
    assert(argc == 2 && argv && argv[1]);

    yyin = fopen(argv[1], "r");
    translation = new_string("");
    __setup_hashmaps();
    __setup_objects();
    /**/
    hashmap_add(typedef_names, "size_t", (void*)true);
    hashmap_add(typedef_names, "bool", (void*)true);
    /**/

    /* Write the initial `object.h` */
    __setup_initial_object();

    /* Parse the text */
    yyparse();
    /******************/

    /* Write the init nodes */
    if(main_flag) __setup_init_objects();

/* printf("\n\033[38;5;207mtypedef_names\033[0m\n");
display_hashmap(typedef_names);
printf("\n\033[38;5;207menum_constants\033[0m\n");
display_hashmap(enum_constants);
printf("\n\033[38;5;207mobject_names\033[0m\n");
display_hashmap(object_names); */

/* printf("\n\033[38;5;207mmodels\033[0m\n");
iterate_on_models();
printf("\n\033[38;5;207mprotocols\033[0m\n");
iterate_on_protocols();
printf("\n\033[38;5;207mobjects\033[0m\n");
iterate_on_objects(); */

    /*********************************/
    FILE *fp = fopen("out.c", "w");
    fprintf(fp, "%s", string_get(translation));
    fclose(fp);
    /*********************************/
}
