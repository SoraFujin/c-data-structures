#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef void* QueueValue;
typedef struct Queue Queue;

Queue* create_queue(size_t queue_length);
int isEmpty(Queue *queue);
void enqueue(Queue *queue, void* data); 
void* dequeue(Queue *queue);
void* peek(Queue *queue);
void print_queue(Queue *queue);
void print_queue_info(Queue *queue);

#endif
