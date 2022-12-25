//
//  main.c
//  remove_spaces
//
//  Created by Khongmeng Kormoua on 2020. 10. 30..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void remove_space(char*);
char* remove_space_dyn(char*);

int main(void) {
    char old[] = "    H   e ll  o  Wor  l d  !";
    
    printf("old string: %s\n", old);
    remove_space(old);
    printf("new string: %s\n", old);
    printf("-------------------------------\n");
    char* new = remove_space_dyn(old);
    printf("new new string: %s\n\n", new);
    free(new);
    new = NULL;
    return 0;
}

void remove_space(char* str) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
    str[j] = '\0';
}

char* remove_space_dyn(char* str) {
    int non_space = 0, j = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != ' ') non_space++;
    
    char* modified = (char*) malloc((non_space + 1) * sizeof(char));
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != ' ') {
            modified[j] = str[i];
            j++;
        }
    modified[j] = '\0';
    return modified;
}
