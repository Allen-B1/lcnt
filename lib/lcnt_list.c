#include <lcnt_list.h>
#include <stdlib.h>
#include <string.h>

void lcnt_list_init(lcnt_list* list, size_t esize) {
    list->esize = esize;
    list->start = NULL;
    list->end = NULL;
}

void lcnt_list_free(lcnt_list* list) {
    lcnt_list_node* node = list->start;
    while (node != NULL) {
        lcnt_list_node* tmp = node;
        node = node->next;
        free(tmp);
    }
    list->start = NULL;
    list->end = NULL;
}

lcnt_list_node* lcnt_list_add(lcnt_list* list, void* data) {
    lcnt_list_node* node = malloc(sizeof(lcnt_list_node) + list->esize);
    if (node == NULL) {
        return NULL;
    }
    node->next = NULL;
    memcpy(&node->data, data, list->esize);
    if (list->end == NULL) {
        list->end = node;
        list->start = node;
    } else {
        list->end->next = node;
        list->end = node;
    }
    return node;
}

lcnt_list_node* lcnt_list_prepend(lcnt_list* list, void* data) {
    lcnt_list_node* node = malloc(sizeof(lcnt_list_node) + list->esize);
    if (node == NULL) {
        return NULL;
    }
    memcpy(&node->data, data, list->esize);
    if (list->start == NULL) {
        node->next = NULL;
        list->start = node;
        list->end = node;
    } else {
        node->next = list->start;
        list->start = node;
    }
    return node;
}
