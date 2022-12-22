#include <stdio.h>

int main (void) {
    int num, right = 1, left = 1;
    printf ("Enter an integer: ");
    scanf ("%d", &num);
    
    while (num / left > 0) left = left * 10;
    left = left / 10;
    
    while (left > right) {
        if ((num / right) % 10 != (num / left) % 10) {
            break;
        } else {
                right = right * 10;
                left = left / 10;
        }
    }
    if (left > right) printf ("The number is not a palindromic\n");
    else printf ("The number is a palindromic\n");
    return 0;
}
