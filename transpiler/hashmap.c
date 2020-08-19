#include "hashmap.h"

/* Return a 32-bit CRC of the contents of the buffer. */
/**
 * @func: crc32
 * @desc: Gets a 32-bit CEC of the contents of the buffer
 * @param s -> The key string
 * @param len -> The length of the key string
 * @return The crc32 value of the key string
 **/
static unsigned long crc32(const unsigned char *s, unsigned int len) {
    unsigned long crc32val = 0;

    unsigned int i;
    for(i = 0; i < len; i++)
        crc32val = crc32_tab[(crc32val ^ s[i]) & 0xff] ^ (crc32val >> 8);
    return crc32val;
}

/**
 * @func: hashmap_hash_int
 * @desc: Hashing functions for a string
 * @param map -> The hashmap we want to modify the table size of
 * @param keystring -> The string to hash
 * @return A unique hashed int
 **/
static unsigned int hashmap_hash_int(hashmap *map, char *keystring) {
    unsigned long key = crc32((unsigned char*)(keystring), strlen(keystring));

	/* Robert Jenkins' 32 bit Mix Function */
	key += (key << 12);
	key ^= (key >> 22);
	key += (key << 4);
	key ^= (key >> 9);
	key += (key << 10);
	key ^= (key >> 2);
	key += (key << 7);
	key ^= (key >> 12);

	/* Knuth's Multiplicative Method */
	key = (key >> 3) * 2654435761;

	return key % map->alloced;
}

/**
 * @func: hashmap_hash
 * @desc: Get the integer of the location in data to store it to the item
 * @param in -> The hashmap
 * @param key -> The key to hash
 * @return The location
 **/
static size_t hashmap_hash(hashmap *map, char *key) {
	if(map->length >= (map->alloced / 2)) return -1;

	size_t curr = hashmap_hash_int(map, key);

	/* Linear probing */
    size_t i = 0;
	for(i = 0; i < max_chain_length; i++) {
		if(map->data[curr].in_use == 0) return curr;
		
        if(map->data[curr].in_use == 1
        && (strcmp(map->data[curr].key, key) == 0))
            return curr;

		curr = (curr + 1) % map->alloced;
	}

    /* In case of a full map */
	return -1;
}

/**
 * @func: hashmap_rehash
 * @desc: Doubles the size of the hashmap and rehashes all the elements
 * @param in -> The hashmap to rehash
 **/
static void hashmap_rehash(hashmap *map) {
    hashmap_element *temp = (hashmap_element*)calloc(2 * map->alloced, sizeof(hashmap_element));

	/* Update the array */
	hashmap_element *curr = map->data;
	map->data = temp;

	/* Update the size */
	size_t old_size = map->alloced;
	map->alloced = 2 * map->alloced;
	map->length = 0;

    /* Rehash all the elements */
    size_t i = 0;
	for(i = 0; i < old_size; i++) {
        /* Skip deleted elements */
        if(curr[i].in_use == 0) continue;
		hashmap_add(map, curr[i].key, curr[i].data);
	}
	return;
}

hashmap *new_hashmap(void) {
    hashmap *map = (hashmap*)malloc(sizeof(hashmap));
	map->data = (hashmap_element*)calloc(hashmap_init_capacity, sizeof(hashmap_element));
	map->alloced = hashmap_init_capacity;
	map->length = 0;
	return map;
}

void hashmap_add(hashmap *map, char *key, void *value) {
    if(map == NULL || key == NULL) return;

    size_t index = hashmap_hash(map, key);
    
    /* In case of a full hashmap */
	while(index == -1) {
        hashmap_rehash(map);
		index = hashmap_hash(map, key);
	}

	map->data[index].data = value;
	map->data[index].key = key;
	map->data[index].in_use = 1;
	map->length++;
	return;
}

void hashmap_set(hashmap *map, char *key, void *value) {
    if(map == NULL || key == NULL) return;

	size_t curr = hashmap_hash_int(map, key);

	/* Linear probing */
    size_t i = 0;
	for(i = 0; i < max_chain_length; i++) {
        if(map->data[curr].in_use == 1) {
            if(strcmp(map->data[curr].key, key) == 0) {
                /* Set to the new value */
                map->data[curr].data = value;
            }
		}
		curr = (curr + 1) % map->alloced;
    }
    return;
}

void *hashmap_get(hashmap *map, char *key) {
    if(map == NULL || key == NULL) return NULL;

	size_t curr = hashmap_hash_int(map, key);

	/* Linear probing  */
    size_t i = 0;
	for(i = 0; i < max_chain_length; i++) {
        if(map->data[curr].in_use == 1) {
            if(strcmp(map->data[curr].key, key) == 0) {
                /* Return the contained data void pointer */
                return map->data[curr].data;
            }
		}
		curr = (curr + 1) % map->alloced;
    }    
	return NULL;
}

void hashmap_delete(hashmap *map, char *key) {
    if(map == NULL || key == NULL) return;

	size_t curr = hashmap_hash_int(map, key);

	/* Linear probing */
    size_t i = 0;
	for(i = 0; i < max_chain_length; i++) {
        if(map->data[curr].in_use == 1) {
            if(strcmp(map->data[curr].key, key) == 0) {
                /* Blank out the fields */
                map->data[curr].in_use = 0;
                map->data[curr].data = NULL;
                map->data[curr].key = NULL;
                map->length--;
                return;
            }
		}

        /* Fix the current hash */
		curr = (curr + 1) % map->alloced;
	}

	return;
}

size_t hashmap_length(hashmap *map) {
	if(map != NULL) return map->length;
	else return 0;
}

hashmap *hashmap_dup(hashmap *map) {
    if(map == NULL) return NULL;

    hashmap *dup = new_hashmap();
    
    /* Iteratively copy all hashmap elements from one pointer to another */
    size_t i = 0;
    for(i = 0; i < map->alloced; i++)
        if(map->data[i].in_use != 0)
            hashmap_add(dup, map->data[i].key, map->data[i].data);

    return dup;
}

hashmap *hashmap_map(hashmap *map, lambda modifier, hashmap_element_type element_type) {
    if(map == NULL || modifier == NULL) return NULL;

    hashmap *dup = hashmap_dup(map);
    
    /* Iterate with linear probing */
    size_t i;
    for(i = 0; i < map->alloced; i++) {
        if(map->data[i].in_use != 0) {
            switch(element_type) {
                case KEYS:
                    /* TODO CREATE ACCESSOR METHODS */
                    dup->data[i].key = modifier(map->data[i].key);
                    break;
                case VALUES:
                    hashmap_set(dup, map->data[i].key, modifier(map->data[i].data));
                    break;
                default:
                    return NULL;
            }
        }
    }

    return dup;
}

hashmap *hashmap_filter(hashmap *map, lambda filter, hashmap_element_type element_type) {
    if(map == NULL || filter == NULL) return NULL;

    hashmap *dup = hashmap_dup(map);

    /* Iterate with linear probing */
    size_t i;
    for(i = 0; i < map->alloced; i++) {
        if(map->data[i].in_use != 0) {
            switch(element_type) {
                case KEYS:
                    /* If the key passes the filter we continue to the next */
                    if(filter(map->data[i].key)) continue;

                    /* Delete the element with the specific key from the hashmap */
                    hashmap_delete(dup, map->data[i].key);
                    break;
                case VALUES:
                    /* If the value passes the filter we continue to the next */
                    if(filter(map->data[i].data)) continue;

                    /* Delete the element with the specific key from the hashmap */
                    hashmap_delete(dup, map->data[i].key);
                    break;
                default:
                    return NULL;
            }
        }
    }

    return dup;
}

void *hashmap_reduce(hashmap *map, lambda fold, hashmap_element_type element_type) {
    if(map == NULL || fold == NULL) return NULL;

    void *accumulator;
    void *current;
    int skip_first = 1;

    /* In general this takes constant time no matter the hashmap size */
    size_t i;
    for(i = 0; i < map->alloced; i++) {
        if(map->data[i].in_use != 0) {
            switch(element_type) {
                case KEYS:
                    /* Set accumulator to some arbitrary hashmap key */
                    accumulator = map->data[i].key;
                    break;
                case VALUES:
                    /* Set accumulator to some arbitrary hashmap value  */
                    accumulator = hashmap_get(map, map->data[i].key);
                    break;
                default:
                    return NULL;
            }
            break;
        }
    }

    /* Iterate through the hashmap */
    for(i = 0; i < map->alloced; i++) {
        if(map->data[i].in_use != 0) {
            if(skip_first == 1) {
                skip_first = 0;
                continue;
            }
            switch(element_type) {
                case KEYS:
                    /* Get the current item */
                    current = map->data[i].key;

                    /* Accumulate the result */
                    accumulator = fold(accumulator, current);
                    break;
                case VALUES:
                    /* Get the current item */
                    current = hashmap_get(map, map->data[i].key);

                    /* Accumulate the result */
                    accumulator = fold(accumulator, current);
                    break;
                default:
                    return NULL;
            }
        }
    }
    
    return accumulator;
}