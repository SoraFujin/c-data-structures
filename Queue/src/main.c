#include <stdio.h>

typedef void QueueValue;

typedef struct {
    
} Queue;

void initalize_queue(size_t size);
void push(void* data);
void pop();
void peek();
int isEmpty();
int isFull();
void free_queue();
static void* queue;

int main() {
    printf("Hello, World!\n");
    return 0;
}


