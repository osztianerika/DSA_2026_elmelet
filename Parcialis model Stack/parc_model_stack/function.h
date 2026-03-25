//
// Created by rober on 2026. 03. 25..
//

#ifndef PARC_MODEL_STACK_FUNCTION_H
#define PARC_MODEL_STACK_FUNCTION_H


typedef struct {
    int year;
    int month;
}Date_t;

typedef enum Type_t {eloetel,foetel,leves};
typedef struct {
    int id;
    enum Type_t tipus;
    Date_t vasarlasi_ido;
    char szin[30];
}Plate_t;

typedef struct {
    int top;
    int capacity;
    Plate_t *elements;
}PlateStack_t;

#include<stdio.h>
#include <stdlib.h>
#include <constants.h>
void createStack(int capacity, PlateStack_t *stack);
/**
* Felszabadítja a veremhez lefoglalt memóriát.
* @param stack - pointer a verem struktúrájához
*/
void destroyStack(PlateStack_t* stack);

/**
* Ellenőrzi, hogy a verem tele van-e.
* @param stack - a verem struktúrája
* @return igaz, ha tele van, hamis egyébként
*/
bool isFull(PlateStack_t stack);
/**
* Ellenőrzi, hogy a verem üres-e.
* @param stack - a verem struktúrája
* @return igaz, ha üres, hamis egyébként
*/
bool isEmpty(PlateStack_t stack);
/**
* Új elemet helyez a verembe, ha nincs tele.
* @param stack - pointer a verem struktúrájához
* @param item - a beszúrandó elem
*/
void push(PlateStack_t* stack, Plate_t item);
/**
* Eltávolítja a verem tetején lévő elemet, ha nem üres.
* @param stack - pointer a verem struktúrájához
* @return a levett elem értéke
*/
Plate_t pop(PlateStack_t* stack);
/**
* Visszaadja a verem tetején lévő elemet, ha nem üres.
* @param stack - a verem struktúrája
* @return a tetején lévő elem értéke
*/
Plate_t peek(PlateStack_t stack);
/**
* Visszaadja a verem méretét.
* @param stack - a verem struktúrája
* @return a verem elemeinek száma
*/
int size(PlateStack_t stack);

/**
 * Beolvassa egy tányér adatait billentyűzetről.
 * A felhasználótól bekéri az összes mezőt, majd feltölti a struktúrát.
 *
 * @param p A beolvasandó Plate_t struktúra címe
 */
void readPlate(Plate_t *p);

/**
 * Kiírja egy tányér adatait a standard kimenetre.
 * Az enum típus szöveges megfelelőjét is megjeleníti.
 *
 * @param p A kiírandó Plate_t struktúra
 */
void printPlate(Plate_t p);

/**
 * Visszaadja a tányér típusának szöveges megfelelőjét.
 *
 * @param type A tányér típusa (enum Type_t)
 * @return A típus szöveges leírása (pl. "eloetel", "leves", "foetel")
 */
char* getDescriptionPlate(enum Type_t type);

/**
 * Szimulálja a tányérok kiosztását a három veremből.
 * A kiosztás sorrendje: foetel -> leves -> eloetel.
 * A folyamat addig tart, amíg mindhárom verem nem üres.
 * Ha bármelyik verem kiürül, a kiosztás leáll.
 *
 * A függvény közben megszámolja, hogy hány azonos színű
 * (egyszínű) tányér kerül kiosztásra egymás után.
 *
 * @param foetelStack A főételes tányérok vereme
 * @param levesStack A leveses tányérok vereme
 * @param eloetelStack Az előételes tányérok vereme
 * @return Az egymás után kiosztott azonos színű tányérok száma
 */
int simulateServing(PlateStack_t *foetelStack,
                    PlateStack_t *levesStack,
                    PlateStack_t *eloetelStack);
#endif //PARC_MODEL_STACK_FUNCTION_H