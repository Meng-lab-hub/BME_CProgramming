//
//  main.c
//  value_backward
//
//  Created by Khongmeng Kormoua on 2020. 11. 06..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>



int main(void) {
    int new_value, length = 0;
    int* array = NULL;
    
    printf("Enter numbers, stop with -1!\n");
    while (scanf("%d", &new_value) == 1 && new_value != -1) {
        int* tmp = (int*)malloc((length + 1) * sizeof(int));
        for (int i = 0; i < length; i++)
            tmp[i] = array[i];
        free(array);
        array = tmp;
        array[length] = new_value;
        length++;
    }
    for (int i = 0; i < length; i++)
        printf("%d ", array[length - 1 - i]);
    free(array);
    array = NULL;
    return 0;
}
