#include <stdio.h>

int main (void) {
    int product = 1, n = 10;
    printf ("\nProduct = ");
    while (n >= 2) {
        product = product * n;
        printf ("%d", n);
        if (n != 2) {
            printf (" x ");
        }
        n--;
    }
    printf (" x 1");
    printf ("\nThe product is: %d\n\n", product);
    return 0;
}
