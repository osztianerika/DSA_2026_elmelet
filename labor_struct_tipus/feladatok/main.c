#include "functions_struct.h"

int main(void) {
    Fish_t fish1 = {0, "Edesvizu harcsa", 2.3, 1, 0, 0};
    printFish(fish1);
    // if (!freopen("fish.txt", "r",stdin)) {
    //     printf(FILE_OPENING_ERROR_MESSAGE);
    //     exit(FILE_OPENING_ERROR_CODE);
    // }
    Fish_t fish2;
    readFishDetails(&fish2);
    printFish(fish2);
    // freopen("CON", "r",stdin);
    // Fish_t fish3;
    // readFishDetails(&fish3);
    // printFish(fish3);#1#*/
    Fish_t *fishes;
    int n;
    readAllFishesDetails(&fishes, &n, "fish.txt");
    printAllFish(fishes, n, "CON");
    return 0;
}
