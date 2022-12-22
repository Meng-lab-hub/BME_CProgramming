#include <stdio.h>

int main (void) {
    int i = 4, x = 0;
    printf ("\n");
    while (x < i) {
        for (int j = 0; j < x; j++) {
            printf (" ");
        }
        printf ("\\\n");
        x++;
    }
    return 0;
}
