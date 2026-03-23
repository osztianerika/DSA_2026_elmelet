#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <customs/constants.h> // A hibakodokat tartalmazo fajl

/**
* Egy struktura, amely egy egesz szamokat tartalmazo sort reprezental.
* @param capacity a sor kapacitasa
* @param front a verem elejenek indexe
* @param rear a verem vegenek indexe
* @param elements pointer a verem elemeire
*/
typedef struct
{
    int capacity;
    int front;
    int rear;
    int *elements;
} Queue_t;

/**
* Letrehozza a sor adatstrukturat, memoriat foglal az elemek szamara.
* @param capacity a sor kapacitasa
* @param queue pointer a sor strukturajahoz
*/
void createQueue(int capacity, Queue_t *queue);

/**
* Felszabaditja az elemek tombjehez lefoglalt memoriat.
* @param queue pointer a sor strukturajahoz
*/
void destroyQueue(Queue_t *queue);

/**
* Ellenorzi, hogy a sor tele van-e.
* @param queue a sor strukturaja
* @return igaz, ha tele van, hamis egyebkent
*/
bool isFullQueue(Queue_t queue);

/**
* Ellenorzi, hogy a sor ures-e.
* @param queue a sor strukturaja
* @return igaz, ha ures, hamis egyebkent
*/
bool isEmptyQueue(Queue_t queue);

/**
* Uj elemet ad a sor vegehez (FIFO).
* @param queue pointer a sor strukturajahoz
* @param item a hozzaadando elem
*/
void enqueue(Queue_t *queue, int item);

/**
* Eltavolitja a sor elejen levo elemet.
* @param queue pointer a sor strukturajahoz
* @return a levett elem
*/
int dequeue(Queue_t *queue);

/**
* Kiirja a sor osszes elemet.
* @param queue a sor strukturaja
*/
void displayQueue(Queue_t queue);