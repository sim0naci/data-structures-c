#include "queue.h"
#include <stdlib.h>

void queue_init(Queue* q) {
    q->data = NULL;
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    q->capacity = 0;
}

void queue_free(Queue* q) {
    free(q->data);
    q->data = NULL;
    q->head = q->tail = q->size = q->capacity = 0;
}

static bool queue_grow(Queue* q) {
    size_t new_cap = (q->capacity == 0) ? 8 : q->capacity * 2;
    int* new_data = (int*)malloc(new_cap * sizeof(int));
    if (!new_data) return false;

    // copia em ordem lógica (head -> tail)
    for (size_t i = 0; i < q->size; i++) {
        new_data[i] = q->data[(q->head + i) % q->capacity];
    }

    free(q->data);
    q->data = new_data;
    q->capacity = new_cap;
    q->head = 0;
    q->tail = q->size;
    return true;
}

bool queue_enqueue(Queue* q, int value) {
    if (q->size == q->capacity) {
        if (!queue_grow(q)) return false;
    }
    q->data[q->tail] = value;
    q->tail = (q->tail + 1) % q->capacity;
    q->size++;
    return true;
}

bool queue_dequeue(Queue* q, int* out_value) {
    if (q->size == 0) return false;
    int v = q->data[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->size--;
    if (out_value) *out_value = v;
    return true;
}

bool queue_peek(const Queue* q, int* out_value) {
    if (q->size == 0) return false;
    if (out_value) *out_value = q->data[q->head];
    return true;
}

bool queue_is_empty(const Queue* q) {
    return q->size == 0;
}

size_t queue_size(const Queue* q) {
    return q->size;
}