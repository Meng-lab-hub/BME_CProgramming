#include <stdio.h>

int main (void) {
    int num, sum = 0;
    
    printf ("Give the desire number: ");
    scanf ("%d", &num);
    while (num != 0) {
        sum = sum + num % 10;
        num = num / 10;
    }
    printf ("Result = %d\n", sum);
    return 0;
}
