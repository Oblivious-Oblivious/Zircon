#ifndef __COMPILER_H_
#define __COMPILER_H_

#include "includes.h"

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

static bool fix_lf(char c) {
    return (c != '\r' && c != '\n');
}
static string *remove_linefeed(string *str) {
    return string_filter(str, (string_lambda)fix_lf);
}

static void *display_char_ptr(void *item) {
    printf("    %s\n", (char*)item);
    return item;
}
static void display_hashmap(hashmap *map) {
    hashmap_map(map, (hashmap_lambda)display_char_ptr, KEYS);
}

static void *delete_file(string *filename) {
    remove(string_get(filename));
    return filename;
}

void *print_strings(void *item);

void *print_strings(void *item) {
    printf("type: `%s`\n", string_get(item));
    return item;
}
static void read_environment(void) {
    FILE *fp;
    char *env = malloc(sizeof(char) * 1024);

    /* TODO -> SECURITY ERROR, CAN OVERFLOW INPUT */
    fp = fopen("env.zdb", "r");
    if(fp != NULL)
        while(fgets(env, 1024, fp))
            hashmap_add(typedef_names, string_get(remove_linefeed(new_string(env))), (void*)true);

    fclose(fp);
}

static void compile_file(void) {
    int i;
    for(i = total_i_values; i < argc; i++) {
        __setup_hashmaps();
        /**/
        read_environment();
        /**/
        
        /* printf("\033[38;5;206mCompiling: `%s`\033[0m\n", argv[i]); */
        yyin = fopen(argv[i], "r");
        /* printf("\033[38;5;206mCompiling: `%s`\033[0m\n", file_to_compile); */
        /* yyin = fopen(file_to_compile, "r"); */
        translation = new_string("");
        init_calls = new_string("");

        /* Parse the text */
        yyparse();

        /* Write the init nodes */
        if(main_flag) {
            main_flag_was_set = true;
            filename = new_string("__zircon_main.c");
            string_add_str(command, string_get(filename));
        }

        vector_add(files, filename);

        fp = fopen(string_get(filename), "w");
        fprintf(fp, "%s", string_get(translation));
        fclose(fp);

        /* @@@ */
        /*
        printf("\n\033[38;5;206mtypedef_names\033[0m\n");
        display_hashmap(typedef_names);
        printf("\n\033[38;5;206menum_constants\033[0m\n");
        display_hashmap(enum_constants);
        printf("\n\033[38;5;206mobject_names\033[0m\n");
        display_hashmap(object_names);
        */
        /* @@@ */
    }

    /* Add the __setup_init_objects() function into the main file */
    if(main_flag_was_set) {
        __setup_init_objects();
        fp = fopen("__zircon_main.c", "a");
        fprintf(fp, "%s", string_get(init_calls));
        fclose(fp);
    }
}

#endif
