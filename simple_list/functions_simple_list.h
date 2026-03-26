//
// Created by Erika on 3/26/2026.
//

#ifndef SIMPLE_LIST_FUNCTIONS_SIMPLE_LIST_H
#define SIMPLE_LIST_FUNCTIONS_SIMPLE_LIST_H
#include <stdlib.h>
#include <constants.h>
#include <stdio.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;
Node* newNode(int new_data);
void insertAtBeginning(Node** head_ref, int new_data);
bool isEmpty(Node *head) ;
void insertAtEnd(Node **head_ref, int new_data);
void printList(Node *node);
#endif //SIMPLE_LIST_FUNCTIONS_SIMPLE_LIST_H