#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "functions_stack.h"

int main(void) {
    Fuzet_t fuzet1={100, 0, "Kek es zold",2026,03,24};
    printFuzet(fuzet1);
    Fuzet_t fuzet2;
    //readFuzet(&fuzet2);
    //printFuzet(fuzet2);
    if (!freopen("input.txt","r",stdin)) {
        printf("Error opening file");
        exit(1);
    }
    int n;
    scanf("%d\n",&n);
    Fuzet_Stack_t fuzetStack;
    createStack(100,&fuzetStack);
    int tomeg=0;
    while (fuzetStack.top<50 && n>0) {
        Fuzet_t fuzet3;
        readFuzet(&fuzet3);
        if (fuzet3.tipus==1) {
            push(&fuzetStack,fuzet3);
            tomeg+=5*fuzet3.lapszam;
        }
        n--;
    }
    printf("%d",tomeg);


    return 0;
}
