//
// Created by Erika on 3/11/2026.
//

#include "functions_stack.h"
#include <constans.h>

void createStack(int capacity, Fuzet_Stack_t *stack)
{
    stack->capacity = capacity;
    stack->top = -1;
    stack->elements = (Fuzet_t*)calloc(capacity, sizeof(Fuzet_t));
    if (!stack->elements) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void destroyStack(Fuzet_Stack_t *stack) {
    free(stack->elements);
    stack->top = -1;
    stack->capacity = 0;
    stack = NULL;
}

bool isFull(Fuzet_Stack_t stack) {
    return stack.top == stack.capacity - 1;
}

bool isEmpty(Fuzet_Stack_t stack) {
    return stack.top == -1;
}

void push(Fuzet_Stack_t *stack, Fuzet_t item) {
    if (isFull(*stack)) {
        printf("FULL_MESSAGE");
        exit(-1);
    }
    stack->top++;
    stack->elements[stack->top] = item;
}

Fuzet_t pop(Fuzet_Stack_t *stack) {
    if (isEmpty(*stack)) {
        printf("Ne poppolj ures stackbol!");
        exit(-2);
    }
    Fuzet_t fuzet0={0,0,"",0,0,0 };
    Fuzet_t temp = stack->elements[stack->top];
    stack->elements[stack->top] = fuzet0;
    stack->top--;
    return temp;
}

Fuzet_t peek(Fuzet_Stack_t stack) {
    if (isEmpty(stack)) {
        printf("EMPTY_MESSAGE");
        exit(-2);
    }
    return stack.elements[stack.top];
}

int size(Fuzet_Stack_t stack) {
    return (stack.top + 1);
}

int evaluation(char op, int number1, int number2) {
    switch (op) {
        case '+': return number2+number1;
        case '-': return number2-number1;
        case '*': return number2*number1;
        case '/': return number2/number1;
        case '%': return number2%number1;
        default: return INT_MIN;
    }
}






