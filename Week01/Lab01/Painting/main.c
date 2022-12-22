#include <stdio.h>

#define PI 3.14159265

int main (void) {
    float height, diameter, totalArea;

    printf ("Paint the container\n\n");

    printf ("Height? ");
    scanf ("%f", &height);      // get the height from the user
    printf ("Diameter? ");
    scanf ("%f", &diameter);    // get the diameter from the user

    totalArea = 2 * ((diameter / 2) * (diameter / 2) * PI) + (diameter * PI * height);        // implementing the formula to find the total surface area

    printf ("\n%.1f can(s) of paint needed.\n", totalArea / 2.0);   // for every 2 square meter we use 1 can so for totalArea we use (totalArea / 2) can
    return 0;
}
