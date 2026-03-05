#include "functions_IntArray.h"

int main(void) {
IntArray array;
	createIntArray(3, &array);
	insertLast(&array,1);
	insertLast(&array,2);
	printArray(array);


    return 0;
}