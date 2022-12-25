//
//  main.c
//  ArraySearch
//
//  Created by Khongmeng Kormoua on 2020. 10. 21..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>

#define length 8      // size of array

int *arraySearch(int, int *, int *);

int main(void) {
    int numb = 11,array[] = {0,3,7,5,10,11,15,23}, i, *index = &i;
    int *ptr = array;
    if (arraySearch(numb, array, index) != NULL) {
        for (int i = 0; i < length; i += 1, ptr += 1)
            printf("A[%d]=%d ", i, *ptr);
        printf("\nThe address of the number is: %p\n", arraySearch(numb, array, index));
        printf("The index of the searching number is: %d\n", i);
    } else {
        printf("Not found!\n");
    }
}

int *arraySearch(int num, int *array, int *index) {
    int *ptr = array;
    for (int i = 0; i < length; i += 1) {
        if (*ptr == num) {
            *index = i;
            return ptr;
        }
        ptr += 1;
    }
    return NULL;
}
