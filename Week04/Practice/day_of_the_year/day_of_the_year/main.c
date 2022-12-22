#include <stdio.h>

int main (void) {
    int daysInM[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, day, month, dayOfY = 0;
    
    printf ("Input the month: ");
    scanf ("%d", &month);
    printf ("%d days\n", daysInM[month - 1]);
    
    printf ("Input the year month day: ");
    scanf ("%d%d%d", &year, &month, &day);
    
    for (int i = 0; i < month - 1; i += 1)
        dayOfY += daysInM[i];
    dayOfY += day;
    if (month > 2)
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            dayOfY += 1;
    printf ("It is day %dth of the year\n", dayOfY);
    
    return 0;
}
