#include <stdio.h>

void print_forward(int*, int);
void print_backward(int*, int);

int main(void) {
    int const sizeOne = 5, sizeTwo = 10;
    int arrOne[] = {0,1,2,3,4};
    int arrTwo[] = {0,1,2,3,4,5,6,7,8,9};
    printf("Forward: ");
    print_forward(arrOne, sizeOne);
    printf("\n");
    printf("Backward: ");
    print_backward(arrTwo, sizeTwo);
    printf("\n");
    return 0;
}
void print_forward(int* arr, int n) {
    if (n > 1) {
        print_forward(arr, n-1);
        printf("%d ", arr[n-1]);
    }
    else printf("%d ", arr[0]);
}
void print_backward(int* arr, int n) {
    if (n > 1) {
        printf("%d ", arr[n - 1]);
        print_backward(arr, n - 1);
    } else printf("%d ", arr[0]);
}