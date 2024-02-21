#include <stdio.h>
#include <stdlib.h>

/*
    Reads file of floats & adds each to an array.
    Sets length pointer to the array size & returns the array.
*/
float * readFloatFileIntoArray(FILE *fptr, int *length) {

    int size;
    fscanf(fptr, "%d", &size);

    float *array = malloc(sizeof(float) * size);
    if (!array) { return NULL; }
    
    for (int i = 0; i < size; i++) {
        fscanf(fptr, "%f", &array[i]);
    }

    *length = size;
    return array;
}

/*
    Frees float array.
*/
void freeFloatArray(float *array) {
    free(array);
}

/*
    Main function for testing/showcasing.
*/
int main() {

    FILE* floats = fopen("floats.txt", "r");
    int length;
    float *array = readFloatFileIntoArray(floats, &length);

    for (int i = 0; i < length; i++) {
        printf("%f\n", array[i]);
    }
    

    freeFloatArray(array);
    
    return 0;
}