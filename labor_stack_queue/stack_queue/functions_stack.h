//
// Created by Erika on 3/11/2026.
//

#ifndef STACK_QUEUE_FUNCTIONS_STACK_H
#define STACK_QUEUE_FUNCTIONS_STACK_H
typedef struct {
    int top;
    int capacity;
    int *elements;
}Stack_t;
#include<stdio.h>
#include <stdlib.h>
#include <constants.h>
void createStack(int capacity, Stack_t *stack);
/**
* Felszabadítja a veremhez lefoglalt memóriát.
* @param stack - pointer a verem struktúrájához
*/
void destroyStack(Stack_t* stack);

/**
* Ellenőrzi, hogy a verem tele van-e.
* @param stack - a verem struktúrája
* @return igaz, ha tele van, hamis egyébként
*/
bool isFull(Stack_t stack);
/**
* Ellenőrzi, hogy a verem üres-e.
* @param stack - a verem struktúrája
* @return igaz, ha üres, hamis egyébként
*/
bool isEmpty(Stack_t stack);
/**
* Új elemet helyez a verembe, ha nincs tele.
* @param stack - pointer a verem struktúrájához
* @param item - a beszúrandó elem
*/
void push(Stack_t* stack, int item);
/**
* Eltávolítja a verem tetején lévő elemet, ha nem üres.
* @param stack - pointer a verem struktúrájához
* @return a levett elem értéke
*/
int pop(Stack_t* stack);
/**
* Visszaadja a verem tetején lévő elemet, ha nem üres.
* @param stack - a verem struktúrája
* @return a tetején lévő elem értéke
*/
int peek(Stack_t stack);
/**
* Visszaadja a verem méretét.
* @param stack - a verem struktúrája
* @return a verem elemeinek száma
*/
int size(Stack_t stack);
#endif //STACK_QUEUE_FUNCTIONS_STACK_H