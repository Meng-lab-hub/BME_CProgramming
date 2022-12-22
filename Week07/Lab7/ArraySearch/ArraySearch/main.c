//
//  main.c
//  ArraySearch
//
//  Created by Khongmeng Kormoua on 2020. 10. 21..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>

int arraySearch(int, int *);

int main(void) {
    int numb = 11, array[] = {0,3,7,5,10,11,15,23};
    if (arraySearch(numb, array) != -1) {
        for (int i = 0; i < 8; i += 1)
            printf("A[%d]=%d ", i, array[i]);
            printf("\nThe number's index is: %d\n", arraySearch(numb, array));
    } else {
        printf("Not found!\n");
    }
}

int arraySearch(int num, int array[8]) {
    for (int i = 0; i < 8;i += 1) {
        if (array[i] == num) return i;
    }
    return -1;
}
