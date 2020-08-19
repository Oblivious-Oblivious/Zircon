#ifndef __STRING_H_
#define __STRING_H_

#include <stdio.h> /* snprintf */
#include <stdlib.h> /* malloc, calloc, realloc, free */
/* TODO -> REPLACE WITH CUSTOM FUNCTIONS */
#include <string.h> /* memmove, strlen */
#include <stdarg.h> /* va_arg, va_start, va_end */

#include "vector.h"

#define PP_256TH_ARG( \
    _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
    _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
    _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
    _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
    _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
    _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
    _61,_62,_63,_64,_65,_66,_67,_68,_69,_70, \
    _71,_72,_73,_74,_75,_76,_77,_78,_79,_80, \
    _81,_82,_83,_84,_85,_86,_87,_88,_89,_90, \
    _91,_92,_93,_94,_95,_96,_97,_98,_99,_100, \
    _101,_102,_103,_104,_105,_106,_107,_108,_109,_110, \
    _111,_112,_113,_114,_115,_116,_117,_118,_119,_120, \
    _121,_122,_123,_124,_125,_126,_127,_128,_129,_130, \
    _131,_132,_133,_134,_135,_136,_137,_138,_139,_140, \
    _141,_142,_143,_144,_145,_146,_147,_148,_149,_150, \
    _151,_152,_153,_154,_155,_156,_157,_158,_159,_160, \
    _161,_162,_163,_164,_165,_166,_167,_168,_169,_170, \
    _171,_172,_173,_174,_175,_176,_177,_178,_179,_180, \
    _181,_182,_183,_184,_185,_186,_187,_188,_189,_190, \
    _191,_192,_193,_194,_195,_196,_197,_198,_199,_200, \
    _201,_202,_203,_204,_205,_206,_207,_208,_209,_210, \
    _211,_212,_213,_214,_215,_216,_217,_218,_219,_220, \
    _221,_222,_223,_224,_225,_226,_227,_228,_229,_230, \
    _231,_232,_233,_234,_235,_236,_237,_238,_239,_240, \
    _241,_242,_243,_244,_245,_246,_247,_248,_249,_250, \
    _251,_252,_253,_254,_255,N,...) N
#define PP_RSEQ_N() \
    255,254,253,252,251,250, \
    249,248,247,246,245,244,243,242,241,240, \
    239,238,237,236,235,234,233,232,231,230, \
    229,228,227,226,225,224,223,222,221,220, \
    219,218,217,216,215,214,213,212,211,210, \
    209,208,207,206,205,204,203,202,201,200, \
    199,198,197,196,195,194,193,192,191,190, \
    189,188,187,186,185,184,183,182,181,180, \
    179,178,177,176,175,174,173,172,171,170, \
    169,168,167,166,165,164,163,162,161,160, \
    159,158,157,156,155,154,153,152,151,150, \
    149,148,147,146,145,144,143,142,141,140, \
    139,138,137,136,135,134,133,132,131,130, \
    129,128,127,126,125,124,123,122,121,120, \
    119,118,117,116,115,114,113,112,111,110, \
    109,108,107,106,105,104,103,102,101,100, \
    99,98,97,96,95,94,93,92,91,90, \
    89,88,87,86,85,84,83,82,81,80, \
    79,78,77,76,75,74,73,72,71,70, \
    69,68,67,66,65,64,63,62,61,60, \
    59,58,57,56,55,54,53,52,51,50, \
    49,48,47,46,45,44,43,42,41,40, \
    39,38,37,36,35,34,33,32,31,30, \
    29,28,27,26,25,24,23,22,21,20, \
    19,18,17,16,15,14,13,12,11,10, \
    9,8,7,6,5,4,3,2,1,0
    
#define PP_NARG_(...) \
    PP_256TH_ARG(__VA_ARGS__)
#define PP_NARG(...) \
    PP_NARG_(__VA_ARGS__,PP_RSEQ_N())

#define puts(...) display(PP_NARG(__VA_ARGS__), __VA_ARGS__)

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

#define new_string(initial_string) string_create(initial_string)

void string_add_str(string *sb, const char *str);

static void string_ensure_space(string *sb, size_t add_len) {
    if(sb == NULL || add_len == 0) return;

    /* If out allocated space is big enough */
    if(sb->alloced >= sb->length+add_len + 1) return;

    while (sb->alloced < sb->length+add_len + 1) {
        /* Doubling growth strategy */
        sb->alloced <<= 1;
        if(sb->alloced == 0) {
            /* Left shift of max bits will go to 0. An unsigned type set to
             * -1 will return the maximum possible size. However, we should
             *  have run out of memory well before we need to do this. Since
             *  this is the theoretical maximum total system memory we don't
             *  have a flag saying we can't grow any more because it should
             *  be impossible to get to this point */
            sb->alloced--;
        }
    }
    sb->str = (char*)realloc(sb->str, sb->alloced);
}

string *string_create(char *initial_string) {
    string *sb = (string*)calloc(1, sizeof(*sb));
    sb->str = (char*)malloc(string_init_capacity);

    /* NULL terminate the string */
    *sb->str = '\0';

    sb->alloced = string_init_capacity;
    sb->length = 0;

    string_add_str(sb, initial_string);
    return sb;
}

void string_add_str(string *sb, const char *str) {
    if(sb == NULL || str == NULL || *str == '\0') return;

    size_t len = strlen(str);
    string_ensure_space(sb, len);

    /* Copy the value into memory */
    memmove(sb->str+sb->length, str, len);

    /* Reset length and NULL terminate */
    sb->length += len;
    sb->str[sb->length] = '\0';
}

void string_add_char(string *sb, char c) {
    if(sb == NULL) return;

    /* In any case we try to overflow the input */
    if(c > 255 || c < 0) return;

    string_ensure_space(sb, 1);

    sb->str[sb->length] = c;
    sb->length++;
    sb->str[sb->length] = '\0';
}

void string_add_int(string *sb, int val) {
    char str[1024];

    if(sb == NULL) return;

    snprintf(str, sizeof(str), "%d", val);
    string_add_str(sb, str);
}

void string_add_double_precision(string *sb, double val) {
    char str[1024];

    if(sb == NULL) return;

    /* Use %g for minimum precision on printing floats */
    snprintf(str, sizeof(str), "%g", val);
    string_add_str(sb, str);
}

char *string_get(string *sb) {
    if(sb == NULL) return NULL;
    return sb->str;
}

char string_get_char_at_index(string *sb, size_t index) {
    if(sb == NULL || index < 0) return '\0';
    return sb->str[index];
}

void string_shorten(string *sb, size_t len) {
    if(sb == NULL || len >= sb->length) return;

    /* Reset the length and NULL terminate, ingoring
        all values right to the NULL from memory */
    sb->length = len;
    sb->str[sb->length] = '\0';
}

void string_delete(string *sb) {
    if(sb == NULL) return;

    /* Call truncate with 0, clearing out the string */
    string_shorten(sb, 0);
}

void string_skip(string *sb, size_t len) {
    if(sb == NULL || len == 0) return;

    if(len >= sb->length) {
        /* If we choose to drop more bytes than the
            string has simply clear the string */
        string_delete(sb);
        return;
    }

    sb->length -= len;

    /* +1 to move the NULL. */
    memmove(sb->str, sb->str + len, sb->length + 1);
}

size_t string_length(string *sb) {
    if(sb == NULL) return 0;
    return sb->length;
}

string *string_dup(string *sb) {
    if(sb == NULL) return NULL;

    string *dup = new_string("");
    string_add_str(dup, string_get(sb));

    return dup;
}

vector *string_split(string *str, string *delimeter) {
	vector *str_tokens = new_vector();
	string *token_str = new_string("");

	/* Iterate through the chars constructing a string and
		reseting the value once we find the delimeter */
	size_t i;
	for(i = 0; (i <= string_length(str)
	&& string_get_char_at_index(str, i) != '\0'); i++) {
		if(string_get_char_at_index(str, i) == string_get(delimeter)[0]) {
			/* We found a character matching the delimeter */
			vector_add(str_tokens, token_str);

			/* Reset the temp string */
			token_str = new_string("");
			continue;
		}

		string_add_char(token_str, string_get_char_at_index(str, i));
	}

	/* We add the last collected characters */
	vector_add(str_tokens, token_str);
	return str_tokens;
}

string *string_substring(string *str, size_t from, size_t __to) {
    string *strdup = string_dup(str);
    string_skip(strdup, from);
    string_shorten(strdup, __to - from + 1);
    return strdup;
}

void display(size_t argc, ...) {
    string *sb = new_string("");
    
    va_list vars;
    va_start(vars, argc);
        int i;
        for(i = 0; i < argc; i++)
            string_add_str(sb, va_arg(vars, void*));
    va_end(vars);
    
    printf("displaying: %s\n", string_get(sb));
    string_delete(sb);
}

string *string_iterate(string *sb, lambda apply) {
    /* TODO -> Convert check to asserts */
    if(sb == NULL || apply == NULL) return NULL;

    char *sb_str = string_get(sb);

    size_t i;
    for(i = 0; i < string_length(sb); i++)
        apply(sb_str[i]);
}

#endif
