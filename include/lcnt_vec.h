#ifndef _LCNT_VEC_H
#define _LCNT_VEC_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct {
	size_t esize;
	size_t len;
	size_t cap;
	void *data;
} lcnt_vec;

void lcnt_vec_init(lcnt_vec* vec, size_t esize);
void lcnt_vec_free(lcnt_vec* vec);

/** Adds an element to the end of the vector. */
intmax_t lcnt_vec_append(lcnt_vec* vec, void* data);

/** Inserts an element at the given index. **/
bool lcnt_vec_insert(lcnt_vec* vec, size_t index, void* data);

/** Removes the element at the given index. */
bool lcnt_vec_remove(lcnt_vec* vec, size_t index);

/** Removes the element at the end of the vector. */
bool lcnt_vec_remove_end(lcnt_vec* vec);

/** Returns pointer to `index`, or `NULL` if `index` >= `cap`. Increases length to match `index` if needed. */
void* lcnt_vec_set(lcnt_vec* vec, size_t index);

/** Returns pointer to `index`, or `NULL` if `index` >= `len`. */
const void* lcnt_vec_get(const lcnt_vec* vec, size_t index);

/** Grows `vec` to capacity `cap` if needed. Returns `true` if `vec->cap >= cap`, false otherwise. */
bool lcnt_vec_grow(lcnt_vec* vec, size_t cap);

#define lcnt_vec_foreach(vec, index) for(*(index) = 0; *(index) < (vec)->len; (*(index))++)

#endif
