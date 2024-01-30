#include <stdio.h>
#include <stdlib.h>

int myFunction(int array[], int size, int query) {
    int count = 0;
    
    for (int i = 0; i < size; i += 1) {
        if (array[i] >= query) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int array[] = {90, 1, 3, 3, 4};
    int size = 5;
    int query = 3;
    
    int answer = myFunction(array, size, query);
    
    printf("Answer: %d\n", answer);
    
    return 0;
}