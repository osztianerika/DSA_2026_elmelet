#include <stdio.h>
#include "function.h"

int main(void) {
    Node *fej = NULL;

    for (int i = 0; i < 10; ++i) {
        int newData;
        scanf("%d", &newData);

        if (isEmpty(fej) || newData <= fej->data) {
            insertAtBeginning(&fej, newData);
        } else {
            Node *tmp = fej;

            while (tmp->next != NULL && tmp->next->data < newData) {
                tmp = tmp->next;
            }

            if (tmp->next == NULL) {
                insertAtEnd(&fej, newData);
            } else {
                insertAfter(tmp, newData);
            }
        }
    }

    printList(fej);
    freeList(&fej);

    return 0;
}