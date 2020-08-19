#include <stdio.h>
#include <string.h>

#include "helpers/vector.h"

#define __EXEC_INIT_(obj) __init_##obj

void *Any;
void *Point;
void *Circle;

void __init_Any(void) {
    printf("initing Any\n");
}
void __init_Point(void) {
    printf("initing Point\n");
}
void __init_Circle(void) {
    printf("initing Circle\n");
}

void call_macro(char *obj) {
    if(!strcmp(obj, "Any"))    __EXEC_INIT_(Any)();
    if(!strcmp(obj, "Point"))  __EXEC_INIT_(Point)();
    if(!strcmp(obj, "Circle")) __EXEC_INIT_(Circle)();
}

int main(void) {
    vector *objects = new_vector();
    vector_add(objects, "Any");
    vector_add(objects, "Point");
    vector_add(objects, "Circle");

    vector_map(objects, (lambda)call_macro);

    return 0;
}
