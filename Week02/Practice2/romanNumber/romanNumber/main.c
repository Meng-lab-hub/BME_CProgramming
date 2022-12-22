#include <stdio.h>

int main (void) {
    int num;
    printf ("Print me this number in Roman number: ");
    scanf ("%d", &num);
    
    if (num > 99) printf ("Number is too big, must be smaller than 100\n");
    else if (num < 1) printf ("Number is ");
    else {
        if (num >= 90) {
            printf ("XC");
            num = num - 90;
        } if (num >= 50) {
            printf ("L");
            num = num - 50;
        } if (num >= 40) {
            printf ("XL");
            num = num - 40;
        }
//        because in roman number , X can be appear several times
        while (num >= 10) {
            printf ("X");
            num = num - 10;
        } if (num >= 9) {
            printf ("IX");
            num = num - 9;
        } if (num >= 5) {
            printf ("V");
            num = num - 5;
        } if (num >= 4) {
            printf ("IV");
            num = num -4;
        }
//        because in roman number, I can be appear several times
        while (num >= 1) {
            printf ("I");
            num = num - 1;
        }
        printf ("\n");
    }
    return 0;
}
