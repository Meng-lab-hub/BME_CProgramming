#include <stdio.h>

int main (void) {
    int m[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n, flag = 0;

    scanf ("%d", &n);
    for (int i = 0; i < 10; i+=1) {
        for (int j = 1; j < 10; j+=1) {
            if (m[i] * m[j] == n) {
                printf ("Yes, there is!\n");
                flag = 1;
            }
            if (flag == 1) break;
        }
        if (flag == 1) break;
    }
    if (flag == 0)
        printf ("No, there is not..\n");
    return 0;
}
