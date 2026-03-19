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

void enqueue(Queue_t *queue, int item) {
    if (isFullQueue(*queue)) {
        printf("Queue is full ");
        exit(-2);
    }
    if (queue->front==-1) {
        queue->front++;
        queue->elements[++queue->rear]=item;
    }
    else {
        queue->elements[++queue->rear]=item;
    }
}

int dequeue(Queue_t *queue) {
    if (isEmptyQueue(*queue)) {
        printf("Queue is empty ");
        exit(-2);
    }
    int save;
    if (queue->front==queue->rear) {
        save=queue->elements[queue->front];
        queue->front=-1;
        queue->rear=-1;
    }
    else {
        save=queue->elements[queue->front];
        queue->front++;
    }
    return save;
}

void display(Queue_t queue) {
    for (int i=queue.front;i<=queue.rear;i++) {
        printf("%i ",queue.elements[i]);
    }
    printf("\n");

}

