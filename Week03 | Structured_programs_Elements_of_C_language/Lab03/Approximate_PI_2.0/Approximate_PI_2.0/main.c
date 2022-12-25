#include <stdio.h>

int main (void) {
    double negativeSum = 0, positiveSum = 0;
    
    for (int i = 0; i < 10000000; i++) {
        positiveSum = positiveSum + (1.0 / (4.0 * i + 1.0));
        negativeSum = negativeSum + (1.0 / (4.0 * i + 3.0));
    }
    printf ("The approximate value of Pi is: %lf\n", 4 * (positiveSum - negativeSum));
    return 0;
}
