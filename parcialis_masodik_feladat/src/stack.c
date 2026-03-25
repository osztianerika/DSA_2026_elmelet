#include "stack.h"
#include <limits.h>

void createStack(int capacity, Stack *stack)
{
    stack->capacity = capacity;
    stack->top = -1;
    stack->elements = (int*)calloc(stack->capacity, sizeof(int));
    if(!stack->elements)
    {
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void destroyStack(Stack *stack)
{
    if(!stack)
    {
        printf("%s", NULL_POINTER_ERROR_MESSAGE);
        return;
    }
    stack->capacity = 0;
    stack->top = -1;
    free(stack->elements);
    stack = NULL;
}

bool isFullStack(Stack stack)
{
    return stack.top == stack.capacity - 1;
}

bool isEmptyStack(Stack stack)
{
    return stack.top == -1;
}

int size(Stack stack)
{
    return stack.top + 1;
}

void push(Stack *stack, int item)
{
    if(!stack)
    {
        printf("%s", NULL_POINTER_ERROR_MESSAGE);
        return;
    }
    if(isFullStack(*stack))
    {
        printf("%s", DATA_STRUCTURE_FULL_ERROR_MESSAGE);
        return;
    }
    stack->elements[++stack->top] = item;
}

int pop(Stack *stack)
{
    if(!stack)
    {
        printf("%s", NULL_POINTER_ERROR_MESSAGE);
        return INT_MIN;
    }
    if(isEmptyStack(*stack))
    {
        printf("%s", DATA_STRUCTURE_EMPTY_ERROR_MESSAGE);
        return INT_MIN;
    }
    int save = stack->elements[stack->top];
    stack->elements[stack->top] = 0;
    --stack->top;
    return save;
}

int peek(Stack stack)
{
    if(isEmptyStack(stack))
    {
        printf("%s", DATA_STRUCTURE_EMPTY_ERROR_MESSAGE);
        return INT_MIN;
    }
    return stack.elements[stack.top];
}