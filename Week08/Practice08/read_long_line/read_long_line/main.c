//
//  main.c
//  read_long_line
//
//  Created by Khongmeng Kormoua on 2020. 10. 30..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

char* read_long_line(char*);

int main(void) {
    char* str = (char*)malloc(sizeof(char));
    str[0] = '\0';
    printf("Say: ");
    str = read_long_line(str);
    printf("You said \"%s\"\n\n", str);
    free(str);
    str = NULL;
    return 0;
}

char* read_long_line(char* str) {
    char* tmp;
    int len = 0, i;
    char c;
    
    while (scanf("%c", &c) == 1 && c != '\n') {
        tmp = (char*)malloc((len + 1 + 1) * sizeof(char));
        for (i = 0; i < len; i++)
            tmp[i] = str[i];
        tmp[len] = c;
        tmp[len + 1] = '\0';
        len++;
        free(str);
        str = tmp;
    }
    return str;
}
