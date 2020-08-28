%{

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

/* Hashmaps containing special identifiers */
hashmap *typedef_names;
hashmap *object_names;
hashmap *enum_constants;

/****/
hashmap *models;
hashmap *protocols;
hashmap *objects;
/****/

vector *init_nodes;
string *main_parameters;

%}

%union {
    string *String;
    vector *Vector;
}

%token OBJECT MODEL PROTOCOL INIT DEFER FIELDS IMPLEMENTS MESSAGE SUPERMESSAGE IMPORT

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

%type<String> model protocol object object_specifier self_or_super declaration_specifiers_or_pointer

%type<Vector> abstract_message_declaration_list abstract_message_declaration model_declaration_list model_declaration
%type<Vector> constructor_declaration destructor_declaration message_declaration_list message_declaration
%type<Vector> object_declaration_list object_declaration fields_declaration

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
    | postfix_expression STRING argument_expression_list {
        /* TODO -> ADDED HERE */
        $$ = new_string("");

        /* Remove quotations */
        string_skip($2, 1);
        string_shorten($2, string_length($2) - 2);

        string_add_str($$, string_get($2));
        string_add_char($$, '(');
        string_add_str($$, string_get($1));
        string_add_str($$, ", ");
        string_add_str($$, string_get($3));
        string_add_char($$, ')');
    }
    | postfix_expression STRING {
        /* TODO -> ADDED HERE */
        $$ = new_string("");

        /* Remove quotations */
        string_skip($2, 1);
        string_shorten($2, string_length($2) - 1);

        string_add_str($$, string_get($2));
        string_add_char($$, '(');
        string_add_str($$, string_get($1));
        string_add_char($$, ')');
    }
    | TYPEDEF_NAME STRING argument_expression_list {
        /* TODO -> ADDED HERE */
        $$ = new_string("");
        
        /* Remove quotations */
        string_skip($2, 1);
        string_shorten($2, string_length($2) - 2);

        string_add_str($$, string_get($2));
        string_add_char($$, '(');
        string_add_str($$, string_get($1));
        string_add_str($$, ", ");
        string_add_str($$, string_get($3));
        string_add_char($$, ')');
    }
    | TYPEDEF_NAME STRING {
        /* TODO -> ADDED HERE */
        $$ = new_string("");

        /* Remove quotations */
        string_skip($2, 1);
        string_shorten($2, string_length($2) - 1);

        string_add_str($$, string_get($2));
        string_add_char($$, '(');
        string_add_str($$, string_get($1));
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
        string_add_char($$, ' ');
    }
    | struct_or_union_specifier {
        $$ = string_dup($1);
        string_add_char($$, ' ');
    }
    | enum_specifier {
        $$ = string_dup($1);
        string_add_char($$, ' ');
    }
    | TYPEDEF_NAME { /* after defined as a typedef_name */
        /* TODO -> ADDED HERE */
        // $$ = string_dup($1);
        $$ = new_string("struct ");
        string_add_str($$, string_get($1));
        string_add_char($$, ' ');
    }
    ;

object_specifier:
      model IDENTIFIER '{' model_declaration_list '}' {
        $$ = new_string("");

        hashmap *model_fields = new_hashmap();
        int i;
        for(i = 0; i < vector_length($4); i++) {
            vector *current = vector_get($4, i);
            /* And a hashmap entry with the variable name and
                store the vector that describes the variable */
            hashmap_add(model_fields, string_get(vector_get(current, 1)), current);
        }
        hashmap_add(models, string_get($2), model_fields);
        if(hashmap_get(typedef_names, string_get($2)) == NULL)
            hashmap_add(typedef_names, string_get(string_dup($2)), (void*)true);
        if(hashmap_get(object_names, string_get($2)) == NULL)
            hashmap_add(object_names, string_get(string_dup($2)), (void*)true);
    }
    | protocol IDENTIFIER IMPLEMENTS TYPEDEF_NAME '{' abstract_message_declaration_list '}' {
        $$ = new_string("");

        /* contains (superclass): string, and (messages): vector */
        vector *protocol_entry = new_vector();
        vector_add(protocol_entry, $4);

        hashmap *protocol_messages = new_hashmap();
        int i;
        for(i = 0; i < vector_length($6); i++) {
            vector *current = vector_get($6, i);
            /* Add a hashmap entry with the messsage name and 
                store the vector that describes the message */
            hashmap_add(protocol_messages, string_get(vector_get(current, 2)), current);
        }
        vector_add(protocol_entry, protocol_messages);

        hashmap_add(protocols, string_get($2), protocol_entry);
        if(hashmap_get(typedef_names, string_get($2)) == NULL)
            hashmap_add(typedef_names, string_get(string_dup($2)), (void*)true);
        if(hashmap_get(object_names, string_get($2)) == NULL)
            hashmap_add(object_names, string_get(string_dup($2)), (void*)true);
    }
    | object IDENTIFIER IMPLEMENTS TYPEDEF_NAME '{' object_declaration_list '}' {
        $$ = new_string("");

        vector *object_entry = new_vector();
        hashmap *object_fields = new_hashmap();
        hashmap *object_messages = new_hashmap();

        /*******/
        vector *object_declaration_fields = vector_get($6, 0);
        vector *object_declaration_messages = vector_get($6, 1);
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

        vector_add(object_entry, $4); /* name */
        vector *object_entry_data = new_vector();
        vector_add(object_entry_data, object_fields);
        vector_add(object_entry_data, new_string(""));
        vector_add(object_entry_data, object_messages);
        vector_add(object_entry, object_entry_data); /* the 3 hashmaps */

        hashmap_add(objects, string_get($2), object_entry);
        if(hashmap_get(typedef_names, string_get($2)) == NULL)
            hashmap_add(typedef_names, string_get(string_dup($2)), (void*)true);
        if(hashmap_get(object_names, string_get($2)) == NULL)
            hashmap_add(object_names, string_get(string_dup($2)), (void*)true);
    }
    | object IDENTIFIER IMPLEMENTS TYPEDEF_NAME '(' parameter_type_list ')' '{' object_declaration_list '}' {
        /* TODO -> USE STACK TO SAVE OBJECT NAMES */
        $$ = new_string("");

        vector *object_entry = new_vector();
        hashmap *object_fields = new_hashmap();
        hashmap *object_messages = new_hashmap();

        /*******/
        vector *object_declaration_fields = vector_get($9, 0);
        vector *object_declaration_messages = vector_get($9, 1);
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

        vector_add(object_entry, $4); /* super */
        vector *object_entry_data = new_vector();
        vector_add(object_entry_data, object_fields);
        vector_add(object_entry_data, $6);
        vector_add(object_entry_data, object_messages);
        vector_add(object_entry, object_entry_data); /* the 3 hashmaps */

        hashmap_add(objects, string_get($2), object_entry);
        if(hashmap_get(typedef_names, string_get($2)) == NULL)
            hashmap_add(typedef_names, string_get(string_dup($2)), (void*)true);
        if(hashmap_get(object_names, string_get($2)) == NULL)
            hashmap_add(object_names, string_get(string_dup($2)), (void*)true);
    }
    ;

object_declaration_list:
      object_declaration {
        $$ = vector_dup($1);
    }
    | object_declaration_list object_declaration {
        $$ = vector_dup($1);
        vector_add($$, $2);
    }
    ;

object_declaration:
      fields_declaration {
        $$ = vector_dup($1);
    }
    | message_declaration_list {
        $$ = vector_dup($1);
    }
    ;

fields_declaration:
      FIELDS '{' '}' {
        $$ = new_vector();
        vector_add($$, new_vector());
    }
    | FIELDS '{' IMPLEMENTS TYPEDEF_NAME ';' '}' {
        /* TODO -> ADDED HERE */
        $$ = new_vector();
        vector *current_fields = new_vector();

        hashmap *current_model = hashmap_get(models, string_get($4));
        int i;
        for(i = 0; i < current_model->alloced; i++)
            if(current_model->data[i].in_use != 0)
                vector_add(current_fields, current_model->data[i].data);
        
        vector_add($$, current_fields);
    }
    | FIELDS '{' IMPLEMENTS TYPEDEF_NAME ';' model_declaration_list '}' {
        /* TODO -> ADDED HERE */
        $$ = new_vector();

        hashmap *current_model = hashmap_get(models, string_get($4));
        int i;
        for(i = 0; i < current_model->alloced; i++)
            if(current_model->data[i].in_use != 0) {
                vector_add($6, current_model->data[i].data);
            }
        
        vector_add($$, $6);
    }
    | FIELDS '{' model_declaration_list '}' {
        $$ = new_vector();
        vector_add($$, $3);
    }
    ;

abstract_message_declaration_list:
      abstract_message_declaration {
        $$ = new_vector();
        vector_add($$, $1);
    }
    | abstract_message_declaration_list abstract_message_declaration {
        $$ = new_vector();
        int i;
        for(i = 0; i < vector_length($1); i++)
            vector_add($$, vector_get($1, i));
        vector_add($$, $2);
    }
    ;

abstract_message_declaration:
      '(' declaration_specifiers_or_pointer ')' self_or_super SEND STRING ';' {
        $$ = new_vector();
        vector_add($$, $2); /* return value */
        vector_add($$, $4); /* sender */
        vector_add($$, $6); /* name */
        vector_add($$, new_string("")); /* parameter entries */
        vector_add($$, new_string("")); /* method block */
    }
    | '(' declaration_specifiers_or_pointer ')' self_or_super SEND STRING SEND parameter_type_list ';' {
        $$ = new_vector();
        vector_add($$, $2); /* return value */
        vector_add($$, $4); /* sender */
        vector_add($$, $6); /* name */
        vector_add($$, $8); /* parameter entries */
        vector_add($$, new_string("")); /* method block */
    }

message_declaration_list:
      message_declaration {
        $$ = new_vector();
        vector_add($$, $1);
    }
    | message_declaration_list message_declaration {
        $$ = new_vector();
        int i;
        for(i = 0; i < vector_length($1); i++)
            vector_add($$, vector_get($1, i));
        vector_add($$, $2);
    }
    ;

message_declaration:
      '(' declaration_specifiers_or_pointer ')' self_or_super SEND STRING SEND compound_statement {
        $$ = new_vector();
        vector_add($$, $2); /* return value */
        vector_add($$, $4); /* sender */
        vector_add($$, $6); /* name */
        vector_add($$, new_vector()); /* variable entries */
        vector_add($$, $8); /* method block */
    }
    | '(' declaration_specifiers_or_pointer ')' self_or_super SEND STRING SEND block_item {
        $$ = new_vector();
        vector_add($$, $2); /* return vaule */
        vector_add($$, $4); /* sender */
        vector_add($$, $6); /* name */
        vector_add($$, new_vector()); /* variable entries */
        vector_add($$, $8); /* method block */
    }
    | '(' declaration_specifiers_or_pointer ')' self_or_super SEND STRING SEND parameter_type_list SEND compound_statement {
        $$ = new_vector();
        vector_add($$, $2); /* return value */
        vector_add($$, $4); /* sender */
        vector_add($$, $6); /* name */
        vector_add($$, $8); /* variable entries */
        vector_add($$, $10); /* method block */
    }
    | '(' declaration_specifiers_or_pointer ')' self_or_super SEND STRING SEND parameter_type_list SEND block_item {
        $$ = new_vector();
        vector_add($$, $2); /* return value */
        vector_add($$, $4); /* sender */
        vector_add($$, $6); /* name */
        vector_add($$, $8); /* variable entries */
        vector_add($$, $10); /* method block */
    }
    | MESSAGE STRING SEND compound_statement {
        $$ = new_vector();
        vector_add($$, new_string("")); /* return value */
        vector_add($$, new_string("self")); /* sender */
        vector_add($$, $2); /* name */
        vector_add($$, new_vector()); /* variable entries */
        vector_add($$, $4); /* method block */
    }
    | MESSAGE STRING SEND block_item {
        $$ = new_vector();
        vector_add($$, new_string("")); /* return value */
        vector_add($$, new_string("self")); /* sender */
        vector_add($$, $2); /* name */
        vector_add($$, new_vector()); /* variable entries */
        vector_add($$, $4); /* method block */
    }
    | SUPERMESSAGE STRING SEND compound_statement {
        $$ = new_vector();
        vector_add($$, new_string("")); /* return value */
        vector_add($$, new_string("super")); /* sender */
        vector_add($$, $2); /* name */
        vector_add($$, new_vector()); /* variable entries */
        vector_add($$, $4); /* method block */
    }
    | SUPERMESSAGE STRING SEND block_item {
        $$ = new_vector();
        vector_add($$, new_string("")); /* return value */
        vector_add($$, new_string("super")); /* sender */
        vector_add($$, $2); /* name */
        vector_add($$, new_vector()); /* variable entries */
        vector_add($$, $4); /* method block */
    }
    | constructor_declaration {
        $$ = vector_dup($1);
    }
    | destructor_declaration {
        $$ = vector_dup($1);
    }
    ;

constructor_declaration:
      INIT compound_statement {
        $$ = new_vector();
        vector_add($$, new_string("void")); /* return value */
        vector_add($$, new_string("self")); /* sender */
        vector_add($$, new_string("\"new\"")); /* name */
        vector_add($$, new_string("va_list *app")); /* variable entries */
        vector_add($$, $2); /* method block */
    }
    ;

destructor_declaration:
      DEFER compound_statement {
        $$ = new_vector();
        vector_add($$, new_string("void")); /* return value */
        vector_add($$, new_string("self")); /* sender */
        vector_add($$, new_string("\"defer\"")); /* name */
        vector_add($$, new_string("void")); /* variable entries */
        vector_add($$, $2); /* method block */
    }
    ;

declaration_specifiers_or_pointer:
      declaration_specifiers {
        $$ = string_dup($1);
    }
    | declaration_specifiers '*' {
        $$ = string_dup($1);
        string_add_char($$, '*');
    }
    ;

self_or_super:
      IDENTIFIER {
        if(string_equals($1, new_string("self")))
            $$ = new_string("self ");
        else if(string_equals($1, new_string("super")))
            $$ = new_string("super" );
    }
    ;

model:
      MODEL {
        $$ = new_string("model ");
    }
    ;

protocol:
      PROTOCOL {
        $$ = new_string("protocol ");
    }
    ;

object:
      OBJECT {
        $$ = new_string("object ");
    }
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
            hashmap_add(typedef_names, string_get(string_dup($2)), (void*)true);
    }
    | struct_or_union IDENTIFIER {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
        /****/
        if(hashmap_get(typedef_names, string_get($2)) == NULL)
            hashmap_add(typedef_names, string_get(string_dup($2)), (void*)true);
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

model_declaration_list:
      model_declaration {
        $$ = vector_dup($1);
        vector_add($$, $1); /* Add the first element */
    }
    | model_declaration_list model_declaration {
        $$ = vector_dup($1);
        vector_add($$, $2);
    }
    ;

model_declaration:
      declaration_specifiers_or_pointer struct_declarator_list ';' {
        $$ = new_vector();
        vector_add($$, $1); /* type */
        vector_add($$, $2); /* name */
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
            hashmap_add(typedef_names, string_get(string_dup($2)), (void*)true);
    }
    | ENUM IDENTIFIER '{' enumerator_list ',' '}' {
        $$ = new_string("enum ");
        string_add_str($$, string_get($2));
        string_add_str($$, " {\n");
        string_add_str($$, string_get($4));
        string_add_str($$, ",\n}\n");
        /****/
        if(hashmap_get(typedef_names, string_get($2)) == NULL)
            hashmap_add(typedef_names, string_get(string_dup($2)), (void*)true);
    }
    | ENUM IDENTIFIER {
        $$ = new_string("enum ");
        string_add_str($$, string_get($2));
        /****/
        if(hashmap_get(typedef_names, string_get($2)) == NULL)
            hashmap_add(typedef_names, string_get(string_dup($2)), (void*)true);
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
      '(' declaration_specifiers_or_pointer ')' ':' declarator {
        /* TODO -> ADDED HERE */
        $$ = new_string("(");
        string_add_str($$, string_get($2));
        string_add_str($$, "): ");
        string_add_str($$, string_get($5));
    }
    | declaration_specifiers declarator {
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
            hashmap_add(typedef_names, string_get(string_dup($1)), (void*)true);
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
            hashmap_add(typedef_names, string_get(string_dup($2)), (void*)true);
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
    | object_specifier {
        $$ = string_dup($1);
    }
    ;

function_definition:
      declaration_specifiers declarator declaration_list compound_statement {
        if(string_equals(string_substring($2, 0, 3), new_string("main"))) {
            $$ = string_dup($1);
            string_add_str($$, string_get($2));
            string_add_str($$, string_get($3));
            
            /* Store parameters for real main */
            string_add_str(main_parameters, string_get($3));

            string_add_str($$, " {\n__setup_objects();\n");
            string_add_str($$, string_get($4));
            string_add_str($$, "}\n");
        }
        else {
            $$ = string_dup($1);
            string_add_str($$, string_get($2));
            string_add_str($$, string_get($3));
            string_add_str($$, string_get($4));
        }
    }
    | declaration_specifiers declarator compound_statement {
        if(string_equals(string_substring($2, 0, 3), new_string("main"))) {
            $$ = string_dup($1);
            string_add_str($$, string_get($2));
            string_add_str($$, " {\n__setup_objects();\n");
            string_add_str($$, string_get($3));
            string_add_str($$, "}\n");
        }
        else {
            $$ = string_dup($1);
            string_add_str($$, string_get($2));
            string_add_str($$, string_get($3));
        }
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
    | IMPORT STRING {
        /* TODO -> ADDED HERE */
        string *import_value = new_string("");
        string_add_str(import_value, string_get($2));

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

        $$ = new_string("\n#include \"");
        string_add_str($$, string_get(import_value));
        string_add_str($$, "\"\n");
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
    printf("`%s`\n", string_get(translation));
    /* yyparse(); */
}

static void __setup_hashmaps(void) {
    typedef_names = new_hashmap();
    enum_constants = new_hashmap();
    object_names = new_hashmap();
    main_parameters = new_string("");
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
    FILE *fp = fopen("object.h", "w");
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
    string_add_str(translation, "static void __setup_objects(void) {\n");
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
    printf("\033[38;5;11mmessage\033[0m: (%s) %s |> %s |> `%s` |> `%s`\n",
        string_get(vector_get(message, 0)),
        string_get(vector_get(message, 1)),
        string_get(vector_get(message, 2)),
        string_get(vector_get(message, 3)),
        string_get(vector_get(message, 4)));
}
static void display_hashmap_of_messages(vector *protocol_data) {
    hashmap *messages = vector_get(protocol_data, 1);
    hashmap_map(messages, (lambda)display_message, VALUES);
}
static void iterate_on_protocols(void) {
    hashmap_map(protocols, (lambda)display_hashmap_of_messages, VALUES);
}
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
    hashmap_add(typedef_names, "Object", (void*)true);
    /**/

    /* Write the initial `object.h` */
    __setup_initial_object();

    /* Parse the text */
    yyparse();
    /******************/

    /* Write the init nodes */
    __setup_init_objects();

printf("\n\033[38;5;207mtypedef_names\033[0m\n");
display_hashmap(typedef_names);
printf("\n\033[38;5;207menum_constants\033[0m\n");
display_hashmap(enum_constants);
printf("\n\033[38;5;207mobject_names\033[0m\n");
display_hashmap(object_names);

printf("\n\033[38;5;207mmodels\033[0m\n");
iterate_on_models();
printf("\n\033[38;5;207mprotocols\033[0m\n");
iterate_on_protocols();
printf("\n\033[38;5;207mobjects\033[0m\n");
iterate_on_objects();

    /*********************************/
    FILE *fp = fopen("out.c", "w");
    fprintf(fp, "%s", string_get(translation));
    fclose(fp);
    /*********************************/
}
