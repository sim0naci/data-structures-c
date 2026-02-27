#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Stack {
    int* data;
    size_t size;
    size_t capacity;
} Stack;

void stack_init(Stack* s);
void stack_free(Stack* s);

bool stack_push(Stack* s, int value);
bool stack_pop(Stack* s, int* out_value);
bool stack_peek(const Stack* s, int* out_value);

bool stack_is_empty(const Stack* s);
size_t stack_size(const Stack* s);

#endif