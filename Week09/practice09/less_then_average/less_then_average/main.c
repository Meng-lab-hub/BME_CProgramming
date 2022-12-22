//
//  main.c
//  less_then_average
//
//  Created by Khongmeng Kormoua on 2020. 11. 06..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int less_then_average(double*, int, double**, int*);

int main(void) {
    int length = 7, lta_len = 0;
    double data[] = {543, 434, 321, 112, 733, -45, -755};
    double* lta = NULL;
    int status = less_then_average(data, length, &lta, &lta_len);
    
    if (status == 1) printf("failed\n");
    for (int i = 0; i < lta_len; i++)
        printf("%.2lf ", lta[i]);
    free(lta);
    lta = NULL;
    return 0;
}

int less_then_average(double* arr, int len, double** lta_arr, int* des_len) {
    double avg = 0.0;
    int cnt = 0, j = 0;
    
    for (int i = 0; i < len; i++)
        avg += arr[i];
    avg /= len;
    
    for (int i = 0; i < len; i++)
        if (arr[i] < avg)
            cnt++;
    
    double* result = (double*)malloc(cnt * sizeof(double));
    if (result == NULL) return 1;
    for (int i = 0; i < len; i++)
        if (arr[i] < avg) {
            result[j] = arr[i];
            j++;
        }
    lta_arr = &result;
    *des_len = cnt;
    return 0;
}
