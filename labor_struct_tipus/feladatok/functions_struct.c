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







