//
//  main.c
//  Trimmer
//
//  Created by Khongmeng Kormoua on 2020. 10. 28..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>

void trim(char*, char*);

int main(void) {
    char word[99] = "   Hi, what's up?    ";
    char modified[99];
    trim(word, modified);
    printf("Old: \"%s\"\n", word);
    printf("New: \"%s\"\n", modified);
    return 0;
}

void trim(char* old, char* new) {
    char* ptr1 = old;
    char* ptr2 = old;
    int length = 0;
    while (*ptr1 == ' ') ptr1 += 1;
    while (*ptr2 != '\0') {
        length += 1;
        ptr2 += 1;
    }
    ptr2 = old + length - 1;
    while (*ptr2 == ' ') ptr2 -= 1;
    while (ptr1 <= ptr2) {
        *new = *ptr1;
        ptr1 += 1;
        new += 1;
    }
    new += 1;
    *new = '\0';
}
