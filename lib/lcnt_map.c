#include <lcnt_list.h>
#include <lcnt_map.h>

typedef struct {
    void* key;
    char data[];
} bucket;

bool lcnt_map_init(lcnt_map* map, size_t esize, size_t cap, lcnt_map_hash_func hash_func, lcnt_map_eq_func eq_func) {
    map->hash_func = hash_func;
    map->eq_func = eq_func;
    map->cap = cap;
    map->esize = esize;
    map->_buckets = malloc(sizeof(lcnt_list) * cap);
    if (map->_buckets == NULL) {
        return false;
    }
    for (size_t i = 0; i < map->cap; i++) {
        lcnt_list_init(&map->_buckets[i], sizeof(bucket) + esize);
    }
    return true;
}

void lcnt_map_free(lcnt_map* map) {
    for (size_t i = 0; i < map->cap; i++) {
        lcnt_list_free(&map->_buckets[i]);
    }
    free(map->_buckets);
}

void* lcnt_map_set(lcnt_map* map, void* key) {
    return NULL;
}

bool lcnt_map_remove(lcnt_map* map, void* key) {
    return false;
}

const   void* lcnt_map_get(const lcnt_map* map, void* key) {
    return NULL;
}

