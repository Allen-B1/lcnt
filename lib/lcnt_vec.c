#include <string.h>
#include <stdlib.h>
#include <lcnt_vec.h>

void lcnt_vec_init(lcnt_vec* vec, size_t esize) {
	vec->esize = esize;
	vec->len = 0;
	vec->cap = 0;
	vec->data = NULL;
}

bool lcnt_vec_add(lcnt_vec* vec, void* data) {
	if(vec->len >= vec->cap) {
		if (!lcnt_vec_grow(vec, vec->cap >= 16 ? vec->cap + 16 : (
					vec->cap == 0 ? 2 : vec->cap * 2))) return false;
	}
	memcpy(((char*)vec->data) + (vec->esize * vec->len), data, vec->esize);
	vec->len += 1;
	return true;
}

bool lcnt_vec_grow(lcnt_vec* vec, size_t cap) {
	if (vec->cap >= cap) {
		return true;
	}

	void* new_data = realloc(vec->data, vec->esize * cap);
	if (new_data == NULL)
		return false;
	vec->data = new_data;
	vec->cap = cap;
	return true;
}

void* lcnt_vec_remove_end(lcnt_vec* vec) {
	if (vec->len == 0)
		return NULL;
	void* elem = lcnt_vec_get(vec, vec->len - 1);
	vec->len -= 1;
	return elem;
}

void lcnt_vec_free(lcnt_vec* vec) {
	free(vec->data);
	vec->data = NULL;
	vec->cap = 0;
	vec->len = 0;
}

void* lcnt_vec_get(lcnt_vec* vec, size_t index) {
	if (index >= vec->cap) {
		return NULL;
	}
	if (index >= vec->len) {
		vec->len = index+1;
	}
	return ((char*)vec->data) + (vec->esize * index);
}

const void* lcnt_vec_get_const(const lcnt_vec* vec, size_t index) {
	if (index >= vec->len) {
		return NULL;
	}
	return ((const char*)vec->data) + (vec->esize * index);
}
