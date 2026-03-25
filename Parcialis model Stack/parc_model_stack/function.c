//
// Created by rober on 2026. 03. 25..
//

#include "function.h"

#include <string.h>

void createStack(int capacity, PlateStack_t *stack)
{
    stack->capacity = capacity;
    stack->top = -1;
    stack->elements = (Plate_t*)calloc(capacity, sizeof(Plate_t));
    if (!stack->elements) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void destroyStack(PlateStack_t *stack) {
    free(stack->elements);
    stack->top = -1;
    stack->capacity = 0;
    stack = NULL;
}

bool isFull(PlateStack_t stack) {
    return stack.top == stack.capacity - 1;
}

bool isEmpty(PlateStack_t stack) {
    return stack.top == -1;
}

void push(PlateStack_t *stack, Plate_t item) {
    if (isFull(*stack)) {
        printf("Hiba! Tele van a stack!");
        exit(-1);
    }
    stack->top++;
    stack->elements[stack->top] = item;
}

Plate_t pop(PlateStack_t *stack) {
    if (isEmpty(*stack)) {
        printf("Ne poppolj ures stackbol!");
        exit(-2);
    }
    Plate_t temp = stack->elements[stack->top];
    Plate_t plate0={0,0,0,0,"semmi"};
    stack->elements[stack->top] = plate0;
    stack->top--;
    return temp;
}

Plate_t peek(PlateStack_t stack) {
    if (isEmpty(stack)) {
        printf("Ne peekelj ures stackbe!");
        exit(-2);
    }
    return stack.elements[stack.top];
}

int size(PlateStack_t stack) {
    return (stack.top + 1);
}

void readPlate(Plate_t *p) {
    scanf("%d%d%d%d\n", &p->id,&p->tipus,&p->vasarlasi_ido.year,&p->vasarlasi_ido.month);
    scanf("%[^\n]", p->szin);
}

void printPlate(Plate_t p) {
    printf("%d %s %d %d %s", p.id,getDescriptionPlate(p.tipus),p.vasarlasi_ido.year,p.vasarlasi_ido.month, p.szin);
}

char * getDescriptionPlate(enum Type_t type) {
    switch (type) {
        case 0: {
            return "eloetel";
        }
        case 1: {
            return "foetel";
        }
        case 2:{return "leves";}
        default:{return "other type";}
    }
}

int simulateServing(PlateStack_t *foetelStack, PlateStack_t *levesStack, PlateStack_t *eloetelStack) {
    int db=0;
    while (!isEmpty(*foetelStack) && !isEmpty(*levesStack) && !isEmpty(*levesStack)) {
        if (strcmp(eloetelStack->elements[eloetelStack->top].szin,foetelStack->elements[foetelStack->top].szin)==0) {
            if (strcmp(eloetelStack->elements[eloetelStack->top].szin,levesStack->elements[levesStack->top].szin)==0) {
                db++;
            }
        }
        printf("eloetel:%s foetel:%s leves:%s \n",pop(eloetelStack).szin,pop(foetelStack).szin,pop(levesStack).szin);
    }
    return db;
}
