#include <stdio.h>

int main (void) {
    int min, i = 0, array[10] = {25, 69, 54, 8, 77, 6, 29, 10, 3, 98};

    printf ("The array: [%d]=%d", i, array[0]);
    for (i = 1; i < 10; i++)
        printf (" [%d]=%d", i, array[i]);
    printf ("\n\n");
    
    min = array[0];
    for (i = 1; i < 10; i++)
        if (min > array[i])
            min = array[i];
    
    printf ("The least: %d\n", min);
    printf ("Marked:");
    for (i = 0; i < 10; i++)
        if (array[i] == min)
            printf (" %d[MIN]", array[i]);
        else
            printf (" %d", array[i]);
    printf ("\n\n");
    return 0;
}
