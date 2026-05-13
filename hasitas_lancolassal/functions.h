//
// Created by Erika on 5/10/2026.
//

#ifndef HASITAS_LANCOLASSAL_FUNCTIONS_H
#define HASITAS_LANCOLASSAL_FUNCTIONS_H
#include "node.h"

#define CAPACITY 13

typedef struct {
    Node *items;
}HashTable;

/**
 * Allocates memory for a hash table with defined SIZE
 * @param pHashTable
 */
void createHashArray(HashTable *pHashTable);
//This should be only accessible in the .c file
//int hashCode(int key);
/**
 * Inserts a new data to the hashArray
 * @param hashTable
 * @param key
 * @param data
 */
void insert(HashTable *hashTable, int key, int data);
/**
 * Deletes a data from the array
 * @param hashTable
 * @param key
 * @param data
 */
void delete(HashTable *hashTable, int key);
/**
 * Searches for a specific data with the given key
 * @param hashTable
 * @param key
 * @return the position if it is present, -1 otherwise
 */
bool search(HashTable hashTable, int key);
/**
 * Prints the content of the array to the standard input
 * @param hashTable
 */
void display(HashTable hashTable);

/**
 * Deallocates memory
 * @param pHashTable
 */
void destroyHashArray(HashTable *pHashTable);

#endif //HASITAS_LANCOLASSAL_FUNCTIONS_H