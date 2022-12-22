//
//  main.c
//  reverse
//
//  Created by Khongmeng Kormoua on 2020. 10. 30..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void reverse_string(char*, char*);
void reverse_inplace(char*);
void swap_char(char*, char*);

int main(void) {
    char string[] = "Hello world!";
    char reverse[99];
    reverse_string(string, reverse);
    printf("Orginal string: %s\n", string);
    printf("New string: %s\n", reverse);
    reverse_inplace(reverse);
    printf("New new string: %s\n", reverse);
    return 0;
}

void reverse_string(char* source, char* target) {
    long i, j;      // use long because strlen return unsigned long
    i = strlen(source) - 1;
    j = 0;
    while (i >= 0) {
        target[j] = source[i];
        i--;
        j++;
    }
    target[j] = '\0';
}

void reverse_inplace(char* source) {
    long length = strlen(source);
    for (int i = 0; i < length/2; i++) {    // if we use i < length, it will cause to double reverse
        swap_char(&source[i], &source[length-1-i]);
    }
    source[length] = '\0';
}

void swap_char(char* a, char* b) {
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
