#include <stdio.h>

int main (void) {
    int n = 1;
    long int denominator = 1;
    double sum = 1;          // I include 1/0! here already
    while (n < 20) {
        denominator = denominator * n;
        sum = sum + 1.0 / denominator;
        n++;
    }
    printf ("e = %lf\n", sum);
    return 0;
}
