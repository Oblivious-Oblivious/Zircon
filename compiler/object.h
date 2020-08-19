#ifndef __OBJECT_H_
#define __OBJECT_H_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stddef.h>

struct Object {
    const struct Class *class;
};
struct Class {
    const struct Object _;
    const char *name;
    const struct Class *super;
    size_t size;
    void *(*ctor)(void *self, va_list *app);
    void *(*dtor)(void *self);
    int (*differ)(const void *self, const void *other);
    int (*puto)(const void *self, FILE *fd);
};

static void *new(const void *_class, ...);
static void delete(void *_self);

static const void *classOf(const void *_self) {
    const struct Object *self = _self;

    assert(_self && self && self->class);
    return self->class;
}

static size_t sizeOf(const void *_self) {
    const struct Class *class = classOf(_self);
    return class->size;
}

static const void *super(const void *_self) {
    const struct Class *self = _self;

    assert(_self && self && self->super);
    return self->super;
}

static void *new(const void *_class, ...) {
    const struct Class *class = _class;
    assert(class && class->size);

    struct Object *object;
    va_list ap;

    object = (struct Object*)calloc(1, class->size);
    va_start(ap, _class);
        object = ctor(object, &ap);
    va_end(ap);
    return object;
}

static void delete(void *_self) {
    if(_self) free(dtor(_self));
}

static const struct Class object [] = {
    {
        { object + 1 },
        "Object",
        object,
        sizeof(struct Object),
        Object_ctor,
        Object_dtor,
        Object_differ,
        Object_puto,
    },
    {
        { object + 1},
        "Class",
        object,
        sizeof(struct Class),
        Class_ctor,
        Class_dtor,
        Object_differ,
        Object_puto,
    }
};

const void *Object = object;
const void *Class = object + 1;

#endif