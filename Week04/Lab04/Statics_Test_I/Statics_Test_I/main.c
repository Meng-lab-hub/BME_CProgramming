#include <stdio.h>


int main (void) {
    char letter, sheet[4];
    int mark1, mark2, mark3, i = 0;
    int passed[4];
    
    scanf ("%c %d %d %d ", &letter, &mark1, &mark2, &mark3);
    
    while ((letter != 'x') || (mark1 != 0) || (mark2 != 0) || (mark3 != 0)) {
        sheet[i] = letter;
        passed[i] = ((mark1 > 1) && (mark2 > 1) && (mark3 > 1) && (mark1 + mark2 + mark3) > 11);
        i++;
        scanf ("%c %d %d %d ", &letter, &mark1, &mark2, &mark3);
    }
    for (i = 0; i < 4; i++)
        printf ("%c %d\n", sheet[i], passed[i]);
    return 0;
}
