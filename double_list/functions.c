//
// Created by Erika on 4/23/2026.
//

#include "functions.h"

/**
 * Memóriát foglal egy új csomóponthoz.
 */
Node *newNode(int new_data) {
    Node *newItem = (Node*) malloc(sizeof(Node));
    if (!newItem) {
        printf("MEMORY_ALLOCATION_ERROR_MESSAGE");
        exit(-3);
    }
    newItem->data = new_data;
    newItem->prev = NULL;
    newItem->next = NULL;
    return newItem;
}

/**
 * Ellenőrzi, hogy a lista üres-e.
 */
bool isEmpty(Node *head) {
    return head == NULL;
}

/**
 * Beszúrás a lista elejére.
 */
void insertAtBeginning(Node **head_ref, int new_data) {
    Node *temp = newNode(new_data);

    if (isEmpty(*head_ref)) {
        *head_ref = temp;
        return;
    }

    temp->next = *head_ref;
    (*head_ref)->prev = temp;
    *head_ref = temp;
}

/**
 * Beszúrás a lista végére.
 */
void insertAtEnd(Node **head_ref, int new_data) {
    Node *temp = newNode(new_data);

    if (isEmpty(*head_ref)) {
        *head_ref = temp;
        return;
    }

    Node *last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = temp;
    temp->prev = last;
}

/**
 * Törlés a lista elejéről.
 */
void deleteFromBeginning(Node **head_ref) {
    if (isEmpty(*head_ref)) {
        printf("NULL_POINTER_EXCEPTION_ERROR_MESSAGE");
        return;
    }

    Node *temp = *head_ref;
    *head_ref = (*head_ref)->next;

    if (*head_ref != NULL) {
        (*head_ref)->prev = NULL;
    }

    free(temp);
}


/**
 * Törlés a lista végéről.
 */
void deleteFromEnd(Node **head_ref) {
    if (isEmpty(*head_ref)) {
        printf("NULL_POINTER_EXCEPTION_ERROR_MESSAGE");
        return;
    }

    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }

    Node *temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}


/**
 * Lista kiírása előre.
 */
void printListForward(Node *node) {
    Node *temp = node;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/**
 * Felszabadítja a memóriát.
 */
void freeList(Node **head) {
    Node *temp = *head;

    while (temp != NULL) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }

    *head = NULL;
}

void printListBackward(Node *head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }

    Node *temp = head;

    /* elmegyünk a lista végére */
    while (temp->next != NULL) {
        temp = temp->next;
    }

    /* visszafelé bejárás */
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}