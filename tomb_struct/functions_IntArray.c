//
// Created by Erika on 3/4/2026.
//

#include "functions_IntArray.h"


void createIntArray(int capacity, IntArray* pArray) {
    //nem kell helyet foglalni a strukturanak
    //pArray = (IntArray*) malloc(sizeof(IntArray));
    pArray->capacity = capacity;
    pArray->size = 0;
    pArray->elements = (int*) calloc(capacity, sizeof(int));
    if (!pArray->elements) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }

}

void printArray(IntArray array) {
    for (int i = 0; i < array.size; ++i) {
        printf("%d ", array.elements[i]);
    }
}

bool isFull(IntArray array) {
    return array.size == array.capacity;
}

bool isEmpty(IntArray array) {
    return array.size == 0;
}

int getItemAt(IntArray array, int position) {
    if (isEmpty(array)) {
        printf("Ures a tomb :(");
        return INT_MIN;
    }
    if (position < 0 || position > array.capacity) return INT_MIN;
    return array.elements[position];
}

void insertLast(IntArray *pArray, int item) {
    if (isFull(*pArray)) {
        printf("A tomb tele van ");
        return;
    }
    pArray->elements[pArray->size] = item;
    pArray->size++;
}
