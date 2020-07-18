#include "helpers.h"

hashmap *_define_class_count;

struct Object {
    unsigned long id;
    char *class;
} Object;

/*     _object_map = new_hashmap();
    hashmap_add(_object_map, "Object", "Object"); */
struct Object* Object_new(void) {
    /* Execute */
    _object_setup();

    /* Allocate space according to the struct type */
    struct Object *self = (struct Object*)malloc(sizeof(struct Object));

    /* Initialize object fields */
    hashmap_add(_define_class_count, "-1", "-1");
    _define_class_count->alloced++;
    self->id = _generate_id(_define_class_count, "Object_new");
    self->class = (char*)malloc(sizeof(char) * 1024);
    self->class = _generate_class_name("Object");

    return self;
}

/* Initialize object base functions */
bool Object__EQEQ__(struct Object *self, struct Object *other) {
    return self->id == other->id;
}

bool Object__NOT_EQ__(struct Object *self, struct Object *other) {
    return self->id != other->id;
}

unsigned long Object_id(struct Object *self) {
    return self->id;
}

bool Object_equal(struct Object *self, struct Object *other) {
    return Object__EQEQ__(self, other);
}

char* Object_to_string(struct Object *self) {
    return self->class;
}

void _object_setup(void) {
    if(!_define_class_count) _define_class_count = new_hashmap();
}