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

void compile_file(char*);

/* Result of the parsed file */
string *translation;
string *filename;
bool main_flag = false;
vector *files;
vector *include_list_for_main;

/* Hashmaps containing special identifiers */
hashmap *typedef_names;
hashmap *object_names;
hashmap *enum_constants;

/* Compilation data */
int total_i_values;
int argc;
char **argv;
bool main_flag_was_set;
string *command;
FILE *fp;
bool do_not_compile;
string *mode;

%}

%union {
    string *String;
    vector *Vector;
}

%token OBJECT INIT DEFER FIELDS IMPLEMENTS IMPORT

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

%type<String> object object_specifier self_or_super declaration_specifiers_or_pointer
%type<Vector> constructor_declaration destructor_declaration message_declaration_list message_declaration model_declaration_list
%type<Vector> object_declaration_list object_declaration fields_declaration object_parameter_type_list object_parameter_type model_declaration

%type<String> preprocessor_directive preprocessor_control_line

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

        /* Turn into an identifier */
        $2 = new_string(string_identifier($2));

        /* Add an identifier to avoid name collisions */
        string_add_str($$, "zircon_");

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

        /* Turn into an identifier */
        $2 = new_string(string_identifier($2));

        /* Add an identifier to avoid name collisions */
        string_add_str($$, "zircon_");

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

        /* Turn into an identifier */
        $2 = new_string(string_identifier($2));

        /* Add an identifier to avoid name collisions */
        string_add_str($$, "zircon_");

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

        /* Turn into an identifier */
        $2 = new_string(string_identifier($2));

        /* Add an identifier to avoid name collisions */
        string_add_str($$, "zircon_");

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
        $$ = string_dup($1);
        string_add_char($$, ' ');
        hashmap_add(typedef_names, string_get(string_dup($1)), (void*)true);
    }
    ;

object_specifier:
      object IDENTIFIER IMPLEMENTS TYPEDEF_NAME '{' object_declaration_list '}' {
        $$ = new_string("");
        main_flag = false;

        filename = string_dup($2);
        string_add_str(filename, ".h");

        /************/
        vector *object_fields = vector_get($6, 0);
        vector *object_messages = vector_get($6, 1);
        /************/

        hashmap_add(typedef_names, string_get(string_dup($2)), (void*)true);
        hashmap_add(object_names, string_get(string_dup($2)), (void*)true);
        
        /* Translate the parsed data */
        string_add_str($$, "\n#ifndef __");
        string_add_str($$, string_get($2));
        string_add_str($$, "_\n");
        string_add_str($$, "#define __");
        string_add_str($$, string_get($2));
        string_add_str($$, "_\n\n");

        string_add_str($$, "/* INDLUDE SUPER */\n");
        string_add_str($$, "#include \"");
        string_add_str($$, string_get($4));
        string_add_str($$, ".h\"\n\n");
        string_add_str($$, "/* REPRESENTATION */\n");
        string_add_str($$, "struct ");
        string_add_str($$, string_get($2));
        string_add_str($$, " {\n    struct ");
        string_add_str($$, string_get($4));
        string_add_str($$, " _;\n");

        /* Create the include file */
        if(!string_equals($4, new_string("Object"))) {
            string *filename = string_dup($4);
            string_add_str(filename, ".h");
            FILE *fp = fopen(string_get(filename), "w");
            fclose(fp);
            vector_add(files, filename);
        }

        int i;
        for(i = 0; i < vector_length(object_fields); i++) {
            vector *field = vector_get(object_fields, i);
            string_add_str($$, "    ");
            string_add_str($$, string_get(vector_get(field, 0)));
            string_add_str($$, string_get(vector_get(field, 1)));
            string_add_str($$, ";\n");
        }
        string_add_str($$, "};\n");
        
        /* Count locally defined messages */
        int locally_defined_messages = 0;
        for(i = 0; i < vector_length(object_messages); i++) {
            vector *message = vector_get(object_messages, i);

            /* Remove quotations */
            string *name = vector_get(message, 2);
            string_skip(name, 1);
            string_shorten(name, string_length(name) - 2);

            /* Turn into an identifier */
            name = new_string(string_identifier(name));
            vector_set(message, 2, name);

            if(string_equals(vector_get(message, 1), new_string("self ")))
                locally_defined_messages++;
        }

        string *inherited_class = new_string("");        
        if(locally_defined_messages != 0) {
            string_add_str($$, "struct ");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class {\n");

            if(string_equals($4, new_string("Object")))
                string_add_str(inherited_class, "Class");
            else {
                string_add_str(inherited_class, string_get($4));
                string_add_str(inherited_class, "Class");
            }
            string_add_str($$, "    struct ");
            string_add_str($$, string_get(inherited_class));
            string_add_str($$, " _;\n");
            for(i = 0; i < vector_length(object_messages); i++) {
                vector *message = vector_get(object_messages, i);
                if(!string_equals(vector_get(message, 2), new_string("new"))
                && !string_equals(vector_get(message, 2), new_string("defer"))
                && !string_equals(vector_get(message, 1), new_string("super "))) {
                    string_add_str($$, "    ");
                    string_add_str($$, string_get(vector_get(message, 0)));
                    string_add_str($$, " (*");
                    string_add_str($$, string_get(vector_get(message, 2)));
                    if(string_length(vector_get(message, 3)) == 0)
                        string_add_str($$, ")(void *self");
                    else {
                        string_add_str($$, ")(void *self");
                        vector *message_fields = vector_get(message, 3);
                        int j;
                        for(j = 0; j < vector_length(message_fields); j++) {
                            string_add_str($$, ", ");
                            vector *current_message_fields = vector_get(message_fields, j);
                            string_add_str($$, string_get(vector_get(current_message_fields, 0)));
                            string_add_str($$, string_get(vector_get(current_message_fields, 1)));
                        }
                    }
                    string_add_str($$, ");\n");
                }
            }
            string_add_str($$, "};");
        }

        string_add_str($$, "\n\n");
        string_add_str($$, "/* DECLARATIONS */\n");
        string_add_str($$, "void *");
        string_add_str($$, string_get($2));
        string_add_str($$, ";\n");
        if(locally_defined_messages != 0) {
            string_add_str($$, "void *");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class;\n");
        }

        string_add_str($$, "\n/* SELECTORS */\n");
        if(locally_defined_messages != 0) {
            for(i = 0; i < vector_length(object_messages); i++) {
                vector *message = vector_get(object_messages, i);
                if(!string_equals(vector_get(message, 2), new_string("new"))
                && !string_equals(vector_get(message, 2), new_string("defer"))
                && !string_equals(vector_get(message, 1), new_string("super "))) {
                    /* Write base call */
                    string_add_str($$, string_get(vector_get(message, 0)));

                    /* Add an identifier to avoid name collisions */
                    string_add_str($$, "zircon_");

                    string_add_str($$, string_get(vector_get(message, 2)));
                    if(string_length(vector_get(message, 3)) == 0)
                        string_add_str($$, "(void *_self");
                    else {
                        string_add_str($$, "(void *_self");
                        vector *message_fields = vector_get(message, 3);
                        int j;
                        for(j = 0; j < vector_length(message_fields); j++) {
                            string_add_str($$, ", ");
                            vector *current_message_fields = vector_get(message_fields, j);
                            string_add_str($$, string_get(vector_get(current_message_fields, 0)));
                            string_add_str($$, string_get(vector_get(current_message_fields, 1)));
                        }
                    }
                    string_add_str($$, ") {\n");
                    string_add_str($$, "    struct ");
                    string_add_str($$, string_get($2));
                    string_add_str($$, "Class *class = classOf(_self);\n\n");
                    string_add_str($$, "    assert(class->");

                    string *name = vector_get(message, 2);
                    string_add_str($$, string_get(name));
                    string_add_str($$, ");\n");
                    string_add_str($$, "    return class->");
                    string_add_str($$, string_get(name));
                    string_add_str($$, "(_self");
                    vector *message_fields = vector_get(message, 3);
                    int j;
                    for(j = 0; j < vector_length(message_fields); j++) {
                        string_add_str($$, ", ");
                        vector *current_message_fields = vector_get(message_fields, j);
                        string_add_str($$, string_get(vector_get(current_message_fields, 1)));
                    }
                    string_add_str($$, ");\n}\n");

                    /* Write super call */
                    string_add_str($$, string_get(vector_get(message, 0)));
                    
                    /* Add an identifier to avoid name collisions */
                    string_add_str($$, "zircon_");

                    string_add_str($$, "super_");
                    string_add_str($$, string_get(vector_get(message, 2)));
                    if(string_length(vector_get(message, 3)) == 0)
                        string_add_str($$, "(void *_class, void *_self");
                    else {
                        string_add_str($$, "(void *_class, void *_self");
                        vector *message_fields = vector_get(message, 3);
                        int j;
                        for(j = 0; j < vector_length(message_fields); j++) {
                            string_add_str($$, ", ");
                            vector *current_message_fields = vector_get(message_fields, j);
                            string_add_str($$, string_get(vector_get(current_message_fields, 0)));
                            string_add_str($$, string_get(vector_get(current_message_fields, 1)));
                        }
                    }
                    string_add_str($$, ") {\n");
                    string_add_str($$, "    struct ");
                    string_add_str($$, string_get($2));
                    string_add_str($$, "Class *superclass = super(_class);\n\n");
                    string_add_str($$, "    assert(_self && superclass->");
                    string_add_str($$, string_get(name));
                    string_add_str($$, ");\n");
                    string_add_str($$, "    return superclass->");
                    string_add_str($$, string_get(name));
                    string_add_str($$, "(_self");
                    for(j = 0; j < vector_length(message_fields); j++) {
                        string_add_str($$, ", ");
                        vector *current_message_fields = vector_get(message_fields, j);
                        string_add_str($$, string_get(vector_get(current_message_fields, 1)));
                    }
                    string_add_str($$, ");\n}\n");
                }
            }
        }

        string_add_str($$, "\n/* METHODS */\n");
        bool constructor_is_overriden = false;
        bool destructor_is_overriden = false;
        string *method_on_new;
        string *method_on_defer;
        for(i = 0; i < vector_length(object_messages); i++) {
            vector *message = vector_get(object_messages, i);
            if(string_equals(vector_get(message, 2), new_string("new"))) {
                constructor_is_overriden = true;
                method_on_new = vector_get(message, 4);
            }
            if(string_equals(vector_get(message, 2), new_string("defer"))) {
                destructor_is_overriden = true;
                method_on_defer = vector_get(message, 4);
            }
        }

        if(constructor_is_overriden) {
            string_add_str($$, "void *");
            string_add_str($$, string_get($2));
            string_add_str($$, "_ctor(void *_self, va_list *app) {\n");
            string_add_str($$, "    struct ");
            string_add_str($$, string_get($2));
            string_add_str($$, " *self = zircon_super_ctor(");
            string_add_str($$, string_get($2));
            string_add_str($$, ", _self, app);\n\n");

            /***********************************************/
            string_add_str($$, string_get(method_on_new));
            /***********************************************/
            
            string_add_str($$, "    return self;\n};\n");
        }
        if(destructor_is_overriden) {
            string_add_str($$, "void *");
            string_add_str($$, string_get($2));
            string_add_str($$, "_dtor(void *_self) {\n");
            string_add_str($$, "    struct ");
            string_add_str($$, string_get($2));
            string_add_str($$, " *self = zircon_super_dtor(");
            string_add_str($$, string_get($2));
            string_add_str($$, ", _self);\n\n");
            string_add_str($$, string_get(method_on_defer));
            string_add_str($$, "\n    return 0;\n};\n");
        }

        for(i = 0; i < vector_length(object_messages); i++) {
            vector *message = vector_get(object_messages, i);
            if(string_equals(vector_get(message, 2), new_string("new"))
            || string_equals(vector_get(message, 2), new_string("defer")))
                continue;
            string_add_str($$, string_get(vector_get(message, 0)));
            string_add_char($$, ' ');
            string_add_str($$, string_get($2));
            string_add_str($$, "_");
            string_add_str($$, string_get(vector_get(message, 2)));
            if(string_length(vector_get(message, 3)) == 0)
                string_add_str($$, "(void *_self");
            else {
                string_add_str($$, "(void *_self");
                vector *message_fields = vector_get(message, 3);
                int j;
                for(j = 0; j < vector_length(message_fields); j++) {
                    string_add_str($$, ", ");
                    vector *current_message_fields = vector_get(message_fields, j);
                    string_add_str($$, string_get(vector_get(current_message_fields, 0)));
                    bool is_message_an_object = vector_get(current_message_fields, 2);
                    if(is_message_an_object)
                        string_add_char($$, '_');
                    string_add_str($$, string_get(vector_get(current_message_fields, 1)));
                }
            }
            string_add_str($$, ") {\n");
            string_add_str($$, "struct ");
            string_add_str($$, string_get($2));
            string_add_str($$, " *self = _self;\n");
            string_add_str($$, "struct ");
            string_add_str($$, string_get($4));
            string_add_str($$, " *super = (struct ");
            string_add_str($$, string_get($4));
            string_add_str($$, "*)self;\n\n");
            vector *message_fields = vector_get(message, 3);
            int j;
            for(j = 0; j < vector_length(message_fields); j++) {
                /* Check for object parameter */
                vector *current_message_fields = vector_get(message_fields, j);
                string *current_message_name = vector_get(current_message_fields, 1);
                bool is_message_an_object = vector_get(current_message_fields, 2);
                if(is_message_an_object) {
                    string_add_str($$, "struct ");
                    string_add_str($$, string_get($2));
                    string_add_str($$, " *");
                    string_add_str($$, string_get(current_message_name));
                    string_add_str($$, " = _");
                    string_add_str($$, string_get(current_message_name));
                    string_add_str($$, ";\n");
                }
            }
            string_add_str($$, string_get(vector_get(message, 4)));
            string_add_str($$, "}\n\n");
        }

        if(locally_defined_messages != 0) {
            string_add_str($$, "void *");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class_ctor(void *_self, va_list *app) {\n");
            string_add_str($$, "    struct ");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class *self = zircon_super_ctor(");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class, _self, app);\n\n");
            string_add_str($$, "    typedef void (*voidf)();\n");
            string_add_str($$, "    voidf selector;\n");
            string_add_str($$, "#ifdef va_copy\n");
            string_add_str($$, "    va_list ap;\n");
            string_add_str($$, "    va_copy(ap, *app);\n");
            string_add_str($$, "#else\n");
            string_add_str($$, "    va_list ap = *app;\n");
            string_add_str($$, "#endif\n");
            string_add_str($$, "    while((selector = va_arg(ap, voidf))) {\n");
            string_add_str($$, "        voidf method = va_arg(ap, voidf);\n\n");
            for(i = 0; i < vector_length(object_messages); i++) {
                vector *message = vector_get(object_messages, i);
                if(string_equals(vector_get(message, 2), new_string("new"))
                || string_equals(vector_get(message, 2), new_string("defer"))
                || string_equals(vector_get(message, 1), new_string("super ")))
                    continue;
                string_add_str($$, "        if(selector == (voidf)");

                /* Add an identifier to avoid name collisions */
                string_add_str($$, "zircon_");

                string_add_str($$, string_get(vector_get(message, 2)));
                string_add_str($$, ")\n");
                string_add_str($$, "            *(voidf*)&self->");
                string_add_str($$, string_get(vector_get(message, 2)));
                string_add_str($$, " = method;\n");
            }
            string_add_str($$, "    }\n");
            string_add_str($$, "#ifdef va_copy\n");
            string_add_str($$, "    va_end(ap);\n");
            string_add_str($$, "#endif\n\n");
            string_add_str($$, "    return self;\n");
            string_add_str($$, "}\n");
        }

        string_add_str($$, "/* INITIALIZATION */\n");
        string_add_str($$, "void __init_");
        string_add_str($$, string_get($2));
        string_add_str($$, "(void) {\n");
        if(!string_equals($4, new_string("Object"))) {
            string_add_str($$, "__init_");
            string_add_str($$, string_get($4));
            string_add_str($$, "();\n");
        }

        if(locally_defined_messages != 0) {
            string_add_str($$, "if(!");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class) ");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class = zircon_new(");
            string_add_str($$, "Class,\n");
            string_add_char($$, '\"');
            string_add_str($$, string_get($2));
            string_add_str($$, "Class\",\n");
            if(!string_equals($4, new_string("Object"))) {
                string_add_str($$, string_get($4));
                string_add_str($$, "Class,\n");
            }
            else
                string_add_str($$, "Class,\n");
            string_add_str($$, "sizeof(struct ");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class),\n");
            string_add_str($$, "zircon_ctor, ");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class_ctor,\n");
            string_add_str($$, "0);\n");

            string_add_str($$, "if(!");
            string_add_str($$, string_get($2));
            string_add_str($$, ") ");
            string_add_str($$, string_get($2));
            string_add_str($$, " = zircon_new(\n");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class,\n");
            string_add_char($$, '\"');
            string_add_str($$, string_get($2));
            string_add_str($$, "\",\n");
            string_add_str($$, string_get($4));
            string_add_str($$, ",\n");
            string_add_str($$, "sizeof(struct ");
            string_add_str($$, string_get($2));
            string_add_str($$, "),\n");

            for(i = 0; i < vector_length(object_messages); i++) {
                vector *message = vector_get(object_messages, i);
                if(!string_equals(vector_get(message, 2), new_string("new"))
                && !string_equals(vector_get(message, 2), new_string("defer"))) {
                    /* Add an identifier to avoid name collisions */
                    string_add_str($$, "zircon_");

                    string_add_str($$, string_get(vector_get(message, 2)));
                    string_add_str($$, ", ");
                    string_add_str($$, string_get($2));
                    string_add_str($$, "_");
                    string_add_str($$, string_get(vector_get(message, 2)));
                    string_add_str($$, ",\n");
                }
            }
        }
        else {
            string_add_str($$, "if(!");
            string_add_str($$, string_get($2));
            string_add_str($$, ") ");
            string_add_str($$, string_get($2));
            string_add_str($$, " = zircon_new(\n");
            string_add_str($$, "Class,\n");
            string_add_char($$, '\"');
            string_add_str($$, string_get($2));
            string_add_str($$, "\",\n");
            string_add_str($$, string_get($4));
            string_add_str($$, ",\n");
            string_add_str($$, "sizeof(struct ");
            string_add_str($$, string_get($2));
            string_add_str($$, "),\n");

            for(i = 0; i < vector_length(object_messages); i++) {
                vector *message = vector_get(object_messages, i);
                if(!string_equals(vector_get(message, 2), new_string("new"))
                && !string_equals(vector_get(message, 2), new_string("defer"))) {
                    /* Add an identifier to avoid name collisions */
                    string_add_str($$, "zircon_");
                    
                    string_add_str($$, string_get(vector_get(message, 2)));
                    string_add_str($$, ", ");
                    string_add_str($$, string_get($2));
                    string_add_str($$, "_");
                    string_add_str($$, string_get(vector_get(message, 2)));
                    string_add_str($$, ",\n");
                }
            }
        }

        if(constructor_is_overriden) {
            string_add_str($$, "zircon_ctor, ");
            string_add_str($$, string_get($2));
            string_add_str($$, "_ctor,\n");
        }

        if(destructor_is_overriden) {
            string_add_str($$, "zircon_dtor, ");
            string_add_str($$, string_get($2));
            string_add_str($$, "_dtor,\n");
        }

        string_add_str($$, "0);\n}\n");

        string_add_str($$, "#endif\n\n");
    }
    | object IDENTIFIER IMPLEMENTS TYPEDEF_NAME '(' object_parameter_type_list ')' '{' object_declaration_list '}' {
        $$ = new_string("");
        main_flag = false;

        filename = string_dup($2);
        string_add_str(filename, ".h");
        
        /************/
        vector *object_fields = vector_get($9, 0);
        vector *object_messages = vector_get($9, 1);
        /************/

        hashmap_add(typedef_names, string_get(string_dup($2)), (void*)true);
        hashmap_add(object_names, string_get(string_dup($2)), (void*)true);
        
        /* Translate the parsed data */
        string_add_str($$, "\n#ifndef __");
        string_add_str($$, string_get($2));
        string_add_str($$, "_\n");
        string_add_str($$, "#define __");
        string_add_str($$, string_get($2));
        string_add_str($$, "_\n\n");

        string_add_str($$, "/* INDLUDE SUPER */\n");
        string_add_str($$, "#include \"");
        string_add_str($$, string_get($4));
        string_add_str($$, ".h\"\n\n");
        string_add_str($$, "/* REPRESENTATION */\n");
        string_add_str($$, "struct ");
        string_add_str($$, string_get($2));
        string_add_str($$, " {\n    struct ");
        string_add_str($$, string_get($4));
        string_add_str($$, " _;\n");

        int i;
        for(i = 0; i < vector_length(object_fields); i++) {
            vector *field = vector_get(object_fields, i);
            string_add_str($$, "    ");
            string_add_str($$, string_get(vector_get(field, 0)));
            string_add_str($$, string_get(vector_get(field, 1)));
            string_add_str($$, ";\n");
        }
        string_add_str($$, "};\n");
        
        /* Count locally defined messages */
        int locally_defined_messages = 0;
        for(i = 0; i < vector_length(object_messages); i++) {
            vector *message = vector_get(object_messages, i);
                
            /* Remove quotations */
            string *name = vector_get(message, 2);
            string_skip(name, 1);
            string_shorten(name, string_length(name) - 2);

            /* Turn into an identifier */
            name = new_string(string_identifier(name));
            vector_set(message, 2, name);

            if(string_equals(vector_get(message, 1), new_string("self ")))
                locally_defined_messages++;
        }

        string *inherited_class = new_string("");        
        if(locally_defined_messages != 0) {
            string_add_str($$, "struct ");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class {\n");

            if(string_equals($4, new_string("Object")))
                string_add_str(inherited_class, "Class");
            else {
                string_add_str(inherited_class, string_get($4));
                string_add_str(inherited_class, "Class");
            }
            string_add_str($$, "    struct ");
            string_add_str($$, string_get(inherited_class));
            string_add_str($$, " _;\n");
            for(i = 0; i < vector_length(object_messages); i++) {
                vector *message = vector_get(object_messages, i);
                if(!string_equals(vector_get(message, 2), new_string("new"))
                && !string_equals(vector_get(message, 2), new_string("defer"))
                && !string_equals(vector_get(message, 1), new_string("super "))) {
                    string_add_str($$, "    ");
                    string_add_str($$, string_get(vector_get(message, 0)));
                    string_add_str($$, " (*");
                    string_add_str($$, string_get(vector_get(message, 2)));
                    if(string_length(vector_get(message, 3)) == 0)
                        string_add_str($$, ")(void *self");
                    else {
                        string_add_str($$, ")(void *self");
                        vector *message_fields = vector_get(message, 3);
                        int j;
                        for(j = 0; j < vector_length(message_fields); j++) {
                            string_add_str($$, ", ");
                            vector *current_message_fields = vector_get(message_fields, j);
                            string_add_str($$, string_get(vector_get(current_message_fields, 0)));
                            string_add_str($$, string_get(vector_get(current_message_fields, 1)));
                        }
                    }
                    string_add_str($$, ");\n");
                }
            }
            string_add_str($$, "};");
        }

        string_add_str($$, "\n\n");
        string_add_str($$, "/* DECLARATIONS */\n");
        string_add_str($$, "void *");
        string_add_str($$, string_get($2));
        string_add_str($$, ";\n");
        if(locally_defined_messages != 0) {
            string_add_str($$, "void *");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class;\n");
        }

        string_add_str($$, "\n/* SELECTORS */\n");
        if(locally_defined_messages != 0) {
            for(i = 0; i < vector_length(object_messages); i++) {
                vector *message = vector_get(object_messages, i);
                if(!string_equals(vector_get(message, 2), new_string("new"))
                && !string_equals(vector_get(message, 2), new_string("defer"))
                && !string_equals(vector_get(message, 1), new_string("super "))) {
                    /* Write base call */
                    string_add_str($$, string_get(vector_get(message, 0)));
                    
                    /* Add an identifier to avoid name collisions */
                    string_add_str($$, "zircon_");

                    string_add_str($$, string_get(vector_get(message, 2)));
                    if(string_length(vector_get(message, 3)) == 0)
                        string_add_str($$, "(void *_self");
                    else {
                        string_add_str($$, "(void *_self");
                        vector *message_fields = vector_get(message, 3);
                        int j;
                        for(j = 0; j < vector_length(message_fields); j++) {
                            string_add_str($$, ", ");
                            vector *current_message_fields = vector_get(message_fields, j);
                            string_add_str($$, string_get(vector_get(current_message_fields, 0)));
                            string_add_str($$, string_get(vector_get(current_message_fields, 1)));
                        }
                    }
                    string_add_str($$, ") {\n");
                    string_add_str($$, "    struct ");
                    string_add_str($$, string_get($2));
                    string_add_str($$, "Class *class = classOf(_self);\n\n");
                    string_add_str($$, "    assert(class->");

                    string *name = vector_get(message, 2);
                    string_add_str($$, string_get(name));
                    string_add_str($$, ");\n");
                    string_add_str($$, "    return class->");
                    string_add_str($$, string_get(name));
                    string_add_str($$, "(_self");
                    vector *message_fields = vector_get(message, 3);
                    int j;
                    for(j = 0; j < vector_length(message_fields); j++) {
                        string_add_str($$, ", ");
                        vector *current_message_fields = vector_get(message_fields, j);
                        string_add_str($$, string_get(vector_get(current_message_fields, 1)));
                    }
                    string_add_str($$, ");\n}\n");

                    /* Write super call */
                    string_add_str($$, string_get(vector_get(message, 0)));

                    /* Add an identifier to avoid name collisions */
                    string_add_str($$, "zircon_");

                    string_add_str($$, "super_");
                    string_add_str($$, string_get(vector_get(message, 2)));
                    if(string_length(vector_get(message, 3)) == 0)
                        string_add_str($$, "(void *_class, void *_self");
                    else {
                        string_add_str($$, "(void *_class, void *_self");
                        vector *message_fields = vector_get(message, 3);
                        int j;
                        for(j = 0; j < vector_length(message_fields); j++) {
                            string_add_str($$, ", ");
                            vector *current_message_fields = vector_get(message_fields, j);
                            string_add_str($$, string_get(vector_get(current_message_fields, 0)));
                            string_add_str($$, string_get(vector_get(current_message_fields, 1)));
                        }
                    }
                    string_add_str($$, ") {\n");
                    string_add_str($$, "    struct ");
                    string_add_str($$, string_get($2));
                    string_add_str($$, "Class *superclass = super(_class);\n\n");
                    string_add_str($$, "    assert(_self && superclass->");
                    string_add_str($$, string_get(name));
                    string_add_str($$, ");\n");
                    string_add_str($$, "    return superclass->");
                    string_add_str($$, string_get(name));
                    string_add_str($$, "(_self");
                    for(j = 0; j < vector_length(message_fields); j++) {
                        string_add_str($$, ", ");
                        vector *current_message_fields = vector_get(message_fields, j);
                        string_add_str($$, string_get(vector_get(current_message_fields, 1)));
                    }
                    string_add_str($$, ");\n}\n");
                }
            }
        }

        string_add_str($$, "\n/* METHODS */\n");
        bool constructor_is_overriden = false;
        bool destructor_is_overriden = false;
        string *method_on_new;
        string *method_on_defer;
        for(i = 0; i < vector_length(object_messages); i++) {
            vector *message = vector_get(object_messages, i);
            if(string_equals(vector_get(message, 2), new_string("new"))) {
                constructor_is_overriden = true;
                method_on_new = vector_get(message, 4);
            }
            if(string_equals(vector_get(message, 2), new_string("defer"))) {
                destructor_is_overriden = true;
                method_on_defer = vector_get(message, 4);
            }
        }

        if(constructor_is_overriden) {
            string_add_str($$, "void *");
            string_add_str($$, string_get($2));
            string_add_str($$, "_ctor(void *_self, va_list *app) {\n");
            string_add_str($$, "    struct ");
            string_add_str($$, string_get($2));
            string_add_str($$, " *self = zircon_super_ctor(");
            string_add_str($$, string_get($2));
            string_add_str($$, ", _self, app");
            string_add_str($$, ");\n\n");

            /***********************************************/
            vector *parameters = $6;
            int k;
            for(k = 0; k < vector_length(parameters); k++) {
                vector *current_parameter = vector_get(parameters, k);
                string_add_str($$, string_get(vector_get(current_parameter, 0)));
                string_add_str($$, string_get(vector_get(current_parameter, 1)));
                string_add_str($$, " = va_arg(*app, ");
                string_add_str($$, string_get(vector_get(current_parameter, 0)));
                string_add_str($$, ");\n");
            }
            string_add_str($$, string_get(method_on_new));
            /***********************************************/
            
            string_add_str($$, "    return self;\n}\n");
        }
        if(destructor_is_overriden) {
            string_add_str($$, "void *");
            string_add_str($$, string_get($2));
            string_add_str($$, "_dtor(void *_self) {\n");
            string_add_str($$, "    struct ");
            string_add_str($$, string_get($2));
            string_add_str($$, " *self = zircon_super_dtor(");
            string_add_str($$, string_get($2));
            string_add_str($$, ", _self);\n\n");
            string_add_str($$, string_get(method_on_defer));
            string_add_str($$, "\n    return 0;\n};\n");
        }

        for(i = 0; i < vector_length(object_messages); i++) {
            vector *message = vector_get(object_messages, i);
            if(string_equals(vector_get(message, 2), new_string("new"))
            || string_equals(vector_get(message, 2), new_string("defer")))
                continue;
            string_add_str($$, string_get(vector_get(message, 0)));
            string_add_char($$, ' ');
            string_add_str($$, string_get($2));
            string_add_str($$, "_");
            string_add_str($$, string_get(vector_get(message, 2)));
            if(string_length(vector_get(message, 3)) == 0)
                string_add_str($$, "(void *_self");
            else {
                string_add_str($$, "(void *_self");
                vector *message_fields = vector_get(message, 3);
                int j;
                for(j = 0; j < vector_length(message_fields); j++) {
                    string_add_str($$, ", ");
                    vector *current_message_fields = vector_get(message_fields, j);
                    string_add_str($$, string_get(vector_get(current_message_fields, 0)));
                    bool is_message_an_object = vector_get(current_message_fields, 2);
                    if(is_message_an_object)
                        string_add_char($$, '_');
                    string_add_str($$, string_get(vector_get(current_message_fields, 1)));
                }
            }
            string_add_str($$, ") {\n");
            string_add_str($$, "struct ");
            string_add_str($$, string_get($2));
            string_add_str($$, " *self = _self;\n");
            string_add_str($$, "struct ");
            string_add_str($$, string_get($4));
            string_add_str($$, " *super = (struct ");
            string_add_str($$, string_get($4));
            string_add_str($$, "*)self;\n\n");
            vector *message_fields = vector_get(message, 3);
            int j;
            for(j = 0; j < vector_length(message_fields); j++) {
                /* Check for object parameter */
                vector *current_message_fields = vector_get(message_fields, j);
                string *current_message_name = vector_get(current_message_fields, 1);
                bool is_message_an_object = vector_get(current_message_fields, 2);
                if(is_message_an_object) {
                    string_add_str($$, "struct ");
                    string_add_str($$, string_get($2));
                    string_add_str($$, " *");
                    string_add_str($$, string_get(current_message_name));
                    string_add_str($$, " = _");
                    string_add_str($$, string_get(current_message_name));
                    string_add_str($$, ";\n");
                }
            }
            string_add_str($$, string_get(vector_get(message, 4)));
            string_add_str($$, "}\n\n");
        }

        if(locally_defined_messages != 0) {
            string_add_str($$, "void *");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class_ctor(void *_self, va_list *app) {\n");
            string_add_str($$, "    struct ");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class *self = zircon_super_ctor(");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class, _self, app);\n\n");
            string_add_str($$, "    typedef void (*voidf)();\n");
            string_add_str($$, "    voidf selector;\n");
            string_add_str($$, "#ifdef va_copy\n");
            string_add_str($$, "    va_list ap;\n");
            string_add_str($$, "    va_copy(ap, *app);\n");
            string_add_str($$, "#else\n");
            string_add_str($$, "    va_list ap = *app;\n");
            string_add_str($$, "#endif\n");
            string_add_str($$, "    while((selector = va_arg(ap, voidf))) {\n");
            string_add_str($$, "        voidf method = va_arg(ap, voidf);\n\n");
            for(i = 0; i < vector_length(object_messages); i++) {
                vector *message = vector_get(object_messages, i);
                if(string_equals(vector_get(message, 2), new_string("new"))
                || string_equals(vector_get(message, 2), new_string("defer"))
                || string_equals(vector_get(message, 1), new_string("super ")))
                    continue;
                string_add_str($$, "        if(selector == (voidf)");

                /* Add an identifier to avoid name collisions */
                string_add_str($$, "zircon_");

                string_add_str($$, string_get(vector_get(message, 2)));
                string_add_str($$, ")\n");
                string_add_str($$, "            *(voidf*)&self->");
                string_add_str($$, string_get(vector_get(message, 2)));
                string_add_str($$, " = method;\n");
            }
            string_add_str($$, "    }\n");
            string_add_str($$, "#ifdef va_copy\n");
            string_add_str($$, "    va_end(ap);\n");
            string_add_str($$, "#endif\n\n");
            string_add_str($$, "    return self;\n");
            string_add_str($$, "}\n");
        }

        string_add_str($$, "/* INITIALIZATION */\n");
        string_add_str($$, "void __init_");
        string_add_str($$, string_get($2));
        string_add_str($$, "(void) {\n");
        if(!string_equals($4, new_string("Object"))) {
            string_add_str($$, "__init_");
            string_add_str($$, string_get($4));
            string_add_str($$, "();\n");
        }
        
        if(locally_defined_messages != 0) {
            string_add_str($$, "if(!");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class) ");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class = zircon_new(");
            string_add_str($$, "Class,\n");
            string_add_char($$, '\"');
            string_add_str($$, string_get($2));
            string_add_str($$, "Class\",\n");
            if(!string_equals($4, new_string("Object"))) {
                string_add_str($$, string_get($4));
                string_add_str($$, "Class,\n");
            }
            else
                string_add_str($$, "Class,\n");
            string_add_str($$, "sizeof(struct ");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class),\n");
            string_add_str($$, "zircon_ctor, ");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class_ctor,\n");
            string_add_str($$, "0);\n");

            string_add_str($$, "if(!");
            string_add_str($$, string_get($2));
            string_add_str($$, ") ");
            string_add_str($$, string_get($2));
            string_add_str($$, " = zircon_new(\n");
            string_add_str($$, string_get($2));
            string_add_str($$, "Class,\n");
            string_add_char($$, '\"');
            string_add_str($$, string_get($2));
            string_add_str($$, "\",\n");
            string_add_str($$, string_get($4));
            string_add_str($$, ",\n");
            string_add_str($$, "sizeof(struct ");
            string_add_str($$, string_get($2));
            string_add_str($$, "),\n");

            for(i = 0; i < vector_length(object_messages); i++) {
                vector *message = vector_get(object_messages, i);
                if(!string_equals(vector_get(message, 2), new_string("new"))
                && !string_equals(vector_get(message, 2), new_string("defer"))) {
                    /* Add an identifier to avoid name collisions */
                    string_add_str($$, "zircon_");

                    string_add_str($$, string_get(vector_get(message, 2)));
                    string_add_str($$, ", ");
                    string_add_str($$, string_get($2));
                    string_add_str($$, "_");
                    string_add_str($$, string_get(vector_get(message, 2)));
                    string_add_str($$, ",\n");
                }
                
            }
        }
        else {
            string_add_str($$, "if(!");
            string_add_str($$, string_get($2));
            string_add_str($$, ") ");
            string_add_str($$, string_get($2));
            string_add_str($$, " = zircon_new(\n");
            string_add_str($$, "Class,\n");
            string_add_char($$, '\"');
            string_add_str($$, string_get($2));
            string_add_str($$, "\",\n");
            string_add_str($$, string_get($4));
            string_add_str($$, ",\n");
            string_add_str($$, "sizeof(struct ");
            string_add_str($$, string_get($2));
            string_add_str($$, "),\n");

            for(i = 0; i < vector_length(object_messages); i++) {
                vector *message = vector_get(object_messages, i);
                if(!string_equals(vector_get(message, 2), new_string("new"))
                && !string_equals(vector_get(message, 2), new_string("defer"))) {
                    /* Add an identifier to avoid name collisions */
                    string_add_str($$, "zircon_");

                    string_add_str($$, string_get(vector_get(message, 2)));
                    string_add_str($$, ", ");
                    string_add_str($$, string_get($2));
                    string_add_str($$, "_");
                    string_add_str($$, string_get(vector_get(message, 2)));
                    string_add_str($$, ",\n");
                }
            }
        }
        
        if(constructor_is_overriden) {
            string_add_str($$, "zircon_ctor, ");
            string_add_str($$, string_get($2));
            string_add_str($$, "_ctor,\n");
        }

        if(destructor_is_overriden) {
            string_add_str($$, "zircon_dtor, ");
            string_add_str($$, string_get($2));
            string_add_str($$, "_dtor,\n");
        }

        string_add_str($$, "0);\n}\n");

        string_add_str($$, "#endif\n\n");
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
      /* nothing */ {
        $$ = new_vector();
        vector_add($$, new_vector());
    }
    | FIELDS '{' '}' {
        $$ = new_vector();
        vector_add($$, new_vector());
    }
    | FIELDS '{' model_declaration_list '}' {
        $$ = new_vector();
        vector_add($$, $3);
    }
    ;

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
    | '(' declaration_specifiers_or_pointer ')' self_or_super SEND STRING SEND object_parameter_type_list SEND compound_statement {
        $$ = new_vector();
        vector_add($$, $2); /* return value */
        vector_add($$, $4); /* sender */
        vector_add($$, $6); /* name */
        vector_add($$, $8); /* variable entries */
        vector_add($$, $10); /* method block */
    }
    | '(' declaration_specifiers_or_pointer ')' self_or_super SEND STRING SEND object_parameter_type_list SEND block_item {
        $$ = new_vector();
        vector_add($$, $2); /* return value */
        vector_add($$, $4); /* sender */
        vector_add($$, $6); /* name */
        vector_add($$, $8); /* variable entries */
        vector_add($$, $10); /* method block */
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
        vector_add($$, new_string("void ")); /* return value */
        vector_add($$, new_string("super ")); /* sender */
        vector_add($$, new_string("\"new\" ")); /* name */

        vector *params = new_vector();
        vector *param1 = new_vector();
        vector_add(param1, new_string("va_list* "));
        vector_add(param1, new_string("app"));
        vector_add(params, param1);

        vector_add($$, params); /* variable entries */
        vector_add($$, $2); /* method block */
    }
    ;

destructor_declaration:
      DEFER compound_statement {
        $$ = new_vector();
        vector_add($$, new_string("void ")); /* return value */
        vector_add($$, new_string("super ")); /* sender */
        vector_add($$, new_string("\"defer\" ")); /* name */
        vector_add($$, new_vector()); /* variable entries */
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
            $$ = new_string("super ");
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
        hashmap_add(typedef_names, string_get(string_dup($2)), (void*)true);
    }
    | struct_or_union IDENTIFIER {
        $$ = string_dup($1);
        string_add_str($$, string_get($2));
        /****/
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

object_parameter_type_list:
      object_parameter_type {
        $$ = new_vector();
        vector_add($$, $1);
    }
    | object_parameter_type_list ',' object_parameter_type {
        $$ = vector_dup($1);
        vector_add($$, $3);
    }
    ;

object_parameter_type:
      '(' declaration_specifiers_or_pointer ')' ':' declarator {
        $$ = new_vector();
        vector_add($$, $2); /* type */
        vector_add($$, $5); /* name */
        vector_add($$, false); /* is object */
    }
    | '(' declaration_specifiers_or_pointer ')' ':' '@' declarator {
        $$ = new_vector();
        vector_add($$, $2);   /* type */
        vector_add($$, $6);   /* name */
        vector_add($$, true); /* is object */
    }

model_declaration_list:
      model_declaration {
        $$ = new_vector();
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
        hashmap_add(typedef_names, string_get(string_dup($2)), (void*)true);
    }
    | ENUM IDENTIFIER '{' enumerator_list ',' '}' {
        $$ = new_string("enum ");
        string_add_str($$, string_get($2));
        string_add_str($$, " {\n");
        string_add_str($$, string_get($4));
        string_add_str($$, ",\n}\n");
        /****/
        hashmap_add(typedef_names, string_get(string_dup($2)), (void*)true);
    }
    | ENUM IDENTIFIER {
        $$ = new_string("enum ");
        string_add_str($$, string_get($2));
        /****/
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

preprocessor_directive:
      preprocessor_control_line {
        $$ = string_dup($1);
    }
    ;

preprocessor_control_line:
      INCLUDE '<' HEADER '>' {
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
        string *import_value = string_dup($2);

        /* Remove quotations */
        string_skip(import_value, 1);
        string_shorten(import_value, string_length(import_value) - 1);

        /* Add to object names */
        hashmap_add(typedef_names, string_get(string_dup(import_value)), (void*)true);
        hashmap_add(object_names, string_get(string_dup(import_value)), (void*)true);

        // /* Compile top bottom all imported objects */
        // string *to_compile = string_dup(import_value);
        // string_add_str(to_compile, ".zc");
        // if(!(string_equals(to_compile, new_string("Object.zc")))) {
        //     printf("compiling %s\n", string_get(to_compile));
        //     compile_file(string_get(to_compile));
        // }

        /* Add a `.h` */
        string_add_str(import_value, ".h");

        $$ = new_string("\n#include \"");
        string_add_str($$, string_get(import_value));
        string_add_str($$, "\"\n");
        
        /* Add to the include list */
        vector_add(include_list_for_main, import_value);
    }
    ;

function_definition:
      declaration_specifiers declarator declaration_list compound_statement {
        if(string_equals(string_substring($2, 0, 3), new_string("main"))) {
            $$ = new_string("void __setup_objects(void);\n");
            string_add_str($$, string_get($1));
            string_add_str($$, string_get($2));
            string_add_str($$, string_get($3));
            string_add_str($$, " {\n__setup_objects();\n");
            string_add_str($$, string_get($4));
            string_add_str($$, "}\n");
            main_flag = true;
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
            $$ = new_string("void __setup_objects(void);\n");
            string_add_str($$, string_get($1));
            string_add_str($$, string_get($2));
            string_add_str($$, " {\n__setup_objects();\n");
            string_add_str($$, string_get($3));
            string_add_str($$, "}\n");
            main_flag = true;
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
    /* exit(1); */
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
    string_add_str(obj, "#include <ctype.h>\n");
    string_add_str(obj, "#include <errno.h>\n");
    string_add_str(obj, "#include <float.h>\n");
    string_add_str(obj, "#include <limits.h>\n");
    string_add_str(obj, "#include <locale.h>\n");
    string_add_str(obj, "/* #include <math.h> */\n");
    string_add_str(obj, "#include <setjmp.h>\n");
    string_add_str(obj, "#include <signal.h>\n");
    string_add_str(obj, "#include <stdarg.h>\n");
    string_add_str(obj, "#include <stddef.h>\n");
    string_add_str(obj, "#include <stdio.h>\n");
    string_add_str(obj, "#include <stdlib.h>\n");
    string_add_str(obj, "#include <string.h>\n");
    string_add_str(obj, "#include <time.h>\n");
    string_add_str(obj, "/** @param bool -> A 'big' enough size to hold both 1 and 0 **/\n");
    string_add_str(obj, "typedef unsigned char bool;\n");
    string_add_str(obj, "#define true 1\n");
    string_add_str(obj, "#define false 0\n\n");
    string_add_str(obj, "struct Object {\n");
    string_add_str(obj, "    struct Class *class;\n");
    string_add_str(obj, "};\n");
    string_add_str(obj, "struct Class {\n");
    string_add_str(obj, "    struct Object _;\n");
    string_add_str(obj, "    char *name;\n");
    string_add_str(obj, "    struct Class *super;\n");
    string_add_str(obj, "    size_t size;\n");
    string_add_str(obj, "    void *(*ctor)(void *self, va_list *app);\n");
    string_add_str(obj, "    void *(*dtor)(void *self);\n");
    string_add_str(obj, "    bool (*differ)(void *self, void *other);\n");
    string_add_str(obj, "    bool (*puto)(void *self, FILE *fd);\n");

    string_add_str(obj, "    void *(*class)(void *self);\n");
    string_add_str(obj, "    void *(*superclass)(void *self);\n");
    string_add_str(obj, "    bool (*is_a)(void *self, char *other);\n");
    string_add_str(obj, "    char *(*to_string)(void *self);\n");
    string_add_str(obj, "};\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static void *classOf(void *_self) {\n");
    string_add_str(obj, "    struct Object *self = _self;\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    assert(_self && self && self->class);\n");
    string_add_str(obj, "    return self->class;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static size_t sizeOf(void *_self) {\n");
    string_add_str(obj, "    struct Class *class = classOf(_self);\n");
    string_add_str(obj, "    return class->size;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static void *super(void *_self) {\n");
    string_add_str(obj, "    struct Class *self = _self;\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    assert(_self && self && self->super);\n");
    string_add_str(obj, "    return self->super;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "void *zircon_ctor(void *_self, va_list *app) {\n");
    string_add_str(obj, "    struct Class *class = classOf(_self);\n");
    string_add_str(obj, "    \n");
    string_add_str(obj, "    assert(class->ctor);\n");
    string_add_str(obj, "    return class->ctor(_self, app);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "void *zircon_super_ctor(void *_class, void *_self, va_list *app) {\n");
    string_add_str(obj, "    struct Class *superclass = super(_class);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    assert(_self && superclass->ctor);\n");
    string_add_str(obj, "    return superclass->ctor(_self, app);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "void *zircon_dtor(void *_self) {\n");
    string_add_str(obj, "    struct Class *class = classOf(_self);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    assert(class->dtor);\n");
    string_add_str(obj, "    return class->dtor(_self);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "void *zircon_super_dtor(void *_class, void *_self) {\n");
    string_add_str(obj, "    struct Class *superclass = super(_class);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    assert(_self && superclass->dtor);\n");
    string_add_str(obj, "    return superclass->dtor(_self);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "bool zircon_differ(void *_self, void *other) {\n");
    string_add_str(obj, "    struct Class *class = classOf(_self);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    assert(class->differ);\n");
    string_add_str(obj, "    return class->differ(_self, other);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "bool zircon_super_differ(void *_class, void *_self, void *other) {\n");
    string_add_str(obj, "    struct Class *superclass = super(_class);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    assert(_self && superclass->differ);\n");
    string_add_str(obj, "    return superclass->differ(_self, other);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "bool zircon_puto(void *_self, FILE *fd) {\n");
    string_add_str(obj, "    struct Class *class = classOf(_self);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    assert(class->puto);\n");
    string_add_str(obj, "    return class->puto(_self, fd);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "bool zircon_super_puto(void *_class, void *_self, FILE *fd) {\n");
    string_add_str(obj, "    struct Class *superclass = super(_class);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    assert(_self && superclass->puto);\n");
    string_add_str(obj, "    return superclass->puto(_self, fd);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "void *zircon_class(void *_self) {\n");
    string_add_str(obj, "    struct Class *class = classOf(_self);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    assert(class->class);\n");
    string_add_str(obj, "    return class->class(_self);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "void *zircon_super_class(void *_class, void *_self) {\n");
    string_add_str(obj, "    struct Class *superclass = super(_class);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    assert(_self && superclass->class);\n");
    string_add_str(obj, "    return superclass->class(_self);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "void *zircon_superclass(void *_self) {\n");
    string_add_str(obj, "    struct Class *class = classOf(_self);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    assert(class->superclass);\n");
    string_add_str(obj, "    return class->superclass(_self);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "void *zircon_super_superclass(void *_class, void *_self) {\n");
    string_add_str(obj, "    struct Class *superclass = super(_class);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    assert(_self && superclass->superclass);\n");
    string_add_str(obj, "    return superclass->superclass(_self);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "bool zircon_is_a(void *_self, char *other) {\n");
    string_add_str(obj, "    struct Class *class = classOf(_self);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    assert(class->is_a);\n");
    string_add_str(obj, "    return class->is_a(_self, other);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "bool zircon_super_is_a(void *_class, void *_self, char *other) {\n");
    string_add_str(obj, "    struct Class *superclass = super(_class);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    assert(_self && superclass->is_a);\n");
    string_add_str(obj, "    return superclass->is_a(_self, other);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "char *zircon_to_string(void *_self) {\n");
    string_add_str(obj, "    struct Class *class = classOf(_self);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    assert(class->to_string);\n");
    string_add_str(obj, "    return class->to_string(_self);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "char *zircon_super_to_string(void *_class, void *_self) {\n");
    string_add_str(obj, "    struct Class *superclass = super(_class);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    assert(_self && superclass->to_string);\n");
    string_add_str(obj, "    return superclass->to_string(_self);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static void *Object_ctor(void *_self, va_list *app) {\n");
    string_add_str(obj, "    return _self;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static void *Object_dtor(void *_self) {\n");
    string_add_str(obj, "    return _self;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static bool Object_differ(void *_self, void *other) {\n");
    string_add_str(obj, "    return _self != other;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static bool Object_puto(void *_self, FILE *fd) {\n");
    string_add_str(obj, "    struct Class *self = classOf(_self);\n");
    string_add_str(obj, "    return fprintf(fd, \"%s at %p\\n\", self->name, _self);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static void *Object_class(void *_self) {\n");
    string_add_str(obj, "    struct Class *self = classOf(_self);\n");
    string_add_str(obj, "    return self;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static void *Object_superclass(void *_self) {\n");
    string_add_str(obj, "    struct Class *superclass = super(_self);\n");
    string_add_str(obj, "    return superclass;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static bool Object_is_a(void *_self, char *name) {\n");
    string_add_str(obj, "    struct Class *self = classOf(_self);\n");
    string_add_str(obj, "    return !strcmp(self->name, name);\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static char *Object_to_string(void *_self) {\n");
    string_add_str(obj, "    struct Class *self = classOf(_self);\n");
    string_add_str(obj, "    char *buf = (char*)malloc(sizeof(char) * 1024);\n");
    string_add_str(obj, "    sprintf(buf, \"@%s\", self->name);\n");
    string_add_str(obj, "    return buf;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static void *Class_ctor(void *_self, va_list *app) {\n");
    string_add_str(obj, "    struct Class *self = _self;\n");
    string_add_str(obj, "    size_t offset = offsetof(struct Class, ctor);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    self->name = va_arg(*app, char*);\n");
    string_add_str(obj, "    self->super = va_arg(*app, struct Class*);\n");
    string_add_str(obj, "    self->size = va_arg(*app, size_t);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    assert(self->super);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    memcpy((char*)self + offset, (char*)self->super + offset, sizeOf(self->super) - offset);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    typedef void (*voidf) ();\n");
    string_add_str(obj, "    voidf selector;\n");
    string_add_str(obj, "#ifdef va_copy\n");
    string_add_str(obj, "    va_list ap;\n");
    string_add_str(obj, "    va_copy(ap, *app);\n");
    string_add_str(obj, "#else\n");
    string_add_str(obj, "    va_list ap = *app;\n");
    string_add_str(obj, "#endif\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    while((selector = va_arg(ap, voidf))) {\n");
    string_add_str(obj, "        voidf method = va_arg(ap, voidf);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "        if(selector == (voidf)zircon_ctor)\n");
    string_add_str(obj, "            *(voidf*)&self->ctor = method;\n");
    string_add_str(obj, "        else if(selector == (voidf)zircon_dtor)\n");
    string_add_str(obj, "            *(voidf*)&self->dtor = method;\n");
    string_add_str(obj, "        else if(selector == (voidf)zircon_differ)\n");
    string_add_str(obj, "            *(voidf*)&self->differ = method;\n");
    string_add_str(obj, "        else if(selector == (voidf)zircon_puto)\n");
    string_add_str(obj, "            *(voidf*)&self->puto = method;\n");
    string_add_str(obj, "        else if(selector == (voidf)zircon_class)\n");
    string_add_str(obj, "            *(voidf*)&self->class = method;\n");
    string_add_str(obj, "        else if(selector == (voidf)zircon_superclass)\n");
    string_add_str(obj, "            *(voidf*)&self->superclass = method;\n");
    string_add_str(obj, "        else if(selector == (voidf)zircon_is_a)\n");
    string_add_str(obj, "            *(voidf*)&self->is_a = method;\n");
    string_add_str(obj, "        else if(selector == (voidf)zircon_to_string)\n");
    string_add_str(obj, "            *(voidf*)&self->to_string = method;\n");
    string_add_str(obj, "    }\n");
    string_add_str(obj, "#ifdef va_copy\n");
    string_add_str(obj, "    va_end(ap);\n");
    string_add_str(obj, "#endif\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    return self;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static void *Class_dtor(void *_self) {\n");
    string_add_str(obj, "    struct Class *self = _self;\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    fprintf(stderr, \"%s: cannot destroy class\\n\", self->name);\n");
    string_add_str(obj, "    return 0;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static void *zircon_new(void *_class, ...) {\n");
    string_add_str(obj, "    struct Class *class = _class;\n");
    string_add_str(obj, "    assert(class && class->size);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    struct Object *object;\n");
    string_add_str(obj, "    va_list ap;\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    object = (struct Object*)calloc(1, class->size);\n");
    string_add_str(obj, "    assert(object);\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "    object->class = class;\n");
    string_add_str(obj, "    va_start(ap, _class);\n");
    string_add_str(obj, "        object = zircon_ctor(object, &ap);\n");
    string_add_str(obj, "    va_end(ap);\n");
    string_add_str(obj, "    return object;\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static void zircon_defer(void *_self) {\n");
    string_add_str(obj, "    if(_self) free(zircon_dtor(_self));\n");
    string_add_str(obj, "}\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "static struct Class object [] = {\n");
    string_add_str(obj, "    {\n");
    string_add_str(obj, "        { object + 1 },\n");
    string_add_str(obj, "        \"Object\",\n");
    string_add_str(obj, "        object,\n");
    string_add_str(obj, "        sizeof(struct Object),\n");
    string_add_str(obj, "        Object_ctor,\n");
    string_add_str(obj, "        Object_dtor,\n");
    string_add_str(obj, "        Object_differ,\n");
    string_add_str(obj, "        Object_puto,\n");
    string_add_str(obj, "        Object_class,\n");
    string_add_str(obj, "        Object_superclass,\n");
    string_add_str(obj, "        Object_is_a,\n");
    string_add_str(obj, "        Object_to_string\n");
    string_add_str(obj, "    },\n");
    string_add_str(obj, "    {\n");
    string_add_str(obj, "        { object + 1 },\n");
    string_add_str(obj, "        \"Class\",\n");
    string_add_str(obj, "        object,\n");
    string_add_str(obj, "        sizeof(struct Class),\n");
    string_add_str(obj, "        Class_ctor,\n");
    string_add_str(obj, "        Class_dtor,\n");
    string_add_str(obj, "        Object_differ,\n");
    string_add_str(obj, "        Object_puto,\n");
    string_add_str(obj, "        Object_class,\n");
    string_add_str(obj, "        Object_superclass,\n");
    string_add_str(obj, "        Object_is_a,\n");
    string_add_str(obj, "        Object_to_string\n");
    string_add_str(obj, "    }\n");
    string_add_str(obj, "};\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "void *Object = object;\n");
    string_add_str(obj, "void *Class = object + 1;\n");
    string_add_str(obj, "\n");
    string_add_str(obj, "#endif\n");

    /*********************************/
    FILE *fp = fopen("Object.h", "w");
    fprintf(fp, "%s", string_get(obj));
    fclose(fp);
    /*********************************/
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

/**/
static void display_strings(char *item) {
    printf("    %s\n", item);
}
static void display_hashmap(hashmap *map) {
    hashmap_map(map, (lambda)display_strings, KEYS);
}
/**/

void delete_file(string *filename) {
    remove(string_get(filename));
}

void add_includes_to_tranlation(string *inc) {
    string_add_str(translation, "#include \"");
    string_add_str(translation, string_get(inc));
    string_add_str(translation, "\"\n");
}

void compile_file(char *file_to_compile) {
    int i;
    for(i = total_i_values; i < argc; i++) {

    __setup_hashmaps();
    /**/
    hashmap_add(typedef_names, "size_t", (void*)true);
    hashmap_add(typedef_names, "bool", (void*)true);
    /**/
    
    /* printf("\033[38;5;206mCompiling: `%s`\033[0m\n", argv[i]); */
    yyin = fopen(argv[i], "r");
    /* printf("\033[38;5;206mCompiling: `%s`\033[0m\n", file_to_compile); */
    /* yyin = fopen(file_to_compile, "r"); */
    translation = new_string("");

    /* Parse the text */
    yyparse();

    /* Write the init nodes */
    if(main_flag) {
        main_flag_was_set = true;
        vector_map(include_list_for_main, (lambda)add_includes_to_tranlation);
        __setup_init_objects();
        filename = new_string("__zircon_main.c");
        string_add_str(command, string_get(filename));
    }

    vector_add(files, filename);

    fp = fopen(string_get(filename), "w");
    fprintf(fp, "%s", string_get(translation));
    fclose(fp);

    /* @@@ */
    /* printf("\n\033[38;5;206mtypedef_names\033[0m\n");
    display_hashmap(typedef_names);
    printf("\n\033[38;5;206menum_constants\033[0m\n");
    display_hashmap(enum_constants);
    printf("\n\033[38;5;206mobject_names\033[0m\n");
    display_hashmap(object_names); */
    /* @@@ */

    }
}

int main(int _argc, char **_argv) {
    assert(_argc > 1 && _argv);
    argc = _argc;
    argv = _argv;

    /* Write the initial `Object.h` */
    __setup_initial_object();
    main_flag = false;
    main_flag_was_set = false;
    include_list_for_main = new_vector();

    /********************************/
    int i;
    files = new_vector();
    vector_add(files, new_string("Object.h"));
    command = new_string("gcc ");
    total_i_values = 2;

    /* Capture mode of compilation */
    mode = new_string(argv[1]);
    if(!string_equals(mode, new_string("run"))
    && !string_equals(mode, new_string("build"))
    && !string_equals(mode, new_string("spec"))
    && !string_equals(mode, new_string("init"))) {
        mode = new_string("run");
        total_i_values--;
    }
    
    /* Generate the c files only */
    do_not_compile = false;
    if(string_equals(new_string(argv[1]), new_string("-cfile"))) {
        total_i_values++;
        do_not_compile = true;
    }
    if(string_equals(string_substring(new_string(argv[1]), 0, 1), new_string("-o"))) {
        string *output_file = new_string(argv[1]);
        string_skip(output_file, 2);
        string_add_str(command, "-o ");
        string_add_str(command, string_get(output_file));
        string_add_char(command, ' ');
        total_i_values++;
    }

    compile_file(argv[total_i_values]);

    if(!do_not_compile && main_flag_was_set && string_equals(mode, new_string("build"))) {
        /* printf("\033[38;5;206mExecuting: `%s`\033[0m\n", string_get(command)); */
        system(string_get(command));
        vector_map(files, (lambda)delete_file);
    }
    else if(!do_not_compile && main_flag_was_set && string_equals(mode, new_string("run"))) {
        string_add_str(command, " && ./a.out && rm a.out");
        /* printf("\033[38;5;206mExecuting: `%s && ./a.out && rm a.out`\033[0m\n", string_get(command)); */
        system(string_get(command));
        vector_map(files, (lambda)delete_file);
    }
    /*********************************/
}
