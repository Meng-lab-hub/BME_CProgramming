#include <stdio.h>

int main (void) {
    int fiftyCoin, hundredCoin, twoHundredCoin;
    printf ("\nCalculating your money from your coins\n\n");

    printf ("How many 50 Ft coins: ");
    scanf ("%d", &fiftyCoin);           // getting a number of 50 coins
    printf ("How many 100 Ft coins: ");
    scanf ("%d", &hundredCoin);         // getting a number of 100 coins
    printf ("How many 200 Ft coins: ");
    scanf ("%d", &twoHundredCoin);      // getting a number of 200 coins

    printf ("\nYou have totally %d Ft.\n", 50 * fiftyCoin + 100 * hundredCoin + 200 * twoHundredCoin);
    return 0;
}
