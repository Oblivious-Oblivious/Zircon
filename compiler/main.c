#include <stdlib.h>

#include "helpers/stdbool.h"
#include "helpers/vector.h"
#include "helpers/string.h"
#include "helpers/hashmap.h"
#include "helpers/stack.h"

vector *operators;
vector *keywords;
string *delimeters;

string *identifier;

enum tokens {
    OPERATOR,
    KEYWORD,
    DELIMETER
};

static bool emit(enum tokens token, string *str) {
    if(string_equals(str, new_string(""))) return 1;
    switch(token) {
        case OPERATOR:  return printf("operator: `%s`\n", string_get(str));
        case KEYWORD:   return printf("keyword: `%s`\n", string_get(str));
        case DELIMETER: return printf("delimeter: `%s`\n", string_get(str));
        default: return 0;
    }
}

static bool is_valid_delimeter(string *token) {
    char *str = string_get(token);
    switch(str[0]) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            return false;
        default: return true;
    }
}

bool is_delimeter(string *token, string *identifier) {
    if(string_equals(token, new_string(" "))) {
        if(is_valid_delimeter(identifier)) {
            emit(DELIMETER, identifier);
            string_delete(identifier);
            return true;
        }
        else if(!string_equals(identifier, new_string(""))) {
            printf("Invalid identifier: %s\n", string_get(identifier));
            string_delete(identifier);
            return true;
        }
    }
    return false;
}

bool is_keyword(string *token, string *identifier) {
    int i;
    for(i = 0; i < vector_length(keywords); i++) {
        if(string_equals(vector_get(keywords, i), identifier)) {
            if(string_equals(token, new_string(" "))) {
                emit(KEYWORD, identifier);
                string_delete(identifier);
                return true;
            }
        }
    }
    return false;
}

bool is_operator(string *token) {
    int i;
    for(i = 0; i < vector_length(operators); i++) {
        if(string_equals(vector_get(operators, i), token)) {
            emit(OPERATOR, token);
            return true;
        }
    }
    return false;
}

void lexer(char c) {
    string *token = new_string("");
    string_add_char(token, c);

    if(is_operator(token)) return;
    if(is_keyword(token, identifier)) return;
    if(is_delimeter(token, identifier)) return;
    else string_add_char(identifier, c);
}

string *read_file(void) {
    return new_string("int a = b + 42c;");
}

bool compile(string *input) {
    string_add_char(input, ' ');
    string_iterate(input, (lambda)lexer);
}

static void __setup_operators(void) {
    operators = new_vector();

    /* Arithmetic */
    vector_add(operators, new_string("+"));
    vector_add(operators, new_string("-"));
    vector_add(operators, new_string("*"));
    vector_add(operators, new_string("/"));
    vector_add(operators, new_string("%"));
    vector_add(operators, new_string("++"));
    vector_add(operators, new_string("--"));

    /* Relational */
    vector_add(operators, new_string("=="));
    vector_add(operators, new_string("!="));
    vector_add(operators, new_string(">"));
    vector_add(operators, new_string("<"));
    vector_add(operators, new_string(">="));
    vector_add(operators, new_string("<="));

    /* Logical */
    vector_add(operators, new_string("&&"));
    vector_add(operators, new_string("||"));
    vector_add(operators, new_string("!"));

    /* Bitwise */
    vector_add(operators, new_string("&"));
    vector_add(operators, new_string("|"));
    vector_add(operators, new_string("^"));
    vector_add(operators, new_string("<<"));
    vector_add(operators, new_string(">>"));

    /* Assignment */
    vector_add(operators, new_string("="));
    vector_add(operators, new_string("+="));
    vector_add(operators, new_string("-="));
    vector_add(operators, new_string("*="));
    vector_add(operators, new_string("/="));
    vector_add(operators, new_string("%="));

    /* Conditional */
    vector_add(operators, new_string("?"));

    /* Pointer */
    vector_add(operators, new_string("sizeof"));
    vector_add(operators, new_string("&"));
    vector_add(operators, new_string("*"));
}

static void __setup_keywords(void) {
    keywords = new_vector();

    /* ANSI C */
    vector_add(keywords, new_string("auto"));
    vector_add(keywords, new_string("break"));
    vector_add(keywords, new_string("case"));
    vector_add(keywords, new_string("char"));
    vector_add(keywords, new_string("const"));
    vector_add(keywords, new_string("continue"));
    vector_add(keywords, new_string("default"));
    vector_add(keywords, new_string("do"));
    vector_add(keywords, new_string("double"));
    vector_add(keywords, new_string("else"));
    vector_add(keywords, new_string("enum"));
    vector_add(keywords, new_string("extern"));
    vector_add(keywords, new_string("float"));
    vector_add(keywords, new_string("for"));
    vector_add(keywords, new_string("goto"));
    vector_add(keywords, new_string("if"));
    vector_add(keywords, new_string("int"));
    vector_add(keywords, new_string("long"));
    vector_add(keywords, new_string("register"));
    vector_add(keywords, new_string("return"));
    vector_add(keywords, new_string("short"));
    vector_add(keywords, new_string("signed"));
    vector_add(keywords, new_string("sizeof"));
    vector_add(keywords, new_string("static"));
    vector_add(keywords, new_string("struct"));
    vector_add(keywords, new_string("switch"));
    vector_add(keywords, new_string("typedef"));
    vector_add(keywords, new_string("union"));
    vector_add(keywords, new_string("unsigned"));
    vector_add(keywords, new_string("void"));
    vector_add(keywords, new_string("volatile"));
    vector_add(keywords, new_string("while"));

    /* C99 */
    vector_add(keywords, new_string("_Bool"));
    vector_add(keywords, new_string("_Complex"));
    vector_add(keywords, new_string("_Imaginary"));
    vector_add(keywords, new_string("inline"));
    vector_add(keywords, new_string("restrict"));

    /* C11 */
    vector_add(keywords, new_string("_Alignas"));
    vector_add(keywords, new_string("_Alignof"));
    vector_add(keywords, new_string("_Atomic"));
    vector_add(keywords, new_string("_Generic"));
    vector_add(keywords, new_string("_Noreturn"));
    vector_add(keywords, new_string("_Static_assert"));
    vector_add(keywords, new_string("_Thread_local"));
}

static void __setup_token_descriptors(void) {
    __setup_operators();
    __setup_keywords();

    identifier = new_string("");
}

int main(void) {
    __setup_token_descriptors();

    string *input = read_file();
    printf("input: `%s`\n\n", string_get(input));
    return compile(input);
}
