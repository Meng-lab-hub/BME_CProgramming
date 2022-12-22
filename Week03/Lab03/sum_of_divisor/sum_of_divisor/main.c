#include <stdio.h>

int main (void) {
    int sumDivisor = 1, divisor = 2, num;
    printf ("Please give a desire number: ");
    scanf ("%d", &num);
    printf ("1 ");
    while (divisor < num) {
        if ((num % divisor) == 0) {
            sumDivisor = sumDivisor + divisor;
            printf ("+ %d ", divisor);
        }
        divisor++;
    }
    printf ("= %d\n", sumDivisor);
    if (sumDivisor == num) printf ("The entered number is perfect number\n");
    return 0;
}
