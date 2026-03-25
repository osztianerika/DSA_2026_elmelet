//
// Created by fkris on 3/25/2026.
//

#include "functions.h"

#include <stdio.h>

void readFuzet(Fuzet_t *fuzet) {
    scanf("%d",&fuzet->lapszam);
    scanf("%d\n",&fuzet->tipus);
    scanf("%[^\n]\n",fuzet->szin);
    scanf("%d",&fuzet->gyartas.ev);
    scanf("%d",&fuzet->gyartas.honap);
    scanf("%d",&fuzet->gyartas.nap);
}
void printFuzet(Fuzet_t fuzet) {
    printf("%d ",fuzet.lapszam);
    printf("%s ",getDescription(fuzet.tipus));
    printf("%s ",fuzet.szin);
    printf("%d ",fuzet.gyartas.ev);
    printf("%d ",fuzet.gyartas.honap);
    printf("%d ",fuzet.gyartas.nap);
}

char * getDescription(enum Tipus_t fuzet) {
    switch (fuzet) {
        case vonalas:
            return "Vonalas";
        case kockas:
            return "Kockas";
        case sima:
            return "Sima";
        default:return "Helytelen";
    }
}
