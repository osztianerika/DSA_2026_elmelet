//
// Created by Boti on 23-Mar-26.
//

#include "airport.h"


void readFlight(Flight_t *pFlight) {
    scanf("%i\n", &pFlight->fligthID);
    scanf("%[^\n]\n",pFlight->to);
    scanf("%i",&pFlight->seats);
    scanf("%d%d%d%d", &pFlight->departureTime.month,&pFlight->departureTime.day,&pFlight->departureTime.hour,&pFlight->departureTime.min);
    scanf("%i",&pFlight->fligthType);
}

void printFlight(Flight_t pFlight_t) {
    printf("%i ", pFlight_t.fligthID);
    printf("%s ",pFlight_t.to);
    printf("%i ",pFlight_t.seats);
    printf("%d %d %d %d ", pFlight_t.departureTime.month,pFlight_t.departureTime.day,pFlight_t.departureTime.hour,pFlight_t.departureTime.min);
    printf("%i ",pFlight_t.fligthType);
    printf("\n");
}
void createIntArray(int capacity, FlightArray_t *pArray) {
    pArray->capacity = capacity;
    pArray->size = 0;
    pArray->elements = (Flight_t*)calloc(pArray->capacity, sizeof (Flight_t));
    if(!pArray->elements) {
        printf("MEMORY_ALLOCATION_ERROR_MESSAGE");
        exit(-2);
    }
}
bool isFull(FlightArray_t array) {
    return array.size == array.capacity;
}
bool isEmpty(FlightArray_t array) {
    return array.size == 0;
}
void printArray(FlightArray_t array) {
    if(isEmpty(array)) {
        printf("EMPTY_MESSAGE");
        return;
    }
    printf("The elements of the array:");
    for (int i = 0; i < array.size; ++i) {
        printFlight(array.elements[i]);
    }
    printf("\n");
}
void insertFirst(FlightArray_t *pArray, Flight_t item) {
    if(isFull(*pArray)) {
        printf("FULL_MESSAGE");
        return;
    }
    for (int i = pArray->size; i > 0; --i) {
        pArray->elements[i] = pArray->elements[i-1];
    }
    pArray->elements[0] = item;
    pArray->size++;
}
void deallocateIntArray(FlightArray_t *pArray) {
    free(pArray->elements);
    pArray->capacity = pArray->size = 0;
    pArray = NULL;
}