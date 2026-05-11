#include <stdio.h>
#include <time.h>

#include "functions_hash.h"

int main(void) {

    HashTable table;
    createHashArray(&table);
    if(!freopen("adatok.txt","r",stdin))
        return -1;
    int n;
    scanf("%i\n",&n);
    for(int i=0;i<n;i++) { 
      HashItem hi;
      scanf("%i\n",&hi.data);
      scanf("%s",&hi.key);
      insert(&table,hi); 
    }
    display(table);
    int pos = search(table,"Elod");
    printf("\n%i - %i",pos,table.items[pos].data);
    return 0;
}

