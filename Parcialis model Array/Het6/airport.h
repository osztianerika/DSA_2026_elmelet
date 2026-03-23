//
// Created by Boti on 23-Mar-26.
//
#include <stdio.h>
#ifndef HET6_AIRPORT_H
#define HET6_AIRPORT_H
typedef struct
{
    int month;
    int day;
    int hour;
    int min;
}Time_t;



typedef struct
{
    int flightID;
    char to[51];
    int seats;
    Time_t departureTime;
    enum FlightType
    {
        UTAS,TEHER, MAGAN, MAS
    }function_e;
}Flight_t;

typedef struct
{
    int size;
    int maxCapacity;
    Flight_t* elements;
}FlightArray_t;

/**
 * Beolvassa egy Flight_t típusú változó adatait billentyűzetről.
 * @param pFlight - pointer a Flight_t struktúrához
 */
void readFlight(Flight_t *pFlight);

/**
 * Kiírja egy Flight_t típusú változó adatait.
 * @param flight - a kiírandó struktúra
 */
void printFlight(Flight_t flight);/**
 * Memóriát foglal egy tömb számára egy adott kapacitással.
 * @param capacity - a tömb kapacitása
 * @param pArray - pointer a tömb struktúrájához
 */

void createFlightArray(int capacity, FlightArray_t* pArray);

/**
 * Kiírja a tömb összes elemét.
 * @param array - a tömb struktúrája
 */
void printArray(FlightArray_t array);

/**
 * Ellenőrzi, hogy a tömb tele van-e.
 * @param array - a tömb struktúrája
 * @return igaz, ha tele van, hamis egyébként
 */
bool isFull(FlightArray_t array);

/**
 * Ellenőrzi, hogy a tömb üres-e.
 * @param array - a tömb struktúrája
 * @return igaz, ha üres, hamis egyébként
 */
bool isEmpty(FlightArray_t array);

/**
 * Beszúr egy elemet a tömb elejére.
 * @param pArray - pointer a tömb struktúrájához
 * @param item - a beszúrandó elem
 */
void insertFirst(FlightArray_t* pArray, Flight_t item);

/**
 * Beszúr egy elemet a tömb végére.
 * @param pArray - pointer a tömb struktúrájához
 * @param item - a beszúrandó elem
 */

/**
 * Felszabadítja a tömb számára lefoglalt memóriát.
 * @param pArray - pointer a tömb struktúrájához
 */
void deallocateFlightArray(FlightArray_t *pArray);
/**
 * Megszámolja a nemzetközi járatokat a tömbben, valamint ezek közül
 * azokat, amelyek férőhelyszáma legalább a megadott küszöbérték.
 *
 * @param array a járatokat tartalmazó tömb
 * @param minSeats a férőhelyek alsó határa
 * @param totalInternational pointer, amelyben visszaadja a nemzetközi járatok számát
 * @return azon nemzetközi járatok száma, amelyek férőhelyszáma >= minSeats
 */
int countInternationalFlights(FlightArray_t array, int minSeats, int *totalInternational);

char* getDescriptionFlightFunction(enum FlightType flight );

#endif //HET6_AIRPORT_H