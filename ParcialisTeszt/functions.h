//
// Created by fkris on 3/25/2026.
//

#ifndef PARCIALISTESZT_FUNCTIONS_H
#define PARCIALISTESZT_FUNCTIONS_H
enum Tipus_t {vonalas,kockas,sima};
typedef  struct {
    int ev,honap,nap;
}Gyartas_t;
typedef struct {
    int lapszam;
    enum Tipus_t tipus;
    char szin[20];
    Gyartas_t gyartas;
}Fuzet_t;
typedef struct {
    int capacity;
    int top;
    Fuzet_t *elements;
}Fuzet_Stack_t;

void readFuzet(Fuzet_t *fuzet);
void printFuzet(Fuzet_t fuzet);
char *getDescription(enum Tipus_t fuzet);


#endif //PARCIALISTESZT_FUNCTIONS_H