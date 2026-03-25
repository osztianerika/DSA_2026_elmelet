#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <customs/constants.h>
#include "stack.h"

int paros(char nyito, char zaro)
{
    return (nyito == '(' && zaro == ')') ||
           (nyito == '[' && zaro == ']') ||
           (nyito == '{' && zaro == '}');
}

int main(void)
{
    char kifejezes[] = "{[2 * (3 + 4)] / 5} + (10 - [2 * 3])";
    const char *NYITO_ZAROJEL = "({[";
    const char *CSUKO_ZAROJEL = ")}]";
    Stack stack;
    createStack(strlen(kifejezes), &stack);
    int helyes = 1;
    for(int i = 0; i < strlen(kifejezes); ++i)
    {
        char c = kifejezes[i];
        if(strchr(NYITO_ZAROJEL, c) != NULL)
        {
            push(&stack, (int)c);
        }
        else if (strchr(CSUKO_ZAROJEL, c) != NULL)
        {
            if (isEmptyStack(stack))
            {
                helyes = 0;
                break;
            }

            char felso = (char)pop(&stack);

            if (!paros(felso, c))
            {
                helyes = 0;
                break;
            }
        }
    }
    if (!isEmptyStack(stack)) helyes = 0;
    if(helyes == 1) printf("Helyes zarojelezes\n");
    else if (helyes == 0) printf("Helytelen zarojelezes\n");
    return 0;
}