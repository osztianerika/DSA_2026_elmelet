//
// Created by Boti on 23-Mar-26.
//
#include "airport.h"


void readFlight(Flight_t* pFlight)
{
    scanf("%i\n", &pFlight->flightID);
    scanf("%[^\n]\n",pFlight->to );
    scanf("%i", &pFlight->seats);
    scanf("%d%d%d%d", &pFlight->departureTime.month, &pFlight->departureTime.day, &pFlight->departureTime.hour, &pFlight->departureTime.min);
    scanf("%i",&pFlight->function_e);
}

void printFlight(Flight_t flight)
{
    printf("%i ", flight.flightID);
    printf("%s ",flight.to);
    printf("%i ", flight.seats);
    printf("%d %d %d %d ", flight.departureTime.month, flight.departureTime.day, flight.departureTime.hour, flight.departureTime.min);
    printf("%s ", getDescriptionFlightFunction(flight.function_e));
    printf("\n");
}

bool isFull(FlightArray_t array)
{
}

bool isEmpty(FlightArray_t array)
{
}

void insertFirst(FlightArray_t* pArray, Flight_t item)
{
}

void deallocateFlightArray(FlightArray_t* pArray)
{
}

int countInternationalFlights(FlightArray_t array, int minSeats, int* totalInternational)
{
}


// void createFlightArray(int capacity, FlightArray_t* pArray)
// {
// }

char* getDescriptionFlightFunction(enum FlightType flight)
{
    switch (flight)
    {
    case 0 : return "UTAS";
    case 1 : return "TEHER";
    case 2 : return "MAGAN";
    default : return "MAS";
    }
}




