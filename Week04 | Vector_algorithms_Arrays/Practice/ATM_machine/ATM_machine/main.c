#include <stdio.h>

int main (void) {
    int note[13] = {20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 0};
    int amount = 76582, i = 0;
    
    for (i = 0; i < 13; i += 1) {
        if (note[i] == 0 && amount == 0)
            break;
        int pcs = amount / note[i];
        if (pcs != 0) {
            printf ("%d pcs of %d\n", pcs, note[i]);
            amount -= pcs * note[i];
        }
    }
    return 0;
}
// what is a problem here
