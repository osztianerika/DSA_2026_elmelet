//
// Created by Erika on 3/11/2026.
//

#ifndef STACK_QUEUE_FUNCTIONS_QUEUE_H
#define STACK_QUEUE_FUNCTIONS_QUEUE_H
typedef struct {
    int capacity;
    int front;
    int rear;
    int *elements;
}Queue_t;
/**
* Létrehozza a sor adatstruktúrát, memóriát foglal az elemek számára.
* @param capacity - a sor kapacitása
* @param queue - pointer a sor struktúrájához
*/
void createQueue(int capacity, Queue_t *queue);

/**
* Felszabadítja az elemek tömbjéhez lefoglalt memóriát.
* @param queue - pointer a sor struktúrájához
*/
void destroyQueue(Queue_t* queue);
/**
* Ellenőrzi, hogy a sor tele van-e.
* @param queue - a sor struktúrája
* @return igaz, ha tele van, hamis egyébként
*/
bool isFullQueue(Queue_t queue);
/**
* Ellenőrzi, hogy a sor üres-e.
* @param queue - a sor struktúrája
* @return igaz, ha üres, hamis egyébként
*/
bool isEmptyQueue(Queue_t queue);
/**
* Új elemet ad a sor végéhez (FIFO).
* @param queue - pointer a sor struktúrájához
* @param item - a hozzáadandó elem (karakterlánc)
*/
void enqueue(Queue_t* queue, int item);
/**
* Eltávolítja a sor elején lévő elemet.
* @param queue - pointer a sor struktúrájához
* @return a levett elem (karakterlánc)
*/
int dequeue(Queue_t* queue);
/**
* Kiírja a sor összes elemét.
* @param queue - a sor struktúrája
*/
void display(Queue_t queue);
#endif //STACK_QUEUE_FUNCTIONS_QUEUE_H