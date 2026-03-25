//
// Created by Erika on 3/11/2026.
//

#ifndef STACK_QUEUE_FUNCTIONS_STACK_H
#define STACK_QUEUE_FUNCTIONS_STACK_H

#include<stdio.h>
#include <stdlib.h>
#include <constans.h>
#include "functions.h"
void createStack(int capacity, Fuzet_Stack_t *stack);
/**
* Felszabadítja a veremhez lefoglalt memóriát.
* @param stack - pointer a verem struktúrájához
*/
void destroyStack(Fuzet_Stack_t* stack);

/**
* Ellenőrzi, hogy a verem tele van-e.
* @param stack - a verem struktúrája
* @return igaz, ha tele van, hamis egyébként
*/
bool isFull(Fuzet_Stack_t stack);
/**
* Ellenőrzi, hogy a verem üres-e.
* @param stack - a verem struktúrája
* @return igaz, ha üres, hamis egyébként
*/
bool isEmpty(Fuzet_Stack_t stack);
/**
* Új elemet helyez a verembe, ha nincs tele.
* @param stack - pointer a verem struktúrájához
* @param item - a beszúrandó elem
*/
void push(Fuzet_Stack_t* stack, Fuzet_t item);
/**
* Eltávolítja a verem tetején lévő elemet, ha nem üres.
* @param stack - pointer a verem struktúrájához
* @return a levett elem értéke
*/
Fuzet_t pop(Fuzet_Stack_t* stack);
/**
* Visszaadja a verem tetején lévő elemet, ha nem üres.
* @param stack - a verem struktúrája
* @return a tetején lévő elem értéke
*/
Fuzet_t peek(Fuzet_Stack_t stack);
/**
* Visszaadja a verem méretét.
* @param stack - a verem struktúrája
* @return a verem elemeinek száma
*/
int size(Fuzet_Stack_t stack);
int evaluation(char op, int number1, int number2);
#endif //STACK_QUEUE_FUNCTIONS_STACK_H