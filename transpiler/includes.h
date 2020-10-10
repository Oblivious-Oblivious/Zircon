#ifndef __INCLUDES_H_
#define __INCLUDES_H_

/* Base includes */
#include <assert.h> /* assert */
#include <stdio.h> /* FILE, fprintf */
#include <stdlib.h> /* malloc, calloc */
#include <string.h>

/* Custom data structures */
#include "stdboolean.h"
#include "string.h"
#include "hashmap.h"

/* Parser definitions */
int yylex(void);
int yyparse(void);
void yyerror(char*);

/* External definitions */
static void *delete_file(string *filename);

/* Result of the parsed file */
string *translation;
string *init_calls;
string *filename;
bool main_flag = false;
vector *files;
hashmap *object_list_for_main;

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

#endif
