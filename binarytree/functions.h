//
// Created by Erika on 4/26/2026.
//
#include <stdlib.h>
#include <stdio.h>
#include <constants.h>
#ifndef BINARYTREE_FUNCTIONS_H
#define BINARYTREE_FUNCTIONS_H
typedef struct Node{
    int info;
    struct Node *left, *right;
}Node;

/**
 * Allocate memory for a new node
 * @param newData
 * @return the allocated node item
 */
Node *createNewNode(int newData);
/**
 * Insert a new node to the left of the root
 * @param root
 * @param newData
 * @return pointer to the inserted node
 */
Node *insertLeft(Node *root, int newData);
/**
 * Insert a new node to the right of the root
 * @param root
 * @param newData
 * @return pointer to the inserted node
 */
Node *insertRight(Node *root, int newData);
/**
 * ROOT-LEFT-RIGHT order of traversal
 * @param root
 */

void preorderTraversal(Node *root);
/**
 * LEFT-ROOT-RIGHT order of traversal
 * @param root
 */

void inorderTraversal(Node *root);
/**
 * LEFT-RIGHT-ROOT order of traversal
 * @param root
 */

void postorderTraversal(Node *root);

/**
 * Deallocate memory
 * @param root
 */
void destroyBinaryTree(Node **root);
#endif //BINARYTREE_FUNCTIONS_H