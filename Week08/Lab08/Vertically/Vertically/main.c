//
//  main.c
//  Vertically
//
//  Created by Khongmeng Kormoua on 2020. 10. 28..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>

int main(void) {
    char word[99];
    char* ptr = word;
    printf("Please enter your word: ");
    scanf("%s", word);
    while (*ptr != '\0') {
        printf("%c\n", *ptr);
        ptr += 1;
    }
    return 0;
}
