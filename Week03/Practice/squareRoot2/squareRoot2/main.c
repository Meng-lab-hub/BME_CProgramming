#include <stdio.h>

int main (void) {
    double guess = 1.0, increment = 0.1;
    
    for (int i = 1; i <= 15; i++) {
        while (guess * guess < 2.0) guess = guess + increment;
        guess = guess - increment;
        increment = increment / 10;
    }
    printf ("Square root of 2 up to 10 degits: %.15lf\n", guess);
    return 0;
}
