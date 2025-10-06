#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef void* QueueValue;

typedef struct {
    QueueValue *data; // Double void pointer for data inside the Queue
    int head;         // Track the first element
    int tail;         // track the last element
    int size;         // Size of the queue
    int capacity;     // Maximum element inside the queue
} Queue;

void print_queue(Queue *queue);
Queue* create_queue(size_t queue_length);
int isEmpty(Queue *queue);
void enqueue(Queue *queue, void* data); 
void* dequeue(Queue *queue);
void* peek(Queue *queue);
void print_queue_info(Queue *queue);

#endif
