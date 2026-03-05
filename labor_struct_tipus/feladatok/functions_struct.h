//
// Created by Erika on 3/4/2026.
//

#ifndef FELADATOK_FUNCTIONS_STRUCT_H
#define FELADATOK_FUNCTIONS_STRUCT_H
#include <stdlib.h>
#include <stdio.h>
#include <constants.h>
enum Type {freshwater, saltwater};
enum Eat {herbivorous, carnivorous};
enum Mode {rod, net };
typedef struct {
  enum Eat eat;
    enum Mode mode;
}Catch_t;
typedef struct {
   enum Type type;
   char name[30];
   float size;
   float age;
   Catch_t catch;

}Fish_t;
char* getTypeDescription(enum Type type);
char* getEatDescription(enum Eat eat);
char* getModeDescription(enum Mode mode);
void readFishDetails(Fish_t *pFish);
void printFish(Fish_t fish);
void allocateMemoryForFishes(Fish_t **dpFishes, int numberOfFishes);
void readAllFishesDetails(Fish_t **dpFishes, int *pNumberOfFishes,const char *input);
void printAllFish(Fish_t *pFishes, int numberOfFishes, const char *destination);



#endif //FELADATOK_FUNCTIONS_STRUCT_H