#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "helpers/stdbool.h"
#include "helpers/string.h"
#include "helpers/vector.h"
#include "helpers/hashmap.h"

#include "extensions/printf/printf.h"

hashmap *_define_class_count;

static void __object_setup(void) {
    if(!_define_class_count) _define_class_count = new_hashmap();
}

static unsigned long __generate_id(hashmap *map, char *class_name) {
    return hashmap_hash_int(map, class_name);
}

static char *__generate_class_name(char *class_name) {
    return class_name;
}

static struct Object *__generate_superclass(struct Object *super) {
    return super;
}



static void __generate_defaults(va_list argv) {
}

static bool __class_contains_message(char *message) {
    return false;
}