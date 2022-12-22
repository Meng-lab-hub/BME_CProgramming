//
//  main.c
//  dynamic_extension_string
//
//  Created by Khongmeng Kormoua on 2020. 11. 05..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copystring(char*);
char* stringcat(char*, char*);

int main(void) {
    char* x;
    x = copystring("apple");
    x = stringcat(x, "tree");
    printf("%s\n", x);
    free(x);
    x = NULL;
    return 0;
}

char* copystring(char* str) {
    long lenght = strlen(str);
    char* result = (char*)malloc(lenght * sizeof(char));
    strcpy(result, str);
    return result;
}
// first function take the string as a argument, it initialize the space for this string in a memory and return an address of that place to variable result in the function.
// then the function use strcpy function from string library to copy the argument to the result and return this result to the main function

char* stringcat(char* old, char* new) {
    long lenOld = strlen(old);
    long lenNew = strlen(new);
    char* append = (char*)malloc((lenOld + lenNew + 1) * sizeof(char));
    strcpy(append, old);
    for (int i = (int)lenOld, j = 0; i < lenNew + lenOld; i++, j++)
        append[i] = new[j];
    append[lenNew + lenOld] = '\0';
    free(old);
    old = NULL;
    return append;
}

// first we take the old string and the new string into the function then we allocate a new space which have enough space to append the old and new string together
// then we copy the old one to the append string first
// then we copy the new string to the rest space that we reserved in the append string
// at last we assign terminating character, free the unused string, point in to nowhere and return the appended string
