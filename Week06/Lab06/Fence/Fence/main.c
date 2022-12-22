//
//  main.c
//  Fence
//
//  Created by Khongmeng Kormoua on 2020. 10. 14..
//  Copyright © 2020. khonmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <math.h>

typedef struct point{
    double x, y;
} point;

double dist(point,point);
double equal(point,point);
point raed(void);

int main(void) {
    double distance = 0.0;
    point start = raed();
    point current = raed();
    point previous;
    distance += dist(start, current);
    previous = current;
    while (!equal(start, current)) {
        distance += dist(previous, current);
        previous = current;
        current = raed();
    }
    printf("The required fence: %.2lf\n", distance);
    return 0;
}

double dist(point a,point b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double equal(point a,point b) {
    return (a.x == b.x && a.y == b.y);
}
point raed(void) {
    point a;
    printf("Enter x and y coordinate: ");
    scanf("%lf %lf", &a.x, &a.y);
    return a;
}
