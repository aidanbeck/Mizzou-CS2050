#include "lab0.h"

/* REQUIRED CODE GOES HERE */

// Info: This function will take an integer representing the size of an array provided as its first parameter,
// an integer array with the given size as its second parameter, and a query integer as its third parameter.
// This function must count the number of times the query integer occurs in the array, and return that
// number.

/*
This function counts the number of times the query appears in the array.
size: size of the array
array: array of integers
query: specific integer to be counted
*/
int countOccurrences (int size , int array [] , int query ) {
    int count = 0;
    
    for (int i = 0; i < size; i += 1) {
        if (array[i] == query) {
            count++;
        }
    }
    
    return count;
}

//gcc -Wall -Werror -Wpedantic main.c lab0.c
