#include <stdio.h>

int main (void) {
    int hr, min, speed, record[100], fine = 0, i = 0, hour[24], currentTime;
    
    scanf ("%d-%d-%d", &hr, &min, &speed);
    currentTime = hr;
    while ((hr != 0) || (min !=0) || (speed != 0)) {
        if (hr != currentTime) {
            currentTime = hr;
            i++;
            fine = 0;
            continue;          // skip to next cycle without perform any thing next in this cycle
        }
        if (140 < speed && speed <= 180) {
            hour[i] = currentTime;
            fine += 50;
            record[i] = fine;
        }
        if (speed > 180) {
            hour[i] = currentTime;
            fine += 150;
            record[i] = fine;
        }
        scanf ("%d-%d-%d", &hr, &min, &speed);
    }
    for (int a = 0; a <= i; a++)
        printf ("%02d:00-%02d:59, -> %d EUR\n", hour[a], hour[a], record[a]);
    return 0;
}
