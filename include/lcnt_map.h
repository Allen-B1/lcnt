#ifndef _LCNT_MAP_H
#define _LCNT_MAP_H

#include <stddef.h>
#include <stdbool.h>
#include "lcnt_ktype.h"

typedef struct {
    /*const*/ size_t cap;
    /*const*/ size_t vsize;
    /*const*/ lcnt_ktype* ktype;

    void* _buckets;
} lcnt_map;

/** Initializes a map. `ktype` must not be `NULL`. */
bool lcnt_map_init(lcnt_map* map, lcnt_ktype* ktype, size_t vsize, size_t cap);
void lcnt_map_free(lcnt_map* map);

void* lcnt_map_set(lcnt_map* map, const void* key);
const void* lcnt_map_get(const lcnt_map* map, const void* key);
bool lcnt_map_remove(lcnt_map* map, const void* key);

/** Returns an array of the map's keys. The array must be `free`d. */
const void** lcnt_map_keys(const lcnt_map* map, size_t* size);

#endif
