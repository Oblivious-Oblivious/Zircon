#ifndef __OBJECT_TRANSLATION_H_
#define __OBJECT_TRANSLATION_H_

#include "includes.h"

static string *translate_object(string *name_of_object, string *parent_object, vector *object_parameter_list, vector *declaration_list) {
    string *object_translation_unit = new_string("");
    main_flag = false;

    filename = string_dup(name_of_object);
    string_add_str(filename, ".h");

    /************/
    vector *object_fields = vector_get(declaration_list, 0);
    vector *object_messages = vector_get(declaration_list, 1);
    /************/

    hashmap_add(typedef_names, string_get(string_dup(name_of_object)), (void*)true);
    hashmap_add(object_names, string_get(string_dup(name_of_object)), (void*)true);

    /* Translate the parsed data */
    string_add_str(object_translation_unit, "\n#ifndef __");
    string_add_str(object_translation_unit, string_get(name_of_object));
    string_add_str(object_translation_unit, "_\n");
    string_add_str(object_translation_unit, "#define __");
    string_add_str(object_translation_unit, string_get(name_of_object));
    string_add_str(object_translation_unit, "_\n\n");

    string_add_str(object_translation_unit, "/* INDLUDE SUPER */\n");
    string_add_str(object_translation_unit, "#include \"");
    string_add_str(object_translation_unit, string_get(parent_object));
    string_add_str(object_translation_unit, ".h\"\n\n");
    string_add_str(object_translation_unit, "/* REPRESENTATION */\n");
    string_add_str(object_translation_unit, "struct ");
    string_add_str(object_translation_unit, string_get(name_of_object));
    string_add_str(object_translation_unit, " {\n    struct ");
    string_add_str(object_translation_unit, string_get(parent_object));
    string_add_str(object_translation_unit, " _;\n");

    /* Create the include file */
    if(!string_equals(parent_object, new_string("Object"))) {
        string *filename = string_dup(parent_object);
        string_add_str(filename, ".h");
        FILE *fp = fopen(string_get(filename), "w");
        fclose(fp);
        vector_add(files, filename);
    }

    size_t i;
    for(i = 0; i < vector_length(object_fields); i++) {
        vector *field = vector_get(object_fields, i);
        string_add_str(object_translation_unit, "    ");
        string_add_str(object_translation_unit, string_get(vector_get(field, 0)));
        string_add_str(object_translation_unit, string_get(vector_get(field, 1)));
        string_add_str(object_translation_unit, ";\n");
    }
    string_add_str(object_translation_unit, "};\n");

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
        string_add_str(object_translation_unit, "struct ");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "Class {\n");

        if(string_equals(parent_object, new_string("Object")))
            string_add_str(inherited_class, "Class");
        else {
            string_add_str(inherited_class, string_get(parent_object));
            string_add_str(inherited_class, "Class");
        }
        string_add_str(object_translation_unit, "    struct ");
        string_add_str(object_translation_unit, string_get(inherited_class));
        string_add_str(object_translation_unit, " _;\n");
        for(i = 0; i < vector_length(object_messages); i++) {
            vector *message = vector_get(object_messages, i);
            if(!string_equals(vector_get(message, 2), new_string("new"))
            && !string_equals(vector_get(message, 2), new_string("defer"))
            && !string_equals(vector_get(message, 1), new_string("super "))) {
                string_add_str(object_translation_unit, "    ");
                string_add_str(object_translation_unit, string_get(vector_get(message, 0)));
                string_add_str(object_translation_unit, " (*");
                string_add_str(object_translation_unit, string_get(vector_get(message, 2)));
                if(string_length(vector_get(message, 3)) == 0)
                    string_add_str(object_translation_unit, ")(void *self");
                else {
                    string_add_str(object_translation_unit, ")(void *self");
                    vector *message_fields = vector_get(message, 3);
                    size_t j;
                    for(j = 0; j < vector_length(message_fields); j++) {
                        string_add_str(object_translation_unit, ", ");
                        vector *current_message_fields = vector_get(message_fields, j);
                        string_add_str(object_translation_unit, string_get(vector_get(current_message_fields, 0)));
                        string_add_str(object_translation_unit, string_get(vector_get(current_message_fields, 1)));
                    }
                }
                string_add_str(object_translation_unit, ");\n");
            }
        }
        string_add_str(object_translation_unit, "};");
    }

    string_add_str(object_translation_unit, "\n\n");
    string_add_str(object_translation_unit, "/* DECLARATIONS */\n");
    string_add_str(object_translation_unit, "void *");
    string_add_str(object_translation_unit, string_get(name_of_object));
    string_add_str(object_translation_unit, ";\n");
    if(locally_defined_messages != 0) {
        string_add_str(object_translation_unit, "void *");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "Class;\n");
    }

    string_add_str(object_translation_unit, "\n/* SELECTORS */\n");
    if(locally_defined_messages != 0) {
        for(i = 0; i < vector_length(object_messages); i++) {
            vector *message = vector_get(object_messages, i);
            if(!string_equals(vector_get(message, 2), new_string("new"))
            && !string_equals(vector_get(message, 2), new_string("defer"))
            && !string_equals(vector_get(message, 1), new_string("super "))) {
                /* Write base call */
                string_add_str(object_translation_unit, string_get(vector_get(message, 0)));

                /* Add an identifier to avoid name collisions */
                string_add_str(object_translation_unit, "zircon_");

                string_add_str(object_translation_unit, string_get(vector_get(message, 2)));
                if(string_length(vector_get(message, 3)) == 0)
                    string_add_str(object_translation_unit, "(void *_self");
                else {
                    string_add_str(object_translation_unit, "(void *_self");
                    vector *message_fields = vector_get(message, 3);
                    size_t j;
                    for(j = 0; j < vector_length(message_fields); j++) {
                        string_add_str(object_translation_unit, ", ");
                        vector *current_message_fields = vector_get(message_fields, j);
                        string_add_str(object_translation_unit, string_get(vector_get(current_message_fields, 0)));
                        string_add_str(object_translation_unit, string_get(vector_get(current_message_fields, 1)));
                    }
                }
                string_add_str(object_translation_unit, ") {\n");
                string_add_str(object_translation_unit, "    struct ");
                string_add_str(object_translation_unit, string_get(name_of_object));
                string_add_str(object_translation_unit, "Class *class = classOf(_self);\n\n");
                string_add_str(object_translation_unit, "    assert(class->");

                string *name = vector_get(message, 2);
                string_add_str(object_translation_unit, string_get(name));
                string_add_str(object_translation_unit, ");\n");
                string_add_str(object_translation_unit, "    return class->");
                string_add_str(object_translation_unit, string_get(name));
                string_add_str(object_translation_unit, "(_self");
                vector *message_fields = vector_get(message, 3);
                size_t j;
                for(j = 0; j < vector_length(message_fields); j++) {
                    string_add_str(object_translation_unit, ", ");
                    vector *current_message_fields = vector_get(message_fields, j);
                    string_add_str(object_translation_unit, string_get(vector_get(current_message_fields, 1)));
                }
                string_add_str(object_translation_unit, ");\n}\n");

                /* Write super call */
                string_add_str(object_translation_unit, string_get(vector_get(message, 0)));

                /* Add an identifier to avoid name collisions */
                string_add_str(object_translation_unit, "zircon_");

                string_add_str(object_translation_unit, "super_");
                string_add_str(object_translation_unit, string_get(vector_get(message, 2)));
                if(string_length(vector_get(message, 3)) == 0)
                    string_add_str(object_translation_unit, "(void *_class, void *_self");
                else {
                    string_add_str(object_translation_unit, "(void *_class, void *_self");
                    vector *message_fields = vector_get(message, 3);
                    size_t j;
                    for(j = 0; j < vector_length(message_fields); j++) {
                        string_add_str(object_translation_unit, ", ");
                        vector *current_message_fields = vector_get(message_fields, j);
                        string_add_str(object_translation_unit, string_get(vector_get(current_message_fields, 0)));
                        string_add_str(object_translation_unit, string_get(vector_get(current_message_fields, 1)));
                    }
                }
                string_add_str(object_translation_unit, ") {\n");
                string_add_str(object_translation_unit, "    struct ");
                string_add_str(object_translation_unit, string_get(name_of_object));
                string_add_str(object_translation_unit, "Class *superclass = super(_class);\n\n");
                string_add_str(object_translation_unit, "    assert(_self && superclass->");
                string_add_str(object_translation_unit, string_get(name));
                string_add_str(object_translation_unit, ");\n");
                string_add_str(object_translation_unit, "    return superclass->");
                string_add_str(object_translation_unit, string_get(name));
                string_add_str(object_translation_unit, "(_self");
                for(j = 0; j < vector_length(message_fields); j++) {
                    string_add_str(object_translation_unit, ", ");
                    vector *current_message_fields = vector_get(message_fields, j);
                    string_add_str(object_translation_unit, string_get(vector_get(current_message_fields, 1)));
                }
                string_add_str(object_translation_unit, ");\n}\n");
            }
        }
    }

    string_add_str(object_translation_unit, "\n/* METHODS */\n");
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
        string_add_str(object_translation_unit, "void *");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "_ctor(void *_self, va_list *app) {\n");
        string_add_str(object_translation_unit, "    struct ");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, " *self = zircon_super_ctor(");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, ", _self, app);\n\n");

        /***********************************************/
        size_t k;
        for(k = 0; k < vector_length(object_parameter_list); k++) {
            vector *current_parameter = vector_get(object_parameter_list, k);
            string_add_str(object_translation_unit, string_get(vector_get(current_parameter, 0)));
            string_add_str(object_translation_unit, string_get(vector_get(current_parameter, 1)));
            string_add_str(object_translation_unit, " = va_arg(*app, ");
            string_add_str(object_translation_unit, string_get(vector_get(current_parameter, 0)));
            string_add_str(object_translation_unit, ");\n");
        }
        /***********************************************/
        string_add_str(object_translation_unit, string_get(method_on_new));

        string_add_str(object_translation_unit, "    return self;\n}\n");
    }
    if(destructor_is_overriden) {
        string_add_str(object_translation_unit, "void *");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "_dtor(void *_self) {\n");
        string_add_str(object_translation_unit, "    struct ");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, " *self = zircon_super_dtor(");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, ", _self);\n\n");
        string_add_str(object_translation_unit, string_get(method_on_defer));
        string_add_str(object_translation_unit, "\n    return 0;\n}\n");
    }

    for(i = 0; i < vector_length(object_messages); i++) {
        vector *message = vector_get(object_messages, i);
        if(string_equals(vector_get(message, 2), new_string("new"))
        || string_equals(vector_get(message, 2), new_string("defer")))
            continue;
        string_add_str(object_translation_unit, string_get(vector_get(message, 0)));
        string_add_char(object_translation_unit, ' ');
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "_");
        string_add_str(object_translation_unit, string_get(vector_get(message, 2)));
        if(string_length(vector_get(message, 3)) == 0)
            string_add_str(object_translation_unit, "(void *_self");
        else {
            string_add_str(object_translation_unit, "(void *_self");
            vector *message_fields = vector_get(message, 3);
            size_t j;
            for(j = 0; j < vector_length(message_fields); j++) {
                string_add_str(object_translation_unit, ", ");
                vector *current_message_fields = vector_get(message_fields, j);
                string_add_str(object_translation_unit, string_get(vector_get(current_message_fields, 0)));
                void *is_message_an_object = vector_get(current_message_fields, 2);
                if(is_message_an_object)
                    string_add_char(object_translation_unit, '_');
                string_add_str(object_translation_unit, string_get(vector_get(current_message_fields, 1)));
            }
        }
        string_add_str(object_translation_unit, ") {\n");
        string_add_str(object_translation_unit, "struct ");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, " *self = _self;\n");
        string_add_str(object_translation_unit, "struct ");
        string_add_str(object_translation_unit, string_get(parent_object));
        string_add_str(object_translation_unit, " *super = (struct ");
        string_add_str(object_translation_unit, string_get(parent_object));
        string_add_str(object_translation_unit, "*)self;\n\n");
        vector *message_fields = vector_get(message, 3);
        size_t j;
        for(j = 0; j < vector_length(message_fields); j++) {
            /* Check forobject parameter */
            vector *current_message_fields = vector_get(message_fields, j);
            string *current_message_name = vector_get(current_message_fields, 1);
            void *is_message_an_object = vector_get(current_message_fields, 2);
            if(is_message_an_object) {
                string_add_str(object_translation_unit, "struct ");
                string_add_str(object_translation_unit, string_get(name_of_object));
                string_add_str(object_translation_unit, " *");
                string_add_str(object_translation_unit, string_get(current_message_name));
                string_add_str(object_translation_unit, " = _");
                string_add_str(object_translation_unit, string_get(current_message_name));
                string_add_str(object_translation_unit, ";\n");
            }
        }
        string_add_str(object_translation_unit, string_get(vector_get(message, 4)));
        string_add_str(object_translation_unit, "}\n\n");
    }

    if(locally_defined_messages != 0) {
        string_add_str(object_translation_unit, "void *");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "Class_ctor(void *_self, va_list *app) {\n");
        string_add_str(object_translation_unit, "    struct ");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "Class *self = zircon_super_ctor(");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "Class, _self, app);\n\n");
        string_add_str(object_translation_unit, "    typedef void (*voidf)();\n");
        string_add_str(object_translation_unit, "    voidf selector;\n");
        string_add_str(object_translation_unit, "#ifdef va_copy\n");
        string_add_str(object_translation_unit, "    va_list ap;\n");
        string_add_str(object_translation_unit, "    va_copy(ap, *app);\n");
        string_add_str(object_translation_unit, "#else\n");
        string_add_str(object_translation_unit, "    va_list ap = *app;\n");
        string_add_str(object_translation_unit, "#endif\n");
        string_add_str(object_translation_unit, "    while((selector = va_arg(ap, voidf))) {\n");
        string_add_str(object_translation_unit, "        voidf method = va_arg(ap, voidf);\n\n");
        for(i = 0; i < vector_length(object_messages); i++) {
            vector *message = vector_get(object_messages, i);
            if(string_equals(vector_get(message, 2), new_string("new"))
            || string_equals(vector_get(message, 2), new_string("defer"))
            || string_equals(vector_get(message, 1), new_string("super ")))
                continue;
            string_add_str(object_translation_unit, "        if(selector == (voidf)");

            /* Add an identifier to avoid name collisions */
            string_add_str(object_translation_unit, "zircon_");

            string_add_str(object_translation_unit, string_get(vector_get(message, 2)));
            string_add_str(object_translation_unit, ")\n");
            string_add_str(object_translation_unit, "            *(voidf*)&self->");
            string_add_str(object_translation_unit, string_get(vector_get(message, 2)));
            string_add_str(object_translation_unit, " = method;\n");
        }
        string_add_str(object_translation_unit, "    }\n");
        string_add_str(object_translation_unit, "#ifdef va_copy\n");
        string_add_str(object_translation_unit, "    va_end(ap);\n");
        string_add_str(object_translation_unit, "#endif\n\n");
        string_add_str(object_translation_unit, "    return self;\n");
        string_add_str(object_translation_unit, "}\n");
    }

    string_add_str(object_translation_unit, "/* INITIALIZATION */\n");
    string_add_str(object_translation_unit, "void __init_");
    string_add_str(object_translation_unit, string_get(name_of_object));
    string_add_str(object_translation_unit, "(void) {\n");
    if(!string_equals(parent_object, new_string("Object"))) {
        string_add_str(object_translation_unit, "__init_");
        string_add_str(object_translation_unit, string_get(parent_object));
        string_add_str(object_translation_unit, "();\n");
    }

    if(locally_defined_messages != 0) {
        string_add_str(object_translation_unit, "if(!");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "Class) ");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "Class = zircon_new(");
        string_add_str(object_translation_unit, "Class,\n");
        string_add_char(object_translation_unit, '\"');
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "Class\",\n");
        if(!string_equals(parent_object, new_string("Object"))) {
            string_add_str(object_translation_unit, string_get(parent_object));
            string_add_str(object_translation_unit, "Class,\n");
        }
        else
            string_add_str(object_translation_unit, "Class,\n");
        string_add_str(object_translation_unit, "sizeof(struct ");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "Class),\n");
        string_add_str(object_translation_unit, "zircon_ctor, ");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "Class_ctor,\n");
        string_add_str(object_translation_unit, "0);\n");

        string_add_str(object_translation_unit, "if(!");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, ") ");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, " = zircon_new(\n");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "Class,\n");
        string_add_char(object_translation_unit, '\"');
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "\",\n");
        string_add_str(object_translation_unit, string_get(parent_object));
        string_add_str(object_translation_unit, ",\n");
        string_add_str(object_translation_unit, "sizeof(struct ");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "),\n");

        for(i = 0; i < vector_length(object_messages); i++) {
            vector *message = vector_get(object_messages, i);
            if(!string_equals(vector_get(message, 2), new_string("new"))
            && !string_equals(vector_get(message, 2), new_string("defer"))) {
                /* Add an identifier to avoid name collisions */
                string_add_str(object_translation_unit, "zircon_");

                string_add_str(object_translation_unit, string_get(vector_get(message, 2)));
                string_add_str(object_translation_unit, ", ");
                string_add_str(object_translation_unit, string_get(name_of_object));
                string_add_str(object_translation_unit, "_");
                string_add_str(object_translation_unit, string_get(vector_get(message, 2)));
                string_add_str(object_translation_unit, ",\n");
            }
        }
    }
    else {
        string_add_str(object_translation_unit, "if(!");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, ") ");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, " = zircon_new(\n");
        string_add_str(object_translation_unit, "Class,\n");
        string_add_char(object_translation_unit, '\"');
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "\",\n");
        string_add_str(object_translation_unit, string_get(parent_object));
        string_add_str(object_translation_unit, ",\n");
        string_add_str(object_translation_unit, "sizeof(struct ");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "),\n");

        for(i = 0; i < vector_length(object_messages); i++) {
            vector *message = vector_get(object_messages, i);
            if(!string_equals(vector_get(message, 2), new_string("new"))
            && !string_equals(vector_get(message, 2), new_string("defer"))) {
                /* Add an identifier to avoid name collisions */
                string_add_str(object_translation_unit, "zircon_");

                string_add_str(object_translation_unit, string_get(vector_get(message, 2)));
                string_add_str(object_translation_unit, ", ");
                string_add_str(object_translation_unit, string_get(name_of_object));
                string_add_str(object_translation_unit, "_");
                string_add_str(object_translation_unit, string_get(vector_get(message, 2)));
                string_add_str(object_translation_unit, ",\n");
            }
        }
    }

    if(constructor_is_overriden) {
        string_add_str(object_translation_unit, "zircon_ctor, ");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "_ctor,\n");
    }

    if(destructor_is_overriden) {
        string_add_str(object_translation_unit, "zircon_dtor, ");
        string_add_str(object_translation_unit, string_get(name_of_object));
        string_add_str(object_translation_unit, "_dtor,\n");
    }

    string_add_str(object_translation_unit, "0);\n}\n");

    string_add_str(object_translation_unit, "#endif\n\n");

    return object_translation_unit;
}

#endif