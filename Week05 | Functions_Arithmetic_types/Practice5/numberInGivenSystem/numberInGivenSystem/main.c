//
//  main.c
//  numberInGivenSystem
//
//  Created by Khongmeng Kormoua on 2020. 10. 09..
//  Copyright © 2020. khonmeng Kormoua. All rights reserved.
//

#include <stdio.h>

int main(void) {
    int number, base, div = 1, value;
    
    printf("Number system: ");
    scanf("%d", &base);
    
    printf("Number: ");
    scanf("%d", &number);
    
    while (div < number) {
        div = div * base;
    }
    div = div / base;
    while (number > 0) {
        value = number/div;
        if (value >= 10)
            printf("%c", value - 10 + 'A');
        printf("%d", value);
        number = number - value*div;
        div = div / base;
    }
    printf("\n");
    return 0;
}
