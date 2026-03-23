#include "functions.h"
#include <stdio.h>
#include <customs/constants.h>
#include <stdlib.h>

void readOneOrder(Order_t *order)
{
    scanf("%d", &order->azonosito);
    scanf("\n%[^\n]", order->nev);
    scanf("%f", &order->ar);
    scanf("%d%d%d%d%d", &order->rendelesIdop.ev, 
        &order->rendelesIdop.honap, 
        &order->rendelesIdop.nap, 
        &order->rendelesIdop.ora, 
        &order->rendelesIdop.perc);
    scanf("%d", &order->fizetesiMod);
    scanf("%d", &order->kiszallitva);
}

char *getDescriptionTypePayment(Payment_t payment)
{
    switch(payment)
    {
        case KESZPENZ: return "Keszpenz";
        case BANKKARTYA: return "Bankkartya";
        case ONLINE: return "Online";
        default: return "Ismeretlen";
    }
    return "Ismeretlen";
}

void printOneOrder(Order_t order)
{
    printf("Azonosito: %d\n", order.azonosito);
    printf("Nev: %s\n", order.nev);
    printf("Ar: %.2f\n", order.ar);
    printf("Datum: %d/%02d/%02d - %02d:%02d\n", order.rendelesIdop.ev, 
        order.rendelesIdop.honap, 
        order.rendelesIdop.nap, 
        order.rendelesIdop.ora, 
        order.rendelesIdop.perc);
    printf("Fizetesi mod: %s\n", getDescriptionTypePayment(order.fizetesiMod));
    if(order.kiszallitva) printf("Kiszallitva\n");
    else printf("Nincs kiszallitva\n");
}

void createQueue(int capacity, Queue_t *queue)
{
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->elements = (Order_t*)calloc(capacity, sizeof(Order_t));
    if(!queue->elements)
    {
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void destroyQueue(Queue_t *queue)
{
    if(!queue)
    {
        printf("%s", NULL_POINTER_ERROR_MESSAGE);
        return;
    }
    free(queue->elements);
    queue->rear = -1;
    queue->front = -1;
    queue->capacity = 0;
    queue = NULL;
}

bool isFullQueue(Queue_t queue)
{
    return queue.capacity - 1 == queue.rear;
}

bool isEmptyQueue(Queue_t queue)
{
    if(queue.front == -1)
    {
        if(queue.rear == -1)
        {
            return true;
        }
    }
    return false;
}

void enqueue(Queue_t *queue, Order_t item)
{
    if(!queue)
    {
        printf("%s", NULL_POINTER_ERROR_MESSAGE);
        exit(NULL_POINTER_ERROR_CODE);
    }
    if(isFullQueue(*queue))
    {
        printf("%s", DATA_STRUCTURE_FULL_ERROR_MESSAGE);
        exit(DATA_STRUCTURE_FULL_ERROR_CODE);
    }
    if(queue->front == -1)
    {
        ++queue->front;
        queue->elements[++queue->rear] = item;
    }
    else
    {
        queue->elements[++queue->rear] = item;
    }
}

Order_t dequeue(Queue_t *queue)
{
    if(!queue)
    {
        printf("%s", NULL_POINTER_ERROR_MESSAGE);
        exit(NULL_POINTER_ERROR_CODE);
    }
    if(isEmptyQueue(*queue))
    {
        printf("%s", DATA_STRUCTURE_EMPTY_ERROR_MESSAGE);
        exit(DATA_STRUCTURE_EMPTY_ERROR_CODE);
    }
    
    Order_t save;
    if(queue->front == queue->rear)
    {
        save = queue->elements[queue->front];
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        save = queue->elements[queue->front];
        ++queue->front;
    }
    return save;
}

void displayQueue(Queue_t queue)
{
    for(int i = queue.front; i <= queue.rear; ++i)
    {
        printOneOrder(queue.elements[i]);
    }
    printf("\n");
}

double calculateCourierBonus(Queue_t queue, double minSumLimit)
{
    double onlinePenz = 0.f;
    double keszpenzPenz = 0.f;
    double osszPenz = 0.f;
    while(!isEmptyQueue(queue))
    {
        Order_t curr = dequeue(&queue);
        if(curr.kiszallitva == 0) continue;
        osszPenz += (double)curr.ar;
        if(curr.fizetesiMod == ONLINE) onlinePenz += (double)curr.ar;
        else if(curr.fizetesiMod == KESZPENZ) keszpenzPenz += (double)curr.ar;
    }
    if(onlinePenz > keszpenzPenz && onlinePenz > minSumLimit) return osszPenz * .1f;
    return 0.f;
}