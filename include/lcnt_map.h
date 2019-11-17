#ifndef _LCNT_MAP_H
#define _LCNT_MAP_H

/* TODO
#include <stddef.h>
#include <stdbool.h>
#include "lcnt_vec.h"

typedef size_t (*lcnt_map_hash_func)(void* key);
typedef bool (*lcnt_map_eq_func)(void* key1, void* key2);

typedef struct {
    lcnt_vec _buckets;
    size_t _cap;

    lcnt_map_hash_func hash_func;
    lcnt_map_eq_func eq_func;
} lcnt_map;

void lcnt_map_init(lcnt_map* map, size_t cap, lcnt_map_hash_func hash_func, lcnt_map_eq_func eq_func);
void lcnt_map_free(lcnt_map* map);
void lcnt_map_add(lcnt_map* map, void* key, void* value);
void lcnt_map_set(lcnt_map* map, void* key, void* value);
void lcnt_map_remove(lcnt_map* map, void* key);

void* lcnt_map_get(const lcnt_map* map);
*/

#endif