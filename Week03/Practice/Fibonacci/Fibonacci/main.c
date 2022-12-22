#include <stdio.h>

int main (void) {
    int num, f = 1, prev = 0, beforePrev = 0;
    
    printf ("Which element to compute: ");
    scanf ("%d", &num);
    
    if (num == 0) f = 0;
    
    for (int i = 2; i <= num; i++) {
        beforePrev = prev;
        prev = f;
        f = prev + beforePrev;
    }
    printf ("The value of element %d is: %d\n", num, f);
    return 0;
}
