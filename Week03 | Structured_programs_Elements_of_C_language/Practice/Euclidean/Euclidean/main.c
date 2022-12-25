#include <stdio.h>

int main (void) {
    int num1, num2;
    
    printf ("Enter 2 numbers: ");
    scanf ("%d %d", &num1, &num2);
    
    while (num1 != num2)
        if (num1 < num2) num2 = num2 - num1;
        else num1 = num1 - num2;
    
    printf ("GCD of these 2 numbers is: %d\n", num1);
    return 0;
}
