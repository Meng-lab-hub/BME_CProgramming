#include <stdio.h>
#include <stdbool.h>

int main (void) {
    bool present[1000];
    
    for (int i = 0; i < 998; i+=1)
        present[i] = true;
    for (int i = 2; i < 1000; i+=1)
        if (present[i - 2])
            for (int j = 2 * i; j < 1000; j = j + i)
                present[j - 2] = false;
    for (int n = 0; n <  998; n+=1)
        if (present[n])
            printf ("%d\t", n + 2);
    printf ("\n");
    return 0;
}
