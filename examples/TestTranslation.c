#include "helpers.h"

/* Implement the Object class */
hashmap *_define_class_count;

struct Object {
    unsigned long id;
    char *class;
} Object;

/* To avoid warnings */
void _object_setup();

/*     _object_map = new_hashmap();
    hashmap_add(_object_map, "Object", "Object"); */
struct Object* Object_new(char *class_name) {
    /* Execute */
    _object_setup();

    /* Allocate space */
    struct Object *self = (struct Object*)malloc(sizeof(struct Object));
    self->class = (char*)malloc(sizeof(char) * 1024);

    /* Initialize object fields */
    hashmap_add(_define_class_count, "-1", "-1");
    _define_class_count->alloced++;
    string *class_str = new_string(class_name);
    string_add_str(class_str, "_new");
    self->id = _generate_id(_define_class_count, string_get(class_str));
    self->class = _generate_class_name(class_name);

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




struct Test {    
    /* Implement a `super` handler */
    struct Object *super;

    /* Test fields */
    char *str;
} Test;

struct Test* Test_new(void) {
    /* Allocate space according to the struct type */
    struct Test *self = (struct Test*)malloc(sizeof(struct Test));

    /* Declare Test fields */
    struct Object *super = Object_new("Test");
    self->str = ""; /* Iterate on type */

    /* Initialize Test fields */
    self->super = super;
    self->str = "ok";

    return self;
}

int main(void) {
    struct Test *obj1 = Test_new();
    struct Test *obj2 = Test_new();

    if(Object__EQEQ__(obj1->super, obj1->super)) printf("obj1 == obj1\n");
    if(Object__NOT_EQ__(obj1->super, obj2->super)) printf("obj1 != obj2\n");

    char *res = obj1->super->class;
    char *res2 = Object_to_string(obj2->super);

    printf("res: %s\nres2: %s\n", res, res2);
    printf("%s\n", Object_to_string(obj2->super));

    /* Print str */
    obj1->str = "test";
    printf("@obj1->str = %s\n", obj1->str);
}