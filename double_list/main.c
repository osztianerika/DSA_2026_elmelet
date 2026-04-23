#include "functions.h"

int main(void) {
    int number;

    printf("Adj meg egy szamot: ");
    scanf("%d", &number);

    Node *head = NULL;

    while (number > 0) {
        int digit = number % 10;
        insertAtBeginning(&head, digit);
        number /= 10;
    }

    printf("\nElore:\n");
    printListForward(head);

    printf("\nVisszafele:\n");
    printListBackward(head);

    freeList(&head);
    return 0;
}