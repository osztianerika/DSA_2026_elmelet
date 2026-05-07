//
// Created by Erika on 5/7/2026.
//

#ifndef HASHTABLE__1_FUNCTIONS_HASH_H
#define HASHTABLE__1_FUNCTIONS_HASH_H
#define CAPACITY 31
#include <stdio.h>
#include <stdlib.h>
#include <constants.h>
typedef struct {
    int key;
    int data;
} HashItem;

typedef struct {
    HashItem *items;
    int size;
}HashTable;

static HashItem dummyData = {-1, 0};
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
 * @param hash_item
 */
void insert(HashTable *hashTable, HashItem hash_item);
/**
 * Deletes a data from the array
 * @param hashTable
 * @param has
 * @param data
 */
void delete(HashTable *hashTable, int key);
/**
 * Searches for a specific data with the given key
 * @param hashTable
 * @param key
 * @return the position if it is present, -1 otherwise
 */
int search(HashTable hashTable, int key);
/**
 * Prints the content of the array to the standard input
 * @param hashTable
 */
void display(HashTable hashTable);

/**
 * Returns the number of elements present in the hashtable
 * @param hashTable
 * @return size
 */
int size(HashTable hashTable);
/**
 * Deallocates memory
 * @param pHashTable
 */
void destroyHashArray(HashTable *pHashTable);
#endif //HASHTABLE__1_FUNCTIONS_HASH_H