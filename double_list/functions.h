//
// Created by Erika on 4/23/2026.
//

#ifndef DUBLE_LIST_FUNCTIONS_H
#define DUBLE_LIST_FUNCTIONS_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * Egy csomópontot reprezentáló struktúra duplán láncolt listában.
 */
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

/* Függvénydeklarációk */

Node *newNode(int new_data);

bool isEmpty(Node *head);

void insertAtBeginning(Node **head_ref, int new_data);

void insertAtEnd(Node **head_ref, int new_data);

void deleteFromBeginning(Node **head_ref);

void deleteFromEnd(Node **head_ref);

void printListForward(Node *node);

void printListBackward(Node *node);

void freeList(Node **head);
#endif //DUBLE_LIST_FUNCTIONS_H