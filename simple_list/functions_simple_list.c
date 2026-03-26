//
// Created by Erika on 3/26/2026.
//

#include "functions_simple_list.h"

Node * newNode(int new_data) {

    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Allocation Error!");
        exit(-1);
    }
    newNode->data = new_data;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginning(Node **head_ref, int new_data) {
   Node *UjNode = newNode(new_data);
    if (isEmpty(*head_ref)) {
        *head_ref = UjNode;
    }
    else {
        UjNode->next = *head_ref;
        *head_ref = UjNode;
    }
}

bool isEmpty(Node *head) {
    return head == NULL;
}

void printList(Node *node) {
    Node *temp = node;
    while (temp != NULL) {
        printf("%i ",temp->data);
        temp = temp->next;
    }
}
