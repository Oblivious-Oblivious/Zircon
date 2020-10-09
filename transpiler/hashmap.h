#ifndef __HASHMAP_H_
#define __HASHMAP_H_

#include <stdlib.h> /* malloc, calloc, realloc, free */
/* TODO -> REPLACE WITH CUSTOM FUNCTIONS */
#include <string.h> /* strlen, strcmp */

/**
 * @func: hashmap_lambda
 * @desc: A generic function type used upon iterable data structures
 * @param -> An element belonging to an iterable
 * @return -> A value that satisfies the callee's purpose (map, filter, reduce)
 **/
/* The param void* can have more than 1 argument stored as a list of some sort */
/* Since this is completely generic we can't check for validity of arguments */
/* The validity of the function is dependent on the callee */

/* typedef void* (*hashmap_lambda)(); */
typedef void* (*hashmap_lambda)(void*);
typedef void* (*hashmap_lambda2)(void*, void*);

/* Initial capacity of the hashmap */
static const size_t hashmap_init_capacity = 32;
static const size_t max_chain_length = 8;

/**
 * @enum: hashmap_element_type
 * @desc: Defines an enum of KEYS or VALUES
 **/
typedef enum {
	KEYS,
	VALUES
} hashmap_element_type;

/**
 * @struct: hashmap_element
 * @desc: Elements contained in the hashmap both keys and values
 * @param key -> The key of the element
 * @param data -> The value of the element
 * @param map_use -> Boolean used for hashmap operations and linear probing
 **/
typedef struct hashmap_element {
	char *key;
	void *data;
	size_t in_use;
} hashmap_element;

/**
 * @struct: hashmap
 * @desc: A hashmap struct that has some maximum size and
 *          current size as well as the data to hold
 * @param alloced -> The maximum allocated size
 * @param length -> The current total size
 * @param data -> The data array contained
 **/
typedef struct hashmap {
	size_t alloced;
	size_t length;
	hashmap_element *data;
} hashmap;

void hashmap_add(hashmap *map, char *key, void *value);

static unsigned long crc32(const unsigned char *s, unsigned int len);
static unsigned int hashmap_hash_int(hashmap *map, char *keystring);
static size_t hashmap_hash(hashmap *map, char *key);
/* static void hashmap_rehash(hashmap *map); */
hashmap *new_hashmap(void);
void hashmap_add(hashmap *map, char *key, void *value);
void hashmap_set(hashmap *map, char *key, void *value);
void *hashmap_get(hashmap *map, char *key);
void hashmap_delete(hashmap *map, char *key);
size_t hashmap_length(hashmap *map);
hashmap *hashmap_dup(hashmap *map);
hashmap *hashmap_map(hashmap *map, hashmap_lambda modifier, hashmap_element_type element_type);
hashmap *hashmap_filter(hashmap *map, hashmap_lambda filter, hashmap_element_type element_type);
void *hashmap_reduce(hashmap *map, hashmap_lambda2 fold, hashmap_element_type element_type);

#endif