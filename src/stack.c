#include "stack.h"
#include <stdlib.h>

void stack_init(Stack* s) {
    s->data = NULL;
    s->size = 0;
    s->capacity = 0;
}

void stack_free(Stack* s) {
    free(s->data);
    s->data = NULL;
    s->size = 0;
    s->capacity = 0;
}

static bool stack_grow(Stack* s) {
    size_t new_cap = (s->capacity == 0) ? 8 : s->capacity * 2;
    int* new_data = (int*)realloc(s->data, new_cap * sizeof(int));
    if (!new_data) return false;
    s->data = new_data;
    s->capacity = new_cap;
    return true;
}

bool stack_push(Stack* s, int value) {
    if (s->size == s->capacity) {
        if (!stack_grow(s)) return false;
    }
    s->data[s->size++] = value;
    return true;
}

bool stack_pop(Stack* s, int* out_value) {
    if (s->size == 0) return false;
    int v = s->data[--s->size];
    if (out_value) *out_value = v;
    return true;
}

bool stack_peek(const Stack* s, int* out_value) {
    if (s->size == 0) return false;
    if (out_value) *out_value = s->data[s->size - 1];
    return true;
}

bool stack_is_empty(const Stack* s) {
    return s->size == 0;
}

size_t stack_size(const Stack* s) {
    return s->size;
}