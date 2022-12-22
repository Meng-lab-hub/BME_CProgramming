//
//  main.c
//  Circles
//
//  Created by Khongmeng Kormoua on 2020. 10. 14..
//  Copyright © 2020. khonmeng Kormoua. All rights reserved.
//

#include <stdio.h>

typedef struct circle{
    double x,y,r;
} circle;

circle createCircle(void);
int overlapCheck(circle, circle);

int main(void) {
    circle a = createCircle();
    circle b = createCircle();
    if (overlapCheck(a, b))
        printf("Two circle are overlap\n");
    else printf("Two circle are not overlap each other\n");
    return 0;
}

int overlapCheck(circle a, circle b) {
    return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) < (a.r+b.r)*(a.r+b.r)) ? 1 : 0;
}

circle createCircle(void) {
    circle a;
    printf("Enter x and y coordinate of circle's center(separate by space): ");
    scanf("%lf %lf", &a.x, &a.y);
    printf("Enter the radius of the circle: ");
    scanf("%lf", &a.r);
    return a;
}
