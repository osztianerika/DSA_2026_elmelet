#pragma once

typedef struct
{
    int ev, honap, nap, ora, perc;
} Time_t;

typedef enum {
    KESZPENZ,
    BANKKARTYA,
    ONLINE
} Payment_t;

typedef struct
{
    int azonosito;
    char nev[51];
    float ar;
    Time_t rendelesIdop;
    Payment_t fizetesiMod;
    bool kiszallitva;
} Order_t;

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
    Order_t *elements;
} Queue_t;

/**
 * Egy rendelés adatainak beolvasása billentyűzetről.
 * @param order pointer egy rendeles adataihoz
 */
void readOneOrder(Order_t *order);
/**
 * Egyetlen rendelés adatainak formázott kiírása a képernyőre.
 * @param order Order_t tipusu valtozo
 */
void printOneOrder(Order_t order);
/**
* Létrehozza a sor adatstruktúrát, memóriát foglal az elemek számára.
* @param capacity - a sor kapacitása
* @param queue - pointer a sor struktúrájához
*/

void createQueue(int capacity, Queue_t *queue);

/**
 *
 * @param payment enum tipusu valtozo
 * @return karakterlancot, amely leirja a fizetes tipusat
 */
char *getDescriptionTypePayment(Payment_t payment);
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
* @param item - a hozzáadandó elem
*/
void enqueue(Queue_t* queue, Order_t item);
/**
* Eltávolítja a sor elején lévő elemet.
* @param queue - pointer a sor struktúrájához
* @return a levett elemet
*/
Order_t dequeue(Queue_t* queue);
/**
* Kiírja a sor összes elemét.
* @param queue - a sor struktúrája
*/
void displayQueue(Queue_t queue);

/**
 *
 * @param queue a sor
 * @param minSumLimit  a minimalis osszeg
 * @return a jutalom osszege vagy 0, ha nem rendeltek legalabb minimalis osszeget
 */
double calculateCourierBonus(Queue_t queue, double minSumLimit);