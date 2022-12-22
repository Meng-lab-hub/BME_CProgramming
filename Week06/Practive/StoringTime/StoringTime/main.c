//
//  main.c
//  StoringTime
//
//  Created by Khongmeng Kormoua on 2020. 10. 16..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>

typedef struct {
    int hour, min;
} time;

void print_time(time);
time add_to_time(time, int);
int elapsed_time(time, time);
time subtract_from_time(time, int);

int main(void) {
    time t = {15, 15};
    time t2 = {16, 30};
    
    print_time(t);
    print_time(add_to_time(t, 45));
    printf("The different is: %d\n", elapsed_time(t2, t));
    print_time(subtract_from_time(t2, 30));
    
    return 0;
}

void print_time(time x) {
    printf("%02d:%02d\n", x.hour, x.min);
}
time add_to_time(time a, int b) {
    time result;
    int fromMidNight = a.hour * 60 + a.min + b;
    result.hour = (fromMidNight/60) % 24;
    result.min = fromMidNight % 60;
    return result;
}
int elapsed_time(time a, time b) {
    return (a.hour * 60 + a.min) - (a.hour * 60 + a.min) ;
}
time subtract_from_time(time a, int b) {
    time result;
    result.hour = a.hour;
    result.min = a.min - b;
    while (result.min < 0) {
        result.min += 60;
        result.hour -= 1;
    }
    while (result.hour < 0) {
        result.hour += 24;
    }
    return result;
}
