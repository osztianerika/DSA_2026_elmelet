#include "airport.h"
#include <constants.h>
#include <stdlib.h>

int main(void) {
    /*Flight_t flight1,flight2;
    readFlight(&flight1);
    freopen("eredmeny_repulok.txt","w",stdout);
    printFlight(flight1);
    if (!freopen("flight_one.txt","r",stdin)) {
        printf("FAILED TO ACCES DIRECTORY");
        return -1;
    }
    readFlight(&flight2);
    printFlight(flight2);*/
    int n;
    Flight_t fligth;
    FlightArray_t array;
    createFlightArray(100,&array);
    if (!freopen("flights.txt","r",stdin)) {
        printf("ERROR");
        return -1;
    }
    scanf("%i",&n);
    for (int i=0;i<n;i++) {
        readFlight(&fligth);
        insertFirst(&array,fligth);
    }
    return 0;
}