#include <lcnt_list.h>
#include <stdlib.h>
#include <string.h>

bool lcnt_list_init(lcnt_list* list, size_t esize) {
    list->esize = esize;
    list->start = NULL;
    list->end = NULL;
	return true;
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

lcnt_list_node* lcnt_list_append(lcnt_list* list, void* data) {
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

lcnt_list_node* lcnt_list_insert(lcnt_list* list, lcnt_list_node* prev, void* data) {
    lcnt_list_node* node = malloc(sizeof(lcnt_list_node) + list->esize);
    if (node == NULL) {
        return NULL;
    }
    memcpy(&node->data, data, list->esize);
    if (prev->next == NULL) {
        node->next = NULL;
        list->end = node;
    } else {
        node->next = prev->next;
    }
    prev->next = node;

    return node;
}

lcnt_list_node* lcnt_list_remove_after(lcnt_list* list, lcnt_list_node* prev) {
    if (prev->next == NULL) {
        return NULL;
    }

    lcnt_list_node* node = prev->next;
    if (node->next != NULL) {
        prev->next = node->next;
        node->next = NULL;
    }
    return node;
}

lcnt_list_node* lcnt_list_remove_start(lcnt_list* list) {
    if (list->start == NULL) {
        return NULL;
    }

    lcnt_list_node* node = list->start;
    list->start = node->next;
    node->next = NULL;
    return node;
}

void* lcnt_list_set(lcnt_list* list, lcnt_list_node* node) {
    return node->data;
}

const void* lcnt_list_get(const lcnt_list* list, const lcnt_list_node* node) {
    return node->data;
}
