#include "../include/queue.h"

struct Queue{
    QueueValue *data; // Double void pointer for data inside the Queue
    int head;         // Track the first element
    int tail;         // track the last element
    int size;         // Size of the queue
    int capacity;     // Maximum element inside the queue
};

Queue* create_queue(size_t queue_length)
{
    Queue *queue = malloc(sizeof(Queue));
    if(!queue)
    {
        printf("Error creating queue on HEAP\n");
        return NULL;
    }
    queue->data = malloc(queue_length * sizeof(QueueValue));
    if(!queue->data)
    {
        printf("Error Allocating memory for data\n");
        free(queue);
        return NULL;
    }
    queue->capacity = queue_length;
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;

    return queue;
}

int isEmpty(Queue *queue)
{
    if(!queue)
        return 1;
    return queue->size == 0;
}

int isFull(Queue *queue)
{
    if(!queue)
        return 1;
    return queue->size == queue->capacity;
}

void enqueue(Queue *queue, void* data) 
{
    if(!queue || !data)
        return;

    if(isFull(queue))
    {
        printf("Queue is Full\n");
        return;
    }

    queue->data[queue->tail] = data;
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->size++;
}

void* dequeue(Queue *queue)
{
    if(!queue)
        return NULL;

    if(isEmpty(queue))
    {
        printf("Queue is empty\n");
        return NULL;
    }

    void *element = queue->data[queue->head];
    queue->head = (queue->head + 1) % queue->capacity;
    queue->size--;
    return element;
}

void* peek(Queue *queue)
{
    if(!queue)
        return NULL;
    if(isEmpty(queue))
    {
        printf("Queue is empty\n");
        return NULL;
    }

    void* element = queue->data[queue->head];
    return element;
}

void free_queue(Queue *queue)
{
    if(!queue)
        return;  

    free(queue->data);
    free(queue);

    printf("Queue freed from memory\n");
}

void print_queue_info(Queue *queue)
{
    int options;
    do {
        printf("Choose one of the following options:\n"
                "1. Print All Elements in Queue.\n"
                "2. Print Size of Queue.\n"
                "3. Print Capacity of Queue.\n"
                "4. Exit\n");

        scanf("%d", &options);

        switch (options) {
            case 1: 
                print_queue(queue);
                break;
            case 2:
                printf("Size of the queue: %d\n", queue->size);
                break;
            case 3:
                printf("Capacity of the queue: %d\n", queue->capacity);
                break;
            case 4:
                printf("Exiting...\n");
                return;
                break;
            default:
                printf("Please choose one of the options (1, 2, 3)\n");
                break;
        }
    } while(options <= 4);

}

void print_queue(Queue *queue)
{
    if(!queue)
        return;
    for (int i = 0; i < queue->size; i++) {
        printf("%d", *(int *)queue->data[i]);
        if (i < queue->size - 1) {
            printf(" -> ");
        }
    }
    printf("\n");
}
