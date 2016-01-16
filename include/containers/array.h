/*
 * array.h
 *
 */

#ifndef INCLUDE_CONTAINERS_ARRAY_H_
#define INCLUDE_CONTAINERS_ARRAY_H_

#include <stdint.h>
#include <stdbool.h>

/* Containers with DEFAULT_MAX_SIZE or less integers should be arrays */
enum { DEFAULT_MAX_SIZE = 4096 };

struct array_container_s {
    int32_t cardinality; // how many elements in array are occupied
    int32_t capacity; // size of array (should be larger or equal to cardinality)
    uint16_t *array; // strictly increasing list of integers 
};

typedef struct array_container_s array_container_t;

/* Create a new array. Return NULL in case of failure. */
array_container_t *array_container_create();

/* Free memory owned by `array'. */
void array_container_free(array_container_t *array);

/* Add `pos' to `array'. Returns true if `pos' was not present. */
bool array_container_add(array_container_t *array, uint16_t pos);

/* Remove `pos' from `array'. Returns true if `pos' was present. */
bool array_container_remove(array_container_t *array, uint16_t pos);

/* Check whether `pos' is present in `array'.  */
bool array_container_contains(const array_container_t *array, uint16_t pos);

/* Get the cardinality of `array'. */
inline int array_container_cardinality(const array_container_t *array) {
    return array->cardinality;
}

/* Set the cardinality to zero (does not release memory). */
inline void array_container_clear(array_container_t *array) {
    array->cardinality = 0;
}

/* Compute the union of `src_1' and `src_2' and write the result to `dst'
 * It is assumed that `dst' is distinct from both `src_1' and `src_2'. */
void array_container_union(const array_container_t *src_1,
                           const array_container_t *src_2,
                           array_container_t *dst);

/* Compute the intersection of src_1 and src_2 and write the result to
 * dst. It is assumed that dst is distinct from both src_1 and src_2. */
void array_container_intersection(const array_container_t *src_1,
                                  const array_container_t *src_2,
                                  array_container_t *dst);

#endif /* INCLUDE_CONTAINERS_ARRAY_H_ */
