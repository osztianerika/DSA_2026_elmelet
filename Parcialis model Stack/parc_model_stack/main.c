#include "function.h"

int main(void) {
    /*Plate_t plate={105,1,2026,07,"feher"};
    /*readPlate(&plate);#1#
    printPlate(plate);*/
    PlateStack_t eloetel;
    PlateStack_t foetel;
    PlateStack_t leves;
    createStack(50,&eloetel);
    createStack(50,&foetel);
    createStack(50,&leves);
    if (!freopen("plates.txt","r",stdin)) {
        printf(FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    int x;
    scanf("%i",&x);
    for (int i=0;i<x;i++) {
        Plate_t kurens;
        readPlate(&kurens);
        switch (kurens.tipus) {
            case 0: {
                push(&eloetel,kurens);
                break;
            }
            case 1: {
                push(&foetel,kurens);
                break;
            }
            case 2: {
                push(&leves,kurens);
                break;
            }
            default: {
                printf("Hibas tanyer");
                break;
            }
        }
    }
    freopen("output.txt","w",stdout);
    printf("egyforma szinu tanyerok:%i", simulateServing(&eloetel,&foetel,&leves));
    freopen("CON","w",stdout);
    return 0;
}