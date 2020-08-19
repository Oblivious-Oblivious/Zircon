#include "helpers.h"

struct Object {
    unsigned long id;
    char *class;
    struct Object *super;
    size_t size;

    /* Hex translation */
    unsigned long (*Object_6964)(void);
    struct Object* (*Object_636c617373)(void);
    struct Object* (*Object_7375706572636c617373)(void);
    size_t (*Object_73697a65)(void);

    /**********************************************/
    bool (*Object_69732061)(struct Object* class);
    bool (*Object_6973206f66)(struct Object* class);
    /**********************************************/

    bool (*Object_726573706f6e647320746f)(char* message);

    struct Object* (*Object_6e6577)(va_list *argv);
    /* TODO -> try make private */void* (*Object_616c6c6f63)(void);
    /* TODO -> try make private */struct Object* (*Object_696e6974)(va_list *argv);

    bool (*Object_3d3d)(struct Object* other);
    bool (*Object_213d)(struct Object* other);
    bool (*Object_657175616c)(struct Object* other);
    char* (*Object_746f20737472696e67)(void);
} Object;

/*     _object_map = new_hashmap();
    hashmap_add(_object_map, "Object", "Object"); */
struct Object* Object_new(va_list argv) {
    /* Execute */
    __object_setup();

    /* Allocate space according to the struct type */
    struct Object *self = (struct Object*)malloc(sizeof(struct Object));

    /* Initialize object fields */
    hashmap_add(_define_class_count, "-1", "-1");
    _define_class_count->alloced++;
    self->id = __generate_id(_define_class_count, "Object_new");
    self->class = (char*)malloc(sizeof(char) * 1024);
    self->class = __generate_class_name("Object");
    self->super = __generate_superclass(self);

    __generate_defaults(argv);

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

int main(void) {
    printf("%s\n", "Hello, World!");
    return 0;
}