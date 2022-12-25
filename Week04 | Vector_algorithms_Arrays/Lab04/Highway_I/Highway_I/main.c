#include <stdio.h>

int main (void) {
    int hr, min, speed, record[100], max = 0, i = 0, hour[24], currentTime;
    
    scanf ("%d-%d-%d", &hr, &min, &speed);
    currentTime = hr;
    while ((hr != 0) || (min !=0) || (speed != 0)) {
        if (hr != currentTime) {
            currentTime = hr;
            i++;
            max = 0;
            continue;
        }
        if (max < speed) {
            record[i] = speed;
            hour[i] = currentTime;
            max = speed;
        }
        scanf ("%d-%d-%d", &hr, &min, &speed);
    }
    for (int a = 0; a <= i; a++)
        printf ("%02d:00-%02d:59 -> %d km/h\n", hour[a], hour[a], record[a]);
    return 0;
}
