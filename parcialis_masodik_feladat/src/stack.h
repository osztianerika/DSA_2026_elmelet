#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <customs/constants.h> // A hibakodokat tartalmazo fajl

/**
* Egy struktura, amely egy egesz szamokat tartalmazo veremet reprezental.
* @param capacity a verem kapacitasa
* @param top a verem tetejenek indexe
* @param elements pointer a verem elemeire
*/
typedef struct
{
    int capacity;
    int top;
    int *elements;
} Stack;

/**
* Inicializalja a verem kapacitasat es tetejet,
* memoriat foglal az elemek tombhoz.
* @param capacity a verem kapacitasa
* @param stack pointer a verem strukturajahoz
*/
void createStack(int capacity, Stack *stack);

/**
* Felszabaditja a veremhez lefoglalt memoriat.
* @param stack pointer a verem strukturajahoz
*/
void destroyStack(Stack *stack);

/**
* Ellenorzi, hogy a verem tele van-e.
* @param stack a verem strukturaja
* @return igaz, ha tele van, hamis egyebkent
*/
bool isFullStack(Stack stack);

/**
* Ellenorzi, hogy a verem ures-e.
* @param stack a verem strukturaja
* @return igaz, ha ures, hamis egyebkent
*/
bool isEmptyStack(Stack stack);

/**
* Uj elemet helyez a verembe, ha nincs tele.
* @param stack pointer a verem strukturajahoz
* @param item a beszurando elem
*/
void push(Stack *stack, int item);

/**
* Eltavolitja a verem tetejen levo elemet, ha nem ures.
* @param stack pointer a verem strukturajahoz
* @return a levett elem erteke
*/
int pop(Stack *stack);

/**
* Visszaadja a verem tetejen levo elemet, ha nem ures.
* @param stack a verem strukturaja
* @return a tetejen levo elem erteke
*/
int peek(Stack stack);

/**
* Visszaadja a verem meretet.
* @param stack a verem strukturaja
* @return a verem elemeinek szama
*/
int size(Stack stack);