//
// Created by Erika on 3/4/2026.
//

#ifndef FELADATOK_FUNCTIONS_STRUCT_H
#define FELADATOK_FUNCTIONS_STRUCT_H
#include <stdlib.h>
#include <stdio.h>
#include <constants.h>
/*
1.	type
2.	name
3.	size
4.	age
5.	eat
6.	mode
Enum kódok:
•type: 0 = freshwater, 1 = saltwater
•eat: 0 = herbivorous, 1 = carnivorous
•mode: 0 = rod, 1 = net
*/

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
//visszaadja a tipus szöveges reprezentációját
char* getTypeDescription(enum Type type);
//visszaadja a táplálkozási mód szöveges reprezentációját
char* getEatDescription(enum Eat eat);
//visszaadja a fogás jellemzőjének szöveges reprezentációját
char* getModeDescription(enum Mode mode);
//egy hal adataink a beolvasása
void readFishDetails(Fish_t *pFish);
//egy hal adataink a kiiratasa
void printFish(Fish_t fish);
//helyfoglalas több halnak, tárolásuk egy tömbben
void allocateMemoryForFishes(Fish_t **dpFishes, int numberOfFishes);
//több hal adataink a beolvasása
void readAllFishesDetails(Fish_t **dpFishes, int *pNumberOfFishes,const char *input);
//egy hal adataink a kiíratása
void printAllFish(Fish_t *pFishes, int numberOfFishes, const char *destination);



#endif //FELADATOK_FUNCTIONS_STRUCT_H