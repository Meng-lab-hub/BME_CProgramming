#include <stdio.h>

int main (void) {
    int width, height;
    
    printf ("\nEnter the width and heigh: ");
    scanf ("%d %d", &width, &height);
    
//    top line of the square
    printf ("\n+");
    for (int i = 1; i <= width; i++)
        printf ("-");
    printf ("+\n");
    
//    in body
    for (int i = 0; i < height; i++) {
        printf ("|");
        for (int j = 0; j < width; j++)
            printf (".");
        printf ("|\n");
    }
    
//    bottom line of the square
    printf ("+");
    for (int i = 1; i <= width; i++)
        printf ("-");
    printf ("+\n");
    
    return 0;
}
