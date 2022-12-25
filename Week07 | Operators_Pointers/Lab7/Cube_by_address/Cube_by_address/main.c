//
//  main.c
//  Cube_by_address
//
//  Created by Khongmeng Kormoua on 2020. 10. 21..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>

void cube(double, double *, double *);

int main(void) {
    double edge = 2.7, Tarea, Tvolumn;
    double *area = &Tarea, *volume = &Tvolumn;
    cube(edge, area, volume);
    printf("The area of all the surface is: %.2lf, and the volume is: %.2lf\n", Tarea, Tvolumn);
    return 0;
}

void cube(double edge, double *parea, double *pvolume) {
    *parea = 6 * edge * edge;
    *pvolume = edge * edge * edge;
}
