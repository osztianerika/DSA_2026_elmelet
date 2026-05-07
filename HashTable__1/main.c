#include <stdio.h>
#include <time.h>

#include "functions_hash.h"

int main(void) {

    HashTable table;
    createHashArray(&table);
    display(table);
    srand(time(0));
    int key = 1;
    while(size(table) < CAPACITY)
    {
        key += rand() % CAPACITY + 1;
        HashItem hash_item={key,rand()%100};
        insert(&table, hash_item);
        printf("\n\n");
        display(table);
    }
    display(table);
    return 0;
}