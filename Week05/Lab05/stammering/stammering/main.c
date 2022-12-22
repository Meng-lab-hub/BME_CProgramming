//
//  main.c
//  stammering
//
//  Created by Khongmeng Kormoua on 2020. 10. 07..
//  Copyright © 2020. khonmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>      // for tolower function which is used to find the lowercase of character c

int isVowel(char);
int isCapVowel(char);

int main(void) {
    char c;

    while (scanf("%c", &c) == 1) {
        if (isCapVowel(c))
            printf("%ch%c", c, tolower(c));
        else if (isVowel(c))
            printf("%ch%c", c, c);
        else
            printf("%c", c);
    }
    return 0;
}

int isVowel(char x) {
    return (x=='a' || x=='e' || x=='i' || x=='o' || x=='u');
}

int isCapVowel(char x) {
    return (x=='A' || x=='A' || x=='A' || x=='A' || x=='A');
}

