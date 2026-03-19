//
// Created by Erika on 3/19/2026.
//

#ifndef ARRAY_STACK_QUEUE_FUNCTIONS_ARRAY_H
#define ARRAY_STACK_QUEUE_FUNCTIONS_ARRAY_H
typedef struct {
 int capacity;
 int size;
 int *elements;
} IntArray;
/**
* Memóriát foglal egy tömb számára egy adott kapacitással.
* @param capacity - a tömb kapacitása
* @param pArray - pointer a tömb struktúrájához
*/
void createIntArray(int capacity, IntArray* pArray);
/**
* Kiírja a tömb összes elemét.
* @param array - a tömb struktúrája
*/
2
void printArray(IntArray array);
/**
* Ellenőrzi, hogy a tömb tele van-e.
* @param array - a tömb struktúrája
* @return igaz, ha tele van, hamis egyébként
*/
bool isFull(IntArray array);
/**
* Ellenőrzi, hogy a tömb üres-e.
* @param array - a tömb struktúrája
* @return igaz, ha üres, hamis egyébként
*/
bool isEmpty(IntArray array);
/**
* Visszaadja a megadott pozíción lévő elemet, ha a pozíció helyes.
* @param array - a tömb struktúrája
* @param position - az elem pozíciója
* @return az elem értéke vagy INT_MIN, ha a pozíció helytelen
*/
int getItemAt(IntArray array, int position);
/**
* Beszúr egy elemet a tömb elejére.
* @param pArray - pointer a tömb struktúrájához
* @param item - a beszúrandó elem
*/
void insertFirst(IntArray* pArray, int item);
/**
* Beszúr egy elemet a tömb végére.
* @param pArray - pointer a tömb struktúrájához
* @param item - a beszúrandó elem
*/
void insertLast(IntArray* pArray, int item);
/**
* Beszúr egy elemet egy adott pozícióra, ha a pozíció helyes.
* @param pArray - pointer a tömb struktúrájához
* @param position - a pozíció
* @param item - a beszúrandó elem
*/
void insertAt(IntArray* pArray, int position, int item);
/**
* Töröl egy elemet egy adott pozícióról, ha a pozíció helyes.
* @param pArray - pointer a tömb struktúrájához
* @param position - a törlendő elem pozíciója
*/
void deleteItemAt(IntArray* pArray, int position);
/**
* Keres egy elemet a tömbben.
* @param pArray - a tömb struktúrája
* @param item - a keresendő elem
* @return a pozíció, ha megtalálta, -1, ha nem található
*/
int search(IntArray pArray, int item);
3
/**
* Frissít egy elemet egy adott pozíción egy új értékkel, ha a pozíció
helyes.
* @param pArray - pointer a tömb struktúrájához
* @param position - a pozíció
* @param newItem - az új elem értéke
* @return igaz, ha a frissítés sikeres, hamis egyébként
*/
bool update(IntArray* pArray, int position, int newItem);
/**
* Felszabadítja a tömb számára lefoglalt memóriát.
* @param pArray - pointer a tömb struktúrájához
*/
void deallocateIntArray(IntArray *pArray);
#endif //ARRAY_STACK_QUEUE_FUNCTIONS_ARRAY_H