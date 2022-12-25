//
//  main.c
//  inserting_string_intoString
//
//  Created by Khongmeng Kormoua on 2020. 11. 05..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* insert_string(char*, int, char*);

int main(void) {
    char* insertStr = insert_string("hello!", 5, ", world");
    printf("%s\n", insertStr);
    free(insertStr);
    insertStr = NULL;
    return 0;
}

char* insert_string(char* str, int position, char* new) {
    long lenght = strlen(str) + strlen(new);
    char* inserted = (char*)malloc((lenght + 1) * sizeof(char));
    int x;
    
    for (x = 0; x < position; x++)
        inserted[x] = str[x];
    for (int i = position, j = 0; i < strlen(new) + position ; i++, j++)      // strlen(new) here is substitution for lenght - strlen(str)
        inserted[i] = new[j];
    for (long i = strlen(new) + position; i < lenght; i++, x++)
        inserted[i] = str[x];
    inserted[lenght] = '\0';
    return inserted;

}

//    first the function copy all the character of string str before the insert position to the inserted string first
//    then copy all the character from string new and place it next to the end of string inserted
//    then copy the rest of the remaining character in string str next to the end of string inserted
//    then add terminating character at the end
//    and return the address of inserted
