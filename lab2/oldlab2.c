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
    It sets the result array to point to the index of the "beginning" element, so that can be treated as zero for itself.
    It returns the end index minus the begin index plus 1, which totals to the length of the new array slice.

*/
int sliceArray (int *array , int size , int begin , int end , int **result) {

    int beginIndex = indexOf(array, size, begin);
    int endIndex = indexOf(array, size, end);

    *result = array + beginIndex;
    return endIndex - beginIndex + 1;

}

int main() {

    // int *array = makeArray(12);
    // array[0] = 137;
    // array[9] = 420;

    // int *result;

    // int size = sliceArray(array, 12, 137, 420, &result);

    // printf("%d, %d\n", 12, size);

    // for (int i = 0; i < 12; i++) {
    //     printf("%d ", array[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < size; i++) {
    //     printf("%d ", result[i]);
    // }
    // printf("\n");

    return 0;
}