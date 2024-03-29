#ifndef _LCNT_LIST_H
#define _LCNT_LIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct lcnt_list_node {
    struct lcnt_list_node* next;
    char data[];
} lcnt_list_node;

typedef struct {
    size_t esize;
    lcnt_list_node* start;
    lcnt_list_node* end;
} lcnt_list;

bool lcnt_list_init(lcnt_list* list, size_t esize);
void lcnt_list_free(lcnt_list* list);

lcnt_list_node* lcnt_list_append(lcnt_list* list, void* data);
lcnt_list_node* lcnt_list_prepend(lcnt_list* list, void* data);
lcnt_list_node* lcnt_list_insert(lcnt_list* list, lcnt_list_node* prev, void* data);
lcnt_list_node* lcnt_list_remove_after(lcnt_list* list, lcnt_list_node* prev);
lcnt_list_node* lcnt_list_remove_start(lcnt_list* list);

void* lcnt_list_set(lcnt_list* list, lcnt_list_node* node);
const void* lcnt_list_get(const lcnt_list* list, const lcnt_list_node* node);

#define lcnt_list_foreach(list, node) for (*(node) = (list)->start; *(node) != NULL; *(node) = (*(node))->next)

#endif
