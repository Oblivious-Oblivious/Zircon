%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string.h"
#include "hashmap.h"

/* Parser definitions */
int yylex(void);
void yyerror(char*);

/* Result of the parsed file */
string *translation;

/* Hashmaps containing special identifiers */
hashmap *typedef_names;
hashmap *enum_constants;

%}

%union {
    string *String;
}

%token OBJECT MODEL PROTOCOL INIT DEFER FIELDS IMPLEMENTS SELF SUPER MESSAGE SUPERMESSAGE

%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT FOR GOTO IF INT LONG REGISTER RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE
%token BOOL COMPLEX IMAGINARY INLINE RESTRICT
%token ALIGNAS ALIGNOF ATOMIC GENERIC NORETURN STATIC_ASSERT THREAD_LOCAL

%token SEND

%token INCR DECR
%token EQ NOT_EQ GREATER_EQ LESS_EQ
%token AND OR
%token SHIFT_LEFT SHIFT_RIGHT
%token ADD_EQ SUB_EQ MUL_EQ DIV_EQ MOD_EQ SHIFT_LEFT_EQ SHIFT_RIGHT_EQ AND_EQ XOR_EQ OR_EQ
%token ACCESS
%token VARIABLE_ARGUMENTS

%token DEFINE INCLUDE IFDEF UNDEF IFNDEF PRE_IF PRE_ELIF PRE_ELSE ENDIF ERROR WARNING PRAGMA LINE DEFINED PRE_CONC

%token TYPEDEF_NAME INT_CONSTANT FLOAT_CONSTANT ENUMERATION_CONSTANT
%token IDENTIFIER STRING FUNC_NAME HEADER
%type<String> TYPEDEF_NAME INT_CONSTANT FLOAT_CONSTANT ENUMERATION_CONSTANT
%type<String> IDENTIFIER STRING FUNC_NAME HEADER

%type<String> primary_expression constant enumeration_constant string generic_selection generic_assoc_list generic_association
%type<String> postfix_expression argument_expression_list unary_expression unary_operator cast_expression multiplicative_expression
%type<String> additive_expression shift_expression relational_expression equality_expression and_expression exclusive_or_expression
%type<String> inclusive_or_expression logical_and_expression logical_or_expression conditional_expression assignment_expression
%type<String> assignment_operator expression constant_expression declaration declaration_specifiers init_declarator_list init_declarator
%type<String> storage_class_specifier type_specifier struct_or_union_specifier struct_or_union struct_declaration_list struct_declaration
%type<String> specifier_qualifier_list struct_declarator_list struct_declarator enum_specifier enumerator_list enumerator atomic_type_specifier
%type<String> type_qualifier function_specifier alignment_specifier declarator direct_declarator pointer type_qualifier_list parameter_type_list
%type<String> parameter_list parameter_declaration identifier_list type_name abstract_declarator direct_abstract_declarator initializer
%type<String> initializer_list designation designator_list designator static_assert_declaration statement labeled_statement compound_statement
%type<String> block_item_list block_item expression_statement selection_statement iteration_statement jump_statement translation_unit
%type<String> external_declaration function_definition declaration_list

%type<String> object_specifier

%type<String> preprocessor_directive preprocessor_control_line preprocessor_constant_expression preprocessor_conditional
%type<String> preprocessor_if_part preprocessor_elif_parts preprocessor_else_part preprocessor_if_line preprocessor_elif_line preprocessor_else_line

%start translation_unit
%%

primary_expression:
      IDENTIFIER {
        $$ = string_dup($1);
    }
    | constant {
        $$ = string_dup($1);
    }
    | string {
        $$ = string_dup($1);
    }
    | '(' expression ')' {
        $$ = new_string("(");
        string_add_str($$, string_get($2));
        string_add_char($$, ')');
    }
    | generic_selection  {
        $$ = string_dup($1);
    }
    ;

constant:
      INT_CONSTANT {
        $$ = string_dup($1);
    }
    | FLOAT_CONSTANT {
        $$ = string_dup($1);
    }
    | ENUMERATION_CONSTANT {
        $$ = string_dup($1);
    }
    ;

enumeration_constant:
      IDENTIFIER {
          $$ = string_dup($1);
          /****/
          /* if(hashmap_get(enum_constants, string_get($1)) == NULL)
              hashmap_add(enum_constants, string_get($1), $1); */
    }
    ;

string:
      STRING {
        $$ = string_dup($1);
    }
    | FUNC_NAME {
        $$ = string_dup($1);
    }
    ;

generic_selection:
      GENERIC '(' assignment_expression ',' generic_assoc_list ')' {
        $$ = new_string("_Generic(");
        string_add_str($$, string_get($3));
        string_add_char($$, ',');
        string_add_str($$, string_get($5));
        string_add_char($$, ')');
    }
    ;

generic_assoc_list:
      generic_association {
        $$ = string_dup($1);
    }
    | generic_assoc_list ',' generic_association {
        $$ = string_dup($1);
        string_add_char($$, ',');
        string_add_str($$, string_get($3));
    }
    ;

generic_association:
      type_name ':' assignment_expression {
        $$ = string_dup($1);
        string_add_str($$, ": ");
        string_add_str($$, string_get($3));
    }
    | DEFAULT ':' assignment_expression {
        $$ = new_string("default: ");
        string_add_str($$, string_get($3));
    }
    ;

postfix_expression:
      primary_expression {
        $$ = string_dup($1);
    }
    | postfix_expression '[' expression ']' {
        $$ = string_dup($1);
        string_add_char($$, '[');
        string_add_str($$, string_get($3));
        string_add_char($$, ']');
    }
    | postfix_expression '(' ')' {
        $$ = string_dup($1);
        string_add_str($$, "()");
    }
    | postfix_expression '(' argument_expression_list ')' {
        $$ = string_dup($1);
        string_add_char($$, '(');
        string_add_str($$, string_get($3));
        string_add_char($$, ')');
    }
    | postfix_expression '.' IDENTIFIER {
        $$ = string_dup($1);
        string_add_char($$, '.');
        string_add_str($$, string_get($3));
    }
    | postfix_expression ACCESS IDENTIFIER {
        $$ = string_dup($1);
        string_add_str($$, "->");
        string_add_str($$, string_get($3));
    }
    | postfix_expression INCR {
        $$ = string_dup($1);
        string_add_str($$, "++");
    }
    | postfix_expression DECR {
        $$ = string_dup($1);
        string_add_str($$, "--");
    }
    | '(' type_name ')' '{' initializer_list '}' {
        $$ = new_string("(");
        string_add_str($$, string_get($2));
        string_add_str($$, ") {\n");
        string_add_str($$, string_get($5));
        string_add_str($$, "\n}\n");
    }
    | '(' type_name ')' '{' initializer_list ',' '}' {
        $$ = new_string("(");
        string_add_str($$, string_get($2));
        string_add_str($$, ") {\n");
        string_add_str($$, string_get($5));
        string_add_str($$, ",\n}\n");
    }
    ;

argument_expression_list:
      assignment_expression {
        $$ = string_dup($1);
    }
    | argument_expression_list ',' assignment_expression {
        $$ = string_dup($1);
        string_add_char($$, ',');
        string_add_str($$, string_get($3));
    }
    ;

unary_expression:
      postfix_expression {
        $$ = string_dup($1);
    }
    | INCR unary_expression {
        $$ = new_string("++");
        string_add_str($$, string_get($2));
    }
    | DECR unary_expression {
        $$ = new_string("--");
        string_add_str($$, string_get($2));
    }
    | unary_operator cast_expression {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    | SIZEOF unary_expression {
        $$ = new_string("sizeof ");
        string_add_str($$, string_get($2));
    }
    | SIZEOF '(' type_name ')' {
        $$ = new_string("sizeof(");
        string_add_str($$, string_get($3));
        string_add_char($$, ')');
    }
    | ALIGNOF '(' type_name ')' {
        $$ = new_string("_Alignof(");
        string_add_str($$, string_get($3));
        string_add_char($$, ')');
    }
    ;

unary_operator:
      '&' {
        $$ = new_string("&");
    }
    | '*' {
        $$ = new_string("*");
    }
    | '+' {
        $$ = new_string("+");
    }
    | '-' {
        $$ = new_string("-");
    }
    | '~' {
        $$ = new_string("~");
    }
    | '!' {
        $$ = new_string("!");
    }
    ;

cast_expression:
      unary_expression {
        $$ = string_dup($1);
    }
    | '(' type_name ')' cast_expression {
        $$ = new_string("(");
        string_add_str($$, string_get($2));
        string_add_char($$, ')');
        string_add_str($$, string_get($4));
    }
    ;

multiplicative_expression:
      cast_expression {
        $$ = string_dup($1);
    }
    | multiplicative_expression '*' cast_expression {
        $$ = string_dup($1);
        string_add_str($$, " * ");
        string_add_str($$, string_get($3));
    }
    | multiplicative_expression '/' cast_expression {
        $$ = string_dup($1);
        string_add_str($$, " / ");
        string_add_str($$, string_get($3));
    }
    | multiplicative_expression '%' cast_expression {
        $$ = string_dup($1);
        string_add_str($$, " % ");
        string_add_str($$, string_get($3));
    }
    ;

additive_expression:
      multiplicative_expression {
        $$ = string_dup($1);
    }
    | additive_expression '+' multiplicative_expression {
        $$ = string_dup($1);
        string_add_str($$, " + ");
        string_add_str($$, string_get($3));
    }
    | additive_expression '-' multiplicative_expression {
        $$ = string_dup($1);
        string_add_str($$, " - ");
        string_add_str($$, string_get($3));
    }
    ;

shift_expression:
      additive_expression {
        $$ = string_dup($1);
    }
    | shift_expression SHIFT_LEFT additive_expression {
        $$ = string_dup($1);
        string_add_str($$, " << ");
        string_add_str($$, string_get($3));
    }
    | shift_expression SHIFT_RIGHT additive_expression {
        $$ = string_dup($1);
        string_add_str($$, " >> ");
        string_add_str($$, string_get($3));
    }
    ;

relational_expression:
      shift_expression {
        $$ = string_dup($1);
    }
    | relational_expression '<' shift_expression {
        $$ = string_dup($1);
        string_add_str($$, " < ");
        string_add_str($$, string_get($3));
    }
    | relational_expression '>' shift_expression {
        $$ = string_dup($1);
        string_add_str($$, " > ");
        string_add_str($$, string_get($3));
    }
    | relational_expression LESS_EQ shift_expression {
        $$ = string_dup($1);
        string_add_str($$, " <= ");
        string_add_str($$, string_get($3));
    }
    | relational_expression GREATER_EQ shift_expression {
        $$ = string_dup($1);
        string_add_str($$, " >= ");
        string_add_str($$, string_get($3));
    }
    ;

equality_expression:
      relational_expression {
        $$ = string_dup($1);
    }
    | equality_expression EQ relational_expression {
        $$ = string_dup($1);
        string_add_str($$, " == ");
        string_add_str($$, string_get($3));
    }
    | equality_expression NOT_EQ relational_expression {
        $$ = string_dup($1);
        string_add_str($$, " != ");
        string_add_str($$, string_get($3));
    }
    ;

and_expression:
      equality_expression {
        $$ = string_dup($1);
    }
    | and_expression '&' equality_expression {
        $$ = string_dup($1);
        string_add_str($$, " & ");
        string_add_str($$, string_get($3));
    }
    ;

exclusive_or_expression:
      and_expression {
        $$ = string_dup($1);
    }
    | exclusive_or_expression '^' and_expression {
        $$ = string_dup($1);
        string_add_str($$, " ^ ");
        string_add_str($$, string_get($3));
    }
    ;

inclusive_or_expression:
      exclusive_or_expression {
        $$ = string_dup($1);
    }
    | inclusive_or_expression '|' exclusive_or_expression {
        $$ = string_dup($1);
        string_add_str($$, " | ");
        string_add_str($$, string_get($3));
    }
    ;

logical_and_expression:
      inclusive_or_expression {
        $$ = string_dup($1);
    }
    | logical_and_expression AND inclusive_or_expression {
        $$ = string_dup($1);
        string_add_str($$, " && ");
        string_add_str($$, string_get($3));
    }
    ;

logical_or_expression:
      logical_and_expression {
        $$ = string_dup($1);
    }
    | logical_or_expression OR logical_and_expression {
        $$ = string_dup($1);
        string_add_str($$, " || ");
        string_add_str($$, string_get($3));
    }
    ;

conditional_expression:
      logical_or_expression {
        $$ = string_dup($1);
    }
    | logical_or_expression '?' expression ':' conditional_expression {
        $$ = string_dup($1);
        string_add_str($$, " ? ");
        string_add_str($$, string_get($3));
        string_add_str($$, " : ");
        string_add_str($$, string_get($5));
    }
    ;

assignment_expression:
      conditional_expression {
        $$ = string_dup($1);
    }
    | unary_expression assignment_operator assignment_expression {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
        string_add_str($$, string_get($3));
    }
    ;

assignment_operator:
      '=' {
        $$ = new_string("=");
    }
    | MUL_EQ {
        $$ = new_string("*=");
    }
    | DIV_EQ {
        $$ = new_string("/=");
    }
    | MOD_EQ {
        $$ = new_string("%=");
    }
    | ADD_EQ {
        $$ = new_string("+=");
    }
    | SUB_EQ {
        $$ = new_string("-=");
    }
    | SHIFT_LEFT_EQ {
        $$ = new_string("<<=");
    }
    | SHIFT_RIGHT_EQ {
        $$ = new_string(">>=");
    }
    | AND_EQ {
        $$ = new_string("&=");
    }
    | XOR_EQ {
        $$ = new_string("^=");
    }
    | OR_EQ {
        $$ = new_string("|=");
    }
    ;

expression:
      assignment_expression {
        $$ = string_dup($1);
    }
    | expression ',' assignment_expression
    ;

constant_expression:
      conditional_expression {
        $$ = string_dup($1);
    }
    ;

declaration:
      declaration_specifiers ';' {
        $$ = string_dup($1);
        string_add_str($$, ";\n");
    }
    | declaration_specifiers init_declarator_list ';' {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
        string_add_str($$, ";\n");
    }
    | static_assert_declaration {
        $$ = string_dup($1);
    }
    ;

declaration_specifiers:
      storage_class_specifier declaration_specifiers {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    | storage_class_specifier {
        $$ = string_dup($1);
    }
    | type_specifier declaration_specifiers {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    | type_specifier {
        $$ = string_dup($1);
    }
    | type_qualifier declaration_specifiers {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    | type_qualifier {
        $$ = string_dup($1);
    }
    | function_specifier declaration_specifiers {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    | function_specifier {
        $$ = string_dup($1);
    }
    | alignment_specifier declaration_specifiers {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    | alignment_specifier {
        $$ = string_dup($1);
    }
    ;

init_declarator_list:
      init_declarator {
        $$ = string_dup($1);
    }
    | init_declarator_list ',' init_declarator {
        $$ = string_dup($1);
        string_add_char($$, ',');
        string_add_str($$, string_get($3));
    }
    ;

init_declarator:
      declarator '=' initializer {
        $$ = string_dup($1);
        string_add_str($$, " = ");
        string_add_str($$, string_get($3));
    }
    | declarator {
        $$ = string_dup($1);
    }
    ;

storage_class_specifier:
      TYPEDEF {
        $$ = new_string("typedef ");
    }
    | EXTERN {
        $$ = new_string("extern ");
    }
    | STATIC {
        $$ = new_string("static ");
    }
    | THREAD_LOCAL {
        $$ = new_string("_Thread_local ");
    }
    | AUTO {
        $$ = new_string("auto ");
    }
    | REGISTER {
        $$ = new_string("register ");
    }
    ;

type_specifier:
      VOID {
        $$ = new_string("void ");
    }
    | CHAR {
        $$ = new_string("char ");
    }
    | SHORT {
        $$ = new_string("short ");
    }
    | INT {
        $$ = new_string("int ");
    }
    | LONG {
        $$ = new_string("long ");
    }
    | FLOAT {
        $$ = new_string("float ");
    }
    | DOUBLE {
        $$ = new_string("double ");
    }
    | SIGNED {
        $$ = new_string("signed ");
    }
    | UNSIGNED {
        $$ = new_string("unsigned ");
    }
    | BOOL {
        $$ = new_string("_Bool ");
    }
    | COMPLEX {
        $$ = new_string("_Complex ");
    }
    | IMAGINARY {
        $$ = new_string("_Imaginary ");
    }
    | atomic_type_specifier {
        $$ = string_dup($1);
    }
    | struct_or_union_specifier {
        $$ = string_dup($1);
    }
    | enum_specifier {
        $$ = string_dup($1);
    }
    | object_specifier {
        $$ = string_dup($1);
    }
    | TYPEDEF_NAME { /* after defined as a typedef_name */
        $$ = string_dup($1);
    }
    ;

object_specifier:
      object_keyword {}
    ;

struct_or_union_specifier:
      struct_or_union '{' struct_declaration_list '}' {
        $$ = string_dup($1);
        string_add_str($$, " {\n");
        string_add_str($$, string_get($3));
        string_add_str($$, "\n}\n");
    }
    | struct_or_union IDENTIFIER '{' struct_declaration_list '}' {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
        string_add_str($$, " {\n");
        string_add_str($$, string_get($4));
        string_add_str($$, "\n}\n");
        /****/
        if(hashmap_get(typedef_names, string_get($2)) == NULL)
            hashmap_add(typedef_names, string_get($2), $2);
    }
    | struct_or_union IDENTIFIER {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
        /****/
        if(hashmap_get(typedef_names, string_get($2)) == NULL)
            hashmap_add(typedef_names, string_get($2), $2);
    }
    ;

struct_or_union:
      STRUCT {
        $$ = new_string("struct ");
    }
    | UNION {
        $$ = new_string("union ");
    }
    ;

struct_declaration_list:
      struct_declaration {
        $$ = string_dup($1);
    }
    | struct_declaration_list struct_declaration {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    ;

struct_declaration:
      specifier_qualifier_list ';' {
        $$ = string_dup($1);
        string_add_str($$, ";\n");
    }
    | specifier_qualifier_list struct_declarator_list ';' {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
        string_add_str($$, ";\n");
    }
    | static_assert_declaration {
        $$ = string_dup($1);
    }
    ;

specifier_qualifier_list:
      type_specifier specifier_qualifier_list {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    | type_specifier {
        $$ = string_dup($1);
    }
    | type_qualifier specifier_qualifier_list {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    | type_qualifier {
        $$ = string_dup($1);
    }
    ;

struct_declarator_list:
      struct_declarator {
        $$ = string_dup($1);
    }
    | struct_declarator_list ',' struct_declarator {
        $$ = string_dup($1);
        string_add_str($$, ", ");
        string_add_str($$, string_get($3));
    }
    ;

struct_declarator:
      ':' constant_expression {
        $$ = new_string(":");
        string_add_str($$, string_get($2));
    }
    | declarator ':' constant_expression {
        $$ = string_dup($1);
        string_add_char($$, ':');
        string_add_str($$, string_get($3));
    }
    | declarator {
        $$ = string_dup($1);
    }
    ;

enum_specifier:
      ENUM '{' enumerator_list '}' {
        $$ = new_string("enum ");
        string_add_str($$, " {\n");
        string_add_str($$, string_get($3));
        string_add_str($$, "\n}\n");
    }
    | ENUM '{' enumerator_list ',' '}' {
        $$ = new_string("enum ");
        string_add_str($$, " {\n");
        string_add_str($$, string_get($3));
        string_add_str($$, ",\n}\n");
    }
    | ENUM IDENTIFIER '{' enumerator_list '}' {
        $$ = new_string("enum ");
        string_add_str($$, string_get($2));
        string_add_str($$, " {\n");
        string_add_str($$, string_get($4));
        string_add_str($$, "\n}\n");
        /****/
        if(hashmap_get(typedef_names, string_get($2)) == NULL)
            hashmap_add(typedef_names, string_get($2), $2);
    }
    | ENUM IDENTIFIER '{' enumerator_list ',' '}' {
        $$ = new_string("enum ");
        string_add_str($$, string_get($2));
        string_add_str($$, " {\n");
        string_add_str($$, string_get($4));
        string_add_str($$, ",\n}\n");
        /****/
        if(hashmap_get(typedef_names, string_get($2)) == NULL)
            hashmap_add(typedef_names, string_get($2), $2);
    }
    | ENUM IDENTIFIER {
        $$ = new_string("enum ");
        string_add_str($$, string_get($2));
        /****/
        if(hashmap_get(typedef_names, string_get($2)) == NULL)
            hashmap_add(typedef_names, string_get($2), $2);
    }
    ;

enumerator_list:
      enumerator {
        $$ = string_dup($1);
    }
    | enumerator_list ',' enumerator {
        $$ = string_dup($1);
        string_add_str($$, ", ");
        string_add_str($$, string_get($3));
    }
    ;

enumerator:
      enumeration_constant '=' constant_expression {
        $$ = string_dup($1);
        string_add_str($$, " = ");
        string_add_str($$, string_get($3));
    }
    | enumeration_constant {
        $$ = string_dup($1);
    }
    ;

atomic_type_specifier:
      ATOMIC '(' type_name ')' {
        $$ = new_string("_Atomic(");
        string_add_str($$, string_get($3));
        string_add_char($$, ')');
    }
    ;

type_qualifier:
      CONST {
        $$ = new_string("const ");
    }
    | RESTRICT {
        $$ = new_string("restrict ");
    }
    | VOLATILE {
        $$ = new_string("volatile ");
    }
    | ATOMIC {
        $$ = new_string("atomic ");
    }
    ;

function_specifier:
      INLINE {
        $$ = new_string("inline ");
    }
    | NORETURN {
        $$ = new_string("noreturn ");
    }
    ;

alignment_specifier:
      ALIGNAS '(' type_name ')' {
        $$ = new_string("_Alignas(");
        string_add_str($$, string_get($3));
        string_add_char($$, ')');
    }
    | ALIGNAS '(' constant_expression ')' {
        $$ = new_string("_Alignas(");
        string_add_str($$, string_get($3));
        string_add_char($$, ')');
    }
    ;

declarator:
      pointer direct_declarator {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    | direct_declarator {
        $$ = string_dup($1);
    }
    ;

direct_declarator:
      IDENTIFIER {
        $$ = string_dup($1);
    }
    | '(' declarator ')' {
        $$ = new_string("(");
        string_add_str($$, string_get($2));
        string_add_char($$, ')');
    }
    | direct_declarator '[' ']' {
        $$ = string_dup($1);
        string_add_str($$, "[]");
    }
    | direct_declarator '[' '*' ']' {
        $$ = string_dup($1);
        string_add_str($$, "[*]");
    }
    | direct_declarator '[' STATIC type_qualifier_list assignment_expression ']' {
        $$ = string_dup($1);
        string_add_char($$, '[');
        string_add_str($$, "static ");
        string_add_str($$, string_get($4));
        string_add_str($$, string_get($5));
        string_add_char($$, ']');
    }
    | direct_declarator '[' STATIC assignment_expression ']' {
        $$ = string_dup($1);
        string_add_char($$, '[');
        string_add_str($$, "static ");
        string_add_str($$, string_get($4));
        string_add_char($$, ']');
    }
    | direct_declarator '[' type_qualifier_list '*' ']' {
        $$ = string_dup($1);
        string_add_char($$, '[');
        string_add_str($$, string_get($3));
        string_add_str($$, "*]");
    }
    | direct_declarator '[' type_qualifier_list STATIC assignment_expression ']' {
        $$ = string_dup($1);
        string_add_char($$, '[');
        string_add_str($$, string_get($3));
        string_add_str($$, "static ");
        string_add_str($$, string_get($5));
        string_add_char($$, ']');
    }
    | direct_declarator '[' type_qualifier_list assignment_expression ']' {
        $$ = string_dup($1);
        string_add_char($$, '[');
        string_add_str($$, string_get($3));
        string_add_str($$, string_get($4));
        string_add_char($$, ']');
    }
    | direct_declarator '[' type_qualifier_list ']' {
        $$ = string_dup($1);
        string_add_char($$, '[');
        string_add_str($$, string_get($3));
        string_add_char($$, ']');
    }
    | direct_declarator '[' assignment_expression ']' {
        $$ = string_dup($1);
        string_add_char($$, '[');
        string_add_str($$, string_get($3));
        string_add_char($$, ']');
    }
    | direct_declarator '(' parameter_type_list ')' {
        $$ = string_dup($1);
        string_add_char($$, '(');
        string_add_str($$, string_get($3));
        string_add_char($$, ')');
    }
    | direct_declarator '(' ')' {
        $$ = string_dup($1);
        string_add_str($$, "()");
    }
    | direct_declarator '(' identifier_list ')' {
        $$ = string_dup($1);
        string_add_char($$, '(');
        string_add_str($$, string_get($3));
        string_add_char($$, ')');
    }
    ;

pointer:
      '*' type_qualifier_list pointer {
        $$ = new_string("*");
        string_add_str($$, string_get($2));
        string_add_str($$, string_get($3));
    }
    | '*' type_qualifier_list {
        $$ = new_string("*");
        string_add_str($$, string_get($2));
    }
    | '*' pointer {
        $$ = new_string("*");
        string_add_str($$, string_get($2));
    }
    | '*' {
        $$ = new_string("*");
    }
    ;

type_qualifier_list:
      type_qualifier {
        $$ = string_dup($1);
    }
    | type_qualifier_list type_qualifier {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    ;

parameter_type_list:
      parameter_list ',' VARIABLE_ARGUMENTS {
        $$ = string_dup($1);
        string_add_str($$, ", ...");
    }
    | parameter_list {
        $$ = string_dup($1); 
    }
    ;

parameter_list:
      parameter_declaration {
        $$ = string_dup($1);
    }
    | parameter_list ',' parameter_declaration {
        $$ = string_dup($1);
        string_add_str($$, ", ");
        string_add_str($$, string_get($3));
    }
    ;

parameter_declaration:
      declaration_specifiers declarator {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    | declaration_specifiers abstract_declarator {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    | declaration_specifiers {
        $$ = string_dup($1);
    }
    ;

identifier_list:
      IDENTIFIER {
        $$ = string_dup($1);
    }
    | identifier_list ',' IDENTIFIER {
        $$ = string_dup($1);
        string_add_str($$, ", ");
        string_add_str($$, string_get($3));
    }
    ;

type_name:
      specifier_qualifier_list abstract_declarator {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    | specifier_qualifier_list {
        $$ = string_dup($1);
    }
    ;

abstract_declarator:
      pointer direct_abstract_declarator {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    | pointer {
        $$ = string_dup($1);
    }
    | direct_abstract_declarator {
        $$ = string_dup($1);
    }
    ;

direct_abstract_declarator:
      '(' abstract_declarator ')' {
        $$ = new_string("(");
        string_add_str($$, string_get($2));
        string_add_char($$, ')');
    }
    | '[' ']' {
        $$ = new_string("[]");
    }
    | '[' '*' ']' {
        $$ = new_string("[*]");
    }
    | '[' STATIC type_qualifier_list assignment_expression ']' {
        $$ = new_string("[static ");
        string_add_str($$, string_get($3));
        string_add_str($$, string_get($4));
        string_add_char($$, ']');
    }
    | '[' STATIC assignment_expression ']' {
        $$ = new_string("[static ");
        string_add_str($$, string_get($3));
        string_add_char($$, ']');
    }
    | '[' type_qualifier_list STATIC assignment_expression ']' {
        $$ = new_string("[");
        string_add_str($$, string_get($2));
        string_add_str($$, " static ");
        string_add_str($$, string_get($4));
        string_add_char($$, ']');
    }
    | '[' type_qualifier_list assignment_expression ']' {
        $$ = new_string("[");
        string_add_str($$, string_get($2));
        string_add_str($$, string_get($3));
        string_add_char($$, ']');
    }
    | '[' type_qualifier_list ']' {
        $$ = new_string("[");
        string_add_str($$, string_get($2));
        string_add_char($$, ']');
    }
    | '[' assignment_expression ']' {
        $$ = new_string("[");
        string_add_str($$, string_get($2));
        string_add_char($$, ']');
    }
    | direct_abstract_declarator '[' ']' {
        $$ = string_dup($1);
        string_add_str($$, "[]");
    }
    | direct_abstract_declarator '[' '*' ']' {
        $$ = string_dup($1);
        string_add_str($$, "[*]");
    }
    | direct_abstract_declarator '[' STATIC type_qualifier_list assignment_expression ']' {
        $$ = string_dup($1);
        string_add_str($$, "[static ");
        string_add_str($$, string_get($4));
        string_add_str($$, string_get($5));
        string_add_char($$, ']');
    }
    | direct_abstract_declarator '[' STATIC assignment_expression ']' {
        $$ = string_dup($1);
        string_add_str($$, "[static ");
        string_add_str($$, string_get($4));
        string_add_char($$, ']');
    }
    | direct_abstract_declarator '[' type_qualifier_list assignment_expression ']' {
        $$ = string_dup($1);
        string_add_char($$, '[');
        string_add_str($$, string_get($3));
        string_add_str($$, string_get($4));
        string_add_char($$, ']');
    }
    | direct_abstract_declarator '[' type_qualifier_list STATIC assignment_expression ']' {
        $$ = string_dup($1);
        string_add_char($$, '[');
        string_add_str($$, string_get($3));
        string_add_str($$, " static ");
        string_add_str($$, string_get($5));
        string_add_char($$, ']');
    }
    | direct_abstract_declarator '[' type_qualifier_list ']' {
        $$ = string_dup($1);
        string_add_char($$, '[');
        string_add_str($$, string_get($3));
        string_add_char($$, ']');
    }
    | direct_abstract_declarator '[' assignment_expression ']' {
        $$ = string_dup($1);
        string_add_char($$, '[');
        string_add_str($$, string_get($3));
        string_add_char($$, ']');
    }
    | '(' ')' {
        $$ = new_string("()");
    }
    | '(' parameter_type_list ')' {
        $$ = new_string("(");
        string_add_str($$, string_get($2));
        string_add_char($$, ')');
    }
    | direct_abstract_declarator '(' ')' {
        $$ = string_dup($1);
        string_add_str($$, "()");
    }
    | direct_abstract_declarator '(' parameter_type_list ')' {
        $$ = string_dup($1);
        string_add_char($$, '(');
        string_add_str($$, string_get($3));
        string_add_char($$, ')');
    }
    ;

initializer:
      '{' initializer_list '}' {
        $$ = new_string(" {\n");
        string_add_str($$, string_get($2));
        string_add_str($$, "\n}\n");
    }
    | '{' initializer_list  ',' '}' {
        $$ = new_string(" {\n");
        string_add_str($$, string_get($2));
        string_add_str($$, ",\n}\n");
    }
    | assignment_expression {
        $$ = string_dup($1);
    }
    ;

initializer_list:
      designation initializer {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    | initializer {
        $$ = string_dup($1);
    }
    | initializer_list ',' designation initializer {
        $$ = string_dup($1);
        string_add_str($$, ", ");
        string_add_str($$, string_get($3));
    }
    | initializer_list ',' initializer {
        $$ = string_dup($1);
        string_add_str($$, ", ");
        string_add_str($$, string_get($3));
    }
    ;

designation:
      designator_list '=' {
        $$ = string_dup($1);
        string_add_str($$, " = ");
    }
    ;

designator_list:
      designator {
        $$ = string_dup($1);
    }
    | designator_list designator {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    ;

designator:
      '[' constant_expression ']' {
        $$ = new_string("[");
        string_add_str($$, string_get($2));
        string_add_char($$, ']');
    }
    | '.' IDENTIFIER {
        $$ = new_string(".");
        string_add_str($$, string_get($2));
    }
    ;

static_assert_declaration:
      STATIC_ASSERT '(' constant_expression ',' STRING ')' ';' {
        $$ = new_string("_Static_assert(");
        string_add_str($$, string_get($3));
        string_add_str($$, ", ");
        string_add_str($$, string_get($5));
        string_add_str($$, ");\n");
    }
    ;

statement:
      labeled_statement {
        $$ = string_dup($1);
    }
    | compound_statement {
        $$ = string_dup($1);
    }
    | expression_statement {
        $$ = string_dup($1);
    }
    | selection_statement {
        $$ = string_dup($1);
    }
    | iteration_statement {
        $$ = string_dup($1);
    }
    | jump_statement {
        $$ = string_dup($1);
    }
    ;

labeled_statement:
      IDENTIFIER ':' statement {
        $$ = string_dup($1);
        string_add_str($$, ": ");
        string_add_str($$, string_get($3));
        /****/
        if(hashmap_get(typedef_names, string_get($1)) == NULL)
            hashmap_add(typedef_names, string_get($1), $1);
    }
    | CASE constant_expression ':' statement {
        $$ = new_string("case ");
        string_add_str($$, string_get($2));
        string_add_str($$, ": ");
        string_add_str($$, string_get($4));
    }
    | DEFAULT ':' statement {
        $$ = new_string("default: ");
        string_add_str($$, string_get($3));
    }
    ;

compound_statement:
      '{' '}' {
        $$ = new_string("{}\n");
    }
    | '{' block_item_list '}' {
        $$ = new_string(" {\n");
        string_add_str($$, string_get($2));
        string_add_str($$, "\n}\n");
    }
    ;

block_item_list:
      block_item {
        $$ = string_dup($1);
    }
    | block_item_list block_item {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    ;

block_item:
      declaration {
        $$ = string_dup($1);
    }
    | statement {
        $$ = string_dup($1);
    }
    ;

expression_statement:
      ';' {
        $$ = new_string(";\n");
    }
    | expression ';' {
        $$ = string_dup($1);
        string_add_str($$, ";\n"/* TODO CAN REMOVE `\n`*/);
    }
    ;

selection_statement:
      IF '(' expression ')' statement ELSE statement {
        $$ = new_string("if(");
        string_add_str($$, string_get($3));
        string_add_str($$, ") ");
        string_add_str($$, string_get($5));
        string_add_str($$, " else ");
        string_add_str($$, string_get($7));
    }
    | IF '(' expression ')' statement {
        $$ = new_string("if(");
        string_add_str($$, string_get($3));
        string_add_str($$, ") ");
        string_add_str($$, string_get($5));
    }
    | SWITCH '(' expression ')' statement {
        $$ = new_string("switch(");
        string_add_str($$, string_get($3));
        string_add_str($$, ") ");
        string_add_str($$, string_get($5));
    }
    ;

iteration_statement:
      WHILE '(' expression ')' statement {
        $$ = new_string("while(");
        string_add_str($$, string_get($3));
        string_add_str($$, ") ");
        string_add_str($$, string_get($5));
    }
    | DO statement WHILE '(' expression ')' ';' {
        $$ = new_string("do ");
        string_add_str($$, string_get($2));
        string_add_str($$, "while(");
        string_add_str($$, string_get($5));
        string_add_str($$, ");\n");
    }
    | FOR '(' expression_statement expression_statement ')' statement {
        $$ = new_string("for(");
        string_add_str($$, string_get($3));
        string_add_str($$, string_get($4));
        string_add_str($$, ") ");
        string_add_str($$, string_get($6));
    }
    | FOR '(' expression_statement expression_statement expression ')' statement {
        $$ = new_string("for(");
        string_add_str($$, string_get($3));
        string_add_str($$, string_get($4));
        string_add_str($$, string_get($5));
        string_add_str($$, ") ");
        string_add_str($$, string_get($7));
    }
    | FOR '(' declaration expression_statement ')' statement {
        $$ = new_string("for(");
        string_add_str($$, string_get($3));
        string_add_str($$, string_get($4));
        string_add_str($$, ") ");
        string_add_str($$, string_get($6));
    }
    | FOR '(' declaration expression_statement expression ')' statement {
        $$ = new_string("for(");
        string_add_str($$, string_get($3));
        string_add_str($$, string_get($4));
        string_add_str($$, string_get($5));
        string_add_str($$, ") ");
        string_add_str($$, string_get($7));
    }
    ;

jump_statement:
      GOTO IDENTIFIER ';'   {
        $$ = new_string("goto ");
        string_add_str($$, string_get($2));
        string_add_str($$, ";\n");
        /****/
        if(hashmap_get(typedef_names, string_get($2)) == NULL)
            hashmap_add(typedef_names, string_get($2), $2);
    }
    | CONTINUE ';'          {
        $$ = new_string("continue");
        string_add_str($$, ";\n");
    }
    | BREAK ';'             {
        $$ = new_string("break");
        string_add_str($$, ";\n");
    }
    | RETURN ';'            {
        $$ = new_string("return");
        string_add_str($$, ";\n");
    }
    | RETURN expression ';' {
        $$ = new_string("return ");
        string_add_str($$, string_get($2));
        string_add_str($$, ";\n");
    }
    ;

translation_unit:
      external_declaration {
        /* Get the final declaration */
        string_add_str(translation, string_get($1));
    }
    | translation_unit external_declaration {
        /* Get the rest of the declarations */
        string_add_str(translation, string_get($2));
    }
    ;

external_declaration:
      preprocessor_directive {
        $$ = string_dup($1);
    }
    | function_definition {
        $$ = string_dup($1);
    }
    | declaration {
        $$ = string_dup($1);
    }
    ;

function_definition:
      declaration_specifiers declarator declaration_list compound_statement {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
        string_add_str($$, string_get($3));
        string_add_str($$, string_get($4));
    }
    | declaration_specifiers declarator compound_statement {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
        string_add_str($$, string_get($3));
    }
    ;

declaration_list:
      declaration {
        $$ = string_dup($1);
    }
    | declaration_list declaration {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
    }
    ;

preprocessor_directive:
      preprocessor_conditional {
        $$ = string_dup($1);
    }
    | preprocessor_control_line {
        $$ = string_dup($1);
    }
    | preprocessor_constant_expression {
        $$ = string_dup($1);
    }
    ;

preprocessor_control_line:
      DEFINE IDENTIFIER STRING {
        $$ = new_string("\n#define ");
        string_add_str($$, string_get($2));
        string_add_char($$, ' ');
        string_add_str($$, string_get($3));
        string_add_char($$, ' ');
    }
    | DEFINE IDENTIFIER {
        $$ = new_string("\n#define ");
        string_add_str($$, string_get($2));
        string_add_char($$, ' ');
    }
    | DEFINE IDENTIFIER declaration_list STRING {
        $$ = new_string("\n#define ");
        string_add_str($$, string_get($2));
        string_add_char($$, ' ');
        string_add_str($$, string_get($3));
        string_add_char($$, ' ');
        string_add_str($$, string_get($4));
        string_add_char($$, ' ');
    }
    | DEFINE IDENTIFIER declaration_list {
        $$ = new_string("\n#define ");
        string_add_str($$, string_get($2));
        string_add_char($$, ' ');
        string_add_str($$, string_get($3));
        string_add_char($$, ' ');
    }
    | INCLUDE '<' HEADER '>' {
        $$ = new_string("\n#include <");
        string_add_str($$, string_get($3));
        string_add_str($$, ">\n");
    }
    | INCLUDE STRING {
        $$ = new_string("\n#include ");
        string_add_str($$, string_get($2));
        string_add_char($$, '\n');
        /* Newline is added on the string */
    }
    | LINE INT_CONSTANT {
        $$ = new_string("\n#line ");
        string_add_str($$, string_get($2));
    }
    | LINE INT_CONSTANT HEADER {
        $$ = new_string("\n#line ");
        string_add_str($$, string_get($2));
        string_add_char($$, ' ');
        string_add_str($$, string_get($3));
    }
    | UNDEF IDENTIFIER {
        $$ = new_string("\n#undef ");
        string_add_str($$, string_get($2));
    }
    | ERROR STRING {
        $$ = new_string("\n#error ");
        string_add_str($$, string_get($2));
    }
    | WARNING STRING {
        $$ = new_string("\n#warning ");
        string_add_str($$, string_get($2));
    }
    | PRAGMA STRING {
        $$ = new_string("\n#pragma ");
        string_add_str($$, string_get($2));
    }
    ;

preprocessor_constant_expression:
      DEFINED '(' IDENTIFIER ')' {
        $$ = new_string("defined(");
        string_add_str($$, string_get($3));
        string_add_char($$, '\n');
    }
    | DEFINED IDENTIFIER {
        $$ = new_string("defined ");
        string_add_str($$, string_get($2));
        string_add_char($$, '\n');
    }
    | constant_expression {
        $$ = string_dup($1);
        string_add_char($$, '\n');
    }
    ;

preprocessor_conditional:
      preprocessor_if_part ENDIF {
        $$ = string_dup($1);
        string_add_str($$, "\n#endif\n");
    }
    | preprocessor_if_part preprocessor_elif_parts preprocessor_else_part ENDIF {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
        string_add_str($$, string_get($3));
        string_add_str($$, "\n#endif\n");
    }
    | preprocessor_if_part preprocessor_else_part ENDIF {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
        string_add_str($$, "\n#endif\n");
    }
    ;

preprocessor_if_line:
      PRE_IF constant_expression {
        $$ = new_string("\n#if ");
        string_add_str($$, string_get($2));
        string_add_char($$, ' ');
    }
    | IFDEF IDENTIFIER {
        $$ = new_string("\n#ifdef ");
        string_add_str($$, string_get($2));
        string_add_char($$, ' ');
    }
    | IFNDEF IDENTIFIER {
        $$ = new_string("\n#ifndef ");
        string_add_str($$, string_get($2));
        string_add_char($$, ' ');
    }
    ;

preprocessor_elif_line:
      PRE_ELIF constant_expression {
        $$ = new_string("\n#elif ");
        string_add_str($$, string_get($2));
        string_add_char($$, ' ');
    }
    ;

preprocessor_else_line:
      PRE_ELSE {
        $$ = new_string("\n#else\n");
        string_add_char($$, ' ');
    }
    ;

preprocessor_if_part:
      preprocessor_if_line translation_unit {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
        string_add_char($$, '\n');
    }
    ;

preprocessor_elif_parts:
      preprocessor_elif_line translation_unit {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
        string_add_char($$, '\n');
    }
    | preprocessor_elif_parts preprocessor_elif_line translation_unit {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
        string_add_str($$, string_get($3));
        string_add_char($$, '\n');
    }
    ;

preprocessor_else_part:
      preprocessor_else_line translation_unit {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
        string_add_char($$, '\n');
    }
    ;

%%

extern FILE *yyin;

#define warning(s, t) do { \
    fprintf(stderr, "%s\n", s); \
    if(t) fprintf(stderr, "%s\n", t); \
} while(0);

void yyerror(char *s) {
    fflush(stdout);
    warning(s, (char*)0);
    yyparse();
}

int main(int argc, char **argv) {
    assert(argc == 2 && argv && argv[1]);

    yyin = fopen(argv[1], "r");
    translation = new_string("");
    typedef_names = new_hashmap();

    yyparse();
    
    /*********************************/
    FILE *fp = fopen("out.c", "w");
    fprintf(fp, "%s", string_get(translation));
    fclose(fp);
    /*********************************/
}
