#include "helpers/stdbool.h"
#include "helpers/vector.h"
#include "helpers/string.h"
#include "helpers/hashmap.h"
#include "helpers/stack.h"

#include <assert.h>
#include <stdio.h>

string *parsed;
vector *object_list;
vector *fields;

void check_inheritance(string *obj) {
    if(string_equals(parsed, obj)) {
        printf("inherits: %s\n", string_get(obj));
        string_delete(parsed);
    }
}

static void print_strings(string *str) {
    printf("field -> %s\n", string_get(str));
}

void parse(char c) {
    string_add_char(parsed, c);
    if(string_equals(parsed, new_string("model"))
    || string_equals(parsed, new_string("protocol"))
    || string_equals(parsed, new_string("object"))) {
        printf("definition keyword: %s\n", string_get(parsed));
        string_delete(parsed);
        return;
    }



    string *dup = string_dup(parsed);
    if(string_length(dup) > 10) {
        int i;
        for(i = 1; string_length(dup) - i >= 10; i++) {
            string_skip(dup, i);
            if(string_equals(dup, new_string("implements"))) {
                string_shorten(parsed, string_length(parsed) - 10);
                printf("name: %s\n", string_get(parsed));
                vector_add(object_list, string_dup(parsed));
                printf("keyword: implements\n");
                string_delete(parsed);
                return;
            }
        }
    }



    vector_map(object_list, (lambda)check_inheritance);
}

string *read_file(char *filename) {
    char ch;
    string *code = new_string("");
    FILE *fd = fopen(filename, "r");

    assert(fd);

    while((ch = fgetc(fd)) != EOF)
        if(ch != '\n' && ch != ' ')
            string_add_char(code, ch);

    fclose(fd);
    return code;
}

bool compile(string *input) {
    string_iterate(input, (lambda)parse);
    printf("%s\n", string_get(parsed));
    return 0;
}

static void __generate_object_boilerplate(void) {
    FILE *fd = fopen("object.h", "w");
    assert(fd);

    fputs("#ifndef __OBJECT_H_\n", fd);
    fputs("#define __OBJECT_H_\n\n", fd);
    
    fputs("#include <assert.h>\n", fd);
    fputs("#include <stdio.h>\n", fd);
    fputs("#include <stdlib.h>\n", fd);
    fputs("#include <string.h>\n", fd);
    fputs("#include <stdarg.h>\n", fd);
    fputs("#include <stddef.h>\n\n", fd);
    
    fputs("struct Object {\n", fd);
    fputs("    const struct Class *class;\n", fd);
    fputs("};\n", fd);
    fputs("struct Class {\n", fd);
    fputs("    const struct Object _;\n", fd);
    fputs("    const char *name;\n", fd);
    fputs("    const struct Class *super;\n", fd);
    fputs("    size_t size;\n", fd);
    fputs("    void *(*ctor)(void *self, va_list *app);\n", fd);
    fputs("    void *(*dtor)(void *self);\n", fd);
    fputs("    int (*differ)(const void *self, const void *other);\n", fd);
    fputs("    int (*puto)(const void *self, FILE *fd);\n", fd);
    fputs("};\n\n", fd);
    
    fputs("static void *new(const void *_class, ...);\n", fd);
    fputs("static void delete(void *_self);\n\n", fd);

    fputs("static const void *classOf(const void *_self) {\n", fd);
    fputs("    const struct Object *self = _self;\n\n", fd);
    fputs("    assert(_self && self && self->class);\n", fd);
    fputs("    return self->class;\n", fd);
    fputs("}\n\n", fd);
    
    fputs("static size_t sizeOf(const void *_self) {\n", fd);
    fputs("    const struct Class *class = classOf(_self);\n", fd);
    fputs("    return class->size;\n", fd);
    fputs("}\n\n", fd);
    
    fputs("static const void *super(const void *_self) {\n", fd);
    fputs("    const struct Class *self = _self;\n\n", fd);
    fputs("    assert(_self && self && self->super);\n", fd);
    fputs("    return self->super;\n", fd);
    fputs("}\n\n", fd);
    
    fputs("static void *new(const void *_class, ...) {\n", fd);
    fputs("    const struct Class *class = _class;\n", fd);
    fputs("    assert(class && class->size);\n\n", fd);
    fputs("    struct Object *object;\n", fd);
    fputs("    va_list ap;\n\n", fd);
    fputs("    object = (struct Object*)calloc(1, class->size);\n", fd);
    fputs("    va_start(ap, _class);\n", fd);
    fputs("        object = ctor(object, &ap);\n", fd);
    fputs("    va_end(ap);\n", fd);
    fputs("    return object;\n", fd);
    fputs("}\n\n", fd);

    fputs("static void delete(void *_self) {\n", fd);
    fputs("    if(_self) free(dtor(_self));\n", fd);
    fputs("}\n\n", fd);

    fputs("static const struct Class object [] = {\n", fd);
    fputs("    {\n", fd);
    fputs("        { object + 1 },\n", fd);
    fputs("        \"Object\",\n", fd);
    fputs("        object,\n", fd);
    fputs("        sizeof(struct Object),\n", fd);
    fputs("        Object_ctor,\n", fd);
    fputs("        Object_dtor,\n", fd);
    fputs("        Object_differ,\n", fd);
    fputs("        Object_puto,\n", fd);
    fputs("    },\n", fd);
    fputs("    {\n", fd);
    fputs("        { object + 1},\n", fd);
    fputs("        \"Class\",\n", fd);
    fputs("        object,\n", fd);
    fputs("        sizeof(struct Class),\n", fd);
    fputs("        Class_ctor,\n", fd);
    fputs("        Class_dtor,\n", fd);
    fputs("        Object_differ,\n", fd);
    fputs("        Object_puto,\n", fd);
    fputs("    }\n", fd);
    fputs("};\n\n", fd);

    fputs("const void *Object = object;\n", fd);
    fputs("const void *Class = object + 1;\n\n", fd);

    fputs("#endif", fd);

    fclose(fd);
}

static void __setup(void) {
    parsed = new_string("");
    object_list = new_vector();
    vector_add(object_list, new_string("Object"));

    __generate_object_boilerplate();
}

int main(int argc, char **argv) {
    assert(argv && argv[1]);

    __setup();
    string *input = read_file(argv[1]);
    return compile(input);
}
