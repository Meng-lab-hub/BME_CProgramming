#include <stdio.h>

int main (void) {
    int n;
    double approx = 1;
    printf ("How many terms calculate the approximation of PI: ");
    scanf ("%d", &n);
    
    for (int i = 1; i <= n; i++) 
        approx = approx * (4.0 * i * i) / (4.0 * i * i - 1.0);
    printf ("The approximate value of PI is: %f\n", 2 * approx);
    return 0;
}
