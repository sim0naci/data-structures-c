#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    size_t size;
} LinkedList;

void list_init(LinkedList* list);
bool list_push_front(LinkedList* list, int value);
bool list_push_back(LinkedList* list, int value);
bool list_pop_front(LinkedList* list, int* out_value);
bool list_remove_value(LinkedList* list, int value); // remove primeira ocorrência
bool list_contains(const LinkedList* list, int value);
void list_print(const LinkedList* list);
void list_clear(LinkedList* list);

#endif
