#ifndef __STACK_H_
#define __STACK_H_

#include <stdlib.h> /* malloc, calloc, realloc, free */

#include "stdbool.h"
/* Stack gets implemented using a vector */
#include "vector.h"


/**
 * @struct: stack
 * @desc: A stack data structure implementation
 * @param length -> The number of items pushed in the stack
 * @param top -> The index of the item on the top of the stack
 * @param items -> A vector of items
 **/
typedef struct stack {
    size_t length;
    size_t top;
    vector *items;
} stack;

/**
 * @func: stack_create
 * @desc: Creates a basic stack data structure using a dynamic array
 * @return The newly created stack
 **/
stack *stack_create(void) {
    stack *st = (stack*)malloc(sizeof(stack));

    /* Initial values */
    st->length = 0;
    st->top = -1;
    st->items = new_vector();

    return st;
}
#define new_stack() stack_create()

/**
 * @func: stack_length
 * @desc: Returns the number of elements pushed in the array
 * @param st -> The stack to use
 * @return The length (st->length)
 **/
size_t stack_length(stack *st) {
    if(st == NULL) return 0;

    return st->length;
}

/**
 * @func: stack_is_empty
 * @desc: Checks whether the stack is empty or not
 * @param st -> The stack to use
 * @return A boolean
 **/
bool stack_is_empty(stack *st) {
    if(st == NULL) return 0;

    return stack_length(st) == 0;
}

/**
 * @func: stack_push
 * @desc: Performs a bury operation on the stack
 * @param st -> The stack to use
 * @param item -> The item to push to the stack
 **/
void stack_push(stack *st, void *item) {
    if(st == NULL) return;

    /* Keep track of the top element and the length */
    st->top++;
    st->length++;

    vector_add(st->items, item);
}

/**
 * @func: stack_pop
 * @desc: Performs a pop operation on the stack
 * @param st -> The stack to use
 * @return The item on the top of the stack
 **/
void *stack_pop(stack *st) {
    if(st == NULL) return NULL;

    if(!stack_is_empty(st)) {
        st->length--;
        return vector_get(st->items, st->top--);
    }
    return NULL;
}

/**
 * @func: stack_peek
 * @desc: Performs a peek operation on the stack
 * @param st -> The stack to use
 * @return The item on top of the stack withou removing it
 **/
void *stack_peek(stack *st) {
    if(st == NULL) return NULL;

    if(!stack_is_empty(st)) return vector_get(st->items, st->top);
    return NULL;
}

#endif