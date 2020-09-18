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

#endif