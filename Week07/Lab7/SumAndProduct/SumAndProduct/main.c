//
//  main.c
//  SumAndProduct
//
//  Created by Khongmeng Kormoua on 2020. 10. 21..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>

void sumAndProduct(double, double, double *, double *);

int main(void) {
    double numb1 = 10, numb2 = 11.5, sum, product, *psum = &sum, *pproduct = &product;
    sumAndProduct(numb1, numb2, psum, pproduct);
    printf("The sum of 2 number is: %.2lf\nThe product of 2 number is: %.2lf\n", *psum, *pproduct);
    return 0;
}

void sumAndProduct(double num1, double num2, double *Psum, double *Pproduct) {
    *Psum = num1 + num2;
    *Pproduct = num1 * num2;
}
