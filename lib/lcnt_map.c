/* TODO
#include <lcnt_vec.h>
#include <lcnt_map.h>

typedef struct {
    void* key;
    void* data;
} bucket;

void lcnt_map_init(lcnt_map* map, size_t cap, lcnt_map_hash_func hash_func, lcnt_map_eq_func eq_func) {
    map->hash_func = hash_func;
    map->eq_func = eq_func;
    map->_cap = cap;
    lcnt_vec_init(&map->_buckets, sizeof(bucket));
    lcnt_vec_grow(&map->_buckets, cap);
    for (size_t i = 0; i < cap; i++) {
        ((bucket*)lcnt_vec_get(&map->_buckets, i))->key = NULL;
    }
}
void lcnt_map_free(lcnt_map* map) {
    lcnt_vec_free(&map->_buckets);
}

void lcnt_map_set(lcnt_map* map, void* key) {
    if (key == NULL)
        return;

    size_t hash = map->hash_func(key) % map->_cap;
    bucket* bt = lcnt_vec_get(&map->_buckets, hash);
}

void lcnt_map_remove(lcnt_map* map, void* key) {
}

void* lcnt_map_get(const lcnt_map* map);

*/