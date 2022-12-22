//
//  main.c
//  numberSystem
//
//  Created by Khongmeng Kormoua on 2020. 10. 09..
//  Copyright © 2020. khonmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char c;
    int result = 0, value, base;
    
    printf("Number base: ");
    scanf("%d", &base);
    
    printf("Enter number: ");
    while(scanf("%c", &c) == 1) {
        value = -1;
        if (c >= '0' && c <= '9')
            value = c - '0';
        else if (c >= 'a' && c <= 'z')
            value = c - 'a' + 10;
        else if (c >= 'A' && c <= 'Z')
            value = c - 'A' + 10;
        result = result * base + value;
        if (value >= 0)
            result = result * base + value;
    }
    printf("Decimal form: %d\n", result);
    return 0;
}
