//
// Created by Erika on 3/11/2026.
//

#include "functions_stack.h"

#include "constants.h"

void createStack(int capacity, Stack_t *stack)
{
    stack->capacity = capacity;
    stack->top = -1;
    stack->elements = (int*)calloc(capacity, sizeof(int));
    if (!stack->elements) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void destroyStack(Stack_t *stack) {
    free(stack->elements);
    stack->top = -1;
    stack->capacity = 0;
    stack = NULL;
}

bool isFull(Stack_t stack) {
    return stack.top == stack.capacity - 1;
}

bool isEmpty(Stack_t stack) {
    return stack.top == -1;
}

void push(Stack_t *stack, int item) {
    if (isFull(*stack)) {
        printf(FULL_MESSAGE);
        exit(-1);
    }
    stack->top++;
    stack->elements[stack->top] = item;
}

int pop(Stack_t *stack) {
    if (isEmpty(*stack)) {
        printf("Ne poppolj ures stackbol!");
        exit(-2);
    }
    int temp = stack->elements[stack->top];
    stack->elements[stack->top] = 0;
    stack->top--;
    return temp;
}

int peek(Stack_t stack) {
    if (isEmpty(stack)) {
        printf(EMPTY_MESSAGE);
        exit(-2);
    }
    return stack.elements[stack.top];
}

int size(Stack_t stack) {
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






