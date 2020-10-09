#ifndef __MAIN_H_
#define __MAIN_H_

#include "includes.h"

static int _main(int _argc, char **_argv) {
    assert(_argc > 1 && _argv);
    argc = _argc;
    argv = _argv;

    /* Write the initial `Object.h` */
    __setup_initial_object();
    main_flag = false;
    main_flag_was_set = false;
    object_list_for_main = new_hashmap();

    /********************************/
    files = new_vector();
    vector_add(files, new_string("Object.h"));
    command = new_string("gcc ");
    string_add_str(command, "-Wno-format -Wno-empty-body -fno-strict-aliasing -Wno-maybe-uninitialized -Wno-unused-variable -Wno-return-type -Wno-missing-prototypes -Wno-unused-parameter -Wno-unused-function -Wno-cast-function-type ");
    string_add_str(command, "-march=native -O2 -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic ");

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

    /* compile_file(argv[total_i_values]); */
    compile_file();

    if(!do_not_compile && main_flag_was_set && string_equals(mode, new_string("build"))) {
        /* printf("\033[38;5;206mExecuting: `%s`\033[0m\n", string_get(command)); */
        system(string_get(command));
        vector_map(files, (vector_lambda)delete_file);
    }
    else if(!do_not_compile && main_flag_was_set && string_equals(mode, new_string("run"))) {
        string_add_str(command, " && ./a.out && rm a.out");
        /* printf("\033[38;5;206mExecuting: `%s && ./a.out && rm a.out`\033[0m\n", string_get(command)); */
        system(string_get(command));
        vector_map(files, (vector_lambda)delete_file);
    }
    /*********************************/

    return 0;
}

#endif
