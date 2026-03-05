//
// Created by Erika on 3/4/2026.
//

#include "functions_struct.h"

char * getTypeDescription(enum Type type) {
    switch (type) {
        case 0: return "freshwater";
        case 1: return "saltwater";
        default: return "Other";
    }
}
char * getEatDescription(enum Eat eat) {
    switch (eat) {
        case 0: return "herbivorous";
        case 1: return "carnivorous";
        default: return "Other";
    }
}

char * getModeDescription(enum Mode mode) {
    switch (mode) {
        case 0: return "rod";
        case 1: return "net";
        default: return "Other";
    }
}

void readFishDetails(Fish_t *pFish) {
    scanf("%i\n",&pFish->type);
    scanf("%[^\n]\n",pFish->name);
    scanf("%f",&pFish->size);
    scanf("%f",&pFish->age);
    scanf("%i",&pFish->catch.eat);
    scanf("%i",&pFish->catch.mode);
}

void printFish(Fish_t fish) {
    printf("\n%s %s %.2f %.2f %s %s",getTypeDescription(fish.type),fish.name,fish.size,fish.age,getEatDescription(fish.catch.eat),getModeDescription(fish.catch.mode));
}

void allocateMemoryForFishes(Fish_t **dpFishes, int numberOfFishes) {
    *dpFishes = (Fish_t*)malloc(numberOfFishes * sizeof(Fish_t));
    if (*dpFishes == NULL) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void readAllFishesDetails(Fish_t **dpFishes, int *pNumberOfFishes, const char *input) {
   if(!freopen(input,"r",stdin)) {
       printf(FILE_OPENING_ERROR_MESSAGE);
       exit(FILE_OPENING_ERROR_CODE);
   }
    scanf("%d", pNumberOfFishes);
    allocateMemoryForFishes(dpFishes, *pNumberOfFishes);
    for (int i = 0; i < *pNumberOfFishes; i++) {
        readFishDetails(&(*dpFishes)[i]);
    }
    freopen("CON", "r", stdin);
}

void printAllFish(Fish_t *pFishes, int numberOfFishes, const char *destination) {
    freopen(destination, "w", stdout);
    for (int i = 0; i < numberOfFishes; i++) {
        printFish(pFishes[i]);
    }
    freopen("CON", "w", stdout);
}








