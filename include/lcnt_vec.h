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

// Appends an element to the vector.
bool lcnt_vec_add(lcnt_vec* vec, void* data);

// Removes an element from the end of the vector and returns it.
void* lcnt_vec_remove_end(lcnt_vec* vec);

// Returns pointer to `index`, or `NULL` if `index` >= `cap`. Increases length to match `index` if needed.
void* lcnt_vec_get(lcnt_vec* vec, size_t index);

// Grows `vec` to capacity `cap` if needed. Returns `true` if `vec->cap >= cap`, false otherwise.
bool lcnt_vec_grow(lcnt_vec* vec, size_t cap);

const void* lcnt_vec_get_const(const lcnt_vec* vec, size_t index);

#define lcnt_vec_add_const(vec, val, T) lcnt_vec_add(vec, (T[]){(val)})
#define lcnt_vec_set(vec, index, val, T) *(T*)lcnt_vec_get(vec, index) = val

#endif