#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Queue {
    int* data;
    size_t head;
    size_t tail;
    size_t size;
    size_t capacity;
} Queue;

void queue_init(Queue* q);
void queue_free(Queue* q);

bool queue_enqueue(Queue* q, int value);
bool queue_dequeue(Queue* q, int* out_value);
bool queue_peek(const Queue* q, int* out_value);

bool queue_is_empty(const Queue* q);
size_t queue_size(const Queue* q);

#endif