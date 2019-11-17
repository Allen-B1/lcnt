#ifndef _LCNT_LIST_H
#define _LCNT_LIST_H

typedef struct lcnt_node {
    struct lcnt_node* next;
    char data[];
} lcnt_node;

typedef struct {
    lcnt_node* start;
    lcnt_node* end;
} lcnt_list;

void lcnt_list_init(lcnt_list* vec, size_t esize);
void lcnt_list_free(lcnt_list* vec);
lcnt_node* lcnt_list_add(lcnt_list* vec, void* data);
lcnt_node* lcnt_list_prepend(lcnt_list* vec, void* data);

#endif