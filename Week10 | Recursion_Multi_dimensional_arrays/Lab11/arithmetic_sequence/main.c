#include <stdio.h>

int arithmetig_seq(int, int, int);
int geometric_seq(int, int, int);

int main(void) {
    int num;
    int const numOfSequence = 10;
    for (int i = 0; i < numOfSequence; i++)
        printf("%5d ", arithmetig_seq(i + 1, 5, 2));
    printf("\n");

    for (int i = 0; i < numOfSequence; i++)
        printf("%5d ", geometric_seq(i + 1, 5, 2));
    printf("\n");
    return 0;
}
int arithmetig_seq(int n, int start, int diff) {
    if (n > 1) return arithmetig_seq(n-1, start, diff) + diff;
    else return start;
}
int geometric_seq(int n, int b0, int q) {
    if (n > 1) return geometric_seq(n-1, b0, q) * q;
    else return b0;
}