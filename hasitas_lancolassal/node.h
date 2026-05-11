//
// Created by Erika on 5/10/2026.
//

#ifndef HASITAS_LANCOLASSAL_NODE_H
#define HASITAS_LANCOLASSAL_NODE_H
#include <stdbool.h>
#include <stdlib.h>
#include <constants.h>
#include <stdio.h>
typedef struct {
    int key;
    int value;
} HashItem;

typedef struct Node {
    HashItem data;
    struct Node *next;
} Node;

/**
 * Allocates memory for a new node
 * @param new_data
 * @return pointer to a new allocated node
 */
Node* newNode(HashItem new_data);

/**
 * Checks if list is empty, head is NULL pointer
 * @param head
 * @return true/false
 */
bool isEmpty(Node *head);

/**
 * Insert new node at start of the list
 * @param head_ref
 * @param new_data
 */
void insertFirst(Node **head_ref, HashItem new_data);


/**
 * Delete a specific node
 * @param head_ref
 * @param key
 */
bool deleteNode(Node** head_ref, int key);

/**
 * Searches for a specific node with value key
 * @param head_ref
 * @param key
 * @return
 */
bool searchNode(Node* head_ref, int key);

/**
 * Print all elements of teh list
 * @param node
 */
void printList(Node* node);

/**
 * Prints the data of the node
 * @param item
 */
void printItem(HashItem item);

/**
 * Deallocates memory
 * @param head
 */
void freeList(Node **head);
#endif //HASITAS_LANCOLASSAL_NODE_H