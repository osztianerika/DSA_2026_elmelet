//
// Created by Erika on 5/7/2026.
//

#include "functions_hash.h"
//
// Created by Erika on 4/26/2026.
//


void createHashArray(HashTable *pHashTable) {
    pHashTable->items = (HashItem*)calloc(CAPACITY, sizeof(HashItem));
    if(!pHashTable->items)
    {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for (int i = 0; i < CAPACITY; ++i) {
        pHashTable->items[i] = dummyData;
    }
    pHashTable->size = 0;
}

void insert(HashTable *hashTable, HashItem hash_item) {
    if(hashTable->size >= CAPACITY) return;
    int osszeg=0;
    for(int i=0;i<strlen(hash_item.key);i++)
    {
        osszeg+=hash_item.key[i]; 
    }
    printf("\n%s - %i ",hash_item.key,osszeg);
    int index = osszeg%CAPACITY;
    
    int i = 0;
    while (strcmp(hashTable->items[(index + i)%CAPACITY].key,dummyData.key))
    {
        i++;
        if (i == CAPACITY)
        {
          return;
        }//Table full
    }
    hashTable->items[(index+i)%CAPACITY] = hash_item;
    hashTable->size++;
}

void display(HashTable hashTable) {
    if(hashTable.size == 0) {
        printf("The table is empty\n");
        return;
    }
    printf("The hash table:\n\tpos\t:\tkey\tvalue\t->\tmod\n");
    for (int i = 0; i < CAPACITY; ++i) {
        if(hashTable.items[i].key != dummyData.key)
        {
            printf("\t%i\t:\t%s\t%i\n", i, hashTable.items[i].key, hashTable.items[i].data);
        }
    }
}

int size(HashTable hashTable) {
    return hashTable.size;
}

void delete(HashTable *hashTable, int key) {
    int index = key%CAPACITY;
    if (hashTable->items[index].key == dummyData.key)
    {
        printf("\n This key does not exist \n");
        return;
    }
    int i = 0;
    while(hashTable->items[(index+i)%CAPACITY].key != key && i < CAPACITY)
    {
        i++;
    }
    if(i == CAPACITY)
    {
        printf("\n This key does not exist \n");
        return;
    }
    hashTable->items[(index+i)%CAPACITY] = dummyData;
    hashTable->size--;
    printf("\n Key (%d) has been removed \n", key);
}

int search(HashTable hashTable, char* key) {

    int index=0; 
    for(int i=0;i<strlen(key);i++)
    {
       index+=key[i]; 
    }
    index%=CAPACITY;
    printf("%i\n",index);
    if (strcmp(hashTable.items[index].key,dummyData.key)==0)
    {
        return -1;
    }
    int i = 0;
    printf("%s\n",hashTable.items[(index+i)%CAPACITY].key);
    while(strcmp(hashTable.items[(index+i)%CAPACITY].key,key)!= 0 && i < CAPACITY)
    {
        printf("%s\n",hashTable.items[(index+i)%CAPACITY].key);
        i++;
    }
    if(i == CAPACITY) return -1;
    return (index + i) % CAPACITY;
}

void destroyHashArray(HashTable *pHashTable) {
    free(pHashTable->items);
    pHashTable->items = NULL;
    pHashTable->size = 0;
}
