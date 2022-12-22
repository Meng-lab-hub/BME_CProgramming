//
//  main.c
//  Vectors
//
//  Created by Khongmeng Kormoua on 2020. 10. 14..
//  Copyright © 2020. khonmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <math.h>

typedef struct vector {
    double x,y;
} vector;

double length(vector);
vector sum(vector,vector);

int main(void) {
    vector a = {1,2};
    vector b = {4,10};
    vector c = sum(a, b);
    printf("%.2lf\n", length(c));
    return 0;
}

double length(vector a) {
    return sqrt((a.x)*(a.x)+(a.y)*(a.y));
}

vector sum(vector a,vector b) {
    vector c;
    c.x = a.x+b.x;
    c.y = a.y+b.y;
    return c;
}
