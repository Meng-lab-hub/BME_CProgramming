#include <stdio.h>

int main (void) {
    printf ("\nCheck prime number\n\n");

    int num, incorrect = 0;
    printf ("Input the number: ");
    scanf ("%d", &num);
    for (int i = 2; i < num; i++) {
        if (num % 2 == 0) {
            incorrect = 1;
            break;
        }
    }
    if (incorrect == 0) printf ("%d is a prime number\n", num);
    else printf ("%d isn't a prime number\n", num);
    return 0;
}
