#include <stdio.h>

int main (void) {
    printf ("\nMonotonously Increasing sequence\n\n");

    printf ("Input the sequence (-789) to stop:\n");
    int num = 0, prevNum, firstInput = 1, mono = 1;
    while (num != 9999) {
        if (firstInput == 1) {
            scanf ("%d", &prevNum);
            firstInput = 0;
        }
        scanf ("%d", &num);
        if (num < prevNum) mono = 0;
        prevNum = num;
    }
    if (mono == 0) printf ("\nThe given sequence is not monotonous increasing sequence!\n");
    else printf ("\nThe given sequence is monotonous increasing sequence!\n");
    return 0;
}
