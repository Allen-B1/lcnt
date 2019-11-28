#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "lcnt_ktype.h"

// djb2
static size_t string_hash(const void* key) {
	const char* str = key;

    size_t hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

static bool string_eq(const void* key1, const void* key2) {
    return strcmp(key1, key2) == 0;
}

lcnt_ktype lcnt_ktype_string = {
    .hash_func = string_hash,
    .eq_func = string_eq,
    .size = sizeof(const char*)
};
