//
//  main.c
//  arraySeparation
//
//  Created by Khongmeng Kormoua on 2020. 10. 21..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>

#define size 10

void printArray(int *, int);
void separateArray(int *, int *, int *, int, int *, int *);

int main(void) {
    int array1[] = {0,1,2,3,4,5,6,7,8,9};
    int array2[10], array3[10];
    int sizeEven = 0, sizeOdd = 0;
    
    printArray(array1, size);
    separateArray(array1, array2, array3, size, &sizeEven, &sizeOdd);
    printArray(array2, sizeEven);
    printArray(array3, sizeOdd);
    
    return 0;
}

void printArray(int * arr, int length) {
    printf("array[%d] = {%d", length, *arr);
    arr += 1;
    for (int i = 1; i < length; i += 1, arr += 1)
        printf(",%d", *arr);
    printf("}\n");
}

void separateArray(int *arr, int *arrEven, int *arrOdd, int sizeA, int *sizeE, int *sizeO) {
    for (int i = 0; i < sizeA; i += 1, arr += 1)
        if (*arr % 2 == 0) {
            *arrEven = *arr;
            *sizeE += 1;
            arrEven += 1;
        } else {
            *arrOdd = *arr;
            *sizeO += 1;
            arrOdd += 1;
        }
}
