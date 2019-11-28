#include <lcnt_vec.h>
#include <lcnt_map.h>

typedef struct bucket {
    struct bucket* next;
    char data[];
} bucket;

bool lcnt_map_init(lcnt_map* map, lcnt_ktype* ktype, size_t vsize, size_t cap) {
    map->cap = cap;
    map->ktype = ktype;
    map->vsize = vsize;

    map->_buckets = malloc(sizeof(bucket*) * cap);
    if (map->_buckets == NULL) {
        return false;
    }
    for (size_t i = 0; i < map->cap; i++) {
        ((bucket**)map->_buckets)[i] = NULL;
    }
    return true;
}

void lcnt_map_free(lcnt_map* map) {
    for (size_t i = 0; i < map->cap; i++) {
        bucket* node = ((bucket**)map->_buckets)[i];
        while (node != NULL) {
            bucket* next = node->next;
            free(node);
            node = next;
        }
    }
    free(map->_buckets);
    map->_buckets = NULL;
}

void* lcnt_map_set(lcnt_map* map, const void* key) {
    size_t hash = map->ktype->hash_func(key) % map->cap;
    bucket* node = ((bucket**)map->_buckets)[hash];

    // if node exists, return pointer to that
    while (node != NULL) {
        if (map->ktype->eq_func(key, node->data)) {
            return ((char*)node->data) + map->ktype->size;
        }
        node = node->next;
    }

    // otherwise create new node
    bucket* newnode = malloc(sizeof(bucket) + map->ktype->size + map->vsize);
    if (newnode == NULL) {
        return NULL;
    }
    memcpy(newnode->data, key, map->ktype->size);

    newnode->next = ((bucket**)map->_buckets)[hash];
    ((bucket**)map->_buckets)[hash] = newnode;
    return ((char*)newnode->data) + map->ktype->size;
}

const void* lcnt_map_get(const lcnt_map* map, const void* key) {
    size_t hash = map->ktype->hash_func(key) % map->cap;
    bucket* node = ((bucket**)map->_buckets)[hash];

    while (node != NULL) {
        if (map->ktype->eq_func(key, node->data)) {
            return ((char*)node->data) + map->ktype->size;
        }
        node = node->next;
    }

    return NULL;
}

bool lcnt_map_remove(lcnt_map* map, const void* key) {
    size_t hash = map->ktype->hash_func(key) % map->cap;
    bucket** nodeptr = &((bucket**)map->_buckets)[hash];

    while (*nodeptr != NULL) {
        if (map->ktype->eq_func(key, (*nodeptr)->data)) {
            bucket* node = *nodeptr;
            *nodeptr = node->next;
            free(node);
            return true;
        }

        nodeptr = &(*nodeptr)->next;
    }

    return false;
}

const void** lcnt_map_keys(const lcnt_map* map, size_t* size) {
    lcnt_vec keys;
    lcnt_vec_init(&keys, sizeof(void*));
    for (size_t i = 0; i < map->cap; i++) {
        bucket* node = ((bucket**)map->_buckets)[i];
        while (node != NULL) {
            *(void**)lcnt_vec_append(&keys) = node->data;
            node = node->next;
        }
    }

    *size = keys.len;
    return keys.data;
}

