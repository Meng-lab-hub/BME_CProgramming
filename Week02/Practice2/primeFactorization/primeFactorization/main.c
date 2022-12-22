#include <stdio.h>

int main (void) {
    int number, divisor = 2;   // first let's divisor be 2 and we will increment it later
    printf ("\nEnter a number to factorize: ");
    scanf ("%d", &number);
    
    while (number > 1) {
        if (number % divisor == 0) {
            printf ("%4d | %d\n", number, divisor);
            number = number / divisor;
        } else
            divisor++;
    }
    printf ("   1 |\n");
    return 0;
}
