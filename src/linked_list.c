#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void list_init(LinkedList* list) {
    list->head = NULL;
    list->size = 0;
}

static Node* node_create(int value) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (!n) return NULL;
    n->value = value;
    n->next = NULL;
    return n;
}

bool list_push_front(LinkedList* list, int value) {
    Node* n = node_create(value);
    if (!n) return false;
    n->next = list->head;
    list->head = n;
    list->size++;
    return true;
}

bool list_push_back(LinkedList* list, int value) {
    Node* n = node_create(value);
    if (!n) return false;

    if (!list->head) {
        list->head = n;
        list->size++;
        return true;
    }

    Node* cur = list->head;
    while (cur->next) cur = cur->next;
    cur->next = n;
    list->size++;
    return true;
}

bool list_pop_front(LinkedList* list, int* out_value) {
    if (!list->head) return false;
    Node* n = list->head;
    if (out_value) *out_value = n->value;

    list->head = n->next;
    free(n);
    list->size--;
    return true;
}

bool list_remove_value(LinkedList* list, int value) {
    if (!list->head) return false;

    Node* cur = list->head;
    Node* prev = NULL;

    while (cur) {
        if (cur->value == value) {
            if (!prev) {
                list->head = cur->next;
            } else {
                prev->next = cur->next;
            }
            free(cur);
            list->size--;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

bool list_contains(const LinkedList* list, int value) {
    Node* cur = list->head;
    while (cur) {
        if (cur->value == value) return true;
        cur = cur->next;
    }
    return false;
}

void list_print(const LinkedList* list) {
    printf("[");
    Node* cur = list->head;
    while (cur) {
        printf("%d", cur->value);
        if (cur->next) printf(" -> ");
        cur = cur->next;
    }
    printf("] (size=%zu)\n", list->size);
}

void list_clear(LinkedList* list) {
    Node* cur = list->head;
    while (cur) {
        Node* next = cur->next;
        free(cur);
        cur = next;
    }
    list->head = NULL;
    list->size = 0;
}