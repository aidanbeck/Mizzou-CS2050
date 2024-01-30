#include "lab1.h"

/*
    This function takes pointers to two integers, a and b.
    It creates a temporary "holder" integer set to the value pointed to by a.
    Then, it sets the value pointed to by a to the value pointed to by b.
    Finally, it sets the value pointed to by b to the holder integer.

*/
void swap(int *a, int *b) {
    int holder;
    holder = *a;
    *a = *b;
    *b = holder;

}

/*
    This function takes an array and the size of said array.
    It first initializes a "max" int to the first element in the array, and a "maxIndex" int to 0, the index of the first element.
    It does this same thing for "min" and "minIndex";

    Then, it loops through each element in the array.
    For each element, it checks if it's value is greater than the max. If so, it changes max to it's value, and maxIndex to it's index.
    It does the same for min and minIndex, but if it is less than min.

    Finally, it checks if min and max are different. if so, it swaps them with the swap function, and returns 0;
    If they are the same, it returns 1, indicating that the swap could not be completed.
*/
int swapMaxMin(int array[], int size) {

    int max = array[0];
    int maxIndex = 0;

    int min = array[0];
    int minIndex = 0;

    for (int i = 0; i < size; i++) {

        if (max < array[i]) {
            max = array[i];
            maxIndex = i;
        }

        if (min > array[i]) {
            min = array[i];
            minIndex = i;
        }
    }

    if (max != min) {
        swap(&array[minIndex], &array[maxIndex]);
        
        for (int i = 0; i < size; i++) {
            printf("%d, ",array[i]);
        }

        return 0;
    } else {
        printf("1");
        return 1;
    }

}

/*
    This functions takes a string, index, and char pointer.
    It creates an int callled "length" set to 0, and loops through each character of the string until it hits a null terminator.
    Each interation it increases length by 1. then it detects if the index is less than 0, or equal to / greater than the length.
    If it is either of those things, it returns 1 indicating that it could not get the char.
    If it is neither, it sets the value of the address being pointed to by result to the character that is in the index of the string.
    And it returns 0, signifying that it worked properly.
*/
int charAt(char str[], int index, char *result) {

    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    if (index < 0 || index >= length) {
        return 1;
    } else {
        *result = str[index];
        return 0;
    }

}