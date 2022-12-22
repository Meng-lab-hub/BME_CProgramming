//
//  main.c
//  Values_backwards
//
//  Created by Khongmeng Kormoua on 2020. 10. 28..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    double* set;
    printf("How many real value do you wish to store: ");
    scanf("%d", &n);
    set = (double*) malloc(n * sizeof(double));
    if (set != NULL) {
        for (int i = 0; i < n; i += 1) {
            printf("Enter %d number: ", i+1);
            scanf("%lf", &set[i]);
        }
        printf("\nIn reversed order: ");
        for (int i = 0; i < n; i += 1)
            printf("%.2lf ", set[n-i-1]);
        printf("\n");
    }
    free(set);
    set = NULL;
    return 0;
}
