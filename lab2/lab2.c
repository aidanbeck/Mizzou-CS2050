#include "lab2.h"

/*
    This function takes an int size and allocates a chunk of memory that can hold an integer per the value of size.
    It then loops through each element in the array and sets it to 0
    Finally, if array doesn't equal NULL, it returns a pointer to the array.
    If it does equal NULL, it returns NULL.
*/
int * makeArray(int size) {

    int *array = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }

    if (array == NULL) {
        return NULL;
    } else {
        return array;
    }

}

/*
    This function takes an array, it's size, and a query element.
    It loops through all elements to see if any of them match the query element.
    If it does, it sets "match" to i, or the index of the element where the match was found.
    It then returns match.
    match is set to -1 by default. If no matches are found, it will return match as -1.
*/
int indexOf(int *array , int size , int element ) {

    int match = -1;

    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            match = i;
        }
    }

    return match;
}


/*
    This function takes an array, it's size, and two query elements, as well as a pointer to an array.
    It uses the indexOf function to identify the index of both query elements, defining them as the beginning and end.
    It then checks if either beginIndex or endIndex equals -1, indicating that it is not found in the function.
    If either equals -1, the function returns -1 indicating the array could not be sliced.
    If not:
    It sets the result array to point to the index of the "beginning" element, so that can be treated as zero for itself.
    It returns the end index minus the begin index plus 1, which totals to the length of the new array slice.

*/
int sliceArray (int *array , int size , int begin , int end , int **result) {

    int beginIndex = indexOf(array, size, begin);
    int endIndex = indexOf(array, size, end);

    if (beginIndex == -1 || endIndex == -1) {
        return -1;
    } else {
        *result = array + beginIndex;
        return endIndex - beginIndex + 1;
    }

}

/*
    This function takes a pointer to an array.
    It frees the memory allocated to the array, and then sets the pointer to the array to NULL.
    This is to avoid the pointer accidentally being used and directing to irrelevant memory.
*/
void freeArray ( int ** array ) {
    free(*array);
    *array = NULL;
}