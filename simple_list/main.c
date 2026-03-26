#include "functions_simple_list.h"

int main(void) {
    Node *head = NULL;
    int x = 123;
    while (x != 0) {
        insertAtBeginning(&head,x%10);
        x/=10;
    }
    printList(head);
    return 0;
}