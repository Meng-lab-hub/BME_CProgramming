//
//  main.c
//  dynamic_copy_string
//
//  Created by Khongmeng Kormoua on 2020. 11. 05..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* copystring(char*);

int main(void) {
    char* string = copystring("apple");
    printf("%s\n", string);
    free(string);
    string = NULL;
    return 0;
}

char* copystring(char* str) {
    long lenght = strlen(str);
    char* result = (char*)malloc(lenght * sizeof(char));
    strcpy(result, str);            // I use strcpy here because it is mentioned in the description of the task
    return result;
}
// first function take the string as a argument, it initialize the space for this string in a memory and return an address of that place to variable result in the function.
// then the function use strcpy function from string library to copy the argument to the result and return this result to the main function
