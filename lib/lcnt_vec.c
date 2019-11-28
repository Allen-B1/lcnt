#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <lcnt_vec.h>

bool lcnt_vec_init(lcnt_vec* vec, size_t esize) {
	vec->esize = esize;
	vec->len = 0;
	vec->cap = 0;
	vec->data = NULL;

	return true;
}

void lcnt_vec_free(lcnt_vec* vec) {
	free(vec->data);
	vec->data = NULL;
	vec->cap = 0;
	vec->len = 0;
}

void* lcnt_vec_append(lcnt_vec* vec) {
	if(vec->len >= vec->cap) {
		if (!lcnt_vec_grow(vec, vec->cap >= 16 ? vec->cap + 16 : (
					vec->cap == 0 ? 2 : vec->cap * 2))) return NULL;
	}
	vec->len += 1;
	return ((char*)vec->data) + vec->esize * (vec->len - 1);
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

bool lcnt_vec_remove_end(lcnt_vec* vec) {
	if (vec->len == 0)
		return false;
	void* elem = (void*)lcnt_vec_get(vec, vec->len - 1);
	vec->len -= 1;
	return true;
}

void* lcnt_vec_set(lcnt_vec* vec, size_t index) {
	if (index >= vec->cap) {
		return NULL;
	}
	if (index >= vec->len) {
		vec->len = index+1;
	}
	return ((char*)vec->data) + (vec->esize * index);
}

const void* lcnt_vec_get(const lcnt_vec* vec, size_t index) {
	if (index >= vec->len) {
		return NULL;
	}
	return ((const char*)vec->data) + (vec->esize * index);
}

void* lcnt_vec_insert(lcnt_vec* vec, size_t index) {
	if (index > vec->len) {
		return NULL;
	}

	if(vec->len >= vec->cap) {
		if (!lcnt_vec_grow(vec, vec->cap >= 16 ? vec->cap + 16 : (
					vec->cap == 0 ? 2 : vec->cap * 2))) return NULL;
	}

	if (index != vec->len) {
		memcpy(((char*)vec->data) + (vec->esize * (index + 1)), ((char*)vec->data) + (vec->esize * index), vec->esize * (vec->len - index));
	}
	vec->len += 1;
	return ((char*)vec->data) + (vec->esize * index);
}

bool lcnt_vec_remove(lcnt_vec* vec, size_t index) {
	if (index >= vec->len) {
		return false;
	}

	memcpy(((char*)vec->data) + (vec->esize * index), ((char*)vec->data) + (vec->esize * (index + 1)), vec->esize * (vec->len - index - 1));
	vec->len -= 1;
	return true;
}

