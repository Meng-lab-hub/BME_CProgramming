#include <stdio.h>
#include <stdlib.h>

int check_and_convert(int array[], int num) {
    if (array == NULL) {
        return 0;       // null safty check
    }
    for (int i=0; i<num; i++) {
        if (array[i] < 0) {
            array[i] = array[i] * (-1);
        }
        if (array[i] > 1024) {
            array[i] = array[i]/64;
        }
    }
    return num;
}

int main(void) {
    int age[] = {1,2,3,4,5,6};
    int* height = NULL;
    int number = 6;
    number = check_and_convert(height, number);
    for (int i = 0; i<number; i++) printf("%d ", age[i]);
    return 0;
}

// function:
