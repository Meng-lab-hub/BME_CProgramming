//
//  main.c
//  remove_part_string
//
//  Created by Khongmeng Kormoua on 2020. 11. 05..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* substring_copy(char*, int, long);

int main(void) {
    char* string = "hello, world";
    char* modified = substring_copy(string, 4, 8);
    printf("Old string: %s\n", string);
    printf("New string: %s\n", modified);
    free(modified);
    modified = NULL;
    return 0;
}

char* substring_copy(char* str, int starting, long ending) {
    if (starting < 0) starting = 0;
    if (ending > strlen(str) - 1) ending = strlen(str) - 1;
    char* subs = (char*)malloc((strlen(str) - ending + starting + 1) * sizeof(char));
    
    for (int i = 0; i < starting; i++)
        subs[i] = str[i];
    long j = ending;
    int i;
    for (i = starting; i < strlen(str) - ending + starting; i++, j++)
        subs[i] = str[j];
    subs[i] = '\0';
    return subs;
}

// this function receive a source string, starting index and ending index
// first it checks the starting index is < 0 and if the ending index is > the lengh of the string, is yes then assign it to 0 and assign string ending to the length of the string, if not leave it as it is
// then we initialize a brandnew string with just as long as we need, all we need is the space for a substring that doesn't contain string between starting and ending index
// then we copy those substring to the new space that we reserved for it
// at last add terminating character and return the address of that reserved space.
