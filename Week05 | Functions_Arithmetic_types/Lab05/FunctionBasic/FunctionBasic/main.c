#include <stdio.h>
#include <math.h>   // just for sin function

double cube (double);
double absolute (double);

int main (void) {
    double a;
    for (a = -1.0000; a <= 1.0000; a += 0.1)
        printf ("%9.4lf %9.4lf %9.4lf %9.4lf\n", a, cube(a), absolute(a), sin(a));
    return 0;
}

double cube (double x) {
    return x * x * x;
}

double absolute (double x) {
    if (x < 0) return -x;
    return x;
}
