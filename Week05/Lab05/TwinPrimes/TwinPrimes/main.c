//
//  main.c
//  TwinPrimes
//
//  Created by Khongmeng Kormoua on 2020. 10. 07..
//  Copyright © 2020. khonmeng Kormoua. All rights reserved.
//

#include <stdio.h>

int isPrime(int);
int containFive(int);

int main(void) {
    int pair = 0;
    for (int i = 2; pair < 60; i += 1)
        if (isPrime(i))
            if (isPrime(i + 2)) {
                printf ("(%d, %d) ", i, i + 2);
                if (containFive(i + 1)) printf ("Contain 5\n");
                else printf ("\n");
                pair += 1;
            }
    return 0;
}

int isPrime(int x) {
    for (int i = 2; i * i <= x; i += 1)
        if (x % i == 0) return 0;
    return 1;
}

int containFive(int x) {
    while (x > 1) {
        if (x % 10 == 5) return 1;
        x = x / 10;
    }
    return 0;
}
