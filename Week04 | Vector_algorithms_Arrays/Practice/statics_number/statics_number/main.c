#include <stdio.h>

int main (void) {
    int value, ct[10];
    for (int i = 0; i < 10; i+=1)
        ct[i] = 0;
    while (scanf ("%d", &value) == 1)
        if (value >= 1 && value <= 10)
            ct[value - 1] += 1;
    for (int i = 0; i < 10; i+=1)
        printf ("%d: %d pcs\n", i + 1, ct[i]);
    return 0;
}
