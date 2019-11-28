#ifndef _LCNT_MAP_H
#define _LCNT_MAP_H

#include <stddef.h>
#include <stdbool.h>
#include "lcnt_list.h"

typedef size_t (*lcnt_map_hash_func)(void* key);
typedef bool (*lcnt_map_eq_func)(void* key1, void* key2);

typedef struct {
    lcnt_list* _buckets;

    /* const */
    size_t cap;
    size_t esize;

    lcnt_map_hash_func hash_func;
    lcnt_map_eq_func eq_func;
} lcnt_map;

bool lcnt_map_init(lcnt_map* map, size_t esize, size_t cap, lcnt_map_hash_func hash_func, lcnt_map_eq_func eq_func);
void lcnt_map_free(lcnt_map* map);
bool lcnt_map_remove(lcnt_map* map, void* key);

void* lcnt_map_set(lcnt_map* map, void* key);
const void* lcnt_map_get(const lcnt_map* map, void* key);

#endif
