#include <stdlib.h>
#include <string.h>

#include "helpers/stdbool.h"
#include "helpers/string.h"
#include "helpers/vector.h"
#include "helpers/hashmap.h"

#include "extensions/printf/printf.h"

static unsigned long _generate_id(hashmap *map, char *class_name) {
    return hashmap_hash_int(map, class_name);
}

static char *_generate_class_name(char *class_name) {
    return string_get(new_string(class_name));
}
