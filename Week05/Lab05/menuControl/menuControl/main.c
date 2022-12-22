//
//  main.c
//  menuControl
//
//  Created by Khongmeng Kormoua on 2020. 10. 07..
//  Copyright © 2020. khonmeng Kormoua. All rights reserved.
//

#include <stdio.h>

int operate (int, int);

int main(void) {
    int n = 1, choice = 1;
    do {
        printf ("\nn = %d\n\n", n);
        printf("0. Restore the initial value (n = 1)\n"
        "1. Add 1\n"
        "2. Negate the number (+/-)\n"
        "3. Multiple by 2\n"
        "9. Exit\n");
        printf ("\nchoice: ");
        scanf ("%d", &choice);
        n = operate(choice, n);
    } while (choice != 9);
    return 0;
}

int operate (int num, int n) {
    switch (num) {
        case 0: return 1;
            break;
        case 1: return n + 1;
            break;
        case 2: return -n;
            break;
        case 3: return 2 * n;
            break;
        case 9: return n;
            break;
    }
    return n;
}
