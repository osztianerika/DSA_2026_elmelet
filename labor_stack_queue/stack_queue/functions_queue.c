//
// Created by Erika on 3/11/2026.
//

#include "functions_queue.h"




void createQueue(int capacity, Queue_t *queue) {
    queue->capacity=capacity;
    queue->front=-1;
    queue->rear=-1;
    queue->elements=(int*)calloc(capacity,sizeof(int));
    if (!queue->elements) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void destroyQueue(Queue_t *queue) {
    free(queue->elements);
    queue->rear=-1;
    queue->front=-1;
    queue->capacity=0;
    queue=NULL;
}

bool isFullQueue(Queue_t queue) {
    return queue.capacity-1==queue.rear;
}

bool isEmptyQueue(Queue_t queue) {
    if (queue.front==-1) {
        if (queue.rear==-1){return true;}
    }
    return false;
}

