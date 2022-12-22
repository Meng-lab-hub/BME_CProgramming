#include <stdio.h>

int main (void) {
    int height;
    printf ("\nHeight of the triangle: ");
    scanf ("%d", &height);
    
    for (int i = 1; i <= height; i++) {
//        loop to print a space
        for (int j = 0; j < height - i; j++)
            printf (" ");
        
//        loop to print o
        for (int o = 0; o < 2 * i - 1; o++)
            printf ("o");

        printf ("\n");
    }
    return 0;
}
