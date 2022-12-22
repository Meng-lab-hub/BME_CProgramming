
#include <stdio.h>

int main (void) {
    
    for (int i = 1; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            printf ("%d%d\n", i, j);
    
    /*
    int i, j;   // i = 1, j = 0
    i = 1;
    while ( i <= 9) {
        j = 0;
        while (j <= 9) {
            printf ("%d%d%d\n", i, j, i);
            j = j + 1;  // j++;
        }
        i = i + 1;  // i++;
    }   */
    return 0;
}
