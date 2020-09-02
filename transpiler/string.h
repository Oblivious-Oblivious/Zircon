#ifndef __STRING_H_
#define __STRING_H_

#include <stdio.h> /* snprintf */
#include <stdlib.h> /* malloc, calloc, realloc, free */

/* TODO -> REPLACE WITH CUSTOM FUNCTIONS */
#include <string.h> /* memmove, strlen */
#include <stdarg.h> /* va_arg, va_start, va_end */

#include "vector.h"

typedef char (*stringlambda)(char);

/** The initial minimum size of a string **/
static const size_t string_init_capacity = 32;

/**
 * @struct: string
 * @desc: A mutable string of characters used to dynamically build a string.
 * @param str -> The str char* we construct our string into
 * @param alloced -> The total sized allocated for the string
 * @param length -> The total length of the string
 **/
typedef struct string {
    char *str;
    size_t alloced;
    size_t length;
} string;

static void string_ensure_space(string *sb, size_t add_len);
string *new_string(char *initial_string);
void string_add_str(string *sb, const char *str);
void string_add_char(string *sb, char c);
void string_add_int(string *sb, int val);
void string_add_double_precision(string *sb, double val);
char *string_get(string *sb);
char string_get_char_at_index(string *sb, size_t index);
void string_shorten(string *sb, size_t len);
void string_delete(string *sb);
void string_skip(string *sb, size_t len);
size_t string_length(string *sb);
unsigned char string_equals(string *sb, string *other);
string *string_dup(string *sb);
vector *string_split(string *str, string *delimeter);
string *string_substring(string *str, size_t from, size_t __to);
string *string_iterate(string *sb, lambda apply);
string *string_map(string *sb, stringlambda modifier);
char *string_identifier(string *sb);

#endif
