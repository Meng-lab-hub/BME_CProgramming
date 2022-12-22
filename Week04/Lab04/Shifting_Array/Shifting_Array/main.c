#include <stdio.h>

int main (void) {
    int array[10] = {25, 69, 54, 8, 77, 6, 29, 10, 3, 98}, temp = 0;
    // {69, 54, 8, 77, 6, 29, 10, 3, 98, 25}
    // {54, 8, 77, 6, 29, 10, 3, 98, 25, 69}
    for (int i = 0; i < 10; i++) {
        temp = array[0];
        for (int j = 0; j < 10; j++) {
            printf ("%d ", array[j]);
            array[j] = array[j+1];
        }
        array[9] = temp;
        printf ("\n");
    }
    return 0;
}
