#ifndef _LCNT_KTYPE_H
#define _LCNT_KTYPE_H

#include <stdbool.h>
#include <stddef.h>

typedef size_t (*lcnt_ktype_hash_func)(const void* key);
typedef bool (*lcnt_ktype_eq_func)(const void* key1, const void* key2);

typedef struct {
    lcnt_ktype_hash_func hash_func;
    lcnt_ktype_eq_func eq_func;
    size_t size;
} lcnt_ktype;

extern lcnt_ktype lcnt_ktype_string;

#endif
