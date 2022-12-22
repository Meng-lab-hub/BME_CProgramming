//
//  main.c
//  Calendar
//
//  Created by Khongmeng Kormoua on 2020. 10. 16..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>

typedef struct {
    int year, month, day;
} Date;

void date_print(Date);
int date_day_of_year(Date);
int date_subtract(Date, Date);
which_day(Date);
int is_leapYear(int);

int main(void) {
    Date d1 = {2020, 10, 16};
    Date d2 = {1914, 9, 1};
    
    date_print(d1);
    printf("Dates of the year is: %d\n", date_day_of_year(d1));
    printf("Days between: %d\n", date_subtract(d2, d1));
    
    return 0;
}
void date_print(Date d) {
    printf("%d/%02d/%02d\n", d.year, d.month, d.day);
}
int date_day_of_year(Date d) {
    int days = 0;
    int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    for (int m = 1; m < d.month; m += 1)
        days += month[m-1];
    days += d.day;
    
    if (d.month > 2 && is_leapYear(d.year))
        days += 1;
    return days;
}
int date_subtract(Date d1, Date d2) {
    int diff = date_day_of_year(d2) - date_day_of_year(d1);
    for (int i = d1.year; i < d2.year; i += 1) {
        diff += 365;
        if (is_leapYear(i))
            diff += 1;
    }
    return diff;
}
which_day(Date);
int is_leapYear(int year) {
    return (((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0);
}
