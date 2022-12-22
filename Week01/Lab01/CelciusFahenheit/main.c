#include <stdio.h>

float convertToCel (float);         // function prototype
float convertToFahr (float);        // function prototype

int main (void) {
    printf ("\nCelcius - Fahrenheit Converter\n\n");

    float temperature;
    char typeOfTemper;

    printf ("Input the temperature and its type\n");
    printf ("C for celcius and F for fahrenheit, (separate by space or enter)\n");
    printf ("For example: 100 F\n");

    printf ("Input: ");
    scanf ("%f %c", &temperature, &typeOfTemper);   // get the input in "100 F" format

    if (typeOfTemper == 'F') {  // case user input temperature in fahrenheit
        printf ("\n%.1f fahrenheit is %.1f celcius.\n", temperature, convertToCel (temperature));
    } else if (typeOfTemper == 'C') {   // case user input temperature in celcius
        printf ("\n%.1f celcius is %.1f fahrenheit.\n", temperature, convertToFahr (temperature));
    } else { // bad case
        printf ("\nImproper input!\n");
    }

    return 0;
}

float convertToCel (float F) {
    float C;
    C = (5.0/9.0) * (F - 32.0); // formula to calculate celcius from fahrenheit
    return C;
}

float convertToFahr (float C) {
    float F;
    F = ((9.0/5.0) * C) + 32.0; // formula to calculate fahrenheit from celcius
    return F;
}
