#ifndef __VECTOR_H_
#define __VECTOR_H_

#include <stdlib.h> /* malloc, calloc, realloc, free */

/**
 * @func: lambda
 * @desc: A generic function type used upon iterable data structures
 * @param -> An element belonging to an iterable
 * @return -> A value that satisfies the callee's purpose (map, filter, reduce)
 **/
/* The param void* can have more than 1 argument stored as a list of some sort */
/* Since this is completely generic we can't check for validity of arguments */
/* The validity of the function is dependent on the callee */
typedef void* (*lambda)(void*);
typedef void* (*lambda2)(void*, void*);

/* Initial capacity of a vector */
static const size_t vector_init_capacity = 32;

/**
 * @struct: vector
 * @desc: Defines a vector data structure
 * @param items -> A void pointer array that contains the heterogenous elements of the vector
 * @param alloced -> The total capacity of the vector
 * @param length -> The total number of values
 **/
typedef struct vector {
    /* TODO -> USE A TYPED UNION INSTEAD OF VOID POINTERS */
    void **items;
    size_t alloced;
    size_t length;
} vector;

// static void vector_ensure_space(vector *v, size_t capacity);
vector *new_vector(void);
void vector_add(vector *v, void *item);
void vector_set(vector *v, size_t index, void *item);
void *vector_get(vector *v, size_t index);
void vector_delete(vector *v, size_t index);
size_t vector_length(vector *v);
vector *vector_dup(vector *v);
vector *vector_map(vector *v, lambda modifier);
vector *vector_filter(vector *v, lambda filter);
void *vector_reduce(vector *v, lambda2 fold);

#endif