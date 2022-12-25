//
//  main.c
//  Rational_number
//
//  Created by Khongmeng Kormoua on 2020. 10. 16..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>

typedef struct {
    int num, den;
} Rational;

void printRational(Rational);
Rational readRational(void);
Rational multiplyRational(Rational, Rational);
Rational addRational(Rational,Rational);
double rationalToDouble(Rational);

int main(void) {
    Rational rat1 = readRational();
    Rational rat2 = readRational();
    Rational X;
    
    printf("Your number is: ");
    printRational(rat1);
    printRational(rat2);
    
    printf("The product is: ");
    multiplyRational(rat1, rat2);
    
    printf("The addition is: ");
    X = addRational(rat1, rat2);
    
    printf("The real number of it is: %lf\n", rationalToDouble(X));
    return 0;
}

void printRational(Rational x) {
    printf("Your number is: ");
    scanf("%d/%d\n", x.num, x.den);
}
Rational readRational(void) {
    Rational x;
    scanf("%d/%d", &x.num, &x.den);
    return x;
}
Rational multiplyRational(Rational a, Rational b) {
    Rational result;
    result.num = a.num * b.num;
    result.den = a.den * b.den;
    return result;
}
Rational addRational(Rational a,Rational b) {
    Rational result;
    result.den = a.den * b.den;
    result.num = a.num * b.den + a.den * b.num;
    return result;
}
double rationalToDouble(Rational x) {
    return (double)x.num/x.den;
}
