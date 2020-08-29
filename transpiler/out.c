
#ifndef __Any_
#define __Any_

/* INDLUDE SUPER */
#include "Object.h"

/* REPRESENTATION */
struct Any {
    const struct Object _;
};


/* DECLARATIONS */
const void *Any;

/* SELECTORS */

/* METHODS */
void *Any_ctor(void *_self, va_list *app) {
    struct Any *self = super_ctor(Any, _self, app);

 {
printf("Creating an `Any` object\n");

}
    return self;
};
bool Any_differ(void *_self, const void *other) {
struct Any *self = _self;
struct Object *super = (struct Object*)self;

return 0;
}

/* INITIALIZATION */
void __init_Any(void) {
if(!Any) Any = new(
Class,
"Any",
Object,
sizeof(struct Any),
differ, Any_differ,
ctor, Any_ctor,
0);
}
#endif

void any(void ) {
void *o = new(Object);
void *a = new(Any);
puto(Any, stdout);
puto(o, stdout);
puto(a, stdout);
if((differ(o, o)) == (differ(a, a))) printf("ok\n");
if((differ(o, a)) != (differ(a, o))) printf("not commutative\n");
defer(o);
defer(a);
defer(Any);

}
void __setup_objects(void);
int main(int argc, char **argv) {
__setup_objects();
 {
any();
puts("");
return 0;

}
}
void __setup_objects(void) {
    __init_Any();
}
